#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TASK 100
#define MAX_LEN   100

char task[MAX_TASK][MAX_LEN];
int state[MAX_TASK];   // 0: 진행중, 1: 완료, 2: 삭제
int count = 0;

/* 함수 선언 */
void print_menu();
void view_task();
void add_task();
void complete_task();
void delete_task();

int main(void)
{
    char input[20];
    int menu;

    while (1)
    {
        print_menu();

        if (fgets(input, sizeof(input), stdin) == NULL)
            continue;

        trim_newline(input);

        if (strlen(input) == 0)
            continue;

        menu = atoi(input);

        switch (menu)
        {
            case 1:
                view_task();
                break;
            case 2:
                add_task();
                break;
            case 3:
                complete_task();
                break;
            case 4:
                delete_task();
                break;
            case 0:
                printf("프로그램을 종료합니다.\n");
                return 0;
            default:
                printf("잘못된 입력입니다.\n");
                break;
        }
    }