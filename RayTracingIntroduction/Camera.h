#pragma once
#include "Color.h"
#include "Hittable.h"

#include <iostream>

class Camera
{
public:
	Camera() = default;
	Camera(double imageWidth, double ratio, int samplePerPixel = 10, int bounces = 10, double vFoV = 90) :
	aspectRatio(ratio), width(imageWidth), sampleCount(samplePerPixel), maxBounces(bounces), verticalFoV(vFoV) {}

	void Render(const Hittable& rWorld);

private:
	int height;
	double aspectRatio, width;
	int sampleCount;
	int maxBounces;
	double verticalFoV;
	Position center, originPixelLocation;
	Vector3 pixelDeltaX, pixelDeltaY;

	void Initialize();
	Color RayColor(const Ray& rRay, int bouncesLeft, const Hittable& rWorld) const;
	Ray GetRay(int x, int y) const;
	Vector3 PixelSampleSquared() const;

};
