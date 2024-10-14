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

// ������� ��� ��������� ������� ������ ��������
int CountEven(int* r, const int size, int i)
{
	if (i >= size) // ������� �������
		return 0;

	// ���� ������� ������, ������ 1, ������ 0
	return (r[i] % 2 == 0) + CountEven(r, size, i + 1);
}

// ������� ��� ������ ���������� ������� ��������
int MinEven(int* r, const int size, int i, int min)
{
	if (i >= size) // ������� �������
		return min;

	if (r[i] % 2 == 0 && r[i] < min) // ���� ������� ������ � ������ �� �������� �����
		min = r[i];

	return MinEven(r, size, i + 1, min); // ����������� ������ ��� ���������� ��������
}

int main()
{
	srand((unsigned)time(NULL));
	const int n = 30;
	int r[n];
	int Low = 1;
	int High = 200;

	Create(r, n, Low, High, 0); // ��������� ������
	Print(r, n, 0); // ��������� ������

	int evenCount = CountEven(r, n, 0); // ϳ�������� ������� ������ ��������
	cout << "Kilkistb parnix elementiv = " << evenCount << endl;

	// ���������� �������� �������� ��� ����� �� ����������� ������� �������� (��� �������� �������)
	int minEven = 201;
	minEven = MinEven(r, n, 0, minEven); // ����� ���������� ������� ��������

	if (minEven <= 200) { // �������� �� �������� ������ �������
		cout << "Naimenshii parniy element = " << minEven << endl;
	}
	else {
		cout << "Parnix nemaye" << endl;
	}

	return 0;
}
