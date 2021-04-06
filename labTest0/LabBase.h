#pragma once
#include <vector>
#include <ctime>
#include "cell.h"

class Labirint
{
public:
	Labirint();
	Labirint(int a, int b);
	Labirint(int a, int b, Cell point);
	~Labirint();
	void print();

protected:
	void initLabirint();
	//a - по горизонтали , b - по вертикали
	bool setCellValue(bool newstate, size_t a, size_t b);

	unsigned int getRandomDirection();

	size_t x, y;//число клеток в лабиринте в строке (и столбце) = 2 * n + 1; при счете с 0 на 1 меньше для индексации
				//x - по горизонтали , y - по вертикали
	Cell zeroPoint = { 0, 0 };
	std::vector<std::vector<bool>> bodyLab;	//1 - стена, 0 - пустота
};