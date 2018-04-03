#include <cmath>
#include <iostream>

bool IsPrime(int number){
  if (number == 2 || number == 3)
        return true;

    if (number % 2 == 0 || number % 3 == 0)
        return false;

    int divisor = 6;
    while (divisor * divisor - 2 * divisor + 1 <= number)
    {

        if (number % (divisor - 1) == 0)
            return false;

        if (number % (divisor + 1) == 0)
            return false;

        divisor += 6;

    }

    return true;

}
int nextPrime (int num )
{
  while (!IsPrime(++num)) 
    { }
    return num;
}


int main(){

  std::cout << nextPrime(0) << std::endl;
  std::cout << nextPrime(5) << std::endl;
}