#include "Draw.h"

#include <windowsx.h>

void Draw::RombDraw(Rhombus *romb, HDC hdc)
{
	RGBTRIPLE frame�olor = romb->GetFrame�olor();
	HPEN hRedPen = CreatePen(PS_SOLID, 5, RGB(frame�olor.rgbtRed, frame�olor.rgbtGreen, frame�olor.rgbtBlue));
	// � �������� ��� � �������� �����������,
	// �������� ���������� ����
	HPEN hOldPen = SelectPen(hdc, hRedPen);
	RGBTRIPLE background�olor = romb->GetBackground�olor();
	// ������� ������� �����
	HBRUSH hGreenBrush = CreateSolidBrush(RGB(background�olor.rgbtRed, background�olor.rgbtGreen, background�olor.rgbtBlue));
	// � �������� �� � �������� �����������,
	// �������� ���������� �����
	HBRUSH hOldBrush = SelectBrush(hdc, hGreenBrush);
	int vertDiagonal = romb->GetVertDiagonal();
	int horizDiagonal = romb->GetHorizDiagonal();
	POINT ppt[4] = { { romb->GetXCenter() - horizDiagonal / 2,	romb->GetYCenter() },{ romb->GetXCenter(),	romb->GetYCenter() - vertDiagonal / 2 },{ romb->GetXCenter() + horizDiagonal / 2,	romb->GetYCenter() },{ romb->GetXCenter(),	romb->GetYCenter() + vertDiagonal / 2 } };
	Polygon(hdc, ppt, 4);
	// �������� � �������� ����������� ���������� ���� 
	SelectPen(hdc, hOldPen);
	// �������� � �������� ����������� ���������� ����� 
	SelectBrush(hdc, hOldBrush);
	// ������� ������� ����
	DeletePen(hRedPen);
	// ������� ������� �����
	DeleteBrush(hGreenBrush);
}