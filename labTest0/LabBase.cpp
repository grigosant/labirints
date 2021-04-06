#include "LabBase.h"
#include <iostream>

Labirint::Labirint()
	: x(3), y(3)
{
	initLabirint();
}
Labirint::Labirint(int a, int b)
	: x(a * 2 + 1), y(b * 2 + 1)
{
	initLabirint();
}

Labirint::Labirint(int a, int b, Cell point)
	:x(a * 2 + 1), y(b * 2 + 1), zeroPoint(point)
{
	initLabirint();
}

void Labirint::initLabirint()
{
	bodyLab.resize(y);
	//for (size_t i = 0; i < y; i++)
	//	bodyLab[i].resize(x);
	//for (size_t i = 0; i < y; i++)
	//{
	//	for (size_t j = 0; j < x; j++)
	//	{
	//		if (!(i % 2) || !(j % 2))//нечетные строки или (четные строки и нечетные столбцы)
	//		{
	//			bodyLab[i][j] = true;
	//		}
	//		else {
	//			bodyLab[i][j] = false;
	//		}
	//	}
	//}
	//более быстрая инициализация
	for (size_t i = 0; i < y; i++)
		bodyLab[i].resize(x, true);
	for (size_t i = 1; i < y; i = i + 2)
	{
		for (size_t j = 1; j < x; j = j + 2)
		{
			if (i % 2 && j % 2)	//(нечетные строки и нечетные столбцы)
			{
				bodyLab[i][j] = false;
			}
		}
	}


	srand(time(0));	//начальная инициализация рандомогенератора
}

void Labirint::print()
{
	for (size_t i = 0; i < y; i++)
	{
		for (size_t j = 0; j < x; j++)
		{
			if (bodyLab[i][j])
				std::cout << "*";
			else
				std::cout << " ";
		}
		std::cout << std::endl;
	}
}

bool Labirint::setCellValue(bool newstate, size_t a, size_t b)
{
	if (a < x && b < y) {
		bodyLab[b][a] = newstate;
		return true;
	}
	return false;
}

unsigned int Labirint::getRandomDirection()
{
	return rand() % 2;	//0 ~ вверх, 1 ~ вправо
}

Labirint::~Labirint()
{
	bodyLab.clear();
}