#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
    struct node *prv;
    int value;
    struct node *nxt;
};
    // to add the nodes to a list

void add_begin(struct node **hd_ptr) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d",&temp->value);
    if(*hd_ptr == NULL)
        temp->nxt = NULL;
    else {
        temp->nxt = *hd_ptr;
        temp->nxt->prv = temp;
    }
    temp->prv = NULL;
    *hd_ptr = temp;
}
void add_end(struct node **hd_ptr) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d",&temp->value);
    if(*hd_ptr == NULL) {
        temp->nxt = temp->prv = NULL;
        *hd_ptr = temp;
    } else {
        struct node *last = *hd_ptr;
        while(last->nxt)
            last = last->nxt;
        temp->nxt = last->nxt;
        temp->prv = last;
        last->nxt = temp;
    }
}
void add_middle(struct node **hd_ptr) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d",&temp->value);
    if(*hd_ptr == NULL) {
        temp->nxt = temp->prv = NULL;
        *hd_ptr = temp;
    } else if((*hd_ptr)->prv == NULL && ((*hd_ptr)->value > temp->value)) {
        temp->prv = (*hd_ptr)->prv;
        temp->nxt = *hd_ptr;
        (*hd_ptr)->prv = temp;
        *hd_ptr = temp;
    } else {
        struct node *last = *hd_ptr;
        while((last->nxt) && (temp->value > last->nxt->value))
            last = last->nxt;
        temp->prv = last;
        temp->nxt = last->nxt;
        if(last->nxt!=NULL)
            last->nxt->prv = temp;
        last->nxt = temp;
    }
}
int check_list(struct node *hd_ptr) {
    if(hd_ptr == NULL) {
        printf("list is empty...\n");
        return 1;
    } else
        return 0;
}
int print(struct node *hd_ptr) {
    if(check_list(hd_ptr))
        return 0;
    while(hd_ptr) {
        printf("%d -> ",hd_ptr->value);
        hd_ptr = hd_ptr->nxt;
    }
    printf("\n");
}
void delete_all(struct node **hd_ptr) {
    struct node *temp;
    while(*hd_ptr) {
        temp = *hd_ptr;
        *hd_ptr = (*hd_ptr)->nxt;
        if(*hd_ptr)
            (*hd_ptr)->prv = temp->prv;
        free(temp);
    }
}
    // to find the length of the list

int count(struct node *hd_ptr) {
    int Count=0;
    while(hd_ptr) {
        ++Count;
        hd_ptr = hd_ptr->nxt;
    }
    return Count;
}
int _delete(struct node **hd_ptr,int value) {
    if(check_list(*hd_ptr))
        return 0;
    struct node *temp = *hd_ptr;
    while(temp) {
        if(temp->value == value) {
            if(temp == *hd_ptr) {
                *hd_ptr = temp->nxt;
                (*hd_ptr)->nxt = temp->prv;
            } else {
                temp->prv->nxt = temp->nxt;
                if(temp->nxt)
                    temp->nxt->prv = temp->prv;
            }
            free(temp);
            return;
        } else
            temp = temp->nxt;
    }
    printf("the given valueue is not present in the list..\n");
}
int reverse_data(struct node *hd_ptr,int Count) {
    if(check_list(hd_ptr))
        return 0;
    struct node *start_node,*end_node,temp;
    start_node = end_node = hd_ptr;
    int i,size;
    while(end_node->nxt)
        end_node = end_node->nxt;
    size = sizeof(struct node) - (2*sizeof(struct node *));
    for(i=0;i<Count/2;i++) {
        memcpy((int*)(&temp)+1,(int*)start_node+1,size);
        memcpy((int*)start_node+1,(int*)end_node+1,size);
        memcpy((int*)end_node+1,(int*)(&temp)+1,size);
        start_node = start_node->nxt;
        end_node = end_node->prv;
    }
}
int main() {
    char opt;
    int value;
    struct node *hd_ptr = NULL;
    do {
        //add_begin(&hptr);
        add_end(&hd_ptr);
        printf("do you want to add another node: y/n \n");
        scanf(" %c",&opt);
    } while(opt == 'y' ||opt == 'Y');
    print(hd_ptr);
    add_middle(&hd_ptr);
    print(hd_ptr);
    //delete_all(&hptr);
    printf("Enter the valueue to be deleted: ");
    scanf("%d",&value);
    _delete(&hd_ptr,value);
    print(hd_ptr);
    reverse_data(hd_ptr,count(hd_ptr));
    print(hd_ptr);
}

