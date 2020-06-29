#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int quo[110];
bool cmp(const int* a,const int* b)
{
    if(a[0]+a[1]!=b[0]+b[1])
        return a[0]+a[1]>b[0]+b[1];
    else
        return a[0]>b[0];
}
int main()
{
    int N,M,K;
    scanf("%d %d %d",&N,&M,&K);
    int** stu=new int* [N];
    for(int i=0;i<N;i++)
        stu[i]=new int [K+4];
    for(int i=0;i<M;i++)
        scanf("%d",quo+i);
    for(int i=0;i<N;i++)
    {
        scanf("%d %d",stu[i],stu[i]+1);
        for(int j=0;j<K;j++)
            scanf("%d",stu[i]+j+2);
        stu[i][K+3]=i;
    }
    sort(stu,stu+N,cmp);
    stu[0][K+2]=0;
    for(int i=1;i<N;i++)
    {
        if(stu[i][0]+stu[i][1]==stu[i-1][0]+stu[i-1][1]&&stu[i][0]==stu[i-1][0])
            stu[i][K+2]=stu[i-1][K+2];
        else
            stu[i][K+2]=i;
    }
    vector<int>* Vec=new vector<int> [M];
    int* last=new int [M];
    fill(last,last+M,-1);
    int count=0;
    while(count<N)
    {
        for(int i=0;i<K;i++)
        {
            if(quo[stu[count][i+2]]>0)
            {
                last[stu[count][i+2]]=stu[count][K+2];
                quo[stu[count][i+2]]--;
                Vec[stu[count][i+2]].push_back(stu[count][K+3]);
                break;
            }
            else if(stu[count][K+2]==last[stu[count][i+2]])
            {
                Vec[stu[count][i+2]].push_back(stu[count][K+3]);
                break;
            }
        }
        count++;
    }
    for(int i=0;i<M;i++)
    {
        if(Vec[i].size()!=0)
        {
            sort(Vec[i].begin(),Vec[i].end());
            printf("%d",Vec[i][0]);
            for(int j=1;j<Vec[i].size();j++)
                printf(" %d",Vec[i][j]);
        }
        printf("\n");
    }
    return 0;
}