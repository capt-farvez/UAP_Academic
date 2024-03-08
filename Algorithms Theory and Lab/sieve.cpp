#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for(int i=2; i<=sqrt(n); i++){
        if(prime[i]){
            for(int j=i*i; j<=n; j++){
                if(j%i==0){
                    prime[j]=false;
                }
            }
        }
    }
    int arr[50000], sum=0;
    for(int i=2; i<=n; i++){
        if(prime[i]){
            cout<<i<<" ";
        }
    }
    return 0;
}