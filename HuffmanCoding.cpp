//
//  main.cpp
//  哈夫曼编码
//
//  Created by Yifu Zhou on 6/17/15.
//  Copyright (c) 2015 Yifu Zhou. All rights reserved.
//

#include <iostream>
using namespace std;

#define N 50
struct HTNode
{
    char data;
    double weight;
    int parent;
    int lchild;
    int rchild;
};

struct HCode
{
    char cd[N];
    int start;
};

void CreateHT ()
{
    int i, k, lnode, rnode;
    double min1, min2;
    
    int n = 8;
    HTNode ht[2*n-1];
    ht[0].weight = 5;
    ht[1].weight = 29;
    ht[2].weight = 7;
    ht[3].weight = 8;
    ht[4].weight = 14;
    ht[5].weight = 23;
    ht[6].weight = 3;
    ht[7].weight = 11;
    
    for (int i = 0; i<2*n-1; i++)
        ht[i].parent = ht[i].lchild = ht[i].rchild = -2;

   
    for (i = n; i<2*n-1; i++)
    {
        min1 = min2 = 6666;
        lnode = rnode = -2;
        for (k = 0; k<i-1; k++)
        {
            if (ht[k].parent== -2)
            {
                if (ht[k].weight< min1)
                {
                    min2 = min1; rnode = lnode;
                    min1 = ht[k].weight; lnode = k;
                }
                if (ht[k].weight< min2)
                {
                    min2 = ht[k].weight; rnode = k;
                }
            }
            ht[i].weight = ht[lnode].weight + ht[rnode].weight;
            ht[i].lchild = lnode; ht[i].rchild = rnode;
            ht[lnode].parent = i; ht[rnode].parent = i;
        }
    }
}

void CreateHCode (HTNode ht[], HCode hcd[], int n)
{
    int i, f, c;
    HCode hc;
    for (i = 0; i<n; i++)
    {
        hc.start = n;
        c = i;
        f = ht[i].parent;
        while (f!= -2)
        {
            if (ht[f].lchild==c)
                hc.cd[hc.start--] = '0';
            else
                hc.cd[hc.start--] = '1';
            c = f; f = ht[f].parent;
        }
        hc.start++;
        hcd[i] = hc;
    }
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n = 8;
    HTNode ht[2*n-1];
    ht[0].weight = 5;
    ht[1].weight = 29;
    ht[2].weight = 7;
    ht[3].weight = 8;
    ht[4].weight = 14;
    ht[5].weight = 23;
    ht[6].weight = 3;
    ht[7].weight = 11;
    for (int i = 0; i<2*n-1; i++)
        ht[i].parent = ht[i].lchild = ht[i].rchild = -2;

    //HCode hcd[n];
    CreateHT();
   // CreateHCode(ht, hcd, n);
    
    return 0;
}
