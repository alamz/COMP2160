#include <stdio.h>
#include <string.h>


int main(void)
{
	char * array[3] = {"zoo"};
	char array_v2[3];
	char * array_ptr;
	array_ptr = &(array);

	printf("%s\n",*array);
	printf("%p\n",array);
	printf("%p\n", array_v2);
	printf("%p", *(array_ptr+2));

}
