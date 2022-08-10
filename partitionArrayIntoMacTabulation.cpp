#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr={1,15,7,9,2,5,10};
    int n=arr.size(),k=3;

    vector<int> dp(n+1,0);
    for(int j=n-1;j>=0;j--){
        int maxi=INT_MIN,len=0,maxCost=INT_MIN;
        for(int i=j;i<min(j+k,n);i++){
            len++;
            maxi=max(maxi,arr[i]);
            int sum=len*maxi+dp[i+1];
            maxCost=max(maxCost,sum);
        }
        dp[j]=maxCost;
    }
    cout<<dp[0]<<'\n';
}