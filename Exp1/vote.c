#include <stdio.h>

//���庯��
int vote (int vote1, int vote2, int vote3);
int and_gate (int bool1, int bool2);
int or_gate (int bool1, int bool2);

//ͶƱ������߼���·ģ��
int main(void){

    //��ʼ������
    int vote1, vote2, vote3; //������ͶƱ
    int result; //ͶƱ���

    //����ͶƱ���
    scanf("%d %d %d", &vote1, &vote2, &vote3);

    //����ͶƱ���
    result = vote(vote1, vote2, vote3);

    //���ͶƱ���
    if(result == 1){
        printf("ͨ��");
    }
    else{
        printf("��ͨ��");
    }

    return 0;
}

//����߼���·��ʵ�֣���Ʊ����ͨ��
int vote(int vote1, int vote2, int vote3){
    int final;
    //�߼����ʽ��(A��(B��C))��(B��C)
    final = or_gate(and_gate(vote1, or_gate(vote2, vote3)), and_gate(vote2, vote3));
    return final;
}
//����
int and_gate (int bool1, int bool2) {
    if(bool1==1 && bool2==1){
        return 1;
    }
    else{
        return 0;
    }
}

//����
int or_gate (int bool1, int bool2) {
    if(bool1==1 || bool2==1){
        return 1;
    }
    else{
        return 0;
    }
}

