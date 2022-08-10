#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<lli,lli> plli;
typedef vector<long long int> vlli;
typedef vector<string> vst;
typedef map<lli,lli> mlli;
typedef set<lli> slli;
typedef unordered_set<lli> uslli;
int main(){
    
    int t=0;
cin>>t;
    while(t--){
    lli n,k;
    cin>>n>>k;

    vlli arr(n);
    for(lli i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr.begin(),arr.end());
    bool flag=false;
    if(n==1 && arr[0]==k) flag=true;
    else if(n>1){
    lli i=0,j=1;
    while(i<n && j<n){
        if(arr[i]+k==arr[j]){ flag=true;
        break;
        }
        else if(arr[i]+k<arr[j]) i++;
        else j++;

    }

    }
    if(flag) cout<<"YES\n";
    else cout<<"NO\n";
        
    }
}