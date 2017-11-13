#include <stdio.h>
#include <stdlib.h>
 
#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <OpenCL.lib>
#endif

int main(){
	printf("oie");
}	
