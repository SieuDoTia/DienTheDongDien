/* DòngĐiệnPhầnHìnhTròn.h */
// 2023.09.01

#pragma once

#include "../NamCham/NamChamHinhTru.h"
#include "../NamCham/NamChamHinhHop.h"

// Dòng Điện Phần Hình Tròn
typedef struct {
   double banKinhNoi;         // mm
   double banKinhNgoai;       // bán kính ngoại (mm)
   double chieuRongGoc;       // chiều rộng (radian)
   unsigned char soDongDien;  // số dòng điện 
} DongDienPhanHinhTron;

DongDienPhanHinhTron datDongDienPhanHinhTron( double banKinhNoi, double banKinhNgoai, double chieuRongGoc, unsigned char soDongDien );

double tinhDienTheChoDongPhanHinhTron_namChamHinhTru( DongDienPhanHinhTron *dongDien, unsigned char soDoanCong, double gocXoay, NamChamHinhTru *namCham );

double tinhDienTheChoDongPhanHinhTron_namChamHinhHop( DongDienPhanHinhTron *dongDien, unsigned char soDoanCong, double gocXoay, NamChamHinhHop *namCham );
