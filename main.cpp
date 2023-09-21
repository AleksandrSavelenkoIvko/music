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
	cout << "Каким способом будем добавлять песню?\n[1]-С клавиатуры\n[2]-По файлу\nВаш выбор?";
	cin >> vib;
	if (vib == 1) {
		string line;
		string name2;
		cout << "\nВведите название песни ";
		cin.ignore();
		getline(cin, song.name);
		cout << "\nВведите автора песни ";
		cin.ignore();
		getline(cin, song.author);
		cout << "\nВведите год песни ";
		cin >> song.date;
		cout << "\nВведите текст песни\n";
		cin.ignore(); 
		while (true) {
			getline(cin, line);
			if (line.empty()) break;
			song.lyrics += line + "\n";
		}
		cout << "Введите название файлика (название+автор) ";
		getline(cin, name2);
		ofstream file("./Katalog/"+name2 + ".txt");
		/*fstream file("1.txt");*/
		if (file) {
			file << "Название: " << song.name << endl;
			file << "Автор: " << song.author << endl;
			file << "Год: " << song.date << endl;
			file << "Текст песни: " << song.lyrics << endl;
			file << "**************************************************************************************" << endl;
			file.close();
			cout << "Песня была успешна добавлена и сохранена в каталог ";
		}
		else cout << "Ошибка файла";
	}
}
int main()
{
setlocale(LC_ALL, "Rus");
Songs song;
int choice;
cout << "Каталог песен\n[1]Добавить\n[2]Удалить\n[3]Изменить\n[4]Отобразить\n[5]Найти\nВаш выбор?";
cin >> choice;
switch (choice) {
case 1: add(song); break;
/*case 2: del(); break;
case 4: change(); break;
case 4: show(); break;
case 5: find(); break;*/
default: cout << "Ошибка"; break;
}
return 0;
}