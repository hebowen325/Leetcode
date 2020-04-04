#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int matrix[201][201];
int N,M,K;
int main()
{
    fill(matrix[0],matrix[0]+201*201,0);
    scanf("%d %d",&N,&M);
    int node1,node2;
    for(int i=0;i<M;i++)
    {
        scanf("%d %d",&node1,&node2);
        matrix[node1][node2]=matrix[node2][node1]=1;
    }
    scanf("%d",&K);
    int n,tmp;
    for(int i=0;i<K;i++)
    {
        vector<int> Vec;
        scanf("%d",&n);
        bool flag=true;
        for(int j=0;j<n;j++)
        {
            scanf("%d",&tmp);
            Vec.push_back(tmp);
        }
        if(n!=N+1||Vec[0]!=Vec[Vec.size()-1])
        {
            printf("NO\n");
        }
        else
        {
            int nodes[201]={0};
            nodes[Vec[0]]=1;
            for(int t=0;t<N;t++)
            {
                if(matrix[Vec[t]][Vec[t+1]]!=1)
                {
                    printf("NO\n");
                    flag=false;
                    break;
                }
                else
                {
                    if(nodes[Vec[t+1]]==1&&t!=N-1)
                    {
                        printf("NO\n");
                        flag=false;
                        break;
                    }
                    else
                    {
                        nodes[Vec[t+1]]=1;
                    }
                }
            }
            if(flag)
            {
                printf("YES\n");
            }
        }
    }
    return 0;
}