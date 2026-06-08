
void OOP1()
{
    // Инкапсуляция
    // Наследование
    // Полиморфизм
    // Абстракция

    struct A
    {
        // оптимизация Выравнивание от большего к меньшему
        double b;    // 8 байт
        int c;       // 4 байта + 4 байта padding (для выравнивания всей структуры по 8 байт)
        char a;      // 1 байт + 7 байт padding

        void Func1()
        {
            int temp = this->a;
        }
    };

    A a;
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

    B* pC = new C();
    
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

void OOP3()
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

void SmartPointer()
{
    // умные указатели
    std::unique_ptr unique_ptr = std::make_unique<int>(10);
    std::shared_ptr shared_ptr = std::make_shared<int>(10);
    std::weak_ptr weak_ptr = shared_ptr;

    if (unique_ptr)
    {
        shared_ptr = std::move(unique_ptr);
    }
}

void OOP()
{
    OOP2();
    OOP3();
    SmartPointer();
}