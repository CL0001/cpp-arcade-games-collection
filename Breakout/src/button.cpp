#include "button.h"

#include "raylib.h"

void Button::Init(int position_x, int position_y, std::string text)
{
	hitbox_ = { static_cast<float>(position_x), static_cast<float>(position_y), 300, 100 };
	text_ = text;
}

void Button::Draw()
{
	DrawRectangleRec(hitbox_, WHITE);

	Vector2 text_position{
		hitbox_.x + (hitbox_.width - MeasureTextEx(GetFontDefault(), text_.c_str(), 50, 0.0f).x) / 2,
		hitbox_.y + (hitbox_.height - MeasureTextEx(GetFontDefault(), text_.c_str(), 50, 0.0f).y) / 2
	};

	DrawText(text_.c_str(), text_position.x, text_position.y, 50, BLACK);
}

bool Button::IsPressed()
{
	if (CheckCollisionPointRec(GetMousePosition(), hitbox_) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		return true;

	return false;
}