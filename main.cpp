//
//  main.cpp
//  排序算法
//
//  Created by Yifu Zhou on 6/16/15.
//  Copyright (c) 2015 Yifu Zhou. All rights reserved.
//

#include <iostream>
using namespace std;

void InsertSort (int a[], int n)
{
    int i, j;
    int temp;
    for (i = 1; i<n; i++)
    {
        temp = a[i];
        j = i-1;
        while (j>= 0 && a[j]>= temp)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
    for (int m = 0; m<n; m++)
    {
        cout<< a[m]<<"  ";
    }
    
}

void BubbleSort (int a[], int n)
{
    int i, j;
    int temp;
    for (i=0; i< n-1; i++)
    {
        for (j=n-1; j>i; j--)
        {
            if (a[j]<a[j-1])
            {
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }
    for (int m = 0; m<n; m++)
    {
        cout<< a[m]<<"  ";
    }

    
}
int main(int argc, const char * argv[])
{
    int n = 6;
    int A[] = { 6, 5, 4, 3, 2, 1};
    InsertSort (A, n);
    BubbleSort(A, n);
}

