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
	if (readHumans("in.txt", vec) == 0) {
		cout << "Не получается окрыть входной файл";
	}
	string namefind, converted;
	cout << "Введите фамилию для поиска:" << endl;
	cin >> namefind;
	converted = convert(namefind);
	cout << findByName(vec, converted) << endl;
	system("pause");
	return 0;
}


