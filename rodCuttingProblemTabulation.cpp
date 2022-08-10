#include<bits/stdc++.h>
using namespace std;

int main(){
    int l=10;
    int val[]={2,5,7,8,10};
    int n=5;

    vector<vector<int>> dp(n,vector<int>(l+1,0));
    for(int i=0;i<=l;i++) dp[0][i]=i*val[0];

    for(int i=1;i<n;i++){
        for(int rl=0;rl<=l;rl++){
            int notTake=dp[i-1][rl];
            int take=INT_MIN;
            int rodLength=i+1;
            if(rodLength<=rl)
            take=val[i]+dp[i][rl-rodLength];

            dp[i][rl]=max(take,notTake);
        }
    }
    cout<<dp[n-1][l]<<'\n';

    for(auto &i:dp){
        for(auto &j:i){
            cout<<j<<' ';
        }cout<<'\n';
    }

}