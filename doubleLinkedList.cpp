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
void insertBefore(Node*, int);
void deleteNodeByValue(Node**, int);


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
    
    cout << "Inserting number 42 before 69" << endl;
    Node* nodeToInsertBefore = head->ptrNext->ptrNext;
    insertBefore(nodeToInsertBefore, 42);
    displayList(head);
    
    cout << "#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=" << endl;
    cout << "Deleting number 1: " << endl;
    deleteNodeByValue(&head, 1);
    displayList(head);
    cout << endl;
        
    cout << "Deleting number 0: " << endl;
    deleteNodeByValue(&head, 0);
    displayList(head);
        cout << endl;
    
    cout << "Deleting number 3: " << endl;
    deleteNodeByValue(&head, 3);
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


void insertBefore(Node* ptrLocation, int iPayload) {
    if (ptrLocation == nullptr) {
        cout << "Location null" << endl;
        return;
    }
    
    Node* newNode = createNode(iPayload);
    
    // Atualiza os ponteiros
    newNode->ptrPrev = ptrLocation->ptrPrev;
    newNode->ptrNext = ptrLocation;
    
    if (ptrLocation->ptrPrev != nullptr) 
        newNode->ptrPrev->ptrNext = newNode;
    
    ptrLocation->ptrPrev = newNode;
}

void deleteNodeByValue(Node** head, int iValue) {
    // Estrutura vazia
    if (*head == nullptr) {
        cout << "Não há como remover" << endl;
        return;
    }
    Node* temp = (*head);
    // Valor no primeiro elemento
    if (temp->iPayload == iValue) {
        (*head) = temp->ptrNext;
        
        if (*head != nullptr)
            (*head)->ptrPrev = nullptr;
        free(temp);
        return;
    }
    
    while (temp != nullptr && temp->iPayload != iValue)
        temp = temp->ptrNext;
    
    // Caso o número pedido não está na estrutura
    if (temp == nullptr) {
        cout << "Valor dado não está na estrutura" << endl;
        return;
    }

    temp->ptrPrev->ptrNext = temp->ptrNext;
    if (temp->ptrNext != nullptr)
        temp->ptrNext->ptrPrev = temp->ptrPrev;
    
    free(temp);
}


// Exercício 1: Elaborar a função 'void insertBefore(Node*, int)' FEITO!
// Exercício 2: Elaborar a função 'void deleteNodeByValue(Node**, int)' FEITO!
// Exercício 3: Elaborar a função 'void searchNodeByValue(Node**, int)'


