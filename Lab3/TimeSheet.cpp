#include "Timesheet.h"

namespace lab3
{
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
	{
		this->mName = name;
		this->mMaxEntries = maxEntries;

		if (this->mMaxEntries > 0)
			this->mPtime = new unsigned int[this->mMaxEntries];

		this->mIndex = 0;
	}

	TimeSheet::TimeSheet(const TimeSheet& other)
	{
		this->mName = other.mName;
		this->mMaxEntries = other.mMaxEntries;

		if (this->mMaxEntries > 0)
		{
			this->mPtime = new unsigned int[this->mMaxEntries];
			this->mIndex = other.mIndex;

			for (unsigned int index = 0; index < this->mIndex; index++)
			{
				this->mPtime[index] = other.mPtime[index];
			}
		}
	}

	TimeSheet::~TimeSheet()
	{
		if (mMaxEntries > 0)
			delete[] mPtime;
	}

	void TimeSheet::AddTime(int timeInHours)
	{
		if (timeInHours >= 1)
		{
			if (timeInHours <= 10)
			{
				if (mIndex < mMaxEntries)
				{
					mPtime[mIndex] = timeInHours;
					mIndex++;
				}
			}
		}
	}

	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		if (index < mIndex)
		{
			return mPtime[index];
		}
		else
		{
			return -1;
		}
	}

	int TimeSheet::GetTotalTime() const
	{
		int totaltime = 0;

		for (unsigned int index = 0; index < mIndex; index++)
		{
			totaltime += mPtime[index];
		}

		return totaltime;
	}

	float TimeSheet::GetAverageTime() const
	{
		float averagetime;

		if (mIndex > 0)
			averagetime = GetTotalTime() / (float)mIndex;
		else
			averagetime = 0.0f;

		return averagetime;
	}

	float TimeSheet::GetStandardDeviation() const
	{
		float std;
		float var;
		float avg;
		float diff;
		
		var = 0;
		avg = GetAverageTime();

		for (unsigned int index = 0; index < mIndex; index++)
		{
			diff = mPtime[index] - avg;
			var += (float)pow(diff, 2.0f);
		}

		if (mIndex > 0)
			var = var / mIndex;
		else
			var = 0.0f;

		std = (float)sqrt(var);

		return std;
	}

	const std::string& TimeSheet::GetName() const
	{
		return mName;
	}

	TimeSheet& TimeSheet::operator=(const TimeSheet& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}
		else 
		{
			// prev
			if (this->mMaxEntries > 0)
				delete[] this->mPtime;

			this->mMaxEntries = rhs.mMaxEntries;
			this->mName = rhs.mName;

			// next
			if (this->mMaxEntries > 0)
			{
				this->mPtime = new unsigned int[this->mMaxEntries];
				this->mIndex = rhs.mIndex;

				for (unsigned int index = 0; index < this->mIndex; index++)
				{
					this->mPtime[index] = rhs.mPtime[index];
				}
			}

			return *this;
		}
	}
}