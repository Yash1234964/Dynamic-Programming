#include<bits/stdc++.h>
using namespace std;

int solve(int* arr,int n,int target,vector<vector<int>> &dp){
if(n==0){
    return (target%arr[n]==0);
}
if(dp[n][target]!=-1) return dp[n][target];
int notTake = solve(arr,n-1,target,dp);
int take=0;
if(arr[n] <=target){
    take = solve(arr,n,target-arr[n],dp);
}
return dp[n][target]=take+notTake;
}

int main(){
    int arr[]={9,6,5,1,1};
    int n=5,target=11;
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    cout<<solve(arr,n-1,target,dp);

    for(auto &i: dp){
        for(auto &j:i){
            cout<<j<<" ";
        }cout<<'\n';
    }
}