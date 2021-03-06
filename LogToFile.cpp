#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

int LogToFile(char *szLogText, ...)
{
	FILE *fp;

	if (!(fp = fopen("logs\\metahook.log", "a")))
		return 0;

	va_list vArgptr;
	char szText[1024];

	va_start(vArgptr, szLogText);
	vsprintf(szText, szLogText, vArgptr);
	va_end(vArgptr);

	fprintf(fp, "%s\n", szText);
	fclose(fp);

	return TRUE;
}