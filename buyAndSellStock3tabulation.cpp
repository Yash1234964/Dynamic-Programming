#include<bits/stdc++.h>
using namespace std;

int main(){

vector<int> arr={3,3,5,0,0,1,4};
int l=7;
vector<vector<vector<int>>> dp(l+1,(vector<vector<int>>(2,vector<int>(3,0))));

for(int i=l-1;i>=0;i--){
    for(int buy=0;buy<=1;buy++){
        for(int cap=1;cap<=2;cap++){

            if(buy){
                dp[i][buy][cap]=max(-arr[i]+dp[i+1][0][cap],dp[i+1][1][cap]);
            }
            else{
                dp[i][buy][cap]=max(arr[i]+dp[i+1][1][cap-1],dp[i+1][0][cap]);
            }
        }
    }

}
cout<<dp[0][1][2]<<'\n';

}