#include <stdio.h>
#include "headers.h"

int find_n_max_freq(int numbers[], int size) {
    int max_freq;   
    int n_max_freq;
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