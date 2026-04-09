#include <stdio.h>
#include <stdlib.h>


int main()
{
    printf("%c", 'a');
    // FILE* fp;

    //파일에서 읽기
    // fp = fopen("test.txt", "r");
    // int a,b;

    // if(fp == NULL)
    // {
    //     printf("파일 열기 실패\n");
    //     return 1;
    // }

    // fscanf(fp, "%d %d", &a, &b);

    // printf("a = %d, b = %d\n", a, b);

    // fclose(fp);
    // return 0;



    // 파일에 쓰기 -> 'w'는 기존 내용 다지우고 새로쓴다
    // fp = fopen("test.txt", "w");

    // if(fp == NULL)
    // {
    //     printf("파일 열기 실패\n");
    //     return 1;
    // }
    
    // fprintf(fp, "Hello file!\n");
    // fprintf(fp, "%d\n", 123);

    // fclose(fp);
    // return 0;


    //파일에 이어쓰기 -> 'a'는 기존 내용 안지운다, 파일 끝에 추가한다
    // fp = fopen("test.txt", "a");

    // if(fp == NULL)
    // {
    //     printf("파일 열기 실패!\n");
    //     return 1;
    // }

    // fprintf(fp, "추가된 내용\n");

    // fclose(fp);
    // return 0;
}