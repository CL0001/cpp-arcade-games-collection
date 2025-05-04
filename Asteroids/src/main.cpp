#include "game.h"

#include "asteroid.h"

int main()
{
	/*Game game;
	game.Run();*/

	InitWindow(1200, 720, "Test");
	
	Asteroid a(Vector2{ GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f }, 3);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);

		a.Draw();

		EndDrawing();
	}
}