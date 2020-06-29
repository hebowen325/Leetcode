#include<cstring>
#include<string>
#include<iostream>
using namespace std;
int main()
{
    int N;
    string s;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        cin>>s;
        long x=stoi(s.substr(0,s.length()/2))*stoi(s.substr(s.length()/2,s.length()/2));
        long t=stoi(s);
        if(x!=0&&t%x==0)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}