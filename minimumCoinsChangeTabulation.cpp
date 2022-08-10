#include<bits/stdc++.h>
using namespace std;

int main(){
    int coins[]={9,6,5,1};
    int n=4,target=11;
    vector<vector<int>> dp(n,vector<int>(target+1,0));

    for(int t=0;t<=target;t++)
    {
        if(t%coins[0]==0) dp[0][t]=t/coins[0];
        else dp[0][t]=1e9;
    }

    for(int idx=1;idx<n;idx++){
        for(int t=0;t<=target;t++){
            int notTake=dp[idx-1][t];
            int take=INT_MAX;
            if(coins[idx]<=t)
            take=1+dp[idx-1][t-coins[idx]];
            dp[idx][t]=min(take,notTake);
        }
    }
    cout<<dp[n-1][target]<<'\n';
    for(auto &i:dp)
    {
        for(auto &j:i)
        cout<<j<<" ";
        cout<<'\n';
    }
} 