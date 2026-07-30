#include<stdio.h>
#include<string.h>
struct student
{
    int rollno;
    char name[50];
};
void main()
{
    struct student s1;

    printf("\n Enter Roll Number:");
    scanf("%d",&s1.rollno);

    printf("\n Enter Name:");
    scanf("%s",s1.name);

    printf("\n Student Data is as follows");
    printf("\n******");

    printf("\n Roll Number is:%d",s1.rollno);
    printf("\n Name is:%s",s1.name);

    getch();
}
