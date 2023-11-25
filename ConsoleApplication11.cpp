#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

void count__words(string line) {
	int numberOfWords = 0;
	char const z = ' ';

	bool isOnlySpaces = true;
	for (int j = 0; j < line.size(); j++) { // если в строке есть хоть один элемент отличный от пробела, то выходим из цикла проверка
		if (line[j] != z) { 
			isOnlySpaces = false;
			break;
		}
	}
	if (isOnlySpaces == true) {
		cout << "нет слов в строке" << endl; // если в строке только пробелы, то заканчиваем программу
		exit(0);
	}

	if (line[0] != z) {
		numberOfWords++; // является ли первый элемент символом отличным от пробела
	}

	for (int i = 0; i < line.size(); i++) {
		if (line[i] == z && line[i + 1] != z) { // если символ равен пробелу и следующий символ не равен пробелу, то прибавляем к сумме 1
			numberOfWords++;					// надо для проверки, что пробел разделяет два символа
		}										// если после пробела идет еще один пробел, то мы пропускаем этот элемент и идем дальше
	}

	if (line.back() == z) {
		cout << numberOfWords - 1<< endl; // если последний элемент строки - пробел, то мы вычитаем из суммы один, чтобы пробел не считался за символ
		exit(0);						  // выводим сумму и заканчиваем программу
	}

	cout << numberOfWords << endl; // выводим сумму символов в строке
}

int main() {
	setlocale(LC_ALL, "Russian");
	string line;
	getline(cin, line); //считывем введенные данные и присваем их line
	count__words(line);
}