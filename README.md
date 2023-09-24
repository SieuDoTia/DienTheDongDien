# DienTheDongDien
Chương trình cho làm mô phỏng điện thế từ nam châm. 

# Cách sử dụng
Tải xuống, bỏ vào hồ sơ và gõ 'make' để biên dịch nó.

Xong rồi tại một tệp tin có tham số cho mô phỏng và gõ

 ./dienTheDongDien <tên tập tin chứa tham số mô phỏng>

# Những tham số cho tạo tập tin chứa tham số mô phỏnng
Những ký hiệu cho tập tin:

##  P - Phiêu bản:

  X - XUẤT TẬP TIN:
    t - tộp tin xuất, có hai loại: tập tin bảng số 'b' và tập tin SVG 's'

  N - NAM CHÂM:
    l - loại nam châm, có hai loại: hình trụ 't' và hình hộp 'h'
  Tham số cho nam châm HÌNH TRỤ
    bk - bán kính ban châm (mm)
    cc - chiều cao nam châm (mm)
    dc - độ cao đo từ mặt phảng dòng điện (mm)
    kc - khoảng cách từ trung tam xoay (mm)
    sl - số lượng nam châm trên rôtor

  Tham số cho nam châm HÌNH HỘP
    cc - chiều cao nam châm (mm)
    cd - chiều dài nam châm (mm)
    cr - chiều rộng nam châm (mm)
    dc - độ cao đo từ mặt phảng dòng điện (mm)
    kc - khoảng cách từ trung tam xoay (mm)
    sl - số lượng nam châm trên rôtor


  D - dòng điện:
    l - loại dòng điện, có hai loại: phần hình tròn 'p' và hình tròn 't'
  Tham số cho dòng điện PHẦN HÌNH TRÒN
    b1 - bán nội (mm)
    b2 - bán kính ngoại (mm)
    cr - chiều rộng góc (radian)
    sl - số lượng dòng điện

  Tham số cho dòng điện HÌNH TRÒN
    bk - bán kính (mm)
    kc - khoảng cách từ trung tam xoay (mm)
    sl - số lượng dòng điện
