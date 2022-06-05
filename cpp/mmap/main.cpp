#include "MMapObjectTool.h"
#include "MyAllocator.h"

#include <vector>

template<typename T1, typename T = std::allocator<T1> >
class Base {
public:
  Base ();
  virtual ~Base ();

private:
  /* data */
};

class Foo {
public:
  Foo () = default;
  virtual ~Foo () = default;

  std::vector<int> vec;
};

int main(int argc, const char *argv[]) {
  Foo foo1;
  Foo foo2;
  foo1.vec.push_back(1);

  for (int i = 0; i < 100; ++i) {
    foo2.vec.push_back(i);
  }

  std::cout << sizeof(foo1) << " " << sizeof(foo2) << std::endl;
  //MMapTool::Allocator<int> allcator;
  std::vector<int, MMapTool::Allocator<int>> vec;
  vec.push_back(1);
  vec.push_back(2);
  for (int i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << std::endl;
  }
  return 0;
}
