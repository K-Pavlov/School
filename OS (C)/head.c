//--------------------------------------------
// NAME: Kaloyan Pavlov
// CLASS: 11a
// NUMBER: 16
// PROBLEM: #1
// FILE NAME: head.c
// FILE PURPOSE:
// The program recreates the head function in UNIX.
//--------------------------------------------
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

//--------------------------------------------
// FUNCTION: work_file
// Takes 10 lines from file ot standart input and prints them to standart output.
// PARAMETERS:
// f - File we take the lines from.(or of no file we take from standtard input), f1 -  the name of the file.
//----------------------------------------------
void work_file(int f,char* f1){
	int br = 0,fds;
	char all,msg[100] = "Head: cannot";  
	while(br < 10){
		fds = read(f,&all,1);
	
		if (fds == -1 ){ // check if read was unsuccessful and returns a hand made error if it is		
			strcat(msg, " read '");
			strcat(msg, f1);
			strcat(msg, "'");
			perror(msg);
		}	
		
		if (all=='\n')
			br++ ;	
		
		if(write(STDOUT_FILENO,&all,1) == -1){ // check if write was unsuccessful and returns a hand made error	if it is
			strcat(msg, " write '");
			strcat(msg, f1);
			strcat(msg, "'");
			perror(msg); 
		}
	}
}

//--------------------------------------------
// FUNCTION: close_file
// Attempts to close the file. If it fails returns a hand-made error.
// PARAMETERS:
// f - the file we try to close. f1 - the name of the file
//----------------------------------------------
int close_file(int f,char* f1){
	char msg[100] = "Head: cannot";
	if (close(f) == -1){
			strcat(msg, " close '");
			strcat(msg, f1);
			strcat(msg, "'");
			perror(msg);
			return -1;	
		}
	close(f);
	return 0;
	}

//--------------------------------------------
// FUNCTION: make_msg
// Makes error msg for open.
// PARAMETERS:
// f1 - the name of the file
//----------------------------------------------

void make_msg(char* f1){ 
		char msg[100] = "Head: cannot";         
		strcat(msg, " open '");
		strcat(msg, f1);
		strcat(msg, "' for reading");
		perror(msg);
}

int main(int argc,char* argv[]){
	int f,fc = 1;
	if (argc == 1){ // if we have no arguments
		work_file(0,NULL);
	}else if(argc==2){ // if we have 1 argument 
		f = open(argv[1],O_RDONLY,0); // Opening file 
		if (f == -1){ // Checking if open was unsuccessful 
			make_msg(argv[1]);
			return -1;
		}	
		work_file(f,argv[1]);
		close_file(f, argv[1]);
	}else{ // if we have more than argument file
		while (fc < argc){
			if(*argv[fc]!='-'){ // checkin if we have an file as an argument
				f = open(argv[fc],O_RDONLY,0);
				if (f == -1){ // Checking if open was unsuccessful
					make_msg( argv[fc]);
					fc++;
					continue;
				}
				// making it look like the head command --
				write(STDOUT_FILENO,"==> ",4); 
				write(STDOUT_FILENO,argv[fc],strlen(argv[fc]));
				write(STDOUT_FILENO," <==\n",5);
				// --
				work_file(f,argv[fc]);
				close_file(f, argv[fc]);
			}else{ // if we have - as an argument print 10 lines from standtard input
				work_file(0,NULL);
			}
			fc++;
		}
	} 
	return 0;
}
