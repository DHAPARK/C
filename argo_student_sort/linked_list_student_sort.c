#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_NAME_LEN 20
#define SUM(stu) (stu.score1+stu.score2)
typedef struct Student Student;
struct  Student
{
    char name[MAX_NAME_LEN];
    int score1;
    int score2;
    //int avg;
};
void Sort(Student* base, int n);
void View(Student* base, int n);
int main(int argc,char* argv[])
{

    char filename1[] = argv[1];
    char filename2[] = argv[2];

    char line[255];
    char f_name[MAX_NAME_LEN];
    int f_score1, f_score2;

    int n = 0;
    Student* base = 0;
    int i = 0;

    //파일
    FILE* file = fopen(filename1, "r");
    if (file == NULL) {
        printf("파일열기 실패\n");
        return 1;
    }
    //n 뽑아
    while (!feof(file)) {
        fgets(line, sizeof(line), file);
        n++;
    }
    fclose(file);


    file = fopen(filename1, "r");
    if (file == NULL) {
        printf("파일열기 실패\n");
        return 1;
    }
    int re_cnt = 0;
    base = (Student*)malloc(sizeof(Student) * n);
    //while (!feof(file)) {
    while(re_cnt < n){
        fgets(line, sizeof(line), file);
        
        printf("%s", line);
        sscanf(line, "%s %d %d", base[re_cnt].name, &base[re_cnt].score1, &base[re_cnt].score2);
        
        re_cnt++;
    }
    fclose(file);
    //파일
    
    Sort(base, n);
    View(base, n,&filename2);
    free(base);
    return 0;
}
void Sort(Student* base, int n)
{
    Student temp;
    int i = 0, j = 0;
    for (i = n; i > 1; i--)
    {
        for (j = 1; j < i; j++)
        {
            if (SUM(base[j - 1]) < SUM(base[j]))
            {
                temp = base[j - 1];
                base[j - 1] = base[j];
                base[j] = temp;
            }
        }
    }
}
void View(Student* base, int n,char *filename2)
{
    int i = 0;
    printf("라스트 라인 이름 점수1 점수2 합계 평균\n");
    
    
    FILE* file2 = fopen(filename2, "w");
    if (file2 == NULL) {
        printf("파일열기 실패\n");
        return 1;
    }


    char buf[256];
    for (i = 0; i < n; i++)
    {
        printf("%s %d %d %d %d \n",base[i].name, base[i].score1, base[i].score2, base[i].score1+base[i].score2, (base[i].score1 + base[i].score2) / 2);
        sprintf(buf, "%s %d %d %d %d \n", base[i].name, base[i].score1, base[i].score2, base[i].score1 + base[i].score2, (base[i].score1 + base[i].score2) / 2);
        fputs(buf,file2);
    }
}