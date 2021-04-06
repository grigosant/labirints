#pragma once
#include "LabBase.h"

class Sidewinder : public Labirint
{
public:
	Sidewinder ();
	Sidewinder(int a, int b);

private:
	void createSidewinderRandmerge();	//��� ���������� � ��������� ������������ ������
	void createSidewinder();	//+- �������� � �����

	bool mergeCells(size_t a, size_t b, unsigned count);	// ���������� �������

	unsigned RoomsInRow;

	unsigned quality = 1;	// ��������� ������ ��������� (��� ������������� createSidewinderRandmerge); ��� 1 �������� ����������� ������ �� ����� ����; 
							// ������� �������� -> ������� �����������
							// �������: ������������ ���� ������, ����� ������� ����� quality; ��� == RoomsInRow ������ ������������ ����
};
