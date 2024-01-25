/* BT3. Tạo file test.txt và ghi một đoạn dữ liệu bất kì. 
Thực hiện ghi ra màn hình các thông tin: Loại file, tên file, 
thời gian chỉnh sửa file lần cuối, kích thước. (Sử dụng struct stat) */

#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysmacros.h>

#define NAME "test.txt"

int main(int argc, char* argv[]) {
    char *file = NAME;
    struct stat des;
    stat(file, &des);

    int fd = open(NAME, O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR| S_IXUSR);
    if (fd > -1)
    {
        write(fd, "hung2098 la nhat", 4);
    }
    else
    {
        printf("Creating file in \"%s\" error!\n", NAME);
    }
    // struct stat des;
    // FILE *file = fopen(NAME, "r+");

    // if (argc != 2) {
    //     printf("Usage: %s <filename>\n", argv[0]);
    //     return 1;
    // }
    // char *filename = argv[1];
    printf("File name: %s\n", FILE_NAME);

    printf("Mode of file: ");
    switch (des.st_mode & S_IFMT) {
        case S_IFBLK:
        printf("Block special\n");
        break;

        case S_IFCHR:
        printf("Character special\n");
        break;

        case S_IFIFO:
        printf("FIFO special\n");
        break;

        case S_IFREG:
        printf("Regular\n");
        break;

        case S_IFDIR:
        printf("Directory\n");
        break;

        case S_IFLNK:
        printf("Smbolic link\n");
        break;

        case S_IFSOCK:
        printf("Socket\n");
        break;

        default:
        printf("Unkown?\n");
    }
    
    //printf("Size of file: ");
    printf("File size: %jd bytes\n", (intmax_t)des.st_size);

    printf("Last file status change timestamp: %s\n", ctime(&des.st_ctim.tv_sec));
    printf("Last data access timestamp:        %s\n", ctime(&des.st_atim.tv_sec));
    printf("Last data modification timestamp:  %s\n", ctime(&des.st_mtim.tv_sec));

    close(fd);
    return 0;
}
