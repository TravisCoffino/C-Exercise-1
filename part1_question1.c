//TRAVIS COFFINO SBU ID 115445347 at 12:31pm
#include<stdio.h>
#include <stdlib.h>
#define MAX 32

int main()
{
  char str[MAX];
  int i=0;
  char ch;
  float dec;
  FILE *inp_f;
  FILE *out_p;
  float sum=0;
  float avg=0;
  int n=0;
  
if((inp_f = fopen("test.txt","r"))== NULL){
  printf("Error opening input file");
  exit(1);
}

if((out_p = fopen("output.txt","w")) == NULL){
  printf("Error writing to output file");
  exit(1);
}

while((ch=fgetc(inp_f))!=EOF){
  if((ch>='0'&&ch<='9')||ch=='-'||ch=='+'){
    str[i]=ch;
    i++;
    while(((ch=fgetc(inp_f))!=EOF)&&((ch>='0'&&ch<='9')||(ch=='.'))){
      str[i]=ch;
      i++;

      
    }
    for(int j = 0; j < i; j++){
      printf("ch %d: %c\n", j, str[j]);
    }
    
    str[i]='\0';
    dec=atof(str);
    sum=sum+dec;
    
    printf("%f",dec);
    fprintf(out_p,"%f",dec);
    
  }
  n++;
  avg=sum/n;
  i=0;
  fprintf(out_p,";");
  // fprintf(out_p,"\n%d\n",n);
}
fprintf(out_p,"\nsum: %f\n",sum);
    fprintf(out_p,"avg: %f\n",avg);

fclose(inp_f);
fclose(out_p);

  //your code here
}
