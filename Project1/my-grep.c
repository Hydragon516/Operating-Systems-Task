#include <stdio.h>
#include <stdlib.h>
#include <string.h>                  // 문자열 비교 함수를 사용하기 위한 라이브러리

int main(int argc, char *argv[]){
        char buf;                    // 현재 문자를 저장할 버퍼
	char line[100];              // 같은 줄의 문자열을 저장할 버퍼
	char fword[100];             // 비교할 문자열

        int line_num = 0;            // 라인 번호
	int cnt = 0;                 // 같은 줄에 저장할 문자의 인덱스

        if (argc == 1){                                       // 만약 command-line argument가 없다면
                printf("\nmy-grep: searchterm [file...]\n");  // 사용법 출력
		exit(1);                                      // exit code 1
        }

	if (argc == 2){                                       // 만약 파일명 없이 문자열만 입력된 경우
		while (1){                                    // 무한 반복
			fgets(fword, 100, stdin);             // 최대 길이 100인 문자열을 입력받아
			if (strstr(fword, argv[1])){          // 이 문자열에 비교 문자열이 포함되어 있다면
				printf("%s", fword);          // 문자열 출력
			}
		}
	}

        FILE *fp;                   // file address

	if (argc > 2){                                                    // 만약 파일명까지 정확하게 입력된 경우
        	for (int i = 1; i < argc - 1; i++){
                	fp = fopen(argv[i + 1], "r");                    // 파일 열기

                	if (fp == NULL){                                  // 만약 파일이 없다면
                        	printf("\nmy-grep: cannot open file\n");  // 오류 메시지 출력
                        	exit(1);                                  // exit code 1
                	}

                	while (EOF != (buf = fgetc(fp))){                                      // 문자열이 없을때까지 반복
                        	if (buf == '\n'){                                              // 만약 줄바꿈 문자라면
                                	line_num++;                                            // 라인 번호 증가
                                	if (cnt > 0){                                          // 저장된 문자열이 있다면
                                        	line[cnt] = '\0';                              // 문자열 맨 마지막에 NULL 문자열 추가
                                        	cnt = 0;				       // 인덱스 초기화
                                        	if (strstr(line, argv[1])){                    // 만약 줄의 문자열에 비교 문자열이 포함되면
                                                	printf("%d : %s\n", line_num, line);   // 해당 줄을 줄 번호와 함께 출력
                                        	}
                                	}
                        	}

                        	else {                    // 줄바꿈 문자가 아니라면
					line[cnt] = buf;  // 줄 버퍼에 문자열 저장
					cnt++;            // 인덱스 증가
                        	}
                	}

                	fclose(fp);  // 파일 닫기
        	}
	}

        return 0;  // 0을 리턴
}
