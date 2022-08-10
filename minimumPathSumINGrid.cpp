#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &arr,int n,int m,vector<vector<int>> &dp){
    if(dp[n][m]!=-1) return dp[n][m];
    if(n==0 && m==0)
    return arr[0][0];

    int l=INT_MAX,r=INT_MAX;
    if(n>0)
     l=arr[n][m]+solve(arr,n-1,m,dp);
     if(m>0)
     r=arr[n][m]+solve(arr,n,m-1,dp);
    
    
     return dp[n][m]=min(l,r); 

}

int main(){
    vector<vector<int>> arr={{10,8,2},{10,5,100},{1,1,2}};
    int n=3,m=3;
    vector<vector<int>>dp(n,vector<int>(m,-1));
    int x=solve(arr,n-1,m-1,dp);
      for(auto i:dp)
     {
         for(auto j:i){
             cout<<j<<" ";
         }cout<<endl;
     }
    cout<<x<<endl;
}