# Exercise 10 
Cung một ví dụ mà multi-thread không cung cấp hiệu suất tốt hơn các giải pháp single-thread

# Exercise 11 
## Viết một chương trình thực hiện tạo 2 threads. Cả hai threads này đều dùng chung một handler.
    Kiểm tra nếu là thread1 đang thực hiện thì in ra thông điệp bất kì để xác định. 
    Nếu là thread2 thì truyền vào dữ liệu kiểu struct human được khởi tạo từ trước, với các thông tin: Họ tên, năm sinh, sdt, quê quán. Sau đó in các thông tin này ra màn hình.

# Exercise 12
## Viết một chương trình thực hiện tạo 3 threads.
    Thread 1: Thực hiện việc nhập dữ liệu sinh viên từ bàn phím, bao gồm thông tin: Họ tên, ngày sinh, quê quán.
    Thread2: Mỗi lần nhập xong dữ liệu một sinh viên, thread này sẽ ghi thông tin sinh viên đó vào file (mỗi thông tin sinh viên nằm trên 1 dòng) thongtinsinhvien.txt.
    Thread3: Đọc dữ liệu vừa ghi được và in ra màn hình sau đó thông báo cho thread 1 tiếp tục nhập thêm sinh viên.
    Sử dụng mutex và condition variable để giải quyết bài toán.
