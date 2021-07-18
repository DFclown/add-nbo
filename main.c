
#include "FileRead.h"

int main(int argc, char* argv[]) {

	if( argc < 2 )
       	{

		printf("./add-nbo 입력 후 합칠 파일명을 입력해주세요.\n");
		exit(0); // EXIT_SICCESS
	}

	uint32_t* uintarr = (uint32_t*)malloc(sizeof(uint32_t) * (argc-1));
	uint32_t uin32 = 0;
	
	for(int i = 1; i < argc; i++)   //argc = 3
       	{
	
		uint32_t temp = FileRead(argv[i]); 
		uintarr[i-1] = temp;
		uin32 += temp;
	}	

	//1000(0x3e8) + 500(0x1f4) = 1500(0x5dc)
	
	for(int i =1; i < argc; i++) 
	{
		
		printf("%d(%#04x)", uintarr[i-1], uintarr[i-1]);
		if(i == argc - 1)
			break;

		printf(" + ");
	}
	printf(" = %d(%#04x)\n", uin32, uin32);
	free(uintarr);	//malloc memory free
	return 0;
}
