#pragma once
#undef UNICODE
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<windows.h>
#include"humanData.h"
#include<map>

using namespace std;

struct Human {
	string name;
	HumanData data;
	Human() {};
	Human(string aname, string addr, string ph) : name(aname), data(addr, ph) {}
};
istream& operator >>(istream& in, Human& human) {
	getline(in, human.name);
	getline(in, human.data.address);
	getline(in, human.data.phone);
	return in;
}
ostream& operator <<(ostream& out, const Human& human) {
	out << human.name << "  " << human.data.address << "  " << human.data.phone;
	return out;
}
bool readHumans(const char* filename, vector<Human>& humans) {
	ifstream in(filename);
	if (!in.is_open())
		return false;
	Human human;
	in >> human;
	while (!in.fail()) {
		humans.push_back(human);
		in >> human;
	}
	in.close();
	return true;
}
bool readHumans(const char* filename, map<string, HumanData>& humans) {
	ifstream in(filename);
	if (!in.is_open())
		return false;
	string name;
	HumanData data;
	getline(in, name) >> data;
	while (!in.fail()) {
		humans[name] = data;
		getline(in, name) >> data;
	}
	in.close();
	return true;
}
class FindException {};
Human findByName(const vector<Human>& humans, const string& name) {
	setlocale(LC_ALL, "Russian");
	cout << "Ведется поиск: " << name << endl;
	for (vector<Human>::const_iterator it = humans.begin(); it != humans.end(); it++) {
		if (it->name == name)
			return (*it);
	}
	throw FindException();
}
Human findByNameBin(const vector<Human>& humans, const string& name, int min, int max) {
	int index = (min + max) / 2;
	if (min > max)
		throw FindException();
	else if (humans[index].name == name)
		return humans[index];
	else if (humans[index].name > name)
		return findByNameBin(humans, name, min, index - 1);
	else if (humans[index].name < name)
		return findByNameBin(humans, name, index + 1, max);
}
Human findByNameBin(const vector<Human>& humans, const string& name) {
	cout << "Ведется поиск: " << name << endl;
	return findByNameBin(humans, name, 0, (int)humans.size() - 1);
}
void findByNameMap(map<string, HumanData>& humans, string name) {
	map<string, HumanData>::const_iterator it = humans.find(name);
	if (it != humans.end()) {
		cout << "Человек найден" << endl;
		cout << it->first << ' ' << it->second << endl;
	}
	else
		cout << "Человек не найден: " << name << endl;
}
string convert(string str) {
	char* buf = new char[strlen(str.c_str()) + 1];
	OemToChar(str.c_str(), buf);
	string res(buf);
	delete[] buf;
	return res;
}
template <class T> class SortableVector :public vector<T> {};
