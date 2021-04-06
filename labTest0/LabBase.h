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
	//a - �� ����������� , b - �� ���������
	bool setCellValue(bool newstate, size_t a, size_t b);

	unsigned int getRandomDirection();

	size_t x, y;//����� ������ � ��������� � ������ (� �������) = 2 * n + 1; ��� ����� � 0 �� 1 ������ ��� ����������
				//x - �� ����������� , y - �� ���������
	Cell zeroPoint = { 0, 0 };
	std::vector<std::vector<bool>> bodyLab;	//1 - �����, 0 - �������
};