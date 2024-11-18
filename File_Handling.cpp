#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main(){
    string filename = "temp.txt";
    string data;

    ofstream write(filename);
    while (write) {
        getline(cin, data);
        if (data=="-1")
            break;
        write << data << endl;
    }
    write.close();

    ifstream read(filename);
    string dataR;
    while ( getline(read, dataR)){
        cout << dataR << endl;
    }
    read.close();

    // ofstream file("CHARS", (ios::out | ios::binary));
    // if(!file) {
    //     cout << "Cannot open output file.\n";
    //     return 1;
    // }
    // for(int i=0; i<256; i++){
    //     file.put((char)i);
    // }
    // file.close();
    
    ifstream file2("temp.txt", (ios::in | ios::binary));
    if(!file2) {
        cout << "Cannot open input file.\n";
        return 1;
    }
    char ch;
    while(file2.get(ch)){
        cout << ch;
    }
    file2.close();

}