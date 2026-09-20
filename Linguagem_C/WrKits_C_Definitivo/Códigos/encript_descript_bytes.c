#include<stdlib.h>
#include<stdio.h>


//Constants
# define N 6


//Variables declaration
unsigned int hexa_numbers[N]={0xA0, 0x73};

//Function's prototypes

void encription(unsigned int hexa_numbers[], int num);

void decription(unsigned int hexa_numbers[], int num);


//Main method
int main(){
    

    //Encription
    encription(hexa_numbers,N);


    //Decription
    decription(hexa_numbers,N);



        
    return 0;
}



//Functions
void encription(unsigned int hexa_numbers[], int num){

    for (int i=0, j=1; i<num; i++, j++){
        printf("Insira o %dº número hexadecimal (use o prefixo 0x):\n", j );
        scanf("%X", &hexa_numbers[i]); 
    }

    for (int i=0; i<num; i++){
        if(i%2==0){
            hexa_numbers[i]+=5;
        }
        if(i%2 != 0){
            hexa_numbers[i]-=3;
        }
    
    }

    for (int i=0, j=1; i<num; i++, j++){
        printf("O %dº número hexadecimal é: 0x%X \n", j , hexa_numbers[i]);
        
    }


}


void decription(unsigned int hexa_numbers[], int num){


    for (int i=0, j=1; i<num; i++, j++){
        if(i%2==0){
            hexa_numbers[i]-=5;
            
        }
        if(i%2 != 0){
            hexa_numbers[i]+=3;
        }
        printf("O %dº número hexadecimal é: 0x%X \n", j , hexa_numbers[i]);

        
        
    }



}