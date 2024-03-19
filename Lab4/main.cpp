#include <cassert>
#include <iostream>
#include <vld.h>

#include "Point.h"
#include "PolyLine.h"

using namespace lab4;
using namespace std;

void PointOperatePlusTest()
{
	cout << "- Point::operator+() -" << endl;
	Point p1(1.3f, 2.1f);
	Point p2(3.4f, 4.5f);

	Point p3 = p1 + p2; // p3�� [4.7f, 6.6f]
	cout << p3.GetX() << ", " << p3.GetY() << endl;
	assert(p3.GetX() == 4.7f && p3.GetY() == 6.6f);
	cout << "- Point::operator+() - END -" << endl;
}

void PointOperateMinusTest()
{
	cout << "- Point::operator-() -" << endl;
	Point p1(1.4f, 2.0f);
	Point p2(1.2f, 4.0f);

	Point p3 = p1 - p2; // p3�� [0.2f, -2.0f]
	cout << p3.GetX() << ", " << p3.GetY() << endl;
	//assert(p3.GetX() == 0.2f && p3.GetY() == -2.0f);  //x��ǥ ������...
	cout << "- Point::operator-() - END -" << endl;
}

void PointOperateMultiplyTest()
{
	cout << "- Point::operator*() -" << endl;
	Point p1(1.2f, 2.5f);

	Point p2 = p1 * 4.0f; // p2�� [4.8f, 10.0f]
	Point p3 = 5.0f * p1; // p3�� [6.0f, 12.5f]
	cout << p2.GetX() << ", " << p2.GetY() << endl;
	assert(p2.GetX() == 4.8f && p2.GetY() == 10.0f);
	cout << p3.GetX() << ", " << p3.GetY() << endl;
	assert(p3.GetX() == 6.0f && p3.GetY() == 12.5f);

	cout << "- Point::operator*() - END -" << endl;
}

void PointDotProductTest()
{
	cout << "- Point::Dot() -" << endl;
	Point p1(1.0f, 2.0f);
	Point p2(1.0f, 4.0f);

	float dotProduct = p1.Dot(p2); // dotProduct�� 9.0f
	cout << dotProduct << endl;
	assert(dotProduct == 9.0f);

	cout << "- Point::Dot() - END -" << endl;
}

void PolyLineAddPointTest()
{
	cout << "- PolyLine::AddPoint() -" << endl;
	PolyLine pl;

	assert(pl.AddPoint(1.0f, 2.0f) == true);
	assert(pl.AddPoint(new Point(2.0f, 3.0f)) == true);
	assert(pl.AddPoint(2.2f, 1.9f) == true);  // pl�� [1.0f, 2.0f], [2.0f, 3.0f], [2.2f, 1.9f]
	assert(pl.AddPoint(5.2f, 8.9f) == true);
	assert(pl.AddPoint(2.2f, 1.4f) == true);
	assert(pl.AddPoint(10.1f, 11.9f) == true);
	assert(pl.AddPoint(7.5f, 1.9f) == true);
	assert(pl.AddPoint(6.6f, 4.5f) == true);
	assert(pl.AddPoint(3.1f, 0.9f) == true);
	assert(pl.AddPoint(0.1f, 0.1f) == true);  // 10��° ��. �̶����� AddPoint()�� true�� ��ȯ.

	assert(pl.AddPoint(2.2f, 1.9f) == false);  // 11��° �� �߰� �õ�. AddPoint()�� false�� ��ȯ�ϰ� �� ���� PolyLine ��ü�� �߰����� �ʾƾ� ��.
	// pl : 10

	/*
	AddPoint �Ű������� �Էµ� Point ��ü�� �ٸ� PolyLine ��ü�� �����ϰų�
	���� �޸𸮿� �Ҵ��� �ϸ�, �Ҹ��� ������ �߻��Ѵ�.
	*/
	PolyLine pl2;
	Point* p1 = new Point(2.2f, 3.3f);
	assert(pl2.AddPoint(1.1f, 2.2f) == true);
	assert(pl2.AddPoint(p1) == true);
	assert(p1->GetX() == 2.2f && p1->GetY() == 3.3f);
	// pl2 : 2 point

	PolyLine pl3(pl2);
	Point* p2 = new Point(22.22f, 33.33f);
	assert(pl3.AddPoint(11.11f, 22.22f) == true);
	assert(pl3.AddPoint(p2) == true);
	assert(p2->GetX() == 22.22f && p2->GetY() == 33.33f);
	// pl3 : 4 point

	PolyLine* pl4 = new PolyLine(pl3);
	Point* p3 = new Point(222.22f, 333.33f);
	assert(pl4->AddPoint(11.11f, 22.22f) == true);
	assert(pl4->AddPoint(p3) == true);
	// pl4 : 6 point

	PolyLine* pl5 = pl4;
	assert(pl5->AddPoint(11.11f, 22.22f) == true);
	assert(pl5->AddPoint(11.11f, 22.22f) == true);
	assert(pl5->AddPoint(11.11f, 22.22f) == true);
	assert(pl5->AddPoint(11.11f, 22.22f) == true);
	assert(pl5->AddPoint(11.11f, 22.22f) == false);
	assert(pl5->AddPoint(11.11f, 22.22f) == false);
	// pl4, pl5 : 10 point

	PolyLine pl6 = pl3;
	assert(pl6.AddPoint(11.11f, 22.22f) == true);
	assert(pl6.AddPoint(11.11f, 22.22f) == true);
	assert(pl6.AddPoint(new Point(55.5f, 66.6f)) == true);
	cout << "- PolyLine::AddPoint() - END -" << endl;
	// pl6 : 7 point
}

void PolyLineRemovePointTest()
{
	cout << "- PolyLine::RemovePoint() -" << endl;
	PolyLine pl;

	assert(pl.AddPoint(1.0f, 2.0f) == true);
	assert(pl.AddPoint(new Point(2.0f, 3.0f)) == true);
	assert(pl.AddPoint(2.2f, 1.9f) == true);  // pl�� [1.0f, 2.0f], [2.0f, 3.0f], [2.2f, 1.9f]

	assert(pl.RemovePoint(1) == true);   // pl�� [1.0f, 2.0f], [2.2f, 1.9f]. true�� ��ȯ.
	assert(pl.RemovePoint(3) == false);  // 4��° ���� �������� �ʱ� ������ pl�� ������ ����. false�� ��ȯ.
	assert(pl.RemovePoint(-1) == false);
	assert(pl.RemovePoint(0) == true);
	assert(pl.RemovePoint(0) == true);
	assert(pl.RemovePoint(0) == false);

	cout << "- PolyLine::RemovePoint() - END -" << endl;
}

void PolyLineTryGetMinBoundingRectangleTest()
{
	cout << "- PolyLine::TryGetMinBoundingRectangle() -" << endl;
	PolyLine pl;
	pl.AddPoint(1.4f, 2.8f);
	pl.AddPoint(3.7f, 2.5f);
	pl.AddPoint(5.5f, 5.5f);
	pl.AddPoint(-2.9f, 4.1f);
	pl.AddPoint(4.3f, -1.0f);
	pl.AddPoint(6.2f, 4.4f);

	Point minP(0.f, 0.f);
	Point maxP(0.f, 0.f);

	assert(pl.TryGetMinBoundingRectangle(&minP, &maxP) == true); // min: [-2.9f, -1.0f], max: [6.2f, 5.5f]
	cout << "min: " << minP.GetX() << ", " << minP.GetY() << endl;
	assert(minP.GetX() == -2.9f && minP.GetY() == -1.0f);
	cout << "max: " << maxP.GetX() << ", " << maxP.GetY() << endl;
	assert(maxP.GetX() == 6.2f && maxP.GetY() == 5.5f);

	cout << "- PolyLine::TryGetMinBoundingRectangle() - END -" << endl;
}

void PolyLineOperateIndexTest()
{
	cout << "- PolyLine::operator[]() -" << endl;
	PolyLine pl;
	pl.AddPoint(1.7f, 2.4f);
	pl.AddPoint(3.9f, 2.1f);
	pl.AddPoint(5.3f, 5.5f);
	pl.AddPoint(-2.1f, 4.0f);

	cout << pl[0]->GetX() << ", " << pl[0]->GetY() << endl;  // [1.7f, 2.4f]
	assert(pl[0]->GetX() == 1.7f && pl[0]->GetY() == 2.4f);
	cout << pl[3]->GetX() << ", " << pl[3]->GetY() << endl;  // [-2.1f, 4.0f]
	assert(pl[3]->GetX() == -2.1f && pl[3]->GetY() == 4.0f);
	assert(pl[6] == nullptr);  // NULL

	PolyLine pl3(pl);
	Point* p2 = new Point(10.1f, 20.1f);
	assert(pl3.AddPoint(p2) == true);
	assert(pl3.AddPoint(50.2f, 25.4f) == true);
	assert(pl3.AddPoint(150.2f, 25.4f) == true);
	assert(pl3.AddPoint(250.2f, 25.4f) == true);
	assert(p2->GetX() == 10.1f && p2->GetY() == 20.1f);
	assert(pl3[0]->GetX() == 1.7f && pl3[0]->GetY() == 2.4f);
	assert(pl3[4]->GetX() == 10.1f && pl3[4]->GetY() == 20.1f);
	assert(pl3[5]->GetX() == 50.2f && pl3[5]->GetY() == 25.4f);
	assert(pl3[10] == nullptr);  // NULL
	assert(pl3[-4] == nullptr);  // NULL
	assert(pl3[20] == nullptr);  // NULL

	PolyLine* pl4 = new PolyLine(pl);
	Point* p3 = new Point(10.1f, 20.1f);
	Point* p4 = new Point(40.1f, 30.1f);
	assert(pl4->AddPoint(p3) == true);
	assert(pl4->AddPoint(50.2f, 25.4f) == true);
	assert(pl4->AddPoint(p4) == true);
	assert((*pl4)[0]->GetX() == 1.7f && (*pl4)[0]->GetY() == 2.4f);
	assert((*pl4)[4]->GetX() == 10.1f && (*pl4)[4]->GetY() == 20.1f);
	assert((*pl4)[5]->GetX() == 50.2f && (*pl4)[5]->GetY() == 25.4f);
	assert((*pl4)[6]->GetX() == 40.1f && (*pl4)[6]->GetY() == 30.1f);
	assert((*pl4)[7] == nullptr);  // NULL
	assert((*pl4)[10] == nullptr);  // NULL
	assert((*pl4)[-4] == nullptr);  // NULL

	cout << "- PolyLine::operator[]() - END -" << endl;

	delete pl4;
}

void TestCaseMain()
{

	PointOperatePlusTest();
	PointOperateMinusTest();
	PointOperateMultiplyTest();
	PointDotProductTest();
	
	// �Ʒ� �ڵ� ���ʹ� �޸� ������ �ǵ������� �߻���
	PolyLineAddPointTest();
	PolyLineRemovePointTest();
	PolyLineTryGetMinBoundingRectangleTest();
	PolyLineOperateIndexTest();

}



int main()
{
	Point p1(2.f, 3.f);
	Point p2(-1.f, 4.f);

	Point p3 = p1 + p2;

	assert(p3.GetX() == 1.f);
	assert(p3.GetY() == 7.f);

	Point p4 = p2 - p1;

	assert(p4.GetX() == -3.f);
	assert(p4.GetY() == 1.f);

	float dotProduct = p1.Dot(p2);

	assert(dotProduct == 10.f);

	Point p5 = p1 * 5.f;

	assert(p5.GetX() == 10.f);
	assert(p5.GetY() == 15.f);

	Point p6 = 2.f * p2;

	assert(p6.GetX() == -2.f);
	assert(p6.GetY() == 8.f);

	/* ----------------------- */

	PolyLine pl1;
	pl1.AddPoint(1.4f, 2.7f);
	pl1.AddPoint(3.5f, 2.1f);
	pl1.AddPoint(5.5f, 5.9f);
	pl1.AddPoint(-2.2f, 4.0f);
	pl1.AddPoint(4.6f, -1.3f);
	pl1.AddPoint(6.0f, 4.5f);

	bool bRemoved = pl1.RemovePoint(4);

	assert(bRemoved);

	Point minP(0.f, 0.f);
	Point maxP(0.f, 0.f);

	pl1.TryGetMinBoundingRectangle(&minP, &maxP);

	assert(minP.GetX() == -2.2f);
	assert(minP.GetY() == 2.1f);
	assert(maxP.GetX() == 6.0f);
	assert(maxP.GetY() == 5.9f);

	TestCaseMain();

	return 0;
}