#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    map<string, int> mp;
   
    for(int i=0; i<n; i++){
        string key; int value;
        cin>>key>>value;
        mp[key]= value;
    }
    // p1 21 p2 3 p3 6 p4 2
    //mp["p1"]= 21;
    //mp["p2"]= 3;
    //mp["p3"]= 6;
    //mp["p4"]= 2;

    vector <pair<string, int>> pairs(mp.begin(), mp.end());

    sort(pairs.begin(), pairs.end(),[](const auto& a, const auto& b){
        return a.second < b.second;
    });
   
    vector <int> pre_sum;
    pre_sum.push_back(0);
   
    int ind=0;
    for (const auto& pair : pairs) {
        pre_sum.push_back(pair.second+pre_sum[ind]);
        ind++;
    }
   
    int sum1=0;
    for(int i=0; i<pre_sum.size()-1; i++){
        sum1+=pre_sum[i];
    }
    cout<<"Avarage Time using shortest path: "<<sum1/double(n)<<endl;
    cout<<"Path : ";
    int ittt=0;
    for (const auto& pair : pairs) {
        cout<<pre_sum[ittt]<<" "<<pair.first<<" ";
        ittt++;
    }
    cout<<pre_sum[pre_sum.size()-1]<<endl;
   
    return 0;
}