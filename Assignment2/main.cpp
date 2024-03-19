#include <cassert>
#include <vld.h>
#include <iostream>
#include <istream>

#define CRTDBG_MAP_ALLOC 
#include <stdlib.h> 
#include <crtdbg.h>


#ifdef _DEBUG

#define new new( _NORMAL_BLOCK, __FILE__, __LINE__ )   // #include <new.h>등으로 operator new나 malloc을 

// Derived해서 정의 한 경우, 사용 할 수 없다.

#endif

#include "Vehicle.h"
#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include "Motorcycle.h"
#include "Sedan.h"
#include "Trailer.h"
#include "UBoat.h"
#include "DeusExMachina.h"
#include "Person.h"
#include "UBoat.h"

#define STR(name) #name

using namespace assignment2;
using namespace std;

void TestTravel()
{
	Person* p1 = new Person("Bob", 85);
	Person* p2 = new Person("James", 75);
	Person* p3 = new Person("Tina", 52);

	Person* p4 = new Person("Peter", 78);
	Person* p5 = new Person("Jane", 48);
	Person* p6 = new Person("Steve", 88);

	Person* p7 = new Person("Bob", 85);
	Person* p8 = new Person("James", 75);
	Person* p9 = new Person("Tina", 52);

	Person* p10 = new Person("Peter", 78);
	Person* p11 = new Person("Jane", 48);
	Person* p12 = new Person("Steve", 88);

	Airplane *a = new Airplane(5);
	a->AddPassenger(p1);
	a->AddPassenger(p2);
	a->AddPassenger(p3);

	Boat* b = new Boat(5);
	b->AddPassenger(p4);
	b->AddPassenger(p5);
	b->AddPassenger(p6);

	Boatplane* bp = new Boatplane(5);
	bp->AddPassenger(p7);
	bp->AddPassenger(p8);
	
	Motorcycle* m = new Motorcycle();
	m->AddPassenger(p9);

	Sedan* s = new Sedan();
	s->AddPassenger(p10);
	s->AddPassenger(p11);
	s->AddPassenger(p12);

	Trailer* t = new Trailer(99);
	s->AddTrailer(t);

	DeusExMachina* deusExMachina1 = DeusExMachina::GetInstance();

	deusExMachina1->Travel();
	deusExMachina1->GetFurthestTravelled();
	cout << endl;

	deusExMachina1->AddVehicle(a);
	deusExMachina1->Travel();
	deusExMachina1->GetFurthestTravelled();

	cout << endl;

	deusExMachina1->AddVehicle(b);
	deusExMachina1->Travel();
	deusExMachina1->GetFurthestTravelled();

	cout << endl;

	deusExMachina1->RemoveVehicle(0);
	deusExMachina1->Travel();
	deusExMachina1->GetFurthestTravelled();

	deusExMachina1->AddVehicle(bp);
	deusExMachina1->Travel();
	deusExMachina1->GetFurthestTravelled();

	cout << endl;

	deusExMachina1->AddVehicle(m);
	deusExMachina1->Travel();
	deusExMachina1->GetFurthestTravelled();

	cout << endl;

	deusExMachina1->AddVehicle(s);
	deusExMachina1->Travel();
	deusExMachina1->GetFurthestTravelled();

	cout << endl;

	deusExMachina1->RemoveVehicle(3);
	deusExMachina1->RemoveVehicle(2);
	deusExMachina1->RemoveVehicle(1);
	deusExMachina1->RemoveVehicle(0);
}

void TestExample()
{
	Person* p = new Person("Bob", 85);

	assert(p->GetName() == std::string("Bob"));
	assert(p->GetWeight() == 85);

	Person* p2 = new Person("James", 75);
	Person* p3 = new Person("Tina", 52);

	Person* p4 = new Person("Peter", 78);
	Person* p5 = new Person("Jane", 48);
	Person* p6 = new Person("Steve", 88);

	Airplane a(5);
	a.AddPassenger(p);
	a.AddPassenger(p2);
	a.AddPassenger(p3);

	assert(a.GetMaxPassengersCount() == 5);
	assert(a.GetPassengersCount() == 3);
	assert(a.GetPassenger(1) == p2);
	assert(a.GetFlySpeed() == 648);
	assert(a.GetDriveSpeed() == 59);
	assert(a.GetMaxSpeed() == 648);

	Boat b(5);
	b.AddPassenger(p4);
	b.AddPassenger(p5);
	b.AddPassenger(p6);

	Boatplane bp = a + b;

	assert(bp.GetPassengersCount() == 6);
	assert(bp.GetMaxPassengersCount() == 10);

	assert(a.GetPassengersCount() == 0);
	assert(b.GetPassengersCount() == 0);

	DeusExMachina* deusExMachina1 = DeusExMachina::GetInstance();
	DeusExMachina* deusExMachina2 = DeusExMachina::GetInstance();

	bool bSame = deusExMachina1 == deusExMachina2;
	assert(bSame);

	Airplane* airplane = new Airplane(5);
	Boat* boat = new Boat(5);
	Boatplane* boatplane = new Boatplane(5);
	Motorcycle* motorcycle = new Motorcycle();
	Sedan* sedan = new Sedan();
	Sedan* sedan2 = new Sedan();
	UBoat* uboat = new UBoat();

	bool bAdded = sedan2->AddTrailer(new Trailer(50));
	assert(bAdded);

//	bAdded = sedan2->AddTrailer(new Trailer(60)); // leak because of not added
//	assert(!bAdded); 

	bAdded = deusExMachina1->AddVehicle(airplane);
	assert(bAdded);

	deusExMachina1->AddVehicle(boat);
	deusExMachina1->AddVehicle(boatplane);
	deusExMachina1->AddVehicle(motorcycle);
	deusExMachina1->AddVehicle(sedan);
	deusExMachina1->AddVehicle(sedan2);
	deusExMachina1->AddVehicle(uboat);
	deusExMachina1->AddVehicle(new Airplane(5));
	deusExMachina1->AddVehicle(new Airplane(5));
	deusExMachina1->AddVehicle(new Airplane(5));

//	bAdded = deusExMachina1->AddVehicle(new Airplane(5)); // leak because of not added
//	assert(!bAdded);

	deusExMachina1->RemoveVehicle(9);
	deusExMachina1->RemoveVehicle(8);
	bool bRemoved = deusExMachina1->RemoveVehicle(7);
	assert(bRemoved);

	bRemoved = deusExMachina1->RemoveVehicle(9);
	assert(!bRemoved);

	deusExMachina1->Travel(); // 모든 운송 수단이 이동
	deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan, UBoat가 이동
	deusExMachina1->Travel(); // Motorcycle, 두 Sedan이 이동
	deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan이 이동
	deusExMachina1->Travel(); // UBoat만 빼고 전부 이동
	deusExMachina1->Travel(); // 어떤 운송 수단도 움직이지 않음
	deusExMachina1->Travel(); // Boat, Motorcycle, 트레일러 안 달린 Sedan, UBoat가 이동
	deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan, UBoat가 이동
	deusExMachina1->Travel(); // Airplane, Boatplane, Motorcycle, 두 Sedan이 이동
	deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan이 이동
	deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan이 이동
	deusExMachina1->Travel(); // 트레일러 달린 Sedan만 이동

	assert(deusExMachina1->GetFurthestTravelled() == boat);

//	deusExMachina1->RemoveVehicle(3);
}

void TestGoogleDocs()
{
	const char* MAX_SPEED_LABLE = "Max Speed: ";
	const char* CUR_P_LABLE = "Current Person: ";
	const unsigned int MAX_CAPACITY = 10;

	Vehicle* air = new Airplane(MAX_CAPACITY);

	Person* toAdd;
	const unsigned int personWeight = 10;

	for (size_t i = 0; i < MAX_CAPACITY + 10; i++)
	{
		toAdd = new Person(STR(i), i);
		if (air->AddPassenger(toAdd) == false)
		{
			delete toAdd;
		}

		cout << MAX_SPEED_LABLE << air->GetMaxSpeed() << endl
			<< CUR_P_LABLE << air->GetPassengersCount() << endl;
	}

	while (air->RemovePassenger(0))
	{
		cout << CUR_P_LABLE << air->GetPassengersCount() << endl;;
	}

	Person* overlapTest = new Person("Overlap Test", 100);
	air->AddPassenger(overlapTest);
	air->AddPassenger(overlapTest);
	assert(air->GetPassengersCount() == 1);

	toAdd = NULL;
	assert(air->AddPassenger(toAdd) == false);

	delete air;

	Airplane dockingTest1(10);
	Boat dockingTest2(10);

	for (size_t i = 0; i < 5; i++)
	{
		dockingTest1.AddPassenger(new Person(STR(i), i));
		dockingTest2.AddPassenger(new Person(STR(i), i));
	}

	const Person* comp1 = dockingTest1.GetPassenger(0);

	Boatplane bp1 = dockingTest1 + dockingTest2;
	Boatplane bp2 = dockingTest2 + dockingTest1;

	const Person* comp2 = bp1.GetPassenger(0);

	//assert(comp1 == comp2); // check order ??? there is no that requirements
	assert(dockingTest1.GetPassengersCount() == 0);
	assert(dockingTest2.GetPassengersCount() == 0);
	assert(bp1.GetPassengersCount() == 10);
	assert(bp2.GetPassengersCount() == 0);

	Boatplane copyConstuctorTest(bp1);

	for (size_t i = 0; i < bp1.GetPassengersCount(); i++)
	{
		const Person* p1 = bp1.GetPassenger(i);
		const Person* p2 = copyConstuctorTest.GetPassenger(i);
		assert(p1 != p2);
	}
	assert(bp1.GetMaxPassengersCount() == copyConstuctorTest.GetMaxPassengersCount());
	assert(bp1.GetPassengersCount() == copyConstuctorTest.GetPassengersCount());
	assert(bp1.GetMaxSpeed() == copyConstuctorTest.GetMaxSpeed());

	Sedan sedanTest;
	Trailer* t1 = new Trailer(10);
	Trailer* t2 = new Trailer(20);

	assert(sedanTest.AddTrailer(t1));
	assert(!sedanTest.AddTrailer(t1)); // overlap test
	assert(!sedanTest.AddTrailer(t2)); // maximum trailer test
	assert(sedanTest.RemoveTrailer());
	assert(sedanTest.AddTrailer(t2));
	assert(sedanTest.RemoveTrailer());

	DeusExMachina* d = DeusExMachina::GetInstance();
	Vehicle* demAirplain = new Airplane(MAX_CAPACITY);
	Vehicle* demBoat = new Airplane(MAX_CAPACITY);
	Vehicle* demBoatplain = new Boatplane(MAX_CAPACITY);
	Vehicle* demMotorcycle = new Motorcycle();
	Vehicle* demSedan1 = new Sedan();
	Vehicle* demSedan2 = new Sedan();
	Trailer* demTrailer = new Trailer(10);
	static_cast<Sedan*>(demSedan2)->AddTrailer(demTrailer);
	Vehicle* demUBoat = new UBoat();

	d->AddVehicle(demAirplain);
	d->AddVehicle(demBoat);
	d->AddVehicle(demBoatplain);
	d->AddVehicle(demMotorcycle);
	d->AddVehicle(demSedan1);
	d->AddVehicle(demSedan2);
	d->AddVehicle(demUBoat);

	for (size_t i = 0; i < 7; i++) 
	{
		Vehicle* tempVPointer = d->GetVehicle(i);
		for (size_t j = tempVPointer->GetPassengersCount(); j < tempVPointer->GetMaxPassengersCount(); j++)
		{
			tempVPointer->AddPassenger(new Person(STR((i + j)), 10));
		}
	}

	for (size_t i = 0; i < 10; i++)
	{
		d->Travel();
	}

	for (size_t i = 7; i > 0; i--)
	{
		d->RemoveVehicle(i-1);
	}
}

void TestVehicle()
{
	Person* p1 = new Person("Bob", 85);
	Person* p2 = new Person("James", 75);
	Person* p3 = new Person("Tina", 52);

	Person* p4 = new Person("Peter", 78);
	Person* p5 = new Person("Jane", 48);
	Person* p6 = new Person("Steve", 88);

	Person* p7 = new Person("Peter", 78);
	Person* p8 = new Person("Jane", 48);
	Person* p9 = new Person("Steve", 88);

	Person* p10 = new Person("Peter", 78);
	Person* p11 = new Person("Jane", 48);
	Person* p12 = new Person("Steve", 88);

	Person* p13 = new Person("Bob", 85);
	Person* p14 = new Person("James", 75);
	Person* p15 = new Person("Tina", 52);

	Person* p16 = new Person("Peter", 78);
	Person* p17 = new Person("Jane", 48);
	Person* p18 = new Person("Steve", 88);

	Person* p19 = new Person("Peter", 78);
	Person* p20 = new Person("Jane", 48);

	Airplane* a = new Airplane(5);
	a->AddPassenger(p1);
	a->AddPassenger(p2);
	a->AddPassenger(p3);

	Boat* b = new Boat(5);
	b->AddPassenger(p4);
	b->AddPassenger(p5);
	b->AddPassenger(p6);

	Boatplane *bp1 = new Boatplane(*a + *b);
	bp1->AddPassenger(p7);

	a->AddPassenger(p8);
	a->AddPassenger(p9);

	b->AddPassenger(p10);
	b->AddPassenger(p11);
	b->AddPassenger(p12);

	Boatplane* bp2 = new Boatplane(*a + *b);
	bp2->AddPassenger(p13);
	bp2->AddPassenger(p14);

	Motorcycle* m = new Motorcycle();
	m->AddPassenger(p15);

	Sedan* s1 = new Sedan();
	s1->AddPassenger(p16);

	Sedan* s2 = new Sedan();
	s2->AddPassenger(p17);

	UBoat* u = new UBoat();
	u->AddPassenger(p18);
	u->AddPassenger(p19);
	u->AddPassenger(p20);

	s2->AddTrailer(new Trailer(10));
	/*
	unsigned int k;
	k = a->GetPassengersCount();
	for (int i=k-1; i >= 0; i--)
		a->RemovePassenger(i);
	
	k = b->GetPassengersCount();
	for (int i = k - 1; i >= 0; i--)
		b->RemovePassenger(i);

	k = bp1->GetPassengersCount();
	for (int i = k - 1; i >= 0; i--)
		bp1->RemovePassenger(i);
		*/

	Sedan* s3 = new Sedan(*s2);
	Airplane* a1 = new Airplane(*a);

	s2->RemoveTrailer();
	s2->AddTrailer(new Trailer(10));
	s2->RemoveTrailer();
	s2->RemoveTrailer();
	s2->RemoveTrailer();

	a->RemovePassenger(0);
	b->RemovePassenger(1);
	bp1->RemovePassenger(1);
	bp2->RemovePassenger(1);
	s1->RemovePassenger(1);
	s2->RemovePassenger(1);
	u->RemovePassenger(1);
	m->RemovePassenger(1);

	m->RemovePassenger(11);
	s1->RemovePassenger(12);

	*a = *a;
	*b = *b;
	*bp1 = *bp1;
	*bp2 = *bp2;
	*s1 = *s1;
	*s2 = *s2;
	*u = *u;
	*m = *m;



	delete a;
	delete a1;
	delete b;
	delete bp1;
	delete bp2;
	delete s1;
	delete s3;
	delete s2;
	delete u;
	delete m;
}

void TestMemory()
{
	unsigned int maxLimit;

	maxLimit = 110;
	Airplane* t = new Airplane(maxLimit);

	Person* p;

	for (unsigned int i = 0; i < maxLimit; i++)
	{
		p = new Person("ddd", i);
		if (t->AddPassenger(p) == false)
		{
			cout << "Limit Passenger on " << i << endl;
			delete p;
			break;
		}
	}

	delete t;

	Boat* bb = new Boat(maxLimit);

	for (unsigned int i = 0; i < maxLimit; i++)
	{
		p = new Person("ddd", i);
		if (bb->AddPassenger(p) == false)
		{
			cout << "Limit Passenger on " << i << endl;
			delete p;
			break;
		}
	}

	delete bb;

	maxLimit = 110;
	Boatplane* tdd = new Boatplane(maxLimit);

	for (unsigned int i = 0; i < maxLimit; i++)
	{
		p = new Person("ddd", i);
		if (tdd->AddPassenger(p) == false)
		{
			cout << "Limit Passenger on " << i << endl;
			delete p;
			break;
		}
	}

	delete tdd;

	maxLimit = 110;
	Motorcycle* ta = new Motorcycle();
	
	for (unsigned int i = 0; i < maxLimit; i++)
	{
		p = new Person("ddd", i);
		if (ta->AddPassenger(p) == false)
		{
			cout << "Limit Passenger on " << i << endl;
			delete p;
			break;
		}
	}

	delete ta;

	maxLimit = 110;
	Sedan* tt = new Sedan();

	for (unsigned int i = 0; i < maxLimit; i++)
	{
		p = new Person("ddd", i);
		if (tt->AddPassenger(p) == false)
		{
			cout << "Limit Passenger on " << i << endl;
			delete p;
			break;
		}
	}

	delete tt;

	maxLimit = 110;
	UBoat* taaaa = new UBoat();

	for (unsigned int i = 0; i < maxLimit; i++)
	{
		p = new Person("ddd", i);
		if (taaaa->AddPassenger(p) == false)
		{
			cout << "Limit Passenger on " << i << endl;
			delete p;
			break;
		}
	}

	delete taaaa;


}


int main()
{
	TestExample();
	TestTravel();
	TestGoogleDocs();
	TestVehicle();
	TestMemory();

	string outputMemoryLeaks = "Memory Leak? "
		+ std::to_string(static_cast<long>(_CrtDumpMemoryLeaks()));
	cout << outputMemoryLeaks.c_str() << endl;
	cout << "MemoryLeak";
}

