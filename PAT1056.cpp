#include<iostream>
#include<map>
#include"limits.h"
using namespace std;
void caculate(int* weight_ord,int* ans,map<int,int> &Map,int num,int NG)
{
    if(num==1)
    {
        ans[Map[weight_ord[0]]]=1;
        return ;
    }
    int rank=num/NG+1;
    if(num%NG!=0)
    {
        rank+=1;
    }
    int max;
    for(int i=0;i<num/NG;i++)
    {
        max=INT_MIN;
        for(int j=0;j<NG;j++)
        {
            if(max<weight_ord[i*NG+j])
            {
                max=weight_ord[i*NG+j];
            }
            ans[Map[weight_ord[i*NG+j]]]=rank;           
        }
        weight_ord[i]=max;
    }
    if(num%NG!=0)
    {
        max=INT_MIN;
        for(int i=0;i<num%NG;i++)
        {
            if(max<weight_ord[num/NG*NG+i])
            {
                max=weight_ord[num/NG*NG+i];
            }
            ans[Map[weight_ord[num/NG*NG+i]]]=rank;   
        }
        weight_ord[num/NG]=max;
    }
    if(rank>1)
    {
        caculate(weight_ord,ans,Map,rank-1,NG);
    }
}
int main()
{
    int Np,NG;
    scanf("%d %d",&Np,&NG);
    map<int,int> Map;
    int* weight=new int [Np];
    int* order=new int [Np];
    int* ans=new int [Np]; 
    int Ord;
    for(int i=0;i<Np;i++)
    {
        scanf("%d",&weight[i]);
        Map[weight[i]]=i;    
    }
    for(int i=0;i<Np;i++)
    {
        scanf("%d",&Ord);
        order[i]=weight[Ord];
    }
    caculate(order,ans,Map,Np,NG);
    printf("%d",ans[0]);
    for(int i=1;i<Np;i++)
    {
        printf(" %d",ans[i]);
    }
    return 0;
}