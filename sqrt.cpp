/* sqrt example */
#include <stdio.h>      /* printf */
#include <math.h>       /* sqrt */

int main ()
{
  double param;
  int result;
  param = 3;
  result = sqrt (param);
  printf ("sqrt(%f) = %d\n", param, result );
  return 0;

}