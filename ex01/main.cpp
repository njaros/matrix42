#include "../includes/vectorialLib.hpp"

using namespace ft;

int main()
{
	Vector<int>	lc1(linearCombination({
												{1, 0, 0},
												{0, 1, 0},
												{0, 0, 1}
	}, {5, -2, 4}));

	std::cout << "lc1 = " << lc1 << '\n';

	Matrix<float>	m({
							   {1.0, 2.1, 0},
							   {4.8, 0.2, -1.98}
	});

	Vector<float>	lc2(linearCombination(m, {1.1, 1.5}));
	std::cout << "lc2 = " << lc2 << '\n';

	std::cout << "\n>>subject exemples<<\n\n";

	const Vector<float> e1({1., 0., 0.});
	const Vector<float> e2({0., 1., 0.});
	const Vector<float> e3({0., 0., 1.});

	const Vector<float> v1({1., 2., 3.});
	const Vector<float> v2({0., 10., -100.});

	std::cout << linearCombination({e1, e2, e3}, {10., -2, 0.5}) << "\n\n";

	std::cout << linearCombination({v1, v2}, {10., -2.}) << "\n\n";

	return 0;
}