#pragma once

#include <deque>

#include "raylib.h"

enum class HeadDirection
{
	Left = 0,
	Up,
	Right,
	Down
};

class Snake
{
public:
	void Init();

	void Draw();

	void Update();

	void ChangeDirection();

	void AddBodySegment();

	Vector2 GetHead() const;
	std::deque<Vector2> GetBody() const;

private:
	Texture2D sprite_;
	std::deque<Vector2> body_;
	
	HeadDirection direction_;

	float move_timer_;
	float move_interval_;
};