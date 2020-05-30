#include<iostream>
using namespace std;
long long transfer(string num,long long radix)
{
    long long sum=0;
    for(int i=0;i<num.size();i++)
    {
        sum*=radix;
        if(num[i]>='0'&&num[i]<='9')
        {
            sum+=num[i]-'0';
        }
        else
        {
            sum+=num[i]-'a'+10;
        }
    }
    return sum;
}
int main()
{
    string num[2];
    long int tag,radix;
    cin>>num[0]>>num[1]>>tag>>radix;
    long long val[2];
    val[tag-1]=transfer(num[tag-1],radix);
    int max_Radix=0;
    for(int i=0;i<num[2-tag].size();i++)
    {
        if(num[2-tag][i]>='0'&&num[2-tag][i]<='9')
        {
            max_Radix=max(num[2-tag][i]-'0'+1,max_Radix);
        }
        else
        {
            max_Radix=max(num[2-tag][i]-'a'+11,max_Radix);
        }
    }
    long long low=max_Radix;
    long long high=max(low,val[tag-1]);
    int ans=-1;
    while(low<=high)
    {
        long long middle=(low+high)/2;
        val[2-tag]=transfer(num[2-tag],middle);
        if(val[2-tag]==val[tag-1])
        {
            printf("%lld",middle);
            return 0;
        }
        else if(val[2-tag]<0||val[2-tag]>val[tag-1])
        {
            high=middle-1;
        }
        else
        {
            low=middle+1;
        }
    }
    printf("Impossible");
    return 0;
}