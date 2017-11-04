#pragma once
#include <math.h>

struct Vec3
{
	union
	{
		float e[3];
		struct
		{
			float x, y, z;
		};
		struct
		{
			float r, g, b;
		};
	};

	Vec3() {}
	Vec3(float s) :x(s), y(s), z(s) {}
	Vec3(float x, float y, float z) : x(x), y(y), z(z) {}
	Vec3(const float v[3])
	{
		e[0] = v[0];
		e[1] = v[1];
		e[2] = v[2];
	}
	Vec3(const Vec3& other) : x(other.x), y(other.y), z(other.z) {}
	
	Vec3& operator=(const Vec3& other)
	{
		x = other.x;
		y = other.y;
		z = other.z;

		return *this;
	}

	float& operator[](int i)
	{
		return e[i];
	}

	const float& operator[](int i) const
	{
		return e[i];
	}

	Vec3& operator+=(const Vec3& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;

		return *this;
	}

	Vec3& operator-=(const Vec3& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;

		return *this;
	}

	Vec3& operator*=(const Vec3& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;

		return *this;
	}

	Vec3& operator/=(const Vec3& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;

		return *this;
	}

	Vec3& operator*=(float s)
	{
		x *= s;
		y *= s;
		z *= s;

		return *this;
	}

	Vec3& operator/=(float s)
	{
		x /= s;
		y /= s;
		z /= s;

		return *this;
	}

	Vec3& operator+()
	{
		return *this;
	}

	Vec3& operator-()
	{
		x = -x;
		y = -y;
		z = -z;

		return *this;
	}

	bool operator==(const Vec3& other) const
	{
		return x == other.x && y == other.y && z == other.z;
	}

	bool operator!=(const Vec3& other) const
	{
		return x != other.x || y != other.y || z != other.z;
	}

	float dot(const Vec3& other) const
	{
		return x*other.x + y*other.y + z*other.z;
	}

	float lengthSq() const
	{
		return dot(*this);
	}

	float length() const
	{
		return sqrtf(lengthSq());
	}

	Vec3& normalize()
	{
		float l = 1.0f/length();
		x *= l;
		y *= l;
		z *= l;

		return *this;
	}

};

Vec3 operator+(const Vec3& lhs, const Vec3& rhs)
{
	return Vec3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

Vec3 operator-(const Vec3& lhs, const Vec3& rhs)
{
	return Vec3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

Vec3 operator*(const Vec3& lhs, const Vec3& rhs)
{
	return Vec3(lhs.x*rhs.x, lhs.y*rhs.y, lhs.z*rhs.z);
}

Vec3 operator/(const Vec3& lhs, const Vec3& rhs)
{
	return Vec3(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z);
}

Vec3 operator*(float s, const Vec3& v)
{
	return Vec3(s*v.x, s*v.y, s*v.z);
}

Vec3 operator*(const Vec3& v, float s)
{
	return Vec3(v.x*s, v.y*s, v.z*s);
}

Vec3 operator/(float s, const Vec3& v)
{
	return Vec3(s / v.x, s / v.y, s / v.z);
}

Vec3 operator/(const Vec3& v, float s)
{
	return Vec3(v.x / s, v.y / s, v.z / s);
}

float dot(const Vec3& lhs, const Vec3& rhs)
{
	return lhs.x*rhs.x + lhs.y*rhs.y + lhs.z*rhs.z;
}

Vec3 cross(const Vec3& rhs, const Vec3& lhs)
{
	return Vec3(lhs.y*rhs.z - lhs.z*rhs.y, lhs.z*rhs.x - lhs.x*rhs.z, lhs.x*rhs.y - lhs.y*rhs.x);
}

Vec3 normalize(const Vec3& v)
{
	float l = 1.0f/v.length();
	return v*l;
}