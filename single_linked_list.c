#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"reverse.h"
typedef struct student
{
    int val;
    struct student *nxt;
}ST;
    // adding nodes to the list
void add_begin(ST**ptr) // ptr = &hptr; *ptr = hptr
{
    ST *node=(ST*)malloc(sizeof(ST));
    printf("Enter the value: ");
    scanf("%d",&node->val);
    node->nxt = *ptr;
    *ptr = node;
}
void add_end(ST**ptr)
{
    ST* node = (ST*)malloc(sizeof(ST));
    printf("Enter the value: ");
    scanf("%d",&node->val);
    if(*ptr==NULL)
    {
        node->nxt = *ptr;
        *ptr = node;
    }
    else
    {
        ST *last = *ptr;
        while(last->nxt != NULL)
            last = last->nxt;
        node->nxt = last->nxt;
        last->nxt = node;
    }
}
void add_middle(ST**ptr)
{
    ST* node = (ST*)malloc(sizeof(ST));
    printf("Enter the value: ");
    scanf("%d",&node->val);
    if((*ptr==NULL) || ((*ptr)->val > node->val))
    {
        node->nxt =*ptr;
        *ptr = node;
    }
    else
    {
        ST *last = *ptr;
        while((last->nxt!=NULL) && (node->val > last->nxt->val))
            last = last->nxt;
        node->nxt = last->nxt;
        last->nxt = node;
    }
}
    // check whether the list is empty..
int check_list(ST *ptr)
{
    if(ptr==NULL)
    {
        printf("list is empty...\n");
        return 0;
    }
    else
        return 1;
}
    //deleting all the nodes in the list...
int delete_all(ST **ptr)
{
    if(!check_list(*ptr))
        return 0;
    ST *temp;
    while(*ptr!=NULL)
    {
        temp = *ptr;
        *ptr = (*ptr) -> nxt;
        free(temp);
    }
}
    // delete a particular node in the list
int _delete(ST**ptr,int val)
{
    if(!check_list(*ptr))
        return 0;
    ST *temp=*ptr,*prv;
    while(temp)
    {
        if(temp->val==val)
        {
            if(temp == *ptr)
                *ptr = (*ptr) -> nxt;
            else
                prv->nxt = temp->nxt;
            free(temp);
            return 0;
        }
        else
        {
            prv = temp;
            temp = temp->nxt;
        }
    }
    printf("the given value is not present in the list...\n");
}

    //printing the nodes
int print(ST* ptr)
{
    if(!check_list(ptr))
        return 0;
    while(ptr!=NULL)
    {
        printf("%d -> ",ptr->val);
        ptr = ptr->nxt;
    }
    printf("\n");
}
    // to print the list in the reverse order...
void reverse_print(ST *ptr)
{
    if(ptr)
    {
        reverse_print(ptr->nxt);
        printf("%d -> ",ptr->val);
    }
    printf("\n")
}
    // to change the order with array..
/*
void reverse_data(ST *ptr,int Count)
{
    ST **temp = (ST**)malloc(Count * sizeof(ST*));
    int i,siz=sizeof(ST)-sizeof(ST*);
    for(i=0;i<Count;i++)
    {
        temp[i]=ptr;
        ptr = ptr->nxt;
    }
    ST temp1;
    for(i=0;i<Count/2;i++)
    {
        memcpy(&temp1,temp[i],siz);
        memcpy(temp[i],temp[Count-i-1],siz);
        memcpy(temp[Count-i-1],&temp1,siz);
    }
}
*/
    // without array...
void reverse_data(ST *ptr,int Count)
{
    ST* ptr1=ptr,*ptr2,temp;
    int i,j,siz=sizeof(ST)-sizeof(ST*);
    for(i=0;i<Count/2;i++)
    {
        ptr2 = ptr;
        for(j=0;j<Count-i-1;j++)
            ptr2 = ptr2->nxt;
        memmove(&temp,ptr1,siz);
        memmove(ptr1,ptr2,siz);
        memmove(ptr2,&temp,siz);
        ptr1 = ptr1 -> nxt;
    }
}
    // to reverse the link...
void reverse_link(ST **ptr,int Count)
{
    ST**temp = (ST**)malloc(Count * sizeof(ST*)),*temp1=*ptr;
    int i;
    for(i=0;i<Count;i++)
    {
        temp[i]=temp1;
        temp1 = temp1->nxt;
    }
    temp[0]->nxt=NULL;
    for(i=1;i<Count;i++)
        temp[i]->nxt = temp[i-1];
    *ptr = temp[i-1];
}
    // reverse link wihtout array
void reverse_link(ST**ptr,int Count)
{
    ST *prv,*cur=NULL;
    while(*ptr!=NULL)
    {
        prv = cur;
        cur = *ptr;
        *ptr =(*ptr)->nxt;
        cur->nxt = prv;
    }
    *ptr = curr;
}
    // to find the length of the string...
int count(ST* ptr)
{
    int count =0;
    while(ptr!=NULL)
    {
        ++count;
        ptr = ptr->nxt;
    }
    return count;
}
int main()
{
    ST * hptr=NULL;
    int val;
    char opt;
    do
    {
        //add_begin(&hptr);
        add_end(&hptr);
        printf("Do you want to add another student details: y/n\n");
        scanf(" %c",&opt);
    }while((opt=='y')||(opt=='Y'));
    print(hptr);
    /*
    add_middle(&hptr);
    print(hptr);
    delete_all(&hptr);
    print(hptr);
    */
    printf("Enter the value to be delete: ");
    scanf("%d",&val);
    _delete(&hptr,val);
    print(hptr);
    reverse_print(hptr);
    reverse_data(hptr,count(hptr));
    print(hptr);
    reverse_link(&hptr,count(hptr));
    print(hptr);
}
