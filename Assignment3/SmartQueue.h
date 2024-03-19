#pragma once

#include <stack>
#include <queue>

namespace assignment3
{
	template <class T>
	class SmartQueue
	{
	public:
		SmartQueue();
		SmartQueue(SmartQueue& rhs);
		virtual ~SmartQueue();

		void Enqueue(T number);
		T Dequeue(void);
		T Peek(void);
		T GetMax(void);
		T GetMin(void);
		double GetAverage(void);
		T GetSum(void) const;
		double GetVariance(void);// O(1)
		double GetStandardDeviation(void);
		unsigned int GetCount(void) const;
		SmartQueue& operator=(SmartQueue& rhs);

	private:
		double roundToPont(double number, unsigned int point);

	private:
		std::queue<T> mQueue;

		double mSum;
		double mSum2;
	};
	template <typename T> SmartQueue<T>::SmartQueue() : mSum(0.0), mSum2(0.0)
	{
	};
	template <typename T> SmartQueue<T>::SmartQueue(SmartQueue& rhs) : mSum(rhs.mSum), mSum2(rhs.mSum2)
	{
		if (rhs.mCount > 0)
		{
			T temp;

			std::queue<std::stack<T>*> queue;

			unsigned int queuelength;
			queuelength = rhs.mQueue.size();

			// iteration
			for (unsigned int i = 0; i < queuelength; i++)
			{
				temp = rhs.mQueue.front();
				rhs.mQueue.pop();

				mQueue.push(temp);

				queue.push(temp);
			}

			rhs.mQueue.swap(queue);
		}
	}

	template <typename T> SmartQueue<T>::~SmartQueue()
	{
	}
	
	template <typename T>
	SmartQueue<T>& SmartQueue<T>::operator=(SmartQueue& rhs)
	{
		if (this != &rhs)
		{
			mSum = rhs.mSum;
			mSum2 = rhs.mSum2;

			if (rhs.mCount > 0)
			{
				T temp;

				std::queue<std::stack<T>*> queue;

				unsigned int queuelength;
				queuelength = rhs.mQueue.size();

				// iteration
				for (unsigned int i = 0; i < queuelength; i++)
				{
					temp = rhs.mQueue.front();
					rhs.mQueue.pop();

					mQueue.push(temp);

					queue.push(temp);
				}

				rhs.mQueue.swap(queue);
			}

			return *this;
		}
		else
		{
			return *this;
		}
	}

	template <typename T>
	void SmartQueue<T>::Enqueue(T number)
	{
		double average;
		double average2;

		mQueue.push(number);

		mSum = mSum + static_cast<double>(number);
		mSum2 = mSum2 + static_cast<double>(number * number);

		average = mSum / mQueue.size();
		average2 = mSum2 / mQueue.size();
	};

	template <typename T>
	T SmartQueue<T>::Dequeue(void)
	{
		T number;

		if (mQueue.size() > 1)
		{
			double average;
			double average2;

			number = mQueue.front();
			mQueue.pop();

			// update sum, average, variance
			mSum = mSum - number;
			mSum2 = mSum2 - number * number;

			average = static_cast<double>(mSum) / mQueue.size();
			average2 = static_cast<double>(mSum2) / mQueue.size();
		}
		else
		{
			if (mQueue.size() == 1)
			{
				number = mQueue.front();
				mQueue.pop();
				// now empty
			}
			else // nothing to pop
			{
				number = NULL;
			}

			// now empty
			mSum = 0.0;
			mSum2 = 0.0;
		}

		return number;
	};

	template <typename T>
	T SmartQueue<T>::Peek(void)
	{
		if (mQueue.size() > 0)
			return mQueue.front();
		else
			return NULL;
	};

	template <typename T>
	T SmartQueue<T>::GetMax(void)
	{
		T max = std::numeric_limits<T>::lowest();

		std::queue<T> queue;
		unsigned int length;
		length = mQueue.size();
		T temp;

		// iteration
		for (unsigned int i = 0; i < length; i++)
		{
			temp = mQueue.front();
			mQueue.pop();

			// update
			if (max < temp)
				max = temp;

			queue.push(temp);
		}

		mQueue.swap(queue);

		return max;
	};

	template <typename T>
	T SmartQueue<T>::GetMin(void)
	{
		T min = std::numeric_limits<T>::max();

		std::queue<T> queue;
		unsigned int length;
		length = mQueue.size();
		T temp;

		// iteration
		for (unsigned int i = 0; i < length; i++)
		{
			temp = mQueue.front();
			mQueue.pop();

			// update
			if (min > temp)
				min = temp;

			queue.push(temp);
		}

		mQueue.swap(queue);

		return min;
	};

	template <typename T>
	double SmartQueue<T>::GetAverage(void)
	{
		if (mQueue.size() > 0)
		{
			std::queue<T> queue;
			unsigned int length;
			length = mQueue.size();
			T temp;
			
			// initial
			double average = 0;

			// iteration
			for (unsigned int i = 0; i < length; i++)
			{
				temp = mQueue.front();
				mQueue.pop();

				// update
				average += static_cast<double>(temp);

				queue.push(temp);
			}

			mQueue.swap(queue);

			average = average / length;

			return roundToPont(average, 3);
		}
		else
			return NULL;
	};

	template <typename T>
	T SmartQueue<T>::GetSum(void) const
	{
		if (mQueue.size() > 0)
			return static_cast<T>(mSum);
		else
			return NULL;
	};

	template <typename T>
	double SmartQueue<T>::GetVariance(void)
	{
		if (mQueue.size() > 0)
		{
			double average;
			double average2;
			double variance;

			average = mSum / mQueue.size();
			average2 = mSum2 / mQueue.size();

			variance = average2 - average * average;

			return roundToPont(variance, 3);
		}
		else
			return NULL;
	};

	template <typename T>
	double SmartQueue<T>::GetStandardDeviation(void)
	{
		if (mQueue.size() > 0)
		{
			double average;
			double average2;
			double variance;

			average = mSum / mQueue.size();
			average2 = mSum2 / mQueue.size();

			variance = average2 - average * average;

			return roundToPont(sqrt(variance), 3);
		}
		else
			return NULL;
	};

	template <typename T>
	unsigned int SmartQueue<T>::GetCount(void) const
	{
		return mQueue.size();
	};

	template <typename T>
	double SmartQueue<T>::roundToPont(double number, unsigned int point)
	{
		double rounded;

		rounded = round(number * pow(10, point)) / pow(10, point);

		return rounded;
	}
}