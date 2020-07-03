#include<iostream>
#include<string>
#include<map>
#include<set>
using namespace std;
map<string,set<int>> Map;
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        int ID;
        char tmp[81];
        scanf("%d\n",&ID);
        for(int j=0;j<5;j++)
        {
            scanf("%[^\n]\n",tmp);
            if(j==2)
            {
                string tt(tmp);
                int start=0;
                for(int t=0;t<tt.size();t++)
                {
                    if(tt[t]==' ')
                    {
                        Map[tt.substr(start,t-start)].insert(ID);
                        start=t+1;
                    }
                }
                Map[tt.substr(start,tt.size()-start)].insert(ID);
            }
            else
            {
                Map[tmp].insert(ID);
            }
        }
    }
    int M;
    string query;
    scanf("%d\n",&M);
    for(int i=0;i<M;i++)
    {
        getline(cin,query);
        cout<<query<<endl;
        query=query.substr(3);
        if(Map[query].size()==0)
        {
            printf("Not Found\n");
        }
        else
        {
            for(set<int>::iterator Iter=Map[query].begin();Iter!=Map[query].end();Iter++)
            {
                printf("%07d\n",*Iter);
            }
        }
    }
    return 0;
}