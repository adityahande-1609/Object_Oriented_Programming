#include<stdio.h>
#define MAX 5
int main()
{
	int queue[MAX],front,rear,a;
	front=rear=-1;
	while(1){
		printf("enter choice:\n1.add\n2.remove\n3display\n4.end");
		scanf("%d",&a);
		switch (a){
			case 1:
				if(rear==MAX-1){
					printf("queue overflow");
				}
				else if(front==-1||front>rear){
					front=rear=0;
					printf("enter value:");
					scanf("%d",&a);
					queue[rear]=a;
				}
				else{
					rear++;
					printf("enter value:");
					scanf("%d",&a);
					queue[rear]=a;
				}
				break;
			case 2:
				if(front==MAX-1||front>rear){
					printf("\nQUEUE UNDERFLOW");
				}
				else{
					printf("\nthe valuse removed is: %d",queue[front]);
					front++;
				}
				break;
			case 3:
				if(front==-1||front>rear){
					printf("\nqueue underflow");
				}
				else{
					printf("\nqueue is: ");
					for(int i=front;i<=rear;i++){
						printf("%d ",queue[i]);
					}
				}
				break;
			case 4:
				return 0;
			default:
				printf("INVALID");
		}
	}
}