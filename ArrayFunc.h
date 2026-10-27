#pragma once
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <utility>

// Формує елементи масиву випадковими числами з діапазону [Low; High]
inline void Create(double* a, const int size, const double Low, const double High)
{
    for (int i = 0; i < size; i++)
        a[i] = std::round((Low + (High - Low) * rand() / RAND_MAX) * 100) / 100;
}

// Виводить елементи масиву в рядок
inline void Print(const double* a, const int size)
{
    for (int i = 0; i < size; i++)
        std::cout << std::setw(8) << a[i];
    std::cout << std::endl;
}

// Повертає кількість додатних елементів масиву
inline int CountPositive(const double* a, const int size)
{
    int k = 0;
    for (int i = 0; i < size; i++)
        if (a[i] > 0)
            k++;
    return k;
}

// Повертає добуток додатних елементів масиву
// (якщо додатних елементів немає, повертає 1 - нейтральний елемент добутку)
inline double ProductPositive(const double* a, const int size)
{
    double p = 1;
    for (int i = 0; i < size; i++)
        if (a[i] > 0)
            p *= a[i];
    return p;
}

// Повертає індекс першого мінімального елемента масиву
inline int IndexMin(const double* a, const int size)
{
    int imin = 0;
    for (int i = 1; i < size; i++)
        if (a[i] < a[imin])
            imin = i;
    return imin;
}

// Повертає суму елементів масиву, розташованих до елемента з індексом index
inline double SumBefore(const double* a, const int index)
{
    double s = 0;
    for (int i = 0; i < index; i++)
        s += a[i];
    return s;
}

// Впорядковує за зростанням (метод вибору) елементи з індексами
// start, start+2, start+4, ... ; решту елементів не змінює
inline void SortStep(double* a, const int size, const int start)
{
    for (int i = start; i < size - 2; i += 2)
    {
        int imin = i;
        for (int j = i + 2; j < size; j += 2)
            if (a[j] < a[imin])
                imin = j;
        std::swap(a[i], a[imin]);
    }
}