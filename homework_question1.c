#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int counter=6,i=0,j=0,guess=0,show=0,k;
  char str[6]={'S','E','N','S','E'};
  int alphabet[26];
  int alphabet2[26];
  char word[32];
  for(k=0;k<26;k++){
  alphabet[k]=0;
  }
   for(k=0;k<26;k++){
  alphabet2[k]=0;
  }
  int letterPos;
  int totalRight=0;
  while(guess<counter){
    printf("Please enter a word: "); scanf("%s",&word);
    printf("\nAttempted word: %s\n",word);
    totalRight=0;
    int len=strlen(word);
    if(len>5||len<5){
    printf("Try again\n");
}
    else{
    for(i=0;i<5;i++){
      if(word[i]==str[i]){
        printf("Correct place: %c\n",word[i]);
        if(str[j]>='a'&&str[j]<='z'){
      letterPos=str[j]-'a';
 }
else{
letterPos=str[j]-'A';
}
alphabet[letterPos]++;
        totalRight++;
      }
    }
   
    for(j=0;j<5;j++){
    if(str[j]>='a'&&str[j]<='z'){
      letterPos=str[j]-'a';
 }
else{
letterPos=str[j]-'A';
}
alphabet2[letterPos]++;

}

if(totalRight==5)
    {
      printf("Correct!\n");
      exit(1);
    }


    for(j=0;j<5;j++){
    for(i=0;i<5;i++){
//     letterPos=word[i]-'A';
     if(word[i]==str[j]){
  if(i!=j){
  if(word[i]>='a'&&word[i]<='z'){
      letterPos=word[i]-'a';
 }
else{
letterPos=word[i]-'A';
}

      if(alphabet[letterPos] == 0){
 printf("%c isn't in the right place, but is in the word\n",word[i]);
 }
      alphabet[letterPos]++;
     
       
//        i++;
    }
     }
   }
}
printf("totalRight= %d\n",totalRight);
   
guess++;
  }
}
}