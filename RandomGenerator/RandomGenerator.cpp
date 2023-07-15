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

void checkPeriod(int (*randomGenerator)()) {
	SItem *Head = NULL;
	SItem *NewItem;

	Head = new SItem; // ������� ������� ������
	Head->id = -1;
	Head->data = -1;
	Head->next = NULL; // ��������� �� ��������� ������� ������
	Head->prev = Head; // ��������� �� ��������� ������� ������

	int data; 

	while (true) {
		data = randomGenerator();
		// �������� ���� �� ������� � ������
		if (Head->prev->data != data) {
			NewItem = new SItem;
			NewItem->data = data;
			// ���� �� �� �������� �������
			FunctionList::addItem(Head, NewItem);
		} else {
			// ���� ��� �� ������ id ���������� ��������
			std::cout<<data<<" ";
			std::cout<<Head->prev->data<<std::endl;
			std::cout<<(Head->prev->id) + 1<<std::endl;
			FunctionList::deleteAllItems(Head);
			return;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "Russian_Russia.1251");
	system("color F0");
	
	showField(rand, 3000000);

	system("pause");
	return 0;
}