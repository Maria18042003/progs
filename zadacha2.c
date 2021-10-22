// Карягина Мария 112 группа

#include <stdio.h>
#define MAXLEN 100 // Задаем максимальный размер массива

// Задача №10 Определить количество различных элементов
// целой неубывающей последовательности. (С использованием массивов)

int processing(int numbers[], int size);

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

    result = processing(numbers, index);

    printf("%d\n", result);
    return 0;
}

int processing(int numbers[], int size) {
    int answer = 1;
    for (int i = 1; i < size; i++) {
        if(numbers[i] > numbers[i-1]) { // в целой неубывающей последовательности достаточно сравнить число с предыдущим
            answer++; // если они различны, то стоящее позже число ранее не встречалось
        }
    }
    return answer;
}