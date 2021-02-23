#include <iostream>
#include "SmartPointer.h"
#include "Tab.h"
#include "CTable.h"
using namespace std;
void pointersTest()
{
    SmartPointer<int> pointer(new int(3));
    cout<<"the pointer is pointing at:\t" << *pointer<<endl;

    {
        SmartPointer<int> pointer1 = pointer;
        cout<<"pointer 1 is pointing at:\t" << *pointer1 << endl;

        //incrementing pointer1
        (*pointer)++;
        cout<<"now pointer 1 is pointing at:\t" << *pointer1 << endl;
    }
    SmartPointer<int> pointer2(new int(23));
    pointer2 = pointer;
    cout<<"pointer 2 is pointing at:\t" << *pointer2<<endl;
    cout<<"pointer is pointing at:\t" << *pointer <<endl;
}

void tabTest()
{
    Tab tab;
    Tab otherTab;
    cout<<"Table"<< endl;
    tab.toString();
    cout<<"\notherTable" << endl;
    otherTab.toString();
    tab = std::move(otherTab);
    cout<<"\ntable" << endl;
    tab.toString();
    cout<<"\notherTab (after moving):" << endl;
    otherTab.toString();
}

void cTableTest()
{
    {
        CTable tab1("1", 9);
        CTable tab2("2", 4);
        CTable tab3("3", 5);

        tab1.vPrint();
        tab2.vPrint();
        tab3.vPrint();
        tab1--.vPrint();
    }
    {
        CTable c_tab_0, c_tab_1;
        c_tab_0.bSetNewSize(5);
        c_tab_1.bSetNewSize(8);
        /* initialize table */

        cout<<"adding value to tab 1 after moving it"<<endl;
        c_tab_1.vSetValueAt(1, 11);
        cout<<"tab0"<<endl;
        c_tab_0.vPrint();
        cout<<"tab1"<<endl;
        c_tab_1.vPrint();
        c_tab_1 = c_tab_1 + c_tab_1;
        cout<<"new table 1" << endl;
        c_tab_1.vPrint();
        c_tab_0 = std::move(c_tab_1);
        cout<<"tab0 after moving tab1 to it" << endl;
        c_tab_0.vPrint();
    }
}

int main() {
    cout<<"\n"<<endl;
    pointersTest();
    cout<<"\n"<<endl;
    tabTest();
    cout<<("\n")<<endl;
    cTableTest();
}