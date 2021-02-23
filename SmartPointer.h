//
// Created by Mufasa on 2/2/2021.
//

#ifndef LAB5_SMARTPOINTER_H
#define LAB5_SMARTPOINTER_H


template<typename T>
class SmartPointer
{
private:
    int* counter{};
    T *pointer;
    void destroy(){
        if(--(*counter) <=0) {
            delete pointer;
            delete counter;
        }
    };
public:
    SmartPointer(T *pointedValue);

    SmartPointer(T pointedValue);

    SmartPointer(const SmartPointer<T> &other);

    ~SmartPointer();

    T &operator*();

    T *operator->();

    SmartPointer &operator = (SmartPointer<T> other);

};

template<typename T>
SmartPointer<T>::SmartPointer(T *pointedValue)
{
    counter = new int(1);
    pointer = pointedValue;

}

template<typename T>
SmartPointer<T>::SmartPointer(T pointedValue)
{
    counter = new int(1);
    pointer = new T(pointedValue);

}

template<typename T>
SmartPointer<T>::SmartPointer(const SmartPointer<T> &other)
{
    pointer = other.pointer;
    counter = other.counter;
    (*counter)++;
}

template<typename T>
SmartPointer<T>::~SmartPointer()
{
    destroy();
}

template<typename T>
T &SmartPointer<T>::operator*()
{
    return *pointer;
}

template<typename T>
T *SmartPointer<T>::operator->()
{
    &pointer;
}

template<typename T>
SmartPointer<T> &SmartPointer<T>::operator=(SmartPointer<T> other)
{
    destroy();
    pointer = other.pointer;
    counter = other.counter;
    (*counter)++;
    return *this;
}
#endif //LAB5_SMARTPOINTER_H
