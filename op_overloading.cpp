#include<iostream>
using namespace std;

class complex{
    int real;
    int img;
    public:
    complex():real(0),img(0){}
    complex(int a,int b ):real(a),img(b){}
    complex operator +(complex c){ 
        return complex(real + c.real,img + c.img);
    }
    // friend complex operator +(complex c1,complex c2){
    //     complex  temp;
    //     temp.real = c1.real + c2.real;
    //     temp.img = c1.img + c2.img;
    //     return  temp;
    // }
    void print(){
        if(real==0)
            cout<<img<<"i";
        else
            cout<<real<<" + "<<img<<"i";
            cout<<endl;
    }
friend  ostream& operator <<(ostream& out,complex &c){
    if(c.real==0){
        out<<c.img<<"i";
    }else{
        out<<c.real<<" + "<<c.img<<"i";
    }
    return out;
}
friend istream& operator >>(istream& in , complex& c){
    in>>c.real;
    in>>c.img;
    return in;
}
};

int main(){
    complex c1(2,3);
    complex c2(4,5);
    complex c4(6,9);

    complex c3,c7,c6;
    c3= c1+c2;
    complex c5= c1+c2+c3;
    c3.print();
    c5.print();
    
    cin>>c6;
    cout<<c6;

}