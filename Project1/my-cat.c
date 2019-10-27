#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	char buf;             // 현재 문자를 담을 버퍼
	char p_buf = '\n';    // 직전 문자를 담을 버퍼
	int line_num = 1;     // 라인 번호

	if (argc == 1){       // 만약 파일 이름이 입력되지 않으면
		return 0;     // 0을 리턴
	}

	FILE *fp;             // file address

	for (int i = 0; i < argc - 1; i++){                       // 파일의 개수만큼 loop
		fp = fopen(argv[i + 1], "r");                    // 파일 열기

		if (fp == NULL){                                  // 만약 파일이 존재하지 않다면
			printf("\nmy-cat: cannot open file\n");   // 에러 메시지 출력
			exit(1);                                  // exit code 1
		}

		while (EOF != (buf = fgetc(fp))){                 // 문자열이 읽히면 while문 유지
			if (p_buf == '\n'){                       // 만약 직전 문자에 줄바꿈 문자가 있다면
				printf("%4d  ", line_num);        // line 번호 출력
				line_num++;                       // line 번호 증가
				p_buf = buf;                      // 직전 문자 버퍼에 현 문자 저장
				printf("%c", buf);                // 문자열 출력
			}
			else {                                    // 줄바꿈 문자가 아니라면
				printf("%c", buf);                // 문자열 출력
				p_buf = buf;                      // 직전 문자 버퍼에 현 문자 저장
			}
		}
		fclose(fp);                                       // 파일 닫기
	}

	return 0;                                                 // 0을 리턴
}
