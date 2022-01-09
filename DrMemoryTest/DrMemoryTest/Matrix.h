#pragma once

template<size_t Cols, size_t Rows, typename T = int>
class Matrix
{
private:
	int arr[Rows][Cols];

public:
	Matrix()
	{
		for (size_t y = 0; y < Rows; y++)
			for (size_t x = 0; x < Cols; x++)
				arr[y][x] = 0;
	}
	Matrix(int const (&nArr)[Rows][Cols])
	{
		std::memcpy(&arr, &nArr, sizeof(T) * Rows * Cols);
	}

	void print() const
	{
		std::cout << "{" << std::endl;
		for (size_t y = 0; y < Rows; y++)
		{
			std::cout << "\t{ ";
			for (size_t x = 0; x < Cols-1; x++)
			{
				std::cout << arr[y][x] << ", ";
			}
			std::cout << arr[y][Cols - 1] << " }" << std::endl;
		}
		std::cout << "}" << std::endl;
	}

	constexpr T at(int x, int y) const
	{
		if (x >= 0 && x < Cols
			&& y >= 0 && y < Rows)
			return arr[y][x];
		else throw new std::exception("array index out of bounds");
		return 0;
	}

	constexpr void set(int x, int y, T val)
	{
		if (x >= 0 && x < Cols
			&& y >= 0 && y < Rows)
			arr[y][x] = val;
		else throw new std::exception("array index out of bounds");
	}

	constexpr Matrix<Cols, Rows> copy() const
	{
		Matrix m(arr);
		return m;
	}

	constexpr Matrix<Cols, Rows> product(T coefficient) const
	{
		Matrix m(arr);
		for (size_t y = 0; y < Rows; y++)
			for (size_t x = 0; x < Cols; x++)
				m.set(x, y, m.at(x, y) * coefficient);
		return m;
	}

	template<size_t Cols2, size_t Rows2>
	constexpr Matrix<Cols2, Rows> dotProduct(const Matrix<Cols2, Rows2> &m) const
	{
		Matrix<Cols2, Rows> retval;
		if (Cols == Rows2)
		{
			for (size_t y = 0; y < Rows; y++)
			{
				for (size_t x = 0; x < Cols2; x++)
				{
					for (size_t i = 0; i < Cols; i++)
						retval.set(x, y, retval.at(x, y) + at(i, y) * m.at(x, i));
				}
			}
		}
		else throw new std::exception();

		return retval;
	}
};