#include <iostream>
#include <vector>
#include <list>
#include <chrono>

using namespace std::chrono;
using namespace std;

void append_to_vector()
{
    vector<int> vec;
    for (int i = 0; i < 1000; ++i) {
        vec.push_back(i);
    }
}

void append_to_list()
{
    list<int> lst;
    for (int i = 0; i < 1000; ++i) {
        lst.push_back(i);
    }
}

void measure_duration()
{
    // Измеряем время выполнения для вектора
    auto start_vector = high_resolution_clock::now();
    for (int i = 0; i < 1000; ++i) {
        append_to_vector();
    }
    auto end_vector = high_resolution_clock::now();
    auto vector_duration = duration_cast<milliseconds>(end_vector - start_vector).count();

    // Измеряем время выполнения для списка
    auto start_list = high_resolution_clock::now();
    for (int i = 0; i < 1000; ++i) {
        append_to_list();
    }
    auto end_list = high_resolution_clock::now();
    auto list_duration = duration_cast<milliseconds>(end_list - start_list).count();

    // Выводим результаты
    cout << "Время выполнения для вектора: " << vector_duration << " миллисекунд" << endl;
    cout << "Время выполнения для списка: " << list_duration << " миллисекунд" << endl;
}

void measure_size()
{
    std::vector<int> vec(1000);  // Вектор из 1000 элементов
    std::list<int> lst(1000);    // Список из 1000 элементов

    // Размер вектора
    size_t vector_memory = sizeof(vec) + (vec.capacity() * sizeof(int));

    // Размер списка
    size_t list_memory = sizeof(lst);
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        list_memory += sizeof(*it);
    }

    std::cout << "Объем памяти, занимаемый вектором: " << vector_memory << " байт" << std::endl;
    std::cout << "Объем памяти, занимаемый списком: " << list_memory << " байт" << std::endl;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    measure_size();
    measure_duration();

    return 0;
}