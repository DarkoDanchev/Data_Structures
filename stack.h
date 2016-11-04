#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T>* next;

    Node(const T& dt,Node<T>* nxt = NULL)
    {
        data = dt;
        next = nxt;
    }
};

template <typename T>
class stack
{
private:
    Node<T>* first;
    size_t counter;
public:
    stack();
    stack(const stack&);
    stack& operator=(const stack&);
    size_t size() const;
    T top() const;
    void push(const T& element);
    void pop();
    void print();

    ~stack();

//private methods
private:
    void copy(const stack<T>&);
    void copyReverse(const stack<T>& st);
    void empty();
    void init();
    bool isEmpty() const;

};
template <typename T>
stack<T>::stack()
{
    this->first = NULL;
    this->counter = 0;
}
template <typename T>
stack<T>::stack(const stack& st)
{
    this->init();
    this->copy(st);
}
template <typename T>
stack<T>& stack<T>::operator=(const stack& st) //to be finished later
{
    if(this != &st)
    {
        this->empty();
        this->init();
        this->copy(st);
    }

    return *this;
}
//the stack core methods
template <typename T>
T stack<T>::top() const
{
    return this->first->data;
}
template <typename T>
void stack<T>::push(const T& element)
{
    Node<T>* add = new Node<T>(element,this->first);
    if(add)
    {
        this->first = add;
        this->counter++;
    }
}
template <typename T>
void stack<T>::pop()
{
    if(!this->isEmpty())
    {
        Node<T>* remove = this->first;
        this->first = this->first->next;
        delete remove;
        this->counter--;
    }
}
//for testing purposes[later to be removed]
template <typename T>
void stack<T>::print()
{
    for(size_t i = 0; i <= this->counter; i++)
    {
        cout<<this->top()<<endl;
        this->pop();
    }
}
template <typename T>
size_t stack<T>::size() const
{
    return this->counter;
}
//the private methods
template <typename T>
bool stack<T>::isEmpty() const
{
    return this->first == NULL;
}
template <typename T>
void stack<T>::init()
{
    this->first = NULL;
    this->counter = 0;
}
template <typename T>
void stack<T>::copyReverse(const stack<T>& st)
{

    Node<T>* node = st.first;
    for(size_t i = 0; i < st.size(); i++)
    {
        this->push(node->data);
        node = node->next;
    }
}
template <typename T>
void stack<T>::copy(const stack<T>& st)
{

    stack<T> reverse;
    reverse.copyReverse(st);

    this->copyReverse(reverse);
}
template <typename T>
void stack<T>::empty()
{
    for(size_t i = 0; i <= this->counter; i++)
        this->pop();
}

//destructor
template <typename T>
stack<T>::~stack()
{
    this->empty();
}

