/*
	��������� �� ������������ ������������� �������� � ��������
	�����: ����� ����� ����������, ������ 2309. ������ 4.1.1
	����: ������: 20.10.2022 ���������: 01.01.2022
*/

#include <iostream>
#include <fstream>

int main() {
	std::setlocale(LC_ALL, "RUS");
	std::ifstream infile("in.txt");
	std::ofstream outfile("out.txt");
	outfile << "��������� ������ ������.\n";
	if (infile.is_open()) {
		const int size = 20;
		int A[size]{};
		int tmp = 0, est_count = 0, arr_count = 0, real_count = 0;
		infile >> est_count;
		outfile << "������� ��������� ���-�� ��������� ������� - " << est_count << ".\n������ �������� ����� ������:\n";
		while (!infile.eof()) {
			infile >> tmp;
			outfile << tmp << ' ';
			++real_count;
		}
		outfile << '\n';
		if (est_count <= 0) {
			if (real_count > 0) outfile << "�������� ������������ �������� ���������� ���-�� ��������� �������, ����� ������ �� ������.\n� ������ ����� ������� ������ ������� ������.\n";
			else {
				outfile << "�������� ������������ �������� ���������� ���-�� ��������� �������, ����� ������ ������.\n� ������ ����� ������� ����.\n";
				arr_count = 1;
			}
			est_count = 1;
		}
		else if (est_count > 0 && est_count <= size) {
			if (real_count < est_count) {
				if (real_count == 0) {
					outfile << "����� ������ ������, � ������ ����� �������� " << est_count << " �����.\n";
					arr_count = est_count;
				}
				else outfile << "����� ������ ������ ����������.\n���������: " << est_count << "\n�������: " << real_count << "\n������������� ������ � ������� ����� ��������� ������.\n";
			}
			else if (real_count == est_count) outfile << "����� ������ ������������� ���������� �������.\n������������ ������ � ������.\n";
			else outfile << "����� ������ ������ ����������.\n���������: " << est_count << "\n�������: " << real_count << "\n� ������ ����� �������� ������ " << est_count << " ��������� ������.\n";
		}
		else {
			if (real_count == 0) {
				outfile << "��������� ���-�� ��������� ������� ��������� ����������� ���������� - " << size << "; ����� ������ ������.\n� ������ ����� �������� " << size << " �����.\n";
				arr_count = size;
			}
			else if (real_count <= size) outfile << "��������� ���-�� ��������� ������� ��������� ����������� ���������� - " << size << "; ����� ������ �� ������ �����������.\n� ������ ����� �������� ��� �������� ������, ������������� ������ � ������� ����� ��������� ������\n";
			else outfile << "��������� ���-�� ��������� ������� ��������� ����������� ���������� - " << size << "; ����� ������ ������ �����������.\n� ������ ����� �������� ������ " << size << " ��������� ������.\n";
			est_count = size;
		}
		infile.close();
		infile.clear();
		infile.open("in.txt");
		infile >> tmp;
		while (!infile.eof()) {
			if (arr_count >= est_count) break;
			infile >> A[arr_count];
			++arr_count;
		}
		if (arr_count < est_count) arr_count = est_count;
		outfile << "������ �� ���������:\n";
		for (int i = 0; i < arr_count; ++i) outfile << A[i] << ' ';
		outfile << '\n';
		int neg_count = 0;
		for (int i = 0; i < arr_count; ++i) if (A[i] < 0) ++neg_count;
		int left_index = 0, tmp_count = 0, right_index = 0;
		for (int i = 0; i < arr_count; ++i) {
			if (A[i] < 0) ++tmp_count;
			if (tmp_count == ((neg_count / 2) + 1)) {
				right_index = i;
				break;
			}
		}
		int swaps = 0;
		while (swaps < (neg_count / 2)) {
			if (A[left_index] >= 0) {
				do ++left_index;
				while (A[left_index] >= 0);
			}
			if (A[left_index] < 0 && A[right_index] < 0) {
				tmp = A[left_index];
				A[left_index] = A[right_index];
				A[right_index] = tmp;
				++swaps;
			}
			++left_index;
			do ++right_index;
			while (A[right_index] >= 0);
		}
		outfile << "�������� ������:\n";
		for (int i = 0; i < arr_count; ++i) outfile << A[i] << ' ';
		outfile << '\n';
	}
	else outfile << "������� ���� �� ������.\n";
	outfile << "��������� ��������� ������.";
	infile.close();
	outfile.close();
	return 0;
}