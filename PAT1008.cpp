
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int count;
    cin>>count;
    int pre_floor=0;
    int curr_floor;
    int ans=0;
    for(int i=0;i<count;i++)
    {
        cin>>curr_floor;
        if(curr_floor>=pre_floor)
        {
            ans+=(curr_floor-pre_floor)*6+5;
        }
        else
        {
            ans+=(pre_floor-curr_floor)*4+5;
        }
        pre_floor=curr_floor;
    }
    cout<<ans;
    return 0;
}