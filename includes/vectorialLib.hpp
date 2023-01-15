#ifndef VECLIB
#define VECLIB

#include "Vector.hpp"

namespace ft
{

	//Given the vector space base "vectorSpace" and the coefficients list, you obtain the vector constructed following those rules :
	//Each vector which compose the vectorSpace is multiplied by his coefficient in the list, then you add them all to get the vector.
	//{v1, v2, ..., vn-1, vn} is the vectorSpace, {a1, a2, ... ,an-1, an} is the coefficient list.
	//constructed vector = a1 * v1 + a2 * v2 + ... + an-1 * vn-1 + an * vn.
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

	//Linear intERPolation : lerp.
	//lerp can give you any point in same line containing lhs ans rhs.
	//In scalar range [0, 1], you got any point between lhs and rhs.
	//In scalar range ]-inf, 0[, you got any point before lhs.
	//In scalar range ]1, inf[, you got any point after rhs.
	//In scalar range ]-inf, inf[, you got any point of the precedents ranges.
	template<class T> T	lerp(const T &lhs, const T &rhs, double scalar)
	{
		return (((1 - scalar) * lhs) + (scalar * rhs));
	}

	//Given 2 vectors v1 and v2 belong to T^3 where T is your chosen type
	//This returns v1 ^ v2
	template<class T> Vector<T>	crossProduct3D(const Vector<T> &lhs, const Vector<T> &rhs)
	{
		if (lhs.size() != 3 || rhs.size() != 3)
			return Vector<T>();
		return (Vector<T>({lhs[1] * rhs[2] - rhs[1] * lhs[2],
						   lhs[2] * rhs[0] - rhs[2] * lhs[0],
						   lhs[0] * rhs[1] - rhs[0] * lhs[1]}));
	}

}

#endif