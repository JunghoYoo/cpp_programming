#include "TimeSheet.h"
using namespace lab3;
#include <vld.h>
#include <iostream>

int main()
{
	TimeSheet p1("Pope", 3);

	p1.AddTime(3); // [ 3 ]
	p1.AddTime(11); // [ 3 ]
	p1.AddTime(2); // [ 3, 2 ]
	p1.AddTime(-1); // [ 3, 2 ]
	p1.AddTime(0); // [ 3, 2 ]
	p1.AddTime(6); // [ 3, 2, 6 ]
	p1.AddTime(4); // [ 3, 2, 6 ]


	TimeSheet p2("Pope", 10);

	p2.AddTime(2);
	p2.AddTime(3);
	p2.AddTime(10);

	p2.GetTimeEntry(2); // returns 10
	p2.GetTimeEntry(6); // returns -1
	p2.GetTimeEntry(0); // returns 2

	TimeSheet p3("Pope", 10);

	p3.AddTime(2);
	p3.AddTime(3);
	p3.AddTime(10);

	p3.GetTotalTime(); // 15 반환

	TimeSheet p4("Pope", 10);

	p4.AddTime(4);
	p4.AddTime(7);
	p4.AddTime(6);
	p4.AddTime(5);
	p4.AddTime(1);
	p4.AddTime(2);

	p4.GetAverageTime(); // 4.1667 반환


	TimeSheet p5("Pope", 10);

	p5.AddTime(4);
	p5.AddTime(7);
	p5.AddTime(6);
	p5.AddTime(5);
	p5.AddTime(1);
	p5.AddTime(2);

	p5.GetStandardDeviation(); // 2.11476 반환

	TimeSheet p6("Pope", 7);

	p6.GetName(); // "Pope" 반환


	lab3::TimeSheet employee1("John", 10);
	employee1.AddTime(4);
	employee1.AddTime(7);
	std::cout << "Employee: " << employee1.GetName() << " / AverageTime: " << employee1.GetAverageTime() << " / TotalTime: " << employee1.GetTotalTime() << std::endl;


	TimeSheet p7(p5);


	return 0;

}