#include <fstream>
#include <iostream>
#include <string>
template <typename KeyType, typename ElementType>
class TreeNode
{
    KeyType key;
    ElementType info;
    TreeNode * left, * right;
    int answer [1000];
public:
   TreeNode(KeyType newKey, ElementType newInfo, TreeNode *l, TreeNode *r){
          key = newKey;
          info = newInfo;
          left = l;
          right = r;
          for(int i = 0; i<1000;i++)
                answer[i] =0;
      };
   static TreeNode * newNode(KeyType k, ElementType e,TreeNode * l, TreeNode * r) { return new TreeNode(k,e,l,r); };
   static TreeNode * insert(KeyType key, ElementType info, TreeNode * t){
        if(!t){
            t = newNode(key, info, nullptr, nullptr);
        }
        TreeNode* head = t;
        while ( t->key  !=  key){
            if(key>t->key){
                if(!t->right){
                    t->right = newNode(key,info, nullptr, nullptr);
                    return head;
                }
                t=t->right;
            }
            else if(key<t->key){
                if(!t->left){
                    t->left = newNode(key, info, nullptr, nullptr);
                    return head;
                }
                t= t->left;
            }
            else if(key==t->key){
                t->info++;
                return head; 
            }
        }
        return head;

   };
   static TreeNode * find(KeyType key , TreeNode * t){
       if(!t){
           return t;
       }
       while ( t->key  !=  key){
            if(key>t->key){
                if(!t->right)
                    return t;
                t=t->right;
            }
            else if(key<t->key){
                if(!t->left)
                    return t;
                t= t->left;
            }
            else
                return t;
        }
        return t;
   };
   static TreeNode * remove(KeyType key , TreeNode * t){
        TreeNode* temp = find(key,t);
        if(temp->left == nullptr && temp->right == nullptr){
            TreeNode* temp10=findPrev(key, t);
            if(temp10->key == key){
                temp10->key = "";
                return t;
            }
            if(temp10->right!=  nullptr && temp10->right->key == key){
                temp10->right = nullptr;
            }
            else if(temp10->left->key == key){
                temp10->left = nullptr;
            }
            delete temp;
            return t;
        }
        else if(temp->left == nullptr){
            TreeNode* temp3 = temp->right;
            temp->key = temp3 ->key;
            temp->info = temp3->info;
            temp->right = temp3->right;
            temp->left = temp3->left;
            delete temp3;
            return t;
        }
        else if(temp->right == nullptr){
            TreeNode* temp5 = temp->left;
            temp->key = temp5->key;
            temp->info = temp5 ->info;
            temp->right = temp5->right;
            temp->left = temp5->left;
            delete temp5;
            return t;
        }
        else{
            int count = 0;
            TreeNode* temp4 = temp->left;
            while(temp4->right != nullptr){
                temp4 = temp4->right;
                count++;
            }
            if(count == 0){
                temp->key = temp4->key;
                temp->info = temp4->info;
                temp->left = temp4->left;
                delete temp4;
                return t;
            }
            TreeNode* temp9 = findPrev(temp4->key, t);
            temp9->right = temp4->left;
            temp->key = temp4 ->key;
            temp->info = temp4->info;
            delete temp4;
            return t;           
        }
   };
   static TreeNode* findPrev(KeyType key, TreeNode *t){
       if(!t){
           return t;
       }
       TreeNode* answer = t;
       while ( t->key  !=  key){
            answer = t;
            if(key>t->key){
                if(!t->right)
                    return answer;
                t=t->right;
            }
            else if(key<t->key){
                if(!t->left)
                    return answer;
                t= t->left;
            }
            else
                return answer;
        }
        return answer;
   }
   static void print(std::ostream & out , TreeNode * t){
       if(t){
        out <<'[';
        print(out, t->left);
        out << '(' << t->key << ',' << t->info << ')';
        print(out, t->right);
        out << ']';
    }
    else
        out << "nullptr";
   };
   static void deleteNode(TreeNode * t) { delete t; }
   static void deleteTree(TreeNode * t){
        if(t){
            deleteTree(t->left);
            deleteTree(t->right);
            deleteNode(t);
        }
   };
   int countLengths(TreeNode* t){
   if(t){
       answer[countLengths(t->left)]++;
       answer[countLengths(t->right)]++;
       return t->key.length();
    }
    else
         return 0;
   }
   void printLengths(){
      for(int i = 1; i<1000; i++)
           if(answer[i]>0){
                 std::cout<<"length "<<i<<": "<<answer[i]<<" words"<<std::endl;
                 answer[i] = 0;
          }
   }
   static ElementType& getInfo(TreeNode* t){ return t->info;};
   static KeyType getKey(TreeNode* t){ return t->key;};
};


