/*
	��������� �� ������������ ������������� �������� � ��������
	�����: ����� ����� ����������, ������ 2309. ������ 4.2.1
	����: ������: 20.10.2022 ���������: 01.11.2022
*/

#include <iostream>
#include <fstream>

int main() {
	std::setlocale(LC_ALL, "RUS");
	std::ifstream infile("in.txt");
	std::ofstream outfile("out.txt");
	outfile << "��������� ������ ������.\n";
	if (infile.is_open()) {
		outfile << "������ �������� ����� ������:\n";
		int tmp = 0, tmp_tmp = 0, real_count = 0;
		while (!infile.eof()) {
			infile >> tmp_tmp;
			if (tmp || tmp_tmp != tmp || real_count) {
				outfile << tmp_tmp << ' ';
				++real_count;
			}
			tmp_tmp = tmp;
		}
		outfile << '\n';
		if (!real_count) {
			outfile << "����� ������ ������.\n� ������ ����� ������� ���� ����.\n";
			real_count = 1;
		}
		infile.close();
		infile.clear();
		infile.open("in.txt");
		int* p;
		p = new int[real_count];
		tmp = 0, tmp_tmp = 0;
		while (!infile.eof()) {
			infile >> tmp_tmp;
			if (tmp || tmp_tmp != tmp) {
				*(p + tmp) = tmp_tmp;
				++tmp;
			}
		}
		if (!tmp) *(p + tmp) = 0;
		outfile << "������ �� ���������:\n";
		for (int i = 0; i < real_count; ++i) outfile << *(p + i) << ' ';
		outfile << '\n';
		int neg_count = 0; tmp_tmp = 0;
		for (int i = 0; i < real_count; ++i) if (*(p + i) < 0) ++neg_count;
		int left_index = 0, right_index = 0;
		for (int i = 0; i < real_count; ++i) {
			if (*(p + i) < 0) ++tmp_tmp;
			if (tmp_tmp == ((neg_count / 2) + 1)) {
				right_index = i;
				break;
			}
		}
		int swaps = 0;
		while (swaps < (neg_count / 2)) {
			if (*(p + left_index) >= 0) {
				do ++left_index;
				while (*(p + left_index) >= 0);
			}
			if (*(p + left_index) < 0 && *(p + right_index) < 0) {
				tmp = *(p + left_index);
				*(p + left_index) = *(p + right_index);
				*(p + right_index) = tmp;
				++swaps;
			}
			++left_index;
			do ++right_index;
			while (*(p + right_index) >= 0);
		}
		outfile << "�������� ������:\n";
		for (int i = 0; i < real_count; ++i) outfile << *(p + i) << ' ';
		outfile << '\n';
		delete[]p;
	}
	else outfile << "������� ���� �� ������.\n";
	outfile << "��������� ��������� ������.";
	infile.close();
	outfile.close();
	return 0;
}