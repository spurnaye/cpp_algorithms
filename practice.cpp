#include <iostream>

// find fibonacci using template meta-programming
template <long long N>
struct fibonacci{
  static constexpr long long value = fibonacci<N-1>::value + fibonacci<N-2>::value;
};

template<>
struct fibonacci<1>{
  static constexpr long long value = 1;
};

template<>
struct fibonacci<0>{
  static constexpr long long value = 0;
};

// end code for fibonacci
// -------------------------------------------------------------------------------------------
// find gcd using template meta programming
template<unsigned M, unsigned N>
struct gcd{
  static constexpr auto value = gcd<N,M%N>::value;
};

template<unsigned M>
struct gcd<M,0>{
  static_assert(M!=0);
  static constexpr auto value = M;
};
// -------------------------------------------------------------------------------------------

// factorial using template meta-programming

template<long long N>
struct factorial{
  static constexpr long long value = N*(factorial<N-1>::value);
};

template<>
struct factorial<0>{
  static constexpr long long value = 1;
};
// -------------------------------------------------------------------------------------------
// X*Y using templates

template<long long x, long long y>
struct multiply{
  static constexpr long long value = N*(factorial<N-1>::value);
};

template<>
struct multiply<0>{
  static constexpr long long value = 1;
};
// -------------------------------------------------------------------------------------------


int main(){
  std::cout << gcd<15,5>::value << '\n'; // 5
  std::cout << fibonacci<80>::value << '\n'; // 23416728348467685
  std::cout << factorial<20>::value << '\n'; // 2432902008176640000
}