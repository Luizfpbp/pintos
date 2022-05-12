#include <stdio.h>
#include <string.h>
#include "devices/input.h"
#include "threads/login.h"

void
scan_check (uint8_t* keys) {

	uint8_t key;
	int tamArr = 0;
		
	printf("lfpbp> ");

	while (key != 13) {
		key = input_getc();
		if (key == 8) {
			printf("\b \b");
			tamArr--;
		}
		
		else if (key == 13) {break;}	

		else {
			keys[tamArr] = key;
			printf("%c", (char)key);
			tamArr++;
		}

	}

	return;

}


void 
login (void) {

	while (1) {
		uint8_t keys[99];
		memset(keys, 0, 99);
		scan_check(keys);
		char* cmd = (char*)keys;
		
		if (strcmp(cmd, "exit") == 0) {
			printf("\n");
			memset(keys, 0, 99);
			break;
		}
		
		
		else if (strcmp(cmd, "whoami") == 0) {
			printf("\nLuiz Fernando Paes de Barros Presta\n");
			memset(keys, 0, 99);	
		}
		
		else {
			printf("\ninvalid command\n");
			memset(keys, 0, 99);
		}		
		
	}
}

