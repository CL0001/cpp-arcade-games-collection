#pragma once

#include <string>

#include "raylib.h"

class Button
{
public:
	void Init(int position_x, int position_y, std::string text);

	void Draw();

	bool IsPressed();

private:
	Rectangle hitbox_{};
	std::string text_;
};