// SoDo.h
// 2023.08.29

#pragma once

#include <stdio.h>
#include "../NamCham/NamChamHinhTru.h"
#include "../NamCham/NamChamHinhHop.h"
#include "../DongDien/DongDienPhanHinhTron.h"
#include "../DongDien/DongDienHinhTron.h"
#include "../Vecto.h"


#define kLE_TRAI        100.0f // điểm ảnh
#define kLE_PHAI         40.0f

#define kLE_DUOI        100.0f // điểm ảnh
#define kLE_TREN         80.0f


#define kCHIEU_DAI_NET    4.0f

/* Dòng Điện Phần Hình Tròn */
typedef struct {
   float viTriX;        // vị trí góc y của sơ đồ
   float viTriY;        // vị trí góc y của sơ đồ
   
   float cucTieuX;
   float cucTieuY;
   
   float cucDaiX;
   float cucDaiY;
   
   float chieuRong;    // chiều rộng sơ đồ
   float chieuCao;     // chiều cao sơ đồ
   
   unsigned short soNetX;   // số nét cho trục x
   unsigned short soNetY;   // số nét cho trục y
   
//   char tieuDeSoDo[64]; // tiêu đề sơ đồ
//   char nhanTrucX[64];  // nhẵn trục x
//   char nhanTrucY[64];  // nhẵn trục y
   
} SoDoChuNhat;


/* Sơ Đồ Dòng Điện */
typedef struct {
   float viTriX;       // vị trí góc y của sơ đồ
   float viTriY;       // vị trí góc y của sơ đồ
   
   float chieuRong;        // cỡ thước sơ đồ (hình vuông)
   float banKinhSoDo;      // bán kính sơ đồ (mm)
   
   unsigned short soNetBanKinh;
   
} SoDoDongDien;


typedef struct {
   float viTriX;       // vị trí góc y của sơ đồ
   float viTriY;       // vị trí góc y của sơ đồ
   
   float cucTieuX;
   float cucTieuY;
   
   float cucDaiX;
   float cucDaiY;

   float chieuRong;    // chiều rộng sơ đồ
   float chieuCao;     // chiều cao sơ đồ

   float namChamChieuRong;
   float namChamChieuCao;
   float namChamViTriX;
   float namChamViTriY;
   
   float dongDienViTriX;
   float dongDienChieuRong;

   unsigned short soNetX;   // số nét cho trục x
   unsigned short soNetY;   // số nét cho trục y
   
} SoDoDoCaoNamCham;


// ---- nam câm hình trụ
void veSoDo_dongDienPhanHinhTron_namChamHinhTru( char *tenTep, double *mangDuLieu, unsigned short soDiem, NamChamHinhTru *mangNamCham, unsigned char soNamCham, DongDienPhanHinhTron *dongDien, unsigned char soDongDien );

void veSoDo_dongDienHinhTron_namChamHinhTru( char *tenTep, double *mangDuLieu, unsigned short soDiem, NamChamHinhTru *mangNamCham, unsigned char soNamCham, DongDienHinhTron *dongDien, unsigned char soDongDien );

// ---- nam câm hình hộp
void veSoDo_dongDienPhanHinhTron_namChamHinhHop( char *tenTep, double *mangDuLieu, unsigned short soDiem, NamChamHinhHop *mangNamCham, unsigned char soNamCham, DongDienPhanHinhTron *dongDien, unsigned char soDongDien );

void veSoDo_dongDienHinhTron_namChamHinhHop( char *tenTep, double *mangDuLieu, unsigned short soDiem, NamChamHinhHop *mangNamCham, unsigned char soNamCham, DongDienHinhTron *dongDien, unsigned char soDongDien );

