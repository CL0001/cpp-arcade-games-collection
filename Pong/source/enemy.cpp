#include "enemy.h"

#include <iostream>

#include "raylib.h"

#include "config.h"

void Enemy::Init()
{
	paddle_ = { GetScreenWidth() - PADDLE_WIDTH - PADDLE_MARGIN, GetScreenHeight() / 2 - PADDLE_HEIGHT, PADDLE_WIDTH, PADDLE_HEIGHT };
}

void Enemy::Draw()
{
	DrawRectangleRec(paddle_, WHITE);
}

void Enemy::Update(Vector2 ball_position)
{
	if (ball_position.y > paddle_.y + PADDLE_HEIGHT)
		paddle_.y += 2;
	
	if (ball_position.y < paddle_.y)
		paddle_.y -= 2;
}

Rectangle Enemy::GetPaddle() const
{
	return paddle_;
}