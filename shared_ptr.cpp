#include <iostream>
#include <atomic>

template <typename T>
class MySharedPtr{
  public:
    MySharedPtr(T val){
      resource_ptr = new T(val);
      c_ptr = new int(1);
    };

    MySharedPtr<T>(const MySharedPtr<T> & ptr){
      std::cout << "copy constructor \n";
      resource_ptr = ptr.resource_ptr;
      (*ptr.c_ptr)++;
      this->c_ptr = ptr.c_ptr;
    }

    MySharedPtr<T>& operator=(const MySharedPtr<T> & ptr){
      std::cout << "copy assignment operator\n";
      if(this != &ptr){
        (*ptr.c_ptr)++;
        this->c_ptr = ptr.c_ptr;
        this->resource_ptr = ptr.resource_ptr;
      }
      return *this;
    }

    MySharedPtr(MySharedPtr && ptr) = delete;
    MySharedPtr & operator=(MySharedPtr && ptr) = delete;

    MySharedPtr & operator *(){
      return resource_ptr;
    }

    MySharedPtr* operator ->(){
      return resource_ptr;
    }

    virtual ~MySharedPtr(){
      std::cout << *c_ptr << '\n';
       if(*c_ptr > 0){
           (*c_ptr)--;
       }else{
          delete c_ptr;
          delete resource_ptr;
       }
    }

    int use_count(){
      return *c_ptr;
    }
  
  private:
    int * c_ptr;
    T * resource_ptr;
};


int main(){
  int x;
  MySharedPtr<decltype(x)> sp(1);
  {
    MySharedPtr<decltype(x)> sp1(2);
    sp1 = sp;
    std::cout << "use count is " << sp.use_count() << '\n';
  }
  sp = sp;

  std::cout << "use count is " << sp.use_count() << '\n';
  return 0;
}
