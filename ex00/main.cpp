#include "../includes/vectorialLib.hpp"

using namespace ft;

int main()
{
std::cout << "===Vector section===\n\n";

	Vector<int>	a{1, 2, 3};
	Vector<int>	b{1, 1, 1};
	Vector<int> c{0, 1};

	Matrix<int>	m{
		{1, 1},
		{2, 2}
	};

	std::cout << "a = " << a << '\n';
	std::cout << "b = " << b << '\n';
	std::cout << "c = " << c << "\n\n";

	a += b;
	std::cout << "a += b\na = ";
	a.displayVectorLn();

	a += c;
	std::cout << "\na += c\n";
	std::cout << "a = " << a << "\n\n";

	c = a + b;
	std::cout << "c = a + b\nc = ";
	c.displayVectorLn();
	std::cout << "a = ";
	a.displayVectorLn();

	c = a * 2;
	std::cout << "\nc = a * 2\nc = ";
	c.displayVectorLn();
	c = a * 2.3;
	std::cout << "\nc = a * 2.3\nc = ";
	c.displayVectorLn();
	c = 7 * a;
	std::cout << "\nc = 7 * a\nc = ";
	c.displayVectorLn();
	a *= 0.7;
	std::cout << "\na *= 0.7\na = ";
	a.displayVectorLn();

	Vector<int>	d;

	std::cout << "\nd = " << d << "\n\n";
	d += c;

	std::cout << "d += c\nd = " << d << "\n\n";

std::cout << ">>subject exemples<<\n\n";

	Vector<float> u({2., 3.});
	const Vector<float> v({5., 7.});
	std::cout << "u = " << u << "\nv = " << v << "\n\n";
	u += v;

	std::cout << "u += v\nu = " << u << "\n\n";

	u = {2., 3.};
	u -= v;

	std::cout << "u -= v\nu = " << u << "\n\n";

	u = {2., 3.};
	u *= 2.;

	std::cout << "u *= 2.\nu = " << u << "\n\n";

std::cout << "===Matrix section===\n\n";

	std::cout << "m = \n" << m << "\n\n";

	Matrix<int> n{
			{1, 2},
			{3, 41}
	};

	if (n.good())
		std::cout << "n = \n" << n << "\n\n";
	else
		std::cout << "matrix n failed\n\n";

	m += n;
	std::cout << "m += n\nm =\n" << m << "\n\n";

	m *= 0.5;
	std::cout << "m *= 0.5\nm =\n" << m << "\n\n";

	Matrix<int>	k(2 * n);

	std::cout << "use of copy constructor : Matrix<int>	k(2 * n);\n k = \n" << k << "\n\n";

	k -= n *= 3;

	std::cout << "k -= n *= 3\nk =\n" << k << "\n\n";
	std::cout << "n =\n" << n << "\n\n";

std::cout << ">>subject exemples<<\n\n";

	Matrix<float> uM{
		{1., 2.},
		{3., 4.}
	};

	const Matrix<float> vM{
		{7., 4.},
		{-2., 2,}
	};

	std::cout << "u =\n" << u << '\n';
	std::cout << "v =\n" << v << "\n\n";

	uM += vM;
	std::cout << "u += v\nu =\n" << uM << "\n\n";

	uM = {{1., 2.}, {3., 4.}};

	uM -= vM;
	std::cout << "u -= v\nu =\n" << uM << "\n\n";

	uM = {{1., 2.}, {3., 4.}};
	uM *= 2.;
	std::cout << "u *= 2.\nu =\n" << uM << "\n\n";


	return 0;
}