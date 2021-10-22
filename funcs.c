#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 112 Карягина Мария
int compare(const double* i, const double* j) {
	if (*j > *i) return 1;
	if (*j < *i) return -1;
	return 0;
}

// 112 Карягина Мария Алексеевна
//  проверка отсортированного массива по возрастанию
int sort_check(double a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		if (a[i] < a[i + 1]) return 1;
	}
	return 0;
}

// 112 Карягина Мария Алексеевна
// сортировка пузырьком
void bubblesort(double a[], int n) {
	int i, j;
	double tmp;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (a[j] < a[j + 1]) {
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

// 112 Карягина Мария Алексеевна
// чтение файла
int read_file(char filename[], double a[], int n) {
	FILE* file;
	if ((file = fopen(filename, "r")) == 0) return 1;
	for (int i = 0; i < n; i++) {
		fscanf(file, "%lf", &a[i]);
	}
	fclose(file);
	return 0;
}

// 112 Карягина Мария Алексеевна
int gener_mas(char filename[], int n) {
	FILE* file;
	if ((file = fopen(filename, "w")) == 0) return 1;
	srand(time(NULL));									//  база текущего времени
	for (int i = 0; i < n; i++) {
		fprintf(file, "%lf ", ((double)rand() / RAND_MAX) * 20 - 10.0);
		if ((i + 1) % 10 == 0) fprintf(file, "%c", '\n');
	}
	fclose(file);
	return 0;
}