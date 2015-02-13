#include <stdio.h>
#pragma once
using namespace std;

template <class T>

class Ordenamiento
{
public:
	static void bubbleSort(T[], int, bool(*) (T, T));
	static void insertionSort(T[], int, bool(*) (T, T));
	static void selectionSort(T[], int, bool(*) (T, T));

	static bool asc(T, T);
	static bool des(T, T);
};


template <class T>
bool Ordenamiento<T>::asc(T a, T b)
{
	return a > b;
}

template <class T>
bool Ordenamiento<T>::des(T a, T b)
{
	return a < b;
}

template <class T>
void Ordenamiento<T>::bubbleSort(T arreglo[], int n, bool compara(T, T))
{
	T temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (compara(arreglo[j - 1], arreglo[j]))
			{
				temp = arreglo[j - 1];
				arreglo[j - 1] = arreglo[j];
				arreglo[j] = temp;
			}
		}
	}
}

template <class T>
void Ordenamiento<T>::insertionSort(T arreglo[], int n, bool compara(T, T))
{
	T index;
	for (int i = 1; i < n; i++)
	{
		index = arreglo[i];
		int j = i - 1;
		while (j >= 0 && compara(arreglo[j], index))
		{
			arreglo[j + 1] = arreglo[j];
			j--;
		}
		arreglo[j + 1] = index;
	}
}

template <class T>
void Ordenamiento<T>::selectionSort(T arreglo[], int n, bool compara(T, T))
{
	int minimo = 0;
	T temp;

	for (int i = 0; i < n - 1; i++)
	{
		minimo = i;
		for (int j = i + 1; j < n; j++)
		{
			if (compara(arreglo[minimo], arreglo[j]))
				minimo = j;
		}
		temp = arreglo[minimo];
		arreglo[minimo] = arreglo[i];
		arreglo[i] = temp;
	}
}