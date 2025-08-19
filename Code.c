#include <stdio.h>
#include <stdlib.h>
//commiting changes
typedef struct todo{
    char task[100];
    struct todo *link;
}s;
s *head=NULL;
s *comphead=NULL;
void addtask()
{
    s *newtask,*trpt;
    newtask=(s*)malloc(1*sizeof(s));
    printf("\nADDING TASK");
    printf("\nEnter the task:");
    scanf(" %[^\n]",newtask->task);
    if(head==NULL)
    {
        head=newtask;
        newtask->link=NULL;
    }
    else
    {
        trpt=head;
        while(trpt->link!=NULL)
        {
            trpt=trpt->link;
        }
        trpt->link=newtask;
    }
    printf("\nTask added");
    
}
void add_task_at_position()
{
    printf("Enter task:");
    s *newtask,*trpt;
    newtask=(s*)malloc(1*sizeof(s));
    scanf(" %[^\n]",newtask->task);
    printf("enter position for the task:");
    int pos;
    scanf("%d",&pos);
    trpt=head;
    if(pos==1)
    {
        newtask->link=head;
        head=newtask;
    }
    else{
    while(pos-2)
    {
        trpt=trpt->link;
        pos--;
    }
    newtask->link=trpt->link;
    trpt->link=newtask;
    }
    
}
void delete_task()
{
    s *trpt,*trpt2;
    printf("enter task number to delete:");
    int n;
    scanf("%d",&n);
    int pos=n;
    trpt=head;
    if(pos==1)
    {
        head=trpt->link;
        free(trpt);
    }
    else{
    while(pos-2!=0)
    {
        trpt=trpt->link;
        pos--;
    }
    }
    trpt2=trpt->link;
    trpt->link=trpt->link->link;
    free(trpt2);
}
void checktask()
{
    printf("Enter task number to mark it completed:");
    int pos;
    scanf("%d",&pos);
    s *trpt,*trpt2,*trpt3;
    trpt=head;
    if(pos==1)
    {
        trpt2=head;
        head=trpt->link;
    }
    else{
    while(pos-2!=0)
    {
        trpt=trpt->link;
        pos--;
    }
    trpt2=trpt->link;
    trpt->link=trpt->link->link;
    }
    trpt3=comphead;
    if(comphead==NULL)
    {
        comphead=trpt2;
        trpt2->link=NULL;
    }
    else{
        while(trpt3->link!=NULL)
        {
            trpt3=trpt3->link;
        }
        trpt3->link=trpt2;
    }
    
    
}
void display_incomp_tasks()
{
    s *trpt;
    int i=1;
    if(head==NULL)
    {
        printf("\n*****NO TASKS ADDED YET::ADD TASKS*****");
        return;
    }
    trpt=head;
    while(trpt->link != NULL)
    {
        printf("\n%d.%s",i,trpt->task);
        i++;
        trpt=trpt->link;
    }
    printf("\n%d.%s",i,trpt->task);
}
void display_comp_tasks()
{
    s *trpt;
    int i=1;
    trpt=comphead;
    if(comphead==NULL)
    {
        printf("\n*****NO TASKS FINISHED YET*****");
        return;
    }
    while(trpt->link != NULL)
    {
        printf("\n%d.%s",i,trpt->task);
        i++;
        trpt=trpt->link;
    }
    printf("\n%d.%s",i,trpt->task);
}
int main()
{
    int a=1,b=1,c=1;
    printf("\t\t\t\t:::::::::::::::::::::::TO-DO LIST:::::::::::::::::::::::\t\t\t\t");
    int n=1;
    printf("\n======================\nTasks management\n======================\n");
    printf("Enter:\n1:To add tasks\n2:To display tasks\n3:To mark completion\n4:To add task at a priority\n5:To remove a task");
    while(n!=0)
    {
        printf("\n------------------\nEnter your choice:");
        scanf("%d",&n);
        switch(n)
        {
            case 1: addtask();
            break;
            case 2: printf("\nEnter:\n1:For incomplete tasks\n2:For finished tasks");
            scanf("%d",&a);
            switch(a){
                case 1: display_incomp_tasks();break;
                case 2: display_comp_tasks();break;
                default: printf("Enter a valid choice");
            }
            break;
            case 3:checktask();
            break;
            case 4:add_task_at_position();
            break;
            case 5:
            delete_task();
            printf("Task removed");break;
            case 0: printf("APPLICATION TERMINATED");break;
            default: printf("Enter a valid choice");break;
        }
    }
    
    
    
    return 0;
}

