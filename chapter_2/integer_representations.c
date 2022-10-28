#include <stdio.h>
#include <string.h>

// typedef将byte_pointer定义为指向一个char类型的指针
typedef unsigned char *byte_pointer;

//接受一个指向char类型的指针，并打印这个指针指向的内容，和后几位的内容
void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

//将x的地址转换为指向x地址中的第一个地址，并非是x这个对象的地址，如果x是int类型，第8行的
//for循环就会四个字节进行执行
void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}


//输出指针的大小
void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val) {
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

void inplace_swap(int *x, int *y) {
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

void reverse_array(int a[], int cnt) {
    int first, last;
    for (first = 0, last = cnt - 1;
         first < last;
         first++, last--
            )
        inplace_swap(&a[first],&a[last]);
}

int main() {
    int x = 0x87654321;
    int y = x^0xffffff00;
    printf("%x",y);
}