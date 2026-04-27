#include<stdio.h>
unsigned int count =0;

unsigned int temp = 0;
unsigned int puissance_rapide(unsigned int x, unsigned int n){
    printf("Appel %u ^ %u \n", x ,n );
    if(n ==0){
        printf("return 1\n");
        count++;
        return 1;
    }else if (n%2 ==0){
        count++;
        temp = puissance_rapide(x, n/2);
        printf("%u ^ %u = (%u^%u)*(%u^%u)", x,n,x, n/2, x,n/2);
        printf("Avec %u^%u =%u \n" ,x,n/2 ,temp);
        return temp*temp;
        }else if(n%2 == 1){
            count++;
            int temp = puissance_rapide(x, (n-1)/2);
            printf("%u ^ %u = %u x (%u^%u)*(%u^%u)", x,n,x,x, (n-1)/2, x,(n-1)/2);
            printf("Avec %u^%u =%u \n" ,x,(n-1)/2 ,temp);

            return x*temp*temp;

        }else{
           //code erreur
           return -1;
            }
    }
int main(){
    puissance_rapide (5,2);
    return 0;
    }
