/*
Viết một chương trình thực hiện tạo 2 threads. Cả hai threads này đều dùng chung một handler.
Kiểm tra nếu là thread1 đang thực hiện thì in ra thông điệp bất kì để xác định. 
Nếu là thread2 thì truyền vào dữ liệu kiểu struct human được khởi tạo từ trước, 
với các thông tin: Họ tên, năm sinh, sdt, quê quán. 
Sau đó in các thông tin này ra màn hình.
*/

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>

pthread_t thread_id1, thread_id2;

typedef struct {
    char name[20];
    char phonenumber[11];
    char birth[5];
    char city[20];
} human;

static void *thread_handler(void* args) {
    pthread_t thr_id = pthread_self();
    human *data = (human*) args;

    if (pthread_equal(thr_id, thread_id1)) {
        printf("I'm thread id 1.\n");
    } else if (pthread_equal(thr_id, thread_id2)) {
        printf("I'm thread id 2.\n");
        printf("Name: \n");
        printf("%s\n", data->name);
        printf("Nam sinh: \n");
        printf("%s\n", data->birth);
        printf("Phone number: \n");
        printf("%s\n",data->phonenumber);
        printf("City: \n");
        printf("%s", data->city);
    }
    //return 0;
}

int main(int argc, const char* argv[]) {
    int ret;
    human data = {0};

    strncpy(data.name, "hung2098", sizeof(data.name));                 
    strncpy(data.birth, "2003", sizeof(data.birth));
    strncpy(data.phonenumber, "0936904xxx", sizeof(data.phonenumber));                 
    strncpy(data.city, "HungYen", sizeof(data.city));

    if (ret = pthread_create(&thread_id1, NULL, &thread_handler, NULL)) {
        printf("pthread_create() error number = %d\n", ret);
        return -1;
    }
    sleep(2);

    if (ret = pthread_create(&thread_id2, NULL, &thread_handler, &data)) {
        printf("pthread_create() error number = %d\n", ret);
        return -1;
    }

    sleep(2);

    return 0;
}                 

