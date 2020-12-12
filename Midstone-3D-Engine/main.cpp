#include <raylib.h>
#include "Camera_3D.h"
#include "Level.h"
#include <iostream>

int main(int argc, char* argv[]) {
	const int WindowWidth = 1200;
	const int WindowHeight = 600;

	InitWindow(WindowWidth, WindowHeight, "3D-Engine");

	SetTargetFPS(60);

	//Camera Setup
	Camera_3D cam3D;
	cam3D.CameraSetup(Vector3{ 4.0f, 2.0f, 4.0f },
					  Vector3{ 0.0f, 1.8f, 0.0f }, 
					  Vector3{ 0.0f, 1.0f, 0.0f });

	//Level Setup
	Level level01(1,20);
	level01.CreateLevel(level01);

	int seconds = 0;

	SetTargetFPS(60); // Set our game to run at 60 frames-per-second
	while (!WindowShouldClose()) {

		UpdateCamera(&cam3D.cam);

		seconds++;
		if (seconds >= 100)
		{
			cam3D.CurrentPos(cam3D.cam);
			seconds = 0;
		}

		BeginDrawing();

			ClearBackground(RAYWHITE);

			BeginMode3D(cam3D.cam);

				DrawPlane(Vector3{ 0.0f, 0.0f, 0.0f }, Vector2{ 32.0f, 32.0f }, LIGHTGRAY); // Draw ground
				DrawCube(Vector3{ -16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, BLUE);     // Draw a blue wall
				DrawCube(Vector3{ 16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, LIME);      // Draw a green wall
				DrawCube(Vector3{ 0.0f, 2.5f, 16.0f }, 32.0f, 5.0f, 1.0f, GOLD);      // Draw a yellow wall

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
				if (IsKeyPressed(KEY_SPACE))
				{
					std::cout << "Character Jumps" << std::endl;
					cam3D.cam.position.y++;
				}

			EndMode3D();

			DrawRectangle(10, 10, 220, 70, Fade(SKYBLUE, 0.5f));
			DrawRectangleLines(10, 10, 220, 70, BLUE);

			DrawText("First person camera default controls:", 20, 20, 10, BLACK);
			DrawText("- Move with keys: W, A, S, D", 40, 40, 10, DARKGRAY);
			DrawText("- F2 to randomize the cubes", 40, 60, 10, DARKGRAY);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}