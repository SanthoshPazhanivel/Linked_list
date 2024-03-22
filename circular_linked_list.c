#include<stdio.h>
#include<stdlib.h>
struct node {
    int val;
    struct node *nxt;
};
void add_begin(struct node **hd_ptr) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d",&temp->val);
    if(*hd_ptr == NULL)
        temp->nxt = temp;
    else
    {
        temp->nxt = *hd_ptr;
        struct node *temp1 = (*hd_ptr)->nxt;
        while(temp1->nxt != (*hd_ptr))
            temp1 = temp1->nxt;
        temp1->nxt = temp;
    }
    *hd_ptr = temp;
}
void add_end(struct node **hd_ptr) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *temp1;
    printf("Enter the value: ");
    scanf("%d",&temp->val);
    if(*hd_ptr == NULL) {
        temp->nxt = temp;
        *hd_ptr = temp;
    } else {
        temp1 = (*hd_ptr)->nxt;
        while(temp1->nxt != (*hd_ptr))
            temp1 = temp1->nxt;
        temp->nxt = temp1->nxt;
        temp1->nxt = temp;
    }
}
void add_middle(struct node **hd_ptr) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *temp1;
    printf("Enter the value: ");
    scanf("%d",&temp->val);
    if(*hd_ptr == NULL) {
        temp->nxt = temp;
        *hd_ptr = temp;
    } else if((*hd_ptr)->val > temp-> val) {
        temp->nxt = *hd_ptr;
        temp1 = (*hd_ptr)->nxt;
        while(temp1->nxt != *hd_ptr)
            temp1 = temp1->nxt;
        temp1->nxt = temp;
        *hd_ptr = temp;
    } else {
        temp1 = (*hd_ptr);
        while((temp1->nxt != *hd_ptr) && (temp->val > temp1->nxt->val))
            temp1 = temp1->nxt;
        temp->nxt = temp1->nxt;
        temp1->nxt = temp;
    }
}
int check_list(struct node *hd_ptr) {
    if(hd_ptr == NULL) {
        printf("The list is empty...\n");
        return 1;
    } else
        return 0;
}
int _delete(struct node **hd_ptr) {
    struct node *temp = *hd_ptr,*temp1 = *hd_ptr,*prv = NULL;
    int val;
    printf("Enter the value to be deleted: ");
    scanf("%d",&val);
    if(check_list(*hd_ptr))
        return 0;
    while(temp->nxt != *hd_ptr)
        temp = temp->nxt;
    do{
        if(temp1->val == val) {
            if(temp1 == *hd_ptr)
                temp->nxt = *hd_ptr = temp1->nxt;
            else
                prv->nxt = temp1->nxt;
            free(temp1);
            return 0;
        } else {
            prv = temp1;
            temp1 = temp1->nxt;
        }
    }while(temp->nxt != temp1);
    printf("the given element is not found in the list..\n");
}
void delete_all(struct node **hd_ptr) {
    struct node *temp = *hd_ptr,*temp1 = *hd_ptr;
    while(temp->nxt != *hd_ptr)
            temp = temp->nxt;
    while(temp!=temp1) {
        temp->nxt = *hd_ptr = temp1->nxt;
        free(temp1);
        temp1 = *hd_ptr;
    }
    free(temp);
    *hd_ptr = NULL;
}
int print(struct node *hd_ptr) {
    if(check_list(hd_ptr))
        return 0;
    struct node *temp = hd_ptr;
    do{
        printf("%d -> ",temp->val);
        temp = temp->nxt;
    }while(temp != hd_ptr);
    printf("\n");
}
int main()
{
    struct node *hd_ptr = NULL;
    char opt;
    do
    {
        //add_begin(&hd_ptr);
        add_end(&hd_ptr);
        printf("do you want to add another node: y/n \n");
        scanf(" %c",&opt);
    }while(opt == 'y' || opt == 'Y');
    print(hd_ptr);
    add_middle(&hd_ptr);
    print(hd_ptr);
    // delete_all(&hd_ptr);
    // print(hd_ptr);
    _delete(&hd_ptr);
    print(hd_ptr);
}
