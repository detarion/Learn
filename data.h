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

int global_value;

void Data()
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
