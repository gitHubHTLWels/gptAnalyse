#include <stdio.h>
#include <sys/stat.h>


#include "gptAnalyse.h"

//DEFINES
#define ERROR_MISSING_ARG	-1
#define ERROR_READING_FILE  -2

static BOOL file_exist(const char *);

int main(int argc, char **argv) {
		
	puts("\n  GPT TABLE Analyser  \n");

	if (argc < 2) {
		puts("Missing arg: expected GPT Header\n");
		return ERROR_MISSING_ARG;
	}
	if (!file_exist( *(argv	+1))) {
			  puts("GPT Header Info not found\n");
			  return ERROR_READING_FILE;
	}
	
	if (!gpt_open(*(argv +1))) {
	     return -1;
	}

	if (!gpt_process()) {
		  return -2;
	}

	gpt_close();

	return 0;

}	

/* LOCAL / STATIC Functions   */


static BOOL file_exist(const char *filePath) {
	struct stat buffer;
	return (stat(filePath,&buffer)==0 ? TRUE : FALSE);
}

