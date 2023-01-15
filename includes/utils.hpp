#ifndef UTILS
#define UTILS

template<class T>
bool	nearZero(const T &val)
{
	if (val <= 0.00001 && val >= -0.00001)
		return true;
	return false;
}

#endif