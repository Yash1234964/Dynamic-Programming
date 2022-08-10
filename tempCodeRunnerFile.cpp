#include<bits/stdc++.h>
using namespace std;

int solve(int n,int m,vector<vector<int>> &dp){
    if(n==0 && m==0)
    return 1;
    if(n<0 || m<0)
    return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    int left=solve(n-1,m,dp);
    int right=solve(n,m-1,dp);
    return dp[n][m]=right+left;
}

int main(){
int n=3,m=3;
vector<vector<int>>dp(3,vector<int>(3,-1));
int count=solve(m-1,n-1,dp);
cout<<count<<endl;
for(auto i:dp){
    for(auto j:i){
        cout<<j<<" ";
    }cout<<endl;
}
}
