#include<iostream>
#include<algorithm>
using namespace std;
int Arr[1000000];
int main()
{
    int c=1;
    int N,t;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",Arr+i);
    }
    sort(Arr,Arr+N);
    for(int i=0;i<N;i++)
    {
        if(Arr[i]<=0)
        {
            continue;
        }
        if(Arr[i]==c)
        {
            c++;
        }
        else if(Arr[i]!=c-1)
        {
            break;
        }
    }
    cout<<c;
    return 0;
}