#include <cassert>
#include <vld.h>

#include "SmartStack.h"
#include "SmartQueue.h"
#include "QueueStack.h"

using namespace assignment3;

void testSmartStack(void)
{
	SmartStack<double> ss;

	ss.Push(3.4);
	ss.Push(1.2);
	ss.Push(4.6);
	ss.Push(3.32);
	ss.Push(10.2);
	ss.Push(1.1);
	ss.Push(-5.9);
	ss.Push(1.1);
	ss.Push(-12.4);
	ss.Push(9.2);

	assert(ss.GetCount() == 10U);
	assert(ss.Peek() == 9.2);
	assert(ss.GetMax() == 10.2);
	assert(ss.GetMin() == -12.4);
	assert(ss.GetSum() == 15.820000000000002);
	assert(ss.GetAverage() == 1.582);
	assert(ss.GetVariance() == 39.983);
	assert(ss.GetStandardDeviation() == 6.323);
	assert(ss.Peek() == 9.2);

	double popped1 = ss.Pop();
	double popped2 = ss.Pop();

	assert(popped1 == 9.2);
	assert(popped2 == -12.4);

	ss.Push(-12.4);
	ss.Push(9.2);

	assert(ss.GetCount() == 10U);
	assert(ss.Peek() == 9.2);
	assert(ss.GetMax() == 10.2);
	assert(ss.GetMin() == -12.4);
	assert(ss.GetSum() == 15.820000000000002);
	assert(ss.GetAverage() == 1.582);
	assert(ss.GetVariance() == 39.983);
	assert(ss.GetStandardDeviation() == 6.323);
	assert(ss.Peek() == 9.2);
	
	SmartStack<double>* ss1 = new SmartStack<double>(ss);

	assert(ss1->GetCount() == 10U);
	assert(ss1->Peek() == 9.2);
	assert(ss1->GetMax() == 10.2);
	assert(ss1->GetMin() == -12.4);
	assert(ss1->GetSum() == 15.820000000000002);
	assert(ss1->GetAverage() == 1.582);
	assert(ss1->GetVariance() == 39.983);
	assert(ss1->GetStandardDeviation() == 6.323);
	assert(ss1->Peek() == 9.2);

	popped1 = ss1->Pop();
	popped2 = ss1->Pop();

	assert(popped1 == 9.2);
	assert(popped2 == -12.4);

	ss1->Push(-12.4);
	ss1->Push(9.2);

	assert(ss1->GetCount() == 10U);
	assert(ss1->Peek() == 9.2);
	assert(ss1->GetMax() == 10.2);
	assert(ss1->GetMin() == -12.4);
	assert(ss1->GetSum() == 15.820000000000002);
	assert(ss1->GetAverage() == 1.582);
	assert(ss1->GetVariance() == 39.983);
	assert(ss1->GetStandardDeviation() == 6.323);
	assert(ss1->Peek() == 9.2);

	*ss1 = ss;

	assert(ss1->GetCount() == 10U);
	assert(ss1->Peek() == 9.2);
	assert(ss1->GetMax() == 10.2);
	assert(ss1->GetMin() == -12.4);
	assert(ss1->GetSum() == 15.820000000000002);
	assert(ss1->GetAverage() == 1.582);
	assert(ss1->GetVariance() == 39.983);
	assert(ss1->GetStandardDeviation() == 6.323);
	assert(ss1->Peek() == 9.2);

	popped1 = ss1->Pop();
	popped2 = ss1->Pop();

	assert(popped1 == 9.2);
	assert(popped2 == -12.4);

	ss1->Push(-12.4);
	ss1->Push(9.2);

	assert(ss1->GetCount() == 10U);
	assert(ss1->Peek() == 9.2);
	assert(ss1->GetMax() == 10.2);
	assert(ss1->GetMin() == -12.4);
	assert(ss1->GetSum() == 15.820000000000002);
	assert(ss1->GetAverage() == 1.582);
	assert(ss1->GetVariance() == 39.983);
	assert(ss1->GetStandardDeviation() == 6.323);
	assert(ss1->Peek() == 9.2);
	delete ss1;
	
}

void testSmartQueue(void)
{
	SmartQueue<double> qq;

	qq.Enqueue(3.4);
	qq.Enqueue(1.2);
	qq.Enqueue(4.6);
	qq.Enqueue(3.32);
	qq.Enqueue(10.2);
	qq.Enqueue(1.1);
	qq.Enqueue(-5.9);
	qq.Enqueue(1.1);
	qq.Enqueue(-12.4);
	qq.Enqueue(9.2);


	assert(qq.GetCount() == 10U);
	assert(qq.Peek() == 3.4);
	assert(qq.GetMax() == 10.2);
	assert(qq.GetMin() == -12.4);
	assert(qq.GetSum() == 15.820000000000002);
	assert(qq.GetAverage() == 1.582);
	assert(qq.GetVariance() == 39.983);
	assert(qq.GetStandardDeviation() == 6.323);
	assert(qq.Peek() == 3.4);

	double popped3 = qq.Dequeue();
	double popped4 = qq.Dequeue();

	assert(popped3 == 3.4);
	assert(popped4 == 1.2);

	qq.Enqueue(1.2);
	qq.Enqueue(3.4);

	assert(qq.GetCount() == 10U);
	assert(qq.Peek() == 4.6);
	assert(qq.GetMax() == 10.2);
	assert(qq.GetMin() == -12.4);
	assert(qq.GetSum() == 15.820000000000002);
	assert(qq.GetAverage() == 1.582);
	assert(qq.GetVariance() == 39.983);
	assert(qq.GetStandardDeviation() == 6.323);
	assert(qq.Peek() == 4.6);
}

void testQueueStack(void)
{
	QueueStack<double> qs(3);

	qs.Enqueue(3.4);//
	qs.Enqueue(1.2);
	qs.Enqueue(4.6);
	qs.Enqueue(3.32);//
	qs.Enqueue(10.2);
	qs.Enqueue(1.1);
	qs.Enqueue(-5.9);//
	qs.Enqueue(1.1);
	qs.Enqueue(-12.4);
	qs.Enqueue(9.2);//

	QueueStack<double> qs1(qs);
	QueueStack<double> qs2 = qs;

	assert(qs1.GetSum() == 15.820000000000002);
	assert(qs1.GetAverage() == 1.582);

	assert(qs2.GetSum() == 15.820000000000002);
	assert(qs2.GetAverage() == 1.582);

	assert(qs.GetSum() == 15.820000000000002);
	assert(qs.GetAverage() == 1.582);

	assert(qs1.GetStackCount() == 4U);
	assert(qs1.GetCount() == 10U);
	assert(qs1.Peek() == 4.6);
	assert(qs1.GetMax() == 10.2);
	assert(qs1.GetMin() == -12.4);
	assert(qs1.Peek() == 4.6);

	assert(qs2.GetStackCount() == 4U);
	assert(qs2.GetCount() == 10U);
	assert(qs2.Peek() == 4.6);
	assert(qs2.GetMax() == 10.2);
	assert(qs2.GetMin() == -12.4);
	assert(qs2.Peek() == 4.6);

	assert(qs.GetStackCount() == 4U);
	assert(qs.GetCount() == 10U);
	assert(qs.Peek() == 4.6);
	assert(qs.GetMax() == 10.2);
	assert(qs.GetMin() == -12.4);
	assert(qs.Peek() == 4.6);

	double popped5 = qs1.Dequeue();
	double popped6 = qs1.Dequeue();
	double popped7 = qs1.Dequeue();
	double popped8 = qs1.Dequeue();

	assert(popped5 == 4.6);
	assert(popped6 == 1.2);
	assert(popped7 == 3.4);
	assert(popped8 == 1.1);

	popped5 = qs1.Dequeue();
	popped6 = qs1.Dequeue();
	popped7 = qs1.Dequeue();
	popped8 = qs1.Dequeue();

	assert(popped5 == 10.2);
	assert(popped6 == 3.32);
	assert(popped7 == -12.4);
	assert(popped8 == 1.1);

	popped5 = qs1.Dequeue();
	popped6 = qs1.Dequeue();

	assert(popped5 == -5.9);
	assert(popped6 == 9.2);

	popped5 = qs2.Dequeue();
	popped6 = qs2.Dequeue();
	popped7 = qs2.Dequeue();
	popped8 = qs2.Dequeue();

	assert(popped5 == 4.6);
	assert(popped6 == 1.2);
	assert(popped7 == 3.4);
	assert(popped8 == 1.1);

	popped5 = qs2.Dequeue();
	popped6 = qs2.Dequeue();
	popped7 = qs2.Dequeue();
	popped8 = qs2.Dequeue();

	assert(popped5 == 10.2);
	assert(popped6 == 3.32);
	assert(popped7 == -12.4);
	assert(popped8 == 1.1);

	popped5 = qs2.Dequeue();
	popped6 = qs2.Dequeue();

	assert(popped5 == -5.9);
	assert(popped6 == 9.2);

	popped5 = qs.Dequeue();
	popped6 = qs.Dequeue();
	popped7 = qs.Dequeue();
	popped8 = qs.Dequeue();

	assert(popped5 == 4.6);
	assert(popped6 == 1.2);
	assert(popped7 == 3.4);
	assert(popped8 == 1.1);

	popped5 = qs.Dequeue();
	popped6 = qs.Dequeue();
	popped7 = qs.Dequeue();
	popped8 = qs.Dequeue();

	assert(popped5 == 10.2);
	assert(popped6 == 3.32);
	assert(popped7 == -12.4);
	assert(popped8 == 1.1);

	popped5 = qs.Dequeue();
	popped6 = qs.Dequeue();

	assert(popped5 == -5.9);
	assert(popped6 == 9.2);

	///

	qs1.Enqueue(3.4);
	qs1.Enqueue(1.2);
	qs1.Enqueue(4.6);
	qs1.Enqueue(3.32);
	qs1.Enqueue(10.2);
	qs1.Enqueue(1.1);
	qs1.Enqueue(-5.9);
	qs1.Enqueue(1.1);
	qs1.Enqueue(-12.4);
	qs1.Enqueue(9.2);

	unsigned int length = qs1.GetCount();
	for (unsigned int i = 0; i < length; i++)
		qs1.Dequeue();

	qs2.Enqueue(3.4);
	qs2.Enqueue(1.2);
	qs2.Enqueue(4.6);
	qs2.Enqueue(3.32);
	qs2.Enqueue(10.2);
	qs2.Enqueue(1.1);
	qs2.Enqueue(-5.9);
	qs2.Enqueue(1.1);
	qs2.Enqueue(-12.4);
	qs2.Enqueue(9.2);

	QueueStack<double>* qs3 = new QueueStack<double>(qs2);

	for (unsigned int a = 0; a < 32; a++)
		qs3->Enqueue(a);

	for (unsigned int a = 0; a < 52; a++)
		qs1.Enqueue(a);

	for (unsigned int a = 0; a < 100; a++)
		qs2.Enqueue(a);

//	for (unsigned int a = 0; a < 200; a++)
//		qs3->Dequeue();

	*qs3 = qs1;

	delete qs3;
}

int main()
{


	testSmartStack();
	testSmartQueue();
	testQueueStack();



	/*
	length = qs2.GetCount();
	for (unsigned int i = 0; i < length; i++)
		qs2.Dequeue();
		*/
	return 0;
}

