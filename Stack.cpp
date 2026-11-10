#include<stdio.h>
int main(){
	int n;
	printf("enter the number of elements :");
	scanf("%d",&n);
	int arr[n],i,a,top=-1;
    while(1){
		printf("choose a option: \n1.add\n2.remove \n3.display\n4.exit");
	    scanf("%d",&a);
		switch (a){
			case 1:
				if(top==n-1){
				printf("stack overflow");
			}
			else{
				top++;
				printf("enter the value:");
				scanf("%d",&arr[top]);
			}
				break;
			case 2:
				if(top==(-1)){
				printf("stack underflow:");
			}
			else{
				printf("value removed:%d",arr[top]);
				top--;
			}
				break;
		case 3:
			if(top==(-1)){
				printf("stack undeflow");
				}
			else{
				printf("the stack is : ");
				for(i=top;i>=0;i--){
					printf("%d ",arr[i]);
				}
				}
			break;
		case 4:
			return 0;
		default:
			printf("invalid value");
		}
		}
     return 0;
}