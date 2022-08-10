#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr,int cap,int l,int idx,int buy,vector<vector<vector<int>>> &dp){
    if(cap==0) return 0;
    if(idx>=l) return 0;
      
      if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];

      int profit=0;

     if(buy){
      profit=max(-arr[idx]+solve(arr,cap,l,idx+1,0,dp),solve(arr,cap,l,idx+1,1,dp));
     }
     else{
     profit=max(arr[idx]+solve(arr,cap-1,l,idx+1,1,dp),solve(arr,cap,l,idx+1,0,dp));
     }
     return dp[idx][buy][cap]=profit;
}

int main(){
    vector<int> arr={3,3,5,0,0,3,1,4};
    int l=8,cap=2;
    vector<vector<vector<int>>> dp(l,vector<vector<int>>(2,vector<int>(3,-1)));

    cout<<solve(arr,cap,l,0,1,dp)<<'\n';
    
}