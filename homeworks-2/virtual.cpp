#include <iostream>

// // virtual function's logic without using "virtual" keyword

class Base {
    public:
        void (*fooPtr)(Base*, int); // VirtualTable
        Base() {
            fooPtr = &Base::fooImpl;
        }
        static void fooImpl(Base* self, int x) {
            std::cout<<"Base: "<<x<<std::endl;
        }
        void foo(int x = 20) {
            fooPtr(this, x);
        }
};

class D : public Base {
    public:
        D() {
            fooPtr = &D::fooImpl;
        }
        static void fooImpl(Base* self, int x) {
            std::cout<<"Derived: "<<x<<std::endl;
        }
        void foo(int x = 100) {
            fooPtr(this, x);
        }
};

class D1 : public Base {
    public:
        D1() {
            fooPtr = &D1::fooImpl;
        }
        static void fooImpl(Base* self, int x) {
            std::cout<<"Derived1: "<<x<<std::endl;
        }
        void foo(int x = 456) {
            fooPtr(this, x);
        }
};

int main() {
    Base *obj = new D();
    obj -> foo(); // Derived, 20
    
    D *ptr = new D();
    ptr->foo(); // Derived 100
    
    // // using cast, but this is unsafe
    Base *b = new D();
    ((D*)b)->foo(); // Derived 100

    Base *base = new Base();
    base->foo(); // Base 20

    Base *d1 = new D1();
    d1->foo(); // Derived1 20

    // // cast is UNSAFE
    Base *d11 = new D1();
    ((D1*)d11)->foo(); // Derived1 456
    return 0;
}

/*
Սկզբում fooPtr-ը ցույց է տալիս բազային class-ի fooImpl-ի վրա, ինչպես virtual-ում։
Հետո Ժառանգի constructor-ը փոխումա իրա fooImpl-ի վրա: Նույն բանը մյուս ժառանգնա անում
*/