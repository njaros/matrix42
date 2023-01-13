#include "Vector.hpp"

using namespace ft;

int main()
{
	Vector<int>	a{1, 2, 3};
	Vector<int>	b{1, 1, 1};
	Vector<int> c{0, 1};

	Matrix<int>	m{
		{1, 1},
		{2, 2}
	};

	a += b;
	a.displayVectorLn();
	a += c;
	std::cout << " a = " << a << '\n';

	c = a + b;
	c.displayVectorLn();
	a.displayVectorLn();
	c = a * 2;
	c.displayVectorLn();
	c = a * 2.3;
	c.displayVectorLn();
	c = 7 * a;
	c.displayVectorLn();
	a *= 0.7;
	a.displayVectorLn();

	Vector<int>	d;
	d += c;

	std::cout << "d = " << d << '\n';

	std::cout << "m = \n" << m << '\n';

	Matrix<int> n{
			{1, 2},
			{3, 41}
	};

	if (n.good())
		std::cout << "n = \n" << n << '\n';
	else
		std::cout << "matrix n failed\n";

	m += n;
	std::cout << m << '\n';

	m *= 0.5;
	std::cout << m << '\n';

	Matrix<int>	k(2 * n);

	std::cout << k << '\n';

	k -= n *= 3;

	std::cout << k << '\n';
	std::cout << n << '\n';

	return 0;
}