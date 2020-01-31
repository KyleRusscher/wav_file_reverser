#include "file.h"
#include <stdio.h>
#include <stdlib.h>

size_t read_file( char* filename, char **buffer){
	FILE* file; 
	fopen_s(&file, filename, "rb"); 
	size_t size; 
	fseek(file, 0, SEEK_END); 
    size = ftell(file);
	*buffer = malloc(size);
	fseek(file, 0, SEEK_SET);
  	fread(*buffer, sizeof(**buffer), size, file);
  	fclose(file);
	return size;
}

size_t write_file( char* filename, char* buffer, size_t size){
	FILE* file; 
	fopen_s(&file, filename, "wb");
	fwrite(buffer, size * sizeof(char), 1, file);
	fclose(file);
	return size;
}
