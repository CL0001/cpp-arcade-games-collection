#include "player.h"

#include "raylib.h"

#include "config.h"

void Player::Init()
{
	paddle_ = { PADDLE_MARGIN, GetScreenHeight() / 2.0f, PADDLE_WIDTH, PADDLE_HEIGHT };
}

void Player::Draw()
{
	DrawRectangleRec(paddle_, WHITE);
}

void Player::Update()
{
	if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
		paddle_.y -= 4;

	if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
		paddle_.y += 4;
}

Rectangle Player::GetPaddle() const
{
	return paddle_;
}
