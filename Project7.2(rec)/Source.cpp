// Lab_7_2_2.cpp
// Барчук Денис Петрович
// Лабораторна робота № 7.2.2)
// Опрацювання багатовимірних масивів рекурсивними способами.
// Варіант 2
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void CreateColumn(int** a, const int rowCount, const int Low, const int High, int rowNo, int colNo) {
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (rowNo < rowCount - 1)
        CreateColumn(a, rowCount, Low, High, rowNo + 1, colNo);
}

void CreateColumns(int** a, const int rowCount, const int colCount, const int Low, const int High, int colNo) {
    CreateColumn(a, rowCount, Low, High, 0, colNo);
    if (colNo < colCount - 1)
        CreateColumns(a, rowCount, colCount, Low, High, colNo + 1);
}

void PrintColumn(int** a, const int rowCount, int rowNo, int colNo) {
    cout << setw(4) << a[rowNo][colNo];
    if (rowNo < rowCount - 1)
        PrintColumn(a, rowCount, rowNo + 1, colNo);
    else
        cout << endl;
}

void PrintColumns(int** a, const int rowCount, const int colCount, int colNo) {
    PrintColumn(a, rowCount, 0, colNo);
    if (colNo < colCount - 1)
        PrintColumns(a, rowCount, colCount, colNo + 1);
    else
        cout << endl;
}

int FindMaxInColumn(int** a, const int rowCount, const int colCount, int colNo, int maxInColumn) {
    if (colNo >= colCount) {
        return maxInColumn; // Базовий випадок: коли пройдемо всі стовпці, повертаємо максимум
    }

    if (a[0][colNo] > maxInColumn) {
        maxInColumn = a[0][colNo]; // Оновлюємо максимум, якщо потрібно
    }

    return FindMaxInColumn(a, rowCount, colCount, colNo + 1, maxInColumn); // Рекурсивний виклик для наступного стовпця
}

int Sum(int** a, const int rowCount, const int colCount, int colNo) {
    if (colNo >= colCount) {
        return 0; // Базовий випадок: коли пройдемо всі стовпці, повертаємо 0
    }

    int maxInColumn = FindMaxInColumn(a, rowCount, colCount, colNo, a[0][colNo]);
    return maxInColumn + Sum(a, rowCount, colCount, colNo + 1); // Рекурсивний виклик для наступного стовпця
}

int main() {
    srand((unsigned)time(NULL));
    int rowCount;
    int colCount;
    cout << "N = "; cin >> rowCount;
    cout << "K = "; cin >> colCount;
    cout << endl;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    int Low = 5, High = 55;
    CreateColumns(a, rowCount, colCount, Low, High, 0);
    PrintColumns(a, rowCount, colCount, 0);
    int S = 0;
    S = Sum(a, rowCount, colCount, 0);
    cout << "Sum of maximum elements: " << S << endl;

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
