#pragma once
#include "Ray.h"

class HitInfo
{
public:
	Position coordinates;
	Vector3 normal;
	double time;
	bool frontFace;

	void SetFaceNormal(const ray& rRay, const Vector3& outwardNormal)
	{
		//NOTE : The outwardNormal vector should be unit length
		frontFace = Dot(rRay.GetDirection(), outwardNormal) < 0;
		normal = frontFace ? outwardNormal : -outwardNormal;
	}

};

class Hittable
{
public:
	virtual ~Hittable() = default;
	virtual bool Hit(const ray& rRay, double rayTimeMin, double rayTimeMax, HitInfo& hitInfo) const = 0;
};
