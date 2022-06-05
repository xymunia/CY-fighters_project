#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>


char** ListStr(char* line)  //  faut voir avec strtok
{
    char** res = 0;
    int count = 0;
    char* tmp = line;
    char delim[2];
    *delim = ',';
    *(delim+1) = 0;

    // Count the number of elements we want to split 
    while (*tmp)
    {
        if (',' == *tmp)
        {
            count++;
        }
        tmp++;
    }

    count++;

    res = malloc(sizeof(char*) * count);

    if (res)
    {
        int idx  = 0;
        char* token = strtok(line, delim);

        while (token)
        {
            *(res + idx + 1) = strdup(token);
            token = strtok(0, delim);
        }
        *(res + idx) = 0;
    }

    return res;
}

int main(){


	char** liste;
	liste = malloc(sizeof(char*)*3);
	char* str;
	str = "Janvier,Fevrier,Mars";
	liste=ListStr(str);

	for(int i = 0;i<3;i++){
	printf("%s\n",*(liste+i));
	} 
	free(liste);







}
