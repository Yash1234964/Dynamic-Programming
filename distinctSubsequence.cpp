#include<bits/stdc++.h>
using namespace std;

int solve(string &s1,string &s2,int i,int j,vector<vector<int>> &dp){

    if(j<0) return 1;
    if(i<0) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    if(s1[i]==s2[j]){
        return dp[i][j]=solve(s1,s2,i-1,j-1,dp) + solve(s1,s2,i-1,j,dp);
    }
    else{
        return dp[i][j]=solve(s1,s2,i-1,j,dp);
    }

}

int main(){

    string s1="babgbag",s2="bag";
    int l1=s1.size(),l2=s2.size();
    vector<vector<int>> dp(l1,vector<int>(l2,-1));

    cout<<solve(s1,s2,l1-1,l2-1,dp)<<'\n';

    for(auto &i:dp){
        for(auto &j:i)
        cout<<j<<" ";

        cout<<'\n';
    }
}