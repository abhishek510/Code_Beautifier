#include<stdio.h>

extern int SIZE;
int isUnderFlow(char A[] , int *top){
	if(*top == -1)
	{
		return 1;
	}


	return 0;

}


int isOverFlow(char A[] , int *top ){
	if(*top == SIZE)
	{
		return 1;
	}
	return 0;

}

void push( char A[] , int  *top, char n){

	if(isOverFlow(A,top)){



	}

	else{

		(*top)++;

		A[*top] = n;

	}
}


char pop( char A[] , int  *top){

	if(!isUnderFlow(A,top))
		return A[(*top)--] ;

		return 'a';

}

char seek ( char A[] , int *top){

	if(isUnderFlow(A,top))
		return 'a';

	else {
			return A[*top];


}
}

void display (char A[ ] , int *top )
{
	int i =0;
 	for (i =0 ; i <  *top ; i++)
 			printf("%c" , A[i]);

}
