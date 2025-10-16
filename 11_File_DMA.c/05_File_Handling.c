#include <stdio.h>
int main() {

  // //Reading a file

  // FILE *ptr=fopen("Tanjila.txt","r");

  // char str[200];

  // // if(fgets(str,100,ptr)!=NULL)
  // //   printf("%s",str);
  // //Output: prints one line

  // while(fgets(str,100,ptr)!=NULL)
  //   printf("%s",str);
  //   //Prints multiple line


     //Writing a file
     FILE *pointer=fopen("Writing.txt","w");
     //Creats a file named Writing.txt

     char string[]="Making a file and modified it";
     fputs(string,pointer);
     fclose(pointer);




  return 0;
}