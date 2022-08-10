#include<bits/stdc++.h>
using namespace std;

int solve(int* val,int l,int idx,vector<vector<int>> &dp){

    if(idx==0){
        return l*val[0];
    }

    if(dp[idx][l]!=-1) return dp[idx][l];

    int notTake = solve(val,l,idx-1,dp);

    int take=INT_MIN;
    if((idx+1)<=l)
    take=val[idx] + solve(val,l-(idx+1),idx,dp);

    return dp[idx][l]=max(take,notTake);
}

int main(){
    int l=10;
    int value[]={2,5,7,8,10};
     int n=5;
    vector<vector<int>> dp(n,vector<int>(l+1,-1));
   

    cout<<solve(value,l,n-1,dp)<<'\n';

    for(auto &i:dp){
        for(auto &j :i){
        cout<<j<<' ';
        }
        cout<<'\n';}
    
}