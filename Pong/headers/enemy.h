#pragma once

#include "raylib.h"

class Enemy
{
public:
	Enemy() = default;
	~Enemy() = default;

	void Init();

	void Draw();

	void Update(Vector2 ball_position);

	Rectangle GetPaddle() const;

private:
	Rectangle paddle_;
};