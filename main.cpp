#include<iostream>
#include "Human.h"
#include <ctime>
#include<vector>
#include <stdlib.h>
#include "Human.h"

using namespace std;

int main(void) {
	setlocale(LC_ALL, "Russian");
	SortableVector<Human> vec;
	map<string, HumanData> map;
	if (readHumans("in.txt", vec) == 0) {
		cout << "Не получается окрыть входной файл" << endl;
		return -1;
	}
	if (readHumans("in.txt", map) == 0) {
		cout << "Не получается окрыть входной файл" << endl;
		return -1;
	}
	string namefind, converted;
	while (true){
		cout << "Введите фамилию для поиска / Для выхода введите слово выход" << endl;
		cin >> namefind;
		cout << endl;
		converted = convert(namefind);
		if (converted == "выход")
			break;
		cout << "Прямой поиск: " << findByName(vec, converted) << endl << endl;
		cout << "Бинарный поиск: " << findByNameBin(vec, converted) << endl << endl;
		cout << "Поиск мапом: ";
		findByNameMap(map, converted);
	}
	system("pause");
	return 0;
}
