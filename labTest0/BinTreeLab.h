#pragma once
#include "LabBase.h"

//северо-восточное смещение
class BinaryTreeLabirint : public Labirint
{
public:
	BinaryTreeLabirint();
	BinaryTreeLabirint(int a, int b);
	BinaryTreeLabirint(int a, int b, Cell point);
private:
	bool BTLabirintCreating();
	inline bool couldMakePath(unsigned int direction, int a, int b);
};