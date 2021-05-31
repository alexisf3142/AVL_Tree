// Alexis Francis & Jillian Hanson
// This is the avlTree.h, where we declare the classes Node and AVLTree
// and their respective helper methods/functions
#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include "dictionary.h"

template <typename K, typename V>
class Node {

public:
    K key;
    V value;
    int height;
    Node<K,V>* left;
    Node<K,V>* right;
    Node(K key, V value);
};

template <typename K, typename V>
class AVLTree: public Dictionary<K,V> {

protected:
    Node<K,V> *root;
    int size{};

public:
    AVLTree();
    virtual int getSize();
    virtual bool isEmpty();
    virtual void insert(K key, V value);
    virtual void update(K key, V value);
    virtual V get(K key);
    virtual bool contains(K key);
    virtual void remove(K key);
    virtual vector<K> getKeys();
    virtual vector<pair<K,V>> getItems();

    vector<pair<K,V>> preOrder();
    Node<K, V> * preorder_h(vector<pair<K,V>> &v, Node<K,V>*n);
    vector<pair<K,V>> inOrder();
    Node<K, V> * inorder_h(vector<pair<K,V>> &v, Node<K,V>*n);
    vector<pair<K,V>> postOrder();
    Node<K,V> * postorder_h(vector<pair<K,V>>&v, Node<K,V>*n);
    void levelOrder();

    pair<K,V> getMax();
    pair<K,V> getMax_h(Node<K,V> *n);

    //Node Stuff
    Node<K,V>*getNode(K key, Node<K,V>*n);
    Node<K,V> *rightRotate(Node<K,V>* a);
    Node<K,V>* leftRotate(Node<K,V>* a);
    int recalculateHeight(Node<K,V>* n);
    int height(Node<K,V>* n);
    Node<K,V>* insert_h(K key, V value, Node<K,V>* n);
    Node<K,V>* remove_h(K key, Node<K,V>* n);
    Node<K,V>* rebalance_LH(Node<K,V>* n);
    Node<K,V>* rebalance_RH(Node<K,V>* n);

};

#include "avlTree_impl_protected.h"
#include "avlTree_impl_public.h"

#endif