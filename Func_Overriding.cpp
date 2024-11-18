#include<iostream>
using namespace std;

class Coding_lang{
    public:
    void use(){
        cout<<"I am used for communicating with computers"<<endl;
    }
};
class C : public Coding_lang{
    public:
    void use(){
        cout<<"I am one of  programming languages most widely used by new progarmmers. "<<endl;
    }
};
class Java : public Coding_lang{
    public:
    void use(){
        cout<<"I am mostly used for backend and development purposes. "<<endl;
    }
};

int main(){
    // Coding_lang *obj;

    C obj1;
    Java obj2;
    Coding_lang obj3;
    // obj= &obj3;
    obj1.use();
    // obj= &obj1;
    obj2.use();
    // obj= &obj2;
    obj3.use();
}