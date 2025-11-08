#include <locale>

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

void Sorts()
{
    std::vector<int> data {64, 34, 25, 12, 73, 49, 3, 22, 11, 90};
    BubbleSort(data);

    data = {64, 34, 25, 12, 73, 49, 3, 22, 11, 90};
    BubbleOptSort(data);

    if (!std::is_sorted(data.begin(), data.end()))
        throw std::exception();
}

int main()
{
    std::setlocale(LC_ALL, "");

    Containers();
    Algorithms();
    Sorts();

    return 0;
}