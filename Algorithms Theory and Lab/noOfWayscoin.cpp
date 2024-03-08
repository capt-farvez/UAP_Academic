// number of ways to make changes

#include<bits/stdc++.h>
using namespace std;

int ways(int wate, vector<int> coins){
    int dp[coins.size()+1][wate+1];
    for(int i = 1; i <= wate; i++){
        dp[0][i] = 0;
    }
    for(int i = 0; i <= coins.size(); i++){
        dp[i][0] = 1;
    }
    for(int i = 1; i <= coins.size(); i++){
        for(int j = 1; j <= wate; j++){
            if(coins[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
            }
        }
    }
    return dp[coins.size()][wate];
}

int main()
{
    int total_coins, wate;
    cin >> total_coins >> wate;
    vector<int> coins;
    for(int i = 0; i < total_coins; i++){
        int x; cin >> x;
        coins.push_back(x);
    }
    cout << ways(wate, coins) << endl;
    return 0;
}