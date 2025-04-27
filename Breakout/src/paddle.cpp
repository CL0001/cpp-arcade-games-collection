#include "paddle.h"

#include <string>

#include "config.h"

void Paddle::Init()
{
	sprite_ = LoadTexture((std::string(ASSETS_PATH) + "paddle.png").c_str());

	hitbox_ = {
		.x = GetScreenWidth() / 2.0f - 64,
		.y = GetScreenHeight() - 64.0f,
		.width = config::sprite_width * 2 * config::scale,
		.height = config::sprite_height * config::scale
	};
}

void Paddle::Draw()
{
	Rectangle texture_coords{
		.x = 0.0f,
		.y = 0.0f,
		.width = config::sprite_width * config::scale,
		.height = config::sprite_height
	};

	DrawTexturePro(sprite_, texture_coords, hitbox_, { 0.0f, 0.0f }, 0.0f, WHITE);
}

void Paddle::Update()
{
	HandleInput();
}

void Paddle::HandleInput()
{
	const float moveSpeed = 10.0f;

	if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
	{
		hitbox_.x -= moveSpeed;
		if (hitbox_.x < 0)
			hitbox_.x = 0;
	}

	if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
	{
		hitbox_.x += moveSpeed;
		if (hitbox_.x + hitbox_.width > GetScreenWidth())
			hitbox_.x = GetScreenWidth() - hitbox_.width;
	}
}