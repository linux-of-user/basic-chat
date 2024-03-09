#include <stdio.h>
#include <unistd.h>

int exists(const char *fname)
{
    FILE *file;
    if ((file = fopen(fname, "r")))
    {
        fclose(file);
        return 1;
    }
    return 0;
}


void main (void)
{
	FILE *fp;
	if (exists("Preferences.filset") == 1)
	{
		printf("Preferences found, going to Init now\n");
		fclose(fp);
		char *args[]={"./Init",NULL};
		execv (args[0],args);
	}
	else
	{
		printf("Preferences not found n\n");
		char *args[]={"./StartWizard",NULL};
		execv (args[0],args);
		printf("FATAL ERROR\n");
	}
	int value;
	
}
