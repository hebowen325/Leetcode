#include<iostream>
#include<algorithm>
#include"limits.h"
using namespace std;
int num[100001];
int Left[100001];
int Right[100001];
int arr[100001];
int main()
{
    int N;
    scanf("%d",&N);
    int max=INT_MIN;
    for(int i=0;i<N;i++)
    {
        scanf("%d",num+i);
        if(i<N-1)
        {
            if(max<num[i])
            {
                max=num[i];
            }
            Left[i+1]=max;
        }
    }
    int min=INT_MAX;
    for(int i=N-1;i>0;i--)
    {
        if(min>num[i])
        {
            min=num[i];
        }
        Right[i-1]=min;
    }
    Left[0]=-1;
    Right[N-1]=INT_MAX;
    int count=0;
    for(int i=0;i<N;i++)
    {
        if(num[i]>=Left[i]&&num[i]<=Right[i])
        {
            arr[count++]=num[i];
        }
    }
    sort(arr,arr+count);
    printf("%d\n",count);
    if(count>0)
    {
        for(int i=0;i<count-1;i++)
        {
            printf("%d ",arr[i]);
        }
        printf("%d",arr[count-1]);
    }
    else
    {
        printf("\n");
    }
    return 0;
}