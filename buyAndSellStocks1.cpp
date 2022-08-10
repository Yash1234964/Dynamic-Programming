#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr ={7,1,5,3,6,4};
    int l =arr.size();

    int mini=arr[0],ans=0;
    for(int i=1;i<l;i++){
       int diff=arr[i]-mini;
       ans=max(ans,diff);
       mini=min(mini,arr[i]);
    }
    cout<<ans<<'\n'; 
}