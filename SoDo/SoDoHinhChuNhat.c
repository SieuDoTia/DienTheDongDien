// 2023.09.19  SơĐồHìnhChữNhật.c

#include <stdlib.h>
#include <math.h>
#include "../HangSo.h"
#include "../SVG.h"
#include "SoDo.h"


#pragma mark ==== Sơ Đồ Dạng Sống
void veSoDo_dangSong( FILE *tepSVG, double *mangDuLieu, unsigned short soDiem, SoDoChuNhat *soDo ) {

   // ----
   float viTriX = soDo->viTriX;
   float viTriY = soDo->viTriY;
   
   float chieuRong = soDo->chieuRong;
   float chieuCao = soDo->chieuCao;
   float cucTieuX = soDo->cucTieuX;
   float cucTieuY = soDo->cucTieuY;
   float cucDaiX = soDo->cucDaiX;
   float cucDaiY = soDo->cucDaiY;
   unsigned short soNetX = soDo->soNetX;
   unsigned short soNetY = soDo->soNetY;

   // ---- tính phóng to
   float phongToX = chieuRong/(cucDaiX - cucTieuX);
   float phongToY = chieuCao/(cucDaiY - cucTieuY);
   
   // ---- độ thị
   float cachDoThiX = chieuRong/soNetX;
   float cachDoThiY = chieuCao/soNetY;
   
   // ---- nét trục
   float cachNetX = (cucDaiX - cucTieuX)/soNetX;
   float cachNetY = (cucDaiY - cucTieuY)/soNetY;
   
   float diem0_x;
   float diem0_y;
   float diem1_x;
   float diem1_y;
   
   // ---- nền
   chuNhat( tepSVG, viTriX, viTriY, chieuRong, chieuCao, kDUNG, 0xefefef, 1.0f,
                kSAI, 0.0f, 0x000000, 0.0f );

   // ==== VẼ ĐỘ THỊ
   // ---- ngang
   diem0_x = viTriX - kCHIEU_DAI_NET;  // tọa độ x không thay đổi
   diem1_x = viTriX + chieuRong;
   diem0_y = viTriY;
   diem1_y = viTriY;

   unsigned short chiSoNet = 0;
   while( chiSoNet <= soNetY ) {
//      printf( "(%5.1f; %5.1f)  %5.1f; %5.1f --> %5.1f; %5.1f\n", viTriX, viTriY, diem0_x, diem0_y, diem1_x, diem1_y );
      // ---- vẽ
      duong( tepSVG, diem0_x, diem0_y, diem1_x, diem1_y, 0.6f, 0x00b9a1, 1.0f );

      // ---- nâng cấp vị trí y
      diem0_y += cachDoThiY;
      diem1_y = diem0_y;

      chiSoNet++;
   }
   
   // ---- dộc
   diem0_y = viTriY;  // tọa độ x không thay đổi
   diem1_y = viTriY + chieuCao + kCHIEU_DAI_NET;
   diem0_x = viTriX;
   diem1_x = viTriX;

   chiSoNet = 0;
   while( chiSoNet <= soNetX ) {
//      printf( "(%5.1f; %5.1f)  %5.1f; %5.1f --> %5.1f; %5.1f\n", viTriX, viTriY, diem0_x, diem0_y, diem1_x, diem1_y );
      // ---- vẽ
      duong( tepSVG, diem0_x, diem0_y, diem1_x, diem1_y, 0.6f, 0xbe6553, 1.0f );

      // ---- nâng cấp vị trí y
      diem0_x += cachDoThiX;
      diem1_x = diem0_x;

      chiSoNet++;
   }

   // ==== BIẾN ĐỔI DỮ LIỆU CHO VẼ SƠ ĐỒ
   float *mangDuLieuVe = malloc( (soDiem << 1) * sizeof( float) );
   if( mangDuLieuVe == NULL ) {
      printf( "SoDo: LỖI LẦM - Vấn đề giành bộ nhớ\n" );
      exit(1);
   }
   
   float viTriNuaChieuCao = chieuCao*0.5f + viTriY;
   unsigned int chiSoDiem = 0;
   unsigned int chiSoCuoi = soDiem << 1;  // (x; y)
   while( chiSoDiem < chiSoCuoi ) {
      // ---- phóng to và lật
      mangDuLieuVe[chiSoDiem] = (float)(mangDuLieu[chiSoDiem]*phongToX) + viTriX;
      chiSoDiem++;
      // ---- lật ngược
      mangDuLieuVe[chiSoDiem] = (float)(-mangDuLieu[chiSoDiem]*phongToY) + viTriNuaChieuCao;
//      printf( "%d  (%5.3e; %5.3e)  %5.3e\n", chiSoDiem, mangDuLieuVe[chiSoDiem], mangDuLieuVe[chiSoDiem-1], mangDuLieu[chiSoDiem] );

      chiSoDiem++;
   }
   // ---- vẽ
   duongDaDiem( tepSVG, mangDuLieuVe, soDiem, kSAI, 0x000000, 0.0f, kDUNG, 1.0f, 0x1e3f91, 1.0f );
   
   // ==== VẼ TRỤC
   // ---- vị trí cho trục y = 0
   float truc_viTriY = viTriNuaChieuCao;
   diem0_x = viTriX - kCHIEU_DAI_NET;
   diem0_y = truc_viTriY;
   diem1_x = viTriX + chieuRong;
   diem1_y = diem0_y;
   duong( tepSVG, diem0_x, diem0_y, diem1_x, diem1_y, 0.8f, 0x000000, 1.0f );
   
   // ---- trục x = 0 (phía trái)
   diem0_x = viTriX;
   diem0_y = viTriY + chieuCao + kCHIEU_DAI_NET;
   diem1_x = viTriX;
   diem1_y = viTriY - kCHIEU_DAI_NET;
   duong( tepSVG, diem0_x, diem0_y, diem1_x, diem1_y, 0.8f, 0x000000, 1.0f );
   
   // ==== SỐ CHO TRỤC
   // ---- số cho trục y = 0
   diem0_x = viTriX;
   diem0_y = viTriY + chieuCao + 20.0f;
   
   chiSoNet = 0;
   chiSoCuoi = soNetX >> 1; // nửa

   float giaTriSo = cucTieuX;
   float buoc = (cucDaiX - cucTieuX)/chiSoCuoi;

   while( chiSoNet <= chiSoCuoi ) {
      char xauSo[32];
      sprintf( xauSo, "%3.1f", giaTriSo );
      vanBan_ngang( tepSVG, xauSo, diem0_x, diem0_y, "Sans", 10.0f, "Normal",
                        kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "middle" );
      diem0_x += cachDoThiX + cachDoThiX;
      giaTriSo += buoc;
      chiSoNet++;
   }
   
   // ---- tên trục x
   diem0_x = viTriX + chieuRong*0.5f;
   diem0_y = viTriY + chieuCao + 40.0f;
   vanBan_ngang( tepSVG, "Góc (radian/π)", diem0_x, diem0_y, "Sans", 14.0f, "Normal",
                kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "middle" );
   
   // ---- tên trục y
   diem0_x = viTriX - 45.0f;
   diem0_y = viTriNuaChieuCao;
   vanBan_ngangXoay( tepSVG, "Điện thế (µV / (rad/s) )", diem0_x, diem0_y, "Sans", 14.0f, "Normal",
                kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "middle", -90.0f );
   

   // ---- số cho trục x = 0
   diem0_x = viTriX - 15.0f;
   diem0_y = viTriY + chieuCao + 5.0f;
   giaTriSo = 0.0f;
   
   chiSoNet = 0;
   chiSoCuoi = soNetY >> 1; // nửa

   giaTriSo = cucTieuY;
   buoc = (cucDaiY - cucTieuY)/chiSoCuoi;
   
   while( chiSoNet <= chiSoCuoi ) {
      char xauSo[32];
      sprintf( xauSo, "%3.1f", giaTriSo );
      vanBan_ngang( tepSVG, xauSo, diem0_x, diem0_y, "Sans", 10.0f, "Normal",
                   kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "end" );
      diem0_y -= cachDoThiY + cachDoThiY;
      giaTriSo += buoc;
      chiSoNet++;
   }
   
   // ==== TIÊU ĐỀ
   diem0_x = viTriX + chieuRong*0.5f;
   diem0_y = viTriY - 20.0f;
   vanBan_ngang( tepSVG, "DẠNG SÓNG", diem0_x, diem0_y, "Sans", 20.0f, "Bold",
                kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "middle" );
}

// ---- ĐÒNG ĐIỆN NGANG
#define kDONG_DIEN_NGANG__CHIEU_RONG_NET 0.7f
#define kDONG_DIEN_NGANG__MAU_NET   0xffa000
#define kDONG_DIEN_NGANG__DO_DUC_NET    1.0f

#pragma mark ==== Sơ Đồ Độ Cao Nam Châm
void veSoDo_doCaoNamChamHinhTron( FILE *tepSVG, SoDoDoCaoNamCham *soDo ) {

   // ----
   float viTriX = soDo->viTriX;
   float viTriY = soDo->viTriY;

   float chieuRong = soDo->chieuRong;
   float chieuCao = soDo->chieuCao;
   float cucTieuX = soDo->cucTieuX;
   float cucTieuY = soDo->cucTieuY;
   float cucDaiX = soDo->cucDaiX;
   float cucDaiY = soDo->cucDaiY;
   unsigned short soNetX = soDo->soNetX;
   unsigned short soNetY = soDo->soNetY;
 
   // ---- tính phóng to
   float phongToX = chieuRong/(cucDaiX - cucTieuX);
   float phongToY = chieuCao/(cucDaiY - cucTieuY);
   
   // ---- độ thị
   float cachDoThiX = chieuRong/soNetX;
   float cachDoThiY = chieuCao/soNetY;
   float viTriNuaChieuCao = viTriY + chieuCao*0.5f;
   
   // ---- nét trục
   float cachNetX = (cucDaiX - cucTieuX)/soNetX;
   float cachNetY = (cucDaiY - cucTieuY)/soNetY;
   
   float diem0_x;
   float diem0_y;
   float diem1_x;
   float diem1_y;
   
   // ---- nền
   chuNhat( tepSVG, viTriX, viTriY, chieuRong, chieuCao, kDUNG, 0xefefef, 1.0f,
           kSAI, 0.0f, 0x000000, 0.0f );
   
   // ==== VẼ ĐỘ THỊ
   // ---- ngang
   diem0_x = viTriX - kCHIEU_DAI_NET;  // tọa độ x không thay đổi
   diem1_x = viTriX + chieuRong;
   diem0_y = viTriY;
   diem1_y = viTriY;
   
   unsigned short chiSoNet = 0;
   while( chiSoNet <= soNetY ) {
      //      printf( "(%5.1f; %5.1f)  %5.1f; %5.1f --> %5.1f; %5.1f\n", viTriX, viTriY, diem0_x, diem0_y, diem1_x, diem1_y );
      // ---- vẽ
      duong( tepSVG, diem0_x, diem0_y, diem1_x, diem1_y, 0.6f, 0x00b9a1, 1.0f );
      
      // ---- nâng cấp vị trí y
      diem0_y += cachDoThiY;
      diem1_y = diem0_y;
      
      chiSoNet++;
   }
   
   // ---- dộc
   diem0_y = viTriY;  // tọa độ x không thay đổi
   diem1_y = viTriY + chieuCao + kCHIEU_DAI_NET;
   diem0_x = viTriX;
   diem1_x = viTriX;
   
   chiSoNet = 0;
   while( chiSoNet <= soNetX ) {
      //      printf( "(%5.1f; %5.1f)  %5.1f; %5.1f --> %5.1f; %5.1f\n", viTriX, viTriY, diem0_x, diem0_y, diem1_x, diem1_y );
      // ---- vẽ
      duong( tepSVG, diem0_x, diem0_y, diem1_x, diem1_y, 0.6f, 0xbe6553, 1.0f );
      
      // ---- nâng cấp vị trí y
      diem0_x += cachDoThiX;
      diem1_x = diem0_x;
      
      chiSoNet++;
   }
   
   // ==== VẼ NAM CHÂM
   float namChamChieuRong = soDo->namChamChieuRong;
   float namChamChieuCao = soDo->namChamChieuCao;
   
   diem0_x = viTriX + (soDo->namChamViTriX - namChamChieuRong*0.5f)*phongToX;
   diem0_y = viTriY + chieuCao - (soDo->namChamViTriY + namChamChieuCao*0.5f)*phongToY;
   
   chuNhat( tepSVG, diem0_x, diem0_y, namChamChieuRong*phongToX, namChamChieuCao*phongToY, kDUNG, 0x47197a, 0.5f,
                kDUNG, 1.0f, 0x47197a, 1.0f );
   
   // ---- vẽ nét chỉ trung tâm nam châm
   //      dộc
   diem0_x = viTriX + soDo->namChamViTriX*phongToX;
   diem0_y = viTriY - 10.0f;
   diem1_x = diem0_x;
   diem1_y = viTriY + chieuCao;
   duong( tepSVG, diem0_x, diem0_y, diem1_x, diem1_y, 0.8f, 0x00007f, 0.5f );

   //     ngang
   diem0_x = viTriX + soDo->namChamViTriX*phongToX - 10.0f;
   diem0_y = viTriY + chieuCao - soDo->namChamViTriY*phongToY;
   diem1_x = diem0_x + 20.0f;
   diem1_y = diem0_y;
   duong( tepSVG, diem0_x, diem0_y, diem1_x, diem1_y, 0.8f, 0x7f007f, 0.5f );
   
   // ---- vẽ nét dòng điện
   float nuaDongDienChieuRong = soDo->dongDienChieuRong*0.5f;
   float dongDienViTriX = soDo->dongDienViTriX;
   diem0_x = viTriX + (dongDienViTriX - nuaDongDienChieuRong)*phongToX;
   diem0_y = viTriY + chieuCao;
   diem1_x = viTriX + (dongDienViTriX + nuaDongDienChieuRong)*phongToX;
   diem1_y = diem0_y;
   duong( tepSVG, diem0_x, diem0_y, diem1_x, diem1_y, 3.0f, 0xffa000, 1.0f );


   // ==== VẼ TRỤC
   // ---- vị trí cho trục y = 0
   float truc_viTriY = viTriY + chieuCao;
   diem0_x = viTriX - kCHIEU_DAI_NET;
   diem0_y = truc_viTriY;
   diem1_x = viTriX + chieuRong;
   diem1_y = diem0_y;
   duong( tepSVG, diem0_x, diem0_y, diem1_x, diem1_y, 0.8f, 0x000000, 1.0f );
   
   // ---- trục x = 0 (phía trái)
   diem0_x = viTriX;
   diem0_y = viTriY + chieuCao + kCHIEU_DAI_NET;
   diem1_x = viTriX;
   diem1_y = viTriY - kCHIEU_DAI_NET;
   duong( tepSVG, diem0_x, diem0_y, diem1_x, diem1_y, 0.8f, 0x000000, 1.0f );
   
   // ==== SỐ CHO TRỤC
   // ---- số cho trục y = 0
   diem0_x = viTriX;
   diem0_y = viTriY + chieuCao + 8.0f;
   
   chiSoNet = 0;
   unsigned short chiSoCuoi = soNetX >> 1; // nửa
   
   float giaTriSo = cucTieuX;
   float buoc = (cucDaiX - cucTieuX)/chiSoCuoi;
   
   while( chiSoNet <= chiSoCuoi ) {
      char xauSo[32];
      sprintf( xauSo, "%3.1f", giaTriSo );
      vanBan_ngangXoay( tepSVG, xauSo, diem0_x, diem0_y, "Sans", 8.0f, "Normal",
                   kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "end", -90.0f );
      diem0_x += cachDoThiX + cachDoThiX;
      giaTriSo += buoc;
      chiSoNet++;
   }
   
   // ---- tên trục x
   diem0_x = viTriX + chieuRong*0.5f;
   diem0_y = viTriY + chieuCao + 40.0f;
   vanBan_ngang( tepSVG, "Cách từ trục xoay (mm)", diem0_x, diem0_y, "Sans", 15.0f, "Normal",
                kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "middle" );
   
   // ---- tên trục y
   diem0_x = viTriX - 35.0f;
   diem0_y = viTriNuaChieuCao;
   vanBan_ngangXoay( tepSVG, "Độ cao (mm)", diem0_x, diem0_y, "Sans", 14.0f, "Normal",
                    kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "middle", -90.0f );

   // ---- số cho trục x = 0
   diem0_x = viTriX - 7.0f;
   diem0_y = viTriY + chieuCao + 5.0f;
   giaTriSo = 0.0f;
   
   chiSoNet = 0;
   chiSoCuoi = soNetY;
   
   giaTriSo = cucTieuY;
   buoc = (cucDaiY - cucTieuY)/chiSoCuoi;
   
   while( chiSoNet <= chiSoCuoi ) {
      char xauSo[32];
      sprintf( xauSo, "%3.1f", giaTriSo );
      vanBan_ngang( tepSVG, xauSo, diem0_x, diem0_y, "Sans", 8.0f, "Normal",
                   kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "end" );
      diem0_y -= cachDoThiY;
      giaTriSo += buoc;
      chiSoNet++;
   }
   
   // ==== TIÊU ĐỀ
   diem0_x = viTriX + chieuRong*0.5f;
   diem0_y = viTriY - 20.0f;
   vanBan_ngang( tepSVG, "ĐỘ CAO NAM CHÂM", diem0_x, diem0_y, "Sans", 20.0f, "Bold",
                kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "middle" );
}
