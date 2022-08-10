#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr={10,20,30,40,50};
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));

    for(int i=0;i<n;i++) dp[i][i]=0;
    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<n;j++){
            int mini=1e8;
            for(int k=i;k<j;k++){
               int steps=(arr[i-1]*arr[k]*arr[j])+dp[i][k]+dp[k+1][j];
               mini=min(mini,steps);
            }
            dp[i][j]=mini;
        }
    }
    cout<<dp[1][n-1]<<'\n';
}