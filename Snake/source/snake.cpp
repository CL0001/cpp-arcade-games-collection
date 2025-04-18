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

	current_direction_ = HeadDirection::Up;
	next_direction_ = current_direction_;

	move_timer_ = 0.0f;
	move_interval_ = 0.2f;
}

void Snake::Reset()
{
	body_ = { Vector2{MAP_START_X + TILE_SIZE * SCALE * 9, MAP_START_Y + TILE_SIZE * SCALE * 9},
			  Vector2{MAP_START_X + TILE_SIZE * SCALE * 9, MAP_START_Y + TILE_SIZE * SCALE * 10},
			  Vector2{MAP_START_X + TILE_SIZE * SCALE * 9, MAP_START_Y + TILE_SIZE * SCALE * 11}
	};

	current_direction_ = HeadDirection::Up;
	next_direction_ = current_direction_;

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

	current_direction_ = next_direction_;

	Vector2 head = body_.front();

	switch (current_direction_)
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
	if ((IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) && current_direction_ != HeadDirection::Down)
		next_direction_ = HeadDirection::Up;

	if ((IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) && current_direction_ != HeadDirection::Up)
		next_direction_ = HeadDirection::Down;

	if ((IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) && current_direction_ != HeadDirection::Right)
		next_direction_ = HeadDirection::Left;

	if ((IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) && current_direction_ != HeadDirection::Left)
		next_direction_ = HeadDirection::Right;
}

void Snake::AddBodySegment()
{
	Vector2 tail = body_.back();

	switch (current_direction_)
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

bool Snake::CheckCollisionHeadWithBody()
{
	for (size_t i = 1; i < body_.size(); i++)
		if (body_.front().x == body_[i].x && body_.front().y == body_[i].y)
			return true;
	return false;
}

Vector2 Snake::GetHead() const
{
	return body_.front();
}

std::deque<Vector2> Snake::GetBody() const
{
	return body_;
}