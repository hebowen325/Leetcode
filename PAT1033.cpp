#include<iostream>
#include<utility>
#include<vector>
#include<iomanip>
#include<unordered_map>
#include<algorithm>
using namespace std;
bool cmp(const pair<double,double> &a,const pair<double,double> &b)
{
    return a.first<b.first;
}
int main()
{
    int capacity_of_tank;
    double distance_from_hz;
    double avg_distance;
    int N;
    cin>>capacity_of_tank>>distance_from_hz>>avg_distance>>N;
    unordered_map<double,double> gas_station;
    double price;
    double distance;
    for(int i=0;i<N;i++)
    {
        cin>>price>>distance;
        gas_station[distance]=price;
    }
    gas_station[distance_from_hz]=0;
    vector<pair<double,double> > Vec(gas_station.begin(),gas_station.end());
    sort(Vec.begin(),Vec.end(),cmp);
    int curr_station=0;
    double max_distance=avg_distance*capacity_of_tank;
    double curr_distance;
    double least;
    int best_place;
    double total_price=0;
    double oil_volume=0;
    if(Vec[0].first>0)
    {
        cout<<"The maximum travel distance = 0.00";
        return 0;
    }
    while(curr_station<N)
    {
        curr_distance=Vec[curr_station].first;
        least=9999.99;
        for(int i=curr_station+1;i<Vec.size()&&Vec[i].first-curr_distance<=max_distance;i++)
        {
            if(least>Vec[i].second)
            {
                least=Vec[i].second;
                best_place=i;
            }
            if(least<Vec[curr_station].second)
            {
                break;
            }
        }
        if(least==9999.99&&curr_distance+max_distance<distance_from_hz)
        {
            cout<<"The maximum travel distance = "<<fixed<<setprecision(2)<<curr_distance+max_distance;
            return 0;
        }
        if(least==9999.99)
        {
            break;
        }
        if(Vec[best_place].second>=Vec[curr_station].second)
        {
            total_price+=(capacity_of_tank-oil_volume)*Vec[curr_station].second;
            oil_volume=capacity_of_tank-((Vec[best_place].first-curr_distance)/avg_distance);
        }
        else
        {
            total_price+=((Vec[best_place].first-curr_distance)/avg_distance-oil_volume)*Vec[curr_station].second;
            oil_volume=0;
        }
        curr_station=best_place;
    }
    cout<<fixed<<setprecision(2)<<total_price;
    return 0;
}