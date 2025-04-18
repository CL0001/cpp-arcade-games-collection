#pragma once

#include <string>

#include "raylib.h"

class Button
{
public:
	void Init(const std::string& content);

	void Draw();

	bool CheckButtonClicked();

private:
	Rectangle background_;
	Rectangle body_;

	std::string content_;
};