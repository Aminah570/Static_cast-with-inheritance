#include <iostream>
#include <string>
using namespace std;

class Animal{
    protected:
        string m_name;
    public:
        Animal(string n){
            m_name=n;
        }
        void makeSound(){
            cout<<"Hmmmm... we dont really know what sound "<<m_name<<" makes"<<endl;
        }
    
};

class Cat: public Animal{
  public:
    Cat(string n) : Animal(n){}
    void makeSound(){
        cout<<m_name<<" says MEOOWWW"<<endl;
    }
    
};
class Dog: public Cat{
    public:
        Dog(string s): Cat(s){}
};
int main(){
    Animal *myA=new Cat("Oreo");
    //before static_cast
    myA->makeSound(); //Animal version
    //after static_cast
    static_cast<Cat *>(myA)->makeSound(); // Cat version, no safety check
    
}
