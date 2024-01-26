# Exercise 5. 
## Viết một chương trình A tạo ra một tiến trình con B rồi in ra PID và PPID của chúng.

### Nhắc lại đối số
Chuyển đổi đối số từ dạng chuỗi thành số nguyên trước khi tính toán tổng
int num1 = atoi(argv[1]);
int num2 = atoi(argv[2]);
Tính tổng và in ra kết quả
printf("Tong 2 doi so la: %d\n", num1 + num2);

### PID
Nếu PID == 0 thì là process con.
Nếu PID > 0 thì là process cha.
Nếu không thì tiến trình không được tạo thành công.

# Exercise 6. 
Viết một chương trình A tạo ra một tiến trình con B, in ra PID và PPID của chúng.  Sử dụng system waitpid() để lấy được trạng thái kết thúc của tiến con B.

# Exercise 7. 
Từ kiến thức đã học, sử dụng SIGCHLD để ngăn ngừa việc hình thành zombie process.
