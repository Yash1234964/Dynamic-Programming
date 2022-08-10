#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> arr={{10,8,2},{10,5,100},{1,1,2}};
    int n=3,m=3;
    vector<vector<int>>dp(n,vector<int>(m,-1));
    
    for(int i=0;i<=2;i++){
       
        for(int j=0;j<=2;j++){
            if(i==0 && j==0) dp[i][j]=arr[i][j];
            else{
             int l=INT_MAX,r=INT_MAX;
            if(i>0) l=dp[i-1][j]+arr[i][j];
            if(j>0) r=dp[i][j-1]+arr[i][j];
            dp[i][j]=min(l,r);      
        }
        }
    }
    cout<<dp[2][2]<<endl;
    for(auto i:dp)
     {
         for(auto j:i){
             cout<<j<<" ";
         }cout<<endl;
     }
}