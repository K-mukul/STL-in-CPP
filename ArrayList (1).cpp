

#include"LinearList.cpp"
#include"Iterator.cpp"
#include<iostream>
#include<algorithm>
using namespace std;

  template <class T>
   class arrayList //: public linearList
    {
         protected:
                   T *array;
                   int listSize;
                   int arrayLength;
                inline void checkIndex(int index);
         public:
                class invalidIndex
                {

                    string mesg;
                public :
                    invalidIndex(string mesgs)
                    {
                        mesg=mesgs;
                    }
                    string getString()
                    {

                        return mesg;
                    }
                };

 // template<class T>

class Iterator
{
protected:
    T *position;

public:
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    //default constructor
    Iterator (T * thePosition)
    {

        position=thePosition;

    }
    // deferencing operator
    T& operator*()const
    {

        return *position;
    }
    T* operator->()
    {
        return &*position;

    }


    //prefix increment operator
    Iterator& operator++()
    {

        ++position;
        return *this;

    }
    Iterator operator++(int)
    {

        Iterator old=*this;
        ++position;
        return old;

    }
    bool operator !=(const Iterator right)
    {
       return this.position!=right.position;
    }

    bool operator ==(const Iterator right)
    {

        return position==right.position;

    }

};
          Iterator begin ()
          {

              return Iterator(array);
          }

          Iterator end()
          {
              return Iterator(array+listSize);
          }
                inline arrayList(int initialCapacity=10);
                inline arrayList(const arrayList<T>&);
                inline int indexOf(const T&);
                inline T& getElement(const int index);
                inline void erase (const T&);
                inline void insert(const int ,const T &);
                ~arrayList()
                {
                            delete [] array;//deleting list
                            }//end of arraylist destructor
                 int size()
                 {
                      return listSize;
                      }//end of size function
                 bool empty()
                 {
                      return listSize==0;//true if listsize is 0
                      }//end of empty
                      };
     template <class T>
     arrayList<T> ::arrayList(int initialCapacity)//definition of constructor
     {
                  if(initialCapacity<0)
                   //throw illegalParameterValue("initialCapacity Can not be less than 0");

                   ;
                   arrayLength=initialCapacity;
                   try{
                       array=new T [arrayLength];//creating space for array
                       }
                       catch(bad_alloc)
                       {
                                       cout<<"\n Error  ::Not Enought Memory Available  :";
                                       }
                   listSize=0;
                   }//end of arraylist constructor
       template < class T >
       arrayList<T> :: arrayList( const arrayList<T> &theList)
       {
                    arrayLength=theList.arrayLength;
                    try
                    {
                        array=new T [arrayLength];
                        }
                     catch(bad_alloc)
                     {
                                     cout<<"ERROR :: List is bigger not enough memory available";
                                     }
                     listSize=theList.listSize;
                     copy(theList.array,theList.array+listSize,array);
                     }//end of copy constructor
      template < class T>
       void arrayList<T> :: checkIndex(int index)
       {
                    if(index<0 || index >listSize-1)
                    {
                               ostringstream s;
                             // s<<"Index = "<<index<<"Size of list "<<listSize;
                            //throw invalidIndex(s.str());
                               }
          }//end of checkindex
template <class T>
int arrayList<T>::indexOf(const T&element)
{
    int index=(int)(find(array,array+listSize,element)-array);
    if(index==listSize)
        return -1;
    else
        return index;
}
template <class T>
T& arrayList<T>::getElement(const int index)
{

    checkIndex(index);
    return array[index];
}
template<class T>
void arrayList<T>::erase(const T&element)
{

    int index;
    index=(int)(find(array,array+listSize,element)-array);
    if(index==-1)
        cout<<endl<<"Element Not Found in list";
    else{
        copy(array+index+1,array+listSize,array+index);
        --listSize;
    }//end of else
}//end of erase

template<class T>
void arrayList<T>::insert(const int index,const T&element)
{

    if(index<0 ||index>=listSize)
    {
        //string mesg="Invalid index found "+ index + "must be between  0 and " + listSize;

      throw invalidIndex("mesg");
    }
};



