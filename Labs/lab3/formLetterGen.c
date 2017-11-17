				
#include <stdio.h>
#include <string.h>

void printTemplate(char * peopleData[])
{
	printf("Welcome back, %s!\n",peopleData[1]);
	printf("We hope that you and all the members\n");
	printf("of the %s family are constantly\n",peopleData[0]);
	printf("reminding your neighbours there\n");
	printf("on %s to shop with us.\n",peopleData[5]);
	printf("As usual, we will ship your order to\n");
	printf("   %s %s %s. %s\n",peopleData[3],peopleData[1],peopleData[2],peopleData[0]);
	printf("   %s %s\n",peopleData[4],peopleData[5]);
	printf("   %s, %s %s\n",peopleData[6],peopleData[7],peopleData[8]);
}

int main(void){
    
    FILE *fp;
    char * data[4][9]; //data is a pointer to data[0][0]
	
    char dataBuffer[81];
    
    char *token;
    
    fp = fopen("data.txt","r");
    if (fp == NULL)
    {
        printf("ERROR OPENING FILE");
    }
    else
    {
		int numPeople = 0;
        while(fgets(dataBuffer,81,fp)!=NULL)
        {
			// printf("[%d] dataBuffer: %s",numPeople,dataBuffer);
			token = strtok(dataBuffer,"| \n");	//token points to Public
			int numToken = 0;					//counts token taken from dataBuffer
			while(token!=NULL)
			{
				// printf("*token= %s\n",token);
				
				
				data[numPeople][numToken]= strdup(token);
				token = strtok( NULL , "|" );
				
				// printf("data: %s\n",data[numPeople][numToken]);

				numToken++;
			}
			numPeople++;
        }
    }
	printTemplate(data[0]);
	printTemplate(data[1]);
	printTemplate(data[2]);
	printTemplate(data[3]);
}
