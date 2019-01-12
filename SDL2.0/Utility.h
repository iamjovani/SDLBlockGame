#pragma once
#include <iostream>

namespace Util
{

	struct Vector2
	{
		Vector2();
		Vector2(float x, float y);
		Vector2& add(Vector2& other);
		Vector2& subtract(Vector2& other);
		Vector2& multiply(Vector2& other);
		Vector2& divide(Vector2& other);

		friend Vector2 add(Vector2 left, Vector2 right);
		friend Vector2 subtract(Vector2 left, Vector2 right);
		friend Vector2 multiply(Vector2 left, Vector2 right);
		friend Vector2 divide(Vector2 left, Vector2 right);

		friend Vector2 operator+(Vector2 left, Vector2 right);
		friend Vector2 operator-(Vector2 left, Vector2 right);
		friend Vector2 operator*(Vector2 left, Vector2 right);
		friend Vector2 operator/(Vector2 left, Vector2 right);
		friend std::ostream& operator<<(std::ostream& stream, Vector2 vector);

		float x, y;
	};

}

