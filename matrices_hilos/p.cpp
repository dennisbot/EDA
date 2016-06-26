#include <bits/stdc++.h>

void arraytest(int a[])
{
    // changed the array a
    a[0]=a[0]+a[1];
    a[1]=a[0]-a[1];
    a[0]=a[0]-a[1];
}
void arraytest1(int a[2])
{
    puts("way 1");
    // changed the array a
    a[0]=a[0]+a[1];
    a[1]=a[0]-a[1];
    a[0]=a[0]-a[1];
}
void arraytest2(int* a)
{
    puts("way 2");
    // changed the array a
    a[0]=a[0]+a[1];
    a[1]=a[0]-a[1];
    a[0]=a[0]-a[1];
}


int main()
{
    int arr[]={1,2};
    printf("%d \t %d\n",arr[0],arr[1]);
    arraytest(arr);
    // arraytest1(arr);
    arraytest2(arr);
    printf("\n After calling fun arr contains: %d\t %d",arr[0],arr[1]);
    return 0;
}