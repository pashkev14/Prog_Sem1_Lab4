/*
	Программа по перестановке отрицательных значений в массивах
	Автор: Савин Павел Алексеевич, группа 2309. Версия 4.1.1
	Даты: Начало: 20.10.2022 Окончание: 01.01.2022
*/

#include <iostream>
#include <fstream>

int main() {
	std::setlocale(LC_ALL, "RUS");
	std::ifstream infile("in.txt");
	std::ofstream outfile("out.txt");
	outfile << "Программа начала работу.\n";
	if (infile.is_open()) {
		const int size = 20;
		int A[size]{};
		int tmp = 0, est_count = 0, arr_count = 0, real_count = 0;
		infile >> est_count;
		outfile << "Считано ожидаемое кол-во элементов массива - " << est_count << ".\nСчитан исходный набор данных:\n";
		while (!infile.eof()) {
			infile >> tmp;
			outfile << tmp << ' ';
			++real_count;
		}
		outfile << '\n';
		if (est_count <= 0) {
			if (real_count > 0) outfile << "Получено недопустимое значение ожидаемого кол-ва элементов массива, набор данных не пустой.\nВ массив будет записан первый элемент набора.\n";
			else {
				outfile << "Получено недопустимое значение ожидаемого кол-ва элементов массива, набор данных пустой.\nВ массив будет записан ноль.\n";
				arr_count = 1;
			}
			est_count = 1;
		}
		else if (est_count > 0 && est_count <= size) {
			if (real_count < est_count) {
				if (real_count == 0) {
					outfile << "Набор данных пустой, в массив будет записано " << est_count << " нулей.\n";
					arr_count = est_count;
				}
				else outfile << "Набор данных меньше ожидаемого.\nОжидалось: " << est_count << "\nСчитано: " << real_count << "\nНезаполненные ячейки в массиве будут заполнены нулями.\n";
			}
			else if (real_count == est_count) outfile << "Набор данных соответствует ожидаемому размеру.\nПроизводится запись в массив.\n";
			else outfile << "Набор данных больше ожидаемого.\nОжидалось: " << est_count << "\nСчитано: " << real_count << "\nВ массив будут записаны первые " << est_count << " элементов набора.\n";
		}
		else {
			if (real_count == 0) {
				outfile << "Ожидаемое кол-во элементов массива превышает максимально допустимое - " << size << "; набор данных пустой.\nВ массив будут записаны " << size << " нулей.\n";
				arr_count = size;
			}
			else if (real_count <= size) outfile << "Ожидаемое кол-во элементов массива превышает максимально допустимое - " << size << "; набор данных не больше допустимого.\nВ массив будут записаны все элементы набора, незаполненные ячейки в массиве будут заполнены нулями\n";
			else outfile << "Ожидаемое кол-во элементов массива превышает максимально допустимое - " << size << "; набор данных больше допустимого.\nВ массив будут записаны первые " << size << " элементов набора.\n";
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
		outfile << "Массив на обработку:\n";
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
		outfile << "Итоговый массив:\n";
		for (int i = 0; i < arr_count; ++i) outfile << A[i] << ' ';
		outfile << '\n';
	}
	else outfile << "Входной файл не найден.\n";
	outfile << "Программа завершила работу.";
	infile.close();
	outfile.close();
	return 0;
}