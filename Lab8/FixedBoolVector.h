#pragma once

#define ROUNDUP_AFTER_DIVIDE32(X) ((X / 32) + 1) 

namespace lab8
{
	template <size_t N>
	class FixedVector<bool, N>
	{
	public:
		FixedVector();
		~FixedVector();
		FixedVector(const FixedVector& rhs);

		bool Add(bool data);
		bool Remove(const bool data);

		bool Get(const unsigned int index) const;
		bool operator[](const unsigned int index) const;
		int GetIndex(const bool data) const;
		size_t GetSize(void) const;
		size_t GetCapacity(void) const;
		FixedVector& operator=(const FixedVector& rhs) const;

	private:
		bool getBitData(unsigned int data, unsigned int bitpos);
		unsigned int getCapacity32(void);
		unsigned int getSize32(void);

		unsigned int mData[ROUNDUP_AFTER_DIVIDE32(N)];
		size_t mSize;
		size_t mCapacity;
	};

	template <size_t N>	FixedVector<bool, N>::FixedVector() : mSize(0), mCapacity(N)
	{
	}

	template <size_t N>	FixedVector<bool, N>::~FixedVector()
	{
	}

	template <size_t N>	FixedVector<bool, N>::FixedVector(const FixedVector<bool, N>& rhs) : mSize(rhs.mSize), mCapacity(rhs.mCapacity)
	{
		if (rhs.mSize > 0)
		{
			for (unsigned int i = 0; i < rhs.mSize32; i++)
			{
				mData[i] = rhs.mData[i];
			}
		}
	}

	template <size_t N>
	bool FixedVector<bool, N>::Add(bool bTargetdata)
	{
		unsigned int size32;
		unsigned int data32;

		if (mSize < mCapacity)
		{
			if ((mSize % 32 == 0)
				&& (mSize != 0)) // go to next 32bit
			{
				size32 = getSize32();

				if (bTargetdata == true)
				{
					data32 = 1;
				}
				else
				{
					data32 = 0;
				}

				// insert
				mData[size32] = data32;
			}
			else // within current 32bit
			{
				size32 = getSize32();

				// current 32bit
				data32 = mData[size32];

				// bit position to be written in 32bit wide
				unsigned int bitpos32 = mSize % 32;

				// mask previous data
				unsigned int maskprev = 0;
				for (unsigned int i = 0; i < bitpos32; i++)
				{
					maskprev += (1 << i);
				}

				unsigned int targetdata;
				if (bTargetdata == true)
					targetdata = 1 << bitpos32;
				else
					targetdata = 0;

				// combine
				data32 = (data32 & maskprev) | targetdata;

				// insert
				mData[size32] = data32;
			}

			mSize++;

			return true;
		}
		else
		{
			return false;
		}
	}

	template <size_t N>
	bool FixedVector<bool, N>::Remove(const bool bTargetdata)
	{
		// Search data
		unsigned int index;
		unsigned int index32;
		unsigned int bitpos32;
		unsigned int masknew;
		unsigned int data32;
		bool bSrcdata;

		index = 0;

		while (index < mSize)
		{
			// word position to be written
			index32 = index / 32;
			// bit position to be written in 32bit wide
			bitpos32 = index % 32;
			masknew = 1 << bitpos32;

			// read by bit mask & shift down
			data32 = (mData[index32] & masknew);

			if (data32 == 0)
				bSrcdata = false;
			else
				bSrcdata = true;

			// compare
			if (bSrcdata == bTargetdata)
			{
				break;
			}

			index++;
		}

		if (index < mSize) // remove
		{
			unsigned int lastindex;
			lastindex = mSize - 1;

			unsigned int targetindex32;
			unsigned int targetbitpos32;
			unsigned int sourceindex32;
			unsigned int sourcebitpos32;

			bool bSourcebit;

			unsigned int maskprev;
			unsigned int targetdata;

			for (unsigned int i = index; i < lastindex; i++)
			{
				// target (left)		
				// word position to be written
				targetindex32 = i / 32;
				// bit position to be written in 32bit wide
				targetbitpos32 = i % 32;

				// source (right)
				// word position to be written
				sourceindex32 = (i + 1) / 32;
				// bit position to be written in 32bit wide
				sourcebitpos32 = (i + 1) % 32;
				// source (right)
				bSourcebit = getBitData(mData[sourceindex32], sourcebitpos32);

				if (bSourcebit == true)
					targetdata = 1 << targetbitpos32;
				else
					targetdata = 0;

				// mask previous data (drop only target bit - diffrent from Remove())
				maskprev = 0xffffffff - (1 << targetbitpos32);

				// combine
				mData[targetindex32] = (mData[targetindex32] & maskprev) | targetdata;
			}

			mSize--;

			return true;
		}
		else // not found
		{
			return false;
		}
	}

	template <size_t N>
	bool FixedVector<bool, N>::Get(const unsigned int index) const
	{
		unsigned int index32;
		unsigned int bitpos32;
		unsigned int masknew;
		unsigned int data32;
		bool bSrcdata;

		// word position to be written
		index32 = index / 32;
		// bit position to be written in 32bit wide
		bitpos32 = index % 32;
		masknew = 1 << bitpos32;

		// read by bit mask & shift down
		data32 = (mData[index32] & masknew);

		if (data32 == 0)
			bSrcdata = false;
		else
			bSrcdata = true;

		return bSrcdata;
	}

	template <size_t N>
	bool FixedVector<bool, N>::operator[](const unsigned int index) const
	{
		unsigned int index32;
		unsigned int bitpos32;
		unsigned int masknew;
		unsigned int data32;
		bool bSrcdata;

		// word position to be written
		index32 = index / 32;
		// bit position to be written in 32bit wide
		bitpos32 = index % 32;
		masknew = 1 << bitpos32;

		// read by bit mask & shift down
		data32 = (mData[index32] & masknew);

		if (data32 == 0)
			bSrcdata = false;
		else
			bSrcdata = true;

		return bSrcdata;
	}
	template <size_t N>
	int FixedVector<bool, N>::GetIndex(const bool bTargetdata) const
	{
		// Search data
		unsigned int index;
		unsigned int index32;
		unsigned int bitpos32;
		unsigned int masknew;
		unsigned int data32;
		bool bSrcdata;

		index = 0;

		while (index < mSize)
		{
			// word position to be written
			index32 = index / 32;
			// bit position to be written in 32bit wide
			bitpos32 = index % 32;
			masknew = 1 << bitpos32;

			// read by bit mask & shift down
			data32 = (mData[index32] & masknew);

			if (data32 == 0)
				bSrcdata = false;
			else
				bSrcdata = true;

			// compare
			if (bSrcdata == bTargetdata)
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

	template <size_t N>
	size_t FixedVector<bool, N>::GetSize(void) const
	{
		return mSize;
	}

	template <size_t N>
	size_t FixedVector<bool, N>::GetCapacity(void) const
	{
		return mCapacity;
	}
	template <size_t N>
	FixedVector<bool, N>& FixedVector<bool, N>::operator=(const FixedVector& rhs) const
	{
		if (this != &rhs)
		{
			// delete existing -> array is static allocated, just reset size
	
			// add new
			mSize = rhs.mSize;
			mCapacity = rhs.mCapacity;

			if (rhs.mSize > 0)
			{
				for (unsigned int i = 0; i < rhs.mSize32; i++)
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
	template <size_t N>
	inline bool FixedVector<bool, N>::getBitData(unsigned int data, unsigned int bitpos)
	{
		unsigned int readdata;
		bool bReadbit;
		unsigned int mask;

		mask = 1 << bitpos;
		readdata = data & mask;

		if (readdata == 0)
			bReadbit = false;
		else
			bReadbit = true;

		return bReadbit;
	}
	template <size_t N>
	unsigned int FixedVector<bool, N>::getCapacity32(void)
	{
		unsigned int capacity32;
		// always round up
		capacity32 = ROUNDUP_AFTER_DIVIDE32(N);

		return capacity32;
	}
	template <size_t N>
	unsigned int FixedVector<bool, N>::getSize32(void)
	{
		unsigned int size32;
		
		size32 = (mSize / 32);
		
		// no round up

		return size32;
	}
}
