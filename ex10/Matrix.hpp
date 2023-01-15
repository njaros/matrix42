#ifndef MAT
#define MAT

#include "Vector.hpp"

namespace ft {

	template<class T>
	class Vector;

	template<class T>
	class Matrix {

	public:

		typedef T value_type;
		typedef ft::Vector<value_type> row;
		typedef std::initializer_list<typename row::inilist> inilist;
		typedef ft::Vector<row> matrix;
		typedef typename std::initializer_list<value_type>::size_type	width_size;
		typedef typename inilist::size_type	high_size;
		typedef typename row::size_type row_size_type;
		typedef typename matrix::size_type matrix_size_type;
		typedef typename matrix::iterator	iterator;
		typedef typename matrix::const_iterator	const_iterator;

	protected :

		matrix				_mat;
		row_size_type		_width;
		matrix_size_type	_high;
		bool				_fail;

		void	_killUpDown(matrix_size_type killer, row_size_type nonZero)
		{
			for (matrix_size_type idx = 0; idx < _high; ++idx)
			{
				if (idx != killer)
				{
					_mat[idx] -= (_mat[idx][nonZero] * _mat[killer]);
				}
			}
		}

	public:

		Matrix() : _width(0), _high(0), _fail(false) {}

		Matrix(matrix_size_type n, row_size_type m, const value_type &val = value_type()) : _mat(n) , _width(m), _high(n), _fail(false)
		{
			for (iterator it = _mat.begin(); it != _mat.end(); ++it)
				*it = Vector<value_type>(m, val);
		}

		Matrix(const inilist &il) : _high(il.size()), _fail(false) {
			for (typename inilist::const_iterator cit = il.begin(); cit != il.end(); ++cit)
			{
				if (cit == il.begin())
					_width = cit->size();
				else if (cit->size() != _width)
				{
					_mat.getVector().clear();
					_width = 0;
					_high = 0;
					_fail = true;
					return;
				}
				_mat.getVector().push_back(row(*cit));
			}
		}

		Matrix(const Matrix &o) : _mat(o._mat), _width(o._width), _high(o._high), _fail(o._fail) {}

		~Matrix() {}

		Matrix &operator=(const Matrix &o) {	_mat = o._mat; _width = o._width;
												_high = o._high; _fail = o._fail;
												return *this;}

		//GETTER, DISPLAYS

		matrix	&getMatrix() {return _mat;}

		void displayMatrix() const {
			for (const_iterator cit = _mat.begin(); cit != _mat.end(); ++cit)
			{
				if (cit != _mat.end() - 1)
					cit->displayVectorLn();
				else
					cit->displayVector();
			}
		}

		void displayMatrixLn() const {
			for (const_iterator cit = _mat.begin(); cit != _mat.end(); ++cit)
				cit->displayVectorLn();
			std::cout << '\n';
		}

		Vector<value_type>			&operator[](matrix_size_type n)			{return _mat[n];}
		const Vector<value_type>	&operator[](matrix_size_type n)	const	{return _mat[n];}

		//UTILITY

		bool				fail()	const	{return _fail;}
		bool				good()	const	{return !_fail;}
		bool				empty()	const	{return _mat.getVector().empty();}
		row_size_type		width()	const	{return _width;}
		matrix_size_type	high()	const	{return _high;}
		iterator 			begin()			{return _mat.begin();}
		const_iterator 		begin()	const	{return _mat.begin();}
		iterator 			end()			{return _mat.end();}
		const_iterator 		end()	const	{return _mat.end();}

		//OPERATORS

		Matrix	&operator+=(const Matrix &rhs)
		{
			if (_mat.getVector().empty())
				*this = rhs;
			else if (_width == rhs._width && _high == rhs._high)
			{
				const_iterator cit = rhs.begin();
				for (iterator it = _mat.begin(); it != _mat.end(); ++it)
				{
					*it += *cit;
					++cit;
				}
			}
			return *this;
		}

		Matrix	&operator-=(const Matrix &rhs)
		{
			if (_mat.getVector().empty())
				*this = rhs * -1;
			if (_width == rhs._width && _high == rhs._high)
			{
				const_iterator cit = rhs.begin();
				for (iterator it = _mat.begin(); it != _mat.end(); ++it) {
					*it -= *cit;
					++cit;
				}
			}
			return *this;
		}

		Matrix	operator+(const Matrix &rhs) const
		{
			Matrix	m(*this);
			return (m += rhs);
		}

		Matrix	operator-(const Matrix &rhs) const
		{
			Matrix	m(*this);
			return (m -= rhs);
		}

		template<class K> Matrix	&operator*=(const K &scalar)
		{
			for (iterator it = _mat.begin(); it != _mat.end(); ++it)
				*it *= scalar;
			return (*this);
		}

		Matrix	operator*(const Matrix &rhs) const
		{
			if (_width != rhs._high)
				return Matrix();
			Matrix	m(_high, rhs._width);
			for (matrix_size_type i = 0; i < m._high; ++i)
			{
				for (row_size_type j = 0; j < m._width; ++j)
				{
					matrix_size_type l = 0;
					for (row_size_type k = 0; k < _width; ++k)
					{
						m[i][j] += _mat[i][k] * rhs[l][j];
						++l;
					}
				}
			}
			return m;
		}

		Vector<value_type>	operator*(const Vector<T> &v) const
		{
			return (v * *this);
		}

		template<class K> Matrix	operator*(const K &scalar)	const
		{
			Matrix	m(*this);
			return (m *= scalar);
		}

		//PROPER MATRIX OPERATORS

		//Given a square matrix m belong to K^(n*n),
		//trace(n) is the sum of each component of the diagonal of m.
		value_type	trace()	const
		{
			value_type	result = value_type();
			if (_width != _high)
			{
				std::cerr << "Warning: Matrix::trace: this isn't a square matrix.\n";
				return result;
			}
			for (matrix_size_type idx = 0; idx < _high; ++idx)
				result += _mat[idx][idx];
			return result;
		}

		Matrix	transpose() const
		{
			Matrix	transposed(_width, _high);
			for (matrix_size_type idxH = 0; idxH < transposed._high; ++idxH)
			{
				for (row_size_type idxW = 0; idxW < transposed._width; ++idxW)
					transposed[idxH][idxW] = _mat[idxW][idxH];
			}
			return transposed;
		}

		Matrix	&rowEchelonSelf()
		{
			for (matrix_size_type idx = 0; idx != _high; ++idx)
			{
				row_size_type	nonZero = _mat[idx]._firstNonZero();
				matrix_size_type	toSwap = idx;
				matrix_size_type	current = idx + 1;
				while (current < _high)
				{
					row_size_type	currentNonZero = _mat[current]._firstNonZero();
					if (currentNonZero < nonZero)
					{
						toSwap = current;
						nonZero = currentNonZero;
					}
					++current;
				}
				if (nonZero == _width)
					break;
				_mat[idx].swap(_mat[toSwap]);
				value_type	divide = _mat[idx][nonZero];
				_mat[idx] /= divide;
				_killUpDown(idx, nonZero);
			}
			return *this;
		}

		Matrix	rowEchelon() const
		{
			Matrix	result(*this);
			return (result.rowEchelonSelf());
		}

	};

	template<class T, class K> Matrix<T>	operator*(const K &scalar, const Matrix<T> &m)
	{
		return (m * scalar);
	}

	template<class T>
	std::ostream &operator<<(std::ostream &o, const Matrix<T> &m)
	{
		for (typename Matrix<T>::const_iterator cit = m.begin(); cit != m.end(); ++cit)
		{
			o << *cit;
			if (cit != m.end() - 1)
				o << '\n';
		}
		return o;
	}

}
#endif