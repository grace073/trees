#include <iostream>
#include<queue>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;

    Node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};

//function to print out the tree elements in level order:
void levelOrderTraversal(Node*root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    //start traversal
    while(!q.empty()){
        Node*front=q.front();
        q.pop();

        if(front==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<front->data<<" ";
            if(front->left!=NULL){
                q.push(front->left);
            }
            if(front->right!=NULL){
                q.push(front->right);
            }
        }
    }
}

// //define a function to search the preorder root node in the inorder array 
// int searchInorder(int inorder[], int size, int target){
//     for(int i=0;i<size;i++){ //time complexity: O(n)
//         if(inorder[i]==target){  //heavy and time consuming operation
//             return i;
//         }
//     }
//     return -1; //this wont be reached as the element is guaranteed to be present.
// }

//alternative to the above search function: Mapping <TC:O(1)>
void createMapping(int inorder[], int size, map<int,int>&valueToIndexMap){
    for(int i=0;i<size;i++){
        int element=inorder[i];
        int index=i;
        valueToIndexMap[element]=index;
    }
}

//REMEMBER!! pass postorderIndex 'BY REFERENCE':
Node*constructTreeFromPostAndInorderTraversal(map<int,int>&valueToIndexMap, int inorder[], int postorder[], int size, int &postorderIndex, int inorderStart, int inorderEnd){
    //base case:
    if(postorderIndex<0 || inorderStart>inorderEnd){
        return NULL;
    }

    int element=postorder[postorderIndex];
    postorderIndex--;
    Node*root=new Node(element);

    //search the corresponding element in the inorder array:
    
    //using search function:
    // int position=searchInorder(inorder, size, element);

    //using map:
    int position=valueToIndexMap[element];

    //recursive call:
    //REMEMBER!!
    //when postorder traversal is given, construct the right subtree first.
    root->right=constructTreeFromPostAndInorderTraversal(valueToIndexMap, inorder, postorder, size, postorderIndex, position+1, inorderEnd);
    root->left=constructTreeFromPostAndInorderTraversal(valueToIndexMap, inorder, postorder, size, postorderIndex, inorderStart, position-1);

    return root;
}

int main(){
    int inorder[]= {8,14,6,2,10,4};
    int postorder[] = {8,6,14,4,10,2};
    int size = 6;
    int postorderIndex = size-1;
    int inorderStart = 0;
    int inorderEnd = size-1; 
    map<int,int> valueToIndexMap;
    createMapping(inorder, size, valueToIndexMap);
    Node* root = constructTreeFromPostAndInorderTraversal(valueToIndexMap,inorder, postorder, size, postorderIndex, inorderStart,inorderEnd);
    
    cout << "Printing the entire tree: " << endl;
    levelOrderTraversal(root);
    return 0;
}
