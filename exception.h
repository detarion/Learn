

void Exception1()
{
    // void funct() noexcept
    // {}

    try
    {
        throw std::string("error");
    }
    catch(const std::string& e)
    {
        std::cerr << e.c_str() << std::endl;
    }

    // вывод в терминал
    // error
}

void Exception2()
{
    class Exception :std::exception
    {
        public:
            Exception(std::string& message)
            {};

            Exception(std::string&& message)
            {};

            const char* what() const noexcept override
            { return "bad optional access"; }
    };

    class A
    {        
        public:
            A()
            { std::cout << "A()" << std::endl;}

            ~A()
            { std::cout << "~A()" << std::endl;}

            void Calc(int a, int b)
            {
                throw Exception{"Division by zero"};
            }
    };

    try
    {
        A a;
        a.Calc(10, 12);
        
        std::cout << "Success" << std::endl;
    }
    catch(const Exception& error)
    {
        std::cout << "Exception: " << error.what() << std::endl;
    }
    catch(const std::exception& error)
    {
        std::cout << "std::exception: " << error.what() << std::endl;
    }
    catch(...)
    {
        std::cout << "Error: ..." << std::endl;
    }

    // вывод в терминал
    // A()
    // ~A() - вызов деструктора при выходе из обсласти видимости try-catch
    // Exception: Division by zero
}

void Exception3()
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
        // объект не сконструирован
        // вызов очистки стека сконструированных объектов
        // A()
        // ~A()
        B()
        {
            //throw std::string("error");
        }

        // вызов std::terminate, т.к. нет кода обработки исключений (noexcept)
        B(const B& b) noexcept
        {
            // ошибка: при noexcept не должно быть исключений
            //throw std::string("error");
        }

        // вызов std::terminate

        ~B()
        {
            // ошибка: все исключения нужно подавить внутри деструктора
            // throw std::string("error");

            try
            {
                throw std::string("error");
            }
            catch(...)
            {
            }
        }
    };

    try
    {
        B b;
        //B c(b);

        throw std::string("error");
    }
    catch(const std::string& e)
    {
        std::cerr << e.c_str() << '\n';
    }
}

void Exceptions()
{
    Exception1();
    Exception2();
    Exception3();
}

