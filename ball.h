#ifndef BALL_HEADER
#define BALL_HEADER

class Ball
{
public:
// constructor
	Ball();

	// accessor functions
	float getCenterX() { return centerX; }
	float getCenterY() { return centerY; }
	float getSpeedX() { return speedX; }
	float getSpeedY() { return speedY; }
	int getRadius() { return radius; }

	// mutator functions
	void setCenterX(float x) { centerX = x; }
	void setCenterY(float y) { centerY = y; }
	void setSpeedX(float speed) { speedX = speed; }
	void setSpeedY(float speed) { speedY = speed; }

	// general functions
	void Draw();
	void Move();

private:
	float centerX, centerY, speedX, speedY;
	float const radius = 10;
};


#endif
