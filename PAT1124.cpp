#include<iostream>
#include<map>
#include<string>
using namespace std;
map<string,int> Map;
string forwards[1001];
int main()
{
    int M,N,S;
    scanf("%d%d%d",&M,&N,&S);
    string tmp;
    int Count=0;
    for(int i=0;i<M;i++)
    {
        cin>>forwards[Count++];
    }
    if(Count<S)
    {
        printf("Keep going...");
    }
    else
    {
        S--;
        while(S<Count)
        {
            while(S<Count&&Map.count(forwards[S]))
            {
                S++;
            }
            if(S<Count)
            {
                cout<<forwards[S]<<endl;
                Map[forwards[S]]=1;
                S+=N;
            }
        }
    }
    return 0;
}