#pragma once

#include <cstdint>

#include <string>

#include "snake.h"
#include "apple.h"
#include "button.h"

class Game
{
public:
	Game();
	~Game() = default;

	void Run();
	void Draw();
	void Update();

	void LoadBestScore();

	void UpdateCurrentScoreText();
	void UpdateBestScoreText();

	void CheckGameOver();

	void Restart();

private:
	Rectangle map_border_;

	uint16_t current_score_;
	uint16_t best_score_;
	std::string current_score_text_;
	std::string best_score_text_;

	Snake snake_;
	Apple apple_;

	bool is_game_over_;

	Button play_again_button_;
};