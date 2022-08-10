#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr={1,3,5,4,7};
    // vector<int> arr={1,5,4,3,2,6,7,10,8,9};
    int l= arr.size();
    vector<int> dp(l,1),cnt(l,1);
    int maxi=0;
    for(int i=0;i<l;i++){
        for(int j=0;j<i;j++){

            if(arr[i]>arr[j] && (dp[j]+1) >dp[i]){
                dp[i]=dp[j]+1;
                cnt[i]=cnt[j];

            }
            else if(arr[i] >arr[j] && (dp[j]+1) ==dp[i]){
                cnt[i]+=cnt[j];
            }

        }
        maxi=max(maxi,dp[i]);
    }
    int ans=0;

    for(int i=0;i<l;i++){
        if(dp[i]==maxi){
            ans+=cnt[i];
        }
    }
    cout<<ans<<'\n';
    for(auto &i:dp){
        cout<<i<<" ";
    }cout<<'\n';

    for(auto &j:cnt){
        cout<<j<<" ";
    }cout<<'\n';
}