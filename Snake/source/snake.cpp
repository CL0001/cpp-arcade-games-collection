#include "snake.h"

#include <string>

#include "raylib.h"

#include "config.h"

void Snake::Init()
{
	sprite_ = LoadTexture((std::string(ASSETS_PATH) + "snake.png").c_str());
	body_ = { Vector2{MAP_START_X + TILE_SIZE * SCALE * 9, MAP_START_Y + TILE_SIZE * SCALE * 9},
			  Vector2{MAP_START_X + TILE_SIZE * SCALE * 9, MAP_START_Y + TILE_SIZE * SCALE * 10},
		      Vector2{MAP_START_X + TILE_SIZE * SCALE * 9, MAP_START_Y + TILE_SIZE * SCALE * 11}
	};
	direction_ = HeadDirection::Up;
	move_timer_ = 0.0f;
	move_interval_ = 0.2f;
}

void Snake::Draw()
{
	for (auto& body_part : body_)
	{
		Rectangle source_rectangle{
			0,
			TILE_SIZE,
			TILE_SIZE,
			TILE_SIZE
		};

		Rectangle destination_rectangle{
			body_part.x,
			body_part.y,
			TILE_SIZE * SCALE,
			TILE_SIZE * SCALE
		};

		Vector2 origin{ 0, 0 };

		DrawTexturePro(sprite_, source_rectangle, destination_rectangle, origin, 0.0f, WHITE);
	}
}

void Snake::Update()
{
	ChangeDirection();

	move_timer_ += GetFrameTime();

	if (move_timer_ < move_interval_)
		return;

	move_timer_ = 0.0f;

	Vector2 head = body_.front();

	switch (direction_)
	{
	case HeadDirection::Left:
		head.x -= TILE_SIZE * SCALE;
		break;

	case HeadDirection::Up:
		head.y -= TILE_SIZE * SCALE;
		break;

	case HeadDirection::Right:
		head.x += TILE_SIZE * SCALE;
		break;

	case HeadDirection::Down:
		head.y += TILE_SIZE * SCALE;
		break;
	}

	body_.push_front(head);
	body_.pop_back();
}

void Snake::ChangeDirection()
{
	if ((IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) && direction_ != HeadDirection::Down)
		direction_ = HeadDirection::Up;

	else if ((IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) && direction_ != HeadDirection::Up)
		direction_ = HeadDirection::Down;

	else if ((IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) && direction_ != HeadDirection::Right)
		direction_ = HeadDirection::Left;

	else if ((IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) && direction_ != HeadDirection::Left)
		direction_ = HeadDirection::Right;
}

void Snake::AddBodySegment()
{
	Vector2 tail = body_.back();

	switch (direction_)
	{
	case HeadDirection::Left:
		tail.x += TILE_SIZE * SCALE;
		break;

	case HeadDirection::Right:
		tail.x -= TILE_SIZE * SCALE;
		break;

	case HeadDirection::Up:
		tail.y += TILE_SIZE * SCALE;
		break;

	case HeadDirection::Down:
		tail.y -= TILE_SIZE * SCALE;
		break;
	}

	body_.emplace_back(tail);
}

Vector2 Snake::GetHead() const
{
	return body_.front();
}

std::deque<Vector2> Snake::GetBody() const
{
	return body_;
}