#include <stdio.h>

/* Global variables declaration */
int a[10], n, elem, i, pos; // predefining array size to be a maximum of 10

/* Function Prototypes */
void create(); 
void display(); 
void insert(); 
void del();

void create() // creating an array
{
    printf("\nEnter the size of the array elements <= 9: ");
    scanf("%d", &n);
    printf("\nEnter the elements for the array:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
} // end of create()

void display() // displaying array elements
{
    printf("\nThe array elements are:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
} // end of display()

void insert() // inserting an element into an array
{
    printf("\nEnter the position for the new element: ");
    scanf("%d", &pos);
    printf("\nEnter the element to be inserted: ");
    scanf("%d", &elem);
    pos = pos - 1;

    for(i = n - 1; i >= pos; i--)
    {
        a[i + 1] = a[i];
    }
    a[pos] = elem;
    n = n + 1;
}

void del() 
{
    printf("\nEnter the position of the element to be deleted: ");
    scanf("%d", &pos);
    pos = pos - 1;
    elem = a[pos];

    for(i = pos; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    n = n - 1;
    printf("\nThe deleted element is %d\n", elem);
} // end of delete()

int main()
{
    int ch;
    create();
    display();

    printf("\n\n--------Menu----------\n");
    printf("1. Insert\n2. Delete\n3. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: 
                insert();
                display();
                break;
            case 2: 
                del();
                display();
                break;
            case 3: 
                return 0;
            default: 
                printf("\nInvalid choice\n");
                break;
        }
    }
} // end of main