


// Карягина Мария 112 группа

#include <stdio.h>
#define MAXLEN 100 // Задаем максимальный размер массива

// Задача 7, дз 2
// какое число в массиве встречается наибольшое количество раз (использование массивов)

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
    int max_freq = 0;   
    int n_max_freq = 0;
    for (int i = 0; i<size; i++) {
        int freq = 0;
        for (int j = 0; j<size; j++) {
            if (numbers[i] == numbers[j]){
                freq++;
            }
        }
        
        if (freq>max_freq){
            max_freq = freq;
            n_max_freq = numbers[i];
        }
    }
    
    return n_max_freq;
}