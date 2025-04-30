#include "ball.h"

#include "config.h"
#include "level.h"

void Ball::Init()
{
	position_ = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
	radius_ = 10;
	move_speed_ = { 0.0f, 3.0f };
}

void Ball::Draw()
{
	DrawCircle(position_.x, position_.y, radius_, WHITE);
}

void Ball::Move()
{
	position_.x += move_speed_.x;
	position_.y += move_speed_.y;

	if (position_.x - radius_ < 0)
	{
		position_.x = radius_;
		move_speed_.x *= -1;
	}

	if (position_.x + radius_ > GetScreenWidth())
	{
		position_.x = GetScreenWidth() - radius_;
		move_speed_.x *= -1;
	}

	if (position_.y - radius_ < 0)
	{
		position_.y = radius_;
		move_speed_.y *= -1;
	}
}

void Ball::ChangeDirectionPaddle(Rectangle paddle)
{
	float paddle_center = paddle.x + paddle.width / 2.0f;

	move_speed_.y = -std::abs(move_speed_.y);

	if (position_.x > paddle_center)
		move_speed_.x = std::abs(move_speed_.x + 2.5f);
	else
		move_speed_.x = -std::abs(move_speed_.x + 2.5f);
}

void Ball::ChangeDirectionBrick(Rectangle brick)
{
	float dx = position_.x - (brick.x + brick.width / 2.0f);
	float dy = position_.y - (brick.y + brick.height / 2.0f);

	float combined_half_width = brick.width / 2.0f + radius_;
	float combined_half_height = brick.height / 2.0f + radius_;

	float overlap_x = combined_half_width - std::abs(dx);
	float overlap_y = combined_half_height - std::abs(dy);

	if (overlap_x < overlap_y)
	{
		move_speed_.x = -move_speed_.x;
		move_speed_.x += (move_speed_.x > 0 ? config::ball_acceleration : -config::ball_acceleration);
	}
	else
	{
		move_speed_.y = -move_speed_.y;
		move_speed_.y += (move_speed_.y > 0 ? config::ball_acceleration : -config::ball_acceleration);
	}
}

Vector2 Ball::GetPosition() const
{
	return position_;
}

float Ball::GetRadius() const
{
	return radius_;
}

void Ball::Reset()
{
	position_ = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
	move_speed_ = { 0.0f, 3.0f };
}
