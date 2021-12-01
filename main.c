#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node * prev;
    int data;
    struct Node * next;
};

struct Node * create_ll(struct Node *start)
{
    struct Node *new_node,*ptr;
    int data;
    printf("\nEnter -1 to end");
    printf("\nEnter Data ");
    scanf("%d",&data);
    while(data!=-1)
    {
        if(start==NULL)
        {
            new_node=(struct Node *)malloc(sizeof(struct Node));
            new_node->data=data;
            new_node->prev=NULL;
            new_node->next=NULL;
            start=new_node;
        }
        else
        {
            ptr=start;
            new_node=(struct Node *)malloc(sizeof(struct Node));
            new_node->data=data;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=new_node;
            new_node->prev=ptr;
            new_node->next=NULL;
        }
        printf("\nEnter Data ");
        scanf("%d",&data);
    }
    return start;
};
struct Node * insert_beg(struct Node * start)
{
    struct Node * new_node;
    int data;
    new_node=(struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter Data ");
    scanf("%d",&data);
    start->prev=new_node;
    new_node->prev=NULL;
    new_node->data=data;
    new_node->next=start;
    start=new_node;
    return start;
};
struct Node * insert_end(struct Node * start)
{
    struct Node * new_node,*ptr;
    int data;
    new_node=(struct Node *)malloc(sizeof(struct Node));
    ptr=start;
    printf("\nEnter Data ");
    scanf("%d",&data);
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=new_node;
    new_node->prev=ptr;
    new_node->data=data;
    new_node->next=NULL;
    return start;
};
struct Node * insert_after(struct Node * start)
{
    struct Node * new_node,*ptr,*p;
    int data,value;
    new_node=(struct Node *)malloc(sizeof(struct Node));
    ptr=start;
    if(ptr==NULL)
    {
        printf("Frist Create List");
    }
    else
    {
        printf("\nEnter Value ");
        scanf("%d",&value);
        printf("\nEnter Data ");
        scanf("%d",&data);
        while(ptr->data!=value)
        {
            ptr=ptr->next;
        }
        p=ptr->next;
        ptr->next=new_node;
        new_node->prev=ptr;
        new_node->data=data;
        new_node->next=p;
        if(p!=NULL)
            p->prev=new_node;
    }
    return start;
};
struct Node * insert_before(struct Node * start)
{
    struct Node * new_node,*ptr,*p;
    int data,value;
    new_node=(struct Node *)malloc(sizeof(struct Node));
    ptr=start;
    if(ptr==NULL)
    {
        printf("\nFrist Create List");
    }
    else
    {
        printf("\nEnter Value ");
        scanf("%d",&value);
        printf("\nEnter Data ");
        scanf("%d",&data);
        while(ptr->data!=value)
        {
            ptr=ptr->next;
        }
        p=ptr->prev;
        ptr->prev=new_node;
        new_node->data=data;
        new_node->prev=p;
        new_node->next=ptr;
        if(p!=NULL)
            p->next=new_node;
        if(p==NULL)
            start=new_node;
    }
    return start;
};
struct Node * delete_beg(struct Node * start)
{
    struct Node * ptr;
    ptr=start;
    start=start->next;
    if(start!=NULL)
        start->prev=NULL;
    free(ptr);
    return start;
};
struct Node * delete_end(struct Node * start)
{
    struct Node *ptr;
    ptr=start;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    if(ptr->prev!=NULL)
        ptr->prev->next=NULL;
    free(ptr);
    return start;
};
struct Node * delete_value(struct Node * start)
{
    struct Node * ptr,*p;
    int value;
    printf("\nEnter Value");
    scanf("%d",&value);
    ptr=start;
    while(ptr->data!=value)
    {
        ptr=ptr->next;
    }
    p=ptr->next;
    if(ptr->prev!=NULL)
        ptr->prev->next=ptr->next;
    else
        start=NULL;
    if(ptr->next!=NULL)
        ptr->next->prev=ptr->prev;
    free(ptr);
    return start;

};
void display(struct Node *start)
{
    struct Node *ptr=start;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
int main()
{
    struct Node *start=NULL;
    int option;
    do{
        printf("\n1 for display");
        printf("\n2 for create List");
        printf("\n3 for insert frist");
        printf("\n4 for insert end");
        printf("\n5 for insert after value");
        printf("\n6 for insert before value");
        printf("\n7 for delete begen");
        printf("\n8 for delete end");
        printf("\n9 for delete value");
        printf("\n11 for exit\n");
        scanf("%d",&option);
        if(option==1)
        {
            display(start);
        }
        else if(option==2)
        {
            start=create_ll(start);
        }
        else if(option==3)
        {
            start=insert_beg(start);
        }
        else if(option==4)
        {
            start=insert_end(start);
        }
        else if(option==5)
        {
            start=insert_after(start);
        }
        else if(option==6)
        {
            start=insert_before(start);
        }
        else if(option==7)
        {
            start=delete_beg(start);
        }
        else if(option==8)
        {
            start=delete_end(start);
        }
        else if(option==9)
        {
            start=delete_value(start);
        }
        else if(option==11)
        {
            break;
        }
        else
        {
            printf("\n wrong option");
        }
    }while(option!=11);
    return 0;
}
