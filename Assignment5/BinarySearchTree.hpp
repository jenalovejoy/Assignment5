//  CS 300 Assignment 4 due 11/21
//  Jena Lovejoy
//  BinarySearchTree.hpp creates a BST and provides functionality like search, delete, and insert

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp
#include <stdio.h>
#include <iostream>
using namespace std;

template <class T>
struct BSTnode {
    T data;
    BSTnode<T> *left;
    BSTnode<T> *right;
    
};

template <class T>
class BinarySearchTree {
private:
    BSTnode<T> *root;
    
    void insert(BSTnode<T> *&p, T &item){
        
        if (p == NULL){
            BSTnode<T> *newBSTnode = new BSTnode<T>;
            p = newBSTnode;
            newBSTnode->data = item;
            newBSTnode->left = NULL;
            newBSTnode->right = NULL;
            
            if (root == NULL){
                root = newBSTnode;
            }
            
        } else if (p->data < item){
            insert(p->right, item);
        } else if (p->data > item){
            insert(p->left, item);
        }
    }
    
    int height(BSTnode<T> *p){
        if (p == NULL){
            return 0;
        } else {
            return 1 + max(height(p->left), height(p->right));
        }
    }
    
    int max(int x, int y){
        if (x > y){
            return x;
        } else {
            return y;
        }
    }
    
    T& search(BSTnode<T> *p, T &item){
        if (p == NULL){
            return item;
            
        } else if (p->data == item){
            return p->data;
            
        } else {
            if (p->data > item){
                return search(p->left, item);
            } else if (p->data < item){
                return search(p->right, item);
            }
        }
        return item;
    }
    
    T findMin(BSTnode<T> *p, T &e){
        if (p == NULL){
            return e;
        } else if (p->left != NULL){
            return findMin(p->left);
        } else if (p->left == NULL){
            return p->data;
        }
    }
    
    T findMax(BSTnode<T> *p, T &e){
        if (p == NULL){
            return e;
        } else if (p->right != NULL){
            return findMin(p->right);
        } else if (p->right == NULL){
            return p->data;
        }
    }
    
    int count(BSTnode<T> *p){
        if (p == NULL){
            return 0;
        } else {
            return 1 + count(p->left) + count(p->right);
        }
    }
    
    void printPreOrder(BSTnode<T> *p){
        if (p != NULL){
            cout << p->data << " ";
            printPreOrder(p->left);
            printPreOrder(p->right);
        }
    }
    
    void printPostOrder(BSTnode<T> *p){
        if (p != NULL){
            printPostOrder(p->left);
            printPostOrder(p->right);
            cout << p->data << " ";
        }
    }
    
    void printInOrder(BSTnode<T> *p){
        if (p != NULL){
            printInOrder(p->left);
            cout << p->data << " ";
            printInOrder(p->right);
        }
    }
    
    void deleteBSTnode(BSTnode<T>*& p, T& item){
        if (p == NULL){
            return;
        }
        if (item < p->data){
            deleteBSTnode(p->left, item);
        } else if (item > p->data){
            deleteBSTnode(p->right, item);
        } else {
            if (p->right != NULL && p->left != NULL){
                T maxBSTnode = findMax(p->left, item);
                p->data = maxBSTnode;
                deleteBSTnode(p->left, maxBSTnode);
            } else {
                BSTnode<T> *q = p;
                if (p->left != NULL){
                    p = p->left;
                } else if (p->right != NULL){
                    p = p->right;
                } else {

                    p = NULL;
                }
                delete q; 
            }
        }
    }
    
public:
    
    BinarySearchTree(){
        root = NULL;
    }
    
    void insert(T &item){
        insert(root, item);
    }
    
    bool isEmpty(){
        return root == NULL;
        
    }
    
    int height(){
        return height(root);
    }
    
    T& search(T &item){
        return search(root, item);
    }
    
    T findMin(T &e){
        return findMin(root, e);
    }
    
    T findMax(T &e){
        return findMax(root, e);
    }
    
    int count(){
        return count(root);
    }
    
    void printPreOrder(){
        printPreOrder(root);
    }
    
    void printPostOrder(){
        printPostOrder(root);
    }
    
    void printInOrder(){
        printInOrder(root);
    }

    void deleteBSTnode(T& item){
        deleteBSTnode(root, item);
    }
};

#endif /* BinarySearchTree_hpp */
