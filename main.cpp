#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode{
    ElemType data;//数据域
    struct LNode* next;//指针域 用于指向下一个节点
}LNode,*LinkList;
//LNode*和LinkList完全等价

//头插法新建链表
void list_head_insert(LNode* &L){
    //带头结点的链表
    L=(LNode*)malloc(sizeof(LNode));//申请头结点空间，头指针指向头节点
    L->next=NULL;//L->data中没放数据
    ElemType x;
    scanf("%d",&x);//从标准输入读取数据
    LNode* s;//用来指向申请的新节点
//    s=(LinkList) malloc(sizeof(LNode));
//    s->data=x;
//    s->next=NULL;
//    L->next=s;//头结点的next指向第一个节点
    while(x!=9999){
//        scanf("%d",&x);
        s=(LinkList)malloc(sizeof(LNode));//申请一个新空间给s，强制类型转换
        s->data=x;//把读取到的值，给新空间中的data成员
        s->next=L->next;//s的next指向原链表的第一个结点，让新节点的next指针指向链表的第一个元素
        L->next=s;//头结点的next指针，指向新结点 让s作为第一个元素
        scanf("%d",&x);//读取标准输入
    }

}
//打印链表中每个结点的值
void print_list(LinkList L){
    L=L->next;
    while(L!=NULL){//NULL是为了代表一张空的藏宝图
       printf("%3d",L->data);//打印当前节点的数据
       L=L->next;//指向下一个结点
    }
}

int main() {

    LinkList L;//链表头指针，是结构体指针类型
    list_head_insert(L);//输入数据可以是3 4 5 6 7 9999，头插法新建链表
    print_list(L);
    return 0;
}
