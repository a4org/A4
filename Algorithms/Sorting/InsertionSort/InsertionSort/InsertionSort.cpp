#include <iostream>
#include <vector>
#include "InsertionSort.h"

using namespace::std;

// function start
// using array (more efficient)
int (*arr_insertion_sort(int (&arr)[ARRAY_SIZE]))[ARRAY_SIZE]
{
    for (int* p = begin(arr)+2; p < end(arr); p++)
    {
        int key = *p;
        int *mp = p - 1;
        while(mp >= begin(arr) && *mp > key)
        {
            *(mp+1) = *mp;
            mp--;
            if(mp == begin(arr)-1) // access the illegal memory
                break;
        }
        *(mp+1) = key;
    }
    return &arr;
}

// using vector (more flexible)
vector<int> vec_insertion_sort(vector<int> vec)
{
    int size = vec.size();
    for (auto i = 2; i < size; i++)
    {
        int key = vec[i]; 
        int j = i - 1;
        while (j >= 0 && vec[j] > key)
        {
            vec[j+1] = vec[j];
            j--;
            if(j == -1)
                break;
        }
        vec[j+1] = key;
    }
    return vec;
}
