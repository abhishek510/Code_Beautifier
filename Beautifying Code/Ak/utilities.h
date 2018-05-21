#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int indexOf( const char sub[] ,  char str[]){
  int i,j , found =0;
  int index = -1;
  for (i= 0 ; i < strlen(str) ; i++){
    if(str[i] == sub[0]){
      found =1;
      for(j=1 ;j<strlen(sub); j++){
        i++;
        if(str[i] != sub[j]){
          found =0;
          break;
        }
      }
    }
    if(found){
      index = i +1 - strlen(sub);
      break;
    }
  }
    return index;
}

char * substr(int beg , int end ,  char str[]){

  if(end < beg || end > strlen(str) || beg< 0 )
    return NULL;

  char *sub = (char *)malloc(sizeof(char)*(end-beg+1));
  int  i;
  for(i =beg ; i < end ; i++)
    sub[i-beg] = str[i];

return sub;
}


char* strstrip(char *s) 
{
    size_t size;
    char *end;

    size = strlen(s);

    if (!size)
    	return s;

    end = s + size - 1;
    while (end >= s && isspace(*end))
    	end--;
    *(end + 1) = '\0';

    while (*s && isspace(*s))
    	s++;

    return s;
}





check(char *line,int depth)
{	
	int i;
	char *temp_begin,*temp_end;
	temp_begin=substr(0,indexOf("\n", line)+1,line);
	temp_end=substr(indexOf("\n", line)+1,strlen(line),line);
	for( i =0 ; i<depth; i++)
    		strcat(temp_begin,"   " );
	return (strcat(temp_begin,temp_end));

}
























