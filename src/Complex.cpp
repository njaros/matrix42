# include "../includes/Complex.hpp"

Complex::Complex() : _a(0.), _b(0.) {}
Complex::Complex(const Complex& other) : _a(other._a), _b(other._b) {}
Complex::Complex(double a, double b): _a(a), _b(b) {}

Complex::~Complex() {}

Complex& Complex::operator=(const Complex& other)
{
	if (&other != this)
	{
		_a = other._a;
		_b = other._b;
	}
	return *this;
}

Complex& Complex::operator+=(const Complex& rhs)
{
	_a += rhs._a;
	_b += rhs._b;
	return *this;
}

Complex& Complex::operator-=(const Complex& rhs)
{
	_a -= rhs._a;
	_b -= rhs._b;
	return *this;
}

Complex Complex::operator+(const Complex& rhs) const
{
	Complex ret(*this);

	return ret += rhs;
}

Complex Complex::operator-(const Complex& rhs) const
{
	Complex ret(*this);

	return ret -= rhs;
}

Complex& Complex::operator*=(const Complex& rhs)
{
	const double tmpA = _a;

	_a *= rhs._a;
	_a -= (_b * rhs._b);
	_b = (tmpA * rhs._b) + (_b * rhs._a);
	return *this;
}

Complex	Complex::operator*(const Complex& rhs) const
{
	Complex ret(*this);

	return ret *= rhs;
}

Complex& Complex::operator/=(Complex rhs)
{
	if (rhs.complex_part())
	{
		*this *= rhs.conjugate();
		rhs *= rhs.conjugate();
	}
	_a /= rhs._a;
	_b /= rhs._a;
	return *this;
}

Complex	Complex::operator/(const Complex& rhs)
{
	Complex ret(*this);

	return ret /= rhs;
}

bool Complex::operator!() const
{
	return !_a && !_b;
}

Complex Complex::conjugate() const
{
	return Complex(this->_a, -this->_b);
}

double Complex::real_part() const
{
	return _a;
}

double Complex::complex_part() const
{
	return _b;
}

std::ostream& operator<<(std::ostream& o, const Complex& c)
{
	o << '(' << c.real_part() << " + " << c.complex_part() << "i)";
	return o;
}