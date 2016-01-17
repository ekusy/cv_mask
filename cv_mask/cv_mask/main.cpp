#include "main.h"

main::main()
{
}


main::~main()
{
}

void main(void){
	cvFunc CV;

	while (true){
		DWORD start = timeGetTime();
		Position pos = CV.getPosition(0.5,0.5);
		DWORD end = timeGetTime();
		double time = (double)(end - start) / 1000;
		printf("time = %lfÅFfps = %lfÅ@x=%d,y=%d\n",time,1/time,pos.x,pos.y);
	}
}