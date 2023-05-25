#include "ball.h"
#include "paddle.h"
#include "raylib.h"

int startGame(PlayerPaddle& paddle, bool& start, Ball& ball);
int gameOver(PlayerPaddle paddle, bool& start, Ball& ball);
int paddleControl(PlayerPaddle& paddle);

int main()
{
	InitWindow(800, 600, "Pong Crusher");

	Ball ball;
	PlayerPaddle userPaddle;
	bool start = false;

	while (!WindowShouldClose()) // Detects window close button or escape key
	{
		// Bounces ball and disallows ball from going out of screen
		if (ball.getCenterX() >= GetScreenWidth() || ball.getCenterX() <= 0)
		{
			ball.setSpeedX(ball.getSpeedX() * -1);
		}
		if (ball.getCenterY() <= 0)
		{
			ball.setSpeedY(ball.getSpeedY() * -1);
		}
		// Checks if ball collides with paddle, bounces ball if it does
		if (CheckCollisionCircleRec(Vector2{ ball.getCenterX(), ball.getCenterY() }, ball.getRadius(),
			Rectangle {userPaddle.getPosX(), userPaddle.getPosY(), 180, 10}))
		{
			ball.setSpeedY(ball.getSpeedY() * -1);
		}

		SetWindowState(FLAG_VSYNC_HINT); // Sets FPS according to user's computer
		ClearBackground(BLACK);
		BeginDrawing();
		
		startGame(userPaddle, start, ball);
		gameOver(userPaddle, start, ball);
		paddleControl(userPaddle);
		
		DrawFPS(10,10);
		EndDrawing();
	}


	return 0;
}

// Begins the game
int startGame(PlayerPaddle& paddle, bool& start, Ball& ball)
{
	ball.Draw();
	paddle.Draw();

	if (start == false)
	{
		DrawText("Press enter key to start the game!", (GetScreenWidth() / 2) - paddle.getWidth(), GetScreenHeight() / 2, 20, WHITE);

		if (IsKeyPressed(KEY_ENTER))
		{
			start = true;
		}
	}
	else
	{
		ball.Move();
	}
	return 0;
}

// Checks if ball hits the bottom and gives game over text
int gameOver(PlayerPaddle paddle, bool& start, Ball& ball)
{
	if (ball.getCenterY() >= GetScreenHeight())
	{	
		start = false;

		ball.setCenterX(GetScreenWidth() / 2.0f);
		ball.setCenterY(GetScreenHeight() * 6.0f / 7.0f);

		ball.setSpeedY(ball.getSpeedY() * -1); // so that the ball goes up instead of down when resetting the game

	}
	return 0;
}

// Player control of paddle
int paddleControl(PlayerPaddle& paddle)
{
	// controls paddle using left and right keys
	if ( (paddle.getPosX() >= 0) && (paddle.getPosX() <= GetScreenWidth() - paddle.getWidth()) )
	{
		if (IsKeyDown(KEY_LEFT))
		{
			paddle.setPosX(paddle.getPosX() - 500.0f * GetFrameTime());
		}
		if (IsKeyDown(KEY_RIGHT))
		{
			paddle.setPosX(paddle.getPosX() + 500.0f * GetFrameTime());
		}
	}
	// prevents paddle from  going off of the screen
	else
	{
		if (paddle.getPosX() <= 0)
		{
			paddle.setPosX(paddle.getPosX() + 1);
		}
		else if (paddle.getPosX() >= (GetScreenWidth() - paddle.getWidth()) )
		{
			paddle.setPosX(paddle.getPosX() - 1);
		}
	}
	return 0;
}