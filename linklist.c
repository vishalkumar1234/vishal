#include<stdio.h>
void insert_begin();
void insert_rear();
void insert_position();
void delete_begin();
void delete_rear();
void delete_position();
void create_node();
void display();
typedef struct linklist
{
   int data;
    struct linklist *link;
} node;
node *front,*rear;

void insert_begin()
{
  node *temp;
   if(front==NULL || rear==NULL)

       create_node();
    else
      {
         temp=(node*)malloc(sizeof(node));
         printf("enter item:");
         scanf("%d",&temp->data);

            temp->link=front;
            front=temp;
      }

}
void create_node()
{
    node*temp;int item;
    temp=(node*)malloc(sizeof(node));
    printf("enter item:");
    scanf("%d",&item);

     temp->data=item;
     temp->link=NULL;
     front=temp;
      rear=temp;
   return;


}
void insert_rear()
{
   node* temp;
   if(front==NULL||rear==NULL)
   create_node();

   else
   {
     temp=(node*)malloc(sizeof(node)) ;
     printf("enter item:");
     scanf("%d",&temp->data);
     rear->link=temp;
     temp->link=NULL;
      rear=temp;
      return;
   }

}

void insert_position()
{

   int position,i;
  node *temp,*temp1;

    if(front==NULL || rear==NULL)

       create_node();
    else
       {
           temp=(node*)malloc(sizeof(node));
           printf("enter item:");
           scanf("%d",&temp->data);

           printf("enter position");
           scanf("%d",&position);

        temp1=front;

       for(i=1;i<position-1;i++)
        temp1=temp1->link;
        temp->link=temp1->link;
         temp1->link=temp;



       }
          return;
}


void delete_begin()
{
   node *temp;
    if(front==NULL)
    {
      printf("linklist is  empty");
    }
     else
      {
          temp=front;
           front=front->link;
            temp->link=NULL;
         printf("deleted item is %d");
          free(temp);


      }



}

void delete_rear()
{

  node *temp;
  if(front==NULL)
   {
      printf("empty linklist");
   }

  else
   {
     temp=front;

      while(temp->link!=rear)
       {
         temp=temp->link;
       }

      temp->link=NULL;

      printf("deleted item is %d",rear->data);

      free(rear);

      rear=temp;

   }
    return;
}

void delete_position()
{
    node *temp,*temp1;
    int position,i;

   if(front==NULL)

    {
       printf("empty list");
    }

   else
    {
      printf("enter position:");
      scanf("%d",&position);

      temp=front;

     for(i=1;i<position-1;i++)


       {
         temp=temp->link;
         temp1=temp->link;
         temp->link=temp1->link;

        printf("deleted item is %d",temp1->data);

          free(temp1);


       }



    }
      return;
}

void display()
 {

   node* temp;
   temp=front;

   printf("\n===============================================================================================\n");
   while(temp->link!=NULL)
     {
         printf("|%p %d %p|",temp,temp->data,temp->link);
          temp=temp->link;

     }

     printf("|%p %d %p|",temp,temp->data,&temp->link);
    printf("\n==============================================================================================\n");
          return;
}
main()
{
        int ch;
        for(; ;)

            {
              printf("\noptions are:");
              printf("\n1.insert at begin");
              printf("\n2.insert at rear");
              printf("\n3.insert position");
              printf("\n4.delete begin");
              printf("\n5.delete rear");
              printf("\n6.delete position");
              printf("\n0.exit");

             printf("\nenter your choice");
             scanf("%d",&ch);

         switch(ch)
           {
             case 1:
             insert_begin();
             display();
             break;

             case 2:
              insert_rear();
              display();
              break;

              case 3:
              insert_position();
              display();
               break;

              case 4:
               delete_begin();
                display();
                  break;

             case 5:
               delete_rear();
               display();
                break;

             case 6:
              delete_position();
              display();
               break;

              case 0:
                 exit(0);
                 break;

                  default:
                printf("invalid option");
           }

        }

}
