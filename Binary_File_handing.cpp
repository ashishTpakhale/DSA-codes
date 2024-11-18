#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main(){
    string filename = "temp.txt";
    string data;
    ofstream file("CHARS", (ios::out | ios::binary));
    if(!file) {
    cout << "Cannot open output file.\n";
    return 1;
    }
    // cout<<"Number of chars : ";
    // int n;
    // cin>>n;
    for(int i=0; i<256; i++){
        file.put((int)i);
        // file.put();15
    } 
    file.close();
    return 0;
}