#include "level.h"

#include <cstdint>
#include <string>

#include "raylib.h"

#include "config.h"
#include <iostream>

void Level::Init()
{
	uint8_t current_index = 0;
	float current_texture = 0.0f;

	for (uint8_t row = 0; row < brick_layout_.size() / config::brick_rows; row++)
	{
		for (uint8_t column = 0; column < config::brick_rows; column++)
		{
			brick_layout_[current_index] = {
				Rectangle{
					.x = current_texture,
					.y = 0.0f,
					.width = config::sprite_width,
					.height = config::sprite_height
				},
				Rectangle{
					.x = config::layout_horizontal_start + column * config::sprite_width * config::scale,
					.y = config::layout_vertical_start + row * config::sprite_height * config::scale,
					.width = config::sprite_width * config::scale,
					.height = config::sprite_height * config::scale
				}
			};
			current_index++;
		}
		current_texture += config::sprite_width;
	}

	tileset_ = LoadTexture((std::string(ASSETS_PATH) + "bricks.png").c_str());
}

void Level::Draw()
{
	for (const auto& brick : brick_layout_)
		DrawTexturePro(tileset_, brick.texture_coords, brick.game_coords, { 0.0f, 0.0f }, 0.0f, WHITE);
}

void Level::CheckCollision(Ball& ball)
{
	for (int i = 0; i < brick_layout_.size(); i++)
	{
		if (CheckCollisionCircleRec(ball.GetPosition(), ball.GetRadius(), brick_layout_[i].game_coords))
		{
			ball.ChangeDirectionBrick(brick_layout_[i].game_coords);
			brick_layout_.erase(brick_layout_.begin() + i);
		}
	}
}