#include<iostream>
using namespace std;
int main()
{
    int N;
    int sum=0;
    cin>>N;
    int* Array=new int [N];
    for(int i=0;i<N;i++)
    {
        cin>>Array[i];
        sum+=Array[i];
    }
    int M;
    int tmp;
    int exit1;
    int exit2;
    cin>>M;
    for(int i=0;i<M;i++)
    {
        cin>>exit1>>exit2;
        if(exit1>exit2)
        {
            tmp=exit1;
            exit1=exit2;
            exit2=tmp;
        }
        int road=0;
        for(int j=exit1-1;j<exit2-1;j++)
        {
            road+=Array[j];
        }
        if(road>sum-road)
        {
            road=sum-road;
        }
        cout<<road<<endl;
    }
    return 0;
}