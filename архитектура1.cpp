// архитектура1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <ctime>

using namespace std;
double Matrix[14000][14000];
double Vector[14000];
double Result[14000];
double Result1[14000];


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N, i, j;

	cout << "N= "; cin >> N;


	srand(time(0));
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			Matrix[i][j] = rand();
		}
	}
	cout << endl;

	for (j = 0; j < N; j++)
	{
		Vector[j] = rand();
	}

	unsigned int start_time_MxV = clock();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Result[i] += Matrix[i][j] * Vector[j];
		}
	}
	unsigned int end_time_MxV = clock();
	unsigned int search_time_MxV = end_time_MxV - start_time_MxV;


	unsigned int start_time_VxM_opt = clock();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Result1[j] += Vector[i] * Matrix[i][j];
		}
	}
	unsigned int end_time_VxM_opt = clock();
	unsigned int search_time_VxM_opt = end_time_VxM_opt - start_time_VxM_opt;


	unsigned int start_time_VxM_neopt = clock();
	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N; i++)
		{
			Result1[j] += Vector[i] * Matrix[i][j];
		}
	}
	unsigned int end_time_VxM_neopt = clock();
	unsigned int search_time_VxM_neopt = end_time_VxM_neopt - start_time_VxM_neopt;

	cout << "Time M x V = " << search_time_MxV << endl;
	cout << "Time V x M (opt) = " << search_time_VxM_opt << endl;
	cout << "Time V x M (neopt) = " << search_time_VxM_neopt << endl;

	system("pause");
	return 0;
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
