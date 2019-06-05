#pragma once
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

struct HumanData {
	string address;
	string phone;
	HumanData() {};
	HumanData(string addr, string ph) {
		address = addr;
		phone = ph;
	}
};
istream& operator >>(istream& in, HumanData& data) {
	getline(in, data.address);
	getline(in, data.phone);
	return in;
}
ostream& operator <<(ostream& out, const HumanData& data) {
	out << data.address << "  " << data.phone;
	return out;
}
