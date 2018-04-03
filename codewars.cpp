// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>
// #include <climits>
// #include <numeric>
// #include <list>
// #include <utility> 

// using namespace std;

// int sequenceSum(int, int, int);
// std::vector<int> invert(std::vector<int> values)
// {
//     std::transform(values.begin(), values.end(), values.begin(), [](int & x){return x*(-1);});
//     return values;
// }

// int divisors(long long);

// std::vector<int> climb(int);

// // int main(){
  
// // // This works in C and C++
// //   int a[] = { 1, 2, 3, 4 };
// //   int b[4];
// //   memcpy(b, a, 4*sizeof(int)); // int is a POD

// //   // This is the preferred method to copy raw arrays in C++ and works with all types that can be copied:
// //   std::copy(a, a+4, b);

// //   // In C++11, you can also use this:
// //   std::copy(std::begin(a), std::end(a), std::begin(b));

// //   // use of vectors
// //   std::vector<int> va(a, a+4); // copies the content of a into the vector
// //   std::vector<int> vb = va;    // vb is a copy of va

// //   // this initialization is only valid in C++11:
// //   std::vector<int> vc { 5, 6, 7, 8 }; // note: no equal sign!

// //   // assign vc to vb (valid in all standardized versions of C++)
// //   vb = vc;

// //   //alternative assignment, works also if both container types are different
// //   vb.assign(vc.begin(), vc.end());

// //   std::vector<int> vd; // an *empty* vector

// //   // you also can use std::copy with vectors
// //   // Since vd is empty, we need a `back_inserter`, to create new elements:
// //   std::copy(va.begin(), va.end(), std::back_inserter(vd));

// //   // copy from array a to vector vd:
// //   // now vd already contains four elements, so this new copy doesn't need to
// //   // create elements, we just overwrite the existing ones.
// //   std::copy(a, a+4, vd.begin());

// //   // C++11 only: Define a `std::array`:
// //   std::array<int, 4> sa = { 9, 10, 11, 12 };

// //   // create a copy:
// //   std::array<int, 4> sb = sa;

// //   // assign the array:
// //   sb = sa;

//   // int jumbo = 23;
//   // int * pe = &jumbo;
//   // cout << jumbo << endl;
//   // cout << pe << endl;

//   // std::vector <int> v = {1,-2,3,-4,5};
//   // for (auto x: invert(v)){
//   //   cout << x << endl;
//   // }

// //   cout << divisors(4);
// //   return 0;
// // }


// // std::vector<int> climb(int n)
// // {
// //     while(n >= 1){
      
// //     }
// //     return std::vector<int>();
// // }

// // int divisors(long long n){
// //   int divisors;
// //   for(long long i = 1; i < n; i++){
// //     (n%i == 0) ? divisors++:divisors;
// //   }
// //   return divisors;
// // }

// // int sequenceSum(int start, int end, int step)
// // {
// //   std::vector <int> v;
// //   for(int i = start; i <= end; i += step){
// //     v.emplace_back(i);
// //   }

// //   return std::accumulate(v.begin(), v.end(), 0);
// // }

// // int main(){
// //   vector<string> s = { "bitcoin", "take", "over", "the", "world", "maybe", "who", "knows", "perhaps" };
// //   partial_sort(begin(s), begin(s) + 1, end(s), [](string & s1, string & s2){ return s1[0] < s2[0];});
// //   string first = s[0];
// //   string transformed ="a";
// //   transform(begin(first), end(first), begin(transformed), [](unsigned char c){ 
// //       return toupper(c);});
// //   cout << transformed << endl;
// //   return 0;
// // }


// class Arge
// {
//   public:
//   static int nbYear(int p0, double percent, int aug, int p);
// };

// int Arge::nbYear(int p0, double percent, int aug, int p){
//     int n = 0;
//     while (p >= p0){
//       p0 += (p0 * percent * 0.01 + aug);
//       n += 1;
//     }
//     return n;
// }


// int main(){
//   int x = Arge::nbYear(1500, 5, 100, 5000);
//   cout << x << endl;
//   return 0;
// }




#include <iostream>
#include <map>
#include <vector>
// std::string randomCase(std::string x) {
//   std::string y;
//   return std::transform (x.begin(), 
//                   x.end(), 
//                   y.begin(), 
//                   y.end(), [](char & c)  {
//                   srand (time(NULL));
//                   int x = (rand()%100) % 2;
//                   return x == 0 ? tolower(c) :  toupper(c);
//                   });
// }


int main (){
  std::vector<int> v{1,2,1,2};
  std::unordered_map<int, int>
  int u = std::accumulate(v.begin(), v.end(), (uint32_t)0, [](uint32_t a, uint32_t b) { return a ^ b; });
  std::cout << u << std::endl;
  return 0;

}