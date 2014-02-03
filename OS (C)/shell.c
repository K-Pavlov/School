//--------------------------------------------
// NAME: Kaloian Pavlov
// CLASS: XIa
// NUMBER: 16
// PROBLEM: #2
// FILE NAME: shell
// FILE PURPOSE:
// Runs the a file given from stdin with 
// arguments, again given from stdin.
//---------------------------------------------
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

//--------------------------------------------
// FUNCTION: parse_cmdline
// Takes a string and return an array of
// strings, splitted by delimeter whitespace.
// PARAMETERS:
// const char* cmd_line - string, user input
// taken from stdin.
//----------------------------------------------
char** parse_cmdline(const char * cmd_line)
{
	int char_count, string_count = -1;
	int substrings = 1,chars_to_write = 0;
	int place_in_string;
	void* new_size;
	//Find the count of substring by
	//couting white spaces, new lines.
	for(char_count = 0; char_count < strlen(cmd_line); char_count++)
	{
		if(isspace(cmd_line[char_count]))
		{
			substrings++;
		}
	}
	//Allocate memory and check if it was successful
	char** parsed_string = malloc(substrings*sizeof(*parsed_string));
	if(parsed_string == NULL)
	{
		perror("Out of memory\n");
		exit(EXIT_FAILURE);
	}
	
	//Go through the whole string, when a
	//whitespace or new line is found write
	//to a string the found chars.
	for(char_count = 0; char_count < strlen(cmd_line); char_count++)
	{
		if(isspace(cmd_line[char_count]))
		{
			string_count++;
			place_in_string = 0;
			parsed_string[string_count] = malloc(sizeof(parsed_string));
			//Write the found chars.
			for(; chars_to_write < char_count; chars_to_write++,place_in_string++)
			{		
				parsed_string[string_count][place_in_string] = cmd_line[chars_to_write];
				//reallocate the memory and check if it was successful
				new_size =
				    realloc(parsed_string[string_count], (place_in_string + 2) * sizeof(parsed_string));
				if(new_size != NULL)
				{
					parsed_string[string_count] = new_size;
				}
				else
				{
					perror("Out of memory");
					exit(EXIT_FAILURE);
				}
			}
			chars_to_write++;
			parsed_string[string_count][place_in_string] = '\0';
		}
	}
	return parsed_string;
}

// Main entry point.
int main(int argc,char** argv)
{
	int status = 0, char_count = 0;	
	char next_in;
	pid_t child;
	char* unparsed_cmd;
	void* new_ele;
	//Endless loop if ctrl+d(EOF char) is
	//pressed the program stops
	while(1)
	{
		char_count = 0;
		//Allocate mememory and check if it was successful
		unparsed_cmd = malloc(sizeof(unparsed_cmd));
		if(unparsed_cmd == NULL)
		{
			perror("Out of memory\n");
			return EXIT_FAILURE;
		}
		//Takes input until enter(\n char) is pressed.
		do{
			if(next_in == EOF)
			{
				return EXIT_SUCCESS;
			}
			next_in = fgetc(stdin);
			unparsed_cmd[char_count] = next_in;
			char_count++;
			//reallocate the memory and check if it was successful
			new_ele = realloc(unparsed_cmd,(char_count+1)*sizeof(unparsed_cmd));
			if(new_ele != NULL)
			{
				unparsed_cmd = new_ele;
			}
			else
			{
				perror("Out of memory");
				return EXIT_FAILURE;
			}
		}while(next_in != '\n'); 		
		char** parsed_cmd = parse_cmdline(unparsed_cmd);
		child = fork();
		//Checks if fork is successful
		if( child < 0)
		{
			status = -1;
			perror("Fork:");
		}
		else if(child == 0)
		{
			//Takes the path == checked[0], checking if execv works			
			if ( execv(parsed_cmd[0], parsed_cmd))
			{
				perror(parsed_cmd[0]);
				return EXIT_FAILURE;
			}
			
		}
		else
		{
			//Waiting for child
			if( waitpid (child, &status, 0) != child ) {
				status = -1;
			}
		}
		//Free dynamically allocated memory.
		free(unparsed_cmd);
	}
	return EXIT_SUCCESS;
}