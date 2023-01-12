#include <vector>
#include <iostream>
#include <initializer_list>

template <class T>
class Vector
{

public :

	typedef T									value_type;
	typedef std::vector<value_type>				container;
	typedef typename container::size_type		size_type;
	typedef typename container::iterator		iterator;
	typedef typename container::const_iterator	const_iterator;

protected :

	container	_components;
	friend class Matrix;

public :

	Vector() {}
	Vector(const std::initializer_list<value_type> &il) : _components(il) {}
	Vector(const Vector &other) : _components(other._components) {}
	~Vector() {}
	Vector	&operator=(const Vector &other)
	{
		if (&other != this)
			_components = other._components;
		return (*this);
	}

	//GETTER, DISPLAY

	const std::vector<value_type>	&getVector()	const	{return _components;}

	void	displayVector()	const
	{
		std::cout << "vector components are :";
		for (const_iterator cit = _components.begin(); cit != _components.end(); ++cit)
			std::cout << " " << *cit;
		std::cout << '\n';
	}

	//UTILITY

	size_type	size()	const	{return _components.size();}

	//OPERATOR

	Vector	&operator+=(const Vector &rhs)
	{
		if (rhs.size() == size())
		{
			size_type	idx = 0;
			for (iterator it = _components.begin(); it != _components.end(); ++it)
				*it += rhs._components[idx++];
		}
		return (*this);
	}

	Vector	&operator-=(const Vector &rhs)
	{
		if (rhs.size() == size())
		{
			size_type	idx = 0;
			for (iterator it = _components.begin(); it != _components.end(); ++it)
				*it -= rhs._components[idx++];
		}
		return (*this);
	}

	Vector	operator+(const Vector &rhs)	const
	{
		Vector	salut(*this);
		return (salut += rhs);
	}

	Vector	operator-(const Vector &rhs)	const
	{
		Vector	salut(*this);
		return (salut -= rhs);
	}

	template<class K>
	Vector	&operator*=(const K &scalar)
	{
		for (iterator it = _components.begin(); it != _components.end(); ++it)
			*it *= scalar;
		return (*this);
	}

	template<class K>
	Vector	operator*(const K &scalar)	const
	{
		Vector	du(*this);
		return (du *= scalar);
	}

};

template<class T, class K>
Vector<T>	operator*(const K &scalar, const Vector<T> &rhs)
{
	Vector<T>	icoli(rhs);
	return (icoli *= scalar);
}