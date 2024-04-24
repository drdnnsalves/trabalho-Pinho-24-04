#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::string;

typedef struct Node {
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
} Node;


Node* createNode(int);
void insertFront(Node**, int);
void insertEnd(Node**, int);
void insertAfter(Node*, int);
void deleteNode(Node**, Node*);
void displayList(Node*);


int main()
{
    Node* head = nullptr;
    displayList(head);
    cout << "#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=" << endl;
    
    insertEnd(&head, 0);
    insertEnd(&head, 1);
    insertEnd(&head, 69);
    insertEnd(&head, 3);
    displayList(head);
    cout << "#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=" << endl;
    
    
    return 0;
}

Node* createNode(int iPayload) {
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->iPayload = iPayload;
    temp->ptrNext = nullptr;
    temp->ptrPrev = nullptr;
    
    return temp;
}

void displayList(Node* node) {
    if (node == nullptr) {
        cout << "Empty list, man." << endl;
        return;
    }
    
    if (node->ptrPrev != nullptr) {
        cout << "Mei ou derradeiro da lista; não é possível realizar displaylist" << endl;
        return;
    }
    
    cout << "Payload: ";
    
    Node* temp = node;
    while (temp != nullptr) {
        cout << temp->iPayload << " ";
        temp = temp->ptrNext;
    }
    
    cout << endl;
}

void insertFront(Node** head, int iPayload) {
    Node* newNode = createNode(iPayload);
    
    if (*head != nullptr) {
        (*head)->ptrPrev = newNode;
        newNode->ptrNext = (*head);
        (*head) = newNode;
        
        return;
    }
    
    if (*head == nullptr)
        (*head) == newNode;
        
}

void insertEnd(Node** head, int iPayload) {
    Node* newNode = createNode(iPayload);
    
    if (*head == nullptr) {
        (*head) = newNode;
        return;
    }
    
    Node* temp = (*head);
    while (temp->ptrNext != nullptr)
        temp = temp->ptrNext;
    
    newNode->ptrPrev = temp;
    temp->ptrNext = newNode;
}

void insertAfter(Node* ptrLocation, int iPayload) {
    if (ptrLocation == nullptr) {
        cout << "Location null" << endl;
        return;
    }
    
    Node* newNode = createNode(iPayload);
    
    newNode->ptrNext = ptrLocation->ptrNext;
    newNode->ptrPrev = ptrLocation;

    ptrLocation->ptrNext = newNode;
    
    if (newNode->ptrNext != nullptr)
        newNode->ptrNext->ptrPrev = newNode;
    
}

void deleteNode(Node** head, Node* ptrDelete) {
    if (*head == nullptr || ptrDelete == nullptr) {
        cout << "da pra remover nao, oh, man" << endl;
        return;
    }
    
    if (*head == ptrDelete)
        (*head) = ptrDelete->ptrNext;
        
    if (ptrDelete->ptrNext != nullptr)
        ptrDelete->ptrNext->ptrPrev = ptrDelete->ptrPrev;
    
    if (ptrDelete->ptrPrev != nullptr)
        ptrDelete->ptrPrev->ptrNext = ptrDelete->ptrNext;
    
    free(ptrDelete);
}

