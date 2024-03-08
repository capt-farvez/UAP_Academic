// lcs in recursive way

#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2, int i, int j){
    if(s1.size() == j || s2.size() == j){
        return 0;
    }
    if(s1[i] == s2[j]){
        return 1+lcs(s1,s2,i+1,j+1);
    }
    else{
        return max(lcs(s1, s2, i+1, j), lcs(s1, s2, i, j+1));
    }
}

int main()
{
    string s1, s2; cin >> s1 >> s2;
    cout << lcs(s1, s2, 0, 0) << endl;
    return 0;
}