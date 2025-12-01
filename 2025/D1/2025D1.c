#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
	//opening the file
	FILE *input = fopen("input.txt","r");
	if(!input)
	{
		printf("File did not open correcty");
		return 1;
	}
	//Reading the file
	int dial = 50;
	int psswd=0;
	char buffer[255];
	while(fgets(buffer, 255, input)!=NULL)
	{
		//Getting the direction
		int dir=2;
		if(buffer[0]=='L')
		{
			dir=-1;
		}
		else
		{
			dir=+1;
		}
		//Getting the number
		int num = atoi(buffer + 1);
		//Now we have the Num, Dir, Dial
		//lets calculate dial
		num = num%100;
		printf("num is %d ",num);
		printf("|| and dir is %d\n",dir);
		//for +ve
		if(dir==1){
			dial=(dial+num)%100;	
		}
		else{
			dial=(dial-num+100)%100;
		}
		//Checking for Zero
		if(dial==0)
		{
			psswd++;
		}
	}
	printf("Zero is %d\n",psswd);
	//closing the file
	fclose(input);
}
