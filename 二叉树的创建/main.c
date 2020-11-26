#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
    char data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
}TreeNode;
typedef TreeNode * pTreeNode;
void preOrder(TreeNode *T) {    //先序遍历的非递归
    TreeNode *stack[15];
    int top = -1;
    TreeNode *p = T;
    while (p != NULL || top != -1) {
        if (p != NULL) {
            stack[++top] = p;
            printf ("%d\t", p->data);
            p = p->lchild;
        } else {
            p = stack[top--];
            p = p->rchild;
        }
    }
}
void postOrder(pTreeNode Tree) {   //后序遍历
    if (NULL != Tree) {
        postOrder(Tree->lchild);
        postOrder(Tree->rchild);
        printf ("%c", Tree->data);
    }
}
void floorOrder(pTreeNode Tree) {
    pTreeNode temp[100];
    int in = 0, out = 0;
    temp[in++] = Tree;
    while (in > out) {
        if (temp[out]) {
            printf("%c", temp[out]->data);
            temp[in++] = temp[out]->lchild;
            temp[in++] = temp[out]->rchild;
        }
        out++;
    }
}
void initTreeNode(pTreeNode *Tree) {
    *Tree = NULL;
}
void creatBinTree(pTreeNode *Tree) {
    char ch;
    ch = getchar();
    if (ch == '#') {
        *Tree = NULL;
    } else {
        *Tree = (pTreeNode)malloc(sizeof(pTreeNode));
        if (NULL == (*Tree)) {
            exit(0);
        } else {
            (*Tree)->data = ch;
            (*Tree)->lchild = NULL;
            (*Tree)->rchild = NULL;
            creatBinTree(&(*Tree)->lchild);
            creatBinTree(&(*Tree)->rchild);
        }
    }
}
void test() {
    pTreeNode T;
    initTreeNode(&T);
    creatBinTree(&T);
    floorOrder(T);
}
int main () {
    test();
    return 0;
}
