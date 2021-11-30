#include <stdio.h>
#include <stdlib.h>

struct Student{
    int id;
    char Name[10];
};

struct Student ar[10];
int toq;

void PrintStudent(struct Student s);
struct Student Fill(void);

int enQueue(struct Student s);
struct Student deQueue(void);
void printScreen(void);

int main()
{
    struct Student s;
    char x;
    int ret;

    while(x != '3')
    {
        system("cls");
        printScreen();
        x=getch();
        system("cls");

        switch(x)
        {
        case '1':
            {
                s = Fill();
                ret = enQueue(s);
                if(ret==0)
                    printf("The Queue is full");
                else if(ret==1)
                    printf("The student has been added successfully");
                getch();
                break;
            }
        case '2':
            {
                s = deQueue();
                if(s.id==-1)
                    printf("there is no data for any students");
                else
                    PrintStudent(s);
                getch();
                break;
            }
        }
    }

    return 0;
}

void printScreen(void)
{
    printf("1- Enqueue\n");
    printf("2- Dequeue\n");
    printf("3- exit\n");
}

void PrintStudent(struct Student s)
{
    int i;

    printf("\n");
    printf("The student ID is: %d\n", s.id);
    printf("The student name is: %s\n", s.Name);
}

struct Student Fill(void)
{
    struct Student s;
    int i;

    printf("Please, Enter the student ID: ");
    scanf("%d", &s.id);

    printf("Please, Enter the student Name: ");
    scanf("%s", s.Name);

    printf("\n");
    return s;
}

int enQueue(struct Student s)
{
    int i, retval=0;
    if(toq<10)
    {
        for(i=toq;i>0;i--)
        {
            ar[i] = ar[i-1];
        }
        ar[0] = s;
        toq++;
        retval = 1;
    }
    return retval;
}

struct Student deQueue(void)
{
    struct Student s1;
    s1.id = -1;
    if(toq>0)
    {
        toq--;
        s1 = ar[toq];
    }
    return s1;
}
