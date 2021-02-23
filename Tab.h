//
// Created by Mufasa on 2/2/2021.
//

#ifndef LAB5_TAB_H
#define LAB5_TAB_H

#include <iostream>
using namespace std;

class Tab
{
private:
    int *tab;
    int size;

    void copy(const Tab &other)
    {
        size = other.size;
        tab = new int[size];

        for(int i = 0; i < size; i++)
        {
            tab[i] = other.tab[i];
        }
    }

public:
    Tab()
    {
        size = 10;
        tab = new int[size]{0};
    }

    Tab(const Tab &other)
    {
        copy(other);
    }

    Tab(Tab &&other)
    {
        size = other.size;
        tab = other.tab;

        other.size = 0;
        other.tab = nullptr;
    }

    ~Tab()
    {
        delete[] tab;

    }
    Tab& operator=(Tab&& other) noexcept
    {
        cout<<("move");
        if (this != &other)
        {
            delete[] tab;

            size = other.size;
            tab = other.tab;

            other.size = 0;
            other.tab = nullptr;
        }
        return *this;
    }

    void toString()
    {
        std::cout<<"table elements: ";
        for(int i = 0; i < size; i++)
        {
            std::cout<<tab[i]<<", ";
        }
        cout<<("");
    }

    bool setSize(int newSize)
    {
        if(newSize < size) return false;
        int *newTab = new int[newSize]{0};
        for(int i = 0; i < size; i++)
        {
            newTab[i] = tab[i];
        }
        delete[] tab;
        size = newSize;
        tab = newTab;
        return true;
    }

    int getSize()
    { return size; }


};


#endif //LAB5_TAB_H
