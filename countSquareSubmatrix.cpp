#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> arr(6,vector<int>(6,1));
    vector<vector<int>>dp(6,vector<int>(6,0));

    for(int i=0;i<6;i++) dp[i][0]=arr[i][0];
    for(int i=0;i<6;i++) dp[0][i]=arr[0][i];

    for(int i=1;i<6;i++){
        for(int j=1;j<6;j++){
            if(arr[i][j==0]) dp[i][j]=0;
            else dp[i][j]=min(arr[i-1][j-1],min(arr[i-1][j],arr[i][j-1]));
        }
    }
    int sum=0;
    for(auto& i:dp){
        for(auto& j:i){
            sum+=j;
        }
    }
    cout<<sum<<'\n';
}