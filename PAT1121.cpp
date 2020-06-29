#include<iostream>
#include<vector>
using namespace std;
int N,M;
int couple[100000]={-1};
int party[100000]={-1};
int main()
{
    int s1,s2;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d %d",&s1,&s2);
        couple[s1]=s2;
        couple[s2]=s1;
    }
    scanf("%d",&M);
    s2=-1;
    for(int i=0;i<M;i++)
    {
        scanf("%d",&s1);
        party[s1]=1;
        s2=max(s2,s1);
    }
    vector<int> Vec;
    for(int i=0;i<=s2;i++)
    {
        if(party[i]==1)
        {
            if(couple[i]==-1||party[couple[i]]==-1)
            {
                Vec.push_back(i);
            }
        }
    }
    printf("%d\n",Vec.size());
    for(int i=0;i<Vec.size();i++)
    {
        printf("%05d",Vec[i]);
        if(i+1!=Vec.size())
        {
            printf(" ");
        }
    }
    return 0;
}