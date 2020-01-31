typedef struct wav_file{
	char riff[4];
	int readbytes;
	char wave[4];
	char fm[4];
	int formatLength;
	short formatType;
	short numChannels;
	int sampleRate;
	int bitsPerSample;
	short blockAlignment;
	short bitsPerSampleShort;
	char beginData[4];
	int sizeOfData;
	char* actualData;
} wav_file;


wav_file* parse(char* contents);
