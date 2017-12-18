#define _CRT_SECURE_NO_WARNINGS
using namespace std;


#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>

#include "Rhombus.h"
#include "Draw.h"
#include "OpenStack.h"

void Test(int &x, int &y, int &v, int &h, Rhombus &romb, RECT rt)
{
	try
	{
		if (romb.GetXCenter() + x + h / 2 > rt.right || romb.GetXCenter() + x - h / 2 < rt.left || romb.GetYCenter() + y - v / 2 < rt.top || romb.GetYCenter() + y + v / 2 > rt.bottom)

		{
			throw 0;
		}
	}
	catch (int thr)
	{
		cout << "������: ���� �� ��������� ����. ���������� � ��������� �� ��������" << endl;
		x = thr;
		y = thr;
		v = thr;
		h = thr;
	}
}
void Change(Rhombus &romb, RECT rt)
{
	int x, y, vertDiagonal, horizDiagonal;
	cout << "������� �������� �� x: ";
	cin >> x;
	cout << "������� �������� �� y: ";
	cin >> y;
	cout << "������� ��������� �� ���������: ";
	cin >> vertDiagonal;
	cout << "������� ��������� �� �����������: ";
	cin >> horizDiagonal;
	int R, G, B;
	cout << "������ ���� ������� (RGB ����� ������):";
	cin >> R >> G >> B;
	romb.SetBackground�olor(R, G, B);
	cout << "������ ���� ������� (RGB ����� ������):";
	cin >> R >> G >> B;
	Test(x, y, vertDiagonal, horizDiagonal, romb, rt);
	if (vertDiagonal != 0 || horizDiagonal != 0)
	{
		romb.SetVertDiagonal(vertDiagonal);
		romb.SetHorizDiagonal(horizDiagonal);
	}
	romb.SetFrame�olor(R, G, B);
	romb.MoveX(x);
	romb.MoveY(y);
}

void main()
{
	setlocale(LC_ALL, "rus");
	// �������� ������������� ����
	HWND hwnd = GetConsoleWindow();
	// �������� �������� �����������
	HDC hdc = GetDC(hwnd);
	RECT rt;
	// �������� ������ ����
	GetClientRect(hwnd, &rt);
	RGBTRIPLE background�olor{ 255,0,0 };
	RGBTRIPLE frame�olor{ 0,255,0 };
	OpenStack stack(10);
	stack.LoadFromFile();
	Rhombus romb;
	romb = stack.GetTopObject();
	stack.Print(hdc);
	do {
		cout << "���������� ������: x= " << romb.GetXCenter() << " y= " << romb.GetYCenter() << endl;
		cout << "����� ��������� �� ��������� " << romb.GetVertDiagonal() << " �� ����������� " << romb.GetHorizDiagonal() << endl;
		Change(romb, rt);
		stack.Push(romb);
		stack.Print(hdc);
		cout << "������ �����: " << stack.Size() << endl;
		cout << "esc - �����" << endl;
	} while (_getch() != 27);

	stack.Pop();
	stack.Size();
	stack.Print(hdc);
	cout << "������ �����: " << stack.Size() << endl;
	_getch();
	stack.SaveToFile();
	// ����������� �������� �����������
	ReleaseDC (hwnd, hdc);
}