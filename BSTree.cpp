//
// Created by 李金豪 on 2020/7/13.
//
#include <iostream>

/*
 * 二叉排序树
 */

//二叉排序树结点
typedef struct BSTNode{
    int key;
    struct BSTNode * lchild, *rchild;
}BSTNode, * BSTree;

//二叉排序树的非递归查找算法
BSTNode * BST_Search(BSTree T, int key) {
    while (T != nullptr && T->key != key) {
        if (key < T->key)
            T = T->lchild;
        else
            T = T->rchild;
    }

    return T;
}

//二叉排序树的递归查找算法
BSTNode * BSTSearch(BSTree T, int key) {
    if (T == nullptr)
        return nullptr; //空树查找失败

    if (key == T->key) {
        return T; //所查结果为根结点，查找成功
    }
    else if (key < T->key) {
        return BSTSearch(T->lchild, key); //在左子树中查找
    } else
        return BSTSearch(T->rchild, key); //在又子树中查找

}

//二叉排序树的非递归插入算法
int BST_Insert(BSTree & T, int k) {
    BSTree p = T, q = T;

    while (p != nullptr) {
        if (p->key == k) //树中存在相同关键字的结点，插入失败
            return 0;

        q = p; //便于链接子树

        if (k < p->key) {
            p = p->lchild;
        } else
            p = p->rchild;

    }

    if (T == nullptr) {
        T = (BSTNode *) malloc(sizeof(BSTNode));
        T->key = k;
        T->lchild = nullptr, T->rchild = nullptr;
        return 1;
    } else {
        p = (BSTNode *) malloc(sizeof(BSTNode));
        p->key = k;
        p->lchild = nullptr, p->rchild = nullptr;

        if (k < q->key) {
            q->lchild = p;
        } else
            q->rchild = p;

        return 1;
    }
}

//二叉排序树的递归插入算法
int BSTInsert(BSTree & T, int k) {
    if (T == nullptr) {
        T = (BSTNode *) malloc(sizeof(BSTNode)); //原树为空，则新插入结点为根结点
        T->key = k;
        T->lchild = nullptr;
        T->rchild = nullptr;

        return 1;
    }
    else if (k == T->key) { //树中存在相同关键字的结点，插入失败
        return 0;
    }
    else if (k < T->key) {
        return BSTInsert(T->lchild, k);
    }
    else
        return BSTInsert(T->rchild, k);
}

//构造一颗二叉排序树
void Creat_BST(BSTree & T, int str[], int n) {
    T = nullptr; //初始时T为空树

    int i = 0;
    while (i < n) {
        BST_Insert(T, str[i]);//用二叉排序树的非递归插入算法构造构造
        i++;
    }
}

//访问结点
void visit(BSTree T) {
    printf("%d\t", T->key);
}

//先序遍历二叉排序树（递归）
void PreOrder(BSTree T) {
    if (T != nullptr) {
        visit(T); //访问根结点
        PreOrder(T->lchild); //访问左子树
        PreOrder(T->rchild); //访问右子树
    }
}

int main() {
    BSTree T; //构造一颗二叉排序树
    int str[] = {45, 24, 53, 45, 12, 24};
    int n = 6;
    Creat_BST(T, str, n);
    PreOrder(T);

    //printf("非递归查找：%d\n", BST_Search(T, 53)->key); //二叉排序树非递归查找算法
    //printf("递归查找：%d\n", BSTSearch(T, 5)->key); //二叉排序树递归查找算法

    //printf("%d\n",BST_Insert(T, 12)); //二叉排序树的递归插入算法
    //printf("非递归查找：%d\n", BST_Search(T, 12)->key); //二叉排序树非递归查找算法

    return 0;
}

