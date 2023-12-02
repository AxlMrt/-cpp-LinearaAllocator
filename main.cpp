#include <iostream>

#include "./LinearAllocator.cpp"
using namespace std;

int main()
{
    const size_t allocatorSize = 1024;
    LinearAllocator allocator(allocatorSize);

    int *array = static_cast<int *>(allocator.allocate(5 * sizeof(int)));
    if (array)
    {
        for (int i = 0; i < 5; ++i)
        {
            array[i] = 1;
            cout << array[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Error" << endl;
    }

    allocator.reset();
    return 0;
}
