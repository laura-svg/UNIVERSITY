#include<iostream>
#include<cstdlib>
using namespace std;
int prompt_menu_item()
{
	int variant;
	setlocale(LC_ALL, "Russian");
	cout << "Работает информационная система Лицея Информационных Технологий\n" << endl;
	cout << "1. Новости дня\n"
		<< "2. Анекдот недели\n"
		<< "3. Автора\n"
		<< "4. Выйти\n" << endl; cout << ">>>";
	cin >> variant; return variant;
}
int main (int argc, char* argv[])
{
	int variant = prompt_menu_item();
	switch (variant) {
	case 1:cout << "Зеленский в Париже  " << endl; break;
	case 2:cout << "Буратино утонул " << endl; break;
	case 3:cout << "Автор: Мовсисян Лаура " << endl; break;
	case 4:cout << "Выход из программы..." << endl; exit(EXIT_SUCCESS); break;
	default:cerr << "Вы выбрали неверный вариант" << endl; exit(EXIT_FAILURE);
	}
	return 0;
}
