#include "../includes/vectorialLib.hpp"

int main()
{
	Complex i1(3, 4);

	Complex i2(7, 1);

	Complex i3(0, 1);

	Complex i4(-1, 0);

	std::cout << i1 << "\n\n";
	std::cout << i2 << "\n\n";
	std::cout << i1 + i2 << "\n\n";
	std::cout << i1 - i2 << "\n\n";
	std::cout << i1 * i2 << "\n\n";
	std::cout << i1 / i2 << "\n\n";

	ft::Vector<Complex> v1({i1, i2});
	ft::Vector<Complex> v2({i3, i4});

	std::cout << v1 << "\n\n";
	std::cout << v2 << "\n\n";

	std::cout << dot(v1, v2) << "\n\n";

	v1 = {i1, i2, i3};
	v2 = {i4, i3, i1};

	std::cout << v1 << "\n\n";
	std::cout << v2 << "\n\n";
	std::cout << dot(v1, v2) << "\n\n";
	std::cout << crossProduct3D(v1, v2) << "\n\n";


	ft::Matrix<Complex> m1({{Complex(1, 2), Complex(2, 3), Complex(7, -2)},
							{Complex(3, 4), Complex(4, -5), Complex(1, -8)},
							{Complex(-4, 4), Complex(0, 0), Complex(17, -1.2)}});

	std::cout << m1.inverse() << "\n\n";

	std::cout << m1 * m1.inverse() << "\n\n";

	return 0;
}