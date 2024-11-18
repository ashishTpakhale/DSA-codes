#include<iostream>
//#include<vector>
#include<string>
using namespace std;

template <class T> class stack{
    T a[10];
    int top;
    public:
    stack() {
        top=-1;
    }

    void push(T ele){
        if(top==-1)
           top++;
        a[top++]= ele;
    }
    T pop(){
        T temp=a[top--];
        return temp;
    }
    bool isEmpty(){
        return top == -1;
    }
    void display(){
        cout<<"Stack is : ";
        for(int i = 0; i < top; i++){
            cout << a[i] << " ";
        }    
        cout << endl;
    }
    
};
 
template <class T1> T1 func(T1 a, T1 b){
    cout<<"This is func called of type T1 "<<endl;
    cout<<a<<" "<<b <<endl;
} 



class Employee{
    public:
        int id;
        string name;
        Employee(){
            id = 0;
            name = " ";
        }
        Employee(int i, string n){
            id = i;
            name = n;
        }
        void display(){
            cout << " ID: "<<id << "Name: "<<name <<endl;
        }
        friend ostream& operator<<(ostream& os, Employee& e) {
            os << e.id<<" "<< e.name;
            return os;
        }
        // friend istream& operator>>(istream& in, Employee& )
        
};


int main(){
    stack<char> charS;
    stack<int> intS;
    stack<Employee> empS;


    charS.push('A');
    charS.push('B');
    charS.push('C');
    charS.display();

    intS.push(123);
    intS.push(456);
    intS.push(789);
    intS.display();

    Employee e1(1,"John");
    Employee e2(2,"Alice");
    Employee e3(3,"Bob");

    empS.push(e1);
    empS.push(e2);
    empS.push(e3);
    int a;
    // cout << "Stack after push: ";
    empS.display();
    // cout << "Popped element: ";
    Employee temp = empS.pop();
    a=func<char>(4,3);
    

    return 0;
};