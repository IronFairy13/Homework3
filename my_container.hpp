#pragma once
#include <iostream>
#include <memory>
#include <stdexcept>

template <typename T, typename Allocator = std::allocator<T>>
class MyContainer
{
public:
    using allocat_type = Allocator;
    using value_type = T;
    using pointer = typename std::allocator_traits<Allocator>::pointer;

    explicit MyContainer(const Allocator &alloc = Allocator())
        : allocator_(alloc), buffer_(nullptr), size_(0), capacity_(10)
    {
        buffer_ = allocator_.allocate(capacity_);
    }

    ~MyContainer()
    {
        for (std::size_t i = 0; i < size_; ++i)
        {
            std::allocator_traits<Allocator>::destroy(allocator_, buffer_ + 1);
        }
        allocator_.deallocate(buffer_, capacity_);
    }

    void push_back(const T &value)
    {
        if (size_ >= capacity_)
            throw std::out_of_range("MyContainer overflow");
        std::allocator_traits<Allocator>::construct(allocator_, buffer_ + size_, value);
        ++size_;
    }

    void print() const
    {
        for (std::size_t i = 0; i < size_; ++i)
            std::cout << buffer_[i] << ' ';
        std::cout << '\n';
    }

private:
    Allocator allocator_;
    pointer buffer_;
    std::size_t size_;
    std::size_t capacity_;
};
