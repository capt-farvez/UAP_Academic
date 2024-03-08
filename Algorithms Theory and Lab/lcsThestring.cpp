// LCS in DP style 
// finding the lcs 

#include<bits/stdc++.h>
using namespace std;

vector<char> TheLcs(string s1, string s2){
    if(s1.size() > s2.size()){
        swap(s1, s2);
    }
    int x = s1.size(), y = s2.size();
    int dp[x+1][y+1];
    for(int i = 0; i <= x; i++){
        dp[i][0] = 0;
    }
    for(int i = 0; i <= y; i++){
        dp[0][i] = 0;
    }
    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= y; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    vector<char> v;
    for(int i = x; i >= 0; i--){
        for(int j = y; j >= 0; j--){
            if(dp[i][j] == dp[i][j-1])
                continue;
            if(dp[i][j] != dp[i-1][j-1]){
                v.push_back(s1[i-1]);
                y = j-1;
                break;
            }
        }
    }
    reverse(v.begin(), v.end());
    return v;
}


int main()
{
    string s1, s2; cin >> s1 >> s2;
    vector<char>lcs = TheLcs(s1, s2);
    for(int i = 0; i < lcs.size(); i++){
        cout << lcs[i];
    }
    cout << endl;
    return 0;
}