#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

//栈大小
#define N 1000
/*
栈结构，用于AC自动机回溯的时候输出关键字
*/
struct stack {
    //栈顶
    int top;
    unsigned char data[N];
};

//-1代表栈中没有元素，{0}将数组全部初始化为0
struct stack mystack= {
    -1,{0}
};


int isempty() {
    if(mystack.top==-1) {
        return 1;
    } else {
        return 0;
    }
}

void setempty() {
    mystack.top=-1;
}

int push(unsigned char data) {
    if(mystack.top+1<=N-1) {//没有溢出
        mystack.data[++mystack.top]=data;
        return 1;
    } else {
        printf("##Error##栈溢出了");
        return 0;
    }
}

//把当前栈中的数据反向的拿出来

unsigned char returnArr[500];
unsigned char* toString(){
    if(isempty())
        return NULL;
    //unsigned char* returnArr;
    //returnArr=(unsigned char*)malloc(sizeof(unsigned char)*((mystack.top+1)));
    int i=mystack.top,j=0;

   //printf("top=%d\n",mystack.top);

    while(i>=0){
        returnArr[j++]=mystack.data[i--];
    }
    returnArr[j]='\0';

   // printf("returnArr:%s\n",returnArr);
    return returnArr;
}

int getSize(){
    return mystack.top;
}


#endif // STACK_H_INCLUDED
