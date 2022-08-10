#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1="acd",s2="ced";
    int l1=3,l2=3;
    vector<vector<int>> dp(l1+1,vector<int>(l2+1,0));

    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[l1][l2]<<'\n';
    for(auto &i:dp){
        for(auto &j:i){
            cout<<j<<' ';
        }cout<<'\n';
    }
}