#include "../includes/vectorialLib.hpp"

using namespace ft;

int main()
{
	Vector v = lerp({147, 14444, 985, -456}, {0, 0, 1, -1000}, 0.1);
	std::cout << "vector v = " << v << '\n';
	Matrix m = lerp(	{
												{1, 2},
												{1, 2}},
								{
												{10, 10},
												{10, 10}},
												0.99);
	char c = lerp('a', 'f', 0.8);
	Matrix	single = lerp({{1}}, {{150}}, 0.8);
	Matrix	error = lerp(	{
												{1, 0, 0},
												{0, 1, 0},
												{0, 0, 1}},
											{
												{1, 1},
												{1, 1},
												{1, 1}},
											   0.1);
	Vector	farAway(lerp({1., 2.}, {4., 2.}, 124.8));
	std::cout << "matrix m = \n" << m << '\n';
	std::cout << "char c = " << c << '\n';
	std::cout << "matrix single = \n" << single << '\n';
	std::cout << "matrix error = \n" << error << '\n';
	std::cout << "Vector farAway = " << farAway << '\n';

std::cout << "\n>>subject exemples\n\n";

	std::cout << lerp(0., 1., 0.) << "\n\n";
	std::cout << lerp(0., 1., 1.) << "\n\n";
	std::cout << lerp(0., 1., 0.5) << "\n\n";
	std::cout << lerp(21., 42., 0.3) << "\n\n";
	std::cout << lerp({2., 1.}, {4., 2.}, 0.3) << "\n\n";
	std::cout << lerp({{2., 1.}, {3., 4.}}, {{20., 10.}, {30., 40.}}, 0.5) << "\n\n";

	return 0;
}