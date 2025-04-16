#include "ball.h"

#include <cmath>

#include "raylib.h"

#include "game.h"

void Ball::Init()
{
	position_ = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
	speed_ = { -4.0f, 2.0f };
	radius_ = 10;
}

void Ball::Draw()
{
	DrawCircle(position_.x, position_.y, radius_, WHITE);
}

void Ball::Update(Rectangle player, Rectangle enemy, int& player_score, int& enemy_score)
{
	if (CheckCollisionCircleRec(position_, radius_, player) || CheckCollisionCircleRec(position_, radius_, enemy))
		speed_.x = -(speed_.x > 0 ? speed_.x + 0.1f : speed_.x - 0.1f);

	if (position_.y + radius_ < 0 || position_.y + radius_ > GetScreenHeight())
		speed_.y = -(speed_.y > 0 ? speed_.y + 0.001f : speed_.y - 0.001f);

	if (position_.x - radius_ < 0)
	{
		position_ = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
		enemy_score++;
		speed_.x = -4.0f;
		speed_.y = 2;
	}

	if (position_.x + radius_ > GetScreenWidth())
	{
		position_ = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
		player_score++;
		speed_.x = -4.0f;
		speed_.y = -2;
	}

	position_.x += speed_.x;
	position_.y += speed_.y;
}

Vector2 Ball::GetPosition() const
{
	return position_;
}