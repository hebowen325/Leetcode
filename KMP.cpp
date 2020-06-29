#include<iostream>
using namespace std;
char str1[100];
char str2[1000];
int Next[100];
void GetNextTable(int N)
{
    Next[0]=-1;
    int i=0,j=-1;
    while(i<N)
    {
        if(j==-1||str1[i]==str1[j])
        {
            i++;
            j++;
            Next[i]=j;
        }
        else
        {
            j=Next[j];
        }     
    }
}

int KMP(int N1,int N2)
{
    GetNextTable(N1);
    int ans=0;
    int i=0,j=0;
    while(j<N2)
    {
        if(i==-1||str1[i]==str2[j])
        {
            i++;
            j++;
        }
        else
        {
            i=Next[i];
        }
        if(i==N1)
        {
            ans+=1;
            i=Next[N1];
        }
    }
    return ans;
}
int main()
{
    scanf("%s",str1);
    scanf("%s",str2);
    int N1,N2;
    for(N1=0;str1[N1]!=0;N1++);
    for(N2=0;str2[N2]!=0;N2++);
    KMP(N1,N2);
}