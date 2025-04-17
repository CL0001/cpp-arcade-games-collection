#include "apple.h"

#include <string>
#include <deque>

#include "raylib.h"

#include "config.h"

Apple::~Apple()
{
	UnloadTexture(sprite_);
}

void Apple::Init()
{
	srand(time_t(0));

	sprite_ = LoadTexture((std::string(ASSETS_PATH) + "red-apple.png").c_str());
}

void Apple::Spawn(const std::deque<Vector2>& snake_body)
{
	int grid_width = static_cast<int>(660.0f / (TILE_SIZE * SCALE));
	int grid_height = static_cast<int>(660.0f / (TILE_SIZE * SCALE));

	bool is_valid_position = true;

	do {
		int x_index = rand() % grid_width;
		int y_index = rand() % grid_height;

		position_ = Vector2{
			MAP_START_X + x_index * TILE_SIZE * SCALE,
			MAP_START_Y + y_index * TILE_SIZE * SCALE
		};

		is_valid_position = true;

		for (const auto& body_part : snake_body)
		{
			if (position_.x == body_part.x && position_.y == body_part.y)
			{
				is_valid_position = false;
				break;
			}
		}
	} while (!is_valid_position);
}

void Apple::Draw()
{
	Rectangle source_rectangle{
		0,
		0,
		TILE_SIZE,
		TILE_SIZE
	};

	Rectangle destination_rectangle{
		position_.x,
		position_.y,
		TILE_SIZE * SCALE,
		TILE_SIZE * SCALE
	};

	Vector2 origin{ 0.0f, 0.0f };

	DrawTexturePro(sprite_, source_rectangle, destination_rectangle, origin, 0.0f, WHITE);
}

Rectangle Apple::GetHitbox() const
{
	return{
		position_.x,
		position_.y,
		TILE_SIZE * SCALE,
		TILE_SIZE * SCALE
	};
}
