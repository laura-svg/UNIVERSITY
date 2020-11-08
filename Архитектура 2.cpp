// Архитектура 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <ctime>
#include <cmath>
#include <windows.h>
#include <cmath>
#include <cstring>
#include <xmmintrin.h>
#include <intrin.h>

using namespace std;

const int A = 3;

float* matrix(float Z[], int size) {
	for (int j = 0; j < size; j++) {
		Z[j] = 1 + rand() % A;
	}
	return Z;
}

void out(float** Z, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << Z[i][j] << "\t";
		}
		cout << endl;
	}
}

void zero(float** Z, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			Z[i][j] = 0;
		}
	}
}

void zero_1(float* Z, int size) {
	for (int j = 0; j < size; j++) {
		Z[j] = 0;
	}
}

void out_1(float* Z, int size) {
	for (int j = 0; j < size; j++) {
		cout << Z[j] << "\t";
	}
}

void transp(float** Z, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			swap(Z[i][j], Z[j][i]);
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int cpuinfo[4];
	__cpuid(cpuinfo, 1);
	bool sseSupportted = false;
	sseSupportted = cpuinfo[3] & (1 << 25) || false;

	cout << "SSE: " << (sseSupportted ? "Поддерживается" : "НЕ поддерживается") << endl;

	srand(time(NULL));
	double time;
	int count = 100;
	bool output = false;

	for (count; count < 5001; count += 100)
	{
		cout << "Размерность массива: " << count << endl;

		float* X1 = static_cast<float*>(_mm_malloc(count * sizeof(float), 16)),
			* Y1 = static_cast<float*>(_mm_malloc(count * sizeof(float), 16)),
			** X = static_cast<float**>(_mm_malloc(count * sizeof(float), 16)),
			** Y = static_cast<float**>(_mm_malloc(count * sizeof(float), 16)),
			* RES1 = static_cast<float*>(_mm_malloc(count * sizeof(float), 16)),
			** RES = static_cast<float**>(_mm_malloc(count * sizeof(float), 16));
		Y = new float* [count];

		float a = 1 + rand() % 10;
		float b = 1 + rand() % 10;

		__m128 A = _mm_set1_ps(a);
		__m128 B = _mm_set1_ps(b);

		for (int i = 0; i < count; i++)
		{
			RES[i] = static_cast<float*>(_mm_malloc(count * sizeof(float), 16));
		}
		for (int i = 0; i < count; i++) {
			Y[i] = static_cast<float*>(_mm_malloc(count * sizeof(float), 16));
		}

		for (int i = 0; i < count; i++) {
			X[i] = static_cast<float*>(_mm_malloc(count * sizeof(float), 16));
		}

		for (int i = 0; i < count; i++) {
			X[i] = matrix(X[i], count); //lets see
			Y[i] = matrix(Y[i], count);
		}

		zero(RES, count);
		zero_1(RES1, count);
		X1 = matrix(X1, count);
		Y1 = matrix(Y1, count);

		if (output == true) {
			cout << "X1" << endl;
			out_1(X1, count);
			cout << endl << "Y1" << endl;
			out_1(Y1, count);
			cout << endl << "X" << endl;
			out(X, count);
			cout << endl << "Y" << endl;
			out(Y, count);
			cout << endl;
		}

		time = clock();
		for (int i = 0; i < count; i++)
		{
			for (int j = 0; j < count; j++) {
				for (int k = 0; k < count; k++) {
					RES[i][j] += X[i][k] * Y[k][j];
				}
			}

		}
		time = (clock() - time) / CLOCKS_PER_SEC;
		cout << "#1 NO SSE: " << time << " c." << endl;

		time = clock();
		for (int i = 0; i < count; i++)
		{
			for (int j = 0; j < count; j++)
			{
				RES1[i] += (a * X1[j]) - (b * Y[i][j] * Y1[j]);
			}
		}
		time = (clock() - time) / CLOCKS_PER_SEC;
		cout << "#2 NO SSE: " << time << " c." << endl;

		if (output == true) {
			cout << "RES" << endl;
			out(RES, count);
			cout << "RES1" << endl;
			out_1(RES1, count);
			cout << endl;
		}

		__m128** XX = reinterpret_cast<__m128**>(X);
		__m128** YY = reinterpret_cast<__m128**>(Y);
		__m128** RRES = reinterpret_cast<__m128**>(RES);

		__m128* XX1 = reinterpret_cast<__m128*>(X1);
		__m128* YY1 = reinterpret_cast<__m128*>(Y1);
		__m128* RRES1 = reinterpret_cast<__m128*>(RES);

		zero(RES, count);
		zero_1(RES1, count);

		transp(Y, count);

		time = clock();
		for (int i = 0; i < count; i++)
		{
			for (int j = 0; j < count; j++)
			{
				for (int k = 0; k < count / 4; k++)
				{
					__m128 temp = _mm_mul_ps(XX[i][k], YY[j][k]);
					//for (int t = 0; t < 4; t++) {
					RES[i][j] += temp.m128_f32[0] + temp.m128_f32[1] + temp.m128_f32[2] + temp.m128_f32[3];//hz maybye
				//}
				}
			}
		}
		time = (clock() - time) / CLOCKS_PER_SEC;
		cout << "#1 SSE: " << time << " c." << endl;

		///////////////

		transp(Y, count);

		time = clock();
		for (int i = 0; i < count; i++)
		{
			for (int j = 0; j < count / 4; j++)
			{
				__m128 temp = _mm_sub_ps(_mm_mul_ps(YY[i][j], YY1[j]), _mm_mul_ps(_mm_mul_ps(A, XX[i][j]), XX1[j]));
				//for (int t = 0; t < 4; t++) {
				//}
				RES1[i] += temp.m128_f32[0] + temp.m128_f32[1] + temp.m128_f32[2] + temp.m128_f32[3];
			}
		}
		time = (clock() - time) / CLOCKS_PER_SEC;
		cout << "#2 SSE: " << time << " c." << endl;

		if (output == true) {
			cout << "RES_2" << endl;
			out(RES, count);
			cout << endl << "RES1_2" << endl;
			out_1(RES1, count);
			cout << endl;
		}
	}
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
