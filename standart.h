#include <memory>
#include <optional>

int Func1()
{
    int value {10};
    return value;
}

std::pair<bool, int> Func2()
{
    return {true, 10};
}

std::optional<int> Func3()
{
    return 10;
    return std::nullopt;
}

void StandartCpp17()
{
    int* p = nullptr;

    for (auto item : {1, 2, 3})
    { }    

    // умные указатели
    std::unique_ptr unique_ptr = std::make_unique<int>(10);
    std::shared_ptr shared_ptr = std::make_shared<int>(10);
    std::weak_ptr weak_ptr = shared_ptr;

    {
        auto result = Func1();
    }
    
    {
        auto [success, result] = Func2();
    }
    
    {
        auto result = Func3();
        if (result)
            auto value = *result;

        if (result.has_value())
            auto value = *result;
    }
}