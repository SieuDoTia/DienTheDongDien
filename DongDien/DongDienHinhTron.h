// 2023.09.06


#pragma once

#include "../NamCham/NamChamHinhTru.h"
#include "../NamCham/NamChamHinhHop.h"

// Dòng Điện Hình Tròn
typedef struct {
   double banKinh;         // bán kính - mm
   double cachTuTrungTam;      // cache trung tam - mm
   unsigned char soDongDien;  // số dòng điện
} DongDienHinhTron;

DongDienHinhTron datDongDienHinhTron( double banKinh, double cachTuTrungTam, unsigned char soDongDien );

// ---- cho nam châm hình trụ
double tinhDienTheChoDongHinhTron_namChamHinhTru( DongDienHinhTron *dongDien, unsigned char soDoanCong, double gocXoay, NamChamHinhTru *namCham );

double tinhDienTheChoDongHinhTron_namChamHinhHop( DongDienHinhTron *dongDien, unsigned char soDoanCong, double gocXoay, NamChamHinhHop *namCham );
