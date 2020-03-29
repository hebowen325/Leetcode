#include<iostream>
#include<string>
#include<math.h>
using namespace std;
int main()
{
    int N,count=0;
    double ans=0;
    scanf("%d",&N);
    char a[50],b[50];
    fill(b,b+50,'0');
    double t;
    for(int j=0;j<N;j++)
    {
        bool flag=true;
        scanf("%s",a);
        sscanf(a,"%lf",&t);
        sprintf(b,"%.2lf",t);
        for(int i=0;a[i]!=0;i++)
        {
            if(a[i]!=b[i])
            {
                flag=false;
                break;
            }
        }
        if(!flag||t>1000||t<-1000)
        {
            cout<<"ERROR: "<<a<<" is not a legal number\n";
        }
        else
        {
            count++;
            ans+=t;
        }
    }
    if(count==0)
    {
        printf("The average of 0 numbers is Undefined");
    }
    else if(count==1)
    {
        printf("The average of %d number is %.2lf",count,ans/(count*1.0));
    }
    else
    {
        printf("The average of %d numbers is %.2lf",count,ans/(count*1.0));
    }
    return 0;
}