#include <stdio.h>

//函数定义
int and_gate(int bool1, int bool2);//与门
int or_gate(int bool1, int bool2);//或门
int nand_gate(int bool);//非门
int implication(int bool1, int bool2);//蕴含

//判案的逻辑电路模拟
int main(void) {

    int Q = 1;  int M = 1;  int P = 1;  int N = 1;
    int result = 0;
    int m_n = implication(M, nand_gate(N));//M→?N
    int p_q = implication(P, nand_gate(Q));//P→?Q
    int p_n = implication(nand_gate(P), N);//?P→N
    //Q∧(M→?N)∧(P→?Q)∧(?P→N)
    int first_half = and_gate(and_gate(Q, m_n), and_gate(p_q, p_n));
    //Q∧(M→?N)∧(P→?Q)∧(?P→N) ?M
    result = implication(first_half, M);

    if (result == 1) {
        printf("A盗窃了x");
    }
    else {
        printf("B盗窃了x");
    }

    return 0;

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

//非门
int nand_gate(int bool) {
    if (bool == 1) {
        return 0;
    }
    else {
        return 1;
    }
}

//蕴含
int implication(int bool1, int bool2) {
    if (bool1 == 1 && bool2 == 0) {
        return 1;
    }
    else {
        return 0;
    }
}