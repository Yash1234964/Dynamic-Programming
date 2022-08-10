#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1="babgbag",s2="bag";
    int l1=s1.length(),l2=s2.length();

    vector<vector<int>> dp(l1+1,vector<int>(l2+1,0));
    for(int i=0;i<=l1;i++){
        dp[i][0]=1;
    }
        for(int i=1;i<=l1;i++){
            for(int j=1;j<=l2;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
                else dp[i][j]=dp[i-1][j];
            }
        }

        cout<<dp[l1][l2]<<'\n';

        for(auto &i:dp){
            for(auto &j:i){
                cout<<j<<" ";
            }
            cout<<'\n';
        }
    
}