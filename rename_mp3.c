#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    
    FILE* f;
 
    for(int i = 1; i < argc; i++){
	    
 		f = fopen(argv[i], "r");		
 		char *song_name = malloc(30*sizeof(char));
 		
 		char *dump = malloc(3*sizeof(char));
 		fseek(f, -128 ,SEEK_END );
 		
 		for(int j= 0; j < 3; j++) fscanf(f, "%c", &dump[j]);
 		for(int j= 0; j < 30; j++)fscanf(f, "%c", &song_name[j]);
 		
 			
 		char *performer_name = malloc(30*sizeof(char));
 		
 		for(int j= 0; j < 30; j++) fscanf(f, "%c", &performer_name[j]);
 		
		char* new_name = malloc(65*sizeof(char));
		
		strcpy(new_name, performer_name);
		strcat(new_name, " - ");
		strcat(new_name, song_name);
		
		int ren = rename(argv[i], new_name);
		
        
    
    }



    return 0;
}
