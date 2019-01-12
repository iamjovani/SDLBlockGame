#include"Utility.h"

using namespace Util;

Util::Vector2::Vector2()
	:x(0.0f), y(0.0f)
{
}

Util::Vector2::Vector2(float x, float y)
	: x(x), y(y)
{}

Util::Vector2& Vector2::add(Vector2& other)
{
	this->x += other.x;
	this->y += other.y;

	return *this;
}

Util::Vector2& Vector2::subtract(Vector2& other)
{
	this->x -= other.x;
	this->y -= other.y;

	return *this;
}

Util::Vector2& Vector2::multiply(Vector2& other)
{
	this->x *= other.x;
	this->y *= other.y;

	return *this;
}

Util::Vector2& Vector2::divide(Vector2& other)
{
	this->x /= other.x;
	this->y /= other.y;

	return *this;
}

Vector2 Util::add(Vector2 left, Vector2 right)
{
	return left.add(right);
}

Vector2 Util::subtract(Vector2 left, Vector2 right)
{
	return left.subtract(right);
}

Vector2 Util::multiply(Vector2 left, Vector2 right)
{
	return left.multiply(right);
}

Vector2 Util::divide(Vector2 left, Vector2 right)
{
	return left.divide(right);
}


Vector2 Util::operator+(Vector2 left, Vector2 right)
{
	return add(left, right);
}


Vector2 Util::operator-(Vector2 left, Vector2 right)
{
	return subtract(left, right);
}

Vector2 Util::operator*(Vector2 left, Vector2 right)
{
	return multiply(left, right);
}

Vector2 Util::operator/(Vector2 left, Vector2 right)
{
	return divide(left, right);
}


std::ostream& Util::operator<<(std::ostream& stream, Vector2 vector)
{
	stream << vector.x << ", " << vector.y;

	return stream;
}

