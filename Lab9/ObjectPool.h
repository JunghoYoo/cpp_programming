#pragma once
#include <vector>
#include <iterator>

namespace lab9
{

	template <class T>
	class ObjectPool
	{
		friend class Game;
	public:
		ObjectPool(size_t maxPoolSize);
		ObjectPool() = delete;
		ObjectPool(ObjectPool& rhs) = delete;
		virtual ~ObjectPool();

		T* Get(void);
		void Return(T* data);
		size_t GetFreeObjectCount(void) const;
		size_t GetMaxFreeObjectCount(void) const;
		ObjectPool& operator= (ObjectPool& rhs) = delete;

	private:
		size_t mMaxPoolSize;
		std::vector<T*> mQueue;

	};
	template <typename T> ObjectPool<T>::ObjectPool(size_t maxPoolSize) : mMaxPoolSize(maxPoolSize)
	{
	}
	template <typename T> ObjectPool<T>::~ObjectPool()
	{
		size_t count;
		count = mQueue.size();

		for (unsigned int i = 0; i < count; i++)
		{
			delete mQueue[i];
		}
	}
	template <typename T> 
	T* ObjectPool<T>::Get(void)
	{
		T* data;

		if (mQueue.size() > 0)
		{
			data = mQueue.back();
			mQueue.pop_back();
		}
		else
		{
			data = new T;
		}

		return data;
	}
	template <typename T>
	void ObjectPool<T>::Return(T* data)
	{
		if (mQueue.size() >= mMaxPoolSize)
		{
			// full queue
			delete data;
		}
		else
		{
			// insert front
			mQueue.insert(mQueue.begin(), data);
		}
	}
	template <typename T>
	size_t ObjectPool<T>::GetFreeObjectCount(void) const
	{
		size_t count;
		count = mQueue.size();

		return count;
	}
	template <typename T>
	size_t ObjectPool<T>::GetMaxFreeObjectCount(void) const
	{
		return mMaxPoolSize;
	}
}