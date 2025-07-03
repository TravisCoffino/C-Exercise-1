#include<stdio.h>
#include <stdlib.h>
#define MAX 32

int main()
{
  FILE *inp_f;
  FILE *out_p;
int X,Y;
int a,b;
char str[MAX];
  if((inp_f = fopen("test2.txt","r"))== NULL){
  printf("Error opening input file");
  exit(1);
}

if((out_p = fopen("output2.txt","w")) == NULL){
  printf("Error writing to output file");
  exit(1);
}

while((fscanf(inp_f,"%s %d %d",&str, &a, &b))!=EOF){

if(strcmp(str,"INITIAL")==0)
{
	X=a;
	Y=a;
}
else if(strcmp(str,"UP")==0){
	Y+=a;
}
else if(strcmp(str,"DOWN")==0){
	Y-=a;
}
else if(strcmp(str,"LEFT")==0){
	X-=a;
}
else if(strcmp(str,"RIGHT")==0){
	X+=a;
}

printf("Current Position: %d %d\n",X,Y);

    
  }
}
