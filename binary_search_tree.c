#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
int data;
struct Node* left;
struct Node* right;
}Node;

//function to create new node

Node* createNode(int data)
{

    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

//function to insert a new node to the binary tree
Node* insertNode(Node* root,int data)
{
    if(root==NULL)
    {
        return createNode(data);
    }
    if(data>root->data)
    {
        root->right=insertNode(root->right,data);
    }
    else if(data<root->data)
    {
        root->left=insertNode(root->left,data);

    }
    return root;

}



//function to find the minimum vale

Node* findMin(Node* root)
{
    Node* curr= root;
    while(curr&&curr->left!=NULL)
    {
        curr=curr->left;
    }
    return curr;
}
Node* findMax(Node* root)
{

    Node* curr=root;
    while(curr&&curr->right!=NULL)
    {
        curr=curr->right;
    }
    return curr;
}


//inoreder traversal
void inorder(Node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void postorder(Node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
void preorder(Node* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void converspreorder(Node* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        converspreorder(root->right);
        converspreorder(root->left);
    }
}
Node* deleteNode(Node* root,int key)
{

    if(root==NULL)
    {
        return root;
    }
    if(key<root->data)
    {
        root->left=deleteNode(root->left,key);
    }else if(key>root->data)
    {

        root->right=deleteNode(root->right,key);
    }else{
    //Node with one or no child
    if(root->left==NULL)
    {
        Node* temp=root->right;
        free(root);
        return temp;
    }
    else if(root->right==NULL)
    {
        Node* temp=root->left;
        free(root);
        return temp;
    }
    //Node with 2 children
    Node* temp= findMin(root->right);
    root->data=temp->data;
    root->right=deleteNode(root->right,temp->data);
    }
    return root;

}

Node* search(Node* root , int key)
{
    if(root==NULL||root->data==key)
    {
        return root;
    }
    if(key<root->data)
    {
        return search(root->left,key);
    }
    return search(root->right,key);
}

int height(Node* root)
{

    if(root==NULL)
        return 0;


    int heightleft = height(root->left);
    int heightright = height(root->right);
    return(heightleft>heightright?heightleft:heightright)+1;
}
void printlevel(Node* root,int level)
{
    if(root==NULL)
    {
        return;
    }
    if(level==1)
    {
        printf("%d ",root->data);
    }
    else if(level>1)
    {
        printlevel(root->left,level-1);
        printlevel(root->right,level-1);
    }
}

int main()
{
    Node* root=NULL;
    root=insertNode(root,15);
    root=insertNode(root,19);
    root=insertNode(root,5);
    root=insertNode(root,1);
    Node* Min = findMin(root);
    printf("%d\n",Min->data);
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    Node* Max = findMax(root);
    printf("%d\n",Max->data);
    converspreorder(root);
    Node* result=search(root,1);
    if(result!=NULL)
    {
        printf("Found\n");

    }
    else{
        printf("Not found\n");
    }
    deleteNode(root,19);
    printf("\n");
    root=insertNode(root,19);
    printlevel(root,2);

}
