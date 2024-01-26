/*BT4. Viết một chương trình mở một file bất kì và sử dụng cờ O_APPEND, 
sau đó thực hiện seek về đầu file rồi ghi một vài dữ liệu vào file đó. 
Dữ liệu sẽ xuất hiện ở vị trí nào của file và tại sao lại như vậy?*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <fcntl.h>

#define NAME "hello.txt"

int main(int argc, char* argv[]) {
    char* file = NAME;
    int fd = open(NAME, O_CREAT | O_WRONLY, 0777);
    
    if (fd == -1) {
        perror("Cannot open this file.\n");
        exit(EXIT_FAILURE);
    } else if (fd > 0) {
        //off_t lseek(int fd, off_t offset, int whence);
        lseek(fd, 0, SEEK_SET);
        write(fd, "hung2098 la nhat\n", 17);
    }

    close(fd);
    return 0;
}

/* Cờ O_APPEND sẽ bắt dữ liệu ghi vào ở cuối file thay vì ghi đè lên
   Nếu bỏ cờ này thì dữ liệu sẽ thêm vào đầu
*/