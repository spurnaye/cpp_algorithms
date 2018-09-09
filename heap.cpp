#include <iostream>
#include <algorithm> // for heap operations
#include <vector>
using namespace std;
int main()
{
     
    // Initializing a vector
    vector<int> v1{20, 30, 40, 25, 15};
     
    // Converting vector into a heap
    // using make_heap()
    make_heap(v1.begin(), v1.end());
     
    // Displaying the maximum element of heap
    // using front()
    cout << "The maximum element of heap is : ";
    cout << v1.front() << endl;
    for_each(v1.begin(), v1.end(), [](const auto & i){std::cout << i << '\n';});
    sort_heap(v1.begin(), v1.end());
    for_each(v1.begin(), v1.end(), [](const auto & i){std::cout << i << '\n';});
    return 0;
}
