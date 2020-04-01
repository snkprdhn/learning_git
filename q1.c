//Sonit Kumar Pradhan
//PES2UG19CS399

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node* next;
};


struct node* getnode(int data)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}



void display(struct node* temp)
{
    printf("\n\n");
    printf("Current linked_list: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n\n");
}



void insert(int data,struct node** temp)
{
    struct node* head=*temp;
    if(*temp==NULL)
    {
        *temp=getnode(data);
    }
    else
    {
        while((*temp)->next!=NULL)
        {
            *temp=(*temp)->next;
        }
        struct node* ptr=getnode(data);
        (*temp)->next=ptr;
        *temp=head;
    }
}



void insert_end(int data,struct node** temp)
{
    struct node* head=*temp;
    if(*temp==NULL)
    {
        *temp=getnode(data);
    }
    else
    {
        while((*temp)->next!=NULL)
        {
            *temp=(*temp)->next;
        }
        struct node* ptr=getnode(data);
        (*temp)->next=ptr;
        *temp=head;
        display(*temp);
    }
}



void insert_front(int data,struct node** temp)
{
    if(*temp==NULL)
    {
        *temp=getnode(data);
    }
    else
    {
        struct node* ptr=getnode(data);
        ptr->next=*temp;
        *temp=ptr;
    }
    display(*temp);
}



void sum_alternate(struct node* temp)
{
    int sum=0,i=0;
    while(temp!=NULL)
    {
        if(i%2==0)
        {
            sum=sum+temp->data;
        }
        temp=temp->next;
        i++;
    }
    printf("\n\nsum of alternate nodes = %d\n\n",sum);
}



void sum(struct node* temp)
{
    int sum=0;
    while(temp!=NULL)
    {
        sum=sum+temp->data;
        temp=temp->next;
    }
    printf("\n\nsum of all the elements in the linked_list = %d\n\n",sum);
}



void sum_even_odd(struct node* temp)
{
    int sum_even=0,sum_odd=0,i=0;
    while(temp!=NULL)
    {
        if(i%2!=0)
        {
            sum_even=sum_even+temp->data;
        }
        else
        {
            sum_odd=sum_odd+temp->data;
        }
        temp=temp->next;
        i++;
    }
    printf("\n\nsum of even nodes = %d\n",sum_even);
    printf("sum of odd nodes = %d\n\n",sum_odd);
}



void delete_front(struct node** temp)
{
    struct node* head=*temp;
    *temp=(*temp)->next;
    free(head);
    display(*temp);
}



void delete_end(struct node** temp)
{
    struct node* head=*temp;
    while(((*temp)->next)->next!=NULL)
    {
        *temp=(*temp)->next;
    }
    struct node* ptr=(*temp)->next;
    free(ptr);
    (*temp)->next=NULL;
    *temp=head;
    display(*temp);
}



void search(int data,struct node* temp)
{
    int loc=1;
    while((temp->data!=data))//while((temp->data!=data)&&(temp!=NULL))=====> This doesn't work idk why
    {
        loc++;
        temp=temp->next;
        if(temp==NULL)
        {
            break;
        }
    }
    if(temp!=NULL)
    {
        printf("\n\n%d found at node # %d\n\n",data,loc);
    }
    else
    {
        printf("\n\n%d is not present in the linked_list\n\n",data);
    }
}



void pro_div(int data,struct node* temp)
{
    int mul=1,flag=0;
    while(temp!=NULL)
    {
        if(((temp->data)%data)==0)
        {
            mul=mul*(temp->data);
            flag=1;
        }

        temp=temp->next;
    }
    if(flag!=0)
    {
        printf("\n\nProduct of nodes of the linked_list which are divisible by %d = %d\n\n",data,mul);
    }
    else
    {
        printf("\n\nNone of the nodes of the linked_list are divisible by %d\n\n",data);
    }
}



void add_after(int value,int data,struct node** temp)
{
    struct node* head=*temp;
    while((*temp)->data!=value)
    {
        *temp=(*temp)->next;
    }
    struct node* ptr=getnode(data);
    ptr->next=(*temp)->next;
    (*temp)->next=ptr;
    *temp=head;
    display(*temp);
}



void add_before(int value,int data,struct node** temp)
{
    struct node* head=*temp;
    if((*temp)->data==value)
    {
        insert_front(data,temp);
        return;
    }
    while(((*temp)->next)->data!=value)
    {
        *temp=(*temp)->next;
    }
    struct node* ptr=getnode(data);
    ptr->next=(*temp)->next;
    (*temp)->next=ptr;
    *temp=head;
    display(*temp);
}



void add_loc(int loc,int data,struct node** temp)
{
    struct node* head=*temp;
    if(loc==1)
    {
        insert_front(data,temp);
        return;
    }
    for(int i=1;i<(loc-1);i++)
    {
        *temp=(*temp)->next;
    }
    struct node* ptr=getnode(data);
    ptr->next=(*temp)->next;
    (*temp)->next=ptr;
    *temp=head;
    display(*temp);
}



void delete_loc(int loc,struct node** temp)
{
    struct node* head=*temp;
    if(loc==1)
    {
        *temp=(*temp)->next;
        return;
    }
    for(int i=1;i<(loc-1);i++)
    {
        *temp=(*temp)->next;
    }
    (*temp)->next=((*temp)->next)->next;
    *temp=head;
    display(*temp);
}



void delete_value(int value,struct node** temp)
{
    struct node* head=*temp;
    if((*temp)->data==value)
    {
        *temp=(*temp)->next;
        return;
    }
    while(((*temp)->next)->data!=value)
    {
        *temp=(*temp)->next;
    }
    (*temp)->next=((*temp)->next)->next;
    *temp=head;
    display(*temp);
}



void get_n(int loc,struct node* temp)
{
    for(int i=1;i<loc;i++)
    {
        temp=temp->next;
    }
    printf("value at node # %d = %d\n\n",loc,temp->data);
}






void main()
{
    int value,len,n,num,loc;
   // bool exit=true;

    struct node* head=NULL;

    printf("Enter the # of nodes to be inserted in the linked_list: ");
    scanf("%d",&len);

    for(int i=1;i<len;i++)
    {
        printf("\nEnter the data for node #%d: ",i);
        scanf("%d",&value);

        insert(value,&head);
    }

    printf("\nEnter the data for node #%d: ",len);
    scanf("%d",&value);
    insert_end(value,&head);

    printf("\n\n");

    while(true)
    {
        printf("1.Display the linked_list.\n");
        printf("2.Insert a node at the front.\n");
        printf("3.Insert a node at the end.\n");
        printf("4.Sum of alternate node elements.\n");
        printf("5.Sum of all the elements in the linked_list.\n");
        printf("6.Sum of even and odd nodes of the linked_list.\n");
        printf("7.Delete a node from the front.\n");
        printf("8.Delete a node from the end.\n");
        printf("9.Search an element.\n");
        printf("10.Product of nodes of the linked_list which are divisible by a given #.\n");
        printf("11.Add a node after the node containing a specific #.\n");
        printf("12.Add a node before the node containing a specific #.\n");
        printf("13.Add a node at a specific location.\n");
        printf("14.Delete the node at a specific location.\n");
        printf("15.Delete the node which contains a specific #.\n");
        printf("16.Find the nth node.\n");
        printf("17.Exit.\n");
        printf("\n===========================================================================\n");

        printf("Enter your choice: ");
        scanf("%d",&n);

        if(n==17)
        {
            exit(0);
        }

        switch(n)
        {
        case 1:
            display(head);
            break;

        case 2:
            printf("\nEnter the # that you want to insert at the front: ");
            scanf("%d",&num);
            insert_front(num,&head);
            break;

        case 3:
            printf("\nEnter the # that you want to insert at the end: ");
            scanf("%d",&num);
            insert_end(num,&head);
            break;

        case 4:
            sum_alternate(head);
            break;

        case 5:
            sum(head);
            break;

        case 6:
            sum_even_odd(head);
            break;

        case 7:
            delete_front(&head);
            break;

        case 8:
            delete_end(&head);
            break;

        case 9:
            printf("\nEnter the # that you want to search: ");
            scanf("%d",&num);
            search(num,head);
            break;

        case 10:
            printf("\nEnter the #: ");
            scanf("%d",&num);
            pro_div(num,head);
            break;

        case 11:
            printf("\nEnter the value after which you want to add the new node: ");
            scanf("%d",&num);
            printf("\nEnter the value that you want to add: ");
            scanf("%d",&value);
            add_after(num,value,&head);
            break;

        case 12:
            printf("\nEnter the value before which you want to add the new node: ");
            scanf("%d",&num);
            printf("\nEnter the value that you want to add: ");
            scanf("%d",&value);
            add_before(num,value,&head);
            break;

        case 13:
            printf("\nEnter the location where you want to add a new node: ");
            scanf("%d",&loc);
            printf("\nEnter the value that you want to add: ");
            scanf("%d",&value);
            add_loc(loc,value,&head);
            break;

        case 14:
            printf("\nEnter the location of the node that you want to delete: ");
            scanf("%d",&loc);
            delete_loc(loc,&head);
            break;

        case 15:
            printf("\nEnter the value of the node that you want to delete: ");
            scanf("%d",&value);
            delete_value(value,&head);
            break;

        case 16:
            printf("\nEnter # of the node whose value you want to find: ");
            scanf("%d",&loc);
            get_n(loc,head);
            break;
        }
    }
}
