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
    lli n;
    cin>>n;
    vlli arr(n);
    for(lli i=0;i<n;i++){
        lli temp=0;
        cin>>temp;
        arr[i]=temp;
    }
    lli a[]={0,0};
    bool flag=true;
    for(lli i=0;i<n;i++){
        if(arr[i]<a[arr[i]&1]) {flag=false;break;}
        else a[arr[i]&1]=arr[i];
    }
    if(flag) cout<<"YES\n";
    else cout<<"NO\n";
    
}
}