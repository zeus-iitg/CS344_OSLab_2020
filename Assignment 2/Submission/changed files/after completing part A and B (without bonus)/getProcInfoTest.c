#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char* argv[]){

	if (argc < 2)
    {
        printf(1, "Incorrect Format!\nFormat: getProcInfoTest <PID>\n");
        exit();
    }

	struct processInfo info;
	if(getProcInfo(atoi(argv[1]), &info) == -1){
		printf(1, "No process has that PID.\n");
		exit();
	}
	if(info.ppid != -2)
		printf(1, "PPID: %d\nSize: %d\nNumber of Context Switches: %d\n", info.ppid, info.psize, info.numberContextSwitches);
	else
		printf(1, "PPID: No Parent Process\nSize: %d\nNumber of Context Switches: %d\n", info.psize, info.numberContextSwitches);
	exit();
}