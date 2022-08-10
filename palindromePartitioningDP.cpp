#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(int i,int j,string str){
    while(i<j){
        if(str[i]!=str[j]) return false;
        i++;
        j--;
    }
    return true;
}

int solve(string & str,int i ,int n,vector<int>&dp){
    if(i==n) return 0;
    if(dp[i]!=-1) return dp[i];
    int mini=INT_MAX;
    for(int j=i;j<n;j++){

        if(isPalindrome(i,j,str)){
            int cost=1+solve(str,j+1,n,dp);
            mini=min(mini,cost);
        }
    }
    return dp[i]=mini;
}

int main(){
    string str="bababcbadcede";
    int n=str.size();
    vector<int> dp(n,-1);
    cout<<solve(str,0,n,dp)-1<<'\n';
}