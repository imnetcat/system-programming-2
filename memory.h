#pragma once
// disable warning "inconsistent annotation for 'new' and 'new[]'"
#pragma warning(disable: 28251) 
void* operator new(size_t size);
void* operator new[](size_t size);
void operator delete(void* ptr);
void operator delete[](void* ptr);
void operator delete(void* ptr, size_t);
void operator delete[](void* ptr, size_t);

namespace memory
{
    namespace heap
    {
        void* alloc(size_t count) noexcept;
        void free(void* src) noexcept;
        void* realloc(void* src, size_t count) noexcept;
    }

    namespace virt
    {
        void* alloc(size_t count) noexcept;
        void free(void* src) noexcept;
        void* realloc(void* src, size_t count) noexcept;
    }
}