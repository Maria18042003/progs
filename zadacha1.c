// Карягина Мария 112 группа

#include <stdio.h>

// Задача №10 Определить количество различных элементов
// целой неубывающей последовательности.

int processing(FILE * fin);

int main(void) {
    char filen[120];
    int result;

    printf("Enter file name: "); // Спрашиваем имя файла
    scanf("%s", filen);

    FILE * file = fopen(filen, "r");
    if (!file) {
        printf("Unable to open file %s\n", filen); // открываем файл и проверяем успешность открытия
        return 1;
    }

    result = processing(file);

    if (result == -1) {
        printf("Invalid sequence"); // Если первое число не считано - последовательность некорректна
        return -1;
    }

    printf("%d\n", result);
    return 0;
}

int processing(FILE * fin) {
    int number;
    int number_prev; // Предыдущее число для сравнения
    int answer = 0;

    if (fscanf(fin, "%d", &number_prev) != 1) { // Формат последовательности неправильный
        return -1;
    } else {
        answer++;
    }

    while (fscanf(fin, "%d", &number) == 1) {
        if (number > number_prev) {  // Последовательность не убывает, а значит если 
            answer++;                // число не равно предыдущему, то оно ранее не встречалось
        }
        number_prev = number;        // Текущее число становится предыдущим
    }
    return answer;
}