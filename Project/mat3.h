#pragma once
#include "vec3.h"

struct Mat3
{
	union
	{
		Vec3 e[3];
		struct
		{
			Vec3 r1, r2, r3;
		};
	};
	
	Mat3() {}
	Mat3(float s) : r1(s), r2(s), r3(s) {}
	Mat3(float e11, float e12, float e13,
		float e21, float e22, float e23,
		float e31, float e32, float e33) 
		: r1(e11,e12,e13), r2(e21, e22, e23), r3(e31,e32,e33)
	{}
	Mat3(const Vec3& r1, const Vec3& r2, const Vec3& r3)
		: r1(r1), r2(r2), r3(r3) {}

	Mat3& operator=(const Mat3& other)
	{
		r1 = other.r1;
		r2 = other.r2;
		r3 = other.r3;

		return *this;
	}

	Mat3& operator+=(const Mat3& other)
	{
		r1 += other.r1;
		r2 += other.r2;
		r3 += other.r3;

		return *this;
	}

	Mat3& operator-=(const Mat3& other)
	{
		r1 -= other.r1;
		r2 -= other.r2;
		r3 -= other.r3;

		return *this;
	}

	Vec3 operator*(const Vec3& rhs) const
	{
		return Vec3(dot(r1, rhs), dot(r2, rhs), dot(r3, rhs));
	}
};
