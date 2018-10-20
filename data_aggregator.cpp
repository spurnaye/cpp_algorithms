#include <atomic>
#include <vector>
#include <iostream>
using atomic_ptr = std::atomic<uint32_t*>;

//std::vector<int>{}

enum class Venue : std::int8_t
{
    VENUE1 = 1,
    VENUE2 = 2,
    VENUE3 = 3,
};

enum class StockSymbol : std::int8_t
{
    AXP = 0,
AAPL = 1,
BA = 2,
CAT = 3,
CSCO = 4,
CVX = 5,
DWDP = 6,
XOM = 7,
GS = 8,
HD = 9,
IBM = 10,
INTC = 11,
JNJ = 12,
KO = 13,
JPM = 14,
MCD = 15,
MMM = 16,
MRK = 17,
MSFT = 18,
NKE = 19,
PFE = 20,
PG = 21,
TRV = 22,
UNH = 23,
UTX = 24,
VZ = 25,
V = 26,
WBA = 27,
WMT = 28,
DIS = 29,
};



int main(){
  atomic_ptr t1;
  atomic_ptr t2;
  atomic_ptr t3;

  int a = static_cast<std::int8_t>(Venue::VENUE3);


  //std::vector<>

}