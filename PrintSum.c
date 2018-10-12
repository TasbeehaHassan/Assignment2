#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
int main(){
	int arr[1000],t=0,totalSum=0;
	int p1[2],p2[2],p3[2],p4[2],p5[2],p6[2],p7[2],p8[2],p9[2],p10[2];
	for(int i=0;i<1000;i++){
		arr[i]=i;
	}
	if(pipe(p1)==-1){ printf("Pipe failed 1\n");
		return 0;
	}
	if(pipe(p2)==-1){ printf("Pipe failed 2\n");
		return 0;
	}
	if(pipe(p3)==-1){ printf("Pipe failed 3\n");
		return 0;
	}
	if(pipe(p4)==-1){ printf("Pipe failed 4\n");
		return 0;
	}
	if(pipe(p5)==-1){ printf("Pipe failed 5\n");
		return 0;
	}
	if(pipe(p6)==-1){ printf("Pipe failed 6\n");
		return 0;
	}
	if(pipe(p7)==-1){ printf("Pipe failed 7\n");
		return 0;
	}
	if(pipe(p8)==-1){ printf("Pipe failed 8\n");
		return 0;
	}
	if(pipe(p9)==-1){ printf("Pipe failed 9\n");
		return 0;
	}
	if(pipe(p10)==-1){ printf("Pipe failed 10\n");
		return 0;
	}
	int cpid1=fork();
	if(cpid1==0){ 
		for(int i=0;i<100;i++){
			t = t + arr[i];
		}
		write(p1[1],&t,sizeof(t));
		close(p1[1]);
		exit(0);
	}
	else{
		int cpid2=fork();
		if(cpid2==0){
			for(int i=100;i<200;i++){
				t = t + arr[i];
			}
			write(p2[1],&t,sizeof(t));
			close(p2[1]);
			exit(0);
		}
		else{
			int cpid3=fork();
			if(cpid3==0){
				for(int i=200;i<300;i++){
					t = t + arr[i];
				}
				write(p3[1],&t,sizeof(t));
				close(p3[1]);
				exit(0);
			}
			else{
				int cpid4=fork();
				if(cpid4==0){
					for(int i=300;i<400;i++){
						t = t + arr[i];
					}
					write(p4[1],&t,sizeof(t));
					close(p4[1]);	
					exit(0);
				}
				else{
					int cpid5=fork();
					if(cpid5==0){
						for(int i=400;i<500;i++){
							t = t + arr[i];
						}
						write(p5[1],&t,sizeof(t));
						close(p5[1]);
						exit(0);
					}
					else{
						int cpid6=fork();
						if(cpid6==0){
							for(int i=500;i<600;i++){
								t = t + arr[i];
							}
							write(p6[1],&t,sizeof(t));
							close(p6[1]);
							exit(0);
						}
						else{
							int cpid7=fork();
							if(cpid7==0){
								for(int i=600;i<700;i++){
									t = t + arr[i];
								}
								write(p7[1],&t,sizeof(t));
								close(p7[1]);
								exit(0);
							}
							else{
								int cpid8=fork();
								if(cpid8==0){
									for(int i=700;i<800;i++){
										t = t + arr[i];
									}
									write(p8[1],&t,sizeof(t));
									close(p8[1]);
									exit(0);
								}
								else{
									int cpid9=fork();
									if(cpid9==0){
										for(int i=800;i<900;i++){
											t = t + arr[i];
										}
										write(p9[1],&t,sizeof(t));
										close(p9[1]);
										exit(0);
									}
									else{
										for(int i=900;i<1000;i++){
											t = t + arr[i];
										}
										write(p10[1],&t,sizeof(t));
										close(p10[1]);
										wait(NULL);
									}
									wait(NULL);
								}
								wait(NULL);
							}
							wait(NULL);
						}
						wait(NULL);
					}
					wait(NULL);
				}
				wait(NULL);
			}
			wait(NULL);
		}
		wait(NULL);
	}
	read(p1[0],&t,sizeof(int));
	totalSum = totalSum + t;
	read(p2[0],&t,sizeof(int));
	totalSum = totalSum + t;
	read(p3[0],&t,sizeof(int));
	totalSum = totalSum + t;
	read(p4[0],&t,sizeof(int));
	totalSum = totalSum + t;
	read(p5[0],&t,sizeof(int));
	totalSum = totalSum + t;
	read(p6[0],&t,sizeof(int));
	totalSum = totalSum + t;
	read(p7[0],&t,sizeof(int));
	totalSum = totalSum + t;
	read(p8[0],&t,sizeof(int));
	totalSum = totalSum + t;
	read(p9[0],&t,sizeof(int));
	totalSum = totalSum + t;
	read(p10[0],&t,sizeof(int));
	totalSum = totalSum + t;
	printf("The Total Sum is = %d",totalSum);
	printf("\n\n");
	close(p1[0]);
	close(p2[0]);
	close(p3[0]);
	close(p4[0]);
	close(p5[0]);
	close(p6[0]);
	close(p7[0]);
	close(p8[0]);
	close(p9[0]);
	close(p10[0]);
	return 0;
}
