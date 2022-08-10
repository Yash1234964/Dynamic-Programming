#include<bits/stdc++.h>
using namespace std;

int main(){
 vector<vector<int>> arr{{1,2,10,4},{100,3,2,1},{1,1,20,2},{1,2,2,1}};
    vector<vector<int>> dp(4,vector<int>(4,-1));
    int n=4,m=4;
    for(int i=0;i<m;i++){
        dp[0][i]=arr[0][i];
    }
        for(int i=1;i<n;i++){
            int rd=INT_MIN,ld=INT_MIN,d=0;
            for(int j=0;j<m;j++){
              if(j>0)
              ld=dp[i-1][j-1]+arr[i][j];
              if(j<m-1)
               rd=dp[i-1][j+1]+arr[i][j];

               d=dp[i-1][j]+arr[i][j];
               dp[i][j]=max(ld,max(rd,d));
            }
        }
        for(auto i:dp){
        for(auto j:i)
        cout<<j<<" ";
        cout<<endl;
    }
         
         int maxi=0;
         for(int i=0;i<n;i++){
             maxi=max(maxi,dp[n-1][i]);
         }
         cout<<maxi<<endl;
    }

