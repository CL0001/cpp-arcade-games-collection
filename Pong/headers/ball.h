#pragma once

#include "raylib.h"

class Ball
{
public:
	Ball() = default;
	~Ball() = default;

	void Init();

	void Draw();

	void Update(Rectangle player, Rectangle enemy, int& player_score, int& enemy_score);

	Vector2 GetPosition() const;

private:
	Vector2 position_;
	Vector2 speed_;
	float radius_;
};