#include <stdio.h>
#include <assert.h>

#define SIZE 26

int are_anagrams(char[],char[]);

int main() {
    printf("running test 'iceman' and 'cinema'...\n");
    char iceman[] = "iceman";
    char cinema[] = "cinema";

    assert(are_anagrams(iceman, cinema));
    printf("passed!\n");

    printf("running test 'raganam' and 'anagram'...\n");
    char raganam[] = "raganam";
    char anagram[] = "anagram";

    assert(are_anagrams(raganam, anagram));
    printf("passed!\n");
    
    printf("running test 'listen' and 'silent'...\n");
    char listen[] = "listen";
    char silent[] = "silent";

    assert(are_anagrams(listen, silent));
    printf("passed!\n");

    printf("running test 'mole' and 'meal'...\n");
    char mole[] = "mole";
    char meal[] = "meal";

    assert(!are_anagrams(mole, meal));
    printf("passed!\n");

    printf("running test 'happy' and 'sad'...\n");
    char happy[] = "happy";
    char sad[] = "sad";

    assert(!are_anagrams(happy, sad));
    printf("passed!\n");
}

int are_anagrams(char first_word[], char second_word[]) {
    int i=0, j=0, len1=0, len2=0, key=0;
    while (first_word[i]!=0)
    {
        len1++;
    }

    while (second_word[j]!=0)
    {
        len2++;
    }
    
    if(len1!=len2)
        return 0;

    for(i=1;i<len1;i++)
    {
        key=first_word[i];
        j=i-1;
        
        while(j>=0 && first_word[j]>key)
        {
            first_word[j+1]=first_word[j];
            j=j-1;
        }
            first_word[j+1]=key;
    }

    i=0, j=0, key=0;

         for(i=1;i<len1;i++)
     {
         key=second_word[i];
         j=i-1;

         while(j>=0 && second_word[j]>key)
         {
             second_word[j+1]=second_word[j];
             j=j-1;
         }
             second_word[j+1]=key;
     }

    i=0, j=0;

        while(len1!=0)
        {
            if(first_word[i]!=second_word[i])
            {
                return 0;
            }
            i++;
            len1--;
        }
            return 1;
}
