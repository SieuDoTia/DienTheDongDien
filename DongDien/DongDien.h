/* DòngĐiện.h */
// 2023.09.21


#pragma once

#include "DongDienPhanHinhTron.h"
#include "DongDienHinhTron.h"

// ---- loại nam châm
#define kDONG_DIEN__PHAN_HINH_TRON 'p'
#define kDONG_DIEN__HINH_TRON      't'

/* Thông Tin Dòng Điện */
typedef struct {
   unsigned char loai;     // loại
   unsigned char soLuong;  // số lượng
   double cachTuTrungTam;  // cách từ trung tâm
   union {
      DongDienPhanHinhTron phanHinhTron;
      DongDienHinhTron hinhTron;
   } thongTin;   // thông tin
} ThongTinDongDien;
