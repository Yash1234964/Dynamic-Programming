#include<bits/stdc++.h>
using namespace std;

int solve(int* val,int* wt,int n,int cap,vector<vector<int>> &dp){

    if(n==0){
        if(cap%wt[n]==0)
        return (cap/wt[0])*val[0];
        return INT_MIN;
    }
    if(dp[n][cap] !=-1) return dp[n][cap];
    int notTake=solve(val,wt,n-1,cap,dp);
    int take=INT_MIN;
    if(wt[n]<=cap)
    take=val[n]+solve(val,wt,n,cap-wt[n],dp);

    return dp[n][cap] = max(take,notTake);
}

int main(){
    int val[]={5,11,13};
    int wt[]={2,4,6};
    int n=3,cap=10;
     vector<vector<int>> dp(n,vector<int>(cap+1,-1));
    cout<<solve(val,wt,n-1,cap,dp)<<'\n';

    for(auto &i :dp){
        for(auto &j:i){
            cout<<j<<" ";
        }cout<<'\n';
    }
}