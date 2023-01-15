#include "../includes/vectorialLib.hpp"

using namespace ft;

int main()
{

	Matrix<float> b = {
			{1, 2},
			{3, 4}
	};

	Matrix<float> c = {
			{1, 2},
			{2, 4}
	};

	Matrix<float> d = {
			{8, 5, -2, 4, 28},
			{4, 2.5, 20, 4, -4},
			{8, 5, 1, 4, 17}
	};

	Matrix<float>	e = {
			{0, 0, 1},
			{1, 2, 3},
			{0, 4, 1.2},
			{2, 2, 2}
	};

	Matrix<float> f = e.rowEchelon();

	b.rowEchelonSelf();
	b.displayMatrixLn();
	c.rowEchelonSelf();
	c.displayMatrixLn();
	d.rowEchelonSelf();
	d.displayMatrixLn();
	f.displayMatrixLn();
	return 0;
}