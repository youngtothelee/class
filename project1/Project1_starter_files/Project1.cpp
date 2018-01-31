/*
 * Project1.cpp
 * 
 * Name: Ima Student
 * EE312 Spring 2016
 * SpellCheck
 */

#include <stdio.h> // provides declarations for printf and putchar
#include <stdint.h> // provides declarations for int32_t uint32_t and the other (new) standard C types

/* All of your code must be in this file. Please no #includes other than standard system headers (ie.., stdio.h, stdint.h)
 *
 * Many students find it helpful to declare global variables (often arrays). You are welcome to use
 * globals if you find them helfpul. Global variables are by no means necessary for this project.
 */

/* You must write this function (spellCheck). Do not change the way the function is declared (i.e., it has
 * exactly two parameters, each parameter is a standard (mundane) C string (see SpellCheck.pdf).
 * You are expected to use reasonable programming style. I *insist* that you indent
 * reasonably and consistently in your code. I strongly encourage you to avoid big functions
 * So, plan on implementing spellCheck by writing two or three other "support functions" that
 * help make the actual spell checking easier for you.
 * There are no explicit restictions on using functions from the C standard library. However,
 * for this project you should avoid using functionality from the C++ standard libary. You will
 * almost certainly find it easiest to just write everything you need from scratch!
 */


bool lettertest(char letter){
    if((letter>64 && letter<91)||(letter>96 && letter<123)){
        return true;
	}
	else {
	    return false;
	}
}



void spellCheck(char article[], char dictionary[]) {
    char temp[50]={0};
    int i=0,j=0, k=0, t=0, counter=0;

    while (article[i]!=0 && article[i+1]!=0){
        if(lettertest(article[i]) && lettertest(article[i+1])){ 
            j=i;
            
            while(article[j]!=32){
                if(article[j+1]==0){
                    break;
                }
                else
                {
                    j++;
                    counter++;
                }
            }
            
            j=i;
            k=counter-1;

            while(counter!=0){
                temp[t]=article[j];
                j++;
                t++;
                counter--;
            }
            
            t=0;
            while(temp[t]!=0){
                printf("%c", temp[t]);
                t++;
            }
                printf("\n");
                i=i+k;
                for(j=0;j<49;j++){
                    temp[j]=0;
                }
        }
        j=0;
        t=0;
        counter=0;
        i++;
        k=0;

    }
}
