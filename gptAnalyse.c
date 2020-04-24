#define _GPT_ANALYSE_C

#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "gptAnalyse.h"


static FILE *fp=NULL;
/*  **************** IMPLEMENTING MMODULE       *****/


		  BOOL gpt_open(char *gptTable) {
				printf("\nDEBUG::get_open file: (%s)\n",gptTable);

				fp = fopen(gptTable,"rb");
				if (!fp) {
						  printf("Cannot open file <%s> due to error: %s\n",gptTable,strerror(errno));
						  return FALSE;
				}
				return TRUE;
		  }
		 

		  void gpt_close() {
				puts("\nDEBUG::gpt_close\n");
				if (fp)
						  fclose(fp);
		  }



		  BOOL gpt_process()  {
					puts("\nDEBUG:: gpt_process\n");

					return TRUE;
		  }	
