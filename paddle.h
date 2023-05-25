#ifndef PADDLE_HEADER
#define PADDLE_HEADER

class PlayerPaddle
{
public:
	// constructor
	PlayerPaddle();

	// accessor functions
	float getPosX() { return posX; }
	float getPosY() { return posY; }
	int getWidth() { return width; }
	int getHeight() { return height; }

	// mutator functions
	void setPosX(float x) { posX = x; }
	void setPosY(float y) { posY = y; }

	// general functions
	void Draw();

private:
	float posX, posY;
	int width, height;
};


#endif