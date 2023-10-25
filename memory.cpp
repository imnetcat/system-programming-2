#include "memory.h"
#include "windows.h"

void* operator new(size_t size)
{
	return memory::heap::alloc(size);
}
void* operator new[](size_t size)
{
	return memory::heap::alloc(size);
}
void operator delete(void* ptr)
{
	memory::heap::free(ptr);
}
void operator delete[](void* ptr)
{
	memory::heap::free(ptr);
}
void operator delete(void* ptr, size_t)
{
	memory::heap::free(ptr);
}
void operator delete[](void* ptr, size_t)
{
	memory::heap::free(ptr);
}

void* memory::heap::alloc(size_t size) noexcept
{
	return HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, size);
}

void memory::heap::free(void* ptr) noexcept
{
	if (ptr)
	{
		HeapFree(GetProcessHeap(), 0, ptr);
	}
}

void* memory::heap::realloc(void* src, size_t size) noexcept
{
	if (!src)
	{
		return HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, size);
	}

	void* tmp = HeapReAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, src, size);
	if (!tmp)
	{
		HeapFree(GetProcessHeap(), 0, src);
	}
	return tmp;
}
