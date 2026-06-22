#include <stdio.h>
#include <string.h>

char task[100][100];
int state[100];   // 0: 진행중, 1: 완료, 2: 삭제
int count = 0;  // 현재 만든 일 수
int selecte_num = 0;

// 함수 선언
void print_menu();
void wait_q();
int  quit(char input[]);
void view_task();
void add_task();
void complete_task();
void delete_task();
void print_task_list();
int  decide_num();

int main(void)
{
    int menu;

    while (1)
    {
        print_menu();

        scanf("%d", &menu);
        getchar();

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

int quit(char input[])
{
    return (strcmp(input, "Q") == 0 || strcmp(input, "q") == 0);
}

void wait_q()
{
    char input[20];

    while (1)
    {
        printf("Q를 입력하면 메인 화면으로 돌아갑니다 : ");
        
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (quit(input))
            break;
    }
}

void print_task_list()
{
    int i;

    if (count == 0)
    {
        printf("등록된 할 일이 없습니다.\n");
        return;
    }
    printf("---------------------------------------------------------------------------\n");
    printf("\n");
    printf("---------------------------------------------------------------------------\n");
    printf("                                   To-Do 리스트\n");
    printf("---------------------------------------------------------------------------\n");

    for (i = 0; i < count; i++)
    {
        if (state[i] == 0)
            printf("%d. [ ] %s\n", i + 1, task[i]);
        else if (state[i] == 1)
            printf("%d. [V] %s\n", i + 1, task[i]);
        else if (state[i] == 2)
            printf("%d. [X] %s\n", i + 1, task[i]);
    }

    printf("---------------------------------------------------------------------------\n");
}

void view_task()
{
    print_task_list();
    wait_q();
}

void add_task()
{
    char input[1000];
    printf("Q를 입력하면 메인 화면으로 돌아갑니다.\n");

    while (1)
    {
        printf("할 일을 입력하세요. : ");

        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
            
        if (quit(input))
            return;

        else if (strlen(input) == 0)
        {
            continue;
        }

        else if (strlen(input) > 100)
        {
            printf("입력된 문자수가 100보다 큽니다. 다시 입력해주세요\n");
            continue;
        }

        else if (count >= 100)
        {
            printf("할 일이 너무 많습니다. 더 이상 추가할 수 없습니다.\n");
            return;
        }

        strcpy(task[count], input);
        state[count] = 0;
        count++;

        printf("할 일 추가 완료\n");
    }
}

int decide_num()
{
    char input[30];
    int value;

    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    if (quit(input))
        return -1;

    if (sscanf(input, "%d", &value) != 1)
        return 0;

    selecte_num = value;
    return 1;
}

void complete_task()
{
    int result;

    if (count == 0)
    {
        printf("등록된 할 일이 없습니다.\n");
        wait_q();
        return;
    }
    
    print_task_list();
    printf("Q를 입력하면 메인 화면으로 돌아갑니다.\n");
    while (1)
    {
        printf("완료 처리할 번호를 입력해주세요. : ");
        result = decide_num();

        if (result == -1)
            return;

        else if (result == 0)
        {
            printf("잘못된 입력입니다.\n");
        }

        else if (selecte_num < 1 || selecte_num > count)
        {
            printf("존재하지 않는 번호입니다.\n");
        }

        else if (state[selecte_num - 1] == 1)
        {
            printf("이미 완료된 할 일입니다.\n");

        }

        else if (state[selecte_num - 1] == 2)
        {
            printf("이미 삭제된 할 일입니다.\n");
        }

        else 
        {
            state[selecte_num - 1] = 1;
            printf("할 일이 완료 처리되었습니다.\n");
        }
    }
    return;
}

void delete_task()
{
    int result;

    if (count == 0)
    {
        printf("등록된 할 일이 없습니다.\n");
        wait_q();
        return;
    }

    print_task_list();
    printf("Q를 입력하면 메인 화면으로 돌아갑니다.\n");
    while (1)
    {
        printf("삭제할 번호를 입력해주세요. : ");
        result = decide_num();

        if (result == -1)
            return;

        else if (result == 0)
        {
            printf("잘못된 입력입니다.\n");
        }

        else if (selecte_num < 1 || selecte_num > count)
        {
            printf("존재하지 않는 번호입니다.\n");
        }

        else if (state[selecte_num - 1] == 2)
        {
            printf("이미 삭제된 할 일입니다.\n");
        }

        else
        {
            state[selecte_num - 1] = 2;
            printf("할 일이 삭제되었습니다.\n");
        }
    }
    return;
}
