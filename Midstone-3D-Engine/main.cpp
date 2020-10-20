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
	int currentLevel = 1;
	Level level01;

	while (!WindowShouldClose()) {
		UpdateCamera(&camera);

		BeginDrawing();
		ClearBackground(BLACK);
		BeginMode3D(camera);

		EndMode3D();

		DrawText("Test", 20, 20, 10, WHITE);
		EndDrawing();
	}

	return 0;
}