#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr={3,1,5,8};
    int l=arr.size();

    arr.insert(arr.begin(),1);
    arr.push_back(1);

    vector<vector<int>> dp(l+2,vector<int>(l+2,0));

    for(int i=l;i>=1;i--){
        for(int j=1;j<=l;j++){
            if(i>j) continue;

            int maxi=INT_MIN;
            for(int idx=i;idx<=j;idx++){
                  
                  int cost=arr[i-1]*arr[idx]*arr[j+1]+dp[i][idx-1]+dp[idx+1][j];
                   maxi=max(maxi,cost);
            }
            dp[i][j]=maxi;
        }
    }
    cout<<dp[1][l]<<'\n';

}