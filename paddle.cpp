#include "paddle.h"
#include "raylib.h"

PlayerPaddle::PlayerPaddle()
{
	width = 180;
	height = 10;
	posX = (GetScreenWidth() / 2.0f) - (width / 2);
	posY = GetScreenHeight() * 9.0f / 10.0f; 
}

void PlayerPaddle::Draw()
{
	DrawRectangle((int) posX, (int) posY, width, height, WHITE);
}