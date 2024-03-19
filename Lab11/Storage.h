#pragma once

#include <memory>

namespace lab11
{
	template<typename T>
	class Storage final
	{
	public:
		Storage() = delete;

		Storage(unsigned int length);
		Storage(unsigned int length, const T& initialValue);
		Storage(const Storage& other);

		Storage& operator=(const Storage& other);

		// Move
		Storage(Storage&& other);
		Storage& operator=(Storage&& other);

		bool Update(unsigned int index, const T& data);
		const std::unique_ptr<T[]>& GetData() const;
		unsigned int GetSize() const;

	private:
		std::unique_ptr<T[]> mData;
		unsigned int mLength;
	};

	template<typename T> Storage<T>::Storage(unsigned int length) 
		: mLength(length)
	{
		if (length > 0)
			mData = std::make_unique<T[]>(mLength);
		else
			mData = nullptr;
	}
	template<typename T> Storage<T>::Storage(unsigned int length, const T& initialValue)
		: mLength(length)
	{
		if (length > 0)
			mData = std::make_unique<T[]>(mLength);
		else
			mData = nullptr;

		for (unsigned int i = 0; i < length; i++)
		{
			mData[i] = initialValue;
		}
	}
	template<typename T> Storage<T>::Storage(const Storage& other)
		: mLength(other.mLength)
	{
		if (mLength > 0)
			mData = std::make_unique<T[]>(mLength);
		else
			mData = nullptr;

		for (unsigned int i = 0; i < mLength; i++)
		{
			mData[i] = other.mData[i];
		}
	}
	template<typename T> Storage<T>& Storage<T>::operator=(const Storage<T>& rhs)
	{
		if (this != &rhs)
		{
			// delete existing
			mData.reset();

			mLength = rhs.mLength;

			if (mLength > 0)
				mData = std::make_unique<T[]>(mLength);
			else
				mData = nullptr;

			for (unsigned int i = 0; i < mLength; i++)
			{
				mData[i] = rhs.mData[i];
			}
		}

		return *this;
	}
	template<typename T> Storage<T>::Storage(Storage<T>&& other)
	{
		mData = move(other.mData);
		mLength = other.mLength;

		// delete other
		other.mData.reset();
		other.mLength = 0;
	}

	template<typename T>
	Storage<T>& Storage<T>::operator=(Storage<T>&& other)
	{
		if (this != &other)
		{
			// delete previous
			mData.reset(); 

			mData = move(other.mData);
			mLength = other.mLength;

			// delete other
			other.mData.reset();
			other.mLength = 0;
		}

		return *this;
	}

	template<typename T>
	bool Storage<T>::Update(unsigned int index, const T& data)
	{
		if (index < mLength)
		{
			mData[index] = data;
			return true;
		}
		else
		{
			return false;
		}
	}

	template<typename T>
	const std::unique_ptr<T[]>& Storage<T>::GetData() const
	{
		return std::move(mData);
	}

	template<typename T>
	unsigned int Storage<T>::GetSize() const
	{
		return mLength;
	}
}