#include <stdio.h>
#include <stdlib.h>
//Create a single linked list and display all even numbers from that.
void create();
void show();

struct student
{
    int rollNo;
    struct student *next;
};

struct student *start = NULL, *node, *temp;

int main(void)
{
    create();
    show();
    return 0;
}

void create()
{
    char choice;
    do
    {
        node = (struct student *)malloc(sizeof(struct student));
        printf("\nEnter the Roll No: ");
        scanf("%d", &node->rollNo);
        node->next = NULL;
        if (start == NULL)
        {
            temp = node;
            start = node;
        }
        else
        {
            temp->next = node;
            temp = temp->next; // or temp = node; => So, that node and temp point the same location.
        }
        printf("Do You Want To Continue Y or N: ");
        fflush(stdin); //Use before scanf() => clear garbage value
        scanf("%c", &choice);
    } while (choice == 'Y' || choice == 'y');
}

void show()
{
    printf("\nInput Detail In Terms Of Even Roll No Number:\n");
    for (temp = start; temp != NULL; temp = temp->next)
    {
      if(temp->rollNo % 2 == 0)
      {
        printf("Roll No: %d\n", temp->rollNo);
      }
    }
    printf("\n\n");
}
