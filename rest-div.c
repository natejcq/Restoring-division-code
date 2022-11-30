#include <stdio.h>
#include<stdlib.h>
#include<math.h>

int dec_bin(int d, int m[], int digits)
{
    int b=0, i=0;
    while(d>0)
    {
        m[i]=d%2;
        printf("%d", d%2);
        d=d/2;
        i++;
    }
    printf(" i is %d\n", i);
    while(i<digits)
    {
        m[i] = 0;
        i++;
    }
    return 0;
}

void reverse_arr(int arr[], int digits)
{
    int temp;
    for(int i = 0; i<digits/2; i++)
    {   
        temp = arr[i];
        arr[i] = arr[digits-i-1];
        arr[digits-i-1] = temp;
    }
}

int main()
{
    int a,b;
    printf("Enter Dividend:");
    scanf("%d", &a);
    printf("Enter the Divisor:");
    scanf("%d", &b);
    //Finding greater number
    int maximum = abs(a)>abs(b) ? abs(a) : abs(b);
    //Finding number of digits
    int digits = (log(maximum)/log(2)) + 1;
    printf("digits is %d \n", digits);
}
   
