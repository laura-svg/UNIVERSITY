﻿// ConsoleApplication2 max.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
using namespace std;
#include<stdio.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	int val, n;
	int max = 1;//const int n = 10; 
	cout << " Введите последовательность целых чисел.Ноль признак конца";
	cin >> val;
	while (val != 0)
	{
		cin >> val;
		if (val < max)
			max = val;
	}
	cout << "Произведение =" << max;
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
