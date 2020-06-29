#include<iostream>
#include<algorithm>
using namespace std;
int length[10001];
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",length+i);
    }
    sort(length,length+N);
    int left=length[0];
    for(int i=1;i<N;i++)
    {
        left=(left+length[i])/2;
    }
    printf("%d",left);
    return 0;
}