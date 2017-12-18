#include "OpenStack.h"
using namespace std;

#include <iostream>
#include <fstream>


OpenStack::OpenStack(int n): length(n), top(0)
{
	shapeStack = new Rhombus[length];
}
OpenStack::~OpenStack()
{
	delete[] shapeStack;
}
void OpenStack::Push(const Rhombus &romb)
{

	if(top < length)
		shapeStack[top++] = romb;
}
void OpenStack::Pop()
{
	if(top > 0)
		top--;
}
void OpenStack::Print(HDC hdc)
{
	for (int i = top - 1; i >= 0; i--)
		print.RombDraw(&shapeStack[i], hdc);
}
int OpenStack::Size()
{
	return top;
}
void OpenStack::SaveToFile()
{
	ofstream fileStack;
	fileStack.open("stack.txt");
	fileStack.write((char*)&top, sizeof(top));
	for (int i = 0; i < top; i++)
	{
		int temp = 0;
		temp = shapeStack[i].GetVertDiagonal();
		fileStack.write((char*)&temp, sizeof(temp));
		temp = shapeStack[i].GetHorizDiagonal();
		fileStack.write((char*)&temp, sizeof(temp));
		fileStack.write((char*)&shapeStack[i].GetBackgroundÑolor(), sizeof(shapeStack[i].GetBackgroundÑolor()));
		fileStack.write((char*)&shapeStack[i].GetFrameÑolor(), sizeof(shapeStack[i].GetFrameÑolor()));
		temp = shapeStack[i].GetXCenter();
		fileStack.write((char*)&temp, sizeof(temp));
		temp = shapeStack[i].GetYCenter();
		fileStack.write((char*)&temp, sizeof(temp));
	}
	fileStack.close();
}
void OpenStack::LoadFromFile()
{
	ifstream fileStack;
	fileStack.open("stack.txt");
	fileStack.read((char*)&top, sizeof(top));
	for (int i = 0; i < top; i++)
	{
		int temp = 0;
		RGBTRIPLE tempColor;
		fileStack.read((char*)&temp, sizeof(temp));
		shapeStack[i].SetVertDiagonal(temp);
		fileStack.read((char*)&temp, sizeof(temp));
		shapeStack[i].SetHorizDiagonal(temp);
		fileStack.read((char*)&tempColor, sizeof(tempColor));
		shapeStack[i].SetBackgroundÑolor(tempColor.rgbtRed, tempColor.rgbtGreen, tempColor.rgbtBlue);
		fileStack.read((char*)&tempColor, sizeof(tempColor));
		shapeStack[i].SetFrameÑolor(tempColor.rgbtRed, tempColor.rgbtGreen, tempColor.rgbtBlue);
		fileStack.read((char*)&temp, sizeof(temp));
		shapeStack[i].SetXCenter(temp);
		fileStack.read((char*)&temp, sizeof(temp));
		shapeStack[i].SetYCenter(temp);
	}
	fileStack.close();
}
Rhombus OpenStack::GetTopObject()
{
	if (top>0)
		return shapeStack[top-1];
	return shapeStack[top];
}