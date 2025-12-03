#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 200

// Estrutura para um nó da lista encadeada
typedef struct Node {
    int key;
    struct Node* next;
} Node;

// Estrutura para a tabela hash
typedef struct {
    Node* head;
} HashTable[MAX_SIZE];

// Função para inicializar a tabela hash
void initializeHashTable(HashTable table, int size) {
    for (int i = 0; i < size; i++) {
        table[i].head = NULL;
    }
}

// Função para inserir um elemento na tabela hash
void insertHashTable(HashTable table, int size, int key) {
    int index = key % size;
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;

    if (table[index].head == NULL) {
        table[index].head = newNode;
    } else {
        Node* temp = table[index].head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Função para imprimir a tabela hash
void printHashTable(HashTable table, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ->", i);
        Node* temp = table[i].head;
        while (temp != NULL) {
            printf(" %d ->", temp->key);
            temp = temp->next;
        }
        printf(" \\\n");  // Indica o final da lista encadeada
    }
}

// Função para liberar a memória da tabela hash
void freeHashTable(HashTable table, int size) {
    for (int i = 0; i < size; i++) {
        Node* temp = table[i].head;
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
        table[i].head = NULL;
    }
}

int main() {
    int testCases;
    scanf("%d", &testCases);

    while (testCases--) {
        int tableSize, numKeys;
        scanf("%d %d", &tableSize, &numKeys);

        HashTable hashTable;
        initializeHashTable(hashTable, tableSize);

        for (int i = 0; i < numKeys; i++) {
            int key;
            scanf("%d", &key);
            insertHashTable(hashTable, tableSize, key);
        }

        printHashTable(hashTable, tableSize);
        freeHashTable(hashTable, tableSize);

        if (testCases) {
            printf("\n"); // Linha em branco entre os conjuntos de saída
        }
    }

    return 0;
}
