#include "FileRead.h"

uint32_t FileRead(const char* str) {

	FILE* file;
	file = fopen(str, "rb");
	uint32_t uin32;

	if (file == NULL) {

		fputs("File error", stderr);
		exit(1);  // EXIT_FAILURE
	}

	fread(&uin32, sizeof(uint32_t), 1, file); 
	uin32 = ntohl(uin32); // 16bit ip_address network to host 
	
	fclose(file);

	return uin32;
}

