#pragma once
#include <cstddef>
#include <stdexcept>
#include <memory>

template <typename T, std::size_t BlockSize = 10>
class MyAllocator
{
public:
    using value_type = T;

    MyAllocator()
    {
        data = static_cast<T *>(::operator new(BlockSize * sizeof(T)));
    }

    template <typename U>
    MyAllocator(const MyAllocator<U, BlockSize> &noexpect) {}

    ~MyAllocator()
    {
        ::operator delete(data);
    }

    T *allocate(std::size_t n)
    {
        if (allocated + n > BlockSize)
        {
            throw std::bad_alloc();
        }
        T *ptr = data + allocated;
        allocated += n;
        return ptr;
    }

    void deallocate(T *, std::size_t) noexcept {}

    template <typename U>
    struct rebind
    {
        using other = MyAllocator<U, BlockSize>;
    };

private:
    T *data = nullptr;
    std::size_t allocated = 0;
};

template <typename T1, typename T2, std::size_t B>
bool operator==(const MyAllocator<T1, B> &, const MyAllocator<T2, B> &) { return true; }

template <typename T1, typename T2, std::size_t B>
bool operator!=(const MyAllocator<T1, B> &, const MyAllocator<T2, B> &) { return false; }
