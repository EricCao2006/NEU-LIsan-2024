#include <stdio.h>

//定义函数
int vote (int vote1, int vote2, int vote3);
int and_gate (int bool1, int bool2);
int or_gate (int bool1, int bool2);

//投票表决的逻辑电路模拟
int main(void){

    //初始化变量
    int vote1, vote2, vote3; //共三人投票
    int result; //投票结果

    //输入投票结果
    scanf("%d %d %d", &vote1, &vote2, &vote3);

    //计算投票结果
    result = vote(vote1, vote2, vote3);

    //输出投票结果
    if(result == 1){
        printf("通过");
    }
    else{
        printf("不通过");
    }

    return 0;
}

//表决逻辑电路的实现，两票以上通过
int vote(int vote1, int vote2, int vote3){
    int final;
    //逻辑表达式：(A∧(B∨C))∨(B∧C)
    final = or_gate(and_gate(vote1, or_gate(vote2, vote3)), and_gate(vote2, vote3));
    return final;
}
//与门
int and_gate (int bool1, int bool2) {
    if(bool1==1 && bool2==1){
        return 1;
    }
    else{
        return 0;
    }
}

//或门
int or_gate (int bool1, int bool2) {
    if(bool1==1 || bool2==1){
        return 1;
    }
    else{
        return 0;
    }
}

