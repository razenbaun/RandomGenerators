#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "randomFunctions.h"
#include "list.h"


void showField(int (*randomGenerator)(), int points) {

	int width = 30; 
	HWND hwnd = GetConsoleWindow(); 
	HDC hdc = GetDC(hwnd); 
	RECT rect; 
	int x, y;
	GetClientRect(hwnd, &rect);

	// –исование псевдослучайно расположенных точек
	for (int i = 0; i<points; i++) {

		// ‘ормирование псевдослучайных координат точки
		x = randomGenerator()%rect.right;
		y = randomGenerator()%rect.bottom;

		// –исование точки
		SetPixel(hdc, x, y, RGB(255, 255, 255));

		// ¬ременна€ задержка (необ€зательно)
		Sleep(20); 
	} 

	InvalidateRect(hwnd, NULL, TRUE);
}

void checkPeriod(int (*randomGenerator)()) {
	SItem *Head = NULL;
	SItem *NewItem;

	Head = new SItem; // нулевой элемент списка
	Head->id = -1;
	Head->next = NULL; // указывает на следующий элемент списка
	Head->prev = Head; // указывает на последней элемент списка

	long int data; 

	for (int i = 0; 10000; i++) {
		data = randomGenerator();
		// провер€ю есть ли элемент в списке
		if (FunctionList::checkItemData(Head, data)) {
			NewItem = new SItem;
			NewItem->data = data;
			// если да то добавл€ю элемент
			FunctionList::addItem(Head, NewItem);
		} else {
			// если нет то вывожу id последнего элемента
			std::cout<<(Head->prev->id)<<std::endl;
			return;
		}
	}

	std::cout<<(Head->next->id)<<std::endl;

	FunctionList::deleteAllItems(Head);
	// очищаю список
}


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "Russian_Russia.1251");

	//checkPeriod(mersonMethod);

	//showField(mersonMethod,300000);

	system("pause");
	return 0;
}