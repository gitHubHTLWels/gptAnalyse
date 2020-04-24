
#ifndef _GPT_ANALYSE_H__
#define _GPT_ANALYSE_H__


	 #ifndef BOOL   
		#define BOOL char   
		void gpt_close();
		BOOL gpt_process();
		#define TRUE   1     
     #define FALSE  0     
    #endif   


		  BOOL gpt_open(char *);
		  void gpt_close();
		  BOOL gpt_process();




#endif
