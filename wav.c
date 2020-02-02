#include "wav.h"
#include <stdio.h>

wav_file* parse(char* contents){
	wav_file* wav = (wav_file*)contents;
	wav->actualData = &contents[44];
	return wav;
}
