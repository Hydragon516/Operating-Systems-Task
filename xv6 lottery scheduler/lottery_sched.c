#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]){
    int i, j;
    int n = argc - 2;  // 추가로 생성할 프로세스 개수

    int current_pid = getpid();

    for(i = 0; i < n; ++i){
        if(current_pid == getpid()){  // 프로세스 중복 생성을 막기 위해 부모 프로세스인 경우만 실행
            fork();  // 프로세스 생성  
        }
    }

    for(j = 0; j < argc; j++){
        if(getpid() == current_pid + j){  // PID 번호를 증가시키며
            setticknum(atoi(argv[j + 1]));  // 프로세스에 티켓을 할당
            printf(1, "%d ok\n", atoi(argv[j + 1]));
        }
    }

    wait();  // 티켓 할당 완료까지 대기

    while(1){
		if(uptime() > 2000){  // uptime 2000까지 프로세스 유지
			break;
		}
	}

    exit();
}