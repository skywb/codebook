#include <stdio.h>

/*! \class Foo
 *  \brief Test Class for brief
 *
 *  详情，测试中文  
 */
class Foo {
public:
  Foo () = default;
  virtual ~Foo () = default;

  /**
  * @brief: return Foo data
  *
  * @return: int
  */
  int GetData() {
    return data_;
  }

  /**
  * @brief: set data for Foo
  *
  * @param: int data
  *
  * @return: void
  */
  void SetData(int data) {
    data_ = data;
  }

private:
   int data_; /*!< test member describe */
};

/**
* @brief: return sum for a and b
*
* @param: int a
*       : int b
*
* @return: int
*/
int Add(int a, int b) {
  return a + b;
}

int main() {


}
