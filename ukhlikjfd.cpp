#include<bits/stdc++.h>
using namespace std;

int utility(int arr[],vector<int>& dpArray,int n){
    if(n==0) return 0;

    if(dpArray[n]!=-1) return dpArray[n];

    int left=utility(arr,dpArray,n-1)+abs(arr[n]-arr[n-1]);
    int right=INT_MAX;
    if(n>1) right=utility(arr,dpArray,n-2)+abs(arr[n]-arr[n-2]);

    return dpArray[n]=min(left,right);

}

int main(){
    int arr[]={30,10,60,10,60,50};
    int n=6;
    vector<int>dpArray(n,-1);
    
    cout<<utility(arr,dpArray,n-1)<<endl;
    for(int i=0;i<n;i++){
        cout<<dpArray[i]<<" ";
    }cout<<endl;
}