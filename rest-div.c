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

void add(int n1[], int n2[], int n, int ans[])
{
    int i, cy; //carry denoted by cy
    i = n-1;
    cy = 0;
    while(i>=0)
    {
        if(cy + n1[i] + n2[i] == 3)
        {
            //case: 1+1+1 = 1 w/ carry of 1
            cy = 1;
            ans[i] = 1;
        }
        else if(cy + n1[i] + n2[i] == 2)
        {
            //case: 1+1+0 = 0 w/ carry of 1
            cy = 1;
            ans[i] = 0;
        }
        else if(cy + n1[i] + n2[i] == 1)
        {
            //case: 1+0+0 = 1
            cy = 0;
            ans[i] = 1;
        }
        else
        {
            cy = 0;
            ans[i] = 0;
        }
        //Decrementing the value of i
        i--;
    }
}
//Addition function


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

//Function to take 2s complement of given binary number of  'n' bits
void twosComplement(int number[], int n1[], int n)
{
    //number->given binary num
    //n1->array in which 2s C will be stored
    //n->number of digits
    //cy -> carry
    int cy= 0;
    int i=0;
    while(i<n)
    {
        if(number[i]==0)
            n1[i]=1;
        else if(number[i]==1)
            n1[i]=0;
        i++;
    }
    //We always add 1 after taking the one's complement
    int a = n1[n-1];
    int b = 1;
    //checking if carry is generated
    cy = a + b - 1;
    if(a + b ==2)
        n1[n-1] = 0;
    else
        n1[n-1] = 1;
    //Now traversing the rest of the number and generating / adding the carry appropriately
    i = n-2;
    while(i>0)
    {
        if(cy + n1[i] == 2)
        {
            //carry generated again
            cy = 1;
            n1[i] = 0; 
            //1 + 1 = 0 w/ a carry of 1
        }
        else if(cy + n1[i] == 1)
        {
            //1 + 0 = 1
            //No carry 
            cy = 0;
            n1[i] = 1; 
        }
        else if(cy + n1[i] == 0)
        {
            cy = 0;
            n1[i] = 0;
        }
        //Decremeting the Value of i
        i--;
    } 
}

int left(int acc[], int q[], int digits)

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

void printall(int AQ[], int s)
{
    //s here is size of the binary no.s
    int i=0;
    //Printing an array i.e. A
    printf("\nA\t\tQ\n");
    while(i<s)
    {
        printf("%d", AQ[i]);
        i++;
    }
    printf("\t\t");
    i = s;
    //Printing Q
    while(i< 2*s) 
    {
        printf("%d", AQ[i]);
        i++;
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
    int m2[digits];
    int AQ[2*digits];
    updateAQ(AQ, A, Q, digits);
    printall(AQ, digits);
    twosComplement(M, m2, digits);
    int n = digits;
    printf("\tStart\n");
    while (n > 0)
    {
        left(acc, q, digits);
        printf("Left Shift A,Q\n");
        updateAQ(AQ, A, Q, digits);
        printall(AQ, digits);
        add(A, m2, digits, A);
        printf("A=A-M\n");
        if (A[digits] == 0)
        {
            Q[0] = 1;
            updateAQ(AQ, A, Q, digits);
            printall(AQ, digits);
        }
        else
        {
            Q[0] = 0;
            add(A, M, digits, A);
            printf("Qo=0; A=A+M\n");
            updateAQ(AQ, A, Q, digits);
            printall(AQ, digits);
        }
        n--;
    }
    printf("\nQuotient = ");
    printarr(Q, digits);
    printf("\nRemainder = ");
    printarr(A, digits);
    return 0;
}



