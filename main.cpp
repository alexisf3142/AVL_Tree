//Alexis Francis & Jillian Hanson
//this is main.ccp, the purpose of this file is to test
//and implement our code
#include <iostream>
#include "avlTree.h"
#include "dictionary.h"
using namespace std;

int main() {
//    //testing the tree from midterm 2, problem #5 b)
//    AVLTree<int,int> avlTree;
//    avlTree.insert(3,3);
//    avlTree.insert(2,2);
//    avlTree.insert(8,8);
//    avlTree.insert(1,1);
//    avlTree.insert(5,5);
//    avlTree.insert(10,10);
//    avlTree.insert(4,4);
//    avlTree.insert(6,6);
//    avlTree.insert(9,9);
//    avlTree.insert(11,11);
//    avlTree.levelOrder();
//    //3
//    //2 8
//    //1 5 10
//    //4 6 9 11
//    //this will cause the tree to be unbalanced, R-L case, so it needs to do a rightRotate(8)
//    //and then R-R case, so a leftRotate(3)
//    avlTree.insert(7,7);
//    avlTree.levelOrder();
//    //5
//    //3 8
//    //2 4 6 10
//    //1 7 9 11
//    //this will cause the tree to be unbalance, L-L case, so it need to do a rightRotate(3)
//    avlTree.remove(5);
//    avlTree.levelOrder();
//    //4
//    //2 8
//    //1 3 6 10
//    //7 9 11
//    //this will cause the tree to be unbalanced, R-R case so it needs to do a leftRotate(4)
//    avlTree.insert(12,12);
//    avlTree.levelOrder();
//    //8
//    //4 10
//    //2 6 9 11
//    //1 3 7 12
//
//    //testing the traversals
//    AVLTree<int,int> avlTree2;
//    avlTree2.insert(50,50);
//    avlTree2.insert(25,25);
//    avlTree2.insert(75,75);
//    avlTree2.insert(15,15);
//    avlTree2.insert(30,30);
//    avlTree2.insert(80,80);
//
//
//    cout << "preOrder" << endl;
//    //50 25 15 30 75 80
//    vector<pair<int,int>> preOrder = avlTree2.preOrder();
//    for (int i = 0; i<preOrder.size(); i++) {
//        cout << preOrder.at(i).first << " ";
//    }
//    cout << endl << "inOrder" << endl;
//    //15 25 30 50 75 80
//    vector<pair<int,int>> inOrder = avlTree2.inOrder();
//    for (int i = 0; i<inOrder.size(); i++) {
//        cout << inOrder.at(i).first << " ";
//    }
//    cout << endl << "postOrder" << endl;
//    //15 30 25 80 75 50
//    vector<pair<int,int>> postOrder = avlTree2.postOrder();
//    for (int i = 0; i<postOrder.size(); i++) {
//        cout << postOrder.at(i).first << " ";
//    }
//    cout << endl;

    AVLTree<int,int> avlTree;
    avlTree.insert(15,15);
    avlTree.insert(5,5);
    avlTree.insert(25,25);
    avlTree.insert(2,2);
    avlTree.insert(6,6);
    avlTree.levelOrder();
    avlTree.insert(8,8);
    avlTree.levelOrder();
    avlTree.insert(1,1);
    avlTree.levelOrder();
    avlTree.remove(6);
    avlTree.levelOrder();



    
    return 0;
}
