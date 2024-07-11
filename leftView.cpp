#include<iostream>
#include<vector>
#include<queue>
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

Node*createTree(){
    cout<<"Enter Node Values:";
    int value;
    cin>>value;
    if(value==-1){
        return NULL;
    }
    //creating Node:
    Node*root=new Node(value);
    cout<<"Entering in left of: "<<value<<endl;
    root->left=createTree();
    cout<<"Entering in right of: "<<value<<endl;
    root->right=createTree();
    return root;
}

void levelOrder(Node*root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    cout<<endl;
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
    }
}

//using recursion:
void printLeftView(Node*root, int level, vector<int>&leftView){
    if(root==NULL){
        return;
    }
    if(level==leftView.size()){
        leftView.push_back(root->data);
    }
    printLeftView(root->left, level+1, leftView);
    printLeftView(root->right, level+1, leftView);
}

int main(){
    Node*root=createTree();
	//10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1 
    cout<<"The constructed Tree is: "<<endl;
    levelOrder(root);
    vector<int>leftView; 
    cout<<"Printing Left View: "<<endl;
    printLeftView(root, 0, leftView);
    for(int i=0;i<leftView.size();i++){
        cout<<leftView[i]<<" ";
    }
    cout<<endl;
    return 0;
}