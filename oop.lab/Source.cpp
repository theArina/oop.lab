#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <conio.h>

void main()
{
	// �������� ������������� ����
	HWND hwnd = GetConsoleWindow();
	// �������� �������� �����������
	HDC hdc = GetDC(hwnd);
	RECT rt;
	char buf[100];
	// ������������� ���� ����
	SetBkColor(hdc, RGB(0, 0, 0));
	// ������������� ���� ������
	SetTextColor(hdc, RGB(255, 0, 0));
	// ������� ������� ����
	HPEN hRedPen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
	// � �������� ��� � �������� �����������,
	// �������� ���������� ����
	HPEN hOldPen = SelectPen(hdc, hRedPen);
	// ������� ������� �����
	HBRUSH hGreenBrush = CreateSolidBrush(RGB(0, 255, 0));
	20;
	// � �������� �� � �������� �����������,
	// �������� ���������� �����
	HBRUSH hOldBrush = SelectBrush(hdc, hGreenBrush);
	// ������� ������ ������������ ����������
	printf("Graphics in Console Window.");
	do {
		// �������� ������ ����
		GetClientRect(hwnd, &rt);
		// ��������� ��������� ������
		sprintf(buf, "������ ���� %d �� %d ��������",
			rt.right, rt.bottom);
		// ������� ������ ������������ ����������
		TextOutA(hdc, 10, 10, buf, strlen(buf));
		// ������ ����������� ������
		Ellipse(hdc, 10, 30, rt.right - 10, rt.bottom - 10);
	} while (_getch() != 27); // ��� ������� ����� �������
							  // (����� Esc) �������������� �����������,
							  // ����������� ���������, ���� ���������� ������� ����,
							  // ������� Esc � �����
							  // �������� � �������� ����������� ���������� ����
	SelectPen(hdc, hOldPen);
	// �������� � �������� ����������� ���������� �����
	SelectBrush(hdc, hOldBrush);
	// ������� ������� ����
	DeletePen(hRedPen);
	// ������� ������� �����
	DeleteBrush(hGreenBrush);
	// ����������� �������� �����������
	ReleaseDC(hwnd, hdc);
}