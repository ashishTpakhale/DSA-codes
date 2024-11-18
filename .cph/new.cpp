#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>a(n);
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        map<int, int> f;
        for (int i=0;i<n;i++){
            f[a[i]]++;
        }
        int maxf = 0;
        int me = 0;
        for (int i=0;i<n;i++){
            if (f[a[i]] > maxf) {
                maxf = f[a[i]];
                me = a[i];
            }
        }
        int zeros = f[0];
        for (int i=0;i<n;i++){
            if (a[i] == 0) {
                a[i] = me;
            }
        }
        int count=0;
        f[me]+=zeros;
        for (int i=0;i<n;i++){
            int x= f[a[i]];
            if (x >1) {
                count+= (x*(x-1))/2;
            }
        }
        // int count=0;
        // for (int i=0;i<n;i++){
        //     int c=1;
        //     for (int j=0;j<n;j++){
        //         if (a[j] == a[i]) {
        //             c++;
        //         }
        //     }
        //     count = max(count,c);
        // }
        cout << max(count, zeros+1) << endl;
    }
    return 0;
}