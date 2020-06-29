#include<stdio.h>
using namespace std;
int Array[200005];
int main()
{
    int N1;
    scanf("%d",&N1);
    int tmp;
    int tmp2;
    for(int i=0;i<N1;i++)
    {
        scanf("%d",&Array[i]);
    }
    int N2;
    scanf("%d",&N2);
    tmp=(N1+N2+1)/2;
    int count=0;
    int ans=0;
    int count1=0;
    int count2=0;
    for(;count2<N2;count2++)
    {
        scanf("%d",&tmp2);
        while(count1<N1&&Array[count1]<tmp2)
        {
            count++;
            if(count==tmp)
            {
                printf("%d",Array[count1]);
                return 0;
            }
            count1++;
        }
        count++;
        if(count==tmp)
        {
            printf("%d",tmp2);
            return 0;
        }
    }
    printf("%d",Array[count1+tmp-count-1]);
    return 0;
}