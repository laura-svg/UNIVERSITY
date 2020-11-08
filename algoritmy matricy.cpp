// algoritmy matricy.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include "iostream"
#include "locale.h"
#include "ctime"
#include "string"
#include "iomanip"

using namespace std;
int is_choice(string);
string viv_array(int*, int);

int main()
{
	setlocale(LC_ALL, "RUS");
	srand((unsigned int)time(NULL));
	string choice;
	int n;
	do
	{
		cout << "Введите размер массива: ";
		getline(cin, choice);
		n = is_choice(choice);
	} while (n == -1);
	float** A = new float* [n];
	for (int i = 0; i < n; i++)
	{
		A[i] = new float[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			A[i][j] = -10 + rand() % 21;
		}
	}


	float* vector = new float[n];
	for (int i = 0; i < n; i++)
	{
		vector[i] = -10 + rand() % 21;
	}
	clock_t t_1 = clock();
	float* result = new float[n];
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			sum += (vector[j] * A[j][i]);
		}
		result[i] = sum;
	}
	// Умножение столбца на матрицу
	clock_t t_2 = clock();
	cout << endl << "Время умножение вектора на матрицу: " << (long double)(t_2 - t_1) / CLOCKS_PER_SEC << " сек " << endl;
	clock_t t_3 = clock();
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			sum += (A[i][j] * vector[j]);
		}
		result[i] = sum;
	}
	clock_t t_4 = clock();
	cout << "Время умножения матрицу на вектор: " << (long double)(t_4 - t_3) / CLOCKS_PER_SEC << " сек " << endl;




	int* fast = new int[n];
	for (int i = 0; i < n; i++)
	{
		fast[i] = 0;
	}
	clock_t t_5 = clock();
	/*for (int i = 0; i < n; i++)
	{
	fast[i] = A[0][i] * vector[0];
	}*/
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fast[j] += (A[i][j] * vector[i]);
		}
	}
	clock_t t_6 = clock();
	cout << "Время умножения вектора на матрицу (ускоренная версия): " << (long double)(t_6 - t_5) / CLOCKS_PER_SEC << " сек " << endl;
	// cout << "Вектор 1: " << viv_array(result, n) << endl;
	// cout << "Вектор 2: " << viv_array(fast,n)<<endl;
	return 0;
}



int is_choice(string src)
{
	for (int i = 0; i < src.length(); i++)
	{
		if (!isdigit(src[i])) return -1;
	}
	return atof(src.c_str());
}

string viv_array(int* arr, int n)
{
	string str = "";
	for (int i = 0; i < n; i++)
	{
		str += to_string(arr[i]);
		if (i != n - 1) str += ",";
	}
	return "{" + str + "}";
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
