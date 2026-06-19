#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char task[100][100];
int state[100];   // 0: 진행중, 1: 완료, 2: 삭제
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

        input[strcspn(input, "\n")] = '\0';

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
            case 5:
                printf("프로그램을 종료합니다.\n");
                return 0;
            default:
                printf("잘못된 입력입니다.\n");
                break;
        }
    }

    return 0;
}

void print_menu()
{
    printf("---------------------------------------------------------------------------\n");
    printf("                                   To-Do 리스트\n");
    printf("---------------------------------------------------------------------------\n");
    printf("1. 할 일 보기\n");
    printf("2. 할 일 추가\n");
    printf("3. 할 일 완료\n");
    printf("4. 할 일 삭제\n");
    printf("5. 종료\n");
    printf("---------------------------------------------------------------------------\n");
    printf("선택 : ");
}

void view_task()
{
    char temp[10];
    if(count == 0)
        printf("등록된 할 일이 없습니다.\n");
    else
    {
        for(int i = 0; i <= count - 1; i++)
        {
            if(state[i] == 0)
                printf("[   ]");
            else if(state[i] == 1)
                printf("[ V ]");
            else if(state[i] == 2)
                printf("[ X ]");
            printf("%d. %s\n", i, task[i]);
        }
        printf("---------------------------------------------------------------------------\n");
    }
    while(1)
    {
        fgets(temp,sizeof(temp),stdin);
        if(strncmp(temp, "Q\n", 10) == 0 || strncmp(temp, "q\n", 10) == 0)
            break;
    }
}

void add_task()
{
    char temp[101];
    while(1)
    {
        printf("할일을 입력하세요 : ");
        fgets(temp,sizeof(temp),stdin);
        if(strncmp(temp, "Q\n", 101) == 0 || strncmp(temp, "q\n", 101) == 0)
            break;
        else
        {
            temp[100] = 0;
            strncpy(task[count], temp, 100);
            count++;
        }

    
        printf("\n");
        printf("할 일 추가 완료\n");
    }
}
    printf("---------------------------------------------------------------------------\n");
}
