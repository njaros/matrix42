#include "vectorialLib.hpp"

using namespace ft;

int main()
{
	Matrix<float>	m = lerp<Matrix<float> >({
												{1, 2},
												{1, 2}},
											  {
												{10, 10},
												{10, 10}},
												0.99);
	Vector<int>	v = lerp<Vector<int> >({147, 14444, 985, -456}, {0, 0, 1, -1000}, 0.1);
	char c = lerp<char>('a', 'f', 0.8);
	Matrix<int>	single = lerp<Matrix<int> >({{1}}, {{150}}, 0.8);
	Matrix<int>	error = lerp<Matrix<int> >({
													  {1, 0, 0},
													  {0, 1, 0},
													  {0, 0, 1}},
											  {
														{1, 1},
														{1, 1},
														{1, 1}},
													   0.1
											  );
	Vector<float>	farAway(lerp<Vector<float> >({1, 2}, {4, 2}, 124.8));
	std::cout << "matrix m = \n" << m << '\n';
	std::cout << "vector v = " << v << '\n';
	std::cout << "char c = " << c << '\n';
	std::cout << "matrix single = \n" << single << '\n';
	std::cout << "matrix error = \n" << error << '\n';
	std::cout << "Vector farAway = " << farAway << '\n';
	return 0;
}