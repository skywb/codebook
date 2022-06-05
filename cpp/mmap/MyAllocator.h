#ifndef MMAP_TOOL_ALLOCATOR_H_
#define MMAP_TOOL_ALLOCATOR_H_

#include <new>
#include <iostream>
#include <cstdlib> // for exit()
#include <climits> // for UNIX_MAX
#include <cstddef>
#include <mmap>

namespace MMapTool {

class MMapMermoryPool {
public:
  static MMapMermoryPool& GetInstances() {
    static MMapMermoryPool obj;
    return obj;
  }
public:
  virtual ~MMapMermoryPool ();
  void Init (const std::string file_path);

private:
  MMapMermoryPool ();

};

template<class T>
class Allocator
{
  public:
    typedef T               value_type;
    typedef T*              pointer;
    typedef const T*        const_pointer;
    typedef T&              reference;
    typedef const T&        const_reference;
    typedef size_t          size_type;
    typedef ptrdiff_t       difference_type;

    template<class U>
      struct rebind
      {
        typedef Allocator<U> other;
      };

    pointer allocate(size_type n, const void* hint=0) {
      std::cout << "_allocate called" << std::endl;
      std::set_new_handler(0);
      pointer tmp = (pointer)(::operator new((size_t)(n * sizeof(value_type))));
      if (NULL == tmp) {
        std::cerr << "out of memory" << std::endl;
        exit(0);
      }
      return tmp;
      //return _allocate((difference_type)n, (pointer)0);
    }

    void deallocate(pointer p, size_type n) {
      ::operator delete(p);
    }

    void construct(pointer p, const T& value) {
      ::new(p) value_type(value);
      //_construct(p, value);
    }

    void destroy(pointer p) {
      p->~value_type();
    }

    pointer address(reference x) {
      return (pointer)&x;
    }

    const_pointer address(const_reference x) {
      return (const_pointer)&x;
    }

    size_type max_size() const {
      return size_type(UINT_MAX/sizeof(T));
    }
};

} // end of namespace

#endif
