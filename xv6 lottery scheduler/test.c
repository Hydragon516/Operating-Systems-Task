#include "types.h"
#include "stat.h"
#include "user.h"

int main(void){
	int pid;

	pid = fork();

	if(pid == -1){
		printf(1, "can't fork, error\n");
		exit();
	}

	if(pid == 0){
		setticknum(100);
	} 
	
	else{
		setticknum(10);
	}

	while(1){
		if(uptime() > 1000){
			break;
		}
	}

	exit();
}
