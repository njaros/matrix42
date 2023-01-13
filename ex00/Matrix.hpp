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

		matrix		_mat;
		width_size 	_width;
		high_size 	_high;
		bool		_fail;

	public:

		Matrix() : _width(0), _high(0), _fail(false) {}

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
												_high = o._high; _fail = o._fail;}

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

		//UTILITY

		bool		fail()	const {return _fail;}
		bool		good()	const {return !_fail;}
		width_size	width() const {return _width;}
		high_size	high()	const {return _high;}
		iterator begin()				{return _mat.begin();}
		const_iterator begin()	const	{return _mat.begin();}
		iterator end()					{return _mat.end();}
		const_iterator end()	const	{return _mat.end();}

		//OPERATORS

		Matrix	&operator+=(const Matrix &rhs)
		{
			if (_width == rhs._width && _high == rhs._high)
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

		template<class K> Matrix	operator*(const K &scalar)	const
		{
			Matrix	m(*this);
			return (m *= scalar);
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