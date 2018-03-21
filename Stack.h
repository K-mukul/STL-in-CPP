template<class T>
class Stack:public LinkedList<T>
{
      protected:
                ListNode<T> *stackTop;
                int stackSize;
      public:
                                 
  inline bool empty() const;
  inline int size() const;
  inline void push(const T&);
  inline void pop();
  inline T& top();


};
template <class T>
bool Stack<T>::empty() const 
{
     return stackSize==0;
     }
     
template <class T>
int Stack<T>::size()
{
    return stackSize;
}

  template <class T>
  void push(T& Item)
  {
       stackTop=new ListNode(Item,stackTop);
       stackSize++;
       }
       
       
template <class T>
void Stack<T>:: pop()
{
         ListNode<T> *tempNode;
         tempNode=stackTop;
         stackTop=stackTop->next;
         free(tempNode);
         }

       
template <class T>
T& Stack<T>:: top()
{
        if(empty())
         cout<<"\nError :Stack Empty Found \n";
         else 
         return stackTop->element;
         }
         
         
