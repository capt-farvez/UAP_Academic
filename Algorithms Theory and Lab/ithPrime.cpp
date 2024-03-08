#include <bits/stdc++.h>
using namespace std;
int main(){
    bool prime[50000];
    memset(prime, true, sizeof(prime));
    for(int i=2; i<=sqrt(50000); i++){
        if(prime[i]){
            for(int j=i*i; j<=50000; j++){
                if(j%i==0){
                    prime[j]=false;
                }
            }
        }
    }
    int arr[50000], sum=0;
    for(int i=2; i<=50000; i++){
        if(prime[i]){
            arr[sum]=i;
            sum++;
        }
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<arr[n-1]<<endl;
        }
    return 0;
}



//                      --- Another way---


// #include<stdio.h>
// #include<math.h>
// int status[1100002]= {0}, kprime[1100002]= {0};
// void siv()
// {
//     int N=1000000,sq;
//     sq=sqrt(N);

//     for(int i=4; i<=N; i+=2)
//         status[i]=1;

//     for(int i=3; i<=sq; i+=2)
//     {
//         if(status[i]==0)
//         {
//             for(int j=i*i; j<=N; j+=i)
//                 status[j]=1;
//         }
//     }
//     status[1]=1;
// }

// int main()
// {    siv();
//     int Q, K, i,j=1;
//     for(i=2; i<=1000000; i++)
//     {
//         if(status[i]==0)
//         {
//             kprime[j]=i;
//             j++;
//         }
//     }
//     scanf("%d", &Q);
//     for(i=1; i<=Q; i++)
//     {
//         scanf("%d", &K);
//         printf("%d\n",kprime[K]);

//     }

// }
