#include<iostream>
using namespace std;

#define MAXVALUE 100
#define MAXLEAF 30
#define MAXNODE  MAXLEAF*2-1
#define MAXBIT 10

typedef struct
{
    int weight;     //权值
    int parent;     //双亲节点
    int lchild;     //左孩子
    int rchild;     // 右孩子
}HNodeType;

typedef struct
{
    int bit[MAXBIT];
    int start;
}HCodeType;

void HuffmanTree(HNodeType HuffNode[],int n)
{
    int i,j,m1,m2,x1,x2;
    
    for(i = 0;i < 2*n-1;i++)     //对数组进行初始化
    {
        HuffNode[i].weight = 0;
        HuffNode[i].parent = -1;
        HuffNode[i].lchild = -1;
        HuffNode[i].rchild = -1;
    }
    for(i = 0;i < n;i++)  //输入各个节点的权值
    {
        cout<<"输入第"<<i<<"个叶节点的权值："<<endl;
        cin>>HuffNode[i].weight;
    }
    for(i = 0;i < n-1;i++)  //构造哈夫曼树
    {
        m1 = MAXVALUE;
        m2 = MAXVALUE;
        x1 = x2 = 0;
        for(j = 0;j < n + i;j++)  //找出两棵权值最小的树
        {
            if(HuffNode[j].weight < m1&&HuffNode[j].parent == -1)
            {
                m2 = m1;
                x2 = x1;
                m1 = HuffNode[j].weight;
                x1 = j;
            }
            else if(HuffNode[j].weight < m2&&HuffNode[j].parent == -1)
            {
                m2 = HuffNode[j].weight;
                x2 = j;
            }
        }
        HuffNode[x1].parent = n + i;   //合并两个子树
        HuffNode[x2].parent = n + i;
        HuffNode[n+i].weight = HuffNode[x1].weight + HuffNode[x2].weight;
        HuffNode[n+i].lchild = x1;
        HuffNode[n+i].rchild = x2;
        
    }
}

void HaffmanCode()        //哈夫曼编码
{
    HNodeType HuffNode[MAXNODE];
    HCodeType HuffCode[MAXLEAF],cd;
    int i,j,c,p,n;
    cout<<"输入节点的个数："<<endl;   //输入节点的个数
    cin>>n;
    HuffmanTree(HuffNode,n);
    for(i = 0;i < n;i++)
    {
        cd.start = n - 1;
        c = i;
        p = HuffNode[c].parent;
        while(p != -1)
        {
            if(HuffNode[p].lchild == c)
                cd.bit[cd.start] = 0;
            else
                cd.bit[cd.start] = 1;
            cd.start--;
            c = p;
            p = HuffNode[c].parent;
        }
        for(j = cd.start+1;j < n;j++)
            HuffCode[i].bit[j] = cd.bit[j];	
        HuffCode[i].start = cd.start;
    }
    cout<<"哈夫曼编码为："<<endl;
    for(i = 0;i < n;i++)
    {
        for(j = HuffCode[i].start + 1;j < n;j++)
            cout<<HuffCode[i].bit[j];	
        cout<<endl;
    }
}
int main(void)
{
    HaffmanCode();
    return 0;
}             
