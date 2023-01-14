#include "vectorialLib.hpp"

using namespace ft;

int main()
{

	Vector<float>	v1({1, 2, 3});
	Vector<float>	v2({4, 5, 6});

	Vector<float>	v3 = crossProduct3D(v1, v2);
	std::cout << v3 << '\n';

	v1 = {0, 0, 1};
	v2 = {1, 0, 0};
	v3 = crossProduct3D(v1, v2);
	std::cout << v3 << '\n';

	v1 = {4, 2, -3};
	v2 = {-2, -5, 16};
	v3 = crossProduct3D(v1, v2);
	std::cout << v3 << '\n';

	return 0;
}