#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct stu
{
    char name[9];
    int height;
}stu;
bool cmp(const stu& s1,const stu& s2)
{
    if(s1.height!=s2.height)
    {
        return s1.height<s2.height;
    }
    else
    {
        return strcmp(s1.name,s2.name)>0;
    }
}
stu S[10001];
string ss[10000];
void generate_row(int start,int end)
{
    int m=end-start+1;
    int middle=m/2;
    fill(ss,ss+m,"0");
    for(int i=0;i<m;i++)
    {
        if(i%2==0)
        {
            ss[middle+i/2]=string(S[end-i].name);
        }
        else
        {
            ss[middle-(i+1)/2]=string(S[end-i].name);
        }
    }
    for(int i=0;i<end-start;i++)
    {
        cout<<ss[i]<<" ";
    }
    cout<<ss[end-start]<<endl;
}
int main()
{
    int N,K;
    char tmp[10];
    scanf("%d %d",&N,&K);
    for(int i=0;i<N;i++)
    {
        scanf("%s %d",S[i].name,&S[i].height);
    }
    sort(S,S+N,cmp);
    if(N%K!=0)
    {
        generate_row(N/K*(K-1),N-1);
        for(int i=0;i<K-1;i++)
        {
            generate_row(N/K*(K-i-2),N/K*(K-i-1)-1);
        }
    }
    else 
    {
        for(int i=0;i<K;i++)
        {
            generate_row(N/K*(K-i-1),N/K*(K-i)-1);
        }
    }
    return 0;
}