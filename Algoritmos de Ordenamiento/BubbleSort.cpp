//
// Created by davepj007 on 20/09/18.
//

#include "BubbleSort.h"

void BubbleSort::swapping(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void BubbleSort::bubbleSort(int *arr, int size) {
    int i, j;
    for (i = 0; i < size-1; i++)
        // Last i elements are already in place
        for (j = 0; j < (size-i)-1; j++)
            if (arr[j] > arr[j+1])
                swapping(&arr[j], &arr[j+1]);
}