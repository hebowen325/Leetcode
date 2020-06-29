#include<iostream>
#include<algorithm>
using namespace std;
float* amount;
float* prices;
typedef struct node
{
    float amo;
    float price;
    float all_price;
}node;
bool cmp(const node& N1,const node& N2)
{
    return N1.price>N2.price;
}
int main()
{
    int N,demand;
    scanf("%d %d",&N,&demand);
    amount=new float [N];
    prices=new float [N];
    node* sets=new node [N];
    for(int i=0;i<N;i++)
    {
        scanf("%f",amount+i);
    }
    for(int i=0;i<N;i++)
    {
        scanf("%f",prices+i);
        sets[i].all_price=prices[i];
        prices[i]/=amount[i];
        sets[i].amo=amount[i];
        sets[i].price=prices[i];
    }
    sort(sets,sets+N,cmp);
    int i=0;
    float ans=0;
    while(demand>0&&i<N)
    {
        if(demand>=sets[i].amo)
        {
            ans+=sets[i].all_price;
            demand-=sets[i].amo;
        }
        else
        {
            ans+=(sets[i].price*demand);
            demand=0;
        }
        i++;
    }
    printf("%.2f",ans);
    return 0;
}