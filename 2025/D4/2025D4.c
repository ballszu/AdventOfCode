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
    char input_arr[nLines][chars/nLines];
    int line=0;
    int col=0;
    int c;
    
    while ((c = getc(input)) != EOF){ 
        if(c !='\n'){
            input_arr[line][col] = c;
            col++;
        }
        else {
            line++;
            col=0;
        }
    }
	//PUZZLE LOGIC
	//
	//
	//
	int count = 0;
	int ans1=0;
	for(int i=0;i<nLines;i++){
		for(int j=0;j<charsl;j++){
			if(input_arr[i][j]=='@'){
				//check for boundary
				for(int x=i-1;x<=i+1;x++){
					for(int y=j-1;y<=j+1;y++){
						if(x>=0 && y>=0 && x<charsl && y<nLines && input_arr[x][y]=='@') count++;
					}
				}
				//if less than 4 rolls
				//add to count else not
				if(count<5){
					ans1++;
				}
				count=0; //reset count to zero
			}
		}
	}
	printf("Answer 1 :%d\n",ans1);
	//
	//
	//
	//Part 2 Of the puzzle
	count=0;
	int ans2=0;
	//making a copy of the input array
    char input_arr_cp[nLines][chars/nLines];
	for(int i=0;i<nLines;i++){
		for(int j=0;j<charsl;j++){
			input_arr_cp[i][j]=input_arr[i][j];
		}
	}
	//puzzle logic
	while(true){
	for(int i=0;i<nLines;i++){
		for(int j=0;j<charsl;j++){
			if(input_arr[i][j]=='@'){
				//check for boundary
				for(int x=i-1;x<=i+1;x++){
					for(int y=j-1;y<=j+1;y++){
						if(x>=0 && y>=0 && x<charsl && y<nLines && input_arr[x][y]=='@'){
							count++;
						}
					}
				}
				//if less than 4 rolls
				//add to count else not
				if(count<5){
					ans2++;
					//updating the future array
					input_arr_cp[i][j]='x';
				}
				count=0; //reset count to zero
			}
		}
	}
	//updating the old array to new array
	for(int p=0;p<nLines;p++){
		for(int q=0;q<charsl;q++){
			input_arr[p][q]=input_arr_cp[p][q];
		}
	}	
	printf("Answer 2:%d\n",ans2);
	}
	//
	//
	//
    //closing the file
    fclose(input);
}
