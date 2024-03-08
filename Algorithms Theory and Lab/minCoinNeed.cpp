#include<bits/stdc++.h>
using namespace std;

int minCoinNeed(int wate, vector<int>coins){
    int dp[coins.size()+1][wate+1];
    for(int i = 0; i <= coins.size(); i++){
        dp[i][0] = 0;
    }
    for(int i = 1; i <= wate; i++){
        dp[0][i] = INT_MAX;
    }
    for(int i = 1; i <= coins.size(); i++){
        for(int j = 1; j <= wate; j++){
            if(coins[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = min(dp[i-1][j], 1+dp[i][j-coins[i-1]]);
            }
        }
    }
    return dp[coins.size()][wate];
}

int main()
{
    int total_coin, wate;
    cin >> total_coin >> wate;
    vector<int>coins;
    for(int i = 0; i < total_coin; i++){
        int x; cin >> x;
        coins.push_back(x);
    }
    cout << minCoinNeed(wate, coins) << endl;
    return 0;
}