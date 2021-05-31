//Alexis Francis & Jillian Hanson
//This is avlTree_impl_protected.h, where we implement all the other
//functions and helper functions

#ifndef AVLTREE_AVLTREE_IMPL_PROTECTED_H
#define AVLTREE_AVLTREE_IMPL_PROTECTED_H

#include "avlTree.h"
using namespace std;

//remove_h
template<class K, class V>
Node<K,V> * AVLTree<K,V>::remove_h(K key, Node<K,V>*n){
    if(n == nullptr){
        cout << "Throwing tantrum now" << endl;
    }
    else if(key < n->key){
        n->left = remove_h(key, n->left);
        return rebalance_RH(n);
    }
    else if(key > n->key){
        n->right = remove_h(key, n->right);
        return rebalance_LH(n);
    }
    else{
        if(n->left == nullptr){
            Node<K,V>*toReturn = n->right;
            delete(n);
            return toReturn;
        }
        else if(n->right == nullptr){
            Node<K,V>*toReturn = n->left;
            delete(n);
            return toReturn;
        }
        else{
            pair<K,V> p;
            p = getMax_h(n->left);
            n->key = p.first;
            n->value = p.second;
            n->left = remove_h(p.first, n->left);
            return n;
        }
    }
}
//getNode
template<class K, class V>
Node<K,V> * AVLTree<K,V>::getNode(K key, Node<K,V>*n){
    if(n == nullptr){
        return nullptr;
    }
    else if(key < n->key){
        return getNode(key, n->left);
    }
    else if(key > n->key){
        return getNode(key, n->right);
    }
    else{
        return n;
    }
}
//rightRotate
template<class K, class V>
Node<K,V> * AVLTree<K,V>::rightRotate(Node<K,V> *a) {
    //testing
    cout << "rightRotate(" << a->key << ")" << endl;
    Node<K,V> *b = a->left;
    Node<K,V> *t2 = b->right;
    //perform the rotation
    b->right = a;
    a->left = t2;
    //update heights
    a->height = recalculateHeight(a);
    b->height = recalculateHeight(b);
    //return new node on top
    return b;
}
//leftRotate
template<class K, class V>
Node<K,V> * AVLTree<K,V>::leftRotate(Node<K, V> *a) {
    //testing
    cout << "leftRotate(" << a->key << ")" << endl;
    Node<K,V> *b = a->right;
    Node<K,V> *t2 = b->left;
    //perform the rotation
    b->left = a;
    a->right = t2;
    //update heights
    b->height = recalculateHeight(b);
    a->height = recalculateHeight(a);
    //return new node on top
    return b;
}
//recalculateHeight
template<class K, class V>
int AVLTree<K,V>::recalculateHeight(Node<K,V> *n) {
    int lh = height(n->left);
    int rh = height(n->right);
    if(lh > rh) {
        return lh + 1;
    }
    else {
        return rh + 1;
    }
}
//height
template<class K, class V>
int AVLTree<K,V>::height(Node<K, V> *n) {
    if (n == nullptr) {
        return -1;
    }
    else {
        return n->height;
    }
}
//insert_h
template<class K, class V>
Node<K,V> * AVLTree<K,V>::insert_h(K key, V value, Node<K, V> *n) {
    if (n == nullptr) {
        return new Node<K,V>(key, value);
    } else if (key < n->key) {
        n->left = insert_h(key, value, n->left);
        return rebalance_LH(n);
    } else if (key > n->key) {
        n->right = insert_h(key, value, n->right);
        return rebalance_RH(n);
    } else {
        cout << "Tantrum in Progress" << endl;
    }
}
//rebalance_LH
template<class K, class V>
Node<K,V> * AVLTree<K,V>::rebalance_LH(Node<K, V> *n) {
    //test if unbalance
    //test if left is 2 more that right
    int lh = height(n->left);
    int rh = height(n->right);
    if (lh == rh + 2) {
        //test if L-R, if so, move to L-L
        Node<K,V> *theLeft = n->left;
        if (height(theLeft->right) > height(theLeft->left)) {
            cout << "L-R case" << endl;
            n->left = leftRotate(theLeft);
            //we are now in L-L case
        }
        cout << "L-L case" << endl;
        return rightRotate(n);
    }
    else {
        //n is height balanced
        n->height = recalculateHeight(n);
        return n;
    }
}
//rebalance_RH
template<class K, class V>
Node<K,V> * AVLTree<K,V>::rebalance_RH(Node<K, V> *n) {
    //test if unbalance
    //test if left is 2 more that right
    int lh = height(n->left);
    int rh = height(n->right);
    if (rh == lh + 2) {
        //test if R-L, if so, move to R-R
        Node<K,V> *theRight = n->right;
        if (height(theRight->left) > height(theRight->right)) {
            cout << "R-L case" << endl;
            n->right = rightRotate(theRight);
            //we are now in R-R case
        }
        cout << "R-R case" << endl;
        return leftRotate(n);
    }
    else {
        //n is height balanced
        n->height = recalculateHeight(n);
        return n;
    }
}
//preorder_h
template<class K, class V>
Node<K,V> * AVLTree<K, V>:: preorder_h(vector<pair<K,V>> &v, Node<K,V>*n){
    if(n != nullptr){
        v.push_back(make_pair(n->key, n->value));
        preorder_h(v, n->left);
        preorder_h(v, n->right);
    }
}
//inorder_H
template<class K, class V>
Node<K,V> *AVLTree<K,V>:: inorder_h(vector<pair<K,V>>&v, Node<K,V>*n){
    if(n != nullptr){
        inorder_h(v, n->left);
        v.push_back(make_pair(n->key, n->value));
        inorder_h(v, n->right);
    }
}
//postorder_h
template<class K, class V>
Node<K,V> *AVLTree<K,V>::postorder_h(vector<pair<K,V>>&v, Node<K,V>*n){
    if(n != nullptr){
        postorder_h(v, n->left);
        postorder_h(v, n->right);
        v.push_back(make_pair(n->key, n->value));
    }
}
//getMax
template<typename K, typename V>
pair<K, V> AVLTree<K, V>::getMax() {
    return getMax_h(root);
}
//getMax_h
template<typename K, typename V>
pair<K, V> AVLTree<K, V>::getMax_h(Node<K,V> *n) {
    if (n == nullptr) {
        cout << "Tantrum in Progress" << endl;
    }
    else if (n->right != nullptr) {
        return getMax_h(n->right);
    }
    else {
        return pair<K,V>(n->key, n->value);
    }
}

#endif //AVLTREE_AVLTREE_IMPL_PROTECTED_H
