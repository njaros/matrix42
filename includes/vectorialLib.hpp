#ifndef VECLIB
#define VECLIB

#include "Vector.hpp"
#include <type_traits>
#include <initializer_list>

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
			std::cerr << "Warning: linearCombination: non associative arguments\n";
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

	//Template specializations for Vector and Matrix, that allows a cumfortable use of lerp

	template< class T >
	struct is_vector : public std::false_type {};

	template< class T >
	struct is_vector< Vector<T> > : public std::true_type {};

	template< class T >
	struct is_vector< const Vector<T> > : public std::true_type {};

	template< class T >
	struct is_inilist : public std::false_type {};

	template< class T >
	struct is_inilist< std::initializer_list<T> > : public std::true_type {};

	template< class T >
	struct is_inilist< const std::initializer_list<T> > : public std::true_type {};

	template< class T >
	struct is_matrix : public std::false_type {};

	template< class T >
	struct is_matrix< Matrix<T> > : public std::true_type {};

	template< class T >
	struct is_matrix< const Matrix<T> > : public std::true_type {};

	template< class T >
	struct is_matrix_inilist : public std::false_type {};

	template < class T >
	struct is_matrix_inilist< std::initializer_list< std::initializer_list< T > > > : public std::true_type {};

	template < class T >
	struct is_matrix_inilist< const std::initializer_list< std::initializer_list< T > > > : public std::true_type {};

	//Linear intERPolation : lerp.
	//lerp can give you any point in same line containing lhs ans rhs.
	//In scalar range [0, 1], you got any point between lhs and rhs.
	//In scalar range ]-inf, 0[, you got any point before lhs.
	//In scalar range ]1, inf[, you got any point after rhs.
	//In scalar range ]-inf, inf[, you got any point of the precedents ranges.
	template<class T>
	typename std::enable_if<std::is_integral<T>::value ||
							std::is_floating_point<T>::value ||
							is_matrix<T>::value ||
							is_vector<T>::value, T>::type
		lerp(const T &lhs, const T &rhs, double scalar)
	{
		return (((1 - scalar) * lhs) + (scalar * rhs));
	}

	template<class T>
	typename std::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value,
							Vector< double > >::type
		lerp(const std::initializer_list<T> &lhs, const std::initializer_list<T> &rhs, double scalar)
	{
		return (((1 - scalar) * Vector(lhs)) 
					+ (scalar * Vector(rhs)));
	}

	template<class T>
	typename std::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value,
							Matrix< double > >::type
		lerp(	const std::initializer_list<std::initializer_list< T > > &lhs,
				const std::initializer_list<std::initializer_list< T > > &rhs, double scalar)
	{
		return (((1 - scalar) * Matrix(lhs))
					+ (scalar * Matrix(rhs)));
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

	Matrix<double>	projection(double fov, double ratio, double near, double far)
	{
		Matrix proj(4, 4);

		double fovr = fov * 180/M_PI;
		proj[3][2] = -1.;
		proj[0][0] = 1. / (std::tan((fovr / 2.)) * ratio);
		proj[1][1] = 1. / std::tan((fovr / 2.));
		proj[2][2] = far / (near - far);
		proj[2][3] = -(far * near) / (far - near);

		return proj;
	}

}

#endif