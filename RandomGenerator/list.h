#ifndef __LIST__H__	
#define __LIST__H__	

struct SItem
{
	int id;
	int data;
	SItem *next;
	SItem *prev;
};

namespace FunctionList
{
	void outList(SItem *Head);

	void addItem(SItem *Head, SItem *NewItem);

	bool checkItemData(SItem *Head, int data);

	bool deleteItem(SItem *Head, int id);

	bool deleteAllItems(SItem *Head);
}
#endif