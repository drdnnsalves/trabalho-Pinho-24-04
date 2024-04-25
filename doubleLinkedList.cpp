#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// poggers
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
void insertBefore(Node**, Node*, int);
void deleteNodeByValue(Node**, int);
Node* searchNodeByValue(Node**, int);


int main()
{
    Node* head = nullptr;
    displayList(head);
    cout << "#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=" << endl;
    
    insertEnd(&head, 0);
    insertEnd(&head, 1);
    insertEnd(&head, 69);
    insertEnd(&head, 3);
    insertFront(&head, 12);
    displayList(head);
    cout << "#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=" << endl;
    
    cout << "Inserting number 42 before 69 and 32 before 12: " << endl;
    insertBefore(&head, searchNodeByValue(&head, 69), 42); // inserir 42 "antes" dada a posição do 69
    insertBefore(&head, searchNodeByValue(&head, 12), 32); // inserir 32 "antes" dada a posição do 12
    displayList(head);
    cout << "#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=" << endl;
    
    cout << "Inserting number -12 after 0 and 9 after 3: " << endl;
    insertAfter(searchNodeByValue(&head, 0), -12); // inserir -12 "após" dada a posição do 0
    insertAfter(searchNodeByValue(&head, 3), 9); // inserir 9 "após" dada a posição do 3
    displayList(head);
    
    cout << "#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=" << endl;
    cout << "Deleting number 1 (by position): " << endl;
    deleteNode(&head, searchNodeByValue(&head, 1));
    displayList(head);
    cout << endl;
    
    cout << "#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=" << endl;
    
    cout << "Deleting number 0 (by value): " << endl;
    deleteNodeByValue(&head, 0);
    displayList(head);
        cout << endl;
    
    cout << "Deleting number 3 (by value): " << endl;
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
    
    if ((*head) == ptrDelete)
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


void insertBefore(Node** head, Node* ptrLocation, int iPayload) {
    if (ptrLocation == nullptr) {
        cout << "Location null" << endl;
        return;
    }
    
    Node* newNode = createNode(iPayload);
    
    newNode->ptrPrev = ptrLocation->ptrPrev;
    newNode->ptrNext = ptrLocation;
    
    if (ptrLocation->ptrPrev != nullptr) {
        newNode->ptrPrev->ptrNext = newNode;
    } else {
        *head = newNode;
    }
    
    ptrLocation->ptrPrev = newNode;
}

Node* searchNodeByValue(Node** head, int iValue) {
    Node* current = nullptr;
    for (current = (*head); current->ptrNext != nullptr; current = current->ptrNext) {
        if (current->iPayload == iValue) {
            return current;
        }
    }
    if (current->iPayload == iValue) {
        return current;
    }
    // caso o nó não seja encontrado, retorna null
    return nullptr;
}

void deleteNodeByValue(Node** head, int iValue) {
    // Estrutura vazia
    if (*head == nullptr) {
        cout << "Não há como remover" << endl;
        return;
    }
    Node* temp = searchNodeByValue(&(*head), iValue);

    temp->ptrPrev->ptrNext = temp->ptrNext;
    if (temp->ptrNext != nullptr)
        temp->ptrNext->ptrPrev = temp->ptrPrev;
        
    // Caso o número pedido não está na estrutura
    if (temp == nullptr) {
        cout << "Valor dado não está na estrutura" << endl;
        return;
    }
    
    free(temp);
}
