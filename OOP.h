void OOP1()
{
    struct A
    {
        A()
        {
            std::cout << "A()" << std::endl;
        }

        virtual ~A()
        {
            std::cout << "~A()" << std::endl;
        }
    };
        
    struct B : A
    {
        B()
        {
            std::cout << "B()" << std::endl;
        }

        ~B()
        {
            std::cout << "~B()" << std::endl;
        }
    };

    struct PropertyA
    {
        PropertyA(int)
        {
            std::cout << "PropertyA()" << std::endl;
        }

        ~PropertyA()
        {
            std::cout << "~PropertyA()" << std::endl;
        }
    };
        
    struct PropertyB
    {
        PropertyB(int)
        {
            std::cout << "PropertyB()" << std::endl;
        }

        ~PropertyB()
        {
            std::cout << "~PropertyB()" << std::endl;
        }
    };

    struct C : B
    {
        C() : propertyB_(1), propertyA_(1)
        {
            std::cout << "C()" << std::endl;
        }

        ~C()
        {
            std::cout << "~C()" << std::endl;
        }

        PropertyA propertyA_;
        PropertyB propertyB_;
    };

    A* pC = new C();
    
    std::cout << "..." << std::endl;

    delete pC;
    pC = nullptr;

    // A()
    // B()
    // PropertyA()
    // PropertyB()
    // C()
    // ...
    // ~C()
    // ~PropertyB()
    // ~PropertyA()
    // ~B()
    // ~A()
}

void OOP2()
{
    struct A
    {
        A()
        {
            std::cout << "A()" << std::endl;
        }

        virtual ~A()
        {
            std::cout << "~A()" << std::endl;
        }

        void Function()
        {
            Print();
        }

        virtual void Print()
        {
            std::cout << "A::Print()" << std::endl;
        }
    };
        
    struct B : A
    {
        B()
        {
            std::cout << "B()" << std::endl;
        }

        ~B()
        {
            std::cout << "~B()" << std::endl;
        }

        void Function()
        {
            Print();
        }

        void Print() override
        {
            std::cout << "B::Print()" << std::endl;
        }
    };

    struct C : B
    {
        C()
        {
            std::cout << "C()" << std::endl;
            A::Function();
        }

        ~C()
        {
            std::cout << "~C()" << std::endl;
        }

        void Function()
        {
            Print();
        }

        void Print() override
        {
            std::cout << "C::Print()" << std::endl;
        }
    };

    A* p = new C();
   
    std::cout << "..." << std::endl;

    delete p;
    p = nullptr;

    // A()
    // B()
    // C()
    // C::Print()
    // ...
    // ~C()
    // ~B()
    // ~A()
}

void OOP()
{
    OOP1();
    OOP2();
}