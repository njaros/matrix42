#include "../includes/vectorialLib.hpp"

using namespace ft;

int main()
{
	int	dotProductInt(dot<int>({2, 2, 1}, {0, -4, -8}));
	std::cout << "dotProductInt = " << dotProductInt << '\n';

	Vector<float> v1({0.1, -4.0001, 7.22});
	Vector<float> v2({0.5, 1.5, 3});
	Vector<float> null({0, 0, 0});

	std::cout << "v1 = " << v1 << '\n';
	std::cout << "v2 = " << v2 << '\n';
	std::cout << "null vector is " << null << '\n';
	std::cout << "dot<float>(v1, v2) = " << dot<float>(v1, v2) << '\n';
	std::cout << "dot<float>(v2, v1) = " << dot<float>(v2, v1) << '\n';
	std::cout << "v1.dot(v2) = " << v1.dot(v2) << '\n';
	std::cout << "v2.dot(v1) = " << v2.dot(v1) << '\n';
	std::cout << "dot<float>(v1, null) = " << dot<float>(v1, null) << '\n';

	std::cout << "dot<int>({1, 2}, {1}) = " << dot<int>({1, 2}, {1}) << '\n';

	return 0;
}