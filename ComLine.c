/**
 * After reading user input, the steps are:
 * (1) fork a child process-X
 * (2) the child process will invoke execvp()-X
 * (3) if command included &, parent will invoke wait()-X
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

#define MAX_LINE 80 
#define MAX_CMD_LEN  80
#define HISTORY_COUNT 10

int history(char *hist[], int current)
{
        int i = current;
        int hist_num = 1;
        hist[0]="history";
        do 
	{
                if (hist[i]) 
				{
                        printf("%4d  %s\n", hist_num, hist[i]);
                        hist_num++;
                }

                i = (i + 1) % HISTORY_COUNT;

        } while (i != current);

        return 0;
}
int recenthistory(char *hist[], int current)
{
        int i = current;
        int hist_num = 1;
        printf("%4d  %s\n", hist_num, hist[i-1]);
        return 0;
}
int findhistory(char *hist[], int current)
{
        int i = current;
        int hist_num = 1;
        printf("%4d  %s\n", hist_num, hist[i-1]);
        return 0;
}
int main()
{
        char cmd[MAX_LINE];
        char *hist[HISTORY_COUNT];
        int i, current = 0;
		int ii=0;
		char *args[MAX_LINE/2 + 1];/* command line (of 80) has max of 40 arguments */
		memset(args, 0, sizeof(args));
	
        for (i = 0; i < HISTORY_COUNT; i++)
        {
           hist[i] = NULL;
		}

        while (1) 
        {
		ii=0;
		printf("OShw>");

           if (cmd[strlen(cmd) ] == '\n')
               cmd[strlen(cmd) ] = '\0';

            free(hist[current]);
            hist[current] = strdup(cmd);
            current = (current + 1) % HISTORY_COUNT;

			//readin inputs
			fgets(cmd, MAX_LINE, stdin);
			
			fflush(stdout);
			//parse inputs
			args[ii] = strtok(cmd, " \n");

			if (strcmp(cmd, "history") == 0)
				history(hist,current);
			else if (strcmp(cmd, "!!") == 0)
				recenthistory(hist,current);
			else if (strcmp(cmd, "!0") == 0)
			{
			int hist_num = 1;
			printf("%4d  %s\n", hist_num, hist[0]);
			}
			else if (strcmp(cmd, "!1") == 0)
			{
			int hist_num = 2;
			printf("%4d  %s\n", hist_num, hist[1]);
			}
			else if (strcmp(cmd, "!2") == 0)
			{
			int hist_num = 3;
			printf("%4d  %s\n", hist_num, hist[2]);
			}
			else if (strcmp(cmd, "!3") == 0)
			{
			int hist_num = 4;
			printf("%4d  %s\n", hist_num, hist[3]);
			}
			else if (strcmp(cmd, "!4") == 0)
			{
			int hist_num = 5;
			printf("%4d  %s\n", hist_num, hist[4]);
			}
			else if (strcmp(cmd, "!5") == 0)
			{
			int hist_num = 6;
			printf("%4d  %s\n", hist_num, hist[5]);
			}
			else if (strcmp(cmd, "!6") == 0)
			{
			int hist_num = 7;
			printf("%4d  %s\n", hist_num, hist[6]);
			}
			else if (strcmp(cmd, "!7") == 0)
			{
			int hist_num = 8;
			printf("%4d  %s\n", hist_num, hist[7]);
			}
			else if (strcmp(cmd, "!8") == 0)
			{
			int hist_num = 9;
			printf("%4d  %s\n", hist_num, hist[8]);
			}
			else if (strcmp(cmd, "!9") == 0)
			{
			int hist_num = 10;
			printf("%4d  %s\n", hist_num, hist[9]);
			}
            else if (strcmp(cmd, "forkit") == 0)
                break;
                
			if (strncmp(cmd, "&", 1) == 0)
			{
				wait(NULL);
			}      
			  
        pid_t pid = fork();
	    if (pid<0)
	    {
			printf("!!!-ERROR-!!!\n");
	    }
	    else if (pid == 0)//child
	    {
			execvp(args[ii],args);
		}
		else 
		{
			wait(NULL);
		} 
		ii++;
	}
        return 0;
}




