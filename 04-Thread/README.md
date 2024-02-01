# Exercise 10 
Cung một ví dụ mà multi-thread không cung cấp hiệu suất tốt hơn các giải pháp single-thread

# Exercise 11 
## Viết một chương trình thực hiện tạo 2 threads. Cả hai threads này đều dùng chung một handler.
    Kiểm tra nếu là thread1 đang thực hiện thì in ra thông điệp bất kì để xác định. 
    Nếu là thread2 thì truyền vào dữ liệu kiểu struct human được khởi tạo từ trước, với các thông tin: Họ tên, năm sinh, sdt, quê quán. Sau đó in các thông tin này ra màn hình.

### Tạo một thread mới
    
    int pthread_creat(pthread_t *threadID, pthread_attr_t *attr, void *(*start)(void *), void *args);

    Đối số đầu tiên : Một khi tiến trình được gọi thành công, đối số đầu tiên sẽ giữ thread ID của thread mới được tạo.

    Đối số thứ hai : Thông thường giá trị này đặt thành NULL.

    Đối số thứ ba : Là một con trỏ hàm (function pointer) . Mỗi một thread sẽ chạy riêng một function, địa chỉ của function này sẽ được truyền tại đối số thứ ba để linux biết được thread này bắt đầu chạy từ đâu.

    Đối số thứ tư : Đối sô arg được truyền vào có kiểu void, điều này cho phép ta truyền bất kì kiểu dữ liệu nào vào hàm xử lý của thread. Hoặc giá trị này có thể là NULL nếu ta không muốn truyền bất cứ đối số nào. Điều này sẽ được thể hiện rõ ràng hơn trong ví dụ dưới đây.


### So sánh threadID
    int pthread_equal(pthread_t tid1, pthread_t tid2);

### Lấy thread ID
    pthread_t pthread_self(void);

### Giải phóng tài nguyên 
    int pthread_join(pthread_t thread_id, NULL);
    Được dùng để chờ một luồng (thread) khác kết thúc thực thi trước khi luồng gọi pthread_join() tiếp tục thực thi. 
    Nếu ta không quan tâm giá trị trả về thì sẽ để NULL

# Exercise 12
## Viết một chương trình thực hiện tạo 3 threads.
    Thread 1: Thực hiện việc nhập dữ liệu sinh viên từ bàn phím, bao gồm thông tin: Họ tên, ngày sinh, quê quán.

    Thread2: Mỗi lần nhập xong dữ liệu một sinh viên, thread này sẽ ghi thông tin sinh viên đó vào file (mỗi thông tin sinh viên nằm trên 1 dòng) thongtinsinhvien.txt.

    Thread3: Đọc dữ liệu vừa ghi được và in ra màn hình sau đó thông báo cho thread 1 tiếp tục nhập thêm sinh viên.

    Sử dụng mutex và condition variable để giải quyết bài toán.
