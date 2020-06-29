#include<iostream>
#include<algorithm>
using namespace std;
int arr[100001];
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",arr+i);
    }
    sort(arr,arr+N);
    int s1=0,s2=0;
    if(N%2==1)
    {
        for(int i=0;i<N/2;i++)
        {
            s1+=arr[i];
        }
        for(int i=N/2;i<N;i++)
        {
            s2+=arr[i];
        }
        printf("%d %d",1,s2-s1);
    }
    else
    {
        for(int i=0;i<N/2;i++)
        {
            s1+=arr[i];
        }
        for(int i=N/2;i<N;i++)
        {
            s2+=arr[i];
        }
        printf("%d %d",0,s2-s1);
    }
    return 0;
}