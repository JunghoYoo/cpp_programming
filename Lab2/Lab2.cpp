#include "Lab2.h"

namespace lab2
{
	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		int number;

		out << "         oct        dec      hex" << std::endl;
		out << "------------ ---------- --------" << std::endl;

		// ������ �ݺ��Ѵ�
		while (in.eof() == false)
		{
			// ���� �ϳ��� �о�´�.
			// ������ ��� ���� ������ �̵��Ѵ�.
			in >> number;

			// �߸��� ��� 1 ���� �̵��Ѵ�.
			if (in.fail())
			{
				in.clear();
				in.ignore(1);

				continue;
			}

			// 8����
			out.setf(std::ios::oct, std::ios::basefield);
			out.width(12);
			out << number;
			
			// 10����
			out.setf(std::ios::dec, std::ios::basefield);
			out.width(11);
			out << number;

			// 16����
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

		// ������ �ݺ��Ѵ�
		while (in.eof() == false)
		{
			// ���� �ϳ��� �о�´�.
			// ������ ��� ���� ������ �̵��Ѵ�.
			in >> number;

			// �߸��� ��� 1 ���� �̵��Ѵ�.
			if (in.fail())
			{
				in.clear();
				in.ignore(1);

				continue;
			}
			
			// �ִ밪 ��
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