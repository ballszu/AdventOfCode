#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
    //opening the file
    FILE *input = fopen("input.txt","r");
    if(!input){
        printf("File did not open correcty");
        return 1;
    }
    //getting the variables
    int nLines=0;    //number of lines in text
    int chars=0;    //number of Chars
    for (int c = getc(input); c != EOF; c = getc(input)){
        if (c == '\n') nLines++;
        else chars++;
    }
    rewind(input); 
	int charsl=chars/nLines;
    //populating the array
    int input_arr[nLines][charsl];
    int line=0;
    int col=0;
    int c;
    while ((c = getc(input)) != EOF){ 
        if(c !='\n'){
            input_arr[line][col] = c -'0';
            col++;
        }
        else {
            line++;
            col=0;
        }
    }
	//PUZZLE LOGIC
	int joultl=0;
	for(int i=0;i<nLines;i++){
			int b=0;
			int b2=0;
			int tens=0;
			int ones=0;
		for(int j=0;j<charsl;j++){
			if(input_arr[i][j]>b){
				b2=b;
				b=input_arr[i][j];
			}
			else if(input_arr[i][j]>b2){  
				b2=input_arr[i][j];
			}
		}
		for(int j=0;j<charsl;j++){
			if(input_arr[i][j]==b2){
				tens=b2;
				ones=b;
				break;
			}
			else if(input_arr[i][j]==b){
				tens=b;
				ones=b2;
				break;
			}
			else if(input_arr[i][j]==b2 || input_arr[i][j]==b){
				tens=b;
				ones=b;
				break;
			}
		}
		joultl=(tens*10)+(ones*1)+joultl;
		
	}
	printf("Answer 1 is: %d\n",joultl);
    //closing the file
    fclose(input);
}
