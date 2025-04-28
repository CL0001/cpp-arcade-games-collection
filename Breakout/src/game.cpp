#include "game.h"

#include "raylib.h"

Game::Game()
{
	InitWindow(1024, 768, "Breakout");
	SetTargetFPS(60);

	paddle_.Init();
	ball_.Init();
	level_.Init();
}

Game::~Game()
{
	CloseWindow();
}

void Game::Run()
{
	while (!WindowShouldClose())
	{
		Draw();
		Update();
	}
}

void Game::Draw()
{
	BeginDrawing();
	ClearBackground(Color{ 40, 40, 43 });

	paddle_.Draw();
	ball_.Draw();
	level_.Draw();

	EndDrawing();
}

void Game::Update()
{
	paddle_.CheckCollision(ball_);
	level_.CheckCollision(ball_);

	paddle_.Move();
	ball_.Move();
}