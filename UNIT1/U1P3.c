int main()
{
    int A[3], B[3], C[3], i;

    printf("enter A:");
    for(i=0;i<3;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("enter B:");
    for(i=0;i<3;i++)
    {
        scanf("%d",&B[i]);
    }
    for(i=0;i<3;i++)

        C[i]=A[i]+B[i];
    printf("C=");
    for(i=0;i<3;i++)
        printf("%d",C[i]);
    return 0;
}
