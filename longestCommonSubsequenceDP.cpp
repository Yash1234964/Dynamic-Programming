#include<bits/stdc++.h>
using namespace std;

int solve(string s1,string s2,int l1,int l2,vector<vector<int>> &dp){
 if(l1<0 || l2<0)
 return 0;

if(dp[l1][l2]!=-1) return dp[l1][l2];
 if(s1[l1]==s2[l2])
 return dp[l1][l2]=1+solve(s1,s2,l1-1,l2-1,dp);

 return dp[l1][l2]=max(solve(s1,s2,l1-1,l1,dp),solve(s1,s2,l1,l2-1,dp));
}

int main(){

 string s1="acd",s2="ced";
 int l1=3,l2=3;
 vector<vector<int>> dp(l1,vector<int>(l2,-1));

 cout<<solve(s1,s2,l1-1,l2-1,dp)<<'\n';
 for(auto &i:dp){
    for(auto &j:i)
    cout<<j<<" ";
    cout<<'\n';
 }


}