//
//  main.cpp
//  图的深度遍历
//
//  Created by Yifu Zhou on 6/12/15.
//  Copyright (c) 2015 Yifu Zhou. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
#define N 8
int a[N][N] =
{
    { 0, 1, 1, 0, 0, 0, 0, 0 },
    { 1, 0, 0, 1, 1, 0, 0, 0 },
    { 1, 0, 0, 0, 0, 1, 1, 0 },
    { 0, 1, 0, 0, 0, 0, 0, 1 },
    { 0, 1, 0, 0, 0, 0, 0, 1 },
    { 0, 0, 1, 0, 0, 0, 0, 1 },
    { 0, 0, 1, 0, 0, 0, 0, 1 },
    { 0, 0, 0, 1, 1, 1, 1, 0 }
};  //Creating an adjacency matrix

int tag[8]={0, 0, 0, 0, 0, 0, 0, 0};


int FirstAdj(int v)
{
    
    int j= 0;
    if(v <8)
    {
        while( a[v-1][j]!=1 || (a[v-1][j] ==1&& tag[j] == 1))
        {
            j++;
        }
        j++;
    }
    else j = 9;
    return j;
}

int NextAdj(int v, int w)
{
    int j = w;
    
        while (a[v-1][j] != 1||(a[v-1][j] ==1&& tag[j] == 1))
        {
            if(j <8)
            {j++;}
            if(j >=8)
            {j =9;break;}
        }
        j++;
    
    
    return j;
    
}

void DFS(int v)
{
    tag[v-1] = 1;
    cout<<v<<"-> ";
    int w = FirstAdj(v);
    
    while (w < 9)
    {
        if (tag[w-1]==0)
        {
            DFS(w);
        }
        w =NextAdj(v, w);
    }
}
int main(int argc, const char * argv[]) {
    
    // insert code here...
    
    DFS(1);
    //DFS(3);
    //DFS(4);
    cout<<"end";
    return 0;
}






