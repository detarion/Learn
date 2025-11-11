#include <string>
#include <vector>

#include <algorithm>
#include <math.h>
#include <numeric>

void STL_Algorithm()
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

void SortAlgorithm()
{
    std::vector<int> data {64, 34, 25, 12, 73, 49, 3, 22, 11, 90};
    BubbleSort(data);

    data = {64, 34, 25, 12, 73, 49, 3, 22, 11, 90};
    ShakerSort(data);

    data = {64, 34, 25, 12, 73, 49, 3, 22, 11, 90};
    SelectionSort(data);

    data = {64, 34, 25, 12, 73, 49, 3, 22, 11, 90};
    InsertionSort(data);

    data = {64, 34, 25, 12, 73, 49, 3, 22, 11, 90};
    MergeSort(data);

    data = {64, 34, 25, 12, 73, 49, 3, 22, 11, 90};
    HeapSort(data);

    std::vector<int> sort_data = {3, 11, 12, 22, 25, 34, 49, 64, 73, 90};
    if (data != sort_data)
        throw std::exception();
}

void TaskAlgorithm()
{
    // PrefixSum(); // Префиксные суммы
    // TwoPointers(); // Два указателя
    // SlidingWindow(); // Скользящее окно
    // FastAndSlowPointers(); // Быстрый и медленный указатель
    // ReversList(); // Разворот связного списка на месте
    // MonotonicStack(); // Монотонный стек
    // TopElements(); // Топ K элементов
    // OverlappingIntervals(); // Перекрывающиеся интервалы
    // ModifiedBinarySearch(); // Модифицированный бинарный поиск
    // BinaryTreeTraversal(); // Обход бинарного дерева
    // DepthFirstSearch(); // DFS поиск в глубину
    // BreadthFirstSearch(); // BFS поиск в ширину
    // MatrixTraversal(); // Обход матрицы
    // BackTracking(); // Возврат
    // DynamicProgramming(); // Динамическое программирование
}

void Algorithms()
{
    STL_Algorithm();
    SortAlgorithm();
    TaskAlgorithm();
}

