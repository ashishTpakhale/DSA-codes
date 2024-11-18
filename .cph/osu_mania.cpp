#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char c[n][4];
        int count[n]={1};
        for(int i=0;i<n;i++){
            for(int j=0;j<4;j++){
                cin>>c[i][j];
                
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<4;j++){
                if(c[i][j]=='#'){
                    count[i]=j+1;
                }

            }
        }
        
        for(int i=n-1;i>=0;i--){
            cout<<count[i]<<" ";
        }
        cout<<endl;
    }
}