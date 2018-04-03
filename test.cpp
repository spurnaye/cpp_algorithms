#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <functional>
#include <string>

using namespace std;
int main(){

  // ruby
  // v = [*1..10]

  vector<int> v(10);
  iota(begin(v), end(v),1);
  
  cout << *begin(v) << endl;
  cout << *end(v) << endl;
  cout << "---" << endl;
  // ruby
  // puts v.join(' ')
  for_each(begin(v), end(v), [](int i){ cout << i << ' ';});
  cout << endl;

  // v.reduce(:+)
  auto sum = accumulate(begin(v), end(v), 0);
  cout << sum << endl;

  // v.reduce(1, :*)
  auto mult = accumulate(begin(v), end(v), 1, multiplies<int>());
  cout << mult << endl;

  // v.any?{|el| el % 2 == 0}
  bool flag = any_of(begin(v), end(v), [](int i){ return i % 2 == 0;});
  cout << flag << endl;

  // v.collect!{|el| el +1 }
  for_each(begin(v), end(v), [](int i){ i++; });
  for_each(begin(v), end(v), [](int i){cout << i << ' ';});
  
  // v.count {||el| el % 2 == 0}
  auto even_count = count_if(begin(v), end(v), [](int i){ return i % 2 == 0;});
  cout << "even_count : " << even_count << endl;

  // v2 = v
  // v2 == v
  vector<int> v2 = v;
  bool is_equal = equal(begin(v), end(v), begin(v2));
  cout << "v2 and v are equal ? " << is_equal << endl;
  vector<int> v3 {1,2,3};
  is_equal = equal(begin(v), end(v), begin(v3));
  cout << "v3 and v are equal ? " << is_equal << endl;

  //v.include?(3)
  auto result1 = find(begin(v), end(v), 3);
  if(result1 != std::end(v)){
    cout << "found 3 in v";
  }


  // 
  string heystack = "The men's and women's track and field events brought big wins for the U.S., Great Britain, Jamaica, Canada, Belgium and South Africa. Catch the best of day 2's track and field events.";
  
  string needle = "track";
 
   auto search_result = std::find_end(begin(heystack), end(heystack), begin(needle), end(needle));
    if (search_result == end(heystack)) {
        cout << "subsequence not found\n";
    } else {
        cout << "last subsequence is at: "
                  << std::distance(begin(heystack), search_result) << "\n";
    }


int x {0};
int y {};
cout << "x: " << x << endl;
cout << "y: " << y << endl;

vector <int> z = {0};
auto zbegin = begin(z);
cout << "z: " << *zbegin << endl;

vector <int> z1(20);
cout << "z: " << z1.size() << endl;

vector <int> z2 {20};
cout << "z: " << z2.size() << endl;
 
double dx = 100.99990090;
cout << static_cast<int>(dx) << endl;

short sary [10] = {10, 3, 4, 5, 6,7};
cout << *begin(sary) << endl;

struct S{
  int x = 10;
  int y = x;
};

S sobj;
cout << sobj.x  << endl;
cout << sobj.y  << endl;

sobj.x = 20;
cout << sobj.x  << endl;
cout << sobj.y  << endl;

string zd = "I'd give my right arm to be" " a great violinist.\n";
cout << zd << endl;
}



