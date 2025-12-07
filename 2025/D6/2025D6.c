#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
	//opening the file
	FILE * input = fopen("input.txt","r");
	if(!input){
		printf("nuh-uh\n");
		return 1;
	}
	char str[5000];
	long int arr[5][1000];
	memset(arr, 0, sizeof arr);
	int l=0;
	while(fgets(str,5000,input)!=NULL){
		char * token = strtok(str," ");
		int n=0;
		while(token!=NULL){
			if(!(token[0]=='+' || token[0]=='*')){
				arr[l][n]=atoi(token);
				//printf("%d\n",arr[l][n]);
			}
			else	arr[l][n]=token[0];
			token=strtok(NULL," ");
			n++;
		}
		l++;
	}
	long long sum=0;
	long long x=0;
	//Doing the puzzle logic
	for(int i=0;i<1000;i++){
		if(arr[4][i]==43)	x = (arr[0][i]+arr[1][i]+arr[2][i]+arr[3][i]);
		else	x = (arr[0][i]*arr[1][i]*arr[2][i]*arr[3][i]);
		sum = sum + x;
	}	
	printf("Answer 1 is: %lld\n",sum);
}
