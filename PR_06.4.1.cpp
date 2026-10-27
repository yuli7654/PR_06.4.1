#include <iostream>
#include <iomanip>
#include <ctime>
#include "ArrayFunc.h"

using namespace std;

int main()
{
    srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел

    int n;
    cout << "n = ";
    cin >> n;
    if (n <= 0)
    {
        cerr << "Кількість елементів має бути додатною" << endl;
        return 1;
    }

    double* a = new double[n]; // динамічний масив
    const double Low = -10;
    const double High = 10;

    cout << fixed << setprecision(2);

    Create(a, n, Low, High);
    cout << "Початковий масив:" << endl;
    Print(a, n);

    // 1.1. Добуток додатних елементів
    if (CountPositive(a, n) > 0)
        cout << "Добуток додатних елементів = " << ProductPositive(a, n) << endl;
    else
        cout << "Додатних елементів немає" << endl;

    // 1.2. Сума елементів, розташованих до мінімального елемента
    int imin = IndexMin(a, n);
    cout << "Мінімальний елемент a[" << imin << "] = " << a[imin] << endl;
    cout << "Сума елементів до мінімального = " << SumBefore(a, imin) << endl;

    // 2. Впорядкування за зростанням окремо елементів на парних місцях
    //    (індекси 1, 3, 5, ...) та на непарних місцях (індекси 0, 2, 4, ...)
    SortStep(a, n, 0);
    SortStep(a, n, 1);
    cout << "Масив після впорядкування:" << endl;
    Print(a, n);

    delete[] a; // звільнили пам'ять
    return 0;
}