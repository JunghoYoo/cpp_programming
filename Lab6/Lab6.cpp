#include "Lab6.h"
#include <limits>
#include <iterator> 
#include <vector>
#include <iostream>
using namespace std;

namespace lab6
{
	int Sum(const std::vector<int>& v)
	{
		int result;

		result = 0;
		
		for (unsigned int i = 0; i < v.size(); i++)
		{
			result += v[i];
		}

		return result;
	}

	int Min(const std::vector<int>& v)
	{
		int min;

		min = std::numeric_limits<int>::max();

		for (unsigned int i = 0; i < v.size(); i++)
		{
			if (min > v[i])
				min = v[i];
		}

		return min;
	}

	int Max(const std::vector<int>& v)
	{
		int max;

		max = std::numeric_limits<int>::min();

		for (unsigned int i = 0; i < v.size(); i++)
		{
			if (max < v[i])
				max = v[i];
		}

		return max;
	}

	float Average(const std::vector<int>& v)
	{
		float average;

		if (v.size() > 0)
		{
			average = static_cast<float>(Sum(v)) / static_cast<float>(v.size());
		}
		else
		{
			average = 0;
		}

		return average;
	}

	int NumberWithMaxOccurrence(const std::vector<int>& v)
	{
		int occrurrednumber = 0;

		if (v.size() > 0)
		{
			std::vector<int> occurence;
			occurence.reserve(v.size());
			occurence.clear();

			for (unsigned int i = 0; i < v.size(); i++)
			{
				occrurrednumber = 0;

				for (unsigned int k = 0; k < v.size(); k++)
				{
					if (i != k)
					{
						if (v[i] == v[k])
						{
							occrurrednumber++;
						}
					}
				}

				occurence.push_back(occrurrednumber);
			}

			int maxnumber;
			maxnumber = Max(occurence);
			
			if (maxnumber > 0)
			{
				unsigned int k = 0;
				while (occurence[k] != maxnumber)
				{
					k++;
				}

				occrurrednumber = v[k];
			}
			else
			{
				// no occurent number
				occrurrednumber = 0; 
			}
		}
		else
		{
			occrurrednumber = 0;
		}
		
		return occrurrednumber;
	}

	void SortDescending(std::vector<int>& v)
	{
		unsigned int index;
		int temp;

		if (v.size() > 1)
		{
			for (unsigned int i = 0; i < v.size() - 1; i++)
			{
				index = i;
				for (unsigned int k = i + 1; k < v.size(); k++)
				{
					if (v[index] <= v[k])
					{
						index = k;
					}
				}

				// swap
				temp = v[index];
				v[index] = v[i];
				v[i] = temp;
			}
		}
	}

}