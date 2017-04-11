//
//  main.cpp
//  二分查找
//
//  Created by Yifu Zhou on 6/16/15.
//  Copyright (c) 2015 Yifu Zhou. All rights reserved.
//

#include <iostream>
using namespace std;

void BinSearch (int a[], int n, int key)
{
    int low = 1, high = n, mid = 0;
    while (low< high)
    {
        int m;
        m = (low + high)%2;
        if (m == 0)
        {
            mid = (low + high)/2;
        }
        else if (m ==1)
        {
            mid = (low +high +1)/2;
        }
        
        if (a[mid] == key)
        {
            break;
        }
        if (a[mid]>key)
        {
            high = mid;
        }
        if (a[mid]<key)
        {
            low = mid;
        }
    }
    cout<< mid;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n = 10;
    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    BinSearch(A, n, 7);
    return 0;
}
