#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> arr,int i,int n,int m, vector<vector<int>> &dp){
    
    if(i<0 || i>=m) return INT_MIN;
    if(dp[n][i]!=-1) return dp[n][i];
    if(n==0) return arr[0][i];

    int d=0,ld=0,rd=0;
     d=arr[n][i]+solve(arr,i,n-1,m,dp);
     ld=arr[n][i]+solve(arr,i-1,n-1,m,dp);
     rd=arr[n][i]+solve(arr,i+1,n-1,m,dp);

     return dp[n][i]=max(d,max(ld,rd));

}

int main(){
    vector<vector<int>> arr{{1,2,10,4},{100,3,2,1},{1,1,20,2},{1,2,2,1}};
    vector<vector<int>> dp(4,vector<int>(4,-1));
    int n=4,m=4;
    int maxi=0,temp=0;
    for(int i=0;i<m;i++){
     temp=solve(arr,i,n-1,m,dp);
     maxi=max(temp,maxi);
    }
    for(auto i:dp){
        for(auto j:i)
        cout<<j<<" ";
        cout<<endl;
    }
    cout<<maxi<<endl;

}