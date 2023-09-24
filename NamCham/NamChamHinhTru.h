// NamCham.h
// 2023.08.28
#include "../Vecto.h"

#pragma once

// Nam Châm Hình Trụ
typedef struct {
   double banKinh;   // bán kính - mm
   double chieuCao;  // chiều cao - mm
   double cuongDo;   // cường độ - A/mm
   Vecto viTri;      // vị trí - mm
} NamChamHinhTru;

//NamChamHinhTru datNamHinhTru( double banKinh, double chieuCao, double cuongDo, Vecto *viTri );
// ---- cho đặt vị trí mảng nam châm
void datViTriMangNamChamHinhTruDeu( NamChamHinhTru *mangNamCham, unsigned char soNamCham, double cuongDo,
                        double banKinhNamCham, double chieuCaoNamCham, double cachTuTrungTam, double doCao );

// ---- cho so sánh/kiểm tra
float tinhTuTruongTrenTrucHinhTru( float viTriZ, double banKinh, double chieuCao, double cuongDo );

Vecto tinhTuTruongNamTramHinhTruMoi( Vecto *viTri, NamChamHinhTru *namCham, unsigned short soDoanChuVi );


