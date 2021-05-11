#include <cstdint>
#include <iostream>
#include <vector>

#include "InsertionSort/InsertionSort.h"

using namespace::std;

int main()
{
    // Test arr_insertion_sort
    int sample[ARRAY_SIZE] = {6,3,10,5,6,4,7,9,8,2};
    cout << "Test arr_insertion_sort(), with arr:" << endl;
    cout << "{ ";
    for (int i : sample)
    {
        cout << i << " ";
    }
    cout << " }" << endl;

    cout << endl;

    cout << "............" << endl;
    int (*testarr)[ARRAY_SIZE] = arr_insertion_sort(sample);
   

    cout << endl;

    cout << "{ ";
    for (int i : *testarr)
    {
        cout << i << " ";
    }
    cout << " }" << endl;


    // Test vec_insertion_sort
    cout << "Test vec_insertion_sort(), with the value you input: " << endl;
    int i;
    vector<int> iv;
    while (cin >> i)
        iv.push_back(i);
    cout << "{ ";
    for (int i : iv)
    {
        cout << i << " ";
    }
    cout << " }" << endl;

    cout << "............" << endl;
    vector<int> vit = vec_insertion_sort(iv);

    
    cout << endl;

    cout << "{ ";
    for (int i : vit)
    {
        cout << i << " ";
    }
    cout << " }" << endl;
    
    return 0;
}
