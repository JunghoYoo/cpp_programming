#pragma once
namespace assignment1
{
	class MyString
	{
	public:
		MyString(const char* s);
		MyString(const MyString& other);
		~MyString();

		unsigned int GetLength() const;
		const char* GetCString() const;
		void Append(const char* s);
		MyString operator+(const MyString& other) const;
		int IndexOf(const char* s);
		int LastIndexOf(const char* s);
		void Interleave(const char* s);
		bool RemoveAt(unsigned int i);
		void PadLeft(unsigned int totalLength);
		void PadLeft(unsigned int totalLength, const char c);
		void PadRight(unsigned int totalLength);
		void PadRight(unsigned int totalLength, const char c);
		void Reverse();
		bool operator==(const MyString& rhs) const;
		MyString& operator=(const MyString& rhs);
		void ToLower();
		void ToUpper();

	private:
		char* mString;
		unsigned int mLength;
		const char EOL = '\0';

		unsigned int getCharLength(const char*);
		bool isEqual(const char* comp1, const char* comp2, unsigned int length);
	};
}