# include <stdio.h>
# include <string.h>
# include <cstdlib>
struct Birthday
{
	int year;
	int mouth;
	int day;
};
struct Score	
{
	double chinese;
	double math;
	double english;
};
struct Student
{
	char name[10];
	char stuNum[10];
	char sex[5];
	int  age;
	struct Score score; 
	struct Birthday birthday;
}student[3];
int main()
{
	struct Student student[3];
	struct Student *p = NULL;
	p = &student[0];
	strcpy(p -> name , "ÍõÆôãå");
	strcpy(p -> stuNum , "20200503");
	strcpy(p -> sex , "Male");
	p -> birthday.year = 2000;
	p -> birthday.mouth = 1;
	p -> birthday.day 	=1;
	p -> age = 20;
	p -> score.chinese = 120;
	p -> score.english = 140;
	p -> score.math	= 135;
	printf("Name:%s\tNum:%s\n",p->name,p->stuNum);
	printf("Sex:%s\tAge:%d\tBirthday:%d %d %d\n",p -> sex,p-> age,p -> birthday.year,p -> birthday.mouth,p -> birthday.day);
	printf("Math:%.0lf\tEnglish:%.0lf\tChinese:%.0lf\n",p->score.math,p->score.english,p->score.chinese); 
	system("pause");
	return 0;
}
