#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr,int idx,int l,bool buy,vector<vector<int>>&dp){

    if(idx>=l){
        return 0;
    }

    int profit=0;
    if(dp[idx][buy] != -1) return dp[idx][buy];
    if(buy){
         profit=max(-arr[idx]+solve(arr,idx+1,l,0,dp),solve(arr,idx+1,l,1,dp));
    }
    else{
      profit=max(arr[idx]+solve(arr,idx+1,l,1,dp),solve(arr,idx+1,l,0,dp));
    }
     return dp[idx][buy]=profit;
}

int main(){
    vector<int> arr={7,1,5,3,6,4};
    int l=arr.size();
    vector<vector<int>> dp(l,vector<int>(2,-1));

    cout<< solve(arr,0,l,1,dp);
}