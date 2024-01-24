#ifndef UTILS
#define UTILS
#include "Complex.hpp"

template<class T>
typename std::enable_if<!is_complex<T>::value, bool>::type
	nearZero(const T &val)
{
	if (val <= 0.00001 && val >= -0.00001)
		return true;
	return false;
}

bool nearZero(const Complex& val)
{
	if (val.real_part() <= 0.00001 && val.real_part() >= -0.00001 &&
		val.complex_part() <= 0.00001 && val.complex_part() >= -0.00001)
		return true;
	return false;
}

#endif