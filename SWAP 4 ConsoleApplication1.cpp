﻿// SWAP 4 ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
using namespace std;
int main()
{
	int a, b, c, d ;
	setlocale(LC_ALL, "Russian");
	cout << "ВВЕДИТЕ А" << "\n";
	cin >> a;
	cout << "ВВЕДИТЕ В" << "\n";
	cin >> b;
	cout << "ВВЕДИТЕ С" << "\n";
	cin >> c;
	cout << "ВВЕДИТЕ D" << "\n";
	cin >> d;
	swap(a, b);
	swap(c, d);
	swap(d, a);
	swap(d, b);
    swap(a, b);
	swap(a, c);
	swap(b, d);
	cout << "A= " << a << endl;
	cout << "B= " << b << endl;
	cout << "C= " << c << endl;
	cout << "D= " << d << endl;
	system("pause");
	return(0);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
