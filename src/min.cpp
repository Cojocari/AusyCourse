#include "../headers/min.h"

void Min::sortArrayAsc(int *arr, int size)
{ 
    //sorting - ASCENDING ORDER
    for (int i = 0; i < size; i++) {
        for ( int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int Min::getMinVal(int *arr, int size)
{ 
    int min = 0;
    //sorting - ASCENDING ORDER
    for (int i = 0; i < size; i++) {
        if(i == 0 )
        {
            min = arr[i];
        }
        else
        {
            if(min > arr[i])
                min = arr[i];
        }
    }
    return min;
}
