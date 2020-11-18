#include <raylib.h>
#include "Camera_3D.h"
#include "Level.h"

int main(int argc, char* argv[]) {
	const int WindowWidth = 1200;
	const int WindowHeight = 600;

	InitWindow(WindowWidth, WindowHeight, "3D-Engine");

	SetTargetFPS(60);

	//Camera Setup
	Camera camera = { 0 };
	Camera_3D cam3D(camera);
	Vector3 pos = { 4.0f, 2.0f, 4.0f };
	Vector3 target = { 0.0f, 1.8f, 0.0f };
	Vector3 up = { 0.0f, 1.0f, 0.0f };
	cam3D.CameraSetup(camera, pos, target, up);

	//Level Setup
	Level level01(1,30);

	while (!WindowShouldClose()) {

		UpdateCamera(&camera);

		BeginDrawing();
		ClearBackground(BLACK);

		BeginMode3D(camera);

		DrawPlane(Vector3{ 0.0f, 0.0f, 0.0f }, Vector2{ 32.0f, 32.0f }, LIGHTGRAY); // Draw ground

		level01.CreateLevel(level01);

		// Draw the cubes using the randomised arrays
		for (int i = 0; i < level01.objectCount; i++)
		{
			DrawCube(level01.positions[i], 2.0f, level01.heights[i], 2.0f, level01.colors[i]);
			DrawCubeWires(level01.positions[i], 2.0f, level01.heights[i], 2.0f, MAROON);
		}

		EndMode3D();

		DrawText("Test", 20, 20, 10, WHITE);
		EndDrawing();
	}

	return 0;
}