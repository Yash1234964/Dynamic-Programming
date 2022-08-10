#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>arr={7,1,5,3,6,4};
    int l=6;

    vector<vector<int>> dp(l+1,vector<int>(2,-1));
     
    dp[l][0]=dp[l][1]=0;
    for(int idx=l-1;idx>=0;idx--){
        for(int buy=0;buy<=1;buy++){
            int profit=0;
            if(buy){
            profit=max(-arr[idx]+dp[idx+1][0],dp[idx+1][1]);
            }
            else{
                profit=max(arr[idx]+dp[idx+1][1],dp[idx+1][0]);
            }
            dp[idx][buy]=profit;
        }
    }
    cout<<dp[0][1]<<'\n';

    for(auto &i:dp){
        for(auto &j:i){
            cout<<j<<" ";
        }
        cout<<'\n';
    }
    }