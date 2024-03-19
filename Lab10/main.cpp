#include <cassert>
#include "DoublyLinkedList.h"
#include "Node.h"
#include <vld.h>

using namespace lab10;

void test1()
{
	DoublyLinkedList<int> list;

	list.Insert(std::make_unique<int>(1));
	list.Insert(std::make_unique<int>(2));
	list.Insert(std::make_unique<int>(3));
	list.Insert(std::make_unique<int>(4));
	list.Insert(std::make_unique<int>(5));
	list.Insert(std::make_unique<int>(6));
	list.Insert(std::make_unique<int>(7));

	bool bSearched = list.Search(4);
	assert(bSearched);

	bSearched = list.Search(10);
	assert(!bSearched);

	unsigned int size = list.GetLength();
	assert(size == 7);

	bool bDeleted = list.Delete(3);
	assert(bDeleted);

	bDeleted = list.Delete(3);
	assert(!bDeleted);

	size = list.GetLength();
	assert(size == 6);

	std::shared_ptr<Node<int>> node = list[2];
	assert(*node->Data == 4);

	list.Insert(std::make_unique<int>(10), 2);

	node = list[2];
	assert(*node->Data == 10);
}

void test2()
{
	DoublyLinkedList<int> list;
	std::shared_ptr<Node<int>> checknode;
	
	list.Insert(std::make_unique<int>(3), 0);
	list.Insert(std::make_unique<int>(2), 0);
	list.Insert(std::make_unique<int>(1), 0);
	
	checknode = list[0];
	assert(*checknode->Data == 1);

	checknode = list[1];
	assert(*checknode->Data == 2);

	checknode = list[2];
	assert(*checknode->Data == 3);

	list.Insert(std::make_unique<int>(4),3);
	list.Insert(std::make_unique<int>(6),4);
	list.Insert(std::make_unique<int>(7),5);

	list.Insert(std::make_unique<int>(5), 4);

	list.Delete(6);

	bool bSearched = list.Search(4);
	assert(bSearched);

	bSearched = list.Search(10);
	assert(!bSearched);

	unsigned int size = list.GetLength();
	assert(size == 6);

	bool bDeleted = list.Delete(3);
	assert(bDeleted);

	bDeleted = list.Delete(3);
	assert(!bDeleted);

	size = list.GetLength();
	assert(size == 5);

	std::shared_ptr<Node<int>> node = list[2];
	assert(*node->Data == 4);

	list.Insert(std::make_unique<int>(10), 2);

	node = list[2];
	assert(*node->Data == 10);

}

int main()
{
//	test1();

	test2();
}