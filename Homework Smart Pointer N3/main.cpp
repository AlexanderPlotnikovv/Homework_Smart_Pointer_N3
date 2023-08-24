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
	T* release()
	{
		T* new_ptr = ptr;
		ptr = nullptr;
		return new_ptr;
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
	sum* ptr1 = ptr.release();
	std::cout << ptr1->s();
	return 0;
}