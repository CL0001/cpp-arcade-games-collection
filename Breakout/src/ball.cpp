#include "ball.h"

#include "level.h"

#include "config.h"

void Ball::Init()
{
	position_ = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
	radius_ = 10;
	move_speed_ = { 5.0f, 5.0f };
}

void Ball::Draw()
{
	DrawCircle(position_.x, position_.y, radius_, WHITE);
}

void Ball::Move()
{

}

void Ball::ChangeDirection(Rectangle brick)
{
	if (position_.x > brick.x)
		move_speed_.x = -(move_speed_.x + config::ball_acceleration);

	// TODO: finish collision handling and acceleration
}

Vector2 Ball::GetPosition() const
{
	return position_;
}

float Ball::GetRadius() const
{
	return radius_;
}