//
// Created by ���� on 2020/7/11.
//
#include <iostream>

//�������������ṹ������
typedef struct BiTNode {
    char data;
    struct BiTNode * lchild, * rchild;
}BiTNode, * BiTree;

//���������н��ṹ������
typedef struct LinkNode{
    BiTNode * data; //��ָ�룬�����ǽ��
    struct LinkNode * next;
}LinkNode;

//�����ͷָ��Ͷ�βָ��ṹ������
typedef struct {
    LinkNode * front; //��ͷָ��
    LinkNode * rear; //��βָ��
    int length; //����һ��length�����Ա�������г���
}LinkQueue;

//��ʼ�����ڵ�
bool InitRoot(BiTree & root) {
    root = (BiTree) malloc(sizeof(BiTNode));
    if (root == nullptr) //�ж϶�̬�����Ƿ�ɹ�
        return false;

    root->data = '1';
    root->lchild = nullptr;
    root->rchild = nullptr;

    return true;
}

//��ʼ����������
void InitQueue(LinkQueue & Q) {
    Q.front = nullptr;
    Q.rear = nullptr;
    Q.length = 0;
}

//���
void EnQueue(LinkQueue & Q, BiTree T) {
    LinkNode * s = (LinkNode *) malloc(sizeof(LinkNode));
    s->data = T;
    s->next = nullptr;

    if (Q.front == nullptr) { //��һ��������ʱ�������
        Q.front = s;
        Q.rear = s;
    } else {
        Q.rear->next = s;
        Q.rear = s;
    }

    Q.length++;
}

//����
bool DeQueue(LinkQueue & Q, BiTree & x) {
    if (Q.front == nullptr) { //�п�
        return false;
    }

    LinkNode * p = Q.front;
    x = p->data;
    Q.front = p->next;

    if (p == Q.rear) { //���ɾ���������һ����㣬��ɾ���������ÿ�
        Q.rear = Q.front;
    }

    free(p);
    Q.length--;

    return true;
}

//�ж϶����Ƿ�Ϊ��
bool IsEmpty(LinkQueue Q) {
    if (Q.front == nullptr) { //�޽��
        return true;
    }

    return false;
}

//������
void NodeInsert(BiTree & T) {
    BiTNode * s1, * s2;
    s1 = (BiTNode *) malloc(sizeof(BiTNode));
    s2 = (BiTNode *) malloc(sizeof(BiTNode));
    s1->data = '2', s2->data = '3';
    s1->lchild = nullptr, s2->lchild = nullptr;
    s1->rchild = nullptr, s2->rchild = nullptr;
    T->lchild = s1; T->rchild = s2;
}

//�������Ԫ��
void visit(BiTree p) {
    printf("%c\t", p->data);
}

//��������α����㷨
void LevelOrder(BiTree T) {
    LinkQueue Q;
    InitQueue(Q); //��ʼ����������
    BiTree p;
    EnQueue(Q, T); //���ڵ����

    while (!IsEmpty(Q)) {
        DeQueue(Q, p);
        visit(p);
        if (p->lchild != nullptr)
            EnQueue(Q, p->lchild);

        if (p->rchild != nullptr)
            EnQueue(Q, p->rchild);
    }
}


int main() {
    BiTree T = nullptr; //����һ�ſ���
    InitRoot(T);
    NodeInsert(T);

    LevelOrder(T);


    return 0;
}
