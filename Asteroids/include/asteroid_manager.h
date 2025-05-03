#pragma once

#include <memory>

#include "raylib.h"

class AsteroidManager
{
public:
	AsteroidManager(std::shared_ptr<Texture2D> sprite_atlas);

	void Draw();
	void Update();
	void Reset();

private:
};