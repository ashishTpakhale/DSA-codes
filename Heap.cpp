#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;

}

void heapify(int a[],int i,int n){
    
    int p=i;
    int lt=2*i+1;
    int rt= 2*i+2;
    if(lt<n && a[lt]< a[p] ){
        p=lt;
    }
    if(rt<n && a[rt]< a[p] ){
        p=rt;
    }
    if(p!=i){
        swap(&a[i],&a[p]);
        heapify(a,i,n);
    }
}
void buildHeap(int a[],int n){
    for(int  i=n/2-1;i>=0;i--){
        heapify(a,i,n);
    }
}
void heapInsert(int a[],int n, int j,int key) {
    if(j>=n){
        cout<<"Overflow"<<endl;
        return;
    }
    a[j] = key;
    heapify(a,0,n);
}
void heapsort(int a[], int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void deleteMax(int a[], int n) {
    if(n == 0) {
        cout << "Underflow" << endl;
        return;
    }
    int max = a[0];
    a[0] = a[n-1];
    n--;
    heapify(a, 0, n);
    cout << "Deleted Min Element: " << max << endl;
}

void print(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

int main(){
    int a[]={100,21,5,6,8,9,7,3,9,12};
    int n=sizeof(a)/sizeof(a[0]);
    // heapsort(a,n);
    buildHeap(a,n);
    // deleteMax(a,n);
    // heapsort(a,n-1);
    print(a,n);
    return 0;
}