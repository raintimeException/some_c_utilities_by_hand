#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node {
    int key;
    struct Node *next;
} Node;

Node *head, *tail;

void init(void)
{
    head = (Node *)malloc(sizeof(*head));
    assert(head != NULL);
    tail = (Node *)malloc(sizeof(*head));
    assert(head != NULL);

    head->next = tail;
    tail->next = tail;
}

void print_all(void)
{
    Node *t = (Node *)malloc(sizeof(*head));
    assert(t != NULL);
    
    t = head;
    while (t != tail) {
        printf("%d\n", t->key);
        t = t->next;
    }
    printf("%d\n", t->key);
}

Node *insert_key_after_node(int key, Node *n)
{
    Node *x = (Node *)malloc(sizeof(*head));
    assert(x != NULL);

    x->next = n->next;
    x->key = key;
    n->next = x;
    return x;
}

Node *delete_node_after(Node *n)
{
    n->next = n->next->next;
}

int main(void)
{
    init();
    head->key = 111;
    tail->key = 999;

    print_all();
    printf("******************\n");

    Node *v = insert_key_after_node(222, head);
    Node *w = insert_key_after_node(333, v);
    Node *x = insert_key_after_node(444, w);
    Node *y = insert_key_after_node(555, x);
    Node *z = insert_key_after_node(666, y);

    print_all();
    printf("******************\n");

    delete_node_after(x);

    print_all();
    printf("******************\n");

    free(head);
    free(tail);
    return 0;
}
