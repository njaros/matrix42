#include "vectorialLib.hpp"

using namespace ft;

int main()
{
	Vector<int>	v1(linearCombination({
												{1, 0, 0},
												{0, 1, 0},
												{0, 0, 1}
	}, {5, -2, 4}));

	std::cout << "v1 = " << v1 << '\n';

	Matrix<float>	m({
							   {1.0, 2.1, 0},
							   {4.8, 0.2, -1.98}
	});

	Vector<float>	v2(linearCombination(m, {1.1, 1.5}));
	std::cout << "v2 = " << v2 << '\n';

	return 0;
}