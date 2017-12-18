#pragma once

#include <iostream>
#include "Rhombus.h"
#include "Draw.h"

class OpenStack
{
	Draw print;
	Rhombus *shapeStack;
	int length, top; // длина и текущий элемент

public:
	OpenStack(int);
	~OpenStack();
	void Push(const Rhombus&);
	void Pop();
	void Print(HDC);
	int Size();
	void SaveToFile();
	void LoadFromFile();
	Rhombus GetTopObject();
};