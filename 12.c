#include <stdio.h>
#include <stdlib.h>

typedef struct linkedListNode
{
    int data;
    struct linkedListNode *next;
} Node;
typedef Node *pNode;

pNode createNode(int data)
{
    pNode node = (pNode)malloc(sizeof(Node)); // typesetting void pointer
    node->data = data;
    node->next = NULL; // controlling wild pointers
    return node;
}

void linkNodes(pNode node1, pNode node2)
{
    node1->next = node2;
    node2->next = NULL;
}

void traverseNode(pNode node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

pNode deleteNodeByValue(pNode head, int data)
{
    pNode temp = head;

    while (temp != NULL)
    {
        if (temp->data == data && temp == head)
        {
            printf("at first...\n");
            head = head->next;
            free(temp);
            temp->next = NULL; // to prevent dangling pointers
            goto end;
        }
        if (temp->next->data == data)
        {
            printf("after first...\n");
            pNode temp2 = temp->next;
            temp->next = temp->next->next;
            free(temp2);
            temp2->next = NULL; // to prevent dangling pointers
            goto end;
        }
        temp = temp->next;
    }
end:
    return head;
}

int main()
{
    pNode HEAD, second, third, fourth;

    HEAD = createNode(97);
    second = createNode(956);
    third = createNode(11);
    fourth = createNode(800);

    linkNodes(HEAD, second);
    linkNodes(second, third);
    linkNodes(third, fourth);
    traverseNode(HEAD);

    HEAD = deleteNodeByValue(HEAD, 956);
    traverseNode(HEAD);

    return 0;
}