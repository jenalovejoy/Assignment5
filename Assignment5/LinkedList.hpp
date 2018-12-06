//  CS300 - Assignment #2 due Friday, Oct. 19  - Resubmitted on 11/12
//  Jena Lovejoy
//  LinkedList.hpp creates the Linked List data structure

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>
using namespace std;

template <class T>
struct node{
    T data;
    node* next;
};

template <class T>
class LinkedList{
    private:
        LinkedList(const LinkedList&)=delete; //copy constructor
    
    public:
        int count;
        node<T> *head, *last;
        LinkedList();
        bool isEmpty();
        int length();
        T front();
        T back();
        void insertFirst(T&);
        void insertLast(T&);
        void deleteNode(T&);
        void copyList(LinkedList<T>& list);
        void destroylist();
        T& search(T&);
        LinkedList<T>& operator=(LinkedList<T>&);
        template <class U>
        friend ostream& operator<<(ostream& os, LinkedList<U>& list);
        ~LinkedList();
};
template <class T>
LinkedList<T>::LinkedList(){
    head = NULL;
    last = NULL;
    count = 0;
}
template <class T>
bool LinkedList<T>::isEmpty(){
    return head==NULL;
}
template <class T>
int LinkedList<T>::length(){
    return count;
}
template <class T>
T LinkedList<T>::front(){
    return head->data;
}
template <class T>
T LinkedList<T>::back(){
    return last->data;
}
template <class T>
void LinkedList<T>::insertFirst(T& item){
    node<T> *temp = new node<T>;
    temp->data = item;
    temp->next = NULL;
    cout << item << endl;
    if (head == NULL){
        head = temp;
        last = temp;
    } else {
        temp->next = head;
        head = temp;
    }
    count++;    
}
template <class T>
void LinkedList<T>::insertLast(T& item){
    node<T> *newnode = new node<T>;
    newnode->data = item;
    newnode->next = NULL;
    if(head==NULL){
        head = last = newnode;
    }else{
        last->next = newnode;
        last = newnode;
    }
    count++;
}

template <class T>
void LinkedList<T>::deleteNode(T& item){
    if(head == NULL)
        cerr<<"empty list";
    else{
        if(head->data == item){
            node<T>* p = head;
            head = head->next;
            delete p;
            count--;
            if(head==NULL) last = NULL;
        }else{
            node<T>* p = head;
            node<T>* q = p->next;
            while(q!=NULL && q->data != item){
                p = q;
                q = q->next;
            }
            if(q!=NULL){
                p->next = q->next;
                count--;
                if(last == q) last = p;
                delete q;
            }
        }
    }
}

template <class T>
void LinkedList<T>::copyList(LinkedList<T> &other){
    node<T> *p = other.head;
    destroylist();
    
    while (p != NULL){
        this->insertLast(p->data);
        p = p->next;
    }
}

template <class T>
void LinkedList<T>::destroylist(){
    node<T> *p;
    while(head != NULL){
        p = head;
        head = head->next;
        delete p;
    }
    last = NULL;
    count = 0;
}
template <class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>& list){
    if(this!= &list){
        copyList(list);
    }
    return *this;
}
template <class T>
ostream& operator<<(ostream& os, LinkedList<T>& list){
    node<T> *p = list.head;
    while(p!= NULL){
        os<<p->data<<" "<<endl;
        p = p->next;
    }
    return os;
}

template <class T>
LinkedList<T>::~LinkedList(){
    destroylist();
}

template <class T>
T& LinkedList<T>::search(T& item){
    if (head == NULL){
        return item;
    } else {
        node<T> *temp = head;
        while (temp != NULL){
            if (temp->data == item){
                return temp->data;
            }
            temp = temp->next;
        }
    }
    return item;
}


#endif /* LINKEDLIST_H_ */
