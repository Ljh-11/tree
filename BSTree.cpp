//
// Created by ���� on 2020/7/13.
//
#include <iostream>

/*
 * ����������
 */

//�������������
typedef struct BSTNode{
    int key;
    struct BSTNode * lchild, *rchild;
}BSTNode, * BSTree;

//�����������ķǵݹ�����㷨
BSTNode * BST_Search(BSTree T, int key) {
    while (T != nullptr && T->key != key) {
        if (key < T->key)
            T = T->lchild;
        else
            T = T->rchild;
    }

    return T;
}

//�����������ĵݹ�����㷨
BSTNode * BSTSearch(BSTree T, int key) {
    if (T == nullptr)
        return nullptr; //��������ʧ��

    if (key == T->key) {
        return T; //������Ϊ����㣬���ҳɹ�
    }
    else if (key < T->key) {
        return BSTSearch(T->lchild, key); //���������в���
    } else
        return BSTSearch(T->rchild, key); //���������в���

}

//�����������ķǵݹ�����㷨
int BST_Insert(BSTree & T, int k) {
    BSTree p = T, q = T;

    while (p != nullptr) {
        if (p->key == k) //���д�����ͬ�ؼ��ֵĽ�㣬����ʧ��
            return 0;

        q = p; //������������

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

//�����������ĵݹ�����㷨
int BSTInsert(BSTree & T, int k) {
    if (T == nullptr) {
        T = (BSTNode *) malloc(sizeof(BSTNode)); //ԭ��Ϊ�գ����²�����Ϊ�����
        T->key = k;
        T->lchild = nullptr;
        T->rchild = nullptr;

        return 1;
    }
    else if (k == T->key) { //���д�����ͬ�ؼ��ֵĽ�㣬����ʧ��
        return 0;
    }
    else if (k < T->key) {
        return BSTInsert(T->lchild, k);
    }
    else
        return BSTInsert(T->rchild, k);
}

//����һ�Ŷ���������
void Creat_BST(BSTree & T, int str[], int n) {
    T = nullptr; //��ʼʱTΪ����

    int i = 0;
    while (i < n) {
        BST_Insert(T, str[i]);//�ö����������ķǵݹ�����㷨���칹��
        i++;
    }
}

//���ʽ��
void visit(BSTree T) {
    printf("%d\t", T->key);
}

//��������������������ݹ飩
void PreOrder(BSTree T) {
    if (T != nullptr) {
        visit(T); //���ʸ����
        PreOrder(T->lchild); //����������
        PreOrder(T->rchild); //����������
    }
}

int main() {
    BSTree T; //����һ�Ŷ���������
    int str[] = {45, 24, 53, 45, 12, 24};
    int n = 6;
    Creat_BST(T, str, n);
    PreOrder(T);

    //printf("�ǵݹ���ң�%d\n", BST_Search(T, 53)->key); //�����������ǵݹ�����㷨
    //printf("�ݹ���ң�%d\n", BSTSearch(T, 5)->key); //�����������ݹ�����㷨

    //printf("%d\n",BST_Insert(T, 12)); //�����������ĵݹ�����㷨
    //printf("�ǵݹ���ң�%d\n", BST_Search(T, 12)->key); //�����������ǵݹ�����㷨

    return 0;
}

