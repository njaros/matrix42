#pragma once
#include <type_traits>
#include <iostream>

class Complex
{
	double _a;
	double _b;

public:

	Complex();
	Complex(const Complex&other);
	Complex(double a, double b);

	~Complex();

	Complex& operator=(const Complex& other);

	template< class scalar >
	typename std::enable_if<std::is_fundamental<scalar>::value, Complex&>::type
		operator=(const scalar& n)
	{
		_a = n;
		_b = 0;
		return *this;
	}

	Complex& operator+=(const Complex& rhs);

	Complex& operator-=(const Complex& rhs);

	Complex operator+(const Complex& rhs) const;

	Complex operator-(const Complex& rhs) const;

	Complex& operator*=(const Complex& rhs);

	Complex operator*(const Complex& rhs) const;

	template<class scalar>
	typename std::enable_if<std::is_fundamental<scalar>::value, Complex&>::type
		operator*=(const scalar& k)
	{
		_a *= k;
		_b *= k;
		return *this;
	}

	template<class scalar>
	typename std::enable_if<std::is_fundamental<scalar>::value, Complex>::type
		operator*(const scalar& k) const
	{
		Complex ret(*this);

		return ret *= k;
	}

	Complex& operator/=(Complex rhs);

	Complex operator/(const Complex& rhs);

	template<class scalar>
	typename std::enable_if<std::is_fundamental<scalar>::value, Complex&>::type
		operator/=(const scalar& k)
	{
		_a /= k;
		_b /= k;
		return *this;
	}

	template<class scalar>
	typename std::enable_if<std::is_fundamental<scalar>::value, Complex>::type
		operator/(const scalar& k) const
	{
		Complex ret(*this);

		return ret /= k;
	}

	bool operator!() const;

	Complex conjugate() const;

	double real_part() const;

	double complex_part() const;
};

std::ostream& operator<<(std::ostream& o, const Complex& c);

template < typename T >
struct isComplex : public std::false_type {};

template <>
struct isComplex<Complex> : public std::true_type {};

template <typename T>
struct is_complex : public isComplex<T> {};

template <class scalar>
typename std::enable_if<std::is_fundamental<scalar>::value, Complex>::type
	operator*(const scalar& k, const Complex c)
{
	return c * k;
}

template <class scalar>
typename std::enable_if<std::is_fundamental<scalar>::value, Complex>::type
	operator/(const scalar& k, const Complex c)
{
	return c / k;
}