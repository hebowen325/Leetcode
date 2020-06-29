#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int num[10001];
int matrix[1001][101];
bool cmp(const int &a,const int &b)
{
    return a>b;
}
int main()
{
    int N,m,n;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",num+i);
    }
    sort(num,num+N,cmp);
    for(int m=N;m>=sqrt(N);m--)
    {
        if(N%m==0)
        {
            n=N/m;
        }
    }
    m=N/n;
    int count=0;
    for(int i=0;count<N;i++)
    {
        for(int j=0;j<n-2*i&&count<N;j++)
        {
            matrix[i][i+j]=num[count++];
        }
        for(int j=1;j<m-2*i-1&&count<N;j++)
        {
            matrix[i+j][n-1-i]=num[count++];
        }
        for(int j=0;j<n-2*i&&count<N;j++)
        {
            matrix[m-1-i][n-1-i-j]=num[count++];
        }
        for(int j=1;j<m-2*i-1&&count<N;j++)
        {
            matrix[m-1-i-j][i]=num[count++];
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("%d",matrix[i][n-1]);
        if(i<m-1)
        {
            printf("\n");
        }
    }
    return 0;
}