#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <conio.h>
void main()
{
	// получаем идентификатор окна
	HWND hwnd = GetConsoleWindow();
	// получаем контекст отображени€
	HDC hdc = GetDC(hwnd);
	RECT rt;
	char buf[100];
	// устанавливаем цвет фона
	SetBkColor(hdc, RGB(0, 0, 0));
	// устанавливаем цвет текста
	SetTextColor(hdc, RGB(255, 0, 0));
	// создаем красное перо
	HPEN hRedPen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
	// и выбираем его в контекст отображени€,
	// сохран€€ предыдущее перо
	HPEN hOldPen = SelectPen(hdc, hRedPen);
	// создаем зеленую кисть
	HBRUSH hGreenBrush = CreateSolidBrush(RGB(0, 255, 0));
	20;
		// и выбираем ее в контекст отображени€,
		// сохран€€ предыдущую кисть
		HBRUSH hOldBrush = SelectBrush(hdc, hGreenBrush);
	// выводим строку стандартными средствами
	printf("Graphics in Console Window.");
	do {
		// получаем размер окна
		GetClientRect(hwnd, &rt);
		// формируем выводимую строку
		sprintf(buf, "–азмер окна %d на %d пикселей",
			rt.right, rt.bottom);
		// выводим строку графическими средствами
		TextOutA(hdc, 10, 10, buf, strlen(buf));
		// рисуем закрашенный эллипс
		Ellipse(hdc, 10, 30, rt.rightЦ10, rt.bottomЦ10);
	} while (getch() != 27); // при нажатии любой клавиши
							 // (кроме Esc) перерисовываем изображение,
							 // изображение изменитс€, если изменились размеры окна,
							 // нажатие Esc Ц выход
							 // выбираем в контекст отображени€ предыдущее перо
	SelectPen(hdc, hOldPen);
	// выбираем в контекст отображени€ предыдущую кисть
	SelectBrush(hdc, hOldBrush);
	// удал€ем красное перо
	DeletePen(hRedPen);
	// удал€ем зеленую кисть
	DeleteBrush(hGreenBrush);
	// освобождаем контекст отображени€
	ReleaseDC(hwnd, hdc);
}