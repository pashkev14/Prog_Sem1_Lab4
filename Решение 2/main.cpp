/*
	Программа по перестановке отрицательных значений в массивах
	Автор: Савин Павел Алексеевич, группа 2309. Версия 4.2.1
	Даты: Начало: 20.10.2022 Окончание: 01.11.2022
*/

#include <iostream>
#include <fstream>

int main() {
	std::setlocale(LC_ALL, "RUS");
	std::ifstream infile("in.txt");
	std::ofstream outfile("out.txt");
	outfile << "Программа начала работу.\n";
	if (infile.is_open()) {
		outfile << "Считан исходный набор данных:\n";
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
			outfile << "Набор данных пустой.\nВ массив будет записан один ноль.\n";
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
		outfile << "Массив на обработку:\n";
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
		outfile << "Итоговый массив:\n";
		for (int i = 0; i < real_count; ++i) outfile << *(p + i) << ' ';
		outfile << '\n';
		delete[]p;
	}
	else outfile << "Входной файл не найден.\n";
	outfile << "Программа завершила работу.";
	infile.close();
	outfile.close();
	return 0;
}