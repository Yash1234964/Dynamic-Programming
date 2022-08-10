#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> arr{{1},{2,3},{3,6,7},{8,9,6,10}};
     vector<vector<int>> dp(4,vector<int>(4,-1));
     // harcoded to be done dynamically 
     dp[3][0]=8;
      dp[3][1]=9;
       dp[3][2]=6;
        dp[3][3]=10;

     for(int i=2;i>=0;i--)
     {
         for(int j=0;j<=i;j++){
             dp[i][j]=min((dp[i+1][j]+arr[i][j]),dp[i+1][j+1]+arr[i][j]);
         }
     }
     cout<<dp[0][0]<<endl;

     for(auto i:dp){
        for(auto j:i)
        cout<<j<<" ";
        cout<<endl;
    }

}