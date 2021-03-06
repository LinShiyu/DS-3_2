// DS exp3_2.cpp: 定义控制台应用程序的入口点。
//

#include <stdio.h>
#define SIZE 100

int enQueue(int *que, int rear, int data)
{
	que[rear] = data;
	rear++;
	return rear;
}

int deQueue(int *que, int front, int rear)
{
	if (front != rear) {
		front++;
	}
	else {
		printf("!");
	}
	return front;
}

int *input(int *que, int &rear_input)
{
	char input[SIZE] = { 0 };
	scanf("%s", input);

	int temp[SIZE] = { 0 };
	int i = 0, j = 0;
	for (i = 0;input[i] != 0;i++) {
		temp[j] = input[i] - '0';
		j++;
	}

	for (j = 0;temp[j] != 0;j++) {
		rear_input = enQueue(que, rear_input, temp[j]);
	}
	return que;
}

int caculate(int *que, int front, int rear, int pos)
{
	int count = 0; //count中存储出队的元素个数，即打印用时

	while (pos > -1) {
		int select = 0;

		//如果当前任务不是目标任务
		if (pos > 0) {
			for (int i = front;i <= rear;i++) {
				if (que[front] < que[i]) {
					select = 1;
				}
			}
			//如果队列中有比当前任务优先级高的
			if (select == 1) {
				rear = enQueue(que, rear, que[front]);
				front = deQueue(que, front, rear);
				pos--;
			}
			//如果队列中没有比当前任务优先级高的
			else if (select == 0) {
				front = deQueue(que, front, rear);
				pos--;
				count++;
			}
		}
		//如果当前任务是目标任务
		else if (pos == 0) {
			for (int i = front;i <= rear;i++) {
				if (que[front] < que[i]) {
					select = 1;
				}
			}
			//如果队列中有比当前任务优先级高的
			if (select == 1) {
				rear = enQueue(que, rear, que[front]);
				front = deQueue(que, front, rear);
				pos = rear - front - 1;
			}
			//如果队列中没有比当前任务优先级高的
			else if (select == 0) {
				front = deQueue(que, front, rear);
				pos--;
				count++;
			}
		}
	}
	return count;
}

int main()
{
	int que[SIZE];
	int front, rear;
	front = rear = 0;

	printf("Input the queue:");
	input(que, rear);

	printf("Input the position:");
	int plus;
	scanf("%d", &plus);
	int pos = front + plus - 1; //pos中存储目标任务在队列中的位置

	int count = caculate(que, front, rear, pos);
	printf("%d min\n", count);

	return 0;
}
