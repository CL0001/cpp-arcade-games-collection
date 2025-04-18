#include "button.h"

#include <string>

#include "config.h"

void Button::Init(const std::string& content)
{
	content_ = content;

	const float screenWidth = GetScreenWidth();
	const float screenHeight = GetScreenHeight();

	const float verticalOffset = 100.0f;

	const float centerX = screenWidth / 2.0f;
	const float centerY = screenHeight / 2.0f + verticalOffset;

	background_ = {
		centerX - BUTTON_BACKGROUND_WIDTH / 2.0f,
		centerY - BUTTON_BACKGROUND_HEIGHT / 2.0f,
		BUTTON_BACKGROUND_WIDTH,
		BUTTON_BACKGROUND_HEIGHT
	};

	body_ = {
		centerX - BUTTON_BODY_WIDTH / 2.0f,
		centerY - BUTTON_BODY_HEIGHT / 2.0f,
		BUTTON_BODY_WIDTH,
		BUTTON_BODY_HEIGHT
	};
}

void Button::Draw()
{
	DrawRectangleRec(background_, ELEMENT_COLOR);
	DrawRectangleRec(body_, BACKGROUND_COLOR);
	DrawText(content_.c_str(), body_.x + 20, body_.y + 30, 50, ELEMENT_COLOR);
}

bool Button::CheckButtonClicked()
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), body_))
	{
		return true;
	}
	return false;
}
