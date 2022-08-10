#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr,int idx,int prev,int n,vector<vector<int>> &dp){

    if(idx==n) return 0;

    if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];

    int len=solve(arr,idx+1,prev,n,dp);

    if(prev==-1 || arr[prev] < arr[idx] ){
        len=max(len,1+solve(arr,idx+1,idx,n,dp));
    }
  return dp[idx][prev+1] =len;
}

int main(){
    vector<int>arr={10,9,2,5,3,7,101,18};
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(n+1,-1));

    cout<<solve(arr,0,-1,n,dp)<<'\n';
}