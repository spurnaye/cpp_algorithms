/*

 RightLessThanMilionTests
 Log
left : 193303 right : 289384
Expected: equal to 916107
Actual: 985335
 SmallSegmentsTests
 Log
left : 476744280 right : 477171088
Expected: equal to 6676768
Actual: 4673524
 SmallRandomSegments
 Log
left : 29582 right : 368382
Expected: equal to 3119172
Actual: 2977072
 RightLessThanBilionTests
 Log
left : 4250829 right : 231192380
Expected: equal to 3131546184
Actual: 2986077936
 OneBilionElementsSegment
 Log
left : 1 right : 1000000000
Expected: equal to 14846928141
Actual: 14088844544
         1962026253
 RandomSegments
 Log
left : 327707248 right : 727368382
Expected: equal to 5983557006
Actual: 5799920913

*/
#include <iostream>
#include <algorithm>
#include <cmath>

long long ccb(int col, int n) {
  double division = (n + 1) / double(2 << col);
  int sum = static_cast<int>(division);
  long long rest = std::max(0.0, (division - sum) * (2 << col) - (1 << col));
  return sum * (1 << col) + rest;
}

long long cab(int n) {
  long long bits = 0;
  for (int i = 0; i < 30; i++) {
    bits += ccb(i, n);
  }
  return bits;
}

long long countOnes(int left, int right) {
  return cab(right) - cab(left - 1);
}
 
int main(){
    std::cout << countOnes(1, 1000000000) << '\n';
}

