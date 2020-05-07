#define _GPT_ANALYSE_C

#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "gptAnalyse.h"
#include "gptStruct.h"


static FILE *fp=NULL;
/*  **************** IMPLEMENTING MMODULE       *****/


 BOOL gpt_open(char *gptTable) {
	#ifdef DEBUG
				printf("Size of Bytes: BYTE: <%d>, UNIT16: <%d>, UINT_32: <%d>, U_INT64 <%d>\n",sizeof(BYTE),sizeof(U_INT16), sizeof(U_INT32),sizeof(U_INT64));

	 		   printf("\nDEBUG::get_open file: (%s)\n",gptTable);
	 #endif	
				fp = fopen(gptTable,"rb");
				if (!fp) {
						  printf("Cannot open file <%s> due to error: %s\n",gptTable,strerror(errno));
						  return FALSE;
				}
				
				return TRUE;
		  }
		 

		  void gpt_close() {
		#ifdef DEBUG
				puts("\nDEBUG::gpt_close\n");
		#endif
				if (fp)
						  fclose(fp);
		  }


#define GPT_TABLE_LEN sizeof(PTABLE_GPT)


	BOOL gpt_process()  {
		PTABLE_GPT  gpt;
		int haveRead=0;
	#ifdef DEBUG
		 puts("\nDEBUG:: gpt_process\n");
	#endif
		 haveRead = fread(&gpt,GPT_TABLE_LEN,1,fp);
		 if (haveRead != 1) {
			printf("Error in reading file (wrong length), expected: %d, received: %d\n",GPT_TABLE_LEN,haveRead);
			return FALSE;
		 }
		 printf("GPT-Analyse \t\t Htl Wels/AHIT3\n\n");
		 printf("Signatur: \t\t %s\n",gpt.header.magic);
		 printf("Header Size: \t\t %ld / 0x%x\n",gpt.header.header_sz,gpt.header.header_sz);
		 //printf("Header Location: \t %ld / 0x%x\n",gpt.header.header_sz,gpt.header.header_lba,gpt.header.header_lba);
		 printf("Backup GPT: \t\t %ld / 0x%x\n",gpt.header.backup_lba,gpt.header.backup_lba);
		 
		 printf("Partitions: \t\t %d / 0x%x\n",gpt.header.entries_count,gpt.header.entries_count);
		 printf("Partition Size: \t %d / %x\n\n",gpt.header.entries_size,gpt.header.entries_size);
		  
		 return TRUE;
}	


