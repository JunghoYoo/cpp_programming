#include <cassert>
#include <iostream>

#include "FixedVector.h"
#include "FixedBoolVector.h"

using namespace lab8;
using namespace std;

void TestFixedBoolVectorAddAndRemove()
{
	FixedVector<bool, 64> v1;
	for (int i = 0; i < 64; i++)
	{
		if (i % 2 == 0)
		{
			assert(v1.Add(false));
		}
		else
		{
			assert(v1.Add(true));
		}
	}
	assert(v1.GetSize() == 64);

	for (unsigned int i = 0; i < 32; i += 2)
	{
		assert(!v1.Get(i));
	}
	for (unsigned int i = 1; i < 32; i += 2)
	{
		assert(v1.Get(i));
	}
	assert(v1.GetIndex(true) == 1);
	assert(v1.GetIndex(false) == 0);

	for (int i = 0; i < 32; i++)
	{
		assert(v1.Remove(false));
	}
	assert(v1.GetSize() == 32);
	for (int i = 0; i < 32; i++)
	{
		cout << "i: " << i << endl;
		assert(v1.Get(i));
	}

	cout << v1.GetIndex(false) << endl;
	assert(v1.GetIndex(true) == 0);
	assert(v1.GetIndex(false) == -1);

	FixedVector<bool, 64> v2;

	for (int i = 0; i < 64; i++)
	{
		assert(v2.Add(false));
	}
	assert(v2.GetSize() == 64);
	assert(v2.GetIndex(true) == -1);
	assert(v2.GetIndex(false) == 0);


	FixedVector<bool, 64> v3;

	for (int i = 0; i < 64; i++)
	{
		assert(v3.Add(true));
	}
	assert(v3.GetSize() == 64);
	assert(v3.GetIndex(true) == 0);
	assert(v3.GetIndex(false) == -1);

	for (int i = 0; i < 64; i++)
	{
		assert(v2.Remove(false));
	}
	assert(v2.GetSize() == 0);
	assert(v2.GetIndex(true) == -1);
	assert(v2.GetIndex(false) == -1);


	for (int i = 0; i < 64; i++)
	{
		assert(v3.Remove(true));
	}
	assert(v3.GetSize() == 0);
	assert(v3.GetIndex(true) == -1);
	assert(v3.GetIndex(false) == -1);
}

void TestMain()
{
	int i1 = 23;
	int i2 = 25;
	int i3 = 10;
	int i4 = -4;
	int i5 = 70;

	FixedVector<int, 33> iv;

	assert(iv.GetCapacity() == 33);

	iv.Add(i1);
	iv.Add(i2);
	iv.Add(i3);
	iv.Add(i4);

	assert(iv.GetSize() == 4);
	assert(iv.GetIndex(i2) == 1);
	assert(iv.Get(1) == i2);
	assert(iv[1] == i2);

	bool bRemoved = iv.Remove(i5);
	assert(!bRemoved);
	assert(iv.GetSize() == 4);

	bRemoved = iv.Remove(i2);
	assert(bRemoved);
	assert(iv.GetSize() == 3);
	assert(iv.GetIndex(i2) == -1);

	FixedVector<bool, 10> v;

	assert(v.GetCapacity() == 10);

	v.Add(true);
	v.Add(true);
	v.Add(true);
	v.Add(true);
	v.Add(false);
	v.Add(false);
	v.Add(true);

	assert(v.GetSize() == 7);
	assert(v.Get(0));
	assert(v.Get(1));
	assert(v.Get(2));
	assert(v.Get(3));
	assert(!v.Get(4));
	assert(!v.Get(5));
	assert(v.Get(6));

	v.Remove(false);

	assert(v.GetSize() == 6);
	assert(!v.Get(4));
	assert(v.Get(5));

	v.Remove(false);

	assert(v.GetSize() == 5);

	for (size_t i = 0; i < v.GetSize(); i++)
	{
		assert(v[i]);
	}

	v.Remove(true);

	assert(v.GetSize() == 4);

	for (size_t i = 0; i < v.GetSize(); i++)
	{
		assert(v[i]);
	}

	FixedVector<bool, 65> v1;

	for (int i = 0; i < 65; i++)
	{
		v1.Add(false);
	}

	assert(v1.Add(true) == false);
	assert(v1.GetSize() == 65);
	assert(v1.GetIndex(true) == -1);
}

void TestMain2()
{
	int integerArray1[] = { 23, 25, 10, -4, 70 };
	enum { INTEGER_VECTOR1_SIZE = 4 };

	FixedVector<int, 4> integerVector1;

	assert(integerVector1.GetCapacity() == INTEGER_VECTOR1_SIZE);
	assert(integerVector1.GetSize() == 0);
	std::cout << "Test FixedVector constructor: PASS" << std::endl;

	assert(integerVector1.Add(integerArray1[0]) == true);
	assert(integerVector1.Add(integerArray1[1]) == true);
	assert(integerVector1.Add(integerArray1[2]) == true);
	assert(integerVector1.Add(integerArray1[3]) == true);
	assert(integerVector1.GetSize() == INTEGER_VECTOR1_SIZE);
	std::cout << "Test FixedVector Add(): PASS" << std::endl;
	assert(integerVector1.Add(integerArray1[4]) == false);
	assert(integerVector1.GetSize() == INTEGER_VECTOR1_SIZE);
	std::cout << "Test FixedVector Add() - over array range: PASS" << std::endl;

	integerVector1.Add(integerArray1[0]);
	integerVector1.Add(integerArray1[1]);
	integerVector1.Add(integerArray1[2]);
	integerVector1.Add(integerArray1[3]);
	assert(integerVector1.GetIndex(integerArray1[1]) == 1);
	std::cout << "Test FixedVector GetIndex(): PASS" << std::endl;
	assert(integerVector1.Get(1) == integerArray1[1]);
	std::cout << "Test FixedVector Get(): PASS" << std::endl;
	assert(integerVector1[1] == integerArray1[1]);
	std::cout << "Test FixedVector operator[](): PASS" << std::endl;	integerVector1[0] = integerArray1[1];
	assert(integerVector1[0] == integerArray1[1]);
	integerVector1[0] = integerArray1[0];
	assert(integerVector1[0] == integerArray1[0]);
	std::cout << "Test FixedVector operator[]() - return reference: PASS" << std::endl;

	for (size_t i = 0; i < INTEGER_VECTOR1_SIZE; ++i)
	{
		assert(integerVector1.Remove(integerArray1[i]) == true);
		assert(integerVector1.GetSize() == INTEGER_VECTOR1_SIZE - (i + 1));
		for (size_t j = 0; j < integerVector1.GetSize(); ++j)
		{
			assert(integerVector1[j] == integerArray1[i + j + 1]);
		}
	}
	std::cout << "Test FixedVector Remove() - order not changed after remove data: PASS" << std::endl;
	assert(integerVector1.Remove(integerArray1[4]) == false);
	assert(integerVector1.GetSize() == INTEGER_VECTOR1_SIZE - 4);
	std::cout << "Test FixedVector Remove() - empty array: PASS" << std::endl;

	enum { BOOL_VECTOR1_SIZE = 7 };
	bool boolArray1[] = {
		true,	/* 0 */
		true,	/* 1 */
		true,	/* 2 */
		true,	/* 3 */
		false,	/* 4 */
		false,	/* 5 */
		true,	/* 6 */
		true	/* 7 - exceeded data */
	};
	FixedVector<bool, BOOL_VECTOR1_SIZE> boolVector1;
	assert(boolVector1.GetCapacity() == BOOL_VECTOR1_SIZE);
	assert(boolVector1.GetSize() == 0);
	std::cout << "Test FixedBoolVector constructor: PASS" << std::endl;
	int a= sizeof(boolVector1);
	assert(sizeof(boolVector1) == (sizeof(int32_t) + sizeof(size_t) + sizeof(size_t)));
	std::cout << "Test FixedBoolVector constructor - fit memroy: PASS" << std::endl;

	assert(boolVector1.Add(boolArray1[0]) == true);
	assert(boolVector1.Add(boolArray1[1]) == true);
	assert(boolVector1.Add(boolArray1[2]) == true);
	assert(boolVector1.Add(boolArray1[3]) == true);
	assert(boolVector1.Add(boolArray1[4]) == true);
	assert(boolVector1.Add(boolArray1[5]) == true);
	assert(boolVector1.Add(boolArray1[6]) == true);
	assert(boolVector1.GetSize() == 7);
	assert(boolVector1.Get(0) == boolArray1[0]);
	assert(boolVector1.Get(1) == boolArray1[1]);
	assert(boolVector1.Get(2) == boolArray1[2]);
	assert(boolVector1.Get(3) == boolArray1[3]);
	assert(boolVector1.Get(4) == boolArray1[4]);
	assert(boolVector1.Get(5) == boolArray1[5]);
	assert(boolVector1.Get(6) == boolArray1[6]);
	std::cout << "Test FixedBoolVector Add(): PASS" << std::endl;
	assert(boolVector1.Add(boolArray1[7]) == false);
	assert(boolVector1.GetSize() == 7);
	std::cout << "Test FixedBoolVector Add() - over array range: PASS" << std::endl;

	assert(boolVector1.Remove(false) == true);
	assert(boolVector1.GetSize() == 6);
	assert(boolVector1.Get(4) == boolArray1[5]);
	assert(boolVector1.Get(5) == boolArray1[6]);
	assert(boolVector1.Remove(false) == true);
	assert(boolVector1.GetSize() == 5);
	assert(boolVector1.Get(4) == boolArray1[6]);
	std::cout << "Test FixedBoolVector Remove(): PASS" << std::endl;
	assert(boolVector1.Remove(false) == false);
	assert(boolVector1.GetSize() == 5);
	std::cout << "Test FixedBoolVector Remove() - not found: PASS" << std::endl;

	for (size_t i = 0; i < boolVector1.GetSize(); i++)
	{
		assert(boolVector1[i]);
	}
	boolVector1.Remove(true);
	assert(boolVector1.GetSize() == 4);
	for (size_t i = 0; i < boolVector1.GetSize(); i++)
	{
		assert(boolVector1[i]);
	}
	std::cout << "Test FixedBoolVector operator[]() - read: PASS" << std::endl;

	FixedVector<bool, 65> boolVector2;

	assert(sizeof(boolVector2) == (3*(sizeof(int32_t)) + sizeof(size_t) + sizeof(size_t))); // 65/32 = 2.xxx -> 3
	std::cout << "Test FixedBoolVector constructor - fit memroy: PASS" << std::endl;
	for (int i = 0; i < 65; i++)
	{
		boolVector2.Add(false);
	}

	assert(boolVector2.Add(true) == false);
	assert(boolVector2.GetSize() == 65);
	assert(boolVector2.GetIndex(true) == -1);
	std::cout << "Test FixedBoolVector GetIndex(): PASS" << std::endl;
}

int main()
{

	TestMain();
	TestMain2();
	TestFixedBoolVectorAddAndRemove();



	FixedVector<int, 99999> iv;

	assert(iv.GetCapacity() == 99999);


	for (unsigned int i=0;i<3000;i++)
		iv.Add(i);

	for (unsigned int i = 0; i < 1000; i=i+3)
		iv.Remove(i);

	int index;

	for (unsigned int i = 0; i < 1000; i++)
	{
		index = iv.GetIndex(i);

		if (i % 3 == 0)
		{
			assert(index == -1);
		}
		else
		{
			assert(index != -1);
		}

	}

	return 0;
}