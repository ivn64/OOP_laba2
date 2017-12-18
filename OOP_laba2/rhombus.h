#pragma once
#include <iostream>
#include <windows.h>

class Rhombus
{
	int vertDiagonal;
	int horizDiagonal;
	RGBTRIPLE background—olor;
	RGBTRIPLE frame—olor;
	int xCenter;
	int yCenter;

public:
	Rhombus();
	Rhombus(int, int, int, int, RGBTRIPLE, RGBTRIPLE);
	int GetVertDiagonal();
	int GetHorizDiagonal();
	RGBTRIPLE GetBackground—olor();
	RGBTRIPLE GetFrame—olor();
	void SetBackground—olor(BYTE, BYTE, BYTE);
	void SetFrame—olor(BYTE, BYTE, BYTE);
	void SetVertDiagonal(int);
	void SetHorizDiagonal(int);
	void SetXCenter(int);
	void SetYCenter(int);
	void SaveToFile();
	void LoadFromFile();
	void MoveX(int);
	void MoveY(int);
	int GetXCenter();
	int GetYCenter();
};