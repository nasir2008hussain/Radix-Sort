#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int max_size(int arr[], int size)
{
    int arr2[size];
    for(int i=0;i<size;i++)
    {
        arr2[i]=arr[i];
    }
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        int count=0;
        while (arr2[i] > 0)
        {
            if ((arr2[i] % 10) >= 0)
            {
                count++;
            }
            arr2[i]=arr2[i]/10;
        }
        if(count>max)
        {
            max=count;
        }
    }
    return max;
}

int extract_digit(int digit, int position)
{
    int temp1;
    int temp2;
    temp1 = digit / pow(10, (position - 1.0));
    temp2 = temp1 % 10;
    return temp2;
}

void radix_sort(int arr[], int max_size, int size)
{
    queue<int> myQueue[10];
    int length = size;
    int k = max_size;
    int m;
    for (int p = 1; p <= k; p++)
    {
        for (int j = 0; j < length; j++)
        {
            int q = extract_digit(arr[j], p);
            myQueue[q].push(arr[j]);
        }
        m = 0;
        for (int i = 0; i < 9; i++)
        {
            while (!myQueue[i].empty())
            {
                arr[m] = myQueue[i].front();
                myQueue[i].pop();
                m++;
            }
        }
    }
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] <<" ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {123, 564, 2101, 10512, 703, 431, 220};
    int size = sizeof(arr) / sizeof(int);
    cout<<"Before Sort\n";
    print(arr, size);
    int max_digit = max_size(arr, size);
    radix_sort(arr, max_digit, size);
    cout<<"Before Sort\n";
    print(arr, size);
}