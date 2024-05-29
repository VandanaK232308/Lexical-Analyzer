/*
NAME :
DATE :
DESCRIPTION :
SAMPLE INPUT :
SAMPLE OUTPUT :
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define NUM_KEYWORDS 8

const char *keywords[] = {"int", "float", "long", "char", "double", "short", "switch", "case"};

int is_keyword(const char *word) 
{
    for (int i = 0; i < NUM_KEYWORDS; i++) 
    {
	if (strcmp(word, keywords[i]) == 0) 
	{
	    return 1;
	}
    }
    return 0;
}

int is_operator(char ch)
{
    return ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == ';' ||
	ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '<' ||
	ch == '>' || ch == '=';
}

void handle_word(const char *word) 
{
    if (is_keyword(word))
    {
	printf("Keyword: %s\n", word);
    }
    else if (word[0] == '"' && word[strlen(word) - 1] == '"') 
    {
	printf("Literal: %s\n", word);
    } 
    else if (isdigit(word[0]) || (word[0] == '.' && isdigit(word[1]))) 
    {
	printf("Literal: %s\n", word);
    } 
    else if (word[0] != '\0') {
	printf("Identifier: %s\n", word);
    }
}

void handle_operator(char op) 
{
    printf("Operator: %c\n", op);
}

int main() 
{
    FILE *file;
    char ch;
    char word[100];
    int word_index = 0;

    file = fopen("test.c", "r");
    if (file == NULL) 
    {
	perror("Error opening file");
	return EXIT_FAILURE;
    }

    while ((ch = fgetc(file)) != EOF) 
    {
	if (isspace(ch) || is_operator(ch)) 
	{
	    word[word_index] = '\0';
	    handle_word(word);
	    word_index = 0; 
	    if (is_operator(ch)) 
	    {
		handle_operator(ch);
	    }
	} 
	else 
	{
	    word[word_index++] = ch;
	}
    }

    if (word_index > 0) 
    {
	word[word_index] = '\0';
	handle_word(word);
    }

    fclose(file);
    return EXIT_SUCCESS;
}





