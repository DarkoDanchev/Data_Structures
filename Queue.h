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
class queue
{
//the private variables
private:
    Node<T>* first;
    Node<T>* last;
    size_t counter;
//the public methods
public:
    queue(); //default constructor
    queue(const queue&); //copy constructor
    queue& operator=(const queue&);
    void enqueue(const T&);
    void dequeue();
    T front() const;
    T end() const;
    size_t size() const;

//the private methods
private:
    void copy(const queue&);
    void init();
    void empty();
    bool isEmpty() const;
};

//the queue core methods
template <typename T>
queue<T>::queue()
{
    this->init();
}
template <typename T>
queue<T>::queue(const queue& q)
{
    this->init();
    this->copy(q);
}

template <typename T>
queue<T>& queue<T>::operator=(const queue& q)
{
    if(this != &q)
    {
        this->empty();
        this->init();
        this->copy(q);
    }

    return *this;
}
template <typename T>
void queue<T>::enqueue(const T& data)
{
    Node<T>* add = new Node<T>(data,NULL);
    if(add)
    {
        if(this->isEmpty())
        {
            this->first = add;
        }
        else
        {
            this->last->next = add;
        }

        this->last = add;
        this->counter++;
    }
}
template <typename T>
void queue<T>::dequeue()
{
    if(!this->isEmpty())
    {
        Node<T>* remove = this->first;
        if(remove)
        {
            if(this->size() == 1)
            {
                this->init();
            }
            else
            {
            this->first = this->first->next;
            delete remove;
            this->counter--;
            }
        }
    }else cout<<"Empty queue"<<endl;
}
template <typename T>
T queue<T>::front() const
{
    if(!this->isEmpty())
    return this->first->data;

    else return 0;
}
template <typename T>
T queue<T>::end() const
{
    if(!this->isEmpty())
    return this->last->data;

    else return 0;
}
template <typename T>
size_t queue<T>::size() const
{
    return this->counter;
}
//the queue private methods
template <typename T>
bool queue<T>::isEmpty() const
{
    return this->counter == 0;
}
template <typename T>
void queue<T>::copy(const queue& q)
{

    Node<T>* node = q.first;
    for(size_t i = 0; i < q.size(); i++)
    {
        this->enqueue(node->data);
        node = node->next;
    }
}
template <typename T>
void queue<T>::init()
{
    this->first = NULL;
    this->last = NULL;
    this->counter = 0;
}
template <typename T>
void queue<T>::empty()
{
    for(size_t i = 0; i < this->size(); i++)
        this->dequeue();
}
