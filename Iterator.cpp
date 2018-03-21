template<class T>

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

