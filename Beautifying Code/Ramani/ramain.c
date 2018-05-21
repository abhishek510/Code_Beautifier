#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#include "utilities.h"

FILE *fin,*fout;

int SIZE = 20;
char Stack[20];
int top =-1;

void putSpacing(){

        int i=0;
        while(pop(Stack,&top)!= 'a')
{                printf("\t" );
              fprintf(fout, "\t\t" );
              i++;

}
  while(i--){

    push(Stack,&top,'{');
  }

}

int typeOfStatement(char *line){

        if(indexOf("printf",line,1) >-1 || indexOf("scanf",line,1)>-1 ) {
                return 0;

        }

        else if(indexOf("for",line,1)>-1) {
                return 2;

        }

        else if( indexOf("while",line,1)>-1 ||  indexOf("if",line,1)>-1 )
                return 3;

        else if(indexOf("=",line,1)>-1)
                return 1;


        return 0;
}


char* typeOne(char *line){

        char *temp = (char *)calloc(sizeof(char), strlen(line)*2);
        int i, j;


        char s;
        for(i=0, j=0; j< strlen(line); i++,j++) {
                s= line[j];


                if (s==',') {
                        temp[i] =',';
                        temp[i+1] = ' ';
                        i++;
                }

                else if(s== '=') {

                        if(line[j-1]== ' ')
                                temp[i]= '=';
                        else{
                                temp[i]=' ';
                                temp[i+1]='=';
                                i++;
                        }

                        if(line[j+1]!=' ')
                        {
                                temp[i+1]=' ';
                                i++;
                        }

                }
                else if(s== '(') {

                        if(line[j-1]== ' ')
                                temp[i]= '(';
                        else{
                                temp[i]=' ';
                                temp[i+1]='(';
                                i++;
                        }
                }
                else if(s== ')') {
                        temp[i]=')';
                        if(line[j+1]!=' ') {
                                temp[i+1]=' ';

                                i++;
                        }
                }



                else

                        temp[i] = line[j];

        }
        return temp;

}

char * conditionalStatements(char *str){

        char * temp = calloc(sizeof(char)*2*strlen(str),1);
        int i,j;
        for( i =0,j=0; i< strlen(str); i++,j++ ) {

                if(str[i] == '=' || str[i]=='!') {

                        if(temp[j-1] != ' ') {

                                temp[j] =' ';
                                temp[j+1] =str[i];
                                temp[j+2] = str[i+1];
                                j+=2;
                                i++;

                        }

                        else{

                                temp[j] =str[i];
                                temp[j+1] = str[i+1];
                                j+=1;
                                i++;

                        }

                        if(str[i+1] != ' ')
                        {
                                temp[j+1] = ' ';
                                j++;
                        }
                }

                else if(str[i]== '<' || str[i] =='>') {

                        if(temp[j-1] != ' ') {
                                temp[j] =' ';
                                temp[j+1] =str[i];
                                j++;
                        }
                        else if(temp[j-1] == ' ') {
                                temp[j] =str[i];
                        }

                        if(str[i+1]=='=') {
                                temp[j+1] = str[i+1];
                                j++;
                                i++;
                        }
                        if(str[i+1]!=' ') {
                                temp[j+1]=' ';
                                j++;
                        }

                }


                else{
                        temp[j] = str[i];
                }

        }

        if(indexOf("-",temp,1)+1){
                for (i=indexOf("-",temp,1)+1; i < strlen(temp)-1; i++)
                        temp[i]=temp[i+1];

        temp[i]= '\0';
}
        return temp;

}




char * forloop(char *pone, char *ptwo, char *pthree){
        size_t len = strlen(pone) + strlen(ptwo) + strlen(pthree);
        char *final = malloc(len*2*sizeof(char));
        char *temp =typeOne(pone);
        strcpy(final,temp);
        strcat(final,"; ");
        free(temp);
        temp = conditionalStatements(ptwo);
        strcat(final,temp);
        strcat(final,"; ");
        free(temp);
        temp = typeOne(pthree);
        strcat(final,temp);

        return final;
}



int main(int argc, char const *argv[]) {
        
	printf("Content-Type: text/plain;charset=us-ascii\n\n");	
	char *temp=NULL;
        char *temp2 =NULL;
        char * line = NULL;
        size_t len = 0,len2 =0;
        int i,j;
        short depth =0;


         fin =(FILE *) fopen("../uploads/test.c" ,"r");
          fout = (FILE  *) fopen("../op.txt","w");

        char ch;
        if (fin == NULL)
                exit(EXIT_FAILURE);
        char **stat;
        int x=0;
        int tos;
        while ((getline(&line, &len, fin))!= -1 ) { // read the contents of the file line by line

                        if(countOf(';',line)>0) {
                        stat = str_split(line,';');
                        if (stat) {
                                for (i = 0; *(stat + i); i++) {

                                        temp= trimwhitespace(*(stat+i));
                                        if((int)(temp)[0] != 0) {
                                                tos = typeOfStatement(temp);
                                                //printf("%d",tos );
                                                //fprintf(fout, "%d",tos );

                                                if(tos==0) {
                                                  putSpacing(depth);
                                                  fprintf(fout, "%s;\n",temp );

                                                        printf("%s;\n",temp );
                                                }
                                                else if(tos ==1) {
                                                  putSpacing(depth);

                                                        temp2 = typeOne(temp);
                                                        printf("%s;\n",temp2);
                                                        fprintf(fout, "%s;\n",temp2 );

                                                        free(temp2);
                                                }
                                                else if(tos ==2) {
                                                  putSpacing(depth);

                                                        temp2= forloop(temp, trimwhitespace(*(stat+i+1)),trimwhitespace(*(stat+i+2)));
                                                        i+=2;
                                                        printf("%s\n",temp2);
                                                        fprintf(fout, "%s\n",temp2);

                                                }
                                        }
                                        free(temp);
                                }
                                free(stat);
                        }
                }


                else{
                        tos = typeOfStatement(line);
                        if(tos ==0)
                                temp2 = typeOne(trimwhitespace(line));
                        else
                                temp2 = conditionalStatements(trimwhitespace(line));
                        putSpacing(depth);
                        fprintf(fout, "%s\n",temp2 );

                        printf("%s\n",temp2 );
                        free(temp2);

                }

                if(indexOf("{", line,1) >-1) {
                        push(Stack , &top , '{');
                }
                if(indexOf("}", line,1) >-1) {
                        pop(Stack , &top);
                }

        }

        exit(EXIT_SUCCESS);

        return 0;
      }
