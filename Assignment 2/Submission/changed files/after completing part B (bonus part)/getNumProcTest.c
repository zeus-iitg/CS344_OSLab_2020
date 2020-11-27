#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void){
	printf(1, "The total number of active processes in the system is %d\n", getNumProc());
	exit();
}