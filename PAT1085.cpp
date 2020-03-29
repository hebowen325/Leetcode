#include<iostream>
#include<algorithm>
using namespace std;
long num[100001];
int main()
{
    int N;
    long p;
    scanf("%d",&N);
    scanf("%ld",&p);
    for(int i=0;i<N;i++)
    {
        scanf("%ld",&num[i]);
    }
    sort(num,num+N);
    int Max=-1;
    int front=0;
    int back=1;
    while(true)
    {
        if(Max>=N-front)
            break;
        while(back<N&&num[back]<=num[front]*p)
            back++;
        back--;
        if(Max<back-front+1)
            Max=back-front+1;
        front++;
    }
    cout<<Max;
    return 0;
}