//#include"LinearList.h"
  template <class T>
   class ArrayList:public LinearList<T>
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

//Iterator class definitin starts here

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
       return this->position!=right.position;
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
                inline ArrayList(int initialCapacity=10);
                inline ArrayList(const ArrayList<T>&);
                inline int indexOf(const T&);
                inline T& getElement(const int index);
                inline void erase (const int);
                inline void insert(const int ,const T &);
                ~ArrayList()
                {
                            delete [] array;//deleting list
                            }//end of ArrayList destructor
                 int size() const
                 {
                      return listSize;
                      }//end of size function
                 bool empty() const
                 {
                      return listSize==0;//true if listsize is 0
                      }//end of empty
                      };
     template <class T>
     ArrayList<T> ::ArrayList(int initialCapacity)//definition of constructor
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
                   }//end of ArrayList constructor
       template < class T >
       ArrayList<T> :: ArrayList( const ArrayList<T> &theList)
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
       void ArrayList<T> :: checkIndex(int index)
       {
                    if(index<0 || index >listSize)
                    {
                               //ostringstream s;
                               string s;
                              s="Invalid Index Found  must be > 0 ";//<<index<<"Size of list "<<listSize;
                              throw invalidIndex(s);
                               }
          }//end of checkindex
template <class T>
int ArrayList<T>::indexOf(const T&element)
{
    int index;//=(int)(find(array,array+listSize,element)-array);
    for(index=0;index<listSize&&array[index]!=element;index++);
    if(index==listSize)
        return -1;
    else
        return index;
}
template <class T>
T& ArrayList<T>::getElement(const int index)
{

    checkIndex(index);
    return array[index];
}
template<class T>
void ArrayList<T>::erase(const int index)
{

    /*int index;
    index=(int)(find(array,array+listSize,element)-array);
    if(index==-1)
        cout<<endl<<"Element Not Found in list";
    else{
        */
    try
      {
          checkIndex(index);

             }
       catch(invalidIndex obj)
       {
           cout<<"Exception While Deletion  :";
           cout<<obj.getString()<<endl;
           return ;

       }

        copy(array+index+1,array+listSize,array+index);
        --listSize;
    //}//end of else
}//end of erase

template<class T>
void ArrayList<T>::insert(const int index,const T&element)
{
      try
      {
          checkIndex(index);

             }
       catch(invalidIndex obj)
       {
           cout<<"Exception while Insertion   :";
           cout<<obj.getString()<<endl;
           return ;
       }

       array[index]=element;
       listSize++;




    }




