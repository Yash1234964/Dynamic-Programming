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
         cin>>arr[i];

     }
     if(n<=2)   {
         cout<<0<<endl;
         for(auto i:arr)
cout<<i<<" ";
    cout<<endl;

     }
     else{
     cout<<((n&1)?n/2:n/2-1)<<endl;
     sort(arr.begin(),arr.end());
     for(lli i=0;i<n-1;i+=2){
         swap(arr[i],arr[i+1]);
}    
for(auto i:arr)
cout<<i<<" ";
    cout<<endl;
     }
    }
}