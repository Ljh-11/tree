//
// Created by 李金豪 on 2020/7/12.
//
#include <iostream>

/*
 * 构造线索二叉树
 */

//定义线索二叉树结点结构体类型
typedef struct ThreadNode {
    char data;
    struct ThreadNode * lchild, * rchild;
    int ltag, rtag; //左右线索标志
}ThreadNode, * ThreadTree;

//定义全局变量
ThreadNode * pre = nullptr;

void InitThreadTree(ThreadTree & T) {
    T = (ThreadNode *) malloc(sizeof(ThreadNode));
    T->data = '1';
    T->lchild = nullptr, T->rchild = nullptr;
    T->ltag = 0; T->rtag = 0;
}

//插入结点
void NodeInsert(ThreadTree & T) {
    ThreadNode * s1, * s2;
    s1 = (ThreadNode *) malloc(sizeof(ThreadNode));
    s2 = (ThreadNode *) malloc(sizeof(ThreadNode));
    s1->data = '2', s2->data = '3';
    s1->lchild = nullptr, s2->lchild = nullptr;
    s1->rchild = nullptr, s2->rchild = nullptr;
    s1->ltag = 0, s1->rtag = 0; s2->ltag = 0, s2->rtag = 0;
    T->lchild = s1; T->rchild = s2;
}

//遍历结点元素
void visit(ThreadNode * p) {
    if (p->lchild == nullptr) { //左子树为空，建立前驱线索
        p->lchild = pre;
        p->ltag = 1;
    }
    if (pre != nullptr && pre->rchild == nullptr) {
        pre->rchild = p; //建立前驱结点的后继结点
        pre->rtag = 1;
    }

    pre = p;
}

//中序遍历二叉树，一边遍历一边线索化
void InThread(ThreadTree T) {
    if (T != nullptr) {
        InThread(T->lchild);
        visit(T);
        InThread(T->rchild);
    }
}

//中序线索化二叉树T
void  CreatInThread(ThreadTree T) { //这里传入T而不是引用T是因为T已事先被初始化为一颗非空二叉树
    pre = nullptr;

    if (T != nullptr) { //非空二叉树才能线索化
        InThread(T); //中序线索化二叉树
        if (pre->rchild == nullptr)
            pre->rtag = 1; //处理遍历的最后一个结点
    }

}

/*
 * 在已经实现中序线索化的二叉树中找前驱和后继结点
 */

//求中序线索二叉树中中序序列下的第一个结点
ThreadNode * Firstnode(ThreadNode * p) {
    while (p->ltag == 0)
        p = p->lchild;

    return p;
}

//求中序线索二叉树中结点p在中序序列下的后继结点
ThreadNode * Nextnode(ThreadNode * p) {
    if (p->rtag == 0)
        return Firstnode(p->rchild);
    else
        return p->rchild; //rtag == 1直接返回后继线索

}

//找到p为根的子树中，最后一个被中序遍历的结点
ThreadNode * Lastnode(ThreadNode * p) {
    while (p->rtag == 0) {
        p = p->rchild;
    }

    return p;
}

//在中序线索二叉树中找到结点p的前驱结点
ThreadNode * Prenode(ThreadNode * p) {
    if (p->ltag == 0)
        return Lastnode(p->lchild);
    else
        return p->lchild;
}

int main() {
    ThreadTree T;
    InitThreadTree(T);
    NodeInsert(T);




    return 0;
}