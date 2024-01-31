//////////////////////////////////////////////////////////////////////////////////////////////////////
/// @file      max.cpp
/// @ingroup   Max values
/// @author    Adrian Cojocari
/// @date      31/01/2024
/// @brief     Insert here a short description
///
/// @copyright Copyright (C) Insert Here All Rights Reserved.
///////////////////////////////////////////////////////////////////////////////

#include "../headers/max.h"

void Max::sortArrayDesc(int *arr, int size)
{ 
    //sorting - ASCENDING ORDER
    for (int i = 0; i < size; i++) {
        for ( int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int Max::getMaxVal(int *arr, int size)
{ 
    int max = 0;
    for (int i = 0; i < size; i++) {
        if(i == 0 )
        {
            max = arr[i];
        }
        else
        {
            if(max < arr[i])
                max = arr[i];
        }
    }
    return max;
}
