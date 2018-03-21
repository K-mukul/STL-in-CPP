
template<class T>
struct DListNode
{

    T element;
    DListNode<T> * next;
    DListNode<T> *prev;
    DListNode(const T &element)
    {
        this->element=element;
        next=NULL;
        prev=NULL;

    }
    DListNode(const T &element,const DListNode<T> *next,const DListNode<T> *prev)
    {

        this->element=element;
        this->next=next;
        this->prev=prev;
    }
};


template <class T>
class DLinkedList:public LinearList<T>
{

protected :
    DListNode<T> *head;
    int listSize;
    int listLenght;
    void checkIndex(int);
public:

                        //member funciton declaration
    inline DLinkedList(const int);
    inline DLinkedList();
    inline DLinkedList(const DLinkedList<T>&);
    inline bool empty() const;
    inline int size() const;
    inline int indexOf(const T&);
    inline T& getElement(const int );
    inline void erase(const int);
    inline void insert(const int ,const T&);
    inline void insertAtBegin(const T&);
    inline void insertAtEnd(const T&);
    friend istream operator >> (istream&in,DLinkedList<T>[]);

   // iterator class defined inside class DLinkedList
      class Iterator
 {
    protected:
     DListNode<T> *position;
    public:
    //default constructor
    Iterator (DListNode<T>*thePosition)
    {

        position=thePosition;

    }
    // deferencing operator
    T& operator*()const
    {

        return position->element;
    }
    T* operator->()
    {
        return &position->element;

    }


    //prefix increment operator
    Iterator& operator++()
    {

        position=position->next;
        return *this;

    }
    Iterator operator++(int)
    {

        Iterator old=*this;
        position=position->next;
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

              return Iterator(head);
          }

          Iterator end()
          {

              return Iterator(NULL);
          }



};




template <class T>
DLinkedList<T>::DLinkedList()
{
  listSize=0;
  head=NULL;
}

template <class T>
DLinkedList<T>::DLinkedList(const int initialCapacity)
{

  listSize=initialCapacity;
  head=NULL;
}
template <class T>
DLinkedList<T>::DLinkedList(const DLinkedList<T> &templist)
{

    listSize=templist.listSize;
    if(listSize==0)
    {
        head=NULL;

    }

    else

    {

        head=new DListNode<T>(templist->head->element);
        head->prev=NULL;
        head->next=NULL;
        DListNode<T> *temp=templist->head->next;
        DListNode<T> *currNode=head,*newNode;
        while(temp!=NULL)
        {
        newNode=new ListNode<T>(temp->element);
        currNode->next=newNode;
        newNode->next=NULL;
        newNode->prev=currNode;
        temp=temp->next;
        currNode=currNode->next;
        }//end oof while
    }//end of else
}
template<class T>
bool DLinkedList<T>::empty() const
    {

        return listSize==0;
    }
template<class T>
int DLinkedList<T>::size() const
    {

        return listSize;
    }

template<class T>
T& DLinkedList<T>::getElement(const int index)
      {

        int count=0;
        DListNode<T> *temp=head;
        while(count!=index&&temp!=NULL)
            temp=temp->next;
        if(temp)
            return temp->element;
           else
           cout<<endl<<"Index not Found List";
    }

template<class T>
int DLinkedList<T>::indexOf(const T &element)
    {

        int index=-1;
        DListNode<T> *temp=head;
        while(temp->element!=element)
        {

            temp=temp->next;
            index++;
        }
        if(index==-1)
            cout<<endl<<"Item Not Found";
         else return index;
    }
template<class T>
void DLinkedList<T>::erase(int index)
  {
      DListNode<T> *temp,*last;
      if(index==0)
      {
          temp=head;
          head=head->next;
      }
      else
      {
          temp=last=head;
      int count=0;
      while(index!=count&&temp!=NULL)
      {

          last=temp;
          temp=temp->next;
      }

      if(temp)
       last->next=temp->next;

      }
        if(temp)
        free(temp);
        else
        cout<<endl<<"Index Not Found";
      }
  template <class T>
  void DLinkedList<T> ::insert(const int index ,const T& node)
  {
      DListNode<T> *temp,*last,*newNode;
      int count;
      last=NULL;
      newNode=new DListNode<T>(node);
      if(index==0)
      {
          if(head)
          {

          newNode->next=head->next;
          newNode->prev=head->prev;
          head=newNode;
          }
          else
            head=newNode;
      }
      else
      {

          for(count=0,temp=head;count!=index&&temp!=NULL;count++,last=temp,temp=temp->next);

          if(last)
          {

               newNode->next=last->next;
               if(temp)
               temp->prev=newNode;
              newNode->prev=last;
              last->next=newNode;
          }
          else
            cout<<"\nInvalid Index Found, Can't Insert Element";
      }

  }


