// C program to remove left recursion of the grammar.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 20

int main()
{
    char pro[SIZE], alpha[SIZE], beta[SIZE];
    int nont_terminal,i,j, index=3;

    printf("Enter the Production as E->E|A: ");
    scanf("%s", pro);

    nont_terminal=pro[0];
    if(nont_terminal==pro[index]) //Checking if the Grammar is LEFT RECURSIVE
    {
        //Getting Alpha
        for(i=++index,j=0;pro[i]!='|';i++,j++){
            alpha[j]=pro[i];
            //Checking if there is NO Vertical Bar (|)
            if(pro[i+1]==0){
                printf("This Grammar CAN'T BE REDUCED.\n");
                exit(0); //Exit the Program
            }
        }
        alpha[j]='\0'; //String Ending NULL Character

        if(pro[++i]!=0) //Checking if there is Character after Vertical Bar (|)
        {
            //Getting Beta
            for(j=i,i=0;pro[j]!='\0';i++,j++){
                beta[i]=pro[j];
            }
            beta[i]='\0'; //String Ending NULL character

            //Showing Output without LEFT RECURSION
            printf("\nGrammar Without Left Recursion: \n\n");
            printf(" %c->%s%c'\n", nont_terminal,beta,nont_terminal);
            printf(" %c'->%s%c'|#\n", nont_terminal,alpha,nont_terminal);
        }
        else
            printf("This Grammar CAN'T be REDUCED.\n");
    }
    else {
        printf("\n This Grammar is not LEFT RECURSIVE.\n");
    }
    return 0;
}

// another one

// #include<stdio.h>  
//   #include<string.h>  
//   #define SIZE 10  
//   int main () {  
//        char non_terminal;  
//        char beta,alpha;  
//        int num;  
//        char production[10][SIZE];  
//        int index=3; /* starting of the string following "->" */  
//        printf("Enter Number of Production : ");  
//        scanf("%d",&num);  
//        printf("Enter the grammar as E->E-A :\n");  
//        for(int i=0;i<num;i++){  
//             scanf("%s",production[i]);  
//        }  
//        for(int i=0;i<num;i++){  
//             printf("\nGRAMMAR : : : %s",production[i]);  
//             non_terminal=production[i][0];  
//             if(non_terminal==production[i][index]) {  
//                  alpha=production[i][index+1];  
//                  printf(" is left recursive.\n");  
//                  while(production[i][index]!=0 && production[i][index]!='|')  
//                       index++;  
//                  if(production[i][index]!=0) {  
//                       beta=production[i][index+1];  
//                       printf("Grammar without left recursion:\n");  
//                       printf("%c->%c%c\'",non_terminal,beta,non_terminal);  
//                       printf("\n%c\'->%c%c\'|$\n",non_terminal,alpha,non_terminal);  
//                  }  
//                  else  
//                       printf(" can't be reduced\n");  
//             }  
//             else  
//                  printf(" is not left recursive.\n");  
//             index=3;  
//        }  
//   }   
