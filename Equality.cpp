#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"
#define vll vector<long long>
#define vi vector<int>
#define mod 1000000007

void solve()
{
    int n;
    cin>>n;
    vector<ll>a(n);
    ll s=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s+=a[i];
    }
    s= s/(n-1);
    for(int i=0;i<n;i++){
        cout<<s-a[i]<<" ";
    }
    cout<<nl;

}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll test=1;
    cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
