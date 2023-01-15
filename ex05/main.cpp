#include "../includes/vectorialLib.hpp"

using namespace ft;

int main()
{
	Vector<float>	v1({8, 0});
	Vector<float>	v2({0, 1});
	Vector<float>	v3({1, 1});
	Vector<float>	v4({sqrt(3), 1});
	Vector<float>	v5({1, sqrt(3)});
	Vector<float>	v6({-1, 1});
	Vector<float>	v7({1, 2, 3});
	Vector<float>	v8({4, 5, 6});

	std::cout << v1.cos(v2) << " should be 0\n";
	std::cout << v1.cos(v3) << " should be 0.707107\n";
	std::cout << v1.cos(v6) << " should be -0.707107\n";
	std::cout << v1.cos(v4) << " should be 0.866025\n";
	std::cout << v1.cos(v5) << " should be 0.5\n";
	std::cout << v7.cos(v8) << " should be 0.974631\n";


	return 0;
}