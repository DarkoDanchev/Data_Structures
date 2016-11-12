#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(const T& dt,Node<T>* lt = NULL, Node<T>* rt = NULL)
    {
        data = dt;
        left = lt;
        right = rt;
    }
};

template <typename T>
class binary_tree
{
//the private data
private:
    Node<T>* root;
//the public methods
public:
    binary_tree();
    T search(const T&);
    void insert(const T&);
    void remove(const T&);
    void destroy();
    void print() const;
    ~binary_tree();
//the private methods
private:
    void add(const T&,Node<T>*&);
    T max(Node<T>*) const;
    void deleteElement(const T&, Node<T>*&);
    void destroy_tree(Node<T>*);
    T findElement(const T&,Node<T>*&) const;
    void printTree(Node<T>*) const;
};
//the public methods
template <typename T>
binary_tree<T>::binary_tree()
{
    this->root = NULL;
}
template <typename T>
T binary_tree<T>::search(const T& element)
{
    return findElement(element,this->root);

}
template <typename T>
void binary_tree<T>::insert(const T& element)
{
    this->add(element,this->root);
}
template <typename T>
void binary_tree<T>::remove(const T& element)
{
    this->deleteElement(element,this->root);
}
template <typename T>
void binary_tree<T>::destroy()
{
    this->destroy_tree(this->root);
}
template <typename T>
void binary_tree<T>::printTree(Node<T>* node) const
{
    if(node)
    {
    printTree(node->left);

    cout<<node->data<<" ";

    printTree(node->right);

    //cout<<endl;
    }
}
template <typename T>
void binary_tree<T>::print() const
{
    this->printTree(this->root);
}
template <typename T>
binary_tree<T>::~binary_tree()
{
    this->destroy();
}
//the private methods
template <typename T>
void binary_tree<T>::add(const T& element,Node<T>*& node)
{
    if(node)
    {
        if(element < node->data)
        {
            if(node->left)
            {
                add(element,node->left);
            }
            else
            {
                node->left = new Node<T>(element,NULL,NULL);
            }

        }
        else if(element == node->data)
            return;
        else
        {
            if(node->right)
            {
            add(element,node->right);
            }
            else
            {
            node->right = new Node<T>(element,NULL,NULL);
            }
        }

    }
    else
    {
        node = new Node<T>(element,NULL,NULL);
    }
}
template <typename T>
T binary_tree<T>::max(Node<T>* val) const
{
    Node<T>* node = val;

    while(node->right)
    {
        node = node->right;
    }

    return node->data;
}
template <typename T>
void binary_tree<T>::deleteElement(const T& element,Node<T>*& node)
{
    if(element < node->data)
        deleteElement(element,node->left);
    else if(element > node->data)
        deleteElement(element,node->right);
    else
    {
        if(node->left && node->right)
        {
            node->data = max(node->left);
            deleteElement(max(node->left),node->left);
        }
        else if(node->left)
        {
            Node<T>* temp = node;
            node = node->left;

            delete temp;
        }
        else
        {
            Node<T>* temp = node;
            node = node->right;

            delete temp;

        }
    }
}
template <typename T>
void binary_tree<T>::destroy_tree(Node<T>* node)
{
    if(node)
    {
        destroy_tree(node->left);
        destroy_tree(node->right);

        delete node;
    }
}
template <typename T>
T binary_tree<T>::findElement(const T& element,Node<T>*& node) const
{
    if(element == node->data)
        return node->data;
    else if(element < node->data)
        findElement(element,node->left);
    else
        findElement(element,node->right);

    return NULL;

}

