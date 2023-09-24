CC=clang

danhSach = dienTheDongDien.o NamChamHinhTru.o NamChamHinhHop.o DongDienHinhTron.o DongDienPhanHinhTron.o\
NhapThongTin.o MoPhong.o SVG.o SoDo.o SoDoHinhChuNhat.o SoDoHinhVuong.o PhatThongTin.o

dienTheDongDien: $(danhSach)
	$(CC) -o dienTheDongDien -lm $(danhSach)

# ==== hàm main() tại đây
dienTheDongDien.o: dienTheDongDien.c
	$(CC) -c dienTheDongDien.c

# ==== Những nam châm
NamChamHinhTru.o: NamCham/NamChamHinhTru.c NamCham/NamChamHinhTru.h
	$(CC) -c NamCham/NamChamHinhTru.c

NamChamHinhHop.o: NamCham/NamChamHinhHop.c NamCham/NamChamHinhHop.h
	$(CC) -c NamCham/NamChamHinhHop.c

# ==== Những dòng điện
DongDienHinhTron.o: DongDien/DongDienHinhTron.c DongDien/DongDienHinhTron.h
	$(CC) -c DongDien/DongDienHinhTron.c

DongDienPhanHinhTron.o: DongDien/DongDienPhanHinhTron.c DongDien/DongDienPhanHinhTron.h
	$(CC) -c DongDien/DongDienPhanHinhTron.c

# ==== Mô Phỏng
MoPhong.o: MoPhong.c MoPhong.h
	$(CC) -c MoPhong.c

# ==== Nhập Thông Tin
NhapThongTin.o: NhapThongTin.c NhapThongTin.h
	$(CC) -c NhapThongTin.c

// ==== cho vẽ sơ đồ
SVG.o: SVG.c SVG.h
	$(CC) -c SVG.c

SoDo.o: SoDo/SoDo.c soDo/SoDo.h
	$(CC) -c SoDo/SoDo.c

SoDoHinhChuNhat.o: SoDo/SoDoHinhChuNhat.c SoDo/SoDoHinhChuNhat.h
	$(CC) -c SoDo/SoDoHinhChuNhat.c

SoDoHinhVuong.o: SoDo/SoDoHinhVuong.c SoDo/SoDoHinhVuong.h
	$(CC) -c SoDo/SoDoHinhVuong.c

PhatThongTin.o: SoDo/PhatThongTin.c SoDo/PhatThongTin.h
	$(CC) -c SoDo/PhatThongTin.c

# ==== LÀM SẠCH
clean:	
	rm $(danhSach)