#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	ifstream input("File.txt");
	string str, sym;
	char l_sym, r_sym;
	getline(input, str);
	getline(input, sym);
	int balance =0;
	bool bal = true;
	for (int i = 0; i < sym.size(); i +=2) {
		l_sym = sym.at(i);
		r_sym = sym.at(i + 1);

		if (l_sym == r_sym) {
			for (int j = 0; j < str.size(); j++) {
				if (l_sym == str.at(j)) balance++;
				balance = balance % 2;
			}
		}

		else {
			for (int j = 0; j < str.size(); j++) {
				if (l_sym == str.at(j)) balance++;
				if (r_sym == str.at(j)) balance--;
				if (balance < 0) break;
			}
		}

		if (balance != 0) {
			bal = false;
			break;
		}

	}
	ofstream output("out.txt");
	if (bal) output << "Скобки збалансированые";
	else output << "Скобки не збалансированые";
	system("pause");
	return 0;
}
