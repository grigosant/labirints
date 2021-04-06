#include "BinTreeLab.h"

BinaryTreeLabirint::BinaryTreeLabirint()
	:Labirint()
{
	BTLabirintCreating();
}
BinaryTreeLabirint::BinaryTreeLabirint(int a, int b)
	:Labirint(a, b)
{
	BTLabirintCreating();
}
BinaryTreeLabirint::BinaryTreeLabirint(int a, int b, Cell point)
	: Labirint(a, b, point)
{
	BTLabirintCreating();
}
bool BinaryTreeLabirint::BTLabirintCreating()
{
	for (int i = 1; i < y; i = i + 2)
	{
		for (int j = 1; j < x; j = j + 2)
		{
			unsigned int randDirect = getRandomDirection();

			if (!couldMakePath(randDirect, j, i))
			{
				randDirect = 1 - randDirect;	//сменить направление
				if (!couldMakePath(randDirect, j, i))
					continue;	//угловая клетка
			}

			if (!randDirect)	//нужно проложить путь вверх
			{
				setCellValue(false, j , i - 1);
			}
			else	//нужно проложить путь вправо
			{
				setCellValue(false, j + 1, i);
			}
		}
	}
	return true;
}


inline bool BinaryTreeLabirint::couldMakePath(unsigned int direction, int a, int b)
{
	/*if (!direction && b == 1)
		return false;
	if (direction && a == x - 2)
		return false;
	return true;*/

	return !(!direction && b == 1) && !(direction && a == x - 2);
}