// NamChamHinhHop.h
// 2023.09.04
#include "../Vecto.h"

#pragma once

// Nam Châm Hình Hợp
typedef struct {
   double chieuDai;  // chiều dài (x) - mm
   double chieuRong; // chiều rộng (y) - mm
   double chieuCao;  // chiều cao (z) - mm
   double cuongDo;   // cường độ - A/m
   double gocXoay;   // go8c xoay - radian
   Vecto viTri;      // vị trí - mm
} NamChamHinhHop;

void datViTriMangNamChamHinhHopDeu( NamChamHinhHop *mangNamCham, unsigned char soNamCham, double cuongDo,
                        double chieuDai, double chieuRong, double chieuCao, double cachTuTrungTam, double doCao );

// ---- cho so sánh
float tinhTuTruongTrenTrucHinhHop( float viTriZ, double chieuDai, double chieuRong, double chieuCao, double cuongDo );

Vecto tinhTuTruongNamTramHinhHopMoi( Vecto *viTri, NamChamHinhHop *namCham,
                                    unsigned short soDoanX, unsigned short soDoanY );

Vecto tinhTuTruongNamTramHinhHopMoi2( Vecto *viTri, NamChamHinhHop *namCham );
