#include "Matrix.hpp"

int main(void)
{
	Vector<int>	a{1, 2, 3};
	Vector<int>	b{1, 1, 1};
	Vector<int> c{0, 1};

	Matrix<int>	m{
		{1, 1},
		{2, 2}
	};

	a += b;
	a.displayVector();
	a += c;
	a.displayVector();

	c = a + b;
	c.displayVector();
	a.displayVector();
	c = a * 2;
	c.displayVector();
	c = a * 2.3;
	c.displayVector();
	c = 7 * a;
	c.displayVector();
	a *= 0.7;
	a.displayVector();


	m.displayMatrix();
	return 0;
}