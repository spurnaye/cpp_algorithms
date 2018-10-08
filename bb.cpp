#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class ThreadPool {
    private:
    std::queue<std::function<int(int,int)>> jobs;
    std::condition_variable cv;
    std::mutex mtx;
    
    
    public:
    
    bool enqueue(std::function<int(int,int)> func){
        std::unique_lock<std::mutex> ul(mtx);
        jobs.enqueue(func);
        cv.nofity_all();
    }
    
    void run(){
        while(true){
        cv.wait([](){
           {
              std::unique_lock<std::mutex> ul(mtx);
              while(jobs.empty()){
                std::function<int(int,int)> func = jobs.dequeue();
                func();
              }
          });
        }
    }
    
}

int main() {
   ThreadPool p;
   std::thread enqueuer[](){
     for(int i = 0; i < 1000000; ++i){
       p.enqueue([=](int i, int i){return i*i;});    
     }
   }
   
  p.run();
 
    return 0;
}