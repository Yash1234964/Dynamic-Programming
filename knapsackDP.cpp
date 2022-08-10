#include<bits/stdc++.h>
using namespace std;

int solve(int* wt,int idx,int* val,int cap,vector<vector<int>>&dp){
    if(idx==0){
        if(wt[idx]<=cap) return val[idx];
        else return 0;
    }
      if(dp[idx][cap]!=-1) return dp[idx][cap];
    int notTake=solve(wt,idx-1,val,cap,dp);
    int take=INT_MIN;
    if(wt[idx]<=cap)
    take=val[idx]+solve(wt,idx-1,val,cap-wt[idx],dp);

    return dp[idx][cap]=max(take,notTake);

}

int main(){
    int val[]={30,40,50};
    int wt[] ={3,2,5};
    int cap=6;
    int n=3;
      vector<vector<int>> dp(n,vector<int>(cap+1,-1));
      cout<<solve(wt,n-1,val,cap,dp);

      for(auto &i:dp){
        for(auto &j:i){
            cout<<j<<" ";
        }cout<<'\n';
      }
}