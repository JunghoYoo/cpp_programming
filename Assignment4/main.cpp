#include <cassert>
#include "TreeNode.h"
#include "BinarySearchTree.h"
#include <vld.h>
#include <cstdlib>
#include <iostream>
#include <set>

using namespace assignment4;
using namespace std;

int treesametest()
{
	BinarySearchTree<int> tree;

	tree.Insert(std::make_unique<int>(38));

	tree.Insert(std::make_unique<int>(20));
	tree.Insert(std::make_unique<int>(60));

	tree.Insert(std::make_unique<int>(8));
	tree.Insert(std::make_unique<int>(30));
	tree.Insert(std::make_unique<int>(45));
	tree.Insert(std::make_unique<int>(70));

	tree.Insert(std::make_unique<int>(1));
	tree.Insert(std::make_unique<int>(13));
	tree.Insert(std::make_unique<int>(25));
	tree.Insert(std::make_unique<int>(37));
	tree.Insert(std::make_unique<int>(40));
	tree.Insert(std::make_unique<int>(53));
	tree.Insert(std::make_unique<int>(65));
	tree.Insert(std::make_unique<int>(77));

	tree.Insert(std::make_unique<int>(9));
	tree.Insert(std::make_unique<int>(15));
	tree.Insert(std::make_unique<int>(21));
	tree.Insert(std::make_unique<int>(27));
	tree.Insert(std::make_unique<int>(32));
	tree.Insert(std::make_unique<int>(37));
	tree.Insert(std::make_unique<int>(39));
	tree.Insert(std::make_unique<int>(41));
	tree.Insert(std::make_unique<int>(48));
	tree.Insert(std::make_unique<int>(55));
	tree.Insert(std::make_unique<int>(61));
	tree.Insert(std::make_unique<int>(79));

	std::vector<int> result;
	result = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(result.size() == 27);

	for (auto it = result.begin(); it != result.end(); ++it)
	{
		cout << *it << " ";
	}

	tree.CheckBSTRule(tree.GetRootNode().lock());
	//	tree.TraverseLevelOrder(tree.GetRootNode().lock());

	cout << endl;
	cout << endl;
	cout << endl;

	// insert same data as root
	tree.Insert(std::make_unique<int>(25));

	std::vector<int> result2;
	result2 = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(result2.size() == 28);

	for (auto it = result2.begin(); it != result2.end(); ++it)
	{
		cout << *it << " ";
	}

	tree.CheckBSTRule(tree.GetRootNode().lock());

	//	tree.TraverseLevelOrder(tree.GetRootNode().lock());
	return 0;
}

int treetest()
{
	BinarySearchTree<int> tree;

	tree.Insert(std::make_unique<int>(10));
	tree.Insert(std::make_unique<int>(15));
	tree.Insert(std::make_unique<int>(5));
	tree.Insert(std::make_unique<int>(4));
	tree.Insert(std::make_unique<int>(19));
	tree.Insert(std::make_unique<int>(20));
	tree.Insert(std::make_unique<int>(17));
	tree.Insert(std::make_unique<int>(12));

	//	std::vector<int> v = tree.TraverseInOrder(tree.GetRootNode().lock());
	std::vector<int> v = tree.CheckBSTRule(tree.GetRootNode().lock());

	assert(v.size() == 8);
	assert(v[0] == 4);
	assert(v[1] == 5);
	assert(v[2] == 10);
	assert(v[3] == 12);
	assert(v[4] == 15);
	assert(v[5] == 17);
	assert(v[6] == 19);
	assert(v[7] == 20);

	bool bSearched = tree.Search(15);
	assert(bSearched);

	bool bDeleted = tree.Delete(6);
	assert(!bDeleted);

	bDeleted = tree.Delete(100);
	assert(!bDeleted);

	bDeleted = tree.Delete(15);
	assert(bDeleted);

	//	v = tree.TraverseInOrder(tree.GetRootNode().lock());
	v = tree.CheckBSTRule(tree.GetRootNode().lock());

	std::vector<int> result;
	//	result = tree.TraverseInOrder(tree.GetRootNode().lock());
	result = tree.CheckBSTRule(tree.GetRootNode().lock());

	for (auto it = result.begin(); it != result.end(); ++it)
	{
		cout << *it << " ";
	}

	return 0;
}

void TraverseTest()
{
	BinarySearchTree<int> tree;

	static std::shared_ptr<TreeNode<int>> head = std::make_shared<TreeNode<int>>(std::make_unique<int>(3));
	static std::shared_ptr<TreeNode<int>> leftson = std::make_shared<TreeNode<int>>(std::make_unique<int>(1));
	static std::shared_ptr<TreeNode<int>> rightson = std::make_shared<TreeNode<int>>(std::make_unique<int>(5));
	static std::shared_ptr<TreeNode<int>> leftson_left = std::make_shared<TreeNode<int>>(std::make_unique<int>(0));
	static std::shared_ptr<TreeNode<int>> leftson_right = std::make_shared<TreeNode<int>>(std::make_unique<int>(2));
	static std::shared_ptr<TreeNode<int>> rightson_left = std::make_shared<TreeNode<int>>(std::make_unique<int>(4));
	static std::shared_ptr<TreeNode<int>> rightson_right = std::make_shared<TreeNode<int>>(std::make_unique<int>(6));

	head->Left = leftson;
	head->Right = rightson;
	leftson->Parent = head;
	rightson->Parent = head;

	leftson->Left = leftson_left;
	leftson->Right = leftson_right;

	rightson->Left = rightson_left;
	rightson->Right = rightson_right;

	std::vector<int> result;
	//	result = tree.TraverseInOrder(head);
	result = tree.CheckBSTRule(head);
	/*
		for (auto it = result.begin(); it != result.end(); ++it)
		{
			cout << *it << " ";
		}

		std::vector<int> resultlevel;
		tree.TraverseLevelOrder(head);
	*/
}


void Test_Insert_GetRoot()
{
	BinarySearchTree<int> tree;

	int arr[10] = { 10, 15, 5, 4, 19, 20, 17, 12, 7, 0 };

	tree.Insert(std::make_unique<int>(arr[0]));
	tree.Insert(std::make_unique<int>(arr[1]));
	tree.Insert(std::make_unique<int>(arr[2]));
	tree.Insert(std::make_unique<int>(arr[3]));
	tree.Insert(std::make_unique<int>(arr[4]));
	tree.Insert(std::make_unique<int>(arr[5]));
	tree.Insert(std::make_unique<int>(arr[6]));
	tree.Insert(std::make_unique<int>(arr[7]));
	tree.Insert(std::make_unique<int>(arr[8]));

	std::shared_ptr<TreeNode<int>> test0 = tree.GetRootNode().lock();
	assert(*test0->Data.get() == 10);
	assert(test0->Parent.lock().get() == nullptr);
	std::shared_ptr<TreeNode<int>> test1 = test0->Left;
	assert(*test1->Data.get() == 5);
	assert(*test1->Parent.lock()->Data.get() == 10);
	std::shared_ptr<TreeNode<int>> test2 = test1->Left;
	assert(*test2->Data.get() == 4);
	assert(*test2->Parent.lock()->Data.get() == 5);
	std::shared_ptr<TreeNode<int>> test3 = test1->Right;
	assert(*test3->Data.get() == 7);
	assert(*test3->Parent.lock()->Data.get() == 5);
	std::shared_ptr<TreeNode<int>> test4 = test0->Right;
	assert(*test4->Data.get() == 15);
	assert(*test4->Parent.lock()->Data.get() == 10);
	std::shared_ptr<TreeNode<int>> test5 = test4->Left;
	assert(*test5->Data.get() == 12);
	assert(*test5->Parent.lock()->Data.get() == 15);
	std::shared_ptr<TreeNode<int>> test6 = test4->Right;
	assert(*test6->Data.get() == 19);
	assert(*test6->Parent.lock()->Data.get() == 15);
	std::shared_ptr<TreeNode<int>> test7 = test6->Left;
	assert(*test7->Data.get() == 17);
	assert(*test7->Parent.lock()->Data.get() == 19);
	std::shared_ptr<TreeNode<int>> test8 = test6->Right;
	assert(*test8->Data.get() == 20);
	assert(*test8->Parent.lock()->Data.get() == 19);

	tree.CheckBSTRule(tree.GetRootNode().lock());

	return;
}

void Test_Search()
{
	BinarySearchTree<int> tree;

	int arr[10] = { 10, 15, 5, 4, 19, 20, 17, 12, 7, 0 };

	assert(!tree.Search(arr[0]));
	tree.Insert(std::make_unique<int>(arr[0]));
	assert(tree.Search(arr[0]));
	tree.Insert(std::make_unique<int>(arr[1]));
	assert(tree.Search(arr[1]));
	tree.Insert(std::make_unique<int>(arr[2]));
	assert(tree.Search(arr[2]));
	tree.Insert(std::make_unique<int>(arr[3]));
	assert(tree.Search(arr[3]));
	tree.Insert(std::make_unique<int>(arr[4]));
	assert(tree.Search(arr[4]));
	tree.Insert(std::make_unique<int>(arr[5]));
	assert(tree.Search(arr[5]));
	tree.Insert(std::make_unique<int>(arr[6]));
	assert(tree.Search(arr[6]));
	tree.Insert(std::make_unique<int>(arr[7]));
	assert(tree.Search(arr[7]));
	tree.Insert(std::make_unique<int>(arr[8]));
	assert(tree.Search(arr[8]));
	assert(!tree.Search(arr[9]));

	tree.CheckBSTRule(tree.GetRootNode().lock());

	return;
}

void Test_Delete()
{
	BinarySearchTree<int> tree;

	int arr[9] = { 10, 15, 5, 4, 19, 20, 17, 12, 7 };

	for (size_t i = 0; i < 9; i++)
	{
		tree.Insert(std::make_unique<int>(arr[i]));
	}

	//	End
	assert(!tree.Delete(9)); 	// 존재하지 않는 노드 삭제
	assert(tree.Delete(20));	// Right 노드 삭제
	assert(!tree.Search(20));	// 삭제 확인
	assert(tree.Delete(12));	// Left 노드 삭제
	assert(!tree.Search(12));	// 삭제 확인
	assert(!tree.Delete(11));	// 존재하지 않는 노드 삭제

	tree.CheckBSTRule(tree.GetRootNode().lock());

	//	Middle
	assert(tree.Delete(19));	// Left만 있는 노드 삭제
	assert(!tree.Search(19));	// 삭제 확인
	assert(tree.Search(17));
	assert(tree.Delete(15));	// Right만 있는 노드 삭제
	assert(!tree.Search(15));	// 삭제 확인
	assert(tree.Delete(5)); 	// Left, Right 모두 있는 노드 삭제
	assert(!tree.Search(5));
	assert(!tree.Delete(5));	// 존재하지 않는 노드 삭제

	tree.CheckBSTRule(tree.GetRootNode().lock());

	//	Head
	assert(tree.Delete(10)); 	// Left, Right 모두 있는 헤드 삭제
	assert(!tree.Search(10));	// 삭제 확인
	assert(tree.Delete(4));
	assert(tree.Delete(7));
	assert(tree.Delete(17));	// Left, Right 모두 없는 헤드 삭제
	assert(!tree.Search(17));	// 삭제 확인
	assert(!tree.Delete(17));	// 비어있는 상태에서 삭제

	tree.CheckBSTRule(tree.GetRootNode().lock());

	for (size_t i = 0; i < 9; i++)
	{
		tree.Insert(std::make_unique<int>(arr[i]));
	}

	tree.CheckBSTRule(tree.GetRootNode().lock());

	tree.Delete(arr[0]);
	tree.Delete(arr[1]);
	tree.Delete(arr[2]);
	tree.Delete(arr[3]);
	tree.Delete(arr[4]);
	tree.Delete(arr[5]);
	tree.Delete(arr[6]);
	tree.Delete(arr[7]);
	tree.Delete(arr[8]);

	tree.CheckBSTRule(tree.GetRootNode().lock());

	return;
}

void Test_Traverse()
{
	BinarySearchTree<int> tree;

	int arr[9] = { 10, 15, 5, 4, 19, 20, 17, 12, 7 };
	int arr_chk[9] = { 4, 5, 7, 10, 12, 15, 17, 19, 20 };

	// 빈 트리
	std::vector<int> v1 = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(v1.size() == 0);
	assert(v1.empty());

	tree.Insert(std::make_unique<int>(arr[0]));
	// 헤드만 있는 트리
	std::vector<int> v2 = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(v2.size() == 1);
	assert(v2[0] == arr[0]);

	// empty 포인터
	std::vector<int> v3 = tree.TraverseInOrder(tree.GetRootNode().lock()->Left);
	assert(v3.size() == 0);
	assert(v3.empty());

	tree.CheckBSTRule(tree.GetRootNode().lock());

	// 트리 입력
	for (size_t i = 1; i < 9; i++)
	{
		tree.Insert(std::make_unique<int>(arr[i]));
	}

	// 헤드 노드 입력
	std::vector<int> v4 = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(v4.size() == 9);
	assert(v4[0] == arr_chk[0]);
	assert(v4[1] == arr_chk[1]);
	assert(v4[2] == arr_chk[2]);
	assert(v4[3] == arr_chk[3]);
	assert(v4[4] == arr_chk[4]);
	assert(v4[5] == arr_chk[5]);
	assert(v4[6] == arr_chk[6]);
	assert(v4[7] == arr_chk[7]);
	assert(v4[8] == arr_chk[8]);

	tree.CheckBSTRule(tree.GetRootNode().lock());

	// 중간 노드 입력
	std::vector<int> v5 = tree.TraverseInOrder(tree.GetRootNode().lock()->Right->Right);
	assert(v5.size() == 3);
	assert(v5[0] == arr_chk[6]);
	assert(v5[1] == arr_chk[7]);
	assert(v5[2] == arr_chk[8]);

	tree.CheckBSTRule(tree.GetRootNode().lock());

	// 말단 노드 입력
	std::vector<int> v6 = tree.TraverseInOrder(tree.GetRootNode().lock()->Right->Left);
	assert(v6.size() == 1);
	assert(v6[0] == arr_chk[4]);

	// 노드 삭제
	for (size_t i = 0; i < 8; i++)
	{
		tree.Delete(arr[i]);
	}

	tree.CheckBSTRule(tree.GetRootNode().lock());

	// 7만 남기고 모두 삭제된 트리
	std::vector<int> v7 = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(v7.size() == 1);
	assert(v7[0] == arr[8]);

	// 노드가 모두 삭제된 트리
	tree.Delete(arr[8]);
	std::vector<int> v8 = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(v8.size() == 0);
	assert(v8.empty());

	tree.CheckBSTRule(tree.GetRootNode().lock());

	return;
}


void TestCaseFromSlackOnlyLeftRight()
{
	BinarySearchTree<int> tree1;
	tree1.Insert(std::make_unique<int>(8));
	tree1.Insert(std::make_unique<int>(5));
	tree1.Insert(std::make_unique<int>(30));
	tree1.Insert(std::make_unique<int>(20));
	tree1.Insert(std::make_unique<int>(45));
	tree1.Insert(std::make_unique<int>(11));
	tree1.Insert(std::make_unique<int>(25));
	tree1.Insert(std::make_unique<int>(26));
	tree1.Insert(std::make_unique<int>(40));
	tree1.Insert(std::make_unique<int>(48));
	tree1.Insert(std::make_unique<int>(24));
	tree1.Insert(std::make_unique<int>(41));
	bool bDeleted1 = tree1.Delete(30);
	assert(bDeleted1);

	BinarySearchTree<int> tree2;
	tree2.Insert(std::make_unique<int>(8));
	tree2.Insert(std::make_unique<int>(5));
	tree2.Insert(std::make_unique<int>(20));
	tree2.Insert(std::make_unique<int>(45));
	tree2.Insert(std::make_unique<int>(11)); //
	tree2.Insert(std::make_unique<int>(25));
	tree2.Insert(std::make_unique<int>(26));
	tree2.Insert(std::make_unique<int>(40));
	tree2.Insert(std::make_unique<int>(48));
	tree2.Insert(std::make_unique<int>(24));
	tree2.Insert(std::make_unique<int>(41));

	std::vector<int> v1 = tree1.TraverseInOrder(tree1.GetRootNode().lock());
	std::vector<int> v2 = tree2.TraverseInOrder(tree2.GetRootNode().lock());

	assert(v1.size() == 11);
	assert(v2.size() == 11);
	assert(v1[0] == v2[0]);
	assert(v1[1] == v2[1]);
	assert(v1[2] == v2[2]);
	assert(v1[3] == v2[3]);
	assert(v1[4] == v2[4]);
	assert(v1[5] == v2[5]);
	assert(v1[6] == v2[6]);
	assert(v1[7] == v2[7]);
	assert(v1[8] == v2[8]);
	assert(v1[9] == v2[9]);
	assert(v1[10] == v2[10]);

	// 트리 모양이 같은 형태인지 일일이 검토
	// 8
	assert(tree1.GetRootNode().lock() != nullptr);
	assert(tree2.GetRootNode().lock() != nullptr);
	assert(*tree1.GetRootNode().lock()->Data == *tree2.GetRootNode().lock()->Data);
	// 5
	assert(tree1.GetRootNode().lock()->Left != nullptr);
	assert(tree2.GetRootNode().lock()->Left != nullptr);
	assert(*tree1.GetRootNode().lock()->Left->Data == *tree2.GetRootNode().lock()->Left->Data);
	// 20
	assert(tree1.GetRootNode().lock()->Right != nullptr);
	assert(tree2.GetRootNode().lock()->Right != nullptr);
	assert(*tree1.GetRootNode().lock()->Right->Data == *tree2.GetRootNode().lock()->Right->Data);
	// 11
	assert(tree1.GetRootNode().lock()->Right->Left != nullptr);
	assert(tree2.GetRootNode().lock()->Right->Left != nullptr);
	assert(*tree1.GetRootNode().lock()->Right->Left->Data == *tree2.GetRootNode().lock()->Right->Left->Data);
	// 45
	assert(tree1.GetRootNode().lock()->Right->Right != nullptr);
	assert(tree2.GetRootNode().lock()->Right->Right != nullptr);
	assert(*tree1.GetRootNode().lock()->Right->Right->Data == *tree2.GetRootNode().lock()->Right->Right->Data);
	// 25
	assert(tree1.GetRootNode().lock()->Right->Right->Left != nullptr);
	assert(tree2.GetRootNode().lock()->Right->Right->Left != nullptr);
	assert(*tree1.GetRootNode().lock()->Right->Right->Left->Data == *tree2.GetRootNode().lock()->Right->Right->Left->Data);
	// 24
	assert(tree1.GetRootNode().lock()->Right->Right->Left->Left != nullptr);
	assert(tree2.GetRootNode().lock()->Right->Right->Left->Left != nullptr);
	assert(*tree1.GetRootNode().lock()->Right->Right->Left->Left->Data == *tree2.GetRootNode().lock()->Right->Right->Left->Left->Data);
	// 26
	assert(tree1.GetRootNode().lock()->Right->Right->Left->Right != nullptr);
	assert(tree2.GetRootNode().lock()->Right->Right->Left->Right != nullptr);
	assert(*tree1.GetRootNode().lock()->Right->Right->Left->Right->Data == *tree2.GetRootNode().lock()->Right->Right->Left->Right->Data);
	assert(*tree1.GetRootNode().lock()->Right->Right->Left->Right->Data == 26);
	// 48
	assert(tree1.GetRootNode().lock()->Right->Right->Right != nullptr);
	assert(tree2.GetRootNode().lock()->Right->Right->Right != nullptr);
	assert(*tree1.GetRootNode().lock()->Right->Right->Right->Data == *tree2.GetRootNode().lock()->Right->Right->Right->Data);
	// 40
	assert(tree1.GetRootNode().lock()->Right->Right->Left->Right->Right != nullptr);
	assert(tree2.GetRootNode().lock()->Right->Right->Left->Right->Right != nullptr);
	assert(*tree1.GetRootNode().lock()->Right->Right->Left->Right->Right->Data == *tree2.GetRootNode().lock()->Right->Right->Left->Right->Right->Data);
	assert(*tree1.GetRootNode().lock()->Right->Right->Left->Right->Right->Data == 40);
	// 41
	assert(tree1.GetRootNode().lock()->Right->Right->Left->Right->Right->Right != nullptr);
	assert(tree2.GetRootNode().lock()->Right->Right->Left->Right->Right->Right != nullptr);
	assert(*tree1.GetRootNode().lock()->Right->Right->Left->Right->Right->Right->Data == *tree2.GetRootNode().lock()->Right->Right->Left->Right->Right->Right->Data);
	assert(*tree1.GetRootNode().lock()->Right->Right->Left->Right->Right->Right->Data == 41);

}

void TestCaseFromSlackOnlyRightLeft()
{
	BinarySearchTree<int> tree1;
	tree1.Insert(std::make_unique<int>(8));
	tree1.Insert(std::make_unique<int>(5));
	tree1.Insert(std::make_unique<int>(30));
	tree1.Insert(std::make_unique<int>(20));
	tree1.Insert(std::make_unique<int>(45));
	tree1.Insert(std::make_unique<int>(11));
	tree1.Insert(std::make_unique<int>(25));
	tree1.Insert(std::make_unique<int>(40));
	tree1.Insert(std::make_unique<int>(48));
	tree1.Insert(std::make_unique<int>(24));
	tree1.Insert(std::make_unique<int>(39));
	tree1.Insert(std::make_unique<int>(41));
	bool bDeleted1 = tree1.Delete(30);
	assert(bDeleted1);

	BinarySearchTree<int> tree2;
	tree2.Insert(std::make_unique<int>(8));
	tree2.Insert(std::make_unique<int>(5));
	tree2.Insert(std::make_unique<int>(20));
	tree2.Insert(std::make_unique<int>(45));
	tree2.Insert(std::make_unique<int>(11));
	tree2.Insert(std::make_unique<int>(25));
	tree2.Insert(std::make_unique<int>(40));
	tree2.Insert(std::make_unique<int>(48));
	tree2.Insert(std::make_unique<int>(24));
	tree2.Insert(std::make_unique<int>(39));
	tree2.Insert(std::make_unique<int>(41));

	std::vector<int> v1 = tree1.TraverseInOrder(tree1.GetRootNode().lock());
	std::vector<int> v2 = tree2.TraverseInOrder(tree2.GetRootNode().lock());

	assert(v1.size() == 11);
	assert(v2.size() == 11);
	assert(v1[0] == v2[0]);
	assert(v1[1] == v2[1]);
	assert(v1[2] == v2[2]);
	assert(v1[3] == v2[3]);
	assert(v1[4] == v2[4]);
	assert(v1[5] == v2[5]);
	assert(v1[6] == v2[6]);
	assert(v1[7] == v2[7]);
	assert(v1[8] == v2[8]);
	assert(v1[9] == v2[9]);
	assert(v1[10] == v2[10]);


	// 트리 모양이 같은 형태인지 일일이 검토
	// 8
	assert(tree1.GetRootNode().lock() != nullptr);
	assert(tree2.GetRootNode().lock() != nullptr);
	assert(*tree1.GetRootNode().lock()->Data == *tree2.GetRootNode().lock()->Data);
	// 5
	assert(tree1.GetRootNode().lock()->Left != nullptr);
	assert(tree2.GetRootNode().lock()->Left != nullptr);
	assert(*tree1.GetRootNode().lock()->Left->Data == *tree2.GetRootNode().lock()->Left->Data);
	// 20
	assert(tree1.GetRootNode().lock()->Right != nullptr);
	assert(tree2.GetRootNode().lock()->Right != nullptr);
	assert(*tree1.GetRootNode().lock()->Right->Data == *tree2.GetRootNode().lock()->Right->Data);
	// 11
	assert(tree1.GetRootNode().lock()->Right->Left != nullptr);
	assert(tree2.GetRootNode().lock()->Right->Left != nullptr);
	assert(*tree1.GetRootNode().lock()->Right->Left->Data == *tree2.GetRootNode().lock()->Right->Left->Data);
	// 45
	assert(tree1.GetRootNode().lock()->Right->Right != nullptr);
	assert(tree2.GetRootNode().lock()->Right->Right != nullptr);
	assert(*tree1.GetRootNode().lock()->Right->Right->Data == *tree2.GetRootNode().lock()->Right->Right->Data);
	// 25
	assert(tree1.GetRootNode().lock()->Right->Right->Left != nullptr);
	assert(tree2.GetRootNode().lock()->Right->Right->Left != nullptr);
	assert(*tree1.GetRootNode().lock()->Right->Right->Left->Data == *tree2.GetRootNode().lock()->Right->Right->Left->Data);
	assert(*tree1.GetRootNode().lock()->Right->Right->Left->Data == 25);
	// 24
	assert(tree1.GetRootNode().lock()->Right->Right->Left->Left != nullptr);
	assert(tree2.GetRootNode().lock()->Right->Right->Left->Left != nullptr);
	assert(*tree1.GetRootNode().lock()->Right->Right->Left->Left->Data == *tree2.GetRootNode().lock()->Right->Right->Left->Left->Data);
	assert(*tree1.GetRootNode().lock()->Right->Right->Left->Left->Data == 24);
	// 40
	assert(tree1.GetRootNode().lock()->Right->Right->Left->Right != nullptr);
	assert(tree2.GetRootNode().lock()->Right->Right->Left->Right != nullptr);
	assert(*tree1.GetRootNode().lock()->Right->Right->Left->Right->Data == *tree2.GetRootNode().lock()->Right->Right->Left->Right->Data);
	// 48
	assert(tree1.GetRootNode().lock()->Right->Right->Right != nullptr);
	assert(tree2.GetRootNode().lock()->Right->Right->Right != nullptr);
	assert(*tree1.GetRootNode().lock()->Right->Right->Right->Data == *tree2.GetRootNode().lock()->Right->Right->Right->Data);
	// 41
	assert(tree1.GetRootNode().lock()->Right->Right->Left->Right->Right != nullptr);
	assert(tree2.GetRootNode().lock()->Right->Right->Left->Right->Right != nullptr);
	assert(*tree1.GetRootNode().lock()->Right->Right->Left->Right->Right->Data == *tree2.GetRootNode().lock()->Right->Right->Left->Right->Right->Data);
	assert(*tree1.GetRootNode().lock()->Right->Right->Left->Right->Right->Data == 41);
	// 39
	assert(tree1.GetRootNode().lock()->Right->Right->Left->Right->Left != nullptr);
	assert(tree2.GetRootNode().lock()->Right->Right->Left->Right->Left != nullptr);
	assert(*tree1.GetRootNode().lock()->Right->Right->Left->Right->Left->Data == *tree2.GetRootNode().lock()->Right->Right->Left->Right->Left->Data);
	assert(*tree1.GetRootNode().lock()->Right->Right->Left->Right->Left->Data == 39);

}

void TestCaseFromSlackLeftRightWithRightChild()
{
	BinarySearchTree<int> tree1;
	tree1.Insert(std::make_unique<int>(8));
	tree1.Insert(std::make_unique<int>(5));
	tree1.Insert(std::make_unique<int>(30));
	tree1.Insert(std::make_unique<int>(20));
	tree1.Insert(std::make_unique<int>(45));
	tree1.Insert(std::make_unique<int>(11));
	tree1.Insert(std::make_unique<int>(25));
	tree1.Insert(std::make_unique<int>(40));
	tree1.Insert(std::make_unique<int>(48));
	tree1.Insert(std::make_unique<int>(24));
	tree1.Insert(std::make_unique<int>(26));
	tree1.Insert(std::make_unique<int>(27));
	tree1.Insert(std::make_unique<int>(39));
	tree1.Insert(std::make_unique<int>(41));
	bool bDeleted1 = tree1.Delete(30);
	assert(bDeleted1);

	BinarySearchTree<int> tree2;
	tree2.Insert(std::make_unique<int>(8));
	tree2.Insert(std::make_unique<int>(5));
	tree2.Insert(std::make_unique<int>(20));
	tree2.Insert(std::make_unique<int>(45));
	tree2.Insert(std::make_unique<int>(11));
	tree2.Insert(std::make_unique<int>(25));
	tree2.Insert(std::make_unique<int>(40));
	tree2.Insert(std::make_unique<int>(48));
	tree2.Insert(std::make_unique<int>(24));
	tree2.Insert(std::make_unique<int>(26));
	tree2.Insert(std::make_unique<int>(27));
	tree2.Insert(std::make_unique<int>(39));
	tree2.Insert(std::make_unique<int>(41));

	std::vector<int> v1 = tree1.TraverseInOrder(tree1.GetRootNode().lock());
	std::vector<int> v2 = tree2.TraverseInOrder(tree2.GetRootNode().lock());

	assert(v1.size() == 13);
	assert(v2.size() == 13);
	assert(v1[0] == v2[0]);
	assert(v1[1] == v2[1]);
	assert(v1[2] == v2[2]);
	assert(v1[3] == v2[3]);
	assert(v1[4] == v2[4]);
	assert(v1[5] == v2[5]);
	assert(v1[6] == v2[6]);
	assert(v1[7] == v2[7]);
	assert(v1[8] == v2[8]);
	assert(v1[9] == v2[9]);
	assert(v1[10] == v2[10]);
	assert(v1[11] == v2[11]);
	assert(v1[12] == v2[12]);


	// 트리 모양이 같은 형태인지 일일이 검토
	// 8
	assert(tree1.GetRootNode().lock() != nullptr);
	assert(tree2.GetRootNode().lock() != nullptr);
	assert(*tree1.GetRootNode().lock()->Data == *tree2.GetRootNode().lock()->Data);
	// 5
	assert(tree1.GetRootNode().lock()->Left != nullptr);
	assert(tree2.GetRootNode().lock()->Left != nullptr);
	assert(*tree1.GetRootNode().lock()->Left->Data == *tree2.GetRootNode().lock()->Left->Data);
	// 20
	assert(tree1.GetRootNode().lock()->Right != nullptr);
	assert(tree2.GetRootNode().lock()->Right != nullptr);
	assert(*tree1.GetRootNode().lock()->Right->Data == *tree2.GetRootNode().lock()->Right->Data);
	// 11
	assert(tree1.GetRootNode().lock()->Right->Left != nullptr);
	assert(tree2.GetRootNode().lock()->Right->Left != nullptr);
	assert(*tree1.GetRootNode().lock()->Right->Left->Data == *tree2.GetRootNode().lock()->Right->Left->Data);
	// 45
	assert(tree1.GetRootNode().lock()->Right->Right != nullptr);
	assert(tree2.GetRootNode().lock()->Right->Right != nullptr);
	assert(*tree1.GetRootNode().lock()->Right->Right->Data == *tree2.GetRootNode().lock()->Right->Right->Data);
	// 25
	assert(tree1.GetRootNode().lock()->Right->Right->Left != nullptr);
	assert(tree2.GetRootNode().lock()->Right->Right->Left != nullptr);
	assert(*tree1.GetRootNode().lock()->Right->Right->Left->Data == *tree2.GetRootNode().lock()->Right->Right->Left->Data);
	// 24
	assert(tree1.GetRootNode().lock()->Right->Right->Left->Left != nullptr);
	assert(tree2.GetRootNode().lock()->Right->Right->Left->Left != nullptr);
	assert(*tree1.GetRootNode().lock()->Right->Right->Left->Left->Data == *tree2.GetRootNode().lock()->Right->Right->Left->Left->Data);
	// 40
	assert(tree1.GetRootNode().lock()->Right->Right->Left->Right != nullptr);
	assert(tree2.GetRootNode().lock()->Right->Right->Left->Right != nullptr);
	assert(*tree1.GetRootNode().lock()->Right->Right->Left->Right->Data == *tree2.GetRootNode().lock()->Right->Right->Left->Right->Data);
	// 48
	assert(tree1.GetRootNode().lock()->Right->Right->Right != nullptr);
	assert(tree2.GetRootNode().lock()->Right->Right->Right != nullptr);
	assert(*tree1.GetRootNode().lock()->Right->Right->Right->Data == *tree2.GetRootNode().lock()->Right->Right->Right->Data);
	// 26
	assert(tree1.GetRootNode().lock()->Right->Right->Left->Right->Left != nullptr);
	assert(tree2.GetRootNode().lock()->Right->Right->Left->Right->Left != nullptr);
	assert(*tree1.GetRootNode().lock()->Right->Right->Left->Right->Left->Data == *tree2.GetRootNode().lock()->Right->Right->Left->Right->Left->Data);
	// 41
	assert(tree1.GetRootNode().lock()->Right->Right->Left->Right->Right != nullptr);
	assert(tree2.GetRootNode().lock()->Right->Right->Left->Right->Right != nullptr);
	assert(*tree1.GetRootNode().lock()->Right->Right->Left->Right->Right->Data == *tree2.GetRootNode().lock()->Right->Right->Left->Right->Right->Data);
	// 27
	assert(tree1.GetRootNode().lock()->Right->Right->Left->Right->Left->Right != nullptr);
	assert(tree2.GetRootNode().lock()->Right->Right->Left->Right->Left->Right != nullptr);
	assert(*tree1.GetRootNode().lock()->Right->Right->Left->Right->Left->Right->Data == *tree2.GetRootNode().lock()->Right->Right->Left->Right->Left->Right->Data);
	assert(*tree1.GetRootNode().lock()->Right->Right->Left->Right->Left->Right->Data == 27);
	// 39
	assert(tree1.GetRootNode().lock()->Right->Right->Left->Right->Left->Right->Right != nullptr);
	assert(tree2.GetRootNode().lock()->Right->Right->Left->Right->Left->Right->Right != nullptr);
	assert(*tree1.GetRootNode().lock()->Right->Right->Left->Right->Left->Right->Right->Data == *tree2.GetRootNode().lock()->Right->Right->Left->Right->Left->Right->Right->Data);
	assert(*tree1.GetRootNode().lock()->Right->Right->Left->Right->Left->Right->Right->Data == 39);

}

void Test_Insert_Case()
{
	BinarySearchTree<int> tree;

	int arr[31] = { 16,
		8, 24,
		4, 12, 20, 28,
	2, 6, 10, 14, 18, 22, 26, 30,
	1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31 };

	for (unsigned int i = 0; i < 31; i++)
		tree.Insert(std::make_unique<int>(arr[i]));

	std::vector<int> result;

	std::shared_ptr<TreeNode<int>> test0 = tree.GetRootNode().lock();

	//	- 동일한값인 경우
	//	-- - 동일한 값의 왼쪽에 자식이 없는경우
	tree.Insert(std::make_unique<int>(3));
	result = tree.TraverseInOrder(tree.GetRootNode().lock());

	tree.CheckBSTRule(tree.GetRootNode().lock());

	//	-- - 동일한 값의 왼쪽에 자식이 없는경우 (두번 추가)
	tree.Insert(std::make_unique<int>(3));
	result = tree.TraverseInOrder(tree.GetRootNode().lock());

	tree.CheckBSTRule(tree.GetRootNode().lock());

	//	-- - 동일한 값의 왼쪽에 자식이 있는경우
//	------ - 후보(동일한 값의 노드의 왼쪽 최대값)가 자식이 없는 경우
	tree.Insert(std::make_unique<int>(12)); // 후보 11 서브 10 부모 8
	result = tree.TraverseInOrder(tree.GetRootNode().lock());
	//	------ - 후보(동일한 값의 노드의 왼쪽 최대값)가 자식이 있는 경우(여러개)
	tree.Delete(21);
	tree.Delete(22);
	tree.Delete(23);

	tree.Insert(std::make_unique<int>(24));
	result = tree.TraverseInOrder(tree.GetRootNode().lock());

	tree.CheckBSTRule(tree.GetRootNode().lock());

	//	-- - 동일한 값이 루트인 경우
	tree.Insert(std::make_unique<int>(16));
	result = tree.TraverseInOrder(tree.GetRootNode().lock());

	tree.CheckBSTRule(tree.GetRootNode().lock());

	return;
}

int GetRandom(unsigned int Max)
{
	unsigned int random;

	random = rand() % Max;

	return random;
}

void Test_Random()
{
	BinarySearchTree<int> tree;
	std::vector<int> travereseResult;
	std::multiset<int> reference;

	unsigned int datalength = 0;
	unsigned int i = 0;
	unsigned int k = 0;
	unsigned int times = 0;
	const unsigned int range = 50;
	bool bSolution;
	int function;

	srand(44);

	while (1)
	{
		times++;

		cout << "== Trial : " << times << " == ";

		travereseResult.clear();

		function = GetRandom(4);

		switch (function)
		{
		case 0:
			i = GetRandom(range);
			cout << "Insert " << i << endl;

			reference.insert(i); // push to reference;
			tree.Insert(std::make_unique<int>(i));

			travereseResult = tree.CheckBSTRule(tree.GetRootNode().lock());

			break;

		case 1:
			i = GetRandom(range);
			cout << "Delete " << i << endl;

			bSolution = false;
			for (auto it = reference.begin(); it != reference.end(); ++it)
			{
				if (i == *it)
				{
					bSolution = true;
					reference.erase(it);

					break;
				}
			}

			if (tree.Delete(i) != bSolution)
				assert(0);

			travereseResult = tree.CheckBSTRule(tree.GetRootNode().lock());

			break;

		case 2:
			i = GetRandom(range);
			cout << "Search " << i << endl;

			bSolution = false;
			for (auto it = reference.begin(); it != reference.end(); ++it)
			{
				if (i == *it)
				{
					bSolution = true;

					break;
				}
			}

			if (tree.Search(i) != bSolution)
				assert(0);

			travereseResult = tree.CheckBSTRule(tree.GetRootNode().lock());

			break;

		case 3:
			cout << "Traverse " << endl;
			travereseResult = tree.TraverseInOrder(tree.GetRootNode().lock());

			break;
		}

		// Check result
		if (travereseResult.size() != reference.size())
			assert(0);

		k = 0;
		for (auto it = reference.begin(); it != reference.end(); ++it)
		{
			if (*it != travereseResult[k++])
			{
				cout << "fail on " << *it;
				assert(0);
			}
		}
	}
}

int main()
{
	//	treesametest();
	//	TraverseTest();

	Test_Insert_GetRoot();
	Test_Search();
	Test_Delete();
	Test_Traverse();

	Test_Insert_Case();

	Test_Random();


	//	TestCaseFromSlackOnlyLeftRight();
	//	TestCaseFromSlackOnlyRightLeft();
	//	TestCaseFromSlackLeftRightWithRightChild();

	cout << " end of test " << endl;

	return 0;
}