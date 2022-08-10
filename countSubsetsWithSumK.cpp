#include<bits/stdc++.h>
using namespace std;

int utility(int* arr,int n,int target,vector<vector<int>> &dp){
    if(n==0) return arr[0]==target;

    if(target==0) return 1;

    if(dp[n][target]!=-1) return dp[n][target];

    int notPick=utility(arr,n-1,target,dp);
     
     int pick=0;
     if(arr[n]<=target)
     pick=utility(arr,n-1,target-arr[n],dp);
     return dp[n][target]=pick + notPick;
} 

int main(){
    int arr[]={1,2,2,3};
    int n=4,target=3;
    vector<vector<int>> dp(n,vector<int>(target+1,-1));

    int count=utility(arr,n-1,target,dp);
    for(auto i:dp){
        for(auto j:i)
        cout<<j<<" ";
        cout<<endl;
    }
    cout<<count<<endl;
}