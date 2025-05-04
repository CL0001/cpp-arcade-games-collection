#pragma once

#include <vector>

#include "raylib.h"

class Asteroid
{
public:
	Asteroid(Vector2 spawn_position, int size);
	~Asteroid() = default;

	void Draw();
	void Update();

	void Move();
	void WrapAroundScreen();

	Vector2 GetPosition() const;
	float GetRadius() const;

private:
	Vector2 position_;
	float radius_;

	std::vector<Vector2> vertices_;

	Vector2 velocity_;
	float rotation_;
	int rotation_direction_;
	int rotation_speed_;
};