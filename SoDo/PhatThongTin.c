#include <stdlib.h>
#include <time.h>
//#include <math.h>
#include "../HangSo.h"
#include "../SVG.h"
#include "SoDo.h"



#pragma mark ==== Phát Thông Tin Nam Châm
void phatThongTinNamChamHinhTru( FILE *tepSVG, float viTriX, float viTriY, NamChamHinhTru *mangNamCham, unsigned char soNamCham ) {
   
   // ---- nền
   chuNhat( tepSVG, viTriX - 15.0f, viTriY - 20.0f, 350.0f, 150.0f, kDUNG, 0xffefef, 1.0f,
           kSAI, 0.0f, 0x000000, 0.0f );
   
   // ==== thông tin nam châm
   char xauThongTin[64];
   float diem0_x = viTriX;
   float diem0_y = viTriY;
   vanBan_ngang( tepSVG, "NAM CHÂM", diem0_x, diem0_y, "Sans", 15.0f, "Bold",
                kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "left" );
   
   // ---- loại nam châm
   diem0_x += 5.0f;
   diem0_y += 15.0f;
   vanBan_ngang( tepSVG, "Loai: hình trụ", diem0_x, diem0_y, "Sans", 12.0f, "Bold",
                kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "left" );
   
   // ---- cường độ nam châm
   diem0_y += 15.0f;
   sprintf( xauThongTin, "Cường độ: %5.1f (A/mm)", mangNamCham[0].cuongDo );
   vanBan_ngang( tepSVG, xauThongTin, diem0_x, diem0_y, "Sans", 12.0f, "Bold",
                kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "left" );
   
   // ---- số lượng nam châm
   diem0_y += 15.0f;
   sprintf( xauThongTin, "Số lượng: %d", soNamCham );
   vanBan_ngang( tepSVG, xauThongTin, diem0_x, diem0_y, "Sans", 12.0f, "Bold",
                kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "left" );
   
   // ---- vị trí của các nam châm
   diem0_y += 20.0f;
   vanBan_ngang( tepSVG, "số: bán kính -- chiều cao | vị trí (mm)", diem0_x, diem0_y, "Sans", 12.0f, "Bold",
                kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "left" );
   
   diem0_y += 14.0f;
   unsigned char chiSoNamCham = 0;
   while( chiSoNamCham < soNamCham ) {
      Vecto viTriNamCham = mangNamCham[chiSoNamCham].viTri;
      sprintf( xauThongTin, " %d: %5.1f -- %5.1f | %5.2f; %5.2f; %5.2f\n", chiSoNamCham,
              mangNamCham[chiSoNamCham].banKinh, mangNamCham[chiSoNamCham].chieuCao,
              viTriNamCham.x, viTriNamCham.y, viTriNamCham.z );
      vanBan_ngang( tepSVG, xauThongTin, diem0_x, diem0_y, "Sans", 12.0f, "Normal",
                   kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "left" );
      diem0_y += 14.0f;
      chiSoNamCham++;
   }

}

void phatThongTinNamChamHinhHop( FILE *tepSVG, float viTriX, float viTriY, NamChamHinhHop *mangNamCham, unsigned char soNamCham ) {
   
   // ---- nền
   chuNhat( tepSVG, viTriX - 15.0f, viTriY - 15.0f, 350.0f, 150.0f, kDUNG, 0xffefef, 1.0f,
           kSAI, 0.0f, 0x000000, 0.0f );
   
   // ==== thông tin nam châm
   char xauThongTin[64];
   float diem0_x = viTriX;
   float diem0_y = viTriY;
   vanBan_ngang( tepSVG, "NAM CHÂM", diem0_x, diem0_y, "Sans", 15.0f, "Bold",
                kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "left" );
   
   // ---- loại nam châm
   diem0_x += 5.0f;
   diem0_y += 15.0f;
   vanBan_ngang( tepSVG, "Loai: hình hộp", diem0_x, diem0_y, "Sans", 12.0f, "Bold",
                kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "left" );
   
   // ---- cường độ nam châm
   diem0_y += 15.0f;
   sprintf( xauThongTin, "Cường độ: %5.1f (A/mm)", mangNamCham[0].cuongDo );
   vanBan_ngang( tepSVG, xauThongTin, diem0_x, diem0_y, "Sans", 12.0f, "Bold",
                kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "left" );
   
   // ---- số lượng nam châm
   diem0_y += 15.0f;
   sprintf( xauThongTin, "Số lượng: %d", soNamCham );
   vanBan_ngang( tepSVG, xauThongTin, diem0_x, diem0_y, "Sans", 12.0f, "Bold",
                kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "left" );
   
   // ---- vị trí của các nam châm
   diem0_y += 20.0f;
   vanBan_ngang( tepSVG, "số: -- chiều dài; rộng; cao | vị trí (mm) | góc xoay (rad)", diem0_x, diem0_y, "Sans", 12.0f, "Bold",
                kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "left" );
   
   diem0_y += 12.0f;
   unsigned char chiSoNamCham = 0;
   while( chiSoNamCham < soNamCham ) {
      Vecto viTriNamCham = mangNamCham[chiSoNamCham].viTri;
      sprintf( xauThongTin, " %d: -- %5.1f; %5.1f; %5.1f | %5.2f; %5.2f; %5.2f | %5.3f\n", chiSoNamCham,
              mangNamCham[chiSoNamCham].chieuDai, mangNamCham[chiSoNamCham].chieuRong,
              mangNamCham[chiSoNamCham].chieuCao,
              viTriNamCham.x, viTriNamCham.y, viTriNamCham.z, mangNamCham[chiSoNamCham].gocXoay );
      vanBan_ngang( tepSVG, xauThongTin, diem0_x, diem0_y, "Sans", 12.0f, "Normal",
                   kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "left" );
      diem0_y += 12.0f;
      chiSoNamCham++;
   }
   
}


#pragma mark ====
void phatThongTinDongDienPhanHinhTron(  FILE *tepSVG, float viTriX, float viTriY, DongDienPhanHinhTron *dongDien, unsigned char soDongDien ) {
   
   // ---- nền
   chuNhat( tepSVG, viTriX - 15.0f, viTriY - 15.0f, 250.0f, 100.0f, kDUNG, 0xefefef, 1.0f,
           kSAI, 0.0f, 0x000000, 0.0f );
   
   // ==== thông tin nam châm
   char xauThongTin[64];

   // ==== thông tin dòng điện
   float diem0_x = viTriX;
   float diem0_y = viTriY;
   vanBan_ngang( tepSVG, "DÒNG ĐIỆN", diem0_x, diem0_y, "Sans", 15.0f, "Bold",
                kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "left" );
   
   // ---- loại dòng điện
   diem0_x += 5.0f;
   diem0_y += 15.0f;
   vanBan_ngang( tepSVG, "Loai: phần hình tròn", diem0_x, diem0_y, "Sans", 12.0f, "Bold",
                kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "left" );
   
   // ---- bán kính nội
   diem0_y += 15.0f;
   sprintf( xauThongTin, "Bán kính nội: %5.1f (mm)", dongDien->banKinhNoi );
   vanBan_ngang( tepSVG, xauThongTin, diem0_x, diem0_y, "Sans", 12.0f, "Bold",
                kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "left" );
   
   // ---- bán kính ngoại
   diem0_y += 15.0f;
   sprintf( xauThongTin, "Bán kính ngoại: %5.1f (mm)", dongDien->banKinhNgoai );
   vanBan_ngang( tepSVG, xauThongTin, diem0_x, diem0_y, "Sans", 12.0f, "Bold",
                kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "left" );
   
   // ---- cách từ trung tâm
   diem0_y += 15.0f;
   sprintf( xauThongTin, "Chiều rộng góc: %5.1f (radian)", dongDien->chieuRongGoc );
   vanBan_ngang( tepSVG, xauThongTin, diem0_x, diem0_y, "Sans", 12.0f, "Bold",
                kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "left" );
   
   // ---- số lượng dòng điện
   diem0_y += 15.0f;
   sprintf( xauThongTin, "Số lượng: %d", soDongDien );
   vanBan_ngang( tepSVG, xauThongTin, diem0_x, diem0_y, "Sans", 12.0f, "Bold",
                kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "left" );
}

void phatThongTinDongDienHinhTron(  FILE *tepSVG, float viTriX, float viTriY, DongDienHinhTron *dongDien, unsigned char soDongDien ) {
   
   // ---- nền
   chuNhat( tepSVG, viTriX - 15.0f, viTriY - 15.0f, 250.0f, 100.0f, kDUNG, 0xefefef, 1.0f,
           kSAI, 0.0f, 0x000000, 0.0f );
   
   // ==== thông tin nam châm
   char xauThongTin[64];

   // ==== thông tin dòng điện
   float diem0_x = viTriX;
   float diem0_y = viTriY;
   vanBan_ngang( tepSVG, "DÒNG ĐIỆN", diem0_x, diem0_y, "Sans", 15.0f, "Bold",
                kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "left" );
   
   // ---- loại dòng điện
   diem0_x += 5.0f;
   diem0_y += 15.0f;
   vanBan_ngang( tepSVG, "Loai: hình tròn", diem0_x, diem0_y, "Sans", 12.0f, "Bold",
                kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "left" );
   
   // ---- bán kính
   diem0_y += 15.0f;
   sprintf( xauThongTin, "Bán kính: %5.1f (mm)", dongDien->banKinh );
   vanBan_ngang( tepSVG, xauThongTin, diem0_x, diem0_y, "Sans", 12.0f, "Bold",
                kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "left" );
   
   // ---- cách từ trung tâm
   diem0_y += 15.0f;
   sprintf( xauThongTin, "Cách từ trung tâm: %5.1f (mm)", dongDien->cachTuTrungTam );
   vanBan_ngang( tepSVG, xauThongTin, diem0_x, diem0_y, "Sans", 12.0f, "Bold",
                kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "left" );
   
   // ---- số lượng dòng điện
   diem0_x = viTriX;
   diem0_y += 15.0f;
   sprintf( xauThongTin, "Số lượng: %d", soDongDien );
   vanBan_ngang( tepSVG, xauThongTin, diem0_x, diem0_y, "Sans", 12.0f, "Bold",
                kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "left" );
}


void phatThongTinTapTapTinNhapVaNgayThang( FILE *tepSVG, float viTriX, float viTriY, char *tenTepSVG ) {

   // ==== thông tin nam châm
   char xauThongTin[64];
   
   // ==== tên tập tin
   float diem0_x = viTriX;
   float diem0_y = viTriY;
   vanBan_ngang( tepSVG, "DÒNG ĐIỆN", diem0_x, diem0_y, "Sans", 15.0f, "Bold",
                kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "left" );
   
   // ==== ngày tháng
   time_t thoiGian = time(NULL);
   struct tm *ngayNay = localtime(&thoiGian);
   
   unsigned short nam = ngayNay->tm_year;
   unsigned char thang = ngayNay->tm_mon;
   unsigned char ngay = ngayNay->tm_mday;
   unsigned char gio = ngayNay->tm_hour;
   unsigned char phut = ngayNay->tm_min;
   unsigned char giay = ngayNay->tm_sec;

   diem0_y += 15.0f;
   sprintf( xauThongTin, "%04d.%02d.%02d %02d:%02d:%02d", nam, thang, ngay, gio, phut, giay );
   vanBan_ngang( tepSVG, xauThongTin, diem0_x, diem0_y, "Sans", 12.0f, "Bold",
                kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "left" );
}
