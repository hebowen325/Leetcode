#include<iostream>
#include<math.h>
#include<stack>
#include "limits.h"
using namespace std;
int chain[200000];
int price[200000];
void fill_price(int i)
{
    stack<int> S;
    while(chain[i]!=-1&&price[i]==-1)
    {
        S.push(i);
        i=chain[i];
    }
    if(chain[i]==-1)
        price[i]=0;
    while(!S.empty())
    {
        price[S.top()]=price[i]+1;
        i=S.top();
        S.pop();
    }

}
int main()
{
    int N;
    double P;
    double r;
    scanf("%d %lf %lf",&N,&P,&r);
    for(int i=0;i<N;i++)
        scanf("%d",chain+i);
    fill(price,price+N,-1);
    for(int i=0;i<N;i++)
        if(price[i]==-1)
            fill_price(i);
    int largest=INT_MIN;
    int smallestcount;
    for(int i=0;i<N;i++)
    {
        if(largest<price[i])
        {
            largest=price[i];
            smallestcount=1;
        }
        else if(largest==price[i])
            smallestcount++;
    }
    printf("%.2f %d",P*pow(1+r/100,double(largest)),smallestcount);
    return 0;
}
