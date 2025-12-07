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
    int rows=0;    //number of rows
    int chars=0;    //number of chars
    for (int c = getc(input); c != EOF; c = getc(input)){
        if (c == '\n') rows++;
        else chars++;
    }
    rewind(input); 
	int cols=chars/rows;	//number of cols
							
    //populating the array
    int input_arr[rows][cols];
    int r=0;
    int c=0;
    int ch;
    
    while ((ch = getc(input)) != EOF){ 
        if(ch !='\n'){
            input_arr[r][c] = ch;
            c++;
        }
        else {
            r++;
            c=0;
        }
    }
	//puzzle logic
	//part 1
	//
	//setting up the first ray
	for(int i=0;i<rows;i++){
		if(input_arr[0][i]=='S') input_arr[1][i]='|';
	}
	//now the ray passes~
	int count=0;
	for(int i=1;i<rows;i++){
		for(int j=0;j<cols;j++){
			if(input_arr[i][j]=='|' && input_arr[i+1][j]=='^'){
				input_arr[i+1][j-1]='|';
				input_arr[i+1][j+1]='|';
				count++;
			}
			else if(input_arr[i][j]=='|'){
				input_arr[i+1][j]='|';
			}
			printf("%c",input_arr[i][j]);
		}
		printf("         count is: %d",count);
		printf("\n");
	}
	//
	//
	//
	fclose(input);
}
