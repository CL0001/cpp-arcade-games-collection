#pragma once

#include <deque>

#include "raylib.h"

class Apple
{
public:
	Apple() = default;
	~Apple();

	void Init();

	void Spawn(const std::deque<Vector2>& snake_body);

	void Draw();

	Rectangle GetHitbox() const;

private:
	Texture2D sprite_;
	
	Vector2 position_;
};