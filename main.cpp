#include <locale>
#include <iostream>

#include <stdint.h> // int64_t
#include <string>
#include <array>
#include <vector>
#include <forward_list>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <bitset>

#include <algorithm>
#include <math.h>
#include <numeric>

int global_value;

void Containers()
{
    int value;
    static int static_value;
    int64_t value64;
    std::string string_data;

    int rows{3}, cols{2};
    int array_int1[cols];
    int array_int2[rows][cols];

    std::array<int, 10> array_data;
    std::vector<int> vector_data;

    std::forward_list<int> forward_list;
    std::list<int> list_data;

    std::stack<int> stack_data;

    std::queue<int> queue_data;
    std::priority_queue<int> pririty_queue_data;
    std::priority_queue<int, std::vector<int>, std::greater<int>> priority_greater_queue;
    std::deque<int> deque_data;

    std::vector<int> data {1, 2, 3, 4};
    std::make_heap(data.begin(), data.end());

    std::unordered_set<int> unordered_set_data;
    std::unordered_map<int, int> unordered_map_data;
    std::unordered_multiset<int> unordered_multi_set_data;
    std::unordered_multimap<int, int> unordered_multi_map_data;

    std::set<int> set_data;
    std::map<int, int> map_data;
    std::multiset<int> multi_set_data;
    std::multimap<int, int> multi_map_data;

    std::bitset<8> bitset_data;
}

void Algorithms()
{
    std::string text {"1234"};
    std::vector<int> data {1, 2, 3, 4};
    std::vector<int> data2;

    auto bIsAlpha = std::isalpha('1'); // 0
    auto upper_symbol = std::toupper('a'); // 65 (A)
    auto low_symbol = std::tolower('A'); // 97 (a)

    auto abs = std::abs(-1); // 1
    auto min = std::min(1, 2); // 1
    auto max = std::max(1, 2); // 2
    auto pow = std::pow(10, 2); // 100
    auto floor = std::floor(1.5); // 1
    auto round = std::round(1.5); // 2
    
    auto sum = std::accumulate(data.begin(), data.end(), 0); // 10
    auto min_it = std::min_element(data.begin(), data.end());
    auto max_it = std::max_element(data.begin(), data.end());
    auto [min_it2, max_it2] = std::minmax_element(data.begin(), data.end());
    
    std::swap(text[0], text[1]); // 2134
    std::reverse(data.begin(), data.end()); // 4321

    auto find1 = std::find(data.begin(), data.end(), 3);
    auto find2 = std::find_if(data.begin(), data.end(),
        [](auto value)
        {
            return value % 2;
        });
    auto find3 = std::find_if_not(data.begin(), data.end(),
        [](auto value)
        {
            return value % 2;
        });

    data2.reserve(data.size());
    std::copy(data.begin(), data.end(), data2.begin());
    std::copy_if(data.begin(), data.end(), data2.begin(),
        [](auto value)
        {
            return value % 2;
        });

    // remove-erase
    // ...

    // удаление дубликатов
    // ...

    std::sort(data.begin(), data.end());

    for (size_t i = 0; i < data.size(); i++)
    {
        /* code */
    }

    for(auto it = data.begin(); it != data.end(); ++it)
    {
        /* code */
    }

    for(auto item : data)
    {
        /* code */
    }

    while(false)
    {
        /* code */
    }

    do
    {
        /* code */
    } while (false);    
}

void BubbleSort(std::vector<int>& data)
{
    for (size_t i = 0; i < data.size(); i++)
    {
        for (size_t j = 0; j < data.size() - 1 - i; j++)
        {
            if (data[j] > data[j+1])
            {
                std::swap(data[j], data[j+1]);
            }            
        }
    }
}

void BubbleOptSort(std::vector<int>& data)
{
    for (size_t i = 0; i < data.size(); i++)
    {
        bool is_sort {true};

        for (size_t j = 0; j < data.size() - 1 - i; j++)
        {
            if (data[j] > data[j+1])
            {
                std::swap(data[j], data[j+1]);
                is_sort = false;
            }
        }

        if (is_sort)
            break;
    }
}

void ShakerSort(std::vector<int>& data)
{
    for (size_t i = 0; i < data.size(); i++)
    {
        for (size_t j = 0; j < data.size() - 1; j++)
        {
            if (data[j] > data[j+1])
            {
                std::swap(data[j], data[j+1]);
            }
        }

        for (size_t j = data.size() - 1; j > 0; j--)
        {
            if (data[j-1] > data[j])
            {
                std::swap(data[j-1], data[j]);
            }
        }
    }    
}

void ShakerOptSort(std::vector<int>& data)
{
    size_t begin_index{0};
    size_t end_index{data.size()};

    for (size_t i = begin_index; i + 1 < end_index; i++)
    {
        bool is_sort {true};

        for (size_t j = begin_index; j + 1 < end_index; j++)
        {
            if (data[j] > data[j+1])
            {
                std::swap(data[j], data[j+1]);
                is_sort = false;
            }
        }

        if (is_sort)
            break;

        is_sort = true;
        end_index--;

        for (size_t j = end_index - 1; j > begin_index; j--)
        {
            if (data[j-1] > data[j])
            {
                std::swap(data[j-1], data[j]);
                is_sort = false;
            }
        }

        if (is_sort)
            break;
        
        begin_index++;
    }    
}

void SelectionSort(std::vector<int>& data)
{
    for (size_t i = 0; i < data.size(); i++)
    {
        size_t min_index = i;

        for (size_t j = i; j < data.size(); j++)
        {
            if (data[j] < data[min_index])
            {
                min_index = j;
            }
        }

        std::swap(data[i], data[min_index]);
    }
}

void SelectionOptSort(std::vector<int>& data)
{
    size_t begin_index {0};
    size_t end_index {data.size() - 1};

    while (begin_index < end_index)   
    {
        size_t min_index {begin_index};
        size_t max_index {end_index};

        for (size_t i = begin_index; i <= end_index; i++)
        {
            if (data[i] < data[min_index])
                min_index = i;

            if (data[i] > data[max_index])
                max_index = i;
        }

        if (begin_index != min_index)
            std::swap(data[begin_index], data[min_index]);

        if (max_index == begin_index)
            max_index = min_index;

        std::swap(data[end_index], data[max_index]);

        begin_index++;
        end_index--;
    }
}

void InsertionSort(std::vector<int>& data)
{
    for (size_t i = 0; i < data.size(); i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if(data[i] > data[j])
            {
                data.insert(data.begin() + j, data[i]);
                data.erase(data.begin() + i);
            }
        }
    }
}

void InsertionOptSort(std::vector<int>& data)
{
    for (size_t i = 1; i < data.size(); i++)
    {
        int key = data[i];
        int index = static_cast<int>(i - 1);

        while (index >= 0 && data[index] > key)
        {
            data[index+1] = data[index];
            index--;
        }

        data[index + 1] = key;
    }
}

void MergeSort(std::vector<int>& data)
{
    if (data.size() <= 1)
        return;

    size_t middle_index = data.size() / 2;
    
    std::vector<int> left_data = {data.begin(), data.begin() + middle_index};
    std::vector<int> right_data = {data.begin() + middle_index, data.end()};    
    
    MergeSort(left_data);
    MergeSort(right_data);

    data.clear();
    std::merge(left_data.begin(), left_data.end(), right_data.begin(), right_data.end(), std::back_inserter(data));
}

void HeapSort(std::vector<int>& data)
{
    std::make_heap(data.begin(), data.end());
    std::sort_heap(data.begin(), data.end());
}

void Sorts()
{
    std::vector<int> data {64, 34, 25, 12, 73, 49, 3, 22, 11, 90};
    BubbleSort(data);
    data = {64, 34, 25, 12, 73, 49, 3, 22, 11, 90};
    BubbleOptSort(data);

    data = {64, 34, 25, 12, 73, 49, 3, 22, 11, 90};
    ShakerSort(data);
    data = {64, 34, 25, 12, 73, 49, 3, 22, 11, 90};
    ShakerOptSort(data);

    data = {64, 34, 25, 12, 73, 49, 3, 22, 11, 90};
    SelectionSort(data);
    data = {64, 34, 25, 12, 73, 49, 3, 22, 11, 90};
    SelectionOptSort(data);

    data = {64, 34, 25, 12, 73, 49, 3, 22, 11, 90};
    InsertionSort(data);
    data = {64, 34, 25, 12, 73, 49, 3, 22, 11, 90};
    InsertionOptSort(data);

    data = {64, 34, 25, 12, 73, 49, 3, 22, 11, 90};
    MergeSort(data);
    //data = {64, 34, 25, 12, 73, 49, 3, 22, 11, 90};
    //MergeOptSort(data);

    data = {64, 34, 25, 12, 73, 49, 3, 22, 11, 90};
    HeapSort(data);

    std::vector<int> sort_data = {3, 11, 12, 22, 25, 34, 49, 64, 73, 90};
    if (data != sort_data)
        throw std::exception();
}

void TaskOOP1()
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

void OOP()
{
    TaskOOP1();
}

int main()
{
    std::setlocale(LC_ALL, "");

    Containers();
    Algorithms();
    Sorts();
    OOP();

    return 0;
}