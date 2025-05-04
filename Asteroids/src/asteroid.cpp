#include "asteroid.h"

#include <cmath>

#include <random>
#include <numbers>

Asteroid::Asteroid(Vector2 spawn_position, int size) :
	position_(spawn_position),
	radius_(size * 10)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist_velocity(1, 10);
	std::uniform_real_distribution<> dist_rotation(0.0, 360.0);
	std::uniform_real_distribution<> dist_rotation_speed(10.0f, 50.0f);
	std::uniform_int_distribution<> dist_sides(6, 12);
	std::uniform_real_distribution<> dist_angle(0.0f, 360.0f);
	std::uniform_real_distribution<> dist_radius(0.8f, 1.2f);

	velocity_.x = dist_velocity(gen);
	velocity_.y = dist_velocity(gen);

	rotation_ = dist_rotation(gen);
	rotation_speed_ = dist_rotation_speed(gen);
	rotation_direction_ = dist_velocity(gen) > 5 ? -1 : 1;

	int sides = dist_sides(gen);
	for (int i = 0; i < sides; i++)
	{
		float angle = dist_angle(gen);
		float distance = radius_ * dist_radius(gen);

		vertices_.emplace_back(
			Vector2{
				static_cast<float>(position_.x + distance * cos(angle * (std::numbers::pi / 180.0f))),
				static_cast<float>(position_.y + distance * sin(angle * (std::numbers::pi / 180.0f)))
			}
		);
	}
}

void Asteroid::Draw()
{
	DrawPolyLines(position_, vertices_.size(), radius_, rotation_, WHITE);
}

void Asteroid::Update()
{

}

void Asteroid::Move()
{

}

void Asteroid::WrapAroundScreen()
{

}

Vector2 Asteroid::GetPosition() const
{
	return position_;
}

float Asteroid::GetRadius() const
{
	return radius_;
}

