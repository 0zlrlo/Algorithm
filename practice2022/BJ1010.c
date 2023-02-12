#include <stdio.h>
double factorial(int k){
    if(k==0||k==1){
        return 1;
    }
    else{
        return k*factorial(k-1);
    }
}
double result(int m, int n){  //이거 넣는 거 n, m 순서로 넣으면 안된다.
    return factorial(m)/(factorial(m-n)*factorial(n));
}
int main(void){
    int num, n, m;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%d %d",&n ,&m);
        printf("%.lf\n",result(m,n)); //이거 넣는 거 n, m 순서로 넣으면 안된다.
        //%f는 float형의 실수로 입력. %lf는 double형의 실수로 입력
    }
    return 0;
}