#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdlib>

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif


const int WIDTH = 850;
const int HEIGHT = 450;

void UpdateDrawFrame();

Vector2 obj;
Vector2 plr;

float angle = 0.f;

int main(void)
{
	InitWindow(WIDTH, HEIGHT, "Pixel Art! :)");

	obj = {WIDTH/2, HEIGHT/2};
	plr = {WIDTH/2, 50};

	#if defined(PLATFORM_WEB)
    	emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
	#else
		SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
		//--------------------------------------------------------------------------------------

		// Main game loop
		while (!WindowShouldClose())    // Detect window close button or ESC key
		{
			UpdateDrawFrame();
		}
	#endif

	CloseWindow();

	return 0;
}

void UpdateDrawFrame()
{
	angle += .1f;

	plr.x = sinf(angle) * (obj.x-plr.x) + WIDTH/2;
	plr.y = cosf(angle) * (obj.y-plr.y) + HEIGHT/2;
	BeginDrawing();
	
	ClearBackground(DARKGRAY);

	DrawCircleV(obj, 50.f, WHITE);
	DrawCircleV(plr, 25.f, WHITE);

	EndDrawing();
}