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
	int joultl[nLines]=0
	for(int i=0;i<nlines;i++){
			int b=0;
			int b2=0;
		for(int j=0;j<charsl;j++){
			if(input_arr[i][j]>b){
				b2=b;
				b=input_arr[i][j];
			}
			else if(input_arr[i][j]>b2){  
				b2=input_arr[i][j];
			}
		}
		
	}
    //closing the file
    fclose(input);
}
