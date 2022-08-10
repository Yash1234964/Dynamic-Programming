#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> arr={10,9,2,5,3,7,101,18};
    int n=arr.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    for(int idx=n-1;idx>=0;idx--){
        for(int prev=idx-1;prev>=-1;prev--){

            int len=dp[idx+1][prev+1];
            if(prev==-1 || arr[idx] > arr[prev]){
                len=max(len,1+dp[idx+1][idx+1]);
            }
            dp[idx][prev+1]=len;
        }
    }
    cout<<dp[0][0]<<'\n';
}