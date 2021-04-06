#include "Sidewinder.h"


Sidewinder::Sidewinder()
	:Labirint()
{
	RoomsInRow = (x - 1) / 2;
	createSidewinder();
}

Sidewinder::Sidewinder(int a, int b)
	:Labirint(a, b), RoomsInRow(a)
{
	createSidewinder();
}

bool Sidewinder::mergeCells(size_t a, size_t b, unsigned count)
{
	if (count > RoomsInRow)
		return false;
	for (size_t i = a; i < a + count * 2 - 2; i = i + 2)
		setCellValue(false, i + 1, b);
	return true;
}

void Sidewinder::createSidewinderRandmerge()
{
	mergeCells(1, 1, RoomsInRow);
	if (y <= 3)
		return;
	for (size_t i = 3; i < y; i = i + 2)
	{
		unsigned freeRoomsInRow = RoomsInRow;
		
		while (freeRoomsInRow)
		{
			size_t currentX = x - 2 * freeRoomsInRow;
			unsigned mergedRooms = (rand() % freeRoomsInRow ) / quality + 1;
			mergeCells(currentX, i, mergedRooms);

			size_t offsetX = (rand() % mergedRooms) * 2;
			setCellValue(false, currentX + offsetX, i - 1);

			freeRoomsInRow -= mergedRooms;
		}
	}
}

void Sidewinder::createSidewinder()
{
	mergeCells(1, 1, RoomsInRow);
	if (y <= 3)
		return;
	Cell currentCell = { 1, 1 };
	for (size_t i = 3; i < y; i = i + 2)
	{
		unsigned freeRoomsInRow = RoomsInRow;
		unsigned mergedRooms = 1;	//»нициализировать пустое множество
		currentCell.y = i;	//¬ыбрать начальный р€д;
		currentCell.x = 1;	//¬ыбрать начальную клетку р€да и сделать еЄ текущей
		size_t startX = 1;

		while (freeRoomsInRow)
		{
			
			unsigned direction = getRandomDirection();

			if (direction && freeRoomsInRow != 1)	//добавл€ем комнату в множество
			{
				mergedRooms++;
				
				mergeCells(currentCell.x, currentCell.y, 2);

			}
			else	//прокладываем путь наверх
			{
				setCellValue(false, startX + (rand() % mergedRooms + 1) * 2 - 2, i - 1);
				
				startX += mergedRooms * 2;
				mergedRooms = 1;

			}
			freeRoomsInRow--;
			currentCell.x += 2;

			//print();
			//system("cls");
		}
	}
}
