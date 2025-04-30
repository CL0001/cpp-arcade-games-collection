#pragma once

#include "raylib.h"

#include "ball.h"

class Paddle
{
public:
	~Paddle();

	void Init();

	void Draw();

	void Move();

	void CheckCollision(Ball& ball);

	void HandleInput();

	void Reset();

private:
	Texture2D sprite_;
	Rectangle hitbox_;
};