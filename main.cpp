#include<iostream>
using namespace std;


bool formCheck(string in) {

	int count = 0;

	if (in[0] == '.' || in.length() - 1 == '.') return false; //не должно начинаться с точки

	for (int i = 0; i < in.length(); i++) { //нельзя две точки подряд
		if (in[i] == '.' && in[i - 1] == '.') {
			return false;
		}
	}


	for (int i = 0; i < in.length(); i++) { //Смотрим, чтобы в вводных было 3 точки
		if (in[i] == '.') {
			count++;

		}
		else if (in[i] >= '0' && in[i] <= '9') {
			continue;
		}
		else {
			return false;
		}
	
	}if (count != 3) return false;

	return true;
}

int intconvert(string in) {

	int r = 1, out = 0;

	for (int i = in.length() - 1; i >= 0; i--) {
		out += (in[i] - '0') * r;
		r *= 10;
	}
	return out;
}

bool numCheck(string in) {

	if (in.length() > 3) return false;
	if (in[0] == '0' && in.length() > 1) return false;

	if (intconvert(in) > 255) return false; 
}

string ipCheck(string in) {

	string y = "Yes", n = "No";
	string num = "";

	if (!formCheck(in)) return n; //смотрим общую форму записи


	for (int i = 0; i < in.length(); i++) { //разделяем адрес на числа и проверяем на корректность каждое число
		if (in[i] != '.') {
			num += in[i];
		}
		else {
			if (!numCheck(num)) return n;
			num = "";
		}

		if (i == in.length() - 1) {
			if (!numCheck(num)) return n;
		}
	}

	
	return y;
	

}


void main() {
	setlocale(LC_ALL, "rus");

	string ip;

	while (true) {
		cout << "Input ip: ";
		cin >> ip;


		cout << ipCheck(ip) << endl;

		ip = "";
	}
}