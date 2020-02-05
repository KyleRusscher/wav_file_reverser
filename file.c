#include "file.h"
#include <stdio.h>
#include <stdlib.h>

size_t read_file( char* filename, char **buffer){
	FILE* file = fopen(filename, "rb"); 
	if(file == NULL){
		printf("There was an error opening %s.  Please verify %s is a valid file.", filename, filename);
		exit(1);
	}
	size_t size; 
	fseek(file, 0, SEEK_END); 
    	size = ftell(file);
	fseek(file, 0, SEEK_SET);
	
	*buffer = malloc(size);
	if (*buffer == NULL) {
    		printf("failed to allocate memory.\n");
    		exit(1);
	}
  	fread(*buffer, sizeof(**buffer), size, file);
  	fclose(file);
	return size;
}

size_t write_file( char* filename, char* buffer, size_t size){
	FILE* file = fopen(filename, "wb");
	if(file == NULL){
		printf("There was an error writing to %s.", filename);
		exit(1);
	}
	fwrite(buffer, size * sizeof(char), 1, file);
	fclose(file);
	return size;
}
