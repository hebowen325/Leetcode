#include<iostream>
#include "limits.h"
using namespace std;
int main()
{
    int count;
    cin>>count;
    int* nums=new int [count];
    bool judge=false;
    int best_num[2];
    int best_sum=INT_MIN;
    for(int i=0;i<count;i++)
    {
        cin>>nums[i];
        if(nums[i]>=0)
        {
            judge=true;
        }
        if(nums[i]>best_sum)
        {
            best_sum=nums[i];
            best_num[0]=best_num[1]=i;
        }
    }
    if(!judge)
    {
        cout<<0<<" "<<nums[0]<<" "<<nums[count-1];
        return 0;
    }
    int first_continue=nums[0];
    int continue_sum;
    for(int i=2;i<=count;i++)
    {
        first_continue+=nums[i-1];
        continue_sum=first_continue;
        if(continue_sum>best_sum)
        {
            best_sum=continue_sum;
            best_num[0]=0;
            best_num[1]=i-1;
        }
        if(continue_sum==best_sum&&0<best_num[0])
        {
            best_num[0]=0;
            best_num[1]=i-1;
        }
        for(int j=0;j<count-i;j++)
        {
            continue_sum-=nums[j];
            continue_sum+=nums[j+i];
            if(continue_sum>best_sum)
            {
                best_sum=continue_sum;
                best_num[0]=j+1;
                best_num[1]=j+i;
            }
            if(continue_sum==best_sum&&j+1<best_num[0])
            {
                best_num[0]=j+1;
                best_num[1]=j+i;
            }
        }
    }
    cout<<best_sum<<" "<<nums[best_num[0]]<<" "<<nums[best_num[1]];
    return 0;
}