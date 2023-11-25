#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

void count__words(string line) {
	int numberOfWords = 0;
	char const z = ' ';

	bool isOnlySpaces = true;
	for (int j = 0; j < line.size(); j++) {
		if (line[j] != z) { 
			isOnlySpaces = false;
			break;
		}
	}
	if (isOnlySpaces == true) {
		cout << "нет слов в строке" << endl;
		exit(0);
	}

	if (line[0] != z) {
		numberOfWords++;
	}

	for (int i = 0; i < line.size(); i++) {
		if (line[i] == z && line[i + 1] != z) {
			numberOfWords++;
		}
	}

	if (line.back() == z) {
		cout << numberOfWords - 1<< endl;
		exit(0);
	}

	cout << numberOfWords << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	string line;
	getline(cin, line);
	count__words(line);
}