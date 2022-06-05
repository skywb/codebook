#ifndef MMAP_OBJECT_TOOL_H_
#define MMAP_OBJECT_TOOL_H_

#include <iostream>

template<class T>
class MMapObjectBase {
public:
  MMapObjectBase () = default;
  virtual ~MMapObjectBase () = default;
private:
  /* data */
};


class MMapObjectTool {
public:
  MMapObjectTool () = default;
  virtual ~MMapObjectTool () = default;
};



#endif
