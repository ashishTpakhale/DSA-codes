#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define vec vector<ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define F(i, n) for (ll i = 0; i < n; i++)
#define RF(i, n) for (ll i = n - 1; i >= 0; i--)
#define mod 1000000007
#define nl "\n"
#define YES cout << "YES\n"
#define NO cout << "NO"
#define mod 1000000007

ll checkCarry(int a,int b){
    ll count = 0;
    ll c = 0;
    while(a!=0 && b!=0){
        if((a%10)+(b%10)>9){
            count++;
            c = 1;
        }
        else{
            c = 0;
        }
        a/=10;
        b/=10;
    }
    
    if(c==1)
    return count+checkCarry(((a!=0)?a:b),1);
    else
    return count;
}

void solve()
{
    ll n;
    cin>>n;
    vector<ll> a(n);
    ll count = 0;
    ll sum = 0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll i=0;i<n;i++){
        
        count +=  checkCarry(a[i],sum);
        sum+=a[i];
    }
    cout<<count<<nl;
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