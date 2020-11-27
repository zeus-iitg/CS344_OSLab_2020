#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void){
	printf(1, "The maximum PID of all active processes in the system is %d\n", getMaxPID());
	exit();
}