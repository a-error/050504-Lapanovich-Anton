#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Russian");
	int n, i, sum1, sum2, k, k1, k2, mass[100];
	sum1 = sum2 = k = k1 = k2 = 0;
	do {
		printf_s("������� ���������� ����������� �����: ");
		scanf_s("%d", &n);
	}
	while (n > 100); // ������ ����. �����
	printf_s("���� �����\n");
	for (i = 0; i < n; i++) {
		mass[i] = rand() % 21 - 10; // �������������� ��. ��. �������
		printf_s("%d ", mass[i]);
	}
	for(i = 0; i < n; i++) {
		if (mass[i] > 0) {
			k++;
			sum1 += mass[i]; // �������� ������������� �����, ������� ����� � ����������
		}
		else if (mass[i] < 0) {
			sum2 += mass[i];
			k1++; // �������� ������������� �����, ������� ����� � ����������
		}
		else k2++; // ������� �����
	}
	printf_s("\n");
	printf_s("����� ������������� �����: %d\n����� ������������� �����: %d\n", sum1, sum2);
	printf_s("���������� ������������� �����: %d\n ���������� ������������� �����: %d\n ���������� �����: %d", k, k1, k2); 
	
	return 0;
}