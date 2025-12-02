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
	int psswd2=0;
	int temp1=0;
	int temp2=0;
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
		//Calculations
		if(dir==1){
			psswd2=((num+dial)/100)+psswd2;
			num = num%100;
			temp1=dial;
			dial=(dial+num)%100;
			if(dial==temp1){
				psswd2--;
			}
		}
		else{
			psswd2=((num-(num+99))/-100)+psswd2;
			num = num%100;
			temp2=dial;
			dial=(dial-num+100)%100;
			if(dial==temp2){
				psswd2--;
			}
		}
		//Checking for Zero
		if(dial==0)
		{
			psswd++;
		}
	}
	printf("Answer for 1st Puzzle is: %d\n",psswd);
	printf("Answer for 2nd Puzzle is: %d\n",psswd2+psswd);
	//closing the file
	fclose(input);
}
