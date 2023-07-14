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

	// ��������� �������������� ������������� �����
	for (int i = 0; i<points; i++) {

		// ������������ ��������������� ��������� �����
		x = randomGenerator()%rect.right;
		y = randomGenerator()%rect.bottom;

		// ��������� �����
		SetPixel(hdc, x, y, RGB(0, 0, 0));

		// ��������� �������� (�������������)
		Sleep(20); 
	} 
	InvalidateRect(hwnd, NULL, TRUE);
}

int checkPeriod(int (*randomGenerator)()) {
	SItem *Head = NULL;
	SItem *NewItem;

	Head = new SItem; // ������� ������� ������
	Head->id = -1;
	Head->next = NULL; // ��������� �� ��������� ������� ������
	Head->prev = Head; // ��������� �� ��������� ������� ������

	int data; 

	for (int i = 0; 10000; i++) {
		data = randomGenerator();
		// �������� ���� �� ������� � ������
		if (FunctionList::checkItemData(Head, data)) {
			NewItem = new SItem;
			NewItem->data = data;
			// ���� �� �� �������� �������
			FunctionList::addItem(Head, NewItem);
		} else {
			// ���� ��� �� ������ id ���������� ��������
			return Head->prev->id;
		}
	}

	return Head->prev->id;

	FunctionList::deleteAllItems(Head);
	// ������ ������
}

int checkAveragePeriod(int (*randomGenerator)(), int num) {
	int average = 0;

	for (int i=0; i < num; i++) {
		average += checkPeriod(randomGenerator);
	}

	return average / num;
}



int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "Russian_Russia.1251");


	system("pause");
	return 0;
}