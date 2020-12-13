#include <raylib.h>
#include "Camera_3D.h"
#include "Level.h"
#include "Physics.h"
#include <iostream>

int main(int argc, char* argv[]) {
	const int WindowWidth = 1200;
	const int WindowHeight = 600;

	InitWindow(WindowWidth, WindowHeight, "3D-Engine");

	SetTargetFPS(60);

	//Character setup
	Physics character;
	character.characterSetup({ 4.0f,2.0f,4.0f }, { 0.0f,0.0f,0.0f }, 100.0f);

	//Camera Setup
	Camera_3D cam3D;
	cam3D.CameraSetup(character.position,
					  character.forward, 
					  Vector3{ 0.0f, 1.0f, 0.0f });

	//Level Setup
	Level level01(1,20);
	level01.CreateLevel(level01);

	int time = 0;

	while (!WindowShouldClose()) {

		// Update camera position and target
		UpdateCamera(&cam3D.cam);
		cam3D.cam.position.y = character.position.y + 2.0f;
		character.position.x = cam3D.cam.position.x;
		character.position.z = cam3D.cam.position.z;
		character.forward = cam3D.cam.target;

		// Updating physics
		character.gravity(0.01);

		// Printing info to the console
		time++;
		if (time >= 100)
		{
			cam3D.CurrentPos(cam3D.cam);
			character.CurrentPos(character);
			time = 0;
		}

		BeginDrawing();

			ClearBackground(RAYWHITE);

			BeginMode3D(cam3D.cam);
				
				// Draws the bounding area for the level
				DrawPlane(Vector3{ 0.0f, 0.0f, 0.0f }, Vector2{ 52.0f, 52.0f }, BLACK);
				DrawCube(Vector3{ -26.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 52.0f, GREEN);	
				DrawCube(Vector3{ 26.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 52.0f, GREEN);	
				DrawCube(Vector3{ 0.0f, 2.5f, 26.0f }, 52.0f, 5.0f, 1.0f, GREEN);	

				// Draw the cubes using the randomised arrays
				for (int i = 0; i < level01.objectCount; i++)
				{
					DrawCube(level01.positions[i], 2.0f, level01.heights[i], 2.0f, level01.colors[i]);
					DrawCubeWires(level01.positions[i], 2.0f, level01.heights[i], 2.0f, MAROON);
				}

				// F2 re randomize cubes
				if (IsKeyPressed(KEY_F2))
				{
					std::cout << "Randomize cubes" << std::endl;
					level01.CreateLevel(level01);
				}
				
				// What to do on jump
				if (IsKeyPressed(KEY_SPACE) && character.position.y == 0.0f)
				{
					std::cout << "Character Jumps" << std::endl;
					character.velocity.y = 10.0f;
				}

				// Gravity
				if (character.position.y > 0)
				{
					character.ApplyForce(Vector3{ 0.0f, -9.8f * character.mass, 0.0 });
				}

				//Stop gravity when hitting ground
				if (character.position.y < 0)
				{
					character.position.y = 0.0f;
					character.velocity = { 0.0f,0.0f,0.0f };
					character.acceleration = { 0.0f,0.0f,0.0f };
				}

			EndMode3D();

			// UI for controls
			DrawRectangle(10, 10, 220, 100, Fade(BLACK , 0.6f));
			DrawRectangleLines(10, 10, 220, 100, GRAY);
			DrawText("Controls:", 20, 20, 10, WHITE);
			DrawText("- Move with keys: W, A, S, D", 40, 40, 10, WHITE);
			DrawText("- Spacebar to Jump", 40, 60, 10, WHITE);
			DrawText("- F2 to randomize the cubes", 40, 80, 10, WHITE);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}