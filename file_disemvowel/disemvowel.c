#include <stdlib.h>
//newly added
#include <string.h>
//#include "disemvowel.h"
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
//please refer to Lab 2 C Strings and Memory Management for details
//please refer the open source code for file reading and writing
#define BUF_SIZE 1024
//declaim
void disemvowel(FILE*, FILE* ); 
bool is_vowel(char c) {
      /*
     * Returns true if c is a vowel (upper or lower case), and
     * false otherwise.
     */
char lower = tolower(c);
if(lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u'){
return true;
}
return false;
}
int copy_non_vowels(int num, char* in_buf, char* out_buf){
      /*
     * Copy all the non-vowels from in_buf to out_buf.
     * num_chars indicates how many characters are in in_buf,
     * and this function should return the number of non-vowels that
     * that were copied over.
     */
int num_chars = 0;
for(int i = 0; i < num; i++){
if(!is_vowel(in_buf[i])){
out_buf[num_chars] = in_buf[i];
num_chars++;
}
}
return num_chars;
}
int main(int argc, char *argv[]){
      // This sets these to `stdin` and `stdout` by default.
    // You then need to set them to user specified files when the user
    // provides files names as command line arguments.
FILE *inputFile = stdin;
FILE *outputFile = stdout;
if(argc == 2) {
inputFile = fopen(argv[1], "r");
} else if(argc == 3){
inputFile = fopen(argv[1], "r");
outputFile = fopen(argv[2], "w");
} else if(argc > 3){
fprintf(stderr, "Too many arguments, please refer to the github documents.");
exit(1);
}
if(inputFile == NULL || outputFile == NULL){
fprintf(stderr, "File error, please refer to the github documents.");
exit(1);
}
disemvowel(inputFile, outputFile);
if(inputFile != stdin){
fclose(inputFile);
}
if(outputFile != stdout){
fclose(outputFile);
}
return 0;
}
/*
char *disemvowel(char *str) {
  //allocat memory
  char *result = (char*) calloc (strlen(str) + 1, sizeof(char));
  int i,j = 0;
  for(i=0; str[i]; i++){
    
    char checkStr[1] = {str[i]};
    if (strpbrk(checkStr,"AEIOUaeiou")){
    }
    else{
      result[j++] = str[i];
    }
  }
  result[j] = '\0';
  return (char*) result;
  //return (char*) "";
}
*/
void disemvowel(FILE* inputFile, FILE* outputFile){
      /*
     * Copy all the non-vowels from in_buf to out_buf.
     * num_chars indicates how many characters are in in_buf,
     * and this function should return the number of non-vowels that
     * that were copied over.
     */
char in[BUF_SIZE];
char out[BUF_SIZE];
while(!feof(inputFile)){
int num_chars = fread(in, sizeof(char), BUF_SIZE, inputFile);
int non_vowel = copy_non_vowels(num_chars, in, out);
fwrite(out, sizeof(char), non_vowel, outputFile);
}
}
 
