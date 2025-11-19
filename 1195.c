#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;


int preOrderArr[500];
int inOrderArr[500];
int postOrderArr[500];

int preIdx, inIdx, postIdx;


Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        
        exit(1); 
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


Node* insert(Node* root, int value) {

    if (root == NULL) {
        return createNode(value);
    }
    
    
    if (value < root->data) {
       
        root->left = insert(root->left, value);
    } else {
       
        root->right = insert(root->right, value);
    }
    
 
    return root;
}


void preOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    preOrderArr[preIdx++] = root->data; 
    preOrder(root->left);               
    preOrder(root->right);              
}


void inOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);                
    inOrderArr[inIdx++] = root->data;  
    inOrder(root->right);               
}


void postOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);                
    postOrder(root->right);               
    postOrderArr[postIdx++] = root->data; 
}

void freeTree(Node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}


void printTraversal(const char* prefix, int arr[], int N) {
    printf("%s", prefix);
    for (int i = 0; i < N; i++) {
        
        printf(" %d", arr[i]);
    }
    printf("\n");
}

int main() {
    int C, N, value;
    
    
    scanf("%d", &C);
    
    for (int i = 1; i <= C; i++) {
       
        Node* root = NULL;
        
        scanf("%d", &N);
        
        for (int j = 0; j < N; j++) {
            scanf("%d", &value);
            root = insert(root, value);
        }
        
        preIdx = 0;
        inIdx = 0;
        postIdx = 0;
        

        preOrder(root);
        inOrder(root);
        postOrder(root);
        
    
        printf("Case %d:\n", i);
        printTraversal("Pre.:", preOrderArr, N);
        printTraversal("In..:", inOrderArr, N);
        printTraversal("Post:", postOrderArr, N);
        
  
        printf("\n");
        

        freeTree(root);
    }
    
    return 0;
}
