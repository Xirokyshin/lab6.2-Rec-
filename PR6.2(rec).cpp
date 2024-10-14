//lab6.2(rec).cpp
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int* r, const int size, const int Low, const int High, int i)
{
	if (i < size) {
		r[i] = Low + rand() % (High - Low + 1);
		Create(r, size, Low, High, i + 1);
	}
}

void Print(int* r, const int size, int i)
{
	if (i < size) {
		cout << setw(4) << r[i];
		Print(r, size, i + 1);
	}
	else {
		cout << endl;
	}
}

// Функція для підрахунку кількості парних елементів
int CountEven(int* r, const int size, int i)
{
	if (i >= size) // базовий випадок
		return 0;

	// Якщо елемент парний, додаємо 1, інакше 0
	return (r[i] % 2 == 0) + CountEven(r, size, i + 1);
}

// Функція для пошуку найменшого парного елемента
int MinEven(int* r, const int size, int i, int min)
{
	if (i >= size) // базовий випадок
		return min;

	if (r[i] % 2 == 0 && r[i] < min) // якщо елемент парний і менший за поточний мінімум
		min = r[i];

	return MinEven(r, size, i + 1, min); // рекурсивний виклик для наступного елемента
}

int main()
{
	srand((unsigned)time(NULL));
	const int n = 30;
	int r[n];
	int Low = 1;
	int High = 200;

	Create(r, n, Low, High, 0); // Створення масиву
	Print(r, n, 0); // Виведення масиву

	int evenCount = CountEven(r, n, 0); // Підрахунок кількості парних елементів
	cout << "Kilkistb parnix elementiv = " << evenCount << endl;

	// Ініціалізуємо мінімальне значення яке більше за максимальне можливе значення (щоб запобігти помилки)
	int minEven = 201;
	minEven = MinEven(r, n, 0, minEven); // Пошук найменшого парного елемента

	if (minEven <= 200) { // Перевірка чи знайдено парний елемент
		cout << "Naimenshii parniy element = " << minEven << endl;
	}
	else {
		cout << "Parnix nemaye" << endl;
	}

	return 0;
}
