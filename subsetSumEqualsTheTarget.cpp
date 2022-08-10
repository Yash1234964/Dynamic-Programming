#include<bits/stdc++.h>
using namespace std;
bool solve(int arr[],int n,int target,vector<vector<int>> &dp){
    if(target==0)
    return true;
    if(n==0) return arr[0]==target;
    if(dp[n][target]!=-1) return dp[n][target];

     bool notTake=solve(arr,n-1,target,dp);
        
        bool take=false;
     if(arr[n]<=target)
     take=solve(arr,n-1,target-arr[n],dp);
    return dp[n][target]=take||notTake;
}

int main(){
    int arr[]={1,2,3,4};
    int n=4;
    int target=11;
    vector<vector<int>>dp(n,vector<int>(target+1,-1));
    if(solve(arr,n-1,target,dp))
    cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    for(auto i:dp){
        for(auto j:i)
        cout<<j<<" ";
        cout<<endl;
    }
}