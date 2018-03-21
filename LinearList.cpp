#include<iostream>

using namespace std;
 template <class T>
 class LinearList
 {
       public:
              //virtual destructor
              virtual ~LinearList(){};
              //return true if list is empty otherwise false
              virtual bool empty() const = 0;
              // return size of list
              virtual int size() const =0;
              //return index of element
              virtual int indexOf(const T& theElement) =0;
              // return element of given index
              virtual T& getElement(const int theIndex)  =0;
              //erase element after searching that element
              virtual void erase(const T& theElement)  =0;
              //erase element of given index
              virtual void erase (const int index) =0;
              //insert element at given index
              virtual void insert(const int index,const T& theElement)=0;
              //dispaly list
              void output(ostream &out)=0;
              };
