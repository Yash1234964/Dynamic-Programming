#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>arr={1,3,4,5};
       int l=7,n=arr.size();
       vector<vector<int>> dp(n+2,vector<int>(n+2,0));
       arr.push_back(l);
       arr.insert(arr.begin(),0);


       for(int i=n;i>=1;i--){
        for(int j=1;j<=n;j++){
            if(i>j) continue;
            int mini=INT_MAX;
            for(int k=i;k<=j;k++){
               int ans=arr[j+1]-arr[i-1]+dp[i][k-1]+dp[k+1][j];
               mini=min(mini,ans);
            }
            dp[i][j]=mini;
        }
       }
       cout<<dp[1][n]<<'\n';
}