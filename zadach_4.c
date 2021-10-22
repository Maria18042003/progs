// Карягина Мария 112 группа

#include <stdio.h>
#include "headers.h"
#define MAXLEN 100 // Задаем максимальный размер массива

// Задача 7, дз 2
// какое число в массиве встречается наибольшое количество раз (использование массивов)

int main(void) {
    char filen[120];
    int result;
    int number;
    int numbers[MAXLEN];
    int index = 0;


    printf("Enter file name: "); // Спрашиваем имя файла
    scanf("%s", filen);

    FILE * file = fopen(filen, "r"); // открываем файл
    if (!file) {
        printf("Unable to open file %s\n", filen); // если не удалось открыть - сообщаем пользователю
        return 1;
    }

    while (fscanf(file, "%d", &number) == 1) {
        numbers[index] = number;
        
        if (index == MAXLEN-1) { // Сторож защищает массив от переполнения
            break; 
        }
        index++;
    }

    result = find_n_max_freq(numbers, index);
    
    printf("%d\n", result);
    return 0;
}

