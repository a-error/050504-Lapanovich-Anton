#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Russian");
	int i, j, k, a[2][3], b[3][2], c[2][2] = {0};
	int str1 = 2, str2 = 3, stolb1 = 3, stolb2 = 2;
	printf_s("������� �������� ������ �������: ");
		for (i = 0; i < str1; i++) {
			for (j = 0; j < stolb1; j++) scanf_s("%d", &a[i][j]); // ���������� ��. ��. 1-�� �������
	    }
		printf_s("������� �������� ������ �������: ");
		for (i = 0; i < str2; i++) {
			for (j = 0; j < stolb2; j++) scanf_s("%d", &b[i][j]); // ���������� ��. ��. 2-�� �������
		}
		for (i = 0; i < str1; i++) {
			for (j = 0; j < stolb2; j++) {
				for (k = 0; k < stolb1; k++) c[i][j] += a[i][k] * b[k][j]; // ������������ ������, ���������� ��. ��. ��������� 3-�� �������
			}
		} printf_s("������������ ������ �����:\n");
		for (i = 0; i < str1; i++) {
			for (j = 0; j < stolb2; j++) {
				printf_s("%d\t", c[i][j]);
			} printf_s("\n");
		}
	return 0;
	}
