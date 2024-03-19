#pragma once

#include <stack>
#include <queue>
#include <limits>

namespace assignment3
{
	template <typename T>
	class SmartStack
	{
	public:
		SmartStack();
		SmartStack(SmartStack& rhs);
		virtual ~SmartStack();

		void Push(T number); // O(1)
		T Pop(void);// O(1)
		T Peek(void);
		T GetMax(void) const;// O(1)
		T GetMin(void) const;// O(1)
		double GetAverage(void);
		T GetSum(void) const;
		double GetVariance(void);// O(1)
		double GetStandardDeviation(void);
		unsigned int GetCount(void) const;
		SmartStack& operator=(SmartStack& rhs);

	private:
		double roundToPont(double number, unsigned int point);

	private:
		std::stack<T> mStack;

		T mMax;
		T mMin;
		T mSum3;
		double mAverage;
		double mAverage2;
		double mVariance;
		double mSum;
		double mSum2;
	};

	template <typename T> SmartStack<T>::SmartStack() : mMax(0), mMin(0), mVariance(0.0), mAverage(0.0), mAverage2(0.0), mSum(0), mSum2(0), mSum3(0)
	{			
		mMax = std::numeric_limits<T>::lowest();
		mMin = std::numeric_limits<T>::max();
	};
	template <typename T> SmartStack<T>::SmartStack(SmartStack& rhs) : mMax(rhs.mMax), mMin(rhs.mMin), mVariance(rhs.mVariance), mAverage(rhs.mAverage), mAverage2(rhs.mAverage2), mSum(rhs.mSum), mSum2(rhs.mSum2), mSum3(rhs.mSum3)
	{
		unsigned int length;
		length = rhs.mStack.size();

		T temp;
		std::stack<T> stack; 
		
		for (unsigned int i = 0; i < length; i++)
		{
			temp = rhs.mStack.top();
			rhs.mStack.pop();

			stack.push(temp);
		}

		// change order of data LIFO -> LIFO 
		for (unsigned int i = 0; i < length; i++)
		{
			temp = stack.top();
			stack.pop();

			mStack.push(temp);

			rhs.mStack.push(temp);
		}
	}

	template <typename T> SmartStack<T>::~SmartStack()
	{
	};

	template <typename T>
	SmartStack<T>& SmartStack<T>::operator=(SmartStack& rhs)
	{
		if (this != &rhs)
		{
			// clear
			unsigned int length;
			length = mStack.size();
			for (unsigned int i = 0; i < length; i++)
			{
				mStack.pop();
			}

			mVariance = rhs.mVariance;
			mAverage = rhs.mAverage;
			mAverage2 = rhs.mAverage2;
			mSum = rhs.mSum;
			mSum2 = rhs.mSum2;
			mSum3 = rhs.mSum3;

			mMax = rhs.mMax;
			mMin = rhs.mMin;

			length = rhs.mStack.size();

			T temp;
			std::stack<T> stack;

			for (unsigned int i = 0; i < length; i++)
			{
				temp = rhs.mStack.top();
				rhs.mStack.pop();

				stack.push(temp);
			}

			// change order of data LIFO -> LIFO 
			for (unsigned int i = 0; i < length; i++)
			{
				temp = stack.top();
				stack.pop();

				mStack.push(temp);

				rhs.mStack.push(temp);
			}

			return *this;
		}
		else
		{
			return *this;
		}
	}
	template <typename T>
	void SmartStack<T>::Push(T number)
	{
		mStack.push(number);
		
		if (mMax < number)
			mMax = number;

		if (mMin > number)
			mMin = number;

		mSum = mSum + number;
		mSum2 = mSum2 + number * number;

		mSum3 = mSum3 + static_cast<T>(number);

		mAverage = mSum / mStack.size();
		mAverage2 = mSum2 / mStack.size();

		mVariance = mAverage2 - mAverage * mAverage;
	};

	template <typename T>
	T SmartStack<T>::Pop(void)
	{
		T number;

		if (mStack.size() > 1)
		{
			number = mStack.top();

			if ((number == mMax) ||
				(number == mMin))
			{
				std::stack<T> stack;
				
				// to be returned
				mStack.pop();

				// ¼øÈ¸ 
				
				// intialize
				mMax = std::numeric_limits<T>::lowest();
				mMin = std::numeric_limits<T>::max();

				unsigned int length;
				length = mStack.size();

				T temp;
				for (unsigned int i = 0; i < length; i++)
				{
					temp = mStack.top();
					mStack.pop();

					// mMax, mMin update
					if (mMax < temp)
						mMax = temp;

					if (mMin > temp)
						mMin = temp;

					stack.push(temp);
				}

				// change order of data LIFO -> LIFO 
				for (unsigned int i = 0; i < length; i++)
				{
					temp = stack.top();
					stack.pop();

					mStack.push(temp);
				}
			}
			else
			{
				mStack.pop();
			}

			// update sum, average, variance
			mSum = mSum - number;
			mSum2 = mSum2 - number * number;

			mSum3 = mSum3 - static_cast<T>(number);

			mAverage = mSum / mStack.size();
			mAverage2 = mSum2 / mStack.size();

			mVariance = mAverage2 - mAverage * mAverage;
		}
		else 
		{
			if (mStack.size() == 1) 
			{
				number = mStack.top();
				mStack.pop();

				// now empty
				mSum = 0;
				mSum2 = 0;
				mAverage = 0.0;
				mAverage2 = 0.0;
				mVariance = 0.0;

				mSum3 = static_cast<T>(0);
			}
			else // empty - nothing to pop
			{
				number = 0;

				// now empty
				mSum = 0;
				mSum2 = 0;
				mAverage = 0.0;
				mAverage2 = 0.0;
				mVariance = 0.0;

				mSum3 = static_cast<T>(0);
			}
		}

		return number;
	};

	template <typename T>
	T SmartStack<T>::Peek(void)
	{
		if (mStack.size() > 0)
			return mStack.top();
		else
			return NULL;
	};

	template <typename T>
	T SmartStack<T>::GetMax(void) const
	{
		return mMax;
	};

	template <typename T>
	T SmartStack<T>::GetMin(void) const
	{
		return mMin;
	};

	template <typename T>
	double SmartStack<T>::GetAverage(void)
	{
		if (mStack.size() > 0)
			return roundToPont(mAverage, 3);
		else
			return NULL;
	};

	template <typename T>
	T SmartStack<T>::GetSum(void) const
	{
		if (mStack.size() > 0)
			return mSum3;
		else
			return NULL;
	};

	template <typename T>
	double SmartStack<T>::GetVariance(void)
	{
		if (mStack.size() > 0)
			return roundToPont(mVariance, 3);
		else
			return NULL;
	};

	template <typename T>
	double SmartStack<T>::GetStandardDeviation(void)
	{
		if (mStack.size() > 0)
			return roundToPont(sqrt(mVariance), 3);
		else
			return NULL;
	};

	template <typename T>
	unsigned int SmartStack<T>::GetCount(void) const
	{
		return mStack.size();
	};

	template <typename T>
	double SmartStack<T>::roundToPont(double number, unsigned int point)
	{
		double rounded;

		rounded = round(number * pow(10, point)) / pow(10, point);

		return rounded;
	}
}