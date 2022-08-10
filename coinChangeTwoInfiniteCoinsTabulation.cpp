#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={9,6,5,1,1};
    int n=5,target=11;
    vector<vector<int>> dp(n,vector<int>(target+1,0));

    for(int i=0;i<=target;i++)
    dp[0][i]=(i%arr[0]==0);

    for(int i=1;i<n;i++){
        for(int t=0;t<=target;t++){
            int notTake=dp[i-1][t];
            int take=0;
            if(arr[i]<=t) take=dp[i][t-arr[i]];

            dp[i][t]=take + notTake;
        }
    }
    cout<<dp[n-1][target]<<'\n';
   for(auto &i:dp){
    for(auto &j:i)
    cout<<j<<' ';
    cout<<'\n';
   }
    
}