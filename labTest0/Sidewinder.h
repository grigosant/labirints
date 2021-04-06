#pragma once
#include "LabBase.h"

class Sidewinder : public Labirint
{
public:
	Sidewinder ();
	Sidewinder(int a, int b);

private:
	void createSidewinderRandmerge();	//моя реализация с рандомным объединением комнат
	void createSidewinder();	//+- алгоритм с хабра

	bool mergeCells(size_t a, size_t b, unsigned count);	// объединить комнаты

	unsigned RoomsInRow;

	unsigned quality = 1;	// насколько мелкие множества (при использовании createSidewinderRandmerge); при 1 возможно объединение вплоть до всего ряда; 
							// большее значение -> меньшие объединения
							// побочка: вертикальные ряды справа, число которых равно quality; при == RoomsInRow только вертикальные ряды
};
