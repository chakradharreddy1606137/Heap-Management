#include<stdio.h>
#include<string.h>
#include<math.h>

#define SIZE 10000

typedef struct BigInteger{
    int arr[SIZE];
    int size;
}BigInt;

BigInt input(){
    printf("Enter the number :");
    char s[SIZE];
    scanf("%s" , s);
    int length = strlen(s);
    BigInt k;
    int z = 0;
    for(int i = length-1 ; i>=0 ; i--){
        k.arr[z] = s[i]-'0';
        z++;
    }
    k.size = z;
    return k;
}
void printBigInt(BigInt k){
    for(int i = k.size-1 ; i>=0 ; i--){
        printf("%d" , k.arr[i]);
    }

    printf("\n");
}
BigInt convert(long long a){
    BigInt ans;
    int z = 0;
    while (a!=0)
    {
        ans.arr[z] = a%10;
        a/=10;
        z++;
    }
    ans.size = z;
    return ans;
    
}
BigInt subtract(BigInt a , BigInt b){
    BigInt ans ;
    if(a.size < b.size){
        return subtract(b , a);
    }else if(a.size==b.size){
        int i = a.size-1;
        while(i>=0 && a.arr[i]==b.arr[i]){
            i--;
        }
        if(i==-1){
            ans.arr[0]=0;
            ans.size = 1;
            return ans;
        }
        if(a.arr[i]<b.arr[i]){
            return subtract(b,a);
        }
    }
    int z = 0;
    int j = 0 ;
    for(int i = 0 ; i<b.size ; i++){
        if(a.arr[i]-b.arr[i]<0){
            a.arr[i+1]--;
            a.arr[i]+=10;
        }
        ans.arr[z] = a.arr[i]-b.arr[i];
        if(ans.arr[z]!=0){
            j = i;
        }
        z++;
    }
    
    for(int i = b.size ; i<a.size ; i++){
        if(a.arr[i]!=0){
            j = i;
        }
        if(a.arr[i]<0){
            a.arr[i+1]--;
            a.arr[i]+=10;
        }
        ans.arr[z] = a.arr[i];
        z++;
    }
    ans.size = j+1;
    return ans;
}
BigInt add(BigInt a , BigInt b){
    if(a.size<b.size){
        return add(b ,a);
    }

    BigInt ans ;
    int z = 0;
    int c = 0;
    for(int i = 0 ; i<b.size ; i++){
        int temp = a.arr[i]+b.arr[i]+c;
        ans.arr[z] = temp%10;
        c  = temp/10;
        z++;
    }
    for(int i = b.size ; i<a.size ; i++){
        int temp = a.arr[i]+c;
        ans.arr[z] = temp%10;
        c  = temp/10;
        z++;
    }
    if(c>0){
        ans.arr[z] = c;
        z++;
    }
    ans.size = z;
    return ans;
    
}

BigInt multiply(BigInt a , BigInt b){
    BigInt ans ;
    ans.size = 0;
    for(int i = 0 ; i<a.size ; i++){
        int c = 0;
        BigInt t ;
        int z = 0;
        for(int j = 0 ; j<b.size ; j++){
            int temp = a.arr[i]*b.arr[j] + c;
            t.arr[z] = temp%10;
            c=temp/10;
            z++;
        }
        if(c>0){
            t.arr[z] = c;
            z++;
        }
        t.size = z;
        BigInt pro1;
        int ind = 0;
        for(int p = 0 ; p<i ; p++){
            pro1.arr[ind] = 0;
            ind++;
        }
        for(int p = 0 ; p<t.size ; p++){
            pro1.arr[ind] = t.arr[p];
            ind++;
        }
        pro1.size = ind;
        ans = add(ans , pro1);
    }
    return ans;
}
/*
BigInt moduloFunc(BigInt a , BigInt b){
    while(a.size>=b.size){
        if(a.size==b.size){
            int i = a.size-1;
            while(i>=0 && a.arr[i]==b.arr[i]){
                i--;
            }
            if(i==-1){
                a.arr[0]=0;
                a.size = 1;
                break;
            }
            if(a.arr[i]<b.arr[i]){
                break;
            }
        }
        a = subtract(a , b);
    }
    return a;
}
BigInt square_root(BigInt a){
    int n = a.size;
    int i, j = 0;
    double sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += a.arr[i] * pow(10, j);
        j++;
    }

    long long result = sqrt(sum);

    BigInt res = convert(result);

    return res;
}
BigInt fact(BigInt a){
    BigInt ans ;
    ans.arr[0] = 1;
    ans.size = 1;
    while(a.size!=1 || a.arr[0]!=0){
        ans = multiply(ans , a);
        BigInt b ;
        b.arr[0] = 1;
        b.size = 1;   
        a = subtract(a , b);
    }
    return ans;
}
BigInt power(BigInt a, BigInt b){
    BigInt one ;
    one.arr[0] = 1;
    one.size = 1;  
    if(b.size==1 || b.arr[0]==0){
        return one;
    }
    BigInt temp = a;
    while(!(b.size==1 && b.arr[0] == 0)){
        temp = multiply(temp , a); 
        b = subtract(b , one);
    }
    return temp;
}
*/
int main(){

    BigInt a,b;
    int n;

    int choice;
    do{
        /*
		printf("\n\n--------------------------------------------\n");
        printf("\n1.Modulo of two big integers");
        printf("\n2.The square root of a big integer");
        printf("\n3.Raise a big integer to a power");
        printf("\n4.Converting a simple integer to a big integer.");
        printf("\n5.Calculating the factorial of big integer");
        */
        printf("\n1.To add two big integers");
        printf("\n2.To subtract a big integer from a big integer");
        printf("\n3.To multiply two big integers");
        printf("\n4.Exit\n\n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            a = input();
            // printBigInt(a);
            b = input();
            // printBigInt(b);
            printf("\naddition of two big integers is : ");
            printBigInt(add(a,b));
            break;
        case 2:
            a = input();
            // printBigInt(a);
            b = input();
            // printBigInt(b);
            printf("\nsubtraction of two big integers is : ");
            printBigInt(subtract(a,b));
            break;
        case 3:
            a = input();
            // printBigInt(a);
            b = input();
            // printBigInt(b);
            printf("\nmultiplication of two big integers is : ");
            printBigInt(multiply(a,b));
            break;
        /*
        case 4:
            scanf("%d",&n);
            printf("\nConverting a simple integer to a big integer : ");
            printBigInt(convert(n));
            break;
        case 5:
            a = input();
            // printBigInt(a);
            printf("\nCalculating the factorial of big integer : ");
            printBigInt(fact(a));
            break;
        case 6:
            a = input();
            // printBigInt(a);
            b = input();
            // printBigInt(b);
            printf("\nTo add two big integers : ");
            printBigInt(add(a,b));
            break;
        */
        default:
            break;
        }
    }while(choice!=6);
    
    return 0;
}
