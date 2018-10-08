// what is Dijkstra's algorithm
// what is spanning tree
// Thread safe Singleton implementation.  
//  solve a Sudoku puzzle
// Write a function that converts a column indicated by a String (e.g A, B, ..., Z, AA, AB, ...) into a number (1, 2, ..., 26, 27, 28, ...).  
// LeetCode problems: 49, 53, 69, 151, 235, 258, 388, 448
// difference between : list, set, map, sortedset,
// difference between : hashmap n hashset
// difference between : hashmap,linkedmap, treemap
// difference between : Arraylist, vector, LL
// difference between : interface n abstract class
// Q. static method possible in abstract class and in interface?

#include <iostream>
#include <type_traits>
#include <vector>
#include <boost/lexical_cast.hpp>
using namespace std;


template <typename T>
T std::enable_if<std::is_integral<T>::value>::type
struct S{};

int main() {
    cout << "Hello, World!" << endl;
    std::vector<int> v {1,2,3,4,5,6,7,8};

    std::for_each(v.begin(), v.end(), [](const auto & x){ std::cout << x << '\n';});
    return 0;
}