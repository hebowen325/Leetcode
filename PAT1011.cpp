#include<iomanip>
#include<iostream>
using namespace std;
int main()
{
    double money[3];
    int largest;
    double ans=1;
    for(int i=0;i<3;i++)
    {
        cin>>money[0];
        cin>>money[1];
        cin>>money[2];
        if(money[0]>money[1])
        {
            largest=0;
        }
        else
        {
            largest=1;
        }
        if(money[2]>money[largest])
        {
            largest=2;
        }
        switch(largest)
        {
            case(0):
            {
                cout<<"W ";
                break;
            }
            case(1):
            {
                cout<<"T ";
                break;
            }
            case(2):
            {
                cout<<"L ";
                break;
            }
        }
        ans*=money[largest];
    }
    ans=(ans*0.65-1)*2;
    cout<<fixed<<setprecision(2)<<ans;
    return 0;
}