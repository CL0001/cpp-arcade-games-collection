#pragma once

#include <memory>

#include "raylib.h"

class Spaceship
{
public:
	Spaceship(std::shared_ptr<Texture2D> sprite_atlas, Rectangle texture_data, Vector2 position);
	~Spaceship() = default;

	void Draw();
	void Update();
	void Reset();

private:
	std::weak_ptr<Texture2D> sprite_atlas_;
	Rectangle texture_data_;

	Vector2 position_;
};
