#include "game.h"

#include <memory>
#include <string>

#include "raylib.h"

Game::Game()
{
	InitWindow(1024, 512, "Asteroids");
	SetTargetFPS(60);

	sprite_atlas_ = std::make_shared<Texture2D>(LoadTexture((std::string(ASSETS_PATH) + "sprite_atlas.png").c_str()));

	player_.emplace(sprite_atlas_,
					Rectangle{ 0.0f, 0.0f, 32.0f, 32.0f },
					Vector2{ GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f });

	asteroid_manager_.emplace(sprite_atlas_);
}

Game::~Game()
{
	UnloadTexture(*sprite_atlas_);

	CloseWindow();
}

void Game::Run()
{
	while (!WindowShouldClose() && !game_over_)
	{
		Draw();
		Update();
	}
}

void Game::Draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	//player_->Draw();
	//asteroid_manager_->Draw();

	EndDrawing();
}

void Game::Update()
{

}

void Game::Reset()
{

}
