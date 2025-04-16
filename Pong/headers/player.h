#pragma once

#include "raylib.h"

class Player
{
public:
	Player() = default;
	~Player() = default;

	void Init();

	void Draw();

	void Update();

	Rectangle GetPaddle() const;

private:
	Rectangle paddle_;
};