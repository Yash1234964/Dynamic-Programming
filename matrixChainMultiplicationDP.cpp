#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr,int i,int j,vector<vector<int>> &dp){

    int mini=1e8;
    if(i==j) return 0;
     if(dp[i][j]!=-1) return dp[i][j];
    for(int k=i;k<j;k++){
      int steps= arr[i-1]*arr[k]*arr[j]+solve(arr,i,k,dp)+solve(arr,k+1,j,dp);
      mini=min(mini,steps);
      
    }
    return mini;
}

int main(){
    vector<int> arr={10,20,30,40,50};
    int l=arr.size();
    vector<vector<int>> dp(l,vector<int>(l,-1));

    cout<<solve(arr,1,l-1,dp);
}