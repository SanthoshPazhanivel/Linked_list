#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int val;
    struct node *nxt;
}node;
void add_begin(node **ptr)
{
    node *temp = (node *)malloc(sizeof(node));
    printf("Enter the value: ");
    scanf("%d",&temp->val);
    // first node condition..
    if(*ptr == NULL)
        temp->nxt = temp;
    // remaining node condition...
    else
    {
        temp->nxt = *ptr;
        node *temp1 = (*ptr)->nxt;
        while(temp1->nxt != (*ptr))
            temp1 = temp1->nxt;
        temp1->nxt = temp;
    }
    *ptr = temp;
}
void add_end(node  **ptr)
{
    node *temp = (node *)malloc(sizeof(node));
    printf("Enter the value: ");
    scanf("%d",&temp->val);
    if(*ptr == NULL)
    {
        temp->nxt = temp;
        *ptr = temp;
    }
    else
    {
        node *temp1 = (*ptr)->nxt;
        while(temp1->nxt != (*ptr))
            temp1 = temp1->nxt;
        temp->nxt = temp1->nxt;
        temp1->nxt = temp;
    }

}
void add_middle(node **ptr)
{
    node *temp = (node *)malloc(sizeof(node));
    printf("Enter the value: ");
    scanf("%d",&temp->val);
    if(*ptr == NULL)
    {
        temp->nxt = temp;
        *ptr = temp;
    }
    else if((*ptr)->val > temp-> val)
    {
        temp->nxt = *ptr;
        node *temp1 = (*ptr)->nxt;
        while(temp1->nxt != *ptr)
            temp1 = temp1->nxt;
        temp1->nxt = temp;
        *ptr = temp;
    }
    else
    {
        node *temp1 = (*ptr);
        while((temp1->nxt != *ptr) && (temp->val > temp1->nxt->val))
            temp1 = temp1->nxt;
        temp->nxt = temp1->nxt;
        temp1->nxt = temp;
    }
}
int check_list(node *ptr)
{
    if(ptr==NULL)
    {
        printf("The list is empty...\n");
        return 1;
    }
    else
        return 0;
}
int _delete(node **ptr)
{
    int val;
    printf("Enter the value to be deleted: ");
    scanf("%d",&val);
    if(check_list(*ptr))
        return 0;
    node *temp = *ptr,*temp1=*ptr,*prv=NULL;
    while(temp->nxt != *ptr)
        temp = temp->nxt;
    do
    {
        if(temp1->val == val)
        {
            if(temp1 == *ptr)
                temp->nxt = *ptr = temp1->nxt;
            else
                prv->nxt = temp1->nxt;
            free(temp1);
            return 0;
        }
        else
        {
            prv = temp1;
            temp1 = temp1->nxt;
        }
    }while(temp->nxt != temp1);
    printf("the given element is not found in the list..\n");
}
void delete_all(node **ptr)
{
    node *temp = *ptr,*temp1 = *ptr;
    while(temp->nxt != *ptr)
            temp = temp->nxt;
    while(temp!=temp1)
    {
        temp->nxt = *ptr = temp1->nxt;
        free(temp1);
        temp1 = *ptr;
    }
    free(temp);
    *ptr = NULL;
}

int print(node *ptr)
{
    if(check_list(ptr))
        return 0;
    node *temp = ptr;
    do
    {
        printf("%d -> ",temp->val);
        temp = temp->nxt;
    }while(temp!=ptr);
    printf("\n");
}

int main()
{
    node *hptr = NULL;
    char opt;
    do
    {
        //add_begin(&hptr);
        add_end(&hptr);
        printf("do you want to add another node: y/n \n");
        scanf(" %c",&opt);
    }while(opt == 'y' || opt == 'Y');
    print(hptr);
    add_middle(&hptr);
    print(hptr);
    // delete_all(&hptr);
    // print(hptr);
    _delete(&hptr);
    print(hptr);
}
