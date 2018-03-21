template<class T>
struct ListNode
{

    T element;
    ListNode<T> * next;
    ListNode(const T &element)
    {
        this->element=element;
        next=NULL;

    }
    ListNode(const T &element,const ListNode<T> *next)
    {

        this->element=element;
        this->next=next;
    }
};
template <class T>
class LinkedList:public LinearList<T>
{

protected :
    ListNode<T> *head;
    int listSize;
    int listLenght;
    void checkIndex(int);
public:

                        //member funciton declaration
    inline LinkedList(const int);
    inline LinkedList();
    inline LinkedList(const LinkedList<T>&);
    inline bool empty()const ;
    inline int size()const ;
    inline T& getElement(const int);
    inline int indexOf(const T&) ;
    inline void erase(const int);
    inline void insertAtBegin(const T&);
    inline void insertAtEnd(const T&);
    inline void insert(const int ,const T&);





     class Iterator
 {
    protected:
     ListNode<T> *position;
    public:
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    //default constructor
    Iterator (ListNode<T>*thePosition)
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
LinkedList<T>::LinkedList()
{
  listSize=0;
  head=NULL;
}

template <class T>
LinkedList<T>::LinkedList(const int initialCapacity)
{
  listSize=initialCapacity;
  head=NULL;
}
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &templist)
{

    listSize=templist.listSize;
    if(listSize==0)
    {
        head=NULL;

    }
    else
    {
        head=new ListNode<T>(templist->head->element);
        ListNode<T> *temp=templist->head->next;
        ListNode<T> *currNode=head;
        while(temp!=NULL)
        {
        currNode->next=new ListNode<T>(temp->element);
        temp=temp->next;
        currNode=currNode->next;
        }//end oof while
    }//end of else
}






template<class T>
  void LinkedList<T>::insertAtEnd(const T&element)
  {

      if(head==NULL)
        head=new ListNode<T>(element);
      else
      {

          ListNode<T> *temp=head;
          while(temp->next!=NULL)
                temp=temp->next;
                temp->next=new ListNode<T>(element);
                temp=temp->next;
                temp->next=NULL;

      }
  }
template<class T>
  void LinkedList<T>::insertAtBegin(const T&element)
  {

      ListNode<T> *temp=new ListNode<T>(element);
       temp->next=head;
       head=temp;

  }
template<class T>
  bool LinkedList<T>:: empty() const
    {

        return listSize==0;
    }

template<class T>
int LinkedList<T>:: size() const
    {

        return listSize;
    }


template<class T>
  T& LinkedList<T>:: getElement(const int index)
      {

        int count=0;
        ListNode<T> *temp=head;
        while(count!=index&&temp!=NULL)
            temp=temp->next;
        if(temp)
            return temp->element;
           else
           cout<<endl<<"Index not Found List";
    }
template<class T>
  int LinkedList<T>:: indexOf(const T &element)
    {

        int index=-1;
        ListNode<T> *temp=head;
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
  void LinkedList<T>::erase(int index)
  {
      ListNode<T> *temp,*last;
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
/*
    void erase(const T&element)
    {

        ListNode<T>*temp,*last;
        temp=head;
        while(temp!=NULL&&temp->element!=element)
        {

            last=temp;
            temp=temp->next;

        }
        if(temp)
            {
        last->next=temp->next;
        free(temp);
            }
            else
                cout<<"Element Not Found in List";
    }
*/
template<class T>
  void LinkedList<T>::insert(const int index,const T&tempNode)
 {

  int count=0;
  ListNode<T> *temp,*last;
  temp=head;
  if(index==0)
  {

      insertAtBegin(tempNode);
  }
  else
    {
  while(count!=index&&temp!=NULL)
  {
      last=temp;
      temp=temp->next;
      count++;
  }
  if(temp)
  {

     ListNode<T> *newNode=new ListNode<T>(tempNode);
     newNode->next=last->next;
     last->next=newNode;
  }
    }
 }








