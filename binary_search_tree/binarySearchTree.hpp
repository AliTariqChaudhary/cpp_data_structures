#include "treeNode.hpp"
#include <iostream>
template <typename KeyType, typename ElementType>
class BinarySearchTree
{
  TreeNode<KeyType,ElementType> * root = nullptr;
public:
    void insert(KeyType key, ElementType info){
        root = TreeNode<KeyType,ElementType>::insert(key,info,root);
    };
    ElementType find(KeyType key){
        TreeNode<KeyType,ElementType>* answer  = TreeNode<KeyType,ElementType>::find(key, root);
        if (!answer) {
            root = TreeNode<KeyType,ElementType>::insert(key,ElementType(),root);
            answer = TreeNode<KeyType,ElementType>::find(key,root);
        }
//        std::cout<<TreeNode<KeyType,ElementType>::getKey(answer)<<std::endl;
        return TreeNode<KeyType,ElementType>::getInfo(answer);
    };
    int & operator[](std::string s){
        TreeNode<KeyType,ElementType>* answer  = TreeNode<KeyType,ElementType>::find(s, root);
        if (!answer) {
            root = TreeNode<KeyType,ElementType>::insert(s,ElementType(),root);
            answer = TreeNode<KeyType,ElementType>::find(s,root);
        }
        return TreeNode<KeyType,ElementType>::getInfo(answer);
    }
    void remove(KeyType key){
        root = TreeNode<KeyType,ElementType>::remove(key,root);
    };
    void print(std::ostream & out){
        TreeNode<KeyType,ElementType>::print(out,root);
    };
   void countLengths(){
        root->countLengths(root);
        root->printLengths();;
        
    }    
    ~BinarySearchTree(){
        TreeNode<KeyType,ElementType>::deleteTree(root);
    };
};  
