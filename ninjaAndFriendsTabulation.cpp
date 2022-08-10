#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> arr{{1,5,3,2},{2,1,9,7},{7,3,6,2},{2,4,1,3}};
    
    int n=4,m=4;
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
    for(int a=0;a<n;a++){
        for(int b=0;b<n;b++){
            if(a==b) dp[n-1][a][b]=arr[n-1][a];
            else dp[n-1][a][b]=arr[n-1][a]+arr[n-1][b];
        }
    }
    for(int i=n-2;i>=0;i--){
    for(int a=0;a<m;a++)
    {
    for(int b=0;b<m;b++){
        int maxi=-1e8;
        for(int k=-1;k<=1;k++){
        for(int j=-1;j<=1;j++){
            int ans=0;
            if(a==b)
            ans=arr[i][a];
            else 
            ans=arr[i][a]+arr[i][b];
              if(a+k>=0 && a+k<n && b+j>=0 && b+j<n)
             ans+=dp[i+1][a+k][b+j]; 
             else ans+=-1e8;
            maxi=max(maxi,ans);
        }
    }
     dp[i][a][b]=maxi;

}
    }

    }
    cout<<dp[0][0][m-1]<<endl;
    }
