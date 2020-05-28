#include<iostream>
#include<vector>
using namespace std;
typedef struct TreeNode
{
    int Level;
    vector<int> son;
    int father;
    TreeNode():Level(-1),father(-1){}
}TreeNode;
TreeNode Arr[100];
int C[100]={0};
int caculate_level(int id)
{
    if(Arr[id].Level==-1)
    {
        Arr[id].Level=caculate_level(Arr[id].father)+1;
    }
    return Arr[id].Level;
}
int main()
{
    Arr[1].father=0;
    Arr[1].Level=1;
    int N,M,maxLevel=0;
    scanf("%d%d",&N,&M);
    if(N==1)
    {
        printf("1");
        return 0;
    }
    for(int i=0;i<M;i++)
    {
        int ID,K,s;
        scanf("%d%d",&ID,&K);
        for(int j=0;j<K;j++)
        {
            scanf("%d",&s);
            Arr[ID].son.push_back(s);
            Arr[s].father=ID;
        }
    }
    for(int i=2;i<=N;i++)
    {
        caculate_level(i);
        if(Arr[i].son.empty())
        {
            C[Arr[i].Level]++;
        }
        maxLevel=max(maxLevel,Arr[i].Level);
    }
    printf("0");
    for(int i=2;i<=maxLevel;i++)
    {
        printf(" %d",C[i]);
    }
    return 0;
}