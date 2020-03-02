#include<iostream>
#include<algorithm>
using namespace std;
int initial[200];
int part[200];
void max_heapsort(int start,int end)
{
    int dad=start;
    int son=2*start+1;
    while(son<=end)
    {
        if(son+1<=end&&part[son]<part[son+1])
            son++;
        if(part[dad]>part[son])
            break;
        else
        {
            swap(part[dad],part[son]);
            dad=son;
            son=2*dad+1;
        }
    }
}
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d",initial+i);
    for(int i=0;i<N;i++)
        scanf("%d",part+i);
    int judge=false;
    int count=N-1;
    while(count>1&&initial[count]==part[count])
        count--;
    if(count==N-1)
    {
        judge=true;
    }
    else
    {
        for(int i=0;i<count;i++)
        {
            if(part[i]>part[i+1])
            {
                judge=true;
                break;
            }
        }
    }
    if(!judge)
    {
        sort(part,part+count+2);
        printf("Insertion Sort\n%d",part[0]);
        for(int i=1;i<N;i++)
            printf(" %d",part[i]);
    }
    else
    {
        count=N-1;
        while(part[count]>=part[count-1])
            count--;
        swap(part[0],part[count]);
        max_heapsort(0,count-1);
        printf("Heap Sort\n%d",part[0]);
        for(int i=1;i<N;i++)
            printf(" %d",part[i]);
    }
    return 0;
}