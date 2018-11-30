#include <stdio.h>
#include <string.h>

int main(void)
{
	char word[1000001];
	int alphabet[26];
	int max = 0;
	int maxIdx = 0;
	int same_flag = 0;
	int i;
	
	scanf("%s", &word);
	
	for(i=0; i<strlen(word); i++)
	{
		if (word[i] >= 65 && word[i] <= 90 )
			alphabet[word[i]-65]++;
		else if ( word[i] >= 97 && word[i] <= 122 )
			alphabet[word[i]-97]++;
	}
	
	for(i=0; i<26; i++)
	{
		if( alphabet[i] > max )
		{
			max = alphabet[i];
			maxIdx = i;
			same_flag = 0;
		}
		else if( alphabet[i] == max )
			same_flag = 1;	
	}
	
	if( same_flag == 0 )
		printf("%c\n", maxIdx+65);
	else
		printf("?\n");

	return 0;
}
