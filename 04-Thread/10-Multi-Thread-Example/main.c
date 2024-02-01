/*
Cung một ví dụ mà multi-thread không cung cấp 
hiệu suất tốt hơn các giải pháp single-thread
*/

#include <stdio.h>
#include <stdlib.h>

// Hàm so sánh để sử dụng với qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n = 1000000;
    int *data = malloc(n * sizeof(int));

    // Tạo một mảng ngẫu nhiên
    for (int i = 0; i < n; i++) {
        data[i] = rand() % 20001 - 10000;  // Số ngẫu nhiên trong khoảng [-10000, 10000]
    }

    // Sắp xếp mảng sử dụng một luồng
    qsort(data, n, sizeof(int), compare);

    free(data);
    return 0;
}

/*
Trong đoạn mã trên, chúng ta sử dụng hàm `qsort` của thư viện chuẩn C để sắp xếp mảng. 
Hàm này chỉ sử dụng một luồng và thường rất nhanh.

Tuy nhiên, việc sắp xếp mảng sử dụng nhiều luồng trong ngôn ngữ C đòi hỏi phải sử dụng 
các API đa luồng như pthreads và việc lập trình đa luồng có thể trở nên phức tạp. 
Ngoài ra, như đã nói ở trên, việc sắp xếp mảng sử dụng nhiều luồng không nhất thiết 
sẽ nhanh hơn việc sử dụng một luồng, đặc biệt là khi kích thước mảng không lớn. 
Vì vậy, việc sử dụng đa luồng cần được cân nhắc kỹ lưỡng dựa trên bài toán cụ thể.
*/