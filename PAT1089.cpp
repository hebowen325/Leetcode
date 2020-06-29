#include<iostream>
#include<algorithm>
using namespace std;
int initial[200];
int result[200];
void Merge_sort(int* sequence,int num,int N)
{
    for(int i=0;i<N/num;i++)
    {
        sort(sequence+num*i,sequence+num*(i+1));
    }
    if(N%num!=0)
        sort(sequence+N/num*num,sequence+N);
}
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d",initial+i);
    for(int i=0;i<N;i++)
        scanf("%d",result+i);
    int i=0;
    for(;i<N-1;i++)
        if(result[i]>result[i+1])
            break;
    bool judge=true;
    for(int j=i+1;j<N;j++)
        if(result[j]!=initial[j])
        {
            judge=false;
            break;
        }
    if(judge)
    {
        printf("Insertion Sort\n");
        if(i<N-1)
            sort(result,result+i+2);
        printf("%d",result[0]);
        for(int j=1;j<N;j++)
            printf(" %d",result[j]);
    }
    else
    {
        printf("Merge Sort\n");
        int num=2;
        while(true)
        {
            Merge_sort(initial,num,N);
            bool flag=true;
            for(int j=0;j<N;j++)
            {
                if(initial[j]!=result[j])
                {
                    flag=false;
                    break;
                }
            }
            if(!flag)
                num*=2;
            else
                break;
        }
        Merge_sort(result,num*2,N);
        printf("%d",result[0]);
        for(int j=1;j<N;j++)
            printf(" %d",result[j]);
    }
    return 0;
}