#pragma once

#include <stack>
#include <queue>
#include "SmartStack.h"

namespace assignment3
{

	template <class T>
	class QueueStack
	{
	public:
		QueueStack(unsigned int maxStackSize);
		QueueStack(QueueStack& rhs);
		virtual ~QueueStack();

		void Enqueue(T number);
		T Dequeue(void);
		T Peek(void);
		T GetMax(void);
		T GetMin(void);
		double GetAverage(void);
		T GetSum(void);
		unsigned int GetCount(void) const;
		unsigned int GetStackCount(void) const;

		QueueStack& operator=(QueueStack& rhs);

	private:
		double roundToPont(double number, unsigned int point);

	private:
		std::queue<std::stack<T>*> mQueue;

		unsigned int mCount;
		unsigned int mMaxStackSize;

		T mSum;
	};

	template <typename T> QueueStack<T>::QueueStack(unsigned int maxStackSize) : mMaxStackSize(maxStackSize), mCount(0), mSum(0)
	{
	};

	template <typename T> QueueStack<T>::~QueueStack()
	{
		std::stack<T>* stack;
		unsigned length = GetStackCount();

		for (unsigned int i = 0; i < length; i++)
		{
			stack = mQueue.front();
			mQueue.pop();
			delete stack;
		}
	};

	template <typename T> QueueStack<T>::QueueStack(QueueStack& rhs) : mMaxStackSize(rhs.mMaxStackSize), mCount(0), mSum(0)
	{
		if (rhs.mCount > 0)
		{
			T temp;

			std::queue<std::stack<T>*> queue;

			unsigned int queuelength;
			queuelength = rhs.mQueue.size();
			
			std::stack<T>* stack;
			unsigned int stacklength;
			
			std::stack<T> stacktemp;

			// iteration
			for (unsigned int i = 0; i < queuelength; i++)
			{
				stack = rhs.mQueue.front();
				rhs.mQueue.pop();
				
				stacklength = stack->size();

				// update
				for (unsigned int k = 0; k < stacklength; k++)
				{
					temp = stack->top();
					stack->pop();

					stacktemp.push(temp);
				}
				
				// reverse order
				for (unsigned int k = 0; k < stacklength; k++)
				{
					temp = stacktemp.top();
					stacktemp.pop();

					// push
					Enqueue(temp);

					stack->push(temp);
				}

				queue.push(stack);

				stacklength = stacktemp.size();
				for (unsigned int k = 0; k < stacklength; k++)
					stacktemp.pop();
			}

			rhs.mQueue.swap(queue);

			queuelength = queue.size();
			for (unsigned int k = 0; k < queuelength; k++)
			{
				delete queue.front();
				queue.pop();
			}
		}
	};

	template <typename T> 
	QueueStack<T>& QueueStack<T>::operator=(QueueStack& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}
		else
		{
			// delete existing 
			std::stack<T>* stack;
			unsigned int length = GetStackCount();

			for (unsigned int i = 0; i < length; i++)
			{
				stack = mQueue.front();
				mQueue.pop();

				unsigned int stacklength = stack->size();
				for (unsigned int k = 0; k < stacklength; k++)
					stack->pop();

				delete stack;
			}
			
			// copy
			mMaxStackSize = rhs.mMaxStackSize;
			mCount = 0;

			if (rhs.mCount > 0)
			{
				T temp;

				std::queue<std::stack<T>*> queue;
				
				unsigned int queuelength;
				queuelength = rhs.mQueue.size();
				
				std::stack<T>* stack;
				unsigned int stacklength;

				std::stack<T> stacktemp;

				// iteration
				for (unsigned int i = 0; i < queuelength; i++)
				{
					stack = rhs.mQueue.front();
					stacklength = stack->size();

					rhs.mQueue.pop();

					// update
					for (unsigned int k = 0; k < stacklength; k++)
					{
						temp = stack->top();
						stack->pop();

						stacktemp.push(temp);
					}

					// reverse order
					for (unsigned int k = 0; k < stacklength; k++)
					{
						temp = stacktemp.top();
						stacktemp.pop();

						// push
						Enqueue(temp);

						stack->push(temp);
					}

					queue.push(stack);

					stacklength = stacktemp.size();
					for (unsigned int k = 0; k < stacklength; k++)
						stacktemp.pop();

				}

				rhs.mQueue.swap(queue);

				queuelength = queue.size();
				for (unsigned int k = 0; k < queuelength; k++)
				{
					delete queue.front();
					queue.pop();
				}
			}

			return *this;
		}
	};

	template <typename T>
	void QueueStack<T>::Enqueue(T number)
	{
		std::stack<T>* stack;

		if (mCount % mMaxStackSize == 0)
		{
			stack = new std::stack<T>;
			mQueue.push(stack);
		}
		else
		{
			stack = mQueue.back();
		}

		mSum += number;
		mCount++;

		stack->push(number);
	};

	template <typename T>
	T QueueStack<T>::Dequeue(void)
	{
		T number;
		std::stack<T>* stack;

		if (mCount > 0)
		{
			mCount--;

			stack = mQueue.front();
			// not pop from queue
			number = stack->top();
			stack->pop();

			mSum -= number;
			
			if (stack->size() == 0)
			{
				mQueue.pop();
				delete stack;
			}
		}
		else
		{
			// no element
			number = 0;
			mSum = 0;
		}

		return number;
	};

	template <typename T>
	T QueueStack<T>::Peek(void)
	{
		if (mCount > 0)
			return (mQueue.front())->top();
		else
			return NULL;
	};

	template <typename T>
	T QueueStack<T>::GetMax(void)
	{
		T max;
		max = std::numeric_limits<T>::lowest();

		std::queue<std::stack<T>*> queue;

		unsigned int length;
		length = mQueue.size();
		std::stack<T>* stack;
		std::stack<T> stacktemp;
		T temp;

		// iteration
		for (unsigned int i = 0; i < length; i++)
		{
			stack = mQueue.front();
			mQueue.pop();

			unsigned int stacklength;
			stacklength = stack->size();

			for (unsigned int k = 0; k < stacklength; k++)
			{
				temp = stack->top();
				stack->pop();

				// mMax, mMin update
				if (max < temp)
					max = temp;

				stacktemp.push(temp);
			}

			// change order of data LIFO -> LIFO 
			for (unsigned int i = 0; i < stacklength; i++)
			{
				temp = stacktemp.top();
				stacktemp.pop();

				stack->push(temp);
			}

			queue.push(stack);
		}

		mQueue.swap(queue);

		unsigned int queuelength = queue.size();
		for (unsigned int k = 0; k < queuelength; k++)
		{
			delete queue.front();
			queue.pop();
		}

		return max;
	};

	template <typename T>
	T QueueStack<T>::GetMin(void)
	{
		T min;
		min = std::numeric_limits<T>::max();

		std::queue<std::stack<T>*> queue;

		unsigned int length;
		length = mQueue.size();
		std::stack<T>* stack;
		std::stack<T> stacktemp;
		T temp;

		// iteration
		for (unsigned int i = 0; i < length; i++)
		{
			stack = mQueue.front();
			mQueue.pop();

			unsigned int stacklength;
			stacklength = stack->size();

			for (unsigned int k = 0; k < stacklength; k++)
			{
				temp = stack->top();
				stack->pop();

				// mMax, mMin update
				if (min > temp)
					min = temp;

				stacktemp.push(temp);
			}

			// change order of data LIFO -> LIFO 
			for (unsigned int i = 0; i < stacklength; i++)
			{
				temp = stacktemp.top();
				stacktemp.pop();

				stack->push(temp);
			}

			queue.push(stack);
		}

		mQueue.swap(queue);

		unsigned int queuelength = queue.size();
		for (unsigned int k = 0; k < queuelength; k++)
		{
			delete queue.front();
			queue.pop();
		}

		return min;
	};

	template <typename T>
	double QueueStack<T>::GetAverage(void)
	{
		if (mCount > 0)
		{
			double average;

			average = static_cast<double>(mSum) / mCount;

			return roundToPont(average, 3);
		}
		else
			return 0.0;
	};

	template <typename T>
	T QueueStack<T>::GetSum(void)
	{
		if (mCount > 0)
		{
			return static_cast<T>(mSum);		
		}
		else
			return static_cast<T>(0);
	};

	template <typename T>
	unsigned int QueueStack<T>::GetCount(void) const
	{
		return mCount;
	};

	template <typename T>
	unsigned int QueueStack<T>::GetStackCount(void) const
	{
		return mQueue.size();
	};

	template <typename T>
	double QueueStack<T>::roundToPont(double number, unsigned int point)
	{
		double rounded;

		rounded = round(number * pow(10, point)) / pow(10, point);

		return rounded;
	}
}