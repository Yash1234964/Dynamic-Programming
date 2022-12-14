#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1="brute",s2="groot";
    int l1=s1.size(),l2=s2.size();

    vector<vector<int>> dp(l1+1,vector<int>(l2+1,0));
    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        cout<<dp[l1][l2]<<'\n';

        string ans="";
        int i=l1,j=l2;

        while(i>0 && j>0){

            if(s1[i-1]==s2[j-1]){
                ans+=s1[i-1];
                i--;j--;
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                ans+=s1[i-1];
                i--;
            }
            else{ ans+=s2[j-1];j--;}
        }

        while(i>0){ans+=s1[i-1];i--;}
        while(j>0) {ans+=s2[j-1];j--;}
        reverse(ans.begin(),ans.end());
        cout<<ans<<'\n';

    }
