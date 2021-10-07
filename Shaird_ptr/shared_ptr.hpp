#include <iostream>
#include"shared_ptr.h"
template<typename T>
Shared_ptr<T>::Shared_ptr()
{
        m_ptr = NULL;
        buf = nullptr;
}
template<typename T>
Shared_ptr<T>::Shared_ptr(T*in_ptr)
{
        m_ptr=in_ptr;
        buf = new DataPointer<T>;
        buf->count++ ;
        buf->Del_ptr = Deletor<T>;
}
template<typename T>
Shared_ptr<T>::Shared_ptr(const Shared_ptr<T>& tmp)
{
        this->m_ptr=tmp.m_ptr;
        this->buf = tmp.buf;
        this->buf->count++ ;
        buf->Del_ptr = Deletor<T>;
}
template<typename T>
Shared_ptr<T>::Shared_ptr(Shared_ptr<T>&& tmp)
{
        this->m_ptr=tmp.m_ptr;
        this->buf = tmp.buf;
        tmp.m_ptr =nullptr ;
        tmp.buf=nullptr ;
}
template<typename T>
Shared_ptr<T> Shared_ptr<T>::operator=(const Shared_ptr<T>& tmp)
{
        if(this == &tmp){return *this;}
        delete m_ptr ;
        delete buf;
        this->m_ptr=tmp.m_ptr;
        this->buf=tmp.buf;
        this->buf->count++ ;
        return tmp ;
}
template<typename T>
Shared_ptr<T>::~Shared_ptr()
{
        buf->count--;
        if(!buf->count && m_ptr!=nullptr)
        {
                buf->Del_ptr(m_ptr);
        }
}
template<typename T>
T& Shared_ptr<T>::operator[](int index){return m_ptr[index];}
