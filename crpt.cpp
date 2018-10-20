#include <iostream>
#include <vector>

template <typename T>
class Logger{
public:
  void log(){
    static_cast<T*>(this)->log();
  }
};

class FileLogger: public Logger<FileLogger>{
public:
  void log(){
    std::cout << "In the class FileLogger\n";
  }
};

int main(){
  std::cout << sizeof(FileLogger) << '\n'; // Size is 1
  FileLogger fl;
  fl.log();

  std::vector<int> v{1,2,3,4,5,6,67,7,8,9,9};
  std::cout << sizeof(v) << '\n';
}