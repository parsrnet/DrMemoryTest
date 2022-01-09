#include <iostream>

#include "Matrix.h"

int main(int argc, char* argv[])
{
	int arr[3][3] = 
	{
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 }
	};

	Matrix<3,3> m(arr);

	m.print();

	std::cout	<< "(X: 0, Y: 2) = " << m.at(0, 2) << std::endl
				<< "(expected: 7)" << std::endl;

	m.set(0, 2, 25);

	std::cout	<< "(X: 0, Y: 2) = " << m.at(0, 2) << std::endl
				<< "(expected: 25)" << std::endl;

	Matrix<3, 3> m2(arr);

	m2 = m2.product(2);

	std::cout << "Multiplied by 2" << std::endl;

	m2.print();

	int arr2[2][3] =
	{
		{ 1, 2, 3 },
		{ 4, 5, 6 }
	};
	int arr3[3][2] =
	{
		{ 7, 8 },
		{ 9, 10 },
		{ 11, 12 }
	};

	Matrix<3, 2> lhs(arr2);
	Matrix<2, 3> rhs(arr3);

	lhs.print();
	std::cout << "DOT PRODUCT" << std::endl;
	rhs.print();

	Matrix<2, 2> dp = lhs.dotProduct(rhs);

	dp.print();

	std::cout << "Press {enter} to continue..."; std::cin.get();

	return 0;
}