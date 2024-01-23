#include "../includes/vectorialLib.hpp"

using namespace ft;

int main()
{
	Vector<int>	v1({1, -2, 4});

	std::cout << "for vector v1 = " << v1 << '\n';
	std::cout << "Manhattan norm = " << v1.normManhattan() << '\n';
	std::cout << "Square Norm = " << v1.normSquare() << '\n';
	std::cout << "Euclidean Norm = " << v1.normEuclidean() << '\n';
	std::cout << "Infinite Norm = " << v1.normInfinite() << "\n\n";

	Vector<float>	v2({-4.38, -52.78, 47.1});

	std::cout << "for vector v2 = " << v2 << '\n';
	std::cout << "Manhattan norm = " << v2.normManhattan() << '\n';
	std::cout << "Square Norm = " << v2.normSquare() << '\n';
	std::cout << "Euclidean Norm = " << v2.normEuclidean() << '\n';
	std::cout << "Infinite Norm = " << v2.normInfinite() << '\n';

	Vector u1({0, 0, 0,});
	std::cout << u1.normManhattan() << ", " << u1.normEuclidean() << ", " << u1.normInfinite() << '\n';

	u1 = {1, 2, 3};
	std::cout << u1.normManhattan() << ", " << u1.normEuclidean() << ", " << u1.normInfinite() << '\n';

	u1 = {-1, -2};
	std::cout << u1.normManhattan() << ", " << u1.normEuclidean() << ", " << u1.normInfinite() << '\n';

	return 0;
}