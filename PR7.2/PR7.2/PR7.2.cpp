#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void CreateMatrix(int** a, const int n, const int Low, const int High);
void PrintMatrix(int** a, const int n);
void TransposeMatrix(int** a, const int n);

int main()
{
    srand((unsigned)time(NULL)); 

    int Low = 1; // Нижня межа значень елементів
    int High = 9; // Верхня межа значень елементів

    int n; // Розмірність матриці
    cout << "n: ";
    cin >> n;

    // Створення динамічної матриці розміром n x n
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    // Створення і виведення початкової матриці
    CreateMatrix(a, n, Low, High);
    cout << "Original matrix:" << endl;
    PrintMatrix(a, n);

    // Транспонування матриці
    TransposeMatrix(a, n);

    // Виведення транспонованої матриці
    cout << "Transposed matrix:" << endl;
    PrintMatrix(a, n);

    // Звільнення пам'яті
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

// Функція для створення матриці з випадковими значеннями в межах [Low, High]
void CreateMatrix(int** a, const int n, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

// Функція для виведення матриці на екран у вигляді таблиці
void PrintMatrix(int** a, const int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

// Функція для транспонування матриці (обмін елементів matrix[i][j] з matrix[j][i])
void TransposeMatrix(int** a, const int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            swap(a[i][j], a[j][i]); 
}
