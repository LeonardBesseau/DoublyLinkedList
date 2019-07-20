//
// Created by leonard on 7/19/19.
//

#ifndef DATASTRUCTURES_LINKEDLIST_H
#define DATASTRUCTURES_LINKEDLIST_H

#include <stdexcept>

template<class T>
struct Node{

    T value;
    Node<T>* prev;
    Node<T>* next;
};

template <typename T>
class LinkedList{

protected:
    int _size;
    Node<T>* root;
    Node<T>* last;

    /**
     * get a node at the index
     * @param index The index of the node
     * @return A pointer to a node
     * @throw std::out_of_range
     */
    Node<T>* getNode(int index);

public:
    LinkedList();
    LinkedList(int sizeIndex, T _t);
    ~LinkedList();


    virtual int size();

    virtual int add(int index, T);
    virtual int add(T);

    virtual int unshift(T);

    virtual bool set(int index, T);

    virtual T remove(int index);

    virtual T pop();

    virtual T shift();

    virtual T get(int index);

    virtual void clear();
    inline T& operator[](int index);
    inline T& operator[](size_t& i) { return this->get(i); }
    inline const T& operator[](const size_t& i) const { return this->get(i); }
};


template<typename T>
LinkedList<T>::LinkedList() {
    root=NULL;
    last=NULL;
    _size=0;
}

//Deconstructor
template<typename T>
LinkedList<T>::~LinkedList(){
    Node<T>* tmp;
    //While
    while(root!=NULL){
        tmp=root;
        root=root->next;
        delete tmp;
    }
    last = NULL;
    _size=0;
}

template<typename T>
Node<T>* LinkedList<T>::getNode(int index) {
    int position = 0;
    Node<T>* current = root;

    if(index >= _size || index < 0){
        throw std::out_of_range ("Index not in the list");
    }

    while(position < index && current){
        current = current->next;
        position++;
    }

    return current;
}

template<typename T>
int LinkedList<T>::size() {
    return _size;
}

template<typename T>
LinkedList<T>::LinkedList(int sizeIndex, T _t) {
    if(sizeIndex <= 0){
        throw std::invalid_argument ("Size must be bigger than 0");
    }
    root= nullptr;
    last= nullptr;
    _size = 0;
    for (int i = 0; i < sizeIndex; ++i) {
        add(_t);
    }
}

template<typename T>
int LinkedList<T>::add(int index, T _t) {

    if(index >= _size){
        return add(_t);
    }

    if(index == 0){
        return unshift(_t);
    }

    auto* newNode = new Node<T>();
    Node<T>* _prev = getNode(index-1);
    Node<T>* _next = _prev->next;

    //Set value of new Node
    newNode->value = _t;

    //Add reference for next node
    newNode->next = _next;
    _next->prev = newNode;

    //Add reference for previous node
    newNode->prev=_prev;
    _prev->next=newNode;

    _size++;

    return _size;
}

template <typename T>
int LinkedList<T>::add(T _t) {
    auto* newNode= new Node<T>();

    newNode->value = _t;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if(root){
        //Items already present in the list
        last->next = newNode;
        newNode->prev = last;
        last = newNode;
    }else{
        root=newNode;
        last=newNode;
    }
    _size++;

    return _size;
}

template <typename T>
int LinkedList<T>::unshift(T _t) {

    if(_size == 0){
        return add(_t);
    }

    auto* newNode = new Node<T>();

    newNode->value = _t;

    newNode->next = root;
    root->prev=newNode;

    root=newNode;

    _size++;

    return _size;
}

template <typename T>
T& LinkedList<T>::operator[](int index) {
    return getNode(index)->value;
}

template <typename T>
bool LinkedList<T>::set(int index, T _t) {
    if(index < 0 || index >= _size){
        throw std::out_of_range ("Index not in the list");
    }

    getNode(index)->value = _t;
    return true;
}

template <typename T>
T LinkedList<T>::pop() {
    if(_size <= 0){
        return NULL;
    }

    if(_size >= 2){
        Node<T>* node = getNode(_size-2);
        T output = node->next->value;
        delete(node->next);
        node->next= nullptr;
        last=node;
        _size--;
        return output;
    }else{
        T output = root->value;
        delete(root);
        root = nullptr;
        last = nullptr;
        _size = 0;
        return output;
    }
}

template <typename T>
T LinkedList<T>::shift() {
    if(_size <= 0){
        return NULL;
    }

    if(_size > 1){
        Node<T>* _next = root->next;
        T output = root->value;

        delete(root);
        root = _next;
        root->prev= nullptr;
        _size--;

        return output;
    }else{
        return pop();
    }
}

template <typename T>
T LinkedList<T>::remove(int index) {
    if( index < 0 || index >= _size){
        throw std::out_of_range ("Index not in the list");
    }

    if(index == 0)
        return shift();

    if (index == _size-1)
    {
        return pop();
    }

    Node<T>* node = getNode(index-1);
    Node<T>* toDelete = node->next;
    T output = toDelete->value;

    node->next= toDelete->next;
    toDelete->next->prev=node;
    delete(toDelete);
    _size--;
    return output;
}

template <typename T>
T LinkedList<T>::get(int index) {
    return getNode(index)->value;
}

template <typename T>
void LinkedList<T>::clear() {
    while(_size > 0){
        shift();
    }
}

#endif //DATASTRUCTURES_LINKEDLIST_H