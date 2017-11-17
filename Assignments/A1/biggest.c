#include <stdio.h>
#include <string.h>

#define LINE_MAX 100

int main(int argc, char *argv[])
{
	char inputLine[LINE_MAX];

	char currWord[LINE_MAX];
	char bigWord[LINE_MAX];

	int bigWeight = 0;
	int weight = 0;
	int index;
	int line = 0;

	fgets(inputLine, LINE_MAX, stdin);

	while(scanf("%c",inputLine) != EOF)
	{

		index = 0;

		line++;
		memset(bigWord,0,strlen(bigWord));
		bigWeight = 0;

		while (index < strlen(inputLine))
		{
			weight = 0;
			memset(currWord, 0, strlen(currWord));
			int currWordIndex = 0;
			while (index < strlen(inputLine) && (
					(inputLine[index] != ' ') &&
					(inputLine[index] != '\t')))
			{
				/*inputPtr has address of inputLine[],
				 *so *inputPtr will take that address and fetch data from it.
				*/
				currWord[currWordIndex] = inputLine[index];
				weight += inputLine[index]; //ASCII value

				index++;
			}
			if(weight > bigWeight)
			{
				strcpy(bigWord,currWord);
				bigWeight = weight;
			}
			index++;
		}
		if (strcmp(bigWord, " ") != 0)
		{
			printf("\nline %d's word: %s", line, bigWord);
		}
		fgets(inputLine, LINE_MAX, stdin);
//		printf("Next INPUT: %s",inputLine);
	}
}
