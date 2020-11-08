// Algoritmy obrobky masiviv.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include<iostream>
#include<stdio.h>
#include<ctime>
using namespace std; 
	void my_array(int A[], int &n)
	{
		int a, b;
		cout << "Введите диапазон чисел [A; B]" << endl;
		cout << " a <= b;" << endl;
		cout << "a = ";
		cin >> a;
		cout << "b = ";
		cin >> b;
		cout << "Массив A:" << endl;
		cout << "Ввведите размер массива с которым будете работать" << endl;
		cin >> n;


		for (int i = 0; i < n; i++)
		{
			A[i] = a + rand() % (b - a + 1);
		}
	}


	void my_vivod(int A[], int n)
	{    
		for (int i = 0; i < n; i++)
		{
			cout << A[i] << " ";
		}
		cout << endl;
	}
	void my_sum ( int A[], int n)
	{
		if (!(n > 0 && n <= 100))
		{
			cout << "Ошибка.Недопустимый массив.Для выхода в главное меню нажмите Enter" << endl;
		}
		for (int i = 0; i < n; i++)
		{
			int min = 0, sum = 0, count = 0;
			for (int index = 0; index < n; index++)
			{
				cout << " A[" << index + 1 << "] = ";
				cin >> A[index];
			}
			min = A[0];
			for (int index = 1; index < n; index++)
			{
				if (A[index] < min)
				{
					min = A[index];
					count = index;
				}
			}
			for (int index = 0; index < count; index++)
			{
				if (index % 2 != 0)
				{
					sum += A[index];
				}
				cout << sum << endl;
			}

		}
	}
/*void my_sum_0(int A[],int n)
{

	for()
	{

		if (A[i] % 2 == 0)
		{
			A[j] = 0;
			j = j - 1;

		}
		A[j] = A[i];
		j=j-1;
	}
 }*/


	int main()
	{
		setlocale(LC_ALL, "Russian");
		int k,n;
		int A[100];
		

		cout << "1.Заповнити масив \n" << endl;
		cout << "2.Вивести масив на екран \n" << endl;
		cout << "3.Завдання 1 \n" << endl;
		cout << "4.Завдання 2 \n" << endl;
		cout << "5.Виход\n" << endl;
		cin >> k;


		while (k != 5)
		{
			switch (k)
			{
				case 1:
					my_array(A, n);

					break;
				case 2:
					my_vivod(A, n);
					break;
				case 3:
					my_sum(A, n);
					break;

				default:

						break;

				/*case 4:
							my_sum_0(A, n);
							break;*/
			}
			cout << "1.Заповнити масив \n" << endl;
			cout << "2.Вивести масив на екран \n" << endl;
			cout << "3.Завдання 1 \n" << endl;
			cout << "4.Завдання 2 \n" << endl;
			cout << "5.Виход\n" << endl;
			cin >> k;
			
		}
			
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
//