#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr,int i,int j,vector<vector<int>> &dp){
    if(i>j) return 0;
     int maxi=INT_MIN;
     if(dp[i][j]!=-1) return dp[i][j];
    for(int idx=i;idx<=j;idx++){
        int cost=arr[i-1]*arr[idx]*arr[j+1]+solve(arr,i,idx-1,dp)+solve(arr,idx+1,j,dp);
        maxi=max(maxi,cost);
    }
    return dp[i][j]=maxi;
}

int main(){
    vector<int> arr={3,1,5,8};
    int l=arr.size();
    arr.push_back(1);
    arr.insert(arr.begin(),1);
    vector<vector<int>>dp(l+1,vector<int>(l+1,-1));

    cout<<solve(arr,1,l,dp);
}