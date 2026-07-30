#include<stdio.h>
#include<conio.h>

enum week{Mon,Tue,Wed,Thu,Fri,Sta,Sun};

void main()
{
    enum week w;
    w=Tue;

    printf("\n Constant value of Tue is %d",w);
    getch();
}
