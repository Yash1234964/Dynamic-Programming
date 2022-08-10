#include<bits/stdc++.h>
using namespace std;

int solve(string s1,string s2,int l1,int l2,vector<vector<int>> &dp){

    if(l1<0) return l2+1;
    if(l2<0) return l1+1;
    
    if(dp[l1][l2]!=-1) return dp[l1][l2];
    if(s1[l1]==s2[l2])
    return solve(s1,s2,l1-1,l2-1,dp);

    int insert=1+solve(s1,s2,l1,l2-1,dp);
    int dele=1+solve(s1,s2,l1-1,l2,dp);
    int rep=1+solve(s1,s2,l1-1,l2-1,dp);

    return dp[l1][l2]=min(insert,min(dele,rep)); 


}

int main(){
    string s1="intention",s2="execution";
    int l1=s1.length(),l2=s2.length();
    vector<vector<int>> dp(l1,vector<int>(l2,-1));

    cout<<solve(s1,s2,l1-1,l2-1,dp)<<'\n';

    for(auto &i:dp){
        for(auto &j:i)
        cout<<j<<" ";
        cout<<'\n';
    }
}