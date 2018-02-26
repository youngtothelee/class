/*
 Name: Young Joon Lee (yl24429)
 */

#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "String.h"

#define SIGNATURE (~0xdeadbeef)

/*
 * Helper macro to find the signature of a UTString
 * Treat this like a function that takes a UTString*
 * Accesses a uint32_t from where the signature should be located
 */
#define CHECK(s) (*(uint32_t*) ((s)->string + (s)->length + 1))

/*
 * Checks if a UTString is valid or not.
 */
bool isOurs(const UTString* s) {
    if (CHECK(s) == SIGNATURE) { return true; }
    else { return false; }
}

/*
 * Allocate a utstring on the heap.
 * Initialize the string correctly by copying src.
 * Return a pointer to the UTString.
 */
UTString* utstrdup(const char* src) {
    uint32_t i=0, len=0;
    struct UTString *mystringptr;

    while (src[i]!=0){
        len++;
        i++;
    }
    mystringptr=(UTString*)malloc(sizeof(UTString));
    mystringptr->string=(char*)malloc(len*sizeof(char)+5);

    for (i=0; i<len; i++){
        (*mystringptr).string[i]=src[i];
    }
    (*mystringptr).string[len]='\0';
    mystringptr->length=len;
     mystringptr->capacity=len;
    CHECK(mystringptr)=SIGNATURE;
    return mystringptr;
}

/*
 * Returns the length of s.
 *  s must be a valid UTString.
 */
uint32_t utstrlen(const UTString* s) {
    if (!isOurs(s)){
        return 0;
    }

	return s->length;
}

/*
 * Append the string suffix to the UTString s.
 *  s must be a valid UTString.
 * Do not allocate any additional storage: only append as many characters
 *  as will actually fit in s.
 * Update the length of s.
 * Return s with the above changes. */
UTString* utstrcat(UTString* s, const char* suffix) {
    assert(isOurs(s));

    uint32_t i=0, len=0, capacity=0;
    len=s->length;
    capacity=s->capacity;

    while(i+len<capacity && suffix[i]!='\0'){
        (*s).string[i+len]=suffix[i];
        i++;
    }
    (*s).length=i+len;
    (*s).string[i+len]='\0';
    CHECK(s) = SIGNATURE;
    return s;
}

/*
 * Copy src into dst.
 *  dst must be a valid UTString.
 *  src is an ordinary string.
 * Do not allocate any additional storage: only copy as many characters
 *  as will actually fit in dst.
 * Update the length of dst.
 * Return dst with the above changes.
 */
UTString* utstrcpy(UTString* dst, const char* src) {
    assert(isOurs(dst));
    uint32_t i=0;
    while(src[i]!=0 && dst->capacity!=0){
        (*dst).string[i]=src[i];
        i++;
        (*dst).capacity--;
    }
    dst->length=i;
    (*dst).string[i]='\0';
    CHECK(dst) = SIGNATURE;


    return dst;
}

/*
 * Free all memory associated with the given UTString.
 */
void utstrfree(UTString* self) {
    assert(isOurs(self));
    char* str = self->string;
    free(str);
    UTString* pt= self;
    free(pt);
    return;
}

/*
 * Make s have at least as much capacity as new_capacity.
 *  s must be a valid UTString.
 * If s has enough capacity already, do nothing.
 * If s does not have enough capacity, then allocate enough capacity,
 *  copy the old string and the null terminator, free the old string,
 *  and update all relevant metadata.
 * Return s with the above changes.
 */
UTString* utstrrealloc(UTString* s, uint32_t new_capacity) {
    assert(isOurs(s));
    uint32_t i=0;

    if(s->capacity>=new_capacity) {
        return s;
    }
    else {

        UTString* newString = (UTString*)malloc(sizeof(UTString));
        newString->string=(char*)malloc(new_capacity+5);
        (*newString).length=(*s).length;
        (*newString).capacity=new_capacity;
        while((*s).string[i]!='\0') {
            (*newString).string[i] =(*s).string[i];
            i++;
        }
        (*newString).string[i]='\0';
        CHECK(newString) = SIGNATURE;

        utstrfree(s);
        return newString;
    }
}
