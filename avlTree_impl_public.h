//Alexis Francis & Jillian Hanson
//This is avlTree_impl_public.h, where we implement most of the public functions
//from the avlTree.h file
#ifndef AVLTREE_AVLTREE_IMPL_PUBLIC_H
#define AVLTREE_AVLTREE_IMPL_PUBLIC_H
#include <queue>
#include <utility>
#include <iostream>
#include"avlTree.h"

using namespace std;

//Node Constructor
template<class K, class V>
Node<K,V>::Node(K key, V value) {
    this->key = key;
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
    this->height = 0;
}
//AvlTree Constructor
template<class K, class V>
AVLTree<K,V>::AVLTree() {
    this->size = 0;
    this->root = nullptr;
}
//getSize
template<class K, class V>
int AVLTree<K,V>::getSize() {
    return this->size;
}
//isEmpty
template<class K, class V>
bool AVLTree<K,V>::isEmpty() {
    if(getSize() > 0) {
        return false;
    }
    else {
        return true;
    }
}
//insert
template<class K, class V>
void AVLTree<K,V>::insert(K key, V value){
    root = insert_h(key, value, root);
    size++;
}
//update
template<class K, class V>
void AVLTree<K,V>::update(K key, V value){
    Node<K,V> *n = getNode(key, root);
    if(n != nullptr){
        n->value = value;
    }
    else{
        cout << "Throwing tantrum now" << endl;
    }
}
//get
template<class K, class V>
V AVLTree<K,V>::get(K key) {
    Node<K,V> *n = getNode(key, root);
    if(n != nullptr){
        return n->value;
    }
    else{
        cout << "Throwing tantrum now" << endl;
    }
}
//contains
template<class K, class V>
bool AVLTree<K,V>::contains(K key){
    return getNode(key, root) != nullptr;
}
//remove
template<class K, class V>
void AVLTree<K,V>::remove(K key){
    root = remove_h(key, root);
}
//getKeys
template<class K, class V>
vector<K> AVLTree<K,V>::getKeys(){
    vector<pair<K,V>> get = getItems();
    vector<K> toReturn;
    for (int i=0; i < get.size(); i++) {
        toReturn.push_back(get.at(i).first);
    }
    return toReturn;
}
//getItems
template<class K, class V>
vector<pair<K,V>> AVLTree<K,V>::getItems(){
    return inOrder();
}
//preOrder
template<class K, class V>
vector<pair<K,V>> AVLTree<K,V>::preOrder() {
    vector<pair<K,V>> v;
    preorder_h(v, root);
    return v;
}
//inOrder
template<class K, class V>
vector<pair<K,V>> AVLTree<K,V>::inOrder(){
    vector<pair<K,V>> v;
    inorder_h(v, root);
    return v;
}
//postOrder
template<class K, class V>
vector<pair<K,V>> AVLTree<K,V>::postOrder(){
    vector<pair<K,V>> v;
    postorder_h(v, root);
    return v;
}
//levelOrder
template <class K, class V>
void AVLTree<K,V>::levelOrder() {
    queue<pair<Node<K,V>*,int>> q;
    q.push(make_pair(root,0));
    int currentLevel = -1;
    while (!q.empty()) {
        // update current pair
        pair<Node<K,V>*,int> current = q.front();
        q.pop();

        // if starting a new level, announce it
        if (currentLevel < current.second) {
            currentLevel = current.second;
            cout << "***** STARTING LEVEL " << currentLevel << " *****" << endl;
        }

        // print the key of the current Node
        Node<K,V>* currentNode = current.first;
        cout << currentNode->key << endl;

        // enqueue the children
        if (currentNode->left != nullptr) {
            q.push(make_pair(currentNode->left, currentLevel+1));
        }
        if (currentNode->right != nullptr) {
            q.push(make_pair(currentNode->right, currentLevel+1));
        }
    }
}
#endif

