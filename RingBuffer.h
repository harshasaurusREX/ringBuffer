#ifndef RINGBUFFER_H_INCLUDED
#define RINGBUFFER_H_INCLUDED

#include <iostream>
using namespace std ;

template <typename T >
class ring
{
private :
    int _pos ;
    T *_value ;
    int _size ;
public :
    class iterator ;
    ring(int & size) ;
    virtual ~ring();
    void add(T item) ;
    int size();
    T & get(int pos);
};

template <typename T >
class ring<T>::iterator
{
    int i_pos ;
    ring i_ring ;

public :
    iterator( int type , ring& p_ring);
    void print ();
    operator ++ ( int ) ;
    operator ++ ( ) ;

};

template<typename T>
ring<T>::ring( int & size) : _pos(0) , _value(NULL) , _size(size)
{
    _value = new T[size] ;
}

template<typename T>
ring<T>::~ring()
{
    delete [] _value ;
}

template<typename T>
void ring<T>::add(T item)
{
    _value[_pos] = item ;
    _pos++ ;

    if(_pos == _size)
        _pos = 0 ;
}

template<typename T>
int ring<T>::size()
{
    return _size ;
}


template<typename T>
T& ring<T>::get(int cur_pos)
{
    return _value[cur_pos] ;
}

template <typename T >
iterator( int pos , ring & p_ring ) : i_pos(pos) , i_ring( p_ring )
{

}

template <typename T>
iterator& ring<T>::iterator operator ++ ( int )
{
    pos++ ;

    return *this ;
}


#endif // RINGBUFFER_H_INCLUDED
