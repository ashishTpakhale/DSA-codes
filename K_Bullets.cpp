#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<int,int>a(n);
        int m=1;
        for(int i= 0; i < n; i++){
            cin>>a[i]
            // if(i>0 && a[i-1]!=a[i]+1){
            //     m++;
            // }
        }
        for(int i= 0; i < n; i++){
            for(int j=i+1;j<n;j++){
                if(a[i]==a[j]+1){

                }
            }
        }
        cout<<m<<endl;
    }
}