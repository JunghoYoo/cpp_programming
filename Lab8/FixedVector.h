#pragma once

namespace lab8
{
	template <typename T, size_t N>
	class FixedVector
	{
	public:
		FixedVector();
		~FixedVector();
		FixedVector(const FixedVector& rhs);

		bool Add(const T& data);
		bool Remove(const T& data);

		const T& Get(const unsigned int index) const;
		T& operator[](const unsigned int index) const;
		int GetIndex(const T& data) const;
		size_t GetSize(void) const;
		size_t GetCapacity(void) const;
		FixedVector& operator=(const FixedVector& rhs) const;

	private:

		T mData[N];
		size_t mSize;
	};

	template <typename T, size_t N>	FixedVector<T, N>::FixedVector() : mSize(0)
	{
	}

	template <typename T, size_t N>	FixedVector<T, N>::~FixedVector()
	{
	}

	template <typename T, size_t N>	FixedVector<T, N>::FixedVector(const FixedVector& rhs) : mSize(rhs.mSize)
	{
		if (rhs.mSize > 0)
		{
			for (unsigned int i = 0; i < rhs.mSize; i++)
			{
				mData[i] = rhs.mData[i];
			}
		}
	}

	template <typename T, size_t N>
	bool FixedVector<T, N>::Add(const T& data)
	{
		if (mSize < N)
		{
			mData[mSize] = data;
			mSize++;

			return true;
		}
		else
		{
			return false;
		}
	}

	template <typename T, size_t N>
	bool FixedVector<T, N>::Remove(const T& data)
	{
		// Search data
		unsigned int index;

		index = 0;

		while (index < mSize)
		{
			if (mData[index] == data)
			{
				break;
			}

			index++;
		}

		if (index < mSize) // remove
		{
			mSize--;

			for (unsigned int i = index; i < mSize; i++)
			{
				mData[i] = mData[i + 1];
			}

			return true;
		}
		else // not found
		{
			return false;
		}
	}

	template <typename T, size_t N>
	const T& FixedVector<T, N>::Get(const unsigned int index) const
	{
		return mData[index];
	}

	template <typename T, size_t N>
	T& FixedVector<T, N>::operator[](const unsigned int index) const
	{
		return (T&)mData[index];
	}

	template <typename T, size_t N>
	int FixedVector<T, N>::GetIndex(const T& data) const
	{
		// Search data
		unsigned int index;

		index = 0;

		while (index < mSize)
		{
			if ((mData[index]) == data)
			{
				break;
			}

			index++;
		}

		if (index < mSize) // found
		{
			return static_cast<int>(index);
		}
		else // not found
		{
			return -1;
		}
	}

	template <typename T, size_t N>
	size_t FixedVector<T, N>::GetSize(void) const
	{
		return mSize;
	}

	template <typename T, size_t N>
	size_t FixedVector<T, N>::GetCapacity(void) const
	{
		return N;
	}

	template <typename T, size_t N>
	FixedVector<T, N>& FixedVector<T, N>::operator=(const FixedVector& rhs) const
	{
		if (this != &rhs)
		{
			mSize = rhs.mSize;

			if (rhs.mSize > 0)
			{
				for (unsigned int i = 0; i < rhs.mSize; i++)
				{
					mData[i] = rhs.mData[i];
				}
			}
		}
		else
		{
			return *this;
		}
	}
}