#include "Person.h"
#include <cassert>

namespace assignment2
{
	Person::Person(const char* name, unsigned int weight)
	{
		mName = name;
		mWeight = weight;
	}

	Person::Person(const Person& person)
	{
		mName = person.mName;
		mWeight = person.mWeight;
	}

	Person::~Person()
	{
	}

	Person& Person::operator=(const Person& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}
		else
		{
			mName = rhs.mName;
			mWeight = rhs.mWeight;

			return *this;
		}
	}

	const std::string& Person::GetName() const
	{
		return mName;
	}

	unsigned int Person::GetWeight() const
	{
		return mWeight;
	}
}