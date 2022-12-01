#include <stdio.h>
#include<stdlib.h>
#include<math.h>

//Simple function to print array
void printarr(int array[], int size)
{
    for(int i=0; i<size;i++)
    {
        printf("%d", array[i]);
    }
}
void updateAQ(int AQ[], int A[], int Q[], int s)
{
    int i=0;
    int j=0;
    while(i<2*s)
    {
       //Updating AQq with value of A
       if(i<s)
       {
          AQ[i] = A[i]; 
       }
       //Updating AQq with value of Q
       else
       {
          AQ[i] = Q[j];
          j++;
       }
       //Increment i 
       i++;
    }
}

int left(int acc[], int q[])

{
    int i;
    for (i = digits; i > 0; i--)
    {
          acc[i] = acc[i - 1];
    }
    acc[0] = q[digits];
    for (i = digits; i > 0; i--)
    {
        q[i]=q[i-1];
     }
} //Left shift

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
     int A[digits];
    int M[digits];
    int Q[digits];
    int x = dec_bin(abs(a), Q, digits);
    int y = dec_bin(abs(b), M, digits);
    reverse_arr(Q, digits);
    reverse_arr(M, digits);
    printf("\nQ is");
    printarr(Q, digits);
}



