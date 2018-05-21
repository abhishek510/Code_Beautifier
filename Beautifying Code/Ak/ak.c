#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#include "utilities.h"


FILE *fin ,*fout;

void putSpacing(int depth){

  int i;
  for( i =0 ; i<depth; i++)
    fprintf(fout, "   " );

}

int typeOfStatement(char *line){

  if(indexOf("</",line) >-1 ){
      return 1;

  }

  else if(indexOf("/>",line)>-1){
    return 2;

  }

  return 0;
}


char* typeOne(char *line){

char *temp = (char *)calloc(sizeof(char), strlen(line)*2);
int i, j;
char s;
for(i=0, j=0 ; j< strlen(line); i++,j++){
s= line[j];
if(line[j]=='='  && (line[j-1]=='!' || line[j-1]=='=' || line[j-1]=='<' || line[j-1]=='>')){
    temp[i]=temp[i-1];
    temp[i-1]=' ';
    temp[i+1]='=';
    temp[i+2]=' ';
    i+=2;
}
 else if(line[j]== '=' && line[j+1]!='='){

    temp[i]=' ';
    temp[i+1]='=';
    temp[i+2]=' ';
    i+=2;
   }
else if(line[j]=='<' && j!=0){

    temp[i]='\n';
    temp[i+1]=line[j];
    i+=1;
   }
else
  temp[i] = line[j];
}


return temp;

}
/*char * typeTwo(char *line){

  char *temp = (char *)malloc(sizeof(char)*strlen(*line)*2);

//  temp = typeOne(substr(0,indexOf(";",line)+1, line));





}*/

int SIZE = 20;
char Stack[20];
int top =-1;


int main(int argc, char const *argv[]) {

   char * line = NULL;
   size_t len = 0;
   int i,j;
   short depth =0;

  fin =(FILE *) fopen("../uploads/test.html" ,"r");
  fout = (FILE  *) fopen("../op.txt","w");
  char ch;
     if (fin == NULL){
        printf("ak");
        exit(EXIT_FAILURE);

     }


      char *temp;
      int x=0;
      int tos;
     while ((getdelim(&line, &len,'>', fin))!= -1 ) {   // read the contents of the file line by line



        //fprintf(fout, "%s\n",temp );



      temp=strstrip(line);
      temp=typeOne(temp);
      //temp=check(temp,depth);
      putSpacing(depth);

      fprintf(fout, "%s\n",temp );

if(indexOf("<br>", line) == -1 && indexOf("<meta", line) == -1 && indexOf("<input", line) == -1)
{

if(indexOf("<", line) >-1){

              depth++;

            }
      if(indexOf("</", line) >-1){

              depth-=2;

            }
}
}



     exit(EXIT_SUCCESS);

  return 0;
}
