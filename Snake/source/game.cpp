#include "game.h"

#include <string>
#include <sstream>
#include <iomanip>

#include "raylib.h"

#include "config.h"

Game::Game()
{
	InitWindow(720, 800, "Snake");
	SetTargetFPS(60);

	map_border_ = { 30, 80, 660.0f, 660.0f };
	current_score_ = 0;
	best_score_ = 0;

	snake_.Init();
	apple_.Init();

	apple_.Spawn(snake_.GetBody());
}

void Game::Run()
{
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BACKGROUND_COLOR);

		if (CheckCollisionPointRec(snake_.GetHead(), map_border_))
		{
			Update();
		}

		Draw();

		EndDrawing();
	}
}

void Game::Draw()
{
	DrawRectangleLinesEx(map_border_, 10, ELEMENT_COLOR);

	DrawText("Best: 000", map_border_.x, 30, FONT_SIZE, ELEMENT_COLOR);
	DrawText(current_score_text_.c_str(), map_border_.x + map_border_.width - MeasureText("Score: 000", FONT_SIZE), 30, FONT_SIZE, ELEMENT_COLOR);
	
	snake_.Draw();
	apple_.Draw();
}

void Game::Update()
{
	snake_.Update();

	if (CheckCollisionPointRec(snake_.GetHead(), apple_.GetHitbox()))
	{
		current_score_++;
		snake_.AddBodySegment();
		apple_.Spawn(snake_.GetBody());
	}

	UpdateScoreText();
}

void Game::UpdateScoreText()
{
	std::ostringstream ss;
	ss << "Score: " << std::setw(3) << std::setfill('0') << current_score_;
	current_score_text_ = ss.str();
}