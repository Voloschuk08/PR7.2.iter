#include "pch.h"
#include "CppUnitTest.h"
#include "../PR7.2/PR7.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72
{
	TEST_CLASS(UnitTest72)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int Low = 1;
			int High = 9;

			int n = 3;

			// Створення динамічної матриці розміром n x n
			int** a = new int* [n];
			for (int i = 0; i < n; i++)
				a[i] = new int[n];

			// Вручну заповнимо матрицю для точного тестування
			a[0][0] = 1; a[0][1] = 2; a[0][2] = 3;
			a[1][0] = 4; a[1][1] = 5; a[1][2] = 6;
			a[2][0] = 7; a[2][1] = 8; a[2][2] = 9;

			// Очікувана транспонована матриця
			int expected[3][3] = {
				{1, 4, 7},
				{2, 5, 8},
				{3, 6, 9}
			};

			// Викликаємо функцію для транспонування
			TransposeMatrix(a, n);

			// Перевірка чи відповідає отримана матриця очікуваній
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					Assert::AreEqual(expected[i][j], a[i][j], L"Matrix element mismatch");
				}
			}

			// Звільнення пам'яті
			for (int i = 0; i < n; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}	