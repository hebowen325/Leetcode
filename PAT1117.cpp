#include<iostream>
#include<algorithm>
using namespace std;
int num[100001];
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",num+i);
    }
    sort(num,num+N);
    int ans;
    int i;
    for(i=N-1;num[i]>N-i;i--);
    cout<<N-i-1;
    return 0;
}