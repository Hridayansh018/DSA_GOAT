#include <iostream>
using namespace std;

class BaseClass{
    public:
    int varBase;
    void display(){
        cout << "Displaying Base Class Variable varBase " << varBase <<endl;
    }
};



// DerivedClass inherits BaseClass
class DerivedClass : public BaseClass{
    public:
    int varDerived;
    void display(){
        cout << "Displaying Base Class Variable varBase " << varBase <<endl;
        cout << "Displaying Derived Class Variable varDeraived " << varDerived <<endl;
    }
};



int main(){

    // int a = 10;
    // int* p = &a;
    // cout << a << endl;
    // cout << &a << endl;
    // cout << p << endl;
    // cout << *p << endl;
    
    // int x = 15;
    // int* y = &x;
    // *y = *y+1;
    // cout<<x;


    // Created a BaseClass Pointer
    BaseClass * base_class_pointer;
    // Created a BaseClass Object
    BaseClass objbase;
    // Created a DerivedClass Object
    DerivedClass objderived;
    // BaseClass pointer is pointing DerivedClass
    base_class_pointer = &objderived;
    // Accessing BaseClass Variable
    base_class_pointer->varBase=12;
    base_class_pointer->display();
   
    // it will throw error because the pointer is of baseclass not DerivedClass so we can not access DerivedClass property
    
    // base_class_pointer->varDerived=20;
    // base_class_pointer->display();


    // Creating a derived class pointer
    DerivedClass * derived_class_pointer;
    // we want this pointer to point at DerivedClass object
    derived_class_pointer = &objderived;
    // Accessing DerivedClass Properties
    derived_class_pointer->varBase=23;
    derived_class_pointer->varDerived=100;
    derived_class_pointer->display();

    /*

    The arrow operator ( -> ) is like dereference operator

    for example we access the properties of an object by dereferencing it via (*ptr).property(); - like this.
    but with this arrow operator we can directly access the object property.
    
    it works like we created an object and then created a pointer for it, 
    then we use arrow operator - so it will access the property of object that is being pointed by dereferencing it.

    that allowes us to use :- 
    derived_class_pointer->display();
    istead of :-
    (*derived_class_pointer).display();

    */

    return 0;
}