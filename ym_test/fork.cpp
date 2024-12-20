#include <iostream>
#include <stdio.h>
#include <unistd.h>

int main(int argc, int *argv[])
{
	pid_t fpid; //fpid表示fork函数返回的值
	int count = 0;
	fpid = fork();
	if (fpid < 0)
		std::cout<<"error in fork!"<<std::endl;
	else if (fpid == 0) {
		printf("i am the child process, my process id is %d/n", getpid());
		printf("我是爹的儿子/n");//对某些人来说中文看着更直白。
		count++;
	}
	else {
		printf("i am the parent process, my process id is %d/n", getpid());
		printf("我是孩子他爹\n");
		count++;
	}
	printf("统计结果是: %d/n", count);
	return 0;
}
