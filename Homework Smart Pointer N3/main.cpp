#include <iostream>

template<class T>
class unique_ptr
{
	T* ptr;
public:
	unique_ptr() : ptr(nullptr) {}
	unique_ptr(T* ptr) : ptr(ptr) {}
	unique_ptr(const unique_ptr& ptr) = delete;
	unique_ptr& operator=(const unique_ptr& ptr) = delete;
	void release(unique_ptr<T>& new_ptr)
	{
		delete ptr;
		ptr = new_ptr.ptr;
		new_ptr.ptr = nullptr;
	}
	T& operator*()
	{
		return *ptr;
	}
	T* operator->()
	{
		return ptr;
	}
	~unique_ptr()
	{
		delete ptr;
	}
};

class sum
{
	int a, b;
public:
	sum(int a, int b): a(a), b(b) {}
	int s()
	{
		return a + b;
	}
};

int main()
{
	unique_ptr<sum> ptr(new sum(5,3));
	std::cout << ptr->s() << std::endl;
	unique_ptr<sum> ptr1(new sum(1,2));
	ptr1.release(ptr);
	std::cout << ptr1->s();
	return 0;
}