#pragma once



class Vec2
{
public:
	float x, y;

	Vec2() {}
	Vec2(float x, float y): x(x), y(y) {}
	Vec2(float val) : x(val), y(val) {}

	float operator[](int right);
};