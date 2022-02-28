#include <stdio.h>
int f();
int i(){
    printf("hellow world");
    puts("hello world");
    return 0;
}

int h(){
    f();
    printf("hello world");
    printf("hello world");
    i();
    return 0;
}

int g(){
    h();
    puts("hello world");
    puts("hello");
    return 0;
}

int f(){
    g();
    g();
    h();
    return 0;
}

int main(){
    f();
    return 0;
}