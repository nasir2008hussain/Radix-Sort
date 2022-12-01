#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int max_size(string arr[], int size)
{
    string arr2[size];
    for (int i = 0; i < size; i++)
    {
        arr2[i] = arr[i];
    }
    int max = arr[0].length();
    for (int i = 1; i < size; i++)
    {
        if (arr[i].length() > max)
        {
            max = arr[i].length();
        }
    }
    return max;
}

int extract_string(int position)
{
    int temp1;
    temp1 = position % 27;
    return temp1;
}

void setArray(string arr[], int size, int max_size)
{
    int length = size;
    int k = max_size;

    for (int j = 0; j < size; j++)
    {
        string temp1 = "";
        string temp2 = "";
        temp2 += arr[j];
        transform(temp2.begin(), temp2.end(), temp2.begin(), ::toupper);
        string temp3 = "";
        if (temp2.length() < k)
        {
            int rem = k - temp2.length();
            for (int y = 0; y < rem; y++)
            {
                temp3 += "@";
            }
            temp1 = temp2 + temp3;
        }
        else
        {
            temp1 += temp2;
        }
        arr[j] = temp1;
    }
}
void radix_sort(string arr[], int max_size, int size, string arr1[])
{
    queue<string> myQueue[27];
    int length = size;
    int k = max_size;
    int m;
    for (int p = (k - 1); p >= 0; p--)
    {
        for (int j = 0; j < length; j++)
        {
            string temp = "";
            temp += arr[j];
            char ch = temp[p];
            if (ch == '@')
            {
                int q=26;
                myQueue[q].push(arr[j]);
            }
            else
            {
                int numVal = (int)(ch - 'A' + 1);
                int q = extract_string(numVal);
                myQueue[q].push(arr[j]);
            }
        }
        m = 0;
        for (int i = 0; i <= 26; i++)
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

void print(string arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i].erase(std::remove(arr[i].begin(), arr[i].end(), '@'), arr[i].end());
        transform(arr[i].begin(), arr[i].end(), arr[i].begin(), ::tolower);
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    string arr[] = {"pakistan", "colombia", "nigeria", "comoros", "switzerland", "germany"};
    int size = sizeof(arr) / sizeof(string);
     cout << "\n---------------------------------------------------\n";
     cout<<"Nasir Hussain\n04072013040\nAssignment : ANALYSIS AND DESIGN OF ALGORITHM\n";
    cout << "\n---------------------------------------------------\n";
    cout << "BEFORE REDIX SORT\n";
    cout << "---------------------------------------------------\n";
    print(arr, size);
    string arr1[size];
    for (int i = 0; i < size; i++)
    {
        arr1[i] = arr[i];
    }
    int max_string = max_size(arr, size);
    setArray(arr, size, max_string);
    radix_sort(arr, max_string, size, arr1);
    cout << "\n---------------------------------------------------\n";
    cout << "BEFORE REDIX SORT\n";
    cout << "---------------------------------------------------\n";
    print(arr, size);
    cout << endl;
    return 0;
}