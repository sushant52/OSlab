// C program to fin XOR of two numbers
// By converting them to binary
// Input taken through command line argument
// SUSHANT SINHA
// 1901CS62

// Including necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
char *strrev(char *str)
{
    if (!str || ! *str)
        return str;

    int i = strlen(str) - 1, j = 0;

    char ch;
    while (i > j)
    {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    }
    return str;
}

// function to calculate xor of two numbers
void xor(long long int a, long long int b){
    long long ia = a, ib = b, ans = 0, twopower = 1;
    char binary_a[100]="";
    char binary_b[100]="";
    char binary_ans[100]="";

    // Finding XOR by repeated division by 2
    while(ia != 0 || ib != 0){
        //  Finding the XOR using xor_bit = (a_bit + b_bit)%2
        if(ia%2)
            strcat(binary_a,"1");
        else
            strcat(binary_a,"0");
        
        if(ib%2)
            strcat(binary_b,"1");
        else
            strcat(binary_b,"0");

        long long xor_bit = (ia % 2 + ib % 2) %2;
        if(xor_bit)
            strcat(binary_ans,"1");
        else
            strcat(binary_ans,"0");
        ans += twopower*xor_bit;
        twopower *= 2;
        ia /= 2;
        ib /= 2;
    }
    // Output
    printf("Decimal: XOR of %lld and %lld: %lld\n",a,b,ans);
    printf("Binary: XOR of %s and %s: %s\n",strrev(binary_a),strrev(binary_b),strrev(binary_ans));
}

// main function with command line arguments
int main(int argc, char* argv[]){
    if(argc!=3){
        printf("Required number of arguments is two\n");
    }
    else
        xor(atoll(argv[1]),atoll(argv[2])); // Function call to find xor
    return 0;
}