#ifndef SHARED_PRT
#define SHARED_PRT

#include <iostream>

template<typename T>
void Deletor(T*m_ptr)
{
        delete m_ptr;
}
template<typename T,typename DT = void(*)(int)>
struct DataPointer
{
        int count;
	DT Del_ptr;
	DataPointer()
	{
		count = 0;
		Del_ptr = Deletor<T>;
	}
};
template<typename T,typename DT = void(*)(int)>
class Shared_ptr
{
private:
        T* m_ptr;
        DataPointer<T>* buf;
public:
        Shared_ptr();
        Shared_ptr(T*);
        Shared_ptr(T*);
        Shared_ptr(const Shared_ptr&);
        Shared_ptr(Shared_ptr &&);
        ~Shared_ptr();
        T& operator[](int);
        Shared_ptr<T> operator=(const Shared_ptr<T>&);
};
#include"shared_ptr.hpp"
#endif   //SHARED_PTR
