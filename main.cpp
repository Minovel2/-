#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <regex>
using namespace std;
const int buttonsCount1 = 5;
const int buttonsCount2 = 2;
string getBigLine(int n) {
	string s = "\n";
	for (int i = 0; i < n; i++) {
		s += '-';
	}
	s += '\n';
	return s;
}
bool Engletters(const string& str) {
	return any_of(str.begin(), str.end(), [](char c) { return isalpha(c); });
}
bool Rusletters(const string& str) {
	regex regex("[а-яА-ЯёЁ]");
	return regex_search(str, regex);
}
string checkd(int counN) {
	string number;
	bool flag = 1;
	cout << "\nВведите данные: ";
	cin >> number;
	if (counN == 2) { //  1 или  2
		while (flag) {
			if (number[0] != '1' && number[0] != '2') {
				cout << "Вы не правильно ввели число!" << endl;
				cout << "Введите число: ";
				cin >> number;
				continue;
			}
			if (stoi(number) != 1 && stoi(number) != 2) {
				cout << "Вы не правильно ввели число!" << endl;
				cout << "Введите число: ";
				cin >> number;
			}
			else {
				flag = 0;
			}
		}
	}
	if (counN == 4) {   // 4 варианта сортировки
		while (flag) {
			if (number[0] != '1' && number[0] != '2' && number[0] != '3' && number[0] != '4' && number[0] != '5') {
				cout << "Вы не правильно ввели число!" << endl;
				cout << "Введите число: ";
				cin >> number;
				continue;
			}
			if (stoi(number) != 1 && stoi(number) != 2 && stoi(number) != 3 && stoi(number) != 4 && stoi(number) != 5) {
				cout << "Вы не правильно ввели число!" << endl;
				cout << "Введите число: ";
				cin >> number;
			}
			else {
				flag = 0;
			}
		}
	}
	if (counN == 0) {   //0 или 1
		while (flag) {
			if (number[0] != '1' && number[0] != '0') {
				cout << "Вы не правильно ввели число!" << endl;
				cout << "Введите число: ";
				cin >> number;
				continue;
			}
			if (stoi(number) != 1 && stoi(number) != 0) {
				cout << "Вы не правильно ввели число!" << endl;
				cout << "Введите число: ";
				cin >> number;
			}
			else {
				flag = 0;
			}
		}
	}
	if (counN == 1) {   //Проверка на буквы
		while (flag) {
			if (Engletters(number) || Rusletters(number)) {
				cout << "Вы ввели буквы!" << endl;
				cout << "Введите число: ";
				cin >> number;
				continue;
			}
			else {
				flag = 0;
			}
		}
	}
	if (counN == 6) {  //проверка стаж
		while (flag) {
			if (Engletters(number) || Rusletters(number)) {
				cout << "Число не из промежутка от [0] до [80]!" << endl;
				cout << "Введите число: ";
				cin >> number;
				continue;
			}
			if (stoi(number) < 0 || stoi(number) > 80) {
				cout << "Число не из промежутка от [0] до [80]!" << endl;
				cout << "Введите число: ";
				cin >> number;

			}
			else {
				flag = 0;
			}
		}
	}

	if (counN == 7) {  //проверка на должность
		int c = 0;
		string arrMonth[12] = { "Доцент", "Профессор", "Ассистент", "Старший_преподаватель", "Заведующий_кафедрой", "Преподаватель" };
		while (flag) {
			number[0] = toupper(number[0]);
			for (int i = 0; i < 12; i++) {
				if (number == arrMonth[i]) {
					c++;
				}
			}
			if (c < 1) {
				cout << "Не существующая должность " << endl;
				cout << "Введите заново: ";
				cin >> number;
			}
			else {
				flag = 0;
			}
		}
	}
	return number;
}
void showMenu1(int menu) {
	setlocale(LC_ALL, "rus");
	string* text = new string[buttonsCount1]{ "Cортировка ", "Добавление данных", "Удаление данных", "Просмотр всех данных", "Создание файлов по параметрам", };
	system("cls");
	cout << "< МЕНЮ >" << endl;
	for (int i = 0; i < buttonsCount1; i++) {
		cout << text[i];
		if (i == menu) {
			cout << " <--";
		}
		cout << endl;
	}
}
void showMenu2(int menu) {
	setlocale(LC_ALL, "rus");
	string* text = new string[buttonsCount2]{ "Создание файла по должности ", "Создание файла со списком преподавателей в порядке убывания стажа работы " };
	system("cls");
	cout << "< МЕНЮ ПО СОЗДАНИЮ ФАЙЛОВ >" << endl;
	for (int i = 0; i < buttonsCount2; i++) {
		cout << text[i];
		if (i == menu) {
			cout << " <--";
		}
		cout << endl;
	}
}
int startCycle1() {
	int menu = 0;
	showMenu1(menu);
	int ch;
	bool cycle = true;
	while (cycle) {
		ch = _getch();
		if (ch == 115 || ch == 80 || ch == 50 || ch == 251) {
			menu = (menu + 1) % buttonsCount1;
		}
		else if (ch == 119 || ch == 72 || ch == 56 || ch == 246) {
			if (menu == 0)
				menu = buttonsCount1;

			menu = (menu - 1) % buttonsCount1;
		}
		if (ch != 13) {
			showMenu1(menu);
		}
		else {
			cycle = false;
			system("cls");
			switch (menu)
			{
			case 0:
				return 1;
				break;
			case 1:
				return  2;
				break;
			case 2:
				return 3;
				break;
			case 3:
				return 4;
				break;
			case 4:
				return 5;
				break;
			}
		}
	}
}
int startCycle2() {
	int menu = 0;
	showMenu2(menu);
	int ch;
	bool cycle = true;
	while (cycle) {
		ch = _getch();
		if (ch == 115 || ch == 80 || ch == 50 || ch == 251) {
			menu = (menu + 1) % buttonsCount2;
		}
		else if (ch == 119 || ch == 72 || ch == 56 || ch == 246) {
			if (menu == 0)
				menu = buttonsCount2;

			menu = (menu - 1) % buttonsCount2;
		}
		if (ch != 13) {
			showMenu2(menu);
		}
		else {
			cycle = false;
			system("cls");
			switch (menu)
			{
			case 0:
				return 1;
				break;
			case 1:
				return  2;
				break;
			case 2:
				return 3;
				break;
			}
		}
	}
}
int famelSize, nameSize, fnameSize, yearSize, monthSize, idSize;
struct person {
	string famel;
	string name;
	string fname;
	string year;
	string month;
};
void updateSizes(vector<person>& p) {
	famelSize = 15, nameSize = 15, fnameSize = 15, yearSize = 5, monthSize = 15, idSize = 3;
	int k = 1, idSizeCounter = 0;
	for (person& m : p) {
		if (k % 10 == 0) {
			idSizeCounter++;
		}
		if (m.famel.length() > famelSize) {
			famelSize = m.famel.length();
		}
		if (m.name.length() > nameSize) {
			nameSize = m.name.length();
		}
		if (m.fname.length() > fnameSize) {
			fnameSize = m.fname.length();
		}
		if (m.year.length() > yearSize) {
			yearSize = m.year.length();
		}
		if (m.month.length() > monthSize) {
			monthSize = m.month.length();
		}
		k++;
	}

	if (idSizeCounter > idSize)
		idSize = idSizeCounter;
}
bool compareFamelD(const person& s1, const person& s2) {  //сортировка по имени по алфавиту
	return s1.famel < s2.famel;
}
bool compareFamelU(const person& s1, const person& s2) {  //сортировка по имени не по алфавиту
	return s1.famel > s2.famel;
}
bool compareNameD(const person& s1, const person& s2) {
	return s1.name < s2.name;
}
bool compareNameU(const person& s1, const person& s2) {
	return s1.name > s2.name;
}
bool compareFNameD(const person& s1, const person& s2) { //сортировка по отчеству
	return s1.fname < s2.fname;
}
bool compareFNameU(const person& s1, const person& s2) {
	return s1.fname > s2.fname;
}
bool compareYearD(const person& s1, const person& s2) {  //сортировка по дате рождения по возрастанию
	return stoi(s1.year) < stoi(s2.year);
}
bool compareYearU(const person& s1, const person& s2) {   //сортировка по дате рождения по убыванию
	return stoi(s1.year) > stoi(s2.year);
}
bool compareMonthD(const person& s1, const person& s2) {
	return s1.month < s2.month;
}
bool compareMonthU(const person& s1, const person& s2) {
	return s1.month > s2.month;
}
void printStudents(string namefile, vector <person>& students) {  //Запись и вывод данных о студентах
	int i = 0;
	cout << endl << left << setw(idSize) << "№" << " " << setw(famelSize) << "Фамилия" << " " << setw(nameSize) << "Имя" << " " << setw(fnameSize) << "Отчество" << " " << setw(yearSize) << "Стаж" << " " << setw(monthSize) << "Должность" << " " << endl;
	cout << getBigLine(idSize + famelSize + nameSize + fnameSize + yearSize + monthSize + 5) << endl;
	for (const auto& hito : students) {
		i++;
		cout << left << setw(idSize) << i << " " << setw(famelSize) << hito.famel << " " << setw(nameSize) << hito.name << " " << setw(fnameSize) << hito.fname << " " << setw(yearSize) << hito.year << " " << setw(monthSize) << hito.month << endl;
	}
}
string* addOut(int countPerson, string namefile, vector <person>& students, int oldcount) {   //Добавление студентов
	ofstream ofile(namefile, fstream::app);
	string str;
	person ps;
	ofile << countPerson + oldcount << endl;
	for (int i = 0; i < countPerson; i++) {
		cout << "Введите фамилию: ";
		cin >> str;
		str[0] = toupper(str[0]);
		ps.famel = str;
		cout << "Введите имя: ";
		cin >> str;
		str[0] = toupper(str[0]);
		ps.name = str;
		cout << "Введите отчество: ";
		cin >> str;
		str[0] = toupper(str[0]);
		ps.fname = str;
		cout << "Введите стаж работы в годах ";
		str = checkd(6);
		ps.year = str;
		cout << "Введите должность: ";
		str = checkd(7);
		ps.month = str;
		ofile << i + 1 << " " << ps.famel << " " << ps.name << " " << ps.fname << " " << ps.year << " " << ps.month << endl;
		students.push_back(ps);
		cout << "Данные записаны" << endl;
		cout << getBigLine(idSize + famelSize + nameSize + fnameSize + yearSize + monthSize + 5) << endl;
	}
	string* arrData = new string[students.size()];
	int i = 0;
	for (const auto& hito : students) {
		arrData[i] += (hito.famel + " " + hito.name + " " + hito.fname + " " + hito.year + " " + hito.month);
		i++;
	}
	ofile.close();
	return arrData;
}
int returnCount(vector <person>& students, string parametr) {
	int k = 0;
	for (const auto& hito : students) {
		if (hito.month == parametr) {
			k++;
		}
		if (hito.year == parametr) {
			k++;
		}
		if (hito.name == parametr) {
			k++;
		}
	}
	return k;
}
void makeFile(string parametr, string nf, vector <person> students, bool printYear = 0) {
	int k = 0;
	ofstream fileName(nf, ios_base::out);
	cout << "\nДанные в файле: " << endl;
	cout << endl << left << setw(idSize) << "№" << " " << setw(famelSize) << "Фамилия" << " " << setw(nameSize) << "Имя" << " " << setw(fnameSize) << "Отчество" << " " << setw(yearSize) << "Стаж" << " " << setw(monthSize) << "Должность" << " " << endl;
	cout << getBigLine(idSize + famelSize + nameSize + fnameSize + yearSize + monthSize + 5) << endl;
	int count = returnCount(students, parametr);
	if (printYear)
		count = students.size();

	fileName << count << endl;
	for (const auto& hito : students) {
		if (hito.month == parametr) {
			k++;
			fileName << k << " " << hito.famel << " " << hito.name << " " << hito.fname << " " << hito.year << " " << hito.month << endl;
			cout << left << setw(idSize) << k << " " << setw(famelSize) << hito.famel << " " << setw(nameSize) << hito.name << " " << setw(fnameSize) << hito.fname << " " << setw(yearSize) << hito.year << " " << setw(monthSize) << hito.month << endl;
		}
		if (hito.year == parametr || printYear) {
			k++;
			fileName << k << " " << hito.famel << " " << hito.name << " " << hito.fname << " " << hito.year << " " << hito.month << endl;
			cout << left << setw(idSize) << k << " " << setw(famelSize) << hito.famel << " " << setw(nameSize) << hito.name << " " << setw(fnameSize) << hito.fname << " " << setw(yearSize) << hito.year << " " << setw(monthSize) << hito.month << endl;
		}
		if (hito.name == parametr) {
			k++;
			fileName << k << " " << hito.famel << " " << hito.name << " " << hito.fname << " " << hito.year << " " << hito.month << endl;
			//fileName << k << hito.famel << endl;
			cout << left << setw(idSize) << k << " " << setw(famelSize) << hito.famel << " " << setw(nameSize) << hito.name << " " << setw(fnameSize) << hito.fname << " " << setw(yearSize) << hito.year << " " << setw(monthSize) << hito.month << endl;
		}
	}
	fileName.close();
}
void updateMakeFile(string par1, string par2, string par3, string& file1, string& file2, string& file3, vector <person> students) {
	ofstream ofile(file1, ios_base::out);
	if (file1.empty()) {
	}
	else {
		int k = 0;
		for (const auto& hito : students) {
			if (hito.month == par1) {
				k++;
				ofile << k << " " << hito.famel << " " << hito.name << " " << hito.fname << " " << hito.year << " " << hito.month << endl;
				//cout << k << " " << hito.famel << " " << hito.name << " " << hito.year << " " << hito.month << endl;
			}
		}
	}
	if (file2.length() < 1) {
	}
	else {
		ofstream ofile(file2, ios_base::out);
		int k = 0;
		for (const auto& hito : students) {
			if (hito.year == par2) {
				k++;
				ofile << k << " " << hito.famel << " " << hito.name << " " << hito.fname << " " << hito.year << " " << hito.month << endl;
			}
		}
	}
	if (file3.length() < 1) {
	}
	else {
		ofstream ofile(file3, ios_base::out);
		int k = 0;
		for (const auto& hito : students) {
			if (hito.name == par3) {
				k++;
				ofile << k << " " << hito.famel << " " << hito.name << " " << hito.fname << " " << hito.year << " " << hito.month << endl;
			}
		}
	}
	ofile.close();
}
vector <person> fileTo_struct(string nameSort, string& k, string*& arr, vector <person> students) {
	ifstream ofile(nameSort);
	cout << "\nОткрытие файла с именем: ..... [" << nameSort << "]" << endl;
	if (ofile.is_open()) {
		SetConsoleCP(1251);
		cin.ignore();
		string countStrok, s;
		getline(ofile, countStrok);
		k = countStrok;
		cout << countStrok << " человек в списке" << endl << "\n";
		string* arrData = new string[stoi(countStrok)];  //массив из строк файла
		for (int i = 0; i < (stoi(countStrok)); i++) {
			getline(ofile, s);
			string s1;
			if (s[2] == ' ') {
				for (int j = 3; j < s.length(); j++) {
					s1 += s[j];
				}
			}
			else {
				for (int j = 2; j < s.length(); j++) {
					s1 += s[j];
				}
			}
			arrData[i] = s1;
			cout << s << endl;
		}
		arr = arrData;
		person ps;
		for (int i = 0; i < stoi(countStrok); i++) {
			string patt;
			int k = 0;
			string s = arrData[i];
			for (int j = 0; j < (arrData[i].length()); j++) {
				if (s[j] != ' ') {
					patt += s[j];
				}
				else {
					k++;
					if (k == 1) {
						ps.famel = patt;
					}
					if (k == 2) {
						ps.name = patt;
					}
					if (k == 3) {
						ps.fname = patt;
					}
					if (k == 4) {
						ps.year = stoi(patt);
					}
					if (k == 5) {
						ps.month = patt;
					}
					patt.clear();
				}
			}
			students.push_back(ps);
		}
	}
	return students;
}
void SelectContiton(int p, string namefile, vector <person>& students, int& countStrok, string* arrData, string& monthForfile, string& yearForfile, string& nameForfile, string& mf, string& yf, string& nf) {
	if (p == 1) {
		string k;
		string* arr;
		int yes = 1;
		while (yes) {
			int firstP;
			int secondP;
			cout << "\nПо убыванию [1] ///// По возрастанию [2]" << endl;
			firstP = stoi(checkd(2));
			cout << "\nПо Фамилии [1] ///// По Имени [2] ///// По Отчеству [3] ///// По Стажу [4] ///// По Должности [5]" << endl;
			secondP = stoi(checkd(4));
			if (firstP == 1) {
				if (secondP == 1) {
					cout << "Сортировка по Фамилии по убыванию" << endl;
					sort(students.begin(), students.end(), compareFamelU);
				}
				if (secondP == 2) {
					cout << "Сортировка по Имени по убыванию" << endl;
					sort(students.begin(), students.end(), compareNameU);
				}
				if (secondP == 3) {
					cout << "Сортировка по Отчеству по убыванию" << endl;
					sort(students.begin(), students.end(), compareFNameU);
				}
				if (secondP == 4) {
					cout << "Сортировка по Стажу по убыванию" << endl;
					sort(students.begin(), students.end(), compareYearU);
				}
				if (secondP == 5) {
					cout << "Сортировка по Должности по убыванию" << endl;
					sort(students.begin(), students.end(), compareMonthU);
				}
			}
			else {
				if (secondP == 1) {
					cout << "Сортировка по Фамилии по возрастанию" << endl;
					sort(students.begin(), students.end(), compareFamelD);
				}
				if (secondP == 2) {
					cout << "Сортировка по Имени по возрастанию" << endl;
					sort(students.begin(), students.end(), compareNameD);
				}
				if (secondP == 3) {
					cout << "Сортировка по Отчеству по возрастанию" << endl;
					sort(students.begin(), students.end(), compareFNameD);
				}
				if (secondP == 4) {
					cout << "Сортировка по Стажу по возрастанию" << endl;
					sort(students.begin(), students.end(), compareYearD);
				}
				if (secondP == 5) {
					cout << "Сортировка по Должности по возрастанию" << endl;
					sort(students.begin(), students.end(), compareMonthD);
				}
			}
			ofstream ofile(namefile, fstream::out);
			int i = 0;
			ofile << countStrok << endl;
			for (const auto& hito : students) {
				i++;
				ofile << i << " " << hito.famel << " " << hito.name << " " << hito.fname << " " << hito.year << " " << hito.month << endl;
			}
			printStudents(namefile, students);
			cout << "Для завершения сортировки файла нажмите [0]" << endl << "Для продолжения[1]" << endl;
			yes = stoi(checkd(0));
		}

	}
	if (p == 2) {
		ofstream ofile(namefile, fstream::out);
		cout << "Сколько человек хотите добавить? ";
		int countPerson;  //количество добавляемых человек
		countPerson = stoi(checkd(1));
		ofile << countStrok + countPerson << endl;
		int k = 0;
		for (const auto& hito : students) {
			k++;
			ofile << k << " " << hito.famel << " " << hito.name << " " << hito.fname << " " << hito.year << " " << hito.month << endl;
		}
		string str;
		person ps;
		for (int i = 0; i < countPerson; i++) {
			cout << "Введите фамилию: ";
			cin >> str;
			str[0] = toupper(str[0]);
			ps.famel = str;
			cout << "Введите имя: ";
			cin >> str;
			str[0] = toupper(str[0]);
			ps.name = str;
			cout << "Введите отчество: ";
			cin >> str;
			str[0] = toupper(str[0]);
			ps.fname = str;
			cout << "Введите стаж работы в годах: ";
			str = checkd(6);
			ps.year = str;
			cout << "Введите должность: ";
			str = checkd(7);;
			ps.month = str;
			ofile << i + 1 + countStrok << " " << ps.famel << " " << ps.name << " " << ps.fname << " " << ps.year << " " << ps.month << endl;
			students.push_back(ps);
			updateSizes(students);
			cout << "Данные записаны" << endl;
			cout << getBigLine(idSize + famelSize + nameSize + fnameSize + yearSize + monthSize + 5) << endl;
		}
		string* arrData1 = new string[students.size()];
		int i = 0;
		/*
		cout << endl << left << setw(2) << "№" << " " << setw(15) << "Фамилия" << setw(15) << "Имя" << setw(15) << "Год" << setw(15) << "Месяц" << endl;
		cout << "------------------------------------------------------------" << endl;
		for (const auto& hito : students) {
			arrData1[i] += (hito.famel + " " + hito.name + " " + hito.year + " " + hito.month);
			i++;
			if (i < 10) {
				cout << i << " " << left << " " << setw(15) << hito.famel << setw(15) << hito.name << setw(15) << hito.year << setw(15) << hito.month << endl;
			}
			else {
				cout << i << " " << left << setw(15) << hito.famel << setw(15) << hito.name << setw(15) << hito.year << setw(15) << hito.month << endl;
			}
		}
		*/
		printStudents(namefile, students);
		countStrok += countPerson;
		ofile.close();
		updateMakeFile(monthForfile, yearForfile, nameForfile, mf, yf, nf, students);
		cout << "\n<Все файлы обновлены>" << endl;
	}
	if (p == 3) {
		ofstream ofile(namefile, fstream::out);
		countStrok--;
		ofile << countStrok << endl;
		printStudents(namefile, students);
		cout << "Какую строку вы хотите удалить? Введите ее номер: ";
		int numS, i = 0;
		numS = stoi(checkd(1));
		string* newArr = new string[countStrok];
		auto iter = students.cbegin();
		students.erase(iter + (numS - 1));
		for (const auto& hito : students) {
			i++;
			ofile << i << " " << hito.famel << " " << hito.name << " " << hito.fname << " " << hito.year << " " << hito.month << endl;
		}

		/*
		for (int i = 1; i < (countStrok+1); i++) {
			if (i != numS) {
				ofile << i << " " << arrData[i + j - 1] << endl;
				cout << i << " " << arrData[i + j - 1] << endl;
			}
			else {
				j++;
				cout << j;
				ofile << i << " " << arrData[i + j -1] << endl;
				cout << i << " " << arrData[i + j - 1] << endl;
			}
		}

		auto iter = students.cbegin();
		students.erase(iter + (numS-1));
		*/
		cout << students.size();
		updateSizes(students);
		printStudents(namefile, students);
		updateMakeFile(monthForfile, yearForfile, nameForfile, mf, yf, nf, students);
		cout << "\n<Все файлы обновлены>" << endl;
		ofile.close();
	}
	if (p == 4) {
		cout << "\n";
		printStudents(namefile, students);
	}
	if (p == 5) {
		int p = startCycle2();
		if (p == 1) {
			cout << "Введите должность для формирования файла: ";
			cin >> monthForfile;
			monthForfile[0] = toupper(monthForfile[0]);
			cout << "Введите название файла для сохранения: ";
			cin >> mf;
			mf += ".txt";
			makeFile(monthForfile, mf, students);
			cout << "\nФайл с именем: " << "(" << mf << ")" << " создан по параметру <ДОЛЖНОСТЬ>" << endl;
			ofstream file("file.txt", ios_base::app);
			file << mf << endl;
			file.close();
		}
		else if (p == 2) {
			string yearForfile;
			cout << "Введите название файла для сохранения: ";
			cin >> yf;
			yf += ".txt";
			sort(students.begin(), students.end(), compareYearU);

			makeFile(yearForfile, yf, students, 1);
			cout << "\nФайл с именем: " << "(" << yf << ")" << " создан по параметру <СТАЖ>" << endl;
			ofstream file("file.txt", ios_base::app);
			file << yf << endl;
			file.close();
		}
		else {
			cout << "Введите имя для формирования файла: ";
			cin >> nameForfile;
			nameForfile[0] = toupper(nameForfile[0]);
			cout << "Введите название файла для сохранения: ";
			cin >> nf;
			nf += ".txt";
			makeFile(nameForfile, nf, students);
			cout << "\nФайл с именем: " << "(" << nf << ")" << " создан по параметру <ИМЯ>" << endl;
			ofstream file("file.txt", ios_base::app);
			file << nf << endl;
			file.close();
		}
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	fstream fs;
	string monthForfile, yearForfile, nameForfile, mf, yf, nf;
	string files = "file.txt";
	int how = 3, numStudents;
	ifstream file(files, ios::in | ios::out);
	string s;
	cout << "Файлы с данными: " << endl;
	while (!file.eof()) {   //Вывод имеющихся файлов
		getline(file, s);
		cout << "[" << s << "]" << endl;
	}
	file.close();
	cout << "////////// Создать файл - [1] ////////// Использовать имеющийся файл - [2] //////////" << endl;
	how = stoi(checkd(2));
	vector <person> students;
	string famel;
	string name;
	string fname;
	string year;
	string month;

	if (how == 1) {
		system("chcp 1251");
		string StandName = "baseNull.txt";
		int howF;
		string nonAutofile;
		cout << "\n///// Использовать имя по умолчанию - [1] ///// Задать свое - [2] /////" << endl;
		howF = stoi(checkd(2));
		if (howF == 1) {
			nonAutofile = StandName;
		}
		else {
			cout << "\n///// Введите имя для названия файла: /////" << endl;
			cin >> nonAutofile;
			nonAutofile += ".txt";
			ofstream file(files, ios_base::app);
			file << nonAutofile << endl;
			file.close();
		}
		cout << "\nСоздание файла с именем: ..... [" << nonAutofile << "]" << endl;
		ofstream ofile(nonAutofile, ios::out);  //открытие файла для записи
		if (ofile.is_open()) {
			cout << "\n ///// Введите количество человек: /////" << endl;
			numStudents = stoi(checkd(1));
			int f = 0;
			string* arrData = addOut(numStudents, nonAutofile, students, f);
			printStudents(nonAutofile, students);
			Sleep(3000);
			system("cls");
			cout << "\n()// Вы вошли в меню редактирования файла //()" << endl;
			int yes = 1;
			while (yes) {
				cout << "Для выхода из программы нажмите [2] ///// Для продолжения [1]" << endl;
				yes = stoi(checkd(2));
				if (yes == 1) {
					int p = startCycle1();
					SelectContiton(p, nonAutofile, students, numStudents, arrData, monthForfile, yearForfile, nameForfile, mf, yf, nf);
				}
				else {
					cout << "Прогрaмма завершена";
					break;
				}
			}
		}
	}         //Ручной ввод
	else {
		if (how == 2) {
			bool t = 1;
			while (t) {
				system("chcp 1251");
				string StandName = "text5.txt";
				int howF = 3;
				string Autofile;
				cout << "\n///// Использовать имя по умолчанию - [1] ///// Задать свое - [2] /////" << endl;
				howF = stoi(checkd(2));
				if (howF == 1) {
					Autofile = StandName;
				}
				else if (howF == 2) {
					cout << "\n///// Введите имя для открытия файла без .txt или выберите любой файл из списка, и напишите его без t: /////" << endl;
					cin >> Autofile;
					Autofile += ".txt";
					ifstream ofile(Autofile);
					cout << Autofile;
					if (!ofile.is_open()) {
						Autofile = Autofile.substr(0, Autofile.length() - 1);
						Autofile += ".txt";
					}
				}
				ifstream ofile(Autofile);
				cout << "\nОткрытие файла с именем: ..... [" << Autofile << "]" << endl;
				if (ofile.is_open()) {
					SetConsoleCP(1251);
					cin.ignore();
					string countStrok, s;
					getline(ofile, countStrok);
					cout << countStrok << " человек в списке" << endl << "\n";
					int CountPerson = stoi(countStrok);
					string* arrData = new string[stoi(countStrok)];  //массив из строк файла
					cout << endl << left << setw(famelSize) << "Фамилия" << " " << setw(nameSize) << "Имя" << " " << setw(fnameSize) << "Отчество" << " " << setw(yearSize) << "Стаж" << " " << setw(monthSize) << "Должность" << " " << endl;
					cout << getBigLine(35) << endl;
					for (int i = 0; i < CountPerson; i++) {
						getline(ofile, s);
						string s1;
						if (s[2] == ' ') {
							for (int j = 3; j < s.length(); j++) {
								s1 += s[j];
							}
						}
						else {
							for (int j = 2; j < s.length(); j++) {
								s1 += s[j];
							}
						}
						arrData[i] = s1;
						string word1, word2, word3, word4, word5;
						istringstream iss(s1);
						iss >> word1 >> word2 >> word3 >> word4 >> word5;
						cout << left << setw(famelSize) << word1 << " " << setw(nameSize) << word2 << " " << setw(fnameSize) << word3 << " " << setw(yearSize) << word4 << " " << setw(monthSize) << word5 << endl;
					}
					person ps;
					for (int i = 0; i < CountPerson; i++) {
						string patt;
						int k = 0;
						string s = arrData[i];
						for (int j = 0; j < (arrData[i].length()); j++) {
							if (s[j] != ' ') {
								patt += s[j];
								if (j == (arrData[i].length() - 1)) {
									ps.month = patt;

									patt.clear();
								}
							}
							else {
								k++;
								if (k == 1) {
									ps.famel = patt;
								}
								if (k == 2) {
									ps.name = patt;
								}
								if (k == 3) {
									ps.fname = patt;
								}
								if (k == 4) {
									ps.year = patt;
								}
								if (k == 5) {
									ps.month = patt;
								}
								patt.clear();
							}
						}
						students.push_back(ps);
					}
					updateSizes(students);
					int yes = 1;
					while (yes) {
						cout << "Для выхода из программы нажмите [2] ///// Для продолжения [1]" << endl;
						yes = stoi(checkd(2));
						if (yes == 1) {
							int p = startCycle1();
							SelectContiton(p, Autofile, students, CountPerson, arrData, monthForfile, yearForfile, nameForfile, mf, yf, nf);
						}
						else {
							cout << "Прогрaмма завершена";
							t = 0;
							break;
						}
					}
				}
				else {
					cout << "Файл не найден!" << endl;
				}
			}
		}
	}
}
