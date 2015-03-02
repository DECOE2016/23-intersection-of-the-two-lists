#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct node
{
    int data;
    struct node* next;
};
 
/* A utility function to insert a node at the begining of a linked list*/
void push (struct node** head_ref, int new_data);
 
/* A utilty function to chec if given data is present in a list */
bool isPresent (struct node *head, int data);
 
 
/* Function to get intersection of two linked lists head1 and head2 */
struct node *getIntersection (struct node *head1, struct node *head2)
{
    struct node *result = NULL;
    struct node *t1 = head1;
 
    // Traverse list1 and search each element of it in list2. If the element
    // is present in list 2, then insert the element to result
    while (t1 != NULL)
    {
        if (isPresent(head2, t1->data))
            push (&result, t1->data);
        t1 = t1->next;
    }
 
    return result;
}
 
/* A utility function to insert a node at the begining of a linked list*/
void push (struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
/* A utility function to print a linked list*/
void printList (struct node *node)
{
    while (node != NULL)
    {
        printf ("%d ", node->data);
        node = node->next;
    }
}
 
/* A utilty function that returns true if data is present in linked list
else return false */
bool isPresent (struct node *head, int data)
{
    struct node *t = head;
    while (t != NULL)
    {
        if (t->data == data)
            return 1;
        t = t->next;
    }
    return 0;
}
 
/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    struct node* intersecn = NULL;
    struct node* unin = NULL;
 
    /*create a linked lits 1->20->3->45 */
    push (&head1, 1);
    push (&head1, 20);
    push (&head1, 3);
    push (&head1, 45);
 
    /*create a linked lits 3->24->45->90->68 */
    push (&head2, 3);
    push (&head2, 24);
    push (&head2, 45);
    push (&head2, 90);
    push (&head2, 68);
 
    intersecn = getIntersection (head1, head2);
 
    printf ("\n First list is \n");
    printList (head1);
 
    printf ("\n Second list is \n");
    printList (head2);
 
    printf ("\n Intersection list is \n");
    printList (intersecn);
 
    return 0;
}



 Intersection list is
3 45
