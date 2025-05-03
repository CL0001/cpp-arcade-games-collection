#pragma once

#include <memory>
#include <optional>

#include "spaceship.h"
#include "asteroid_manager.h"

class Game
{
public:
	Game();
	~Game();

	void Run();

	void Draw();

	void Update();

	void Reset();

private:
	std::shared_ptr<Texture2D> sprite_atlas_;
	std::optional<Spaceship> player_;
	std::optional<AsteroidManager> asteroid_manager_;

	bool game_over_ = false;
};