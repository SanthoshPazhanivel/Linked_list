
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
    int value;
    struct node *nxt;
};
    // adding nodes to the list

void add_begin(struct node **hd_ptr) {
    struct node *st_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d",&st_node->value);
    st_node->nxt = *hd_ptr;
    *hd_ptr = st_node;
}
void add_end(struct node **hd_ptr) {
    struct node *st_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d",&st_node->value);
    if(*hd_ptr == NULL) {
        st_node->nxt = *hd_ptr;
        *hd_ptr = st_node;
    } else {
        struct node *prev = *hd_ptr;
        while(prev->nxt != NULL)
            prev = prev->nxt;
        st_node->nxt = prev->nxt;
        prev->nxt = st_node;
    }
}
void add_middle(struct node **hd_ptr) {
    struct node *st_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d",&st_node->value);
    if((*hd_ptr == NULL) || ((*hd_ptr)->value > st_node->value)) {
        st_node->nxt = *hd_ptr;
        *hd_ptr = st_node;
    } else {
        struct node *prev = *hd_ptr;
        while((prev->nxt != NULL) && (st_node->value > prev->nxt->value))
            prev = prev->nxt;
        st_node->nxt = prev->nxt;
        prev->nxt = st_node;
    }
}
    // check whether the list is empty..

int check_list(struct node *hptr) {
    if(hptr == NULL) {
        printf("listruct node is empty...\n");
        return 0;
    } else
        return 1;
}
    //deleting all the nodes in the list...

int delete_all(struct node **hd_ptr) {
    struct node *temp = NULL;
    if(!check_list(*hd_ptr))
        return 0;
    while(*hd_ptr != NULL) {
        temp = *hd_ptr;
        *hd_ptr = (*hd_ptr) -> nxt;
        free(temp);
    }
}
    // delete a particular node in the list

int _delete(struct node **hd_ptr,int value) {
    struct node *temp = *hd_ptr, *prev;
    if(!check_list(*hd_ptr))
        return 0;
    while(temp) {
        if(temp->value==value) {
            if(temp == *hd_ptr)
                *hd_ptr = (*hd_ptr) -> nxt;
            else
                prev->nxt = temp->nxt;
            free(temp);
            return 0;
        } else {
            prev = temp;
            temp = temp->nxt;
        }
    }
    printf("the given value is not present in the list...\n");
}

    //to print the nodes in the list

int print(struct node *hd_ptr) {
    if(!check_list(hd_ptr))
        return 0;
    while(hd_ptr != NULL) {
        printf("%d -> ",hd_ptr->value);
        hd_ptr = hd_ptr->nxt;
    }
    printf("\n");
}
    // to print the node in the reverse order...

void reverse_print(struct node *hd_ptr) {
    if(hd_ptr) {
        reverse_print(hd_ptr->nxt);
        printf("%d -> ",hd_ptr->value);
    }
}
    // the reverse the data of the nodes in the list
/*
void reverse_data(struct node *hd_ptr,int Count) {
    struct node temp1;
    struct node **temp = (struct node **)malloc(Count * sizeof(struct node *));
    int i,siz = sizeof(struct node) - sizeof(struct node *);
    for(i=0;i<Count;i++) {
        temp[i] = hd_ptr;
        hd_ptr = hd_ptr->nxt;
    }
    for(i=0;i<Count/2;i++) {
        memcpy(&temp1,temp[i],siz);
        memcpy(temp[i],temp[Count-i-1],siz);
        memcpy(temp[Count-i-1],&temp1,siz);
    }
}
*/
    // to reverse the data of the nodes in the list without array

void reverse_data(struct node *hd_ptr,int Count) {
    struct node *ptr1 = hd_ptr,*ptr2,temp;
    int i,j,siz = sizeof(struct node) - sizeof(struct node *);
    for(i=0;i<Count/2;i++) {
        ptr2 = hd_ptr;
        for(j=0;j<Count-i-1;j++)
            ptr2 = ptr2->nxt;
        memmove(&temp,ptr1,siz);
        memmove(ptr1,ptr2,siz);
        memmove(ptr2,&temp,siz);
        ptr1 = ptr1->nxt;
    }
}
    // to reverse the link...

/*void reverse_link(struct node **hd_ptr,int Count) {
    struct node **str_arr = (struct node **)malloc(Count * sizeof(struct node *)),*temp1 = *hd_ptr;
    int i;
    for(i=0;i<Count;i++) {
        str_arr[i]=temp1;
        temp1 = temp1->nxt;
    }
    str_arr[0]->nxt=NULL;
    for(i=1;i<Count;i++)
        str_arr[i]->nxt = str_arr[i-1];
    *hd_ptr = str_arr[i-1];
}*/
    // reverse link without array

void reverse_link(struct node **hd_ptr,int Count) {
    struct node *prv,*cur = NULL;
    while(*hd_ptr != NULL) {
        prv = cur;
        cur = *hd_ptr;
        *hd_ptr =(*hd_ptr)->nxt;
        cur->nxt = prv;
    }
    *hd_ptr = cur;
}
    // to find the length of the list...

int count(struct node *hd_ptr)
{
    int count =0;
    while(hd_ptr != NULL) {
        ++count;
        hd_ptr = hd_ptr->nxt;
    }
    return count;
}
int main()
{
    struct node *hptr = NULL;
    int value;
    char opt;
    do {
        //add_begin(&hptr);
        add_end(&hptr);
        printf("Do you want to add another node details: y/n\n");
        scanf(" %c",&opt);
    } while((opt=='y')||(opt=='Y'));
    print(hptr);
    /*
    add_middle(&hptr);
    print(hptr);
    delete_all(&hptr);
    print(hptr);
    */
    printf("Enter the value to be delete: ");
    scanf("%d",&value);
    _delete(&hptr,value);
    print(hptr);
    printf("Reverse print: ");
    reverse_print(hptr);
    printf("\n");
    printf("Reverse data: ");
    reverse_data(hptr,count(hptr));
    print(hptr);
    printf("Reverse link: ");
    reverse_link(&hptr,count(hptr));
    print(hptr);
}
