#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definir o tamanho
#define MAX_SIZE 100

// Estrutura para representar um livro
typedef struct {
    char title[100];
} Book;

// Estrutura para representar uma fila de livros

typedef struct {
    Book items[MAX_SIZE];
    int front, rear;
} Queue;

// Estrutura para representar uma pilha de livros
typedef struct {
    Book items[MAX_SIZE];
    int top;
} Stack;

// Funcao para inicializar uma filas
void initializeQueue(Queue *q){
    q->front = -1;
    q->rear = -1;
}

//Funcao para verificar se a fila esta vazia
int isQueueEmpty(Queue *q) {
    return (q->front == -1 && q->rear == -1);
}

// Funcao para enfileirar um livro
void enqueue(Queue *q, Book book) {
    if((q->rear +1) % MAX_SIZE == q->front) {
        printf("Queue is full. \n");
        return;
    } else if (isQueueEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }
    q->items[q->rear] = book;
}

// Funcao para desenfileirar um livro
Book dequeue(Queue *q) {
    Book dequeuedItem;
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        strcpy(dequeuedItem.title, "NULL");
        return dequeuedItem;
    } else if (q->front == q->rear) {
        dequeuedItem = q->items[q->front];
        q->front = -1;
        q->rear = -1;
        return dequeuedItem;
    } else {
        dequeuedItem = q->items[q->front];
        q->front = (q->front + 1) % MAX_SIZE;
        return dequeuedItem;
    }
}

// Funcao para inicializar uma pilha
void initializeStack(Stack *s) {
    s->top = -1;
}

// Funcao para verificar se a pilha esta vazia
int isStackEmpty(Stack *s) {
    return (s->top == -1);
}

// Funcao para empilhar um livro
void push(Stack *s, Book book) {
    if(s->top == MAX_SIZE -1) {
        printf("Stack is full.\n");
        return;
    }
    s->top++;
    s->items[s->top] = book;
}

// Funcao para desempilhar um livro
Book pop(Stack *s) {
    Book poppedItem;
    if(isStackEmpty(s)) {
        printf(" Stack is empty. \n");
        strcpy(poppedItem.title, "NULL");
        return poppedItem;
    }
    poppedItem = s->items[s->top];
    s->top--;
    return poppedItem;
}

int main() {
    // Exemplo de uso da fila e da pilha de livros
    Queue bookQueue;
    Stack bookStack;

    initializeQueue(&bookQueue);
    initializeStack(&bookStack);

    // Enfileirando alguns livros
    Book book1 = {"Book 1"};
    Book book2 = {"Book 2"};
    Book book3 = {"Book 3"};
    Book book4 = {"Book 4"};
    enqueue(&bookQueue, book1);
    enqueue(&bookQueue, book2);
    enqueue(&bookQueue, book3);
    enqueue(&bookQueue, book4);

    // Desenfileirando e empilhando livros
    while (!isQueueEmpty(&bookQueue)) {
        Book dequeuedBook = dequeue(&bookQueue);
        push(&bookStack, dequeuedBook);
        printf("%s\n", dequeuedBook.title);
    }

    // Desempilhando os livros e exibindo seus titulos
    printf("Books in reverse order:\n");
    while (!isStackEmpty(&bookStack)) {
        Book poppedBook = pop(&bookStack);
        printf("%s\n", poppedBook.title);
    }

    return 0;
}