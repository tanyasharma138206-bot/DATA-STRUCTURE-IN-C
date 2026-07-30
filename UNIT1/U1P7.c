#include<stdio.h>
int main()
{
    int a[100],n,i,pos,value;
    printf("enter the elements:");

    scanf("%d",&n);
    printf("enter the elements:\n");

    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("enter the position to insert(1 to %d):",n+1);

    scanf("%d",&pos);
    printf("enter the elements to insert:");

    scanf("%d",&value);

    if(pos<1||pos>n+1)
    {
        printf("position not found");
    }
    else
    {
        for(i=n;i>=pos;i--)
        a[i]=a[i-1];

        a[pos-1]=value;
        n++;
    }
    printf("array after insertion:\n");
    for(i=0;i<n;i++)
        printf("%d",a[i]);

    return 0;
}
