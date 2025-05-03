#include "spaceship.h"

#include <memory>

#include "raylib.h"

Spaceship::Spaceship(std::shared_ptr<Texture2D> sprite_atlas, Rectangle texture_data_, Vector2 position) :
	sprite_atlas_(sprite_atlas),
	texture_data_(texture_data_),
	position_(position)
{
}

void Spaceship::Draw()
{

}

void Spaceship::Update()
{

}

void Spaceship::Reset()
{

}

