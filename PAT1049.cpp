#include<iostream>
#include<math.h>
int count_one(int N)
{
    int power=1;
    int x=N;
    int ans=0;
    while(x!=0)
    {
        if(x%10==1)
        {
            ans+=(x/10)*power;
            ans+=(N%power)+1;
        }
        else if(x%10>0)
        {
            ans+=(x/10+1)*power;
        }
        else
        {
            ans+=(x/10)*power;
        }
        x/=10;
        power*=10;
    }
    return ans;
}
int main()
{
    int N;
    scanf("%d",&N);
    if(N==0)
    {
        return 0;
    }
    printf("%d",count_one(N));
    return 0;
}