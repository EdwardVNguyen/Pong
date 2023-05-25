#include "ball.h"
#include "raylib.h"

// constructor
Ball::Ball()
{
	centerX = GetScreenWidth() / 2.0f; // Sets ball in the middle
	centerY = GetScreenHeight() * 6.0f / 7.0f; // Sets the ball 6/7 of the screen height
	
	speedX = 300.0f; // Starting ball speed
	speedY = 300.0f;
}

// general functions
void Ball::Draw()
{
	DrawCircle((int) centerX, (int) centerY, radius, WHITE);
}

void Ball::Move()
{
	setCenterX(getCenterX() + (getSpeedX() * GetFrameTime()) );
	setCenterY(getCenterY() - (getSpeedY() * GetFrameTime()) );
}