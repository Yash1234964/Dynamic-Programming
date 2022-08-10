#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> val{5,11,13};
    vector<int> wt{2,4,6};
    int n=3,cap=10;

    vector<vector<int>> dp(n,vector<int>(cap+1,0));

    for(int w=1;w<=cap;w++){
        dp[0][w]=(w/wt[0])*val[0];
    }

    for(int i=1;i<n;i++){
        for(int w=1;w<=cap;w++){
            int notTake=dp[i-1][w];
            int take=0;
            if(w-wt[i]>=0)
            take=val[i]+dp[i][w-wt[i]];

            dp[i][w]=max(take,notTake);
        }
    }
    cout<<dp[n-1][cap]<<'\n';

    for(auto &i:dp){
        for(auto &j:i){
            cout<<j<<" ";
        }cout<<'\n';
    }
}