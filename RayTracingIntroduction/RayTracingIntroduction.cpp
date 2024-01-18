#include "Camera.h"
#include "DialectricMaterial.h"
#include "HittableCollection.h"
#include "LambertianMaterial.h"
#include "Sphere.h"
#include "MetalMaterial.h"


using namespace std;


int main(int argc, char* argv[])
{
	//World
	HittableCollection world;


	double radius = cos(pi / 4);

	shared_ptr<Material> leftMat = make_shared<LambertianMaterial>(Color(0, 0, 1));
	shared_ptr<Material> rightMat = make_shared<LambertianMaterial>(Color(1, 0, 0));

	world.Add(make_shared<Sphere>(Position(-radius, 0, -1), radius, leftMat));
	world.Add(make_shared<Sphere>(Position(radius, 0, -1), radius, rightMat));


	/*shared_ptr<Material> groundMat = make_shared<LambertianMaterial>(Color(0.8, 0.8, 0.0));
	shared_ptr<Material> leftMat = make_shared<DialectricMaterial>(1.5);
	shared_ptr<Material> centerMat = make_shared<LambertianMaterial>(Color(0.1, 0.2, 0.5));
	shared_ptr<Material> rightMat = make_shared<MetalMaterial>(Color(0.8, 0.6, 0.2), 0.0);


	world.Add(make_shared<Sphere>(Position(0, -100.5, -1), 100, groundMat));
	world.Add(make_shared<Sphere>(Position(0,      0, -1), 0.5, centerMat));
	world.Add(make_shared<Sphere>(Position(-1.1,   0, -1), 0.5, leftMat));
	world.Add(make_shared<Sphere>(Position(-1,	   0, -1), -0.4, leftMat));
	world.Add(make_shared<Sphere>(Position(1.1,    0, -1), 0.5, rightMat));*/


	Camera camera(400, 16.0 / 9.0, 100, 50, 90);
	camera.Render(world);
	return 0;


}
