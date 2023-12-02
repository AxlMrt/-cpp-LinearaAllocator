#include <iostream>
#include <new>

using namespace std;

class LinearAllocator
{
  private:
    size_t totalSize;
    size_t used;
    char *memory;

  public:
    LinearAllocator(size_t size) : totalSize(size), used(0), memory(static_cast<char *>(malloc(size)))
    {
        if (memory == nullptr)
        {
            throw bad_alloc();
        }
    }

    ~LinearAllocator()
    {
        free(memory);
    }

    void *allocate(size_t size)
    {
        if (used + size > totalSize)
            return nullptr;

        void *ptr = memory + used;
        used += size;
        return ptr;
    }

    void reset()
    {
        used = 0;
    }
};
