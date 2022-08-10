#include<bits/stdc++.h>
using namespace std;

int main(){
    int val[]={30,40,50};
    int wt[] ={3,2,5};
    int cap=6;
    int n=3;

    vector<vector<int>> dp(n,vector<int>(cap+1,0));
    for(int i=wt[0];i<=cap;i++) dp[0][i]=val[0];

    for(int i=1;i<n;i++){
        for(int w=0;w<=cap;w++){
            int notTake=dp[i-1][w];
            int take=INT_MIN;
            if(wt[i]<=w)
            take=val[i]+dp[i-1][w-wt[i]];

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