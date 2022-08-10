#include<bits/stdc++.h>
using namespace std;

bool solve(string s1,string s2, int i,int j,vector<vector<int>>& dp){
  
  if(i==0 && j==0) return true;
  if(i==0 && j>0) return false;

  if(i>0 && j==0)
{
    for(int k=0;k<=i;k++){
        if(s1[k]!='*')
        return false;
    }
    return true;
}

if(dp[i][j] !=-1) return dp[i][j];

    if(s1[i-1]==s2[j-1] || s1[i]=='?') return dp[i][j]=solve(s1,s2,i-1,j-1,dp);
    else if(s1[i-1]=='*') return dp[i][j]=solve(s1,s2,i-1,j-1,dp) || solve(s1,s2,i,j-1,dp);

    return dp[i][j]=false;
}

int main(){
    string s1="ab*cd",s2="abdefcd";
    // string s1="a?ay",s2="ray";
    int l1=s1.length(),l2=s2.length();
    vector<vector<int>> dp(l1+1,vector<int>(l2+1,-1));

    cout<<solve(s1,s2,l1,l2,dp);
}