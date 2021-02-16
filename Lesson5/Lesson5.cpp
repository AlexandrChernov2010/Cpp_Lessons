#include <iostream>

using namespace std;

int swap_myAarr (int number)
{
 if (number == 1) return 0;
    else if (number == 0) return 1;
}
int Fill_myArr (int Arr[], int size_Arr)
{
    int number = 1;
    for (int i = 0; i < size_Arr; i++)
    {
        Arr[i] = number;
        number += 3;
    }
    return Arr[0];
}


int main()
{
    //5.1

    int myArr[10] = {1, 1, 0, 0, 1, 0, 1, 1, 0, 0};
    for (int i = 0; i < (sizeof(myArr) / sizeof(int)); i++)
    {
        myArr[i] = swap_myAarr(myArr[i]);
        cout << myArr[i] << " ";
    }


    //5.2

    int myArr_int[8] = {0};
    myArr_int[0] = Fill_myArr(myArr_int, (sizeof(myArr) / sizeof(int)));
    cout << endl;
    for (int k = 0; k < (sizeof(myArr_int) / sizeof(int)); k++)
    {
        cout << myArr_int[k] << " ";
    }


    return 0;
}
