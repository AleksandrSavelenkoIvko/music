#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Songs {
	string name;
	string author;
	string lyrics;
	int date;
};

void add(Songs song){
	int vib;
	cout << "����� �������� ����� ��������� �����?\n[1]-� ����������\n[2]-�� �����\n��� �����?";
	cin >> vib;
	if (vib == 1) {
		string line;
		string name2;
		cout << "\n������� �������� ����� ";
		cin.ignore();
		getline(cin, song.name);
		cout << "\n������� ������ ����� ";
		cin.ignore();
		getline(cin, song.author);
		cout << "\n������� ��� ����� ";
		cin >> song.date;
		cout << "\n������� ����� �����\n";
		cin.ignore(); 
		while (true) {
			getline(cin, line);
			if (line.empty()) break;
			song.lyrics += line + "\n";
		}
		cout << "������� �������� ������� (��������+�����) ";
		getline(cin, name2);
		ofstream file("./Katalog/"+name2 + ".txt");
		/*fstream file("1.txt");*/
		if (file) {
			file << "��������: " << song.name << endl;
			file << "�����: " << song.author << endl;
			file << "���: " << song.date << endl;
			file << "����� �����: " << song.lyrics << endl;
			file << "**************************************************************************************" << endl;
			file.close();
			cout << "����� ���� ������� ��������� � ��������� � ������� ";
		}
		else cout << "������ �����";
	}
}
int main()
{
setlocale(LC_ALL, "Rus");
Songs song;
int choice;
cout << "������� �����\n[1]��������\n[2]�������\n[3]��������\n[4]����������\n[5]�����\n��� �����?";
cin >> choice;
switch (choice) {
case 1: add(song); break;
/*case 2: del(); break;
case 4: change(); break;
case 4: show(); break;
case 5: find(); break;*/
default: cout << "������"; break;
}
return 0;
}