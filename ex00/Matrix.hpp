#include "Vector.hpp"

template<class T>
class Matrix
{

public:

	typedef T							value_type;
	typedef Vector<value_type>			row;
	typedef Vector<row>					matrix;
	typedef typename row::size_type		row_size_type;
	typedef typename matrix::size_type	matrix_size_type;

protected :

	matrix _mat;

public:

	Matrix() {}
	Matrix(const std::initializer_list<std::initializer_list<value_type> >) {
		for (std::initializer_list<std::initializer_list<value_type> >::const_i)
	}
	Matrix(const Matrix &o) : _mat(o._mat) {}
	~Matrix() {}
	Matrix	&operator=(const Matrix &o)	{_mat = o._mat;}

	void displayMatrix()	const
	{
		_mat.displayVector();
	}
};
