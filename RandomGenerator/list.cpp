#include "stdafx.h"
#include <iostream>
#include "list.h"


void FunctionList::outList(SItem *Head){
	using namespace std;
	SItem *Curr;
	Curr = Head->next;
	if(!Curr){
		cout<<"Список пуст"<<endl;
		return;
	}
	cout<<"-----------------------------------"<<endl;
	while (Curr->next){
		cout<<"id: "<<Curr->id<<" data: "<<Curr->data<<endl;
		Curr = Curr->next;
	}
	cout<<"id: "<<Curr->id<<" data: "<<Curr->data<<endl;
	cout<<"-----------------------------------"<<endl;
}

void FunctionList::addItem(SItem *Head, SItem *NewItem){
	using namespace std;
	NewItem->next = NULL;
	NewItem->id = (Head->prev->id) + 1;
	SItem *Curr;
	Curr = Head->prev;
	NewItem->prev = Curr;
	Curr->next = NewItem;
	Head->prev = NewItem;

}


bool FunctionList::checkItemData(SItem *Head, int data){
	// true - элемень найден
	// false - нет

	using namespace std;
	SItem *Curr;
	Curr = Head->next;
	if(!Curr){
		return true; 
	}
	while (Curr->next){
		if(Curr->data == data){
			// cout<<Curr->data<<" "<<data<<endl;
			return false;
		}
		Curr = Curr->next;
	}
	if(Curr->data == data){
		return true;
	}

	return true;
}

bool FunctionList::deleteItem(SItem *Head, int id){
	// true - элемент удалён
	// false - не найден

	using namespace std;
	cout<<"-----------------------------------"<<endl;
	SItem *Curr;
	SItem *prevCurr;
	SItem *nextCurr;
	Curr = Head->next;
	if(!Curr){
		return false;
	}
	Curr = Head->prev;
	if(Curr->id == id){
		prevCurr = Curr->prev;
		prevCurr->next = NULL;
		Head->prev = prevCurr;
		delete Curr;
		return true;
	}
	Curr = Head->next;
	while (Curr->next){
		if(Curr->id == id){
			prevCurr = Curr->prev;
			nextCurr = Curr->next;
			prevCurr->next = nextCurr;
			nextCurr->prev = prevCurr;
			delete Curr;
			return true;
		}
		Curr = Curr->next;
	}
	if(Curr->id == id){
			prevCurr = Curr->prev;
			nextCurr = Curr->next;
			prevCurr->next = nextCurr;
			nextCurr->prev = prevCurr;
			delete Curr;
			return true;
	}
	return false;
}

bool FunctionList::deleteAllItems(SItem *Head){
	using namespace std;

	bool flag = true;

	SItem *Curr;
	Curr = Head->prev; // Head->prev - последний элемент
	for(int i = 0; i<=Curr->id; i++){ // id последнего элемента
		if (FunctionList::deleteItem(Head, i)) {
			flag = false;
		}
	}
	return flag;
}