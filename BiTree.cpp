//
// Created by 李金豪 on 2020/7/11.
//
#include <iostream>

//定义二叉链表结点结构体类型
typedef struct BiTNode {
    char data;
    struct BiTNode * lchild, * rchild;
}BiTNode, * BiTree;

//定义链队列结点结构体类型
typedef struct LinkNode{
    BiTNode * data; //存指针，而不是结点
    struct LinkNode * next;
}LinkNode;

//定义队头指针和队尾指针结构体类型
typedef struct {
    LinkNode * front; //队头指针
    LinkNode * rear; //队尾指针
    int length; //增加一个length变量以便于求队列长度
}LinkQueue;

//初始化根节点
bool InitRoot(BiTree & root) {
    root = (BiTree) malloc(sizeof(BiTNode));
    if (root == nullptr) //判断动态分配是否成功
        return false;

    root->data = '1';
    root->lchild = nullptr;
    root->rchild = nullptr;

    return true;
}

//初始化辅助队列
void InitQueue(LinkQueue & Q) {
    Q.front = nullptr;
    Q.rear = nullptr;
    Q.length = 0;
}

//入队
void EnQueue(LinkQueue & Q, BiTree T) {
    LinkNode * s = (LinkNode *) malloc(sizeof(LinkNode));
    s->data = T;
    s->next = nullptr;

    if (Q.front == nullptr) { //第一个结点入队时特殊操作
        Q.front = s;
        Q.rear = s;
    } else {
        Q.rear->next = s;
        Q.rear = s;
    }

    Q.length++;
}

//出队
bool DeQueue(LinkQueue & Q, BiTree & x) {
    if (Q.front == nullptr) { //判空
        return false;
    }

    LinkNode * p = Q.front;
    x = p->data;
    Q.front = p->next;

    if (p == Q.rear) { //如果删除的是最后一个结点，则删除后链表置空
        Q.rear = Q.front;
    }

    free(p);
    Q.length--;

    return true;
}

//判断队列是否为空
bool IsEmpty(LinkQueue Q) {
    if (Q.front == nullptr) { //无结点
        return true;
    }

    return false;
}

//插入结点
void NodeInsert(BiTree & T) {
    BiTNode * s1, * s2;
    s1 = (BiTNode *) malloc(sizeof(BiTNode));
    s2 = (BiTNode *) malloc(sizeof(BiTNode));
    s1->data = '2', s2->data = '3';
    s1->lchild = nullptr, s2->lchild = nullptr;
    s1->rchild = nullptr, s2->rchild = nullptr;
    T->lchild = s1; T->rchild = s2;
}

//遍历结点元素
void visit(BiTree p) {
    printf("%c\t", p->data);
}

//二叉树层次遍历算法
void LevelOrder(BiTree T) {
    LinkQueue Q;
    InitQueue(Q); //初始化辅助队列
    BiTree p;
    EnQueue(Q, T); //根节点入队

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
    BiTree T = nullptr; //定义一颗空树
    InitRoot(T);
    NodeInsert(T);

    LevelOrder(T);


    return 0;
}
