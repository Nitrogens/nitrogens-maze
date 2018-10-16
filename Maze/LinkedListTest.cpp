#include "stdafx.h"
extern bool matrix[SIZE][SIZE];
void print(DataType a)
{
	cout << a << endl;
}
void linkedListTest(void)
{
	LinkedList * list = new LinkedList();

	list->insertNode(1, list->getLast());
	list->insertNode(5, list->getLast());
	list->insertNode(9, list->getLast());

	list->search(print);

	list->deleteNode(list->getLast());

	list->search(print);

	system("pause");
}

