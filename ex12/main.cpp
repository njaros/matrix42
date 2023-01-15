#include "vectorialLib.hpp"

using namespace ft;

int main()
{

	Matrix<float>	a({
							   {2, 0, 0},
							   {0, 2, 0},
							   {0, 0, 2}
	});

	a.displayMatrixLn();
	a.inverse().displayMatrixLn();

	Matrix<float>	b({
							   {1, 0, 0},
							   {0, 1, 0},
							   {0, 0, 1}
	});

	b.displayMatrixLn();
	b.inverse().displayMatrixLn();

	Matrix<float>	c({
							   {8, 5, -2},
							   {4, 7, 20},
							   {7, 6, 1}
	});

	c.displayMatrixLn();
	c.inverse().displayMatrixLn();

	Matrix<float>	d({
							   {1, 2, 3},
							   {4, 5, 6}
	});

	d.displayMatrixLn();
	d.inverse().displayMatrixLn();

	Matrix<float>	e = {
			{8, 5, -2, 4},
			{4, 2.5, 20, 4},
			{8, 5, 1, 4},
			{28, -4, 17, 1}
	};

	e.displayMatrixLn();
	e.inverse().displayMatrixLn();

	Matrix<float>	f = {
			{7, 4, 1},
			{1, 0, 0},
			{14, 8, 2}
	};

	f.displayMatrixLn();
	f.inverse().displayMatrixLn();

	return 0;
}