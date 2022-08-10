#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr,int i,int j,vector<vector<int>> &dp){
    if(i>j) return 0;

   if(dp[i][j]!=-1) return dp[i][j];
    int mini=INT_MAX;

    for(int k=i;k<=j;k++){
        int ans=arr[j+1]-arr[i-1]+solve(arr,i,k-1,dp)+solve(arr,k+1,j,dp);
        mini=min(mini,ans);
    }
    return dp[i][j]=mini;
}

int main(){
    vector<int> arr={1,3,4,5};
    int l=arr.size(),n=7;

    arr.push_back(n);
    arr.insert(arr.begin(),0);

    sort(arr.begin(),arr.end());
    vector<vector<int>> dp(l+1,vector<int>(l+1,-1));
    cout<<solve(arr,1,l,dp)<<'\n';

}