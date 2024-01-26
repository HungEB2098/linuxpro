# Exercise 4. 
Viết một chương trình mở một file bất kì và sử dụng cờ O_APPEND, 
sau đó thực hiện seek về đầu file rồi ghi một vài dữ liệu vào file đó. 
Dữ liệu sẽ xuất hiện ở vị trí nào của file và tại sao lại như vậy?

## O_APPEND

The file is opened in append mode.  Before each write(2),
the file offset is positioned at the end of the file, as
if with lseek(2).  The modification of the file offset and 
the write operation are performed as a single atomic step.

O_APPEND may lead to corrupted files on NFS filesystems if
more than one process appends data to a file at once.
This is because NFS does not support appending to a file,
so the client kernel has to simulate it, which can't be
done without a race condition.

--> mở một tập tin để chỉ định rằng mọi dữ liệu mới được ghi vào tập tin sẽ được thêm vào cuối của tập tin, thay vì ghi đè lên dữ liệu hiện có.

## LSEEK
#include <unistd.h>

off_t lseek(int fd, off_t offset, int whence);
