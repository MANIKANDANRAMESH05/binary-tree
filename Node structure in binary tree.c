#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;                 
    struct Node *leftChild;   
    struct Node *rightChild;  
} Node;


Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        exit(1);
    }
    newNode->data = data;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}


void printInOrder(Node *currentNode) {
    if (currentNode != NULL) {
        printInOrder(currentNode->leftChild);
        printf("%d ", currentNode->data);
        printInOrder(currentNode->rightChild);
    }
}


int main() {
    
    Node *rootNode = createNode(10);
    rootNode->leftChild = createNode(5);
    rootNode->rightChild = createNode(15);
    rootNode->leftChild->leftChild = createNode(2);
    rootNode->leftChild->rightChild = createNode(7);
    rootNode->rightChild->leftChild = createNode(12);
    rootNode->rightChild->rightChild = createNode(20);

    
    printf("Tree in in-order traversal:\n");
    printInOrder(rootNode);
    printf("\n");
}
   
