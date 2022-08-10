#include<bits/stdc++.h>
using namespace std;

int solve(int* coins,int n,int target,vector<vector<int>>& dp){

    if(n==0){
        if(target%coins[n]==0)
        return target/coins[n];
        else return 1e9;
    }
    if(dp[n][target]!=-1) return dp[n][target];
    int notTake=solve(coins,n-1,target,dp);
    int take=1e9;
    if(coins[n]<=target){
      take=1+solve(coins,n,target-coins[n],dp);
    }
    return dp[n][target]=min(take,notTake);
}

int main(){
    int coins[]={9,6,5,1,1};
    int n=5,target=11;
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    cout<<solve(coins,n-1,target,dp)<<'\n';

    for(auto &i:dp){
        for(auto &j:i){
            cout<<j<<" ";
        }
        cout<<'\n';
    }
    
}