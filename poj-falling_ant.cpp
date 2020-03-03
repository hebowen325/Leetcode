#include<iostream>
#include<algorithm>
using namespace std;
typedef struct ant
{
    int place;
    int v;
    ant(){}
    ant(int x1,int x2):place(x1),v(x2){}
}ant;
ant Ant[100];
bool cmp(const ant &a1,const ant &a2)
{
    return a1.place<a2.place;
}
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d %d",&Ant[i].place,&Ant[i].v);
    }
    sort(Ant,Ant+N,cmp);
    int num_of_zero=0;
    while(Ant[num_of_zero].v!=0)
    {
        num_of_zero++;
    }
    int leftcount=0,rightcount=0,left[100],right[100];
    for(int i=0;i<num_of_zero;i++)
    {
        if(Ant[i].v>0)
        {
            left[leftcount++]=i;
        }
    }
    for(int i=num_of_zero+1;i<N;i++)
    {
        if(Ant[i].v<0)
        {
            right[rightcount++]=i;
        }
    }
    if(leftcount==rightcount)
    {
        printf("Cannot fall!");
    }
    else if(leftcount<rightcount)
    {
        printf("%d",Ant[right[leftcount]].place);
    }
    else
    {
        printf("%d",100-Ant[left[leftcount-rightcount-1]].place);
    }
    return 0;
}