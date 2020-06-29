#include<iostream>
#include<stack>
using namespace std;
int matrix[200][200];
int mark[200]={0};
int main()
{
    fill(matrix[0],matrix[0]+200*200,-1);
    int N,M;
    scanf("%d %d",&N,&M);
    int parent,K,children;
    for(int i=0;i<M;i++)
    {
        scanf("%d %d",&parent,&K);
        matrix[parent][0]=0;
        for(int j=0;j<K;j++)
        {
            scanf("%d",&children);
            matrix[parent][children]=1;
        }
    }
    mark[1]=1;
    for(int i=1;i<=N;i++)
    {
        parent=i;
        if(matrix[parent][0]==0)
        {
            stack<int> S1;
            stack<int> S2;
            for(int j=1;j<=N;j++)
            {
                if(matrix[parent][j]==1)
                {
                    mark[j]=mark[parent]+1;
                    if(matrix[j][0]==0)
                        S1.push(j);
                }
            }
            matrix[parent][0]=-1;
            while(!S1.empty())
            {
                S2=S1;
                S1=stack<int>();
                while(!S2.empty())
                {
                    parent=S2.top();
                    S2.pop();
                    for(int j=1;j<=N;j++)
                    {
                        if(matrix[parent][j]==1)
                        {
                            mark[j]=mark[parent]+1;
                            if(matrix[j][0]==0)
                                S1.push(j);
                        }
                    }
                    matrix[parent][0]=-1;
                }
            }
        }
    }
    int ord[200]={0};
    for(int i=1;i<=N;i++)
    {
        ord[mark[i]]++;
    }
    int largest=-1;
    int largest_place;
    for(int i=1;i<=N;i++)
    {
        if(largest<ord[i])
        {
            largest=ord[i];
            largest_place=i;
        }
    }
    cout<<largest<<" "<<largest_place;
    return 0;
}