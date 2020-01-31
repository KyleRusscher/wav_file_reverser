#include "file.h"
#include "wav.h"
#include "stdio.h"
#include <stdlib.h> 
#include <string.h> 

int main(int argc, char** argv){
	char* buffer;
	size_t file_size = read_file(argv[1], &buffer);
	file_size = write_file(argv[1], buffer, file_size);
	wav_file* wav = parse(buffer);
	if (strcmp(wav->wave, "WAVE") != 0){
		exit(24);
	}
	printf("\nFile: %s", argv[1]);
	printf("\n====================");
	printf("\nFile size is %zu.  Read %d bytes.", file_size, wav->readbytes);
	printf("\nFormat is \"%s\" with format data length %d.", wav->fm, wav->formatLength);
	printf("\nFormat type is %s", wav->wave);
	printf("\n%hu channel(s) with a sample rate of %d. ", wav->numChannels, wav->sampleRate);
	printf("\n%d byte rate, 2 alignment, %d bits per sample.", wav->bitsPerSample, wav->bitsPerSampleShort);
	printf("\nData is \"%s\" and data size is %d\n", wav->beginData, wav->sizeOfData);

	for(int i = 44; i < wav->sizeOfData / 2; i+=wav->bitsPerSampleShort){
		for(int j = 0; j < wav->bitsPerSampleShort; j++){
			char temp = wav->actualData[i+j];
			wav->actualData[i+j] = wav->actualData[wav->sizeOfData - wav->bitsPerSampleShort - i + j];
			wav->actualData[wav->sizeOfData - wav->bitsPerSampleShort - i + j] = temp;
		}
	}
	file_size = write_file(argv[2], buffer, file_size);
}
