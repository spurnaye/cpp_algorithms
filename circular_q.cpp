#include <iostream>
#include <vector>
#include "circular.h"

using namespace std;

int main(int argc, char* argv[])
{
       vector<int> v;

       v.push_back(1);
       v.push_back(2);
       v.push_back(3);

       const_circular_iter<vector<int> >out (v);     // or  “out(v.begin(), v.end());”

       cout << *out++;
       cout << *out++;
       cout << *out++;
       cout << *out++;
       cout << *out ++ << endl;

       return 0;
}