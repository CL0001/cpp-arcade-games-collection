#pragma once

#include "raylib.h"

class Paddle
{
public:
	void Init();

	void Draw();

	void Update();

private:
	Texture2D sprite_;
	Rectangle hitbox_;
};