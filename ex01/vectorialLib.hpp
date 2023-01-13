#ifndef VECLIB
#define VECLIB

#include "Vector.hpp"

namespace ft
{

	template<class T> Vector<T> linearCombination(const Matrix<T> &vectorSpace, const Vector<T> &coefficients)
	{
		if (vectorSpace.fail() || !coefficients.size() || vectorSpace.high() != coefficients.size())
		{
			std::cerr << "Warning: lineaCombination: non associative arguments\n";
			return (Vector<T>());
		}
		typename Vector<T>::const_iterator	cit = coefficients.begin();
		typename Matrix<T>::const_iterator	citM = vectorSpace.begin();
		Vector<T>	vec;
		while (cit != coefficients.end())
		{
			vec += *citM * *cit;
			++cit;
			++citM;
		}
		return vec;
	}

	template<class T> Vector<T> linearCombination(const Matrix<T> &vectorSpace, const std::initializer_list<T> &coefficients)
	{
		if (vectorSpace.fail() || !coefficients.size() || vectorSpace.high() != coefficients.size())
		{
			std::cerr << "Warning: lineaCombination: non associative arguments\n";
			return (Vector<T>());
		}
		typename std::initializer_list<T>::const_iterator	cit = coefficients.begin();
		typename Matrix<T>::const_iterator	citM = vectorSpace.begin();
		Vector<T>	vec;
		while (cit != coefficients.end())
		{
			vec += *citM * *cit;
			++cit;
			++citM;
		}
		return vec;
	}

	template<class T> Vector<T> linearCombination(const std::initializer_list<Vector<T> > &vectorSpace, const Vector<T> &coefficients)
	{
		if (!vectorSpace.size() || coefficients.size() != vectorSpace.size())
		{
			std::cerr << "Warning: lineaCombination: non associative arguments\n";
			return (Vector<T>());
		}
		typename std::initializer_list<Vector<T> >::size_type	check = vectorSpace.begin()->size();
		for (typename std::initializer_list<Vector<T> >::const_iterator	citCheck = vectorSpace.begin(); citCheck != vectorSpace.end(); ++citCheck)
		{
			if (citCheck->size() != check)
			{
				std::cerr << "Warning: lineaCombination: non sense vector space\n";
				return (Vector<T>());
			}
		}
		typename Vector<T>::const_iterator cit = coefficients.begin();
		typename std::initializer_list<Vector<T> >::const_iterator citM = vectorSpace.begin();
		Vector<T> vec;
		while (cit != coefficients.end()) {
			vec += *citM * *cit;
			++cit;
			++citM;
		}
		return vec;
	}

	template<class T> Vector<T> linearCombination(const std::initializer_list<Vector<T> > &vectorSpace, const std::initializer_list<T> &coefficients)
	{
		if (!vectorSpace.size() || coefficients.size() != vectorSpace.size())
		{
			std::cerr << "Warning: lineaCombination: non associative arguments\n";
			return (Vector<T>());
		}
		typename std::initializer_list<Vector<T> >::size_type	check = vectorSpace.begin()->size();
		for (typename std::initializer_list<Vector<T> >::const_iterator	citCheck = vectorSpace.begin(); citCheck != vectorSpace.end(); ++citCheck)
		{
			if (citCheck->size() != check)
			{
				std::cerr << "Warning: lineaCombination: non sense vector space\n";
				return (Vector<T>());
			}
		}
		typename std::initializer_list<T>::const_iterator cit = coefficients.begin();
		typename std::initializer_list<Vector<T> >::const_iterator citM = vectorSpace.begin();
		Vector<T> vec;
		while (cit != coefficients.end()) {
			vec += *citM * *cit;
			++cit;
			++citM;
		}
		return vec;
	}
}

#endif