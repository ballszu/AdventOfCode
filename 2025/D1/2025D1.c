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
	int dial2 = 50;
	int psswd=0;
	int psswd2=0;
	char buffer[255];
	while(fgets(buffer, 255, input)!=NULL)
	{
		//Getting the direction
		int dir=2;
		if(buffer[0]=='L'){
			dir=-1;
		}
		else{
			dir=+1;
		}
		//Getting the number
		int num = atoi(buffer + 1);
		//Calculating Password 2
		for(int i = 0; i < num; i++) {
    		if(dir == 1){ 
        		dial2++; 
        		if(dial2 > 99){
            		dial2 = 0;
     		   }
    		} 
			else{
        		dial2--;
        		if(dial2 < 0){
            		dial2 = 99;
        		}
    		}
    		if(dial2 == 0){
        		psswd2++;
    		}
		}
		//Calculating password 1
		//lets calculate dial
		num = num%100;
		if(dir==1){
			dial=(dial+num)%100;	
		}
		else{
			dial=(dial-num+100)%100;
		}
		//Checking for Zero
		if(dial==0){
			psswd++;
		}
	}
	printf("Password 1 is: %d\n",psswd);	
	printf("Password 2 is: %d\n",psswd2);
	//closing the file
	fclose(input);
}
