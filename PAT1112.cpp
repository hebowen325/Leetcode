#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[300];
char obj[1500];
int main()
{
    fill(arr,arr+300,-2);
    int k;
    scanf("%d %s",&k,obj);
    int continuous=1;
    vector<char> ans;
    int i;
    for(i=1;obj[i-1]!=0;i++)
    {
        if(obj[i]==obj[i-1])
        {
            continuous++;
            if(continuous==k&&arr[obj[i]]==-2)
            {
                ans.push_back(obj[i]);
                arr[obj[i]]=ans.size()-1;
            }
        }
        else
        {
            if(continuous%k!=0)
            {
                if(arr[obj[i-1]]>=0)
                {
                    ans.erase(ans.begin()+arr[obj[i-1]]);
                }
                arr[obj[i-1]]=-1;
            }
            continuous=1;
        }
    }
    for(i=0;i<ans.size();i++)
    {
        printf("%c",ans[i]);
    }
    printf("\n");
    for(i=0;obj[i]!=0;i++)
    {
        if(arr[obj[i]]>=0)
        {
            printf("%c",obj[i]);
            i+=k-1;
        }
        else
        {
            printf("%c",obj[i]);
        }
    }
    return 0;
}