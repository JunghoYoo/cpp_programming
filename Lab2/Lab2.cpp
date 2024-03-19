#include "Lab2.h"

namespace lab2
{
	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		int number;

		out << "         oct        dec      hex" << std::endl;
		out << "------------ ---------- --------" << std::endl;

		// 끝까지 반복한다
		while (in.eof() == false)
		{
			// 정수 하나를 읽어온다.
			// 정상인 경우 다음 정수로 이동한다.
			in >> number;

			// 잘못된 경우 1 문자 이동한다.
			if (in.fail())
			{
				in.clear();
				in.ignore(1);

				continue;
			}

			// 8진수
			out.setf(std::ios::oct, std::ios::basefield);
			out.width(12);
			out << number;
			
			// 10진수
			out.setf(std::ios::dec, std::ios::basefield);
			out.width(11);
			out << number;

			// 16진수
			out.setf(std::ios::hex, std::ios::basefield);
			out.setf(std::ios::uppercase);
			out.width(9);
			out << number;
			
			out << std::endl;
		}
	}

	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{
		float number;
		float maxnumber = -FLT_MAX;

		// 끝까지 반복한다
		while (in.eof() == false)
		{
			// 정수 하나를 읽어온다.
			// 정상인 경우 다음 정수로 이동한다.
			in >> number;

			// 잘못된 경우 1 문자 이동한다.
			if (in.fail())
			{
				in.clear();
				in.ignore(1);

				continue;
			}
			
			// 최대값 비교
			if (number > maxnumber)
				maxnumber = number;

			out << "     ";
			out.width(15);
			out.precision(3);
			out.setf(std::ios::fixed, std::ios::floatfield); // floatfield set to fixed
			out.setf(std::ios::internal, std::ios::adjustfield);
			out.setf(std::ios::showpos);

			out << number;
			out << std::endl;
		}

		out << "max: ";
		out.width(15);
		out.precision(3);
		out.setf(std::ios::fixed, std::ios::floatfield); // floatfield set to fixed
		out.setf(std::ios::internal, std::ios::adjustfield);
		out.setf(std::ios::showpos);

		out << maxnumber;
		out << std::endl;
	}
}