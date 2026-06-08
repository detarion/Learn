#include <memory>
#include <optional>
#include <vector>

void Func1()
{
}

int Func2()
{
    return 10;
}

int Func3(int value1, int& value2, int&& value3)
{
    return 10;
}

std::vector<int> Func4()
{
    // NRVO - Name return value optimization
    std::vector<int> vec = {1, 2, 3};
    return vec;
}

template<typename T>
T Func5(T value1, T value2)
{
    return value1 + value2;
}

std::pair<bool, int> Func6()
{
    return {true, 10};
}
std::optional<int> Func7()
{
    if (true)
        return 10;
    else
        return std::nullopt;
}

int global_value1;
int global_value2 = 10;

void StandartCpp17()
{
    {   // переменные
        int value1;
        int value2 = 10;
        double value3 {10.4};
    
        static int static_value = 10;

        int* p_value = nullptr;
        p_value = &value2;
        (*p_value)++;
        auto value4 = *p_value;

        int* r_value = &value2;
        r_value++;
    }

    if(true)
    { }

    std::vector<int> vec = { 1, 2, 3};

    for (size_t i = 0; i < vec.size(); ++i)
        int temp = vec[i];

    for (auto it = vec.begin(); it != vec.end(); ++it)
        int temp = *it;

    for (auto item : vec)
        int temp = item;

    for (const auto item : vec)
        int temp = item;

    for (auto& item : vec)
        int temp = item;

    {
        Func1();
        auto result2 = Func2();
        int value1 = 10, value2 = 11;
        auto result3 = Func3(value1, value2, 12);
        auto result4 = Func4();
        auto result5 = Func5(10, 12);

        auto result7 = Func7();
        if (result7)
            int temp = *result7;
    }

    // C++11
    // std::move
    // std::forward
    // лямбда-фунции
    // constexpr Вычисления на этапе компиляции
    // умные указатели

    // C++14
    // полировка С++11

    // С++17
    // auto result5 = Func5(10, 12);
    // std::optional, std::variant, std::any
    // if constexpr
    // std::string_view
    // std::filesystem
    // if(auto res = ...)
    // std::sort(std::execution::par, vec.begin(), vec.end()); // Сортировка в несколько потоков!
}