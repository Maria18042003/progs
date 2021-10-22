#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcs.h"
#define LEN 80000

// 112 Карягина Мария Алексеевна
// Вводим размеры массива, время
int main(void) {
	char generfile[120];		
	char sortfile[120];			
	int n = 5000;				
	double mas[LEN];			
	clock_t  start, end;		
	int i, j;					
	float bubtime, qtime;		
	FILE* file;					

	for (j = 0; j < 5; j++) {							//  Увеличение массива
														
		printf("Enter the path to the file to store the generated array:\n");    // Путь файла к массиву
		scanf("%s", generfile);

		if (gener_mas(generfile, n)) {					
			printf("Error opening file\n");				// если файл не открылся, выведется 1
			return 1;
		}

		if (read_file(generfile, mas, n)) {				
			printf("Could not open file\n");			// если все в порядке, выводится 0
			return 1;
		}
		
		start = clock();								// засекаем время
		bubblesort(mas, n);								
		end = clock();									
		bubtime = (float)(end - start) / CLOCKS_PER_SEC;		// чтобы получить секунды делим на константу
		if (sort_check(mas, n)) {						
			printf("Array was not bubble sorted\n");	
			return 1;									
		}
		else printf("Array was bubble sorted\n");		

		if (read_file(generfile, mas, n)) {				
			printf("Could not open file\n");			
			return 1;
		}
		
		start = clock();								
														
		qsort(mas, n, sizeof(double), (int(*)(const void*, const void*))compare);
		end = clock();									
		qtime = (float)(end - start) / CLOCKS_PER_SEC;			
		if (sort_check(mas, n)) {						
			printf("Array was not quick sorted\n");		
			return 1;									
		}
		else printf("Array was quick sorted\n");		
														
		printf("Enter the file path to store the sorted array:\n");
		scanf("%s", sortfile);
		if ((file = fopen(sortfile, "w")) == 0) {		
			printf("Error opening file\n");				
			return 1;
		}

		for (i = 0; i < n; i++) {
			fprintf(file, "%lf ", mas[i]);
			if ((i + 1) % 10 == 0) fprintf(file, "%c", '\n');	
		}
		fclose(file);

		printf("Number of array elements: %d\n", n);
		printf("Bubble sort time(sec): %f\n", bubtime);
		printf("Q-sort sort time(sec): %f\n\n", qtime);

		n *= 2;										
			}

	return 0;
}

// Карягина Мария Алексеевна 112