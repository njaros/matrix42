#include "../includes/vectorialLib.hpp"

using namespace ft;

int main()
{

	Matrix<float> a = {
			{-1, 1},
			{1, -1}
	};

	Matrix<float> b = {
			{2, 0, 0},
			{0, 2, 0},
			{0, 0, 2}
	};

	Matrix<float> c = {
			{8, 5, -2},
			{4, 7, 20},
			{7, 6, 1}
	};

	Matrix<float>	d = {
			{8, 5, -2, 4},
			{4, 2.5, 20, 4},
			{8, 5, 1, 4},
			{28, -4, 17, 1}
	};

	Matrix<float>	e = {
			{0, 1, 0, 0},
			{1, 0, 0, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 1}
	};

	a.displayMatrixLn();
	std::cout << "has for triangular form : \n";
	a.triangular().displayMatrixLn();
	std::cout << "has determinant = " << a.determinant() << '\n';
	b.displayMatrixLn();
	std::cout << "has for triangular form : \n";
	b.triangular().displayMatrixLn();
	std::cout << "has determinant = " << b.determinant() << '\n';
	c.displayMatrixLn();
	std::cout << "has for triangular form : \n";
	c.triangular().displayMatrixLn();
	std::cout << "has determinant = " << c.determinant() << '\n';
	d.displayMatrixLn();
	std::cout << "has for triangular form : \n";
	d.triangular().displayMatrixLn();
	std::cout << "has determinant = " << d.determinant() << '\n';
	e.displayMatrixLn();
	std::cout << "has for triangular form : \n";
	e.triangular().displayMatrixLn();
	std::cout << "has determinant = " << e.determinant() << '\n';
	return 0;
}