//Travis Coffino
#include <stdio.h>
#include <stdlib.h>
#define NRROWS 4
#define NRCOLS 4

int main(){
	FILE *fin;
	float a[6][6], sum=0,sum2=0;
	int i,j,m,n,row;
	float temp;
	// float a[NRROWS][NRCOLS];
	if((fin=fopen("lab7test1.txt","r"))==NULL){
		printf("File lab7test1.txt cannot be opened\n");
		exit(1);
	}
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			fscanf(fin,"%f",&a[i][j]);
		}
	}
	for(i=0;i<3;i++){
		scanf("%d",&row);
		for(j=0;j<5;j++){
			sum+=a[row][j];
		}
	}
	printf("%f\n",sum);
	
	
	// -----------------------
	
	scanf("%d%d",&n,&m);
	for(j=0;j<5;j++){
		temp=a[n][j];
		a[n][j]=a[m][j];
		a[m][j]=a[n][j];
	}
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			//fprintf(fout,"%f",a[i][j]);
      printf("%f ",a[i][j]);
		}
		//fprintf(fout,"\n");
    printf("\n");
	}

	// -----------------

	for(i=0;i<5;i++){
		for(j=i;j<5;j++){
			printf("%f ",a[i][j]);
			sum2=sum2+a[i][j];
		}printf("\n");
		
	}printf("sum: %f",sum2);
}