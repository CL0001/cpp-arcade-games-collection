#pragma once

#include "raylib.h"

class Ball
{
public:
	void Init();

	void Draw();

	void Move();

	void ChangeDirectionPaddle(Rectangle paddle);
	void ChangeDirectionBrick(Rectangle brick);

	Vector2 GetPosition() const;
	float GetRadius() const;

private:
	Vector2 position_;
	float radius_;

	Vector2 move_speed_;
};