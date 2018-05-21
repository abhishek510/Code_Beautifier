#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>

int indexOf( const char sub[] ,  char str[], int n){
  int i,j , found =0 ,oc =0;
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
      oc++;
      if(oc == n){
      index = i +1 - strlen(sub);
      break;
      }
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

int countOf(char ch , char str[]){

int i,c=0;
for(i =0 ; i< strlen(str);i++)
      if(str[i] == ch)
          c++;

return c;
}



char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

char *trimwhitespace(char *str){
  size_t len = 0;
      char *frontp = str;
      char *endp = NULL;

      if( str == NULL ) { return NULL; }
      if( str[0] == '\0' ) { return str; }

      len = strlen(str);
      endp = str + len;

      /* Move the front and back pointers to address the first non-whitespace
       * characters from each end.
       */
      while( isspace((unsigned char) *frontp) ) { ++frontp; }
      if( endp != frontp )
      {
          while( isspace((unsigned char) *(--endp)) && endp != frontp ) {}
      }

      if( str + len - 1 != endp )
              *(endp + 1) = '\0';
      else if( frontp != str &&  endp == frontp )
              *str = '\0';

      /* Shift the string so that it starts at str so that if it's dynamically
       * allocated, we can still free it on the returned pointer.  Note the reuse
       * of endp to mean the front of the string buffer now.
       */
      endp = str;
      if( frontp != str )
      {
              while( *frontp ) { *endp++ = *frontp++; }
              *endp = '\0';
      }


      return str;
}
