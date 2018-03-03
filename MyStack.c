//
//  MyStack.c
//  JPNavigationControllerDemo
//
//  Created by 邱弘宇 on 2018/3/3.
//  Copyright © 2018年 尹久盼. All rights reserved.
//

#include <stdlib.h>

typedef struct node *PNode;

typedef struct node{
    char *data;//数据
    PNode next;//下一节点的指针
}Node;

typedef struct stack{
    size_t size;//栈的大小
    PNode topNode;//栈顶指针
}*Stack;


/**
 初始化节点
 */
PNode initPNode(char *data){
    PNode node = (PNode)malloc(sizeof(PNode));
    node->data = data;
    node->next = NULL;
    return node;
}

/**
 销毁一个节点
 */
void deallocPNode(PNode node){
    node->data = NULL;
    node->next = NULL;
}

/**
 初始化栈-带参数
 */
Stack initStackWithPNode(PNode topNode){
    Stack stack = (Stack)malloc(sizeof(Stack));
    stack->topNode = topNode;
    if (topNode != NULL) {
        stack->size = 1;
    }
    return stack;
}

/**
 初始化栈-不带参数
 */
Stack initStack(){
    return initStackWithPNode(NULL);
}

/**
 销毁栈
 */
void deallocStack(Stack stack){
    while (stack->topNode != NULL) {
        PNode localTopNode = stack->topNode;
        PNode nextNode = localTopNode->next;
        deallocPNode(localTopNode);
        free(localTopNode);
        stack->topNode = nextNode;
    }
    stack->size = 0;
    free(stack);
}

/**
 入栈
 */
PNode pushStack(Stack stack,char *data){
    
    PNode pNode = NULL;
    size_t nodeSize = sizeof(Node);
    pNode = malloc(nodeSize);
    
    if (pNode != NULL) {
        pNode->data = data;
        pNode->next = stack->topNode;
        stack->size++;
        stack->topNode = pNode;
    }
    
    //返回当前栈顶元素
    return pNode;
}

/**
 出栈
 @param stack Stack struct
 @return 返回当前栈顶元素
 */
PNode popStack(Stack stack){
    
    if (stack->size > 0) {
        PNode popNode = NULL;
        popNode = stack->topNode;
        stack->size--;
        stack->topNode = popNode->next;
        if (popNode != NULL) {
            free(popNode);
        }
    }
    else{
        return NULL;
    }
    
    //返回当前栈顶元素
    return stack->topNode;
    
}
