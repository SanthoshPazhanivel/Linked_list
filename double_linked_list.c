/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    struct node *prv;
    int val;
    struct node *nxt;
}node;
    // add the node at begin
void add_begin(node **ptr)
{
    node *temp = (node *)malloc(sizeof(node));
    printf("Enter the value: ");
    scanf("%d",&temp->val);
    if(*ptr == NULL)
        temp->nxt = NULL;
    else
    {
        temp->nxt = *ptr;
        temp->nxt->prv = temp;
    }
    temp->prv = NULL;
    *ptr = temp;
}
    // add the node at end
void add_end(node **ptr)
{
    node *temp = (node *)malloc(sizeof(node));
    printf("Enter the value: ");
    scanf("%d",&temp->val);
    if(*ptr == NULL)
    {
        temp->nxt = temp->prv = NULL;
        *ptr = temp;
    }
    else
    {
        node *last = *ptr;
        while(last->nxt)
            last = last->nxt;
        temp->nxt = last->nxt;
        temp->prv = last;
        last->nxt = temp;
    }
}
void add_middle(node **ptr)
{
    node *temp = (node *)malloc(sizeof(node));
    printf("Enter the value: ");
    scanf("%d",&temp->val);
    if(*ptr == NULL)
    {
        temp->nxt = temp->prv = NULL;
        *ptr = temp;
    }
    else if((*ptr)->prv==NULL && ((*ptr)->val > temp->val))
    {
        temp->prv = (*ptr)->prv;
        temp->nxt = *ptr;
        (*ptr)->prv = temp;
        *ptr = temp;
    }
    else
    {
        node *last = *ptr;
        while((last->nxt) && (temp->val > last->nxt->val))
              last = last->nxt;
        temp->prv = last;
        temp->nxt = last->nxt;
        if(last->nxt!=NULL)
            last->nxt->prv = temp;
        last->nxt = temp;
    }
}
int check_list(node *ptr)
{
    if(ptr==NULL)
    {
        printf("list is empty...\n");
        return 1;
    }
    else
        return 0;
}
int print(node *ptr)
{
    if(check_list(ptr))
        return 0;
    while(ptr)
    {
        printf("%d -> ",ptr->val);
        ptr = ptr->nxt;
    }
    printf("\n");
}
void delete_all(node**ptr)
{
    node *temp;
    while(*ptr)
    {
        temp = *ptr;
        *ptr = (*ptr)->nxt;
        if(*ptr)
            (*ptr)->prv = temp->prv;
        free(temp);
    }
}
// to find the length of the list
int count(node *ptr)
{
    int Count=0;
    while(ptr)
    {
        ++Count;
        ptr = ptr->nxt;
    }
    return Count;
}
int _delete(node **ptr,int value)
{
    if(check_list(*ptr))
        return 0;
    node *temp = *ptr;
    while(temp)
    {
        if(temp->val == value)
        {
            if(temp == *ptr)
            {
                *ptr = temp->nxt;
                (*ptr)->nxt = temp->prv;
            }
            else
            {
                temp->prv->nxt = temp->nxt;
                if(temp->nxt)
                    temp->nxt->prv = temp->prv;
            }
            free(temp);
            return ;
        }
        else
            temp=temp->nxt;
    }
    printf("the given value is not present in the list..\n");

}
int reverse_data(node *ptr,int Count)
{
    if(check_list(ptr))
        return 0;
    node *start,*end,temp;
    start = end = ptr;
    int i,size;
    while(end->nxt)
        end = end->nxt;
    size = sizeof(node) - 2*sizeof(node*);
    for(i=0;i<Count/2;i++)
    {
        memcpy((int*)(&temp)+1,(int*)start+1,size);
        memcpy((int*)start+1,(int*)end+1,size);
        memcpy((int*)end+1,(int*)(&temp)+1,size);
        start = start->nxt;
        end = end->prv;
    }
}
int main()
{
    char opt;
    int value;
    node *hptr=NULL;
    do
    {
        //add_begin(&hptr);
        add_end(&hptr);
        printf("do you want to add another node: y/n \n");
        scanf(" %c",&opt);
    }while(opt == 'y' ||opt == 'Y');
    print(hptr);
    add_middle(&hptr);
    print(hptr);
    //delete_all(&hptr);
    printf("Enter the value to be deleted: ");
    scanf("%d",&value);
    _delete(&hptr,value);
    print(hptr);
    reverse_data(hptr,count(hptr));
    print(hptr);
}
*/

