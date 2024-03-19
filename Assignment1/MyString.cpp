#include "MyString.h"

namespace assignment1
{
	MyString::MyString(const char* s)
	{
		mLength = getCharLength(s);
		if (mLength > 0)
		{
			mString = new char[mLength + 1];

			for (unsigned int i = 0; i < mLength; i++)
			{
				mString[i] = s[i];
			}

			mString[mLength] = EOL;
		}
		else 
		{
			mString = 0;
		}
	}

	MyString::MyString(const MyString& other)
	{
		mLength = other.mLength;
		if (mLength > 0)
		{
			mString = new char[mLength + 1];

			for (unsigned int i = 0; i < mLength; i++)
			{ 
				mString[i] = other.mString[i];
			}

			mString[mLength] = EOL;
		}
		else 
		{
			mString = 0;
		}
	}

	MyString::~MyString()
	{
		if (mLength > 0)
		{
			delete[] mString;
		}
	}

	unsigned int MyString::GetLength() const
	{
		return mLength;
	}

	const char* MyString::GetCString() const
	{
		if (mLength > 0)
		{
			return mString;
		}
		else
		{
			return &EOL;
		}
	}

	void MyString::Append(const char* s)
	{
		char* newString;
		unsigned int newLength;

		// String To be appended
		newLength = getCharLength(s);

		if (newLength > 0)
		{
			newString = new char[mLength + newLength + 1]; // add prev newline

			// Copy Prev String & drop prev newline
			for (unsigned int i = 0; i < mLength; i++)
				newString[i] = mString[i];

			// Copy new String
			for (unsigned int i = mLength; i < mLength + newLength; i++)
				newString[i] = s[i - mLength];

			newString[mLength + newLength] = EOL;

			// delete prev String
			delete[] mString;

			// Update Appended String & Length
			mLength = mLength + newLength;
			mString = newString;
		}
	}

	MyString MyString::operator+(const MyString& other) const
	{
		MyString newMyString(*this);

		if (other.mLength > 0)
		{
			newMyString.Append(other.mString);
		}

		return newMyString;
	}

	int MyString::IndexOf(const char* s)
	{
		unsigned int k;
		unsigned int nSearchLengths;

		// String To search
		nSearchLengths = getCharLength(s);

		if ((mLength >= nSearchLengths) && (s != 0))
		{
			for (k = 0; k < (mLength - nSearchLengths + 1); k++)
			{
				if (isEqual(this->mString + k, s, nSearchLengths) == true)
					return k;
			}

			return -1;
		}
		else
		{
			return -1;
		}
	}

	int MyString::LastIndexOf(const char* s)
	{
		int k;
		unsigned int nSearchLengths;
		int nFoundIndex = -1;

		// String To search
		nSearchLengths = getCharLength(s);

		if ((mLength >= nSearchLengths) && (s != 0))
		{
			for (k = (mLength - nSearchLengths); k >= 0 ; k--)
			{
				if (isEqual(this->mString + k, s, nSearchLengths) == true)
					return k;
			}

			return -1;
		}
		else
		{
			return -1;
		}
	}

	void MyString::Interleave(const char* s)
	{
		char* newString;
		unsigned int newLength;
		unsigned prev1Index = 0;
		unsigned prev2Index = 0;

		// String To be appended
		newLength = getCharLength(s);

		if (newLength > 0)
		{
			newString = new char[mLength + newLength + 1]; // drop prev newline

			// Copy Prev String & drop prev newline
			unsigned int i;
			for (i = 0; i < mLength + newLength; i++)
			{
				if ((prev1Index < mLength) && (prev2Index < newLength))
				{
					if ((i % 2) == 0)
					{
						newString[i] = mString[prev1Index++];
					}
					else if ((i % 2) == 1)
					{
						newString[i] = s[prev2Index++];
					}
				}
				else if ((prev1Index < mLength) && (prev2Index >= newLength))
				{
					newString[i] = mString[prev1Index++];
				}
				else if ((prev1Index >= mLength) && (prev2Index < newLength))
				{
					newString[i] = s[prev2Index++];
				}
			}

			newString[mLength + newLength] = EOL;
			// delete prev String
			delete[] mString;

			// Update Appended String & Length
			mLength = mLength + newLength;
			mString = newString;
		}
	}

	bool MyString::RemoveAt(unsigned int index)
	{
		if (index < mLength) 
		{
			char* newString;
			newString = new char [ mLength - 1 ];

			unsigned int k = 0;

			for (unsigned int i = 0; i < mLength; i++)
			{
				if (i != index)
				{
					newString[k++] = mString[i];
				}
			}

			mLength--;

			delete [] mString;
			mString = newString;
			
			return true;
		}

		return false;
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
		PadLeft(totalLength, ' ');
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
		if (totalLength > mLength)
		{
			char* newString;
			unsigned int i;

			// String To be appended
			newString = new char[totalLength + 1]; // drop prev newline

			// Copy new String
			for (i = 0; i < totalLength - mLength; i++)
				newString[i] = c;

			// Copy prev String & drop prev newline
			for (i = totalLength - mLength; i < totalLength; i++)
				newString[i] = mString[i - (totalLength - mLength)];

			newString[totalLength] = EOL;

			// delete prev String
			delete[] mString;

			// Update Appended String & Length
			mLength = totalLength;
			mString = newString;
		}
	}

	void MyString::PadRight(unsigned int totalLength)
	{
		PadRight(totalLength, ' ');
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
		if (totalLength > mLength)
		{
			char* newString;
			unsigned int i;

			// String To be appended
			newString = new char[totalLength + 1];
			
			// Copy new String
			for (i = mLength; i < totalLength; i++)
				newString[i] = c;

			// Copy prev String & drop prev newline
			for (i = 0; i < mLength; i++)
				newString[i] = mString[i];

			newString[totalLength] = EOL;

			// delete prev String
			delete[] this->mString;

			// Update Appended String & Length
			mLength = totalLength;
			this->mString = newString;
		}
	}

	void MyString::Reverse()
	{
		if (mLength > 0)
		{
			char temp;
			unsigned int i;

			for (i = 0; i < (mLength / 2); i++)
			{
				temp = mString[i];
				mString[i] = mString[mLength - 1 - i];
				mString[mLength - 1 - i] = temp;
			}
		}
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		if (this->mLength == rhs.mLength)
		{
			unsigned int i = 0;

			while (i < mLength)
			{
				if (this->mString[i] != rhs.mString[i])
					return false;
				else
					i++;
			}

			return true;
		}

		return false;
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		delete[] mString;

		mLength = getCharLength(rhs.mString);
		if (mLength > 0)
		{
			mString = new char[mLength + 1];

			for (unsigned int i = 0; i < mLength; i++)
			{
				mString[i] = rhs.mString[i];
			}

			mString[mLength] = EOL;
		}
		else
		{
			mString = 0;
		}

		return *this;
	}

	void MyString::ToLower()
	{
		for (unsigned int i = 0; i < mLength; i++)
			if ((mString[i] >= 'A') && (mString[i] <= 'Z'))
				mString[i] = mString[i] - 'A' + 'a';
	}

	void MyString::ToUpper()
	{
		for (unsigned int i = 0; i < mLength; i++)
			if ((mString[i] >= 'a') && (mString[i] <= 'z'))
				mString[i] = mString[i] - 'a' + 'A';
	}

	unsigned int MyString::getCharLength(const char* s)
	{
		int nLength = 0;

		if (s != 0)
		{
			while (s[nLength] != EOL)
			{
				nLength++;
			}
		}

		return nLength;
	}

	bool MyString::isEqual(const char* comp1, const char* comp2, unsigned int length)
	{
		for (unsigned int k = 0; k < length; k++)
		{
			if (comp1[k] != comp2[k])
				return false;
		}

		return true;
	}

}