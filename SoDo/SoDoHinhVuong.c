// 2023.09.19  SơĐồHìnhVuông.c

#include <stdlib.h>
#include <math.h>
#include "../HangSo.h"
#include "../SVG.h"
#include "SoDo.h"

// ---- NỀN
#define kSO_DO_NEN__MAU         0xefefef
#define kSO_DO_NEN__CHIEU_RONG_NET  0.7f
#define kSO_DO_NEN__MAU_NET      0xbe6553
#define kSO_DO_NEN__DO_DUC_NET      1.0f

// ---- TRỤC
#define kSO_DO_TRUC__MAU      0x002f6f
#define kSO_DO_TRUC__CHIEU_RONG_NET 0.8f
#define kSO_DO_TRUC__DO_DUC      1.0f

// ---- ĐÒNG ĐIỆN
#define kDONG_DIEN__CHIEU_RONG_NET 6.0f
#define kDONG_DIEN__MAU_NET    0xffa000
#define kDONG_DIEN__DO_DUC_NET    0.5f

// ---- QŨY ĐẠO NAM CHÂM
#define kQUY_DAO_NAM_CHAM__CHIEU_RONG_NET 5.0f
#define kQUY_DAO_NAM_CHAM__MAU_NET    0x7f7f7f
#define kQUY_DAO_NAM_CHAM__DO_DUC_NET    0.5f

// ---- NAM CHÂM
#define kNAM_CHAM__CHIEU_RONG_NET 1.5f
#define kNAM_CHAM__MAU_NET   0x47197a
#define kNAM_CHAM__DO_DUC_NET    1.0f

#define kNAM_CHAM__MAU_TO     0x47197a
#define kNAM_CHAM__DO_DUC_TO    0.5f






#pragma mark ==== Vẽ Những Nam Châm
void veNhungNamChamHinhTru( FILE *tepSVG, NamChamHinhTru *mangNamCham, unsigned char soNamCham, float trungTam_x, float trungTam_y, float phongTo ) {
   
   double diemTrungTamNamCham_x;
   double diemTrungTamNamCham_y;

   float banKinhNamCham = mangNamCham[0].banKinh;
   float cachNamCham = sqrt(mangNamCham[0].viTri.x*mangNamCham[0].viTri.x + mangNamCham[0].viTri.y*mangNamCham[0].viTri.y);
   float duongKinhNamCham = banKinhNamCham*phongTo*2.0f;
   
   // ---- qũy đạo nam châm
   hinhTron( tepSVG, trungTam_x, trungTam_y, cachNamCham*phongTo, kSAI, 0x000000, 0.0f,
            kDUNG, duongKinhNamCham, kQUY_DAO_NAM_CHAM__MAU_NET, kQUY_DAO_NAM_CHAM__DO_DUC_NET*0.2f );
   
   hinhTron( tepSVG, trungTam_x, trungTam_y, cachNamCham*phongTo, kSAI, 0x000000, 0.0f,
            kDUNG, kQUY_DAO_NAM_CHAM__CHIEU_RONG_NET, kQUY_DAO_NAM_CHAM__MAU_NET, kQUY_DAO_NAM_CHAM__DO_DUC_NET );
   
   unsigned char chiSoNamCham = 0;
   while( chiSoNamCham < soNamCham ) {
      // ---- tính vị trí trung tâm của nam châm
      diemTrungTamNamCham_x = trungTam_x + mangNamCham[chiSoNamCham].viTri.x*phongTo;
      diemTrungTamNamCham_y = trungTam_y + mangNamCham[chiSoNamCham].viTri.y*phongTo;
      
      // ---- vẽ nam châm
      hinhTron( tepSVG, diemTrungTamNamCham_x, diemTrungTamNamCham_y, banKinhNamCham*phongTo, kDUNG,
               kNAM_CHAM__MAU_TO, kNAM_CHAM__DO_DUC_TO, kDUNG,
               kNAM_CHAM__CHIEU_RONG_NET, kNAM_CHAM__MAU_NET, kNAM_CHAM__DO_DUC_NET );
      chiSoNamCham++;
   }
}

void veNhungNamChamHinhHop( FILE *tepSVG, NamChamHinhHop *mangNamCham, unsigned char soNamCham, float trungTam_x, float trungTam_y, float phongTo ) {
   
   float nuaChieuDaiNamCham = 0.5*mangNamCham[0].chieuDai*phongTo;
   float nuaChieuRongNamCham = 0.5*mangNamCham[0].chieuRong*phongTo;
   float cachNamCham = sqrt(mangNamCham[0].viTri.x*mangNamCham[0].viTri.x + mangNamCham[0].viTri.y*mangNamCham[0].viTri.y);

   float duongKinhNamCham = nuaChieuDaiNamCham*2.0f;
   
   // ---- qũy đạo nam châm
   hinhTron( tepSVG, trungTam_x, trungTam_y, cachNamCham*phongTo, kSAI, 0x000000, 0.0f,
            kDUNG, duongKinhNamCham, kQUY_DAO_NAM_CHAM__MAU_NET, kQUY_DAO_NAM_CHAM__DO_DUC_NET*0.2f );
   
   hinhTron( tepSVG, trungTam_x, trungTam_y, cachNamCham*phongTo, kSAI, 0x000000, 0.0f,
            kDUNG, kQUY_DAO_NAM_CHAM__CHIEU_RONG_NET, kQUY_DAO_NAM_CHAM__MAU_NET, kQUY_DAO_NAM_CHAM__DO_DUC_NET );

   float mangDiem[8];
   
   unsigned char chiSoNamCham = 0;
   while( chiSoNamCham < soNamCham ) {
      // ---- tính vị trí trung tâm của nam châm
      float diemTrungTamNamCham_x;
      float diemTrungTamNamCham_y;
      diemTrungTamNamCham_x = trungTam_x + mangNamCham[chiSoNamCham].viTri.x*phongTo;
      diemTrungTamNamCham_y = trungTam_y + mangNamCham[chiSoNamCham].viTri.y*phongTo;
      
      // ---- tính điểm
      float gocXoay = mangNamCham[chiSoNamCham].gocXoay;
      float cosGoc = cosf( gocXoay );
      float sinGoc = sinf( gocXoay );
      
      mangDiem[0] = nuaChieuDaiNamCham*cosGoc - nuaChieuRongNamCham*sinGoc + diemTrungTamNamCham_x;
      mangDiem[1] = nuaChieuRongNamCham*cosGoc + nuaChieuDaiNamCham*sinGoc + diemTrungTamNamCham_y;
      
      mangDiem[2] = -nuaChieuDaiNamCham*cosGoc - nuaChieuRongNamCham*sinGoc + diemTrungTamNamCham_x;
      mangDiem[3] = nuaChieuRongNamCham*cosGoc - nuaChieuDaiNamCham*sinGoc + diemTrungTamNamCham_y;
      
      mangDiem[4] = -nuaChieuDaiNamCham*cosGoc + nuaChieuRongNamCham*sinGoc + diemTrungTamNamCham_x;
      mangDiem[5] = -nuaChieuRongNamCham*cosGoc - nuaChieuDaiNamCham*sinGoc + diemTrungTamNamCham_y;
      
      mangDiem[6] = nuaChieuDaiNamCham*cosGoc + nuaChieuRongNamCham*sinGoc + diemTrungTamNamCham_x;
      mangDiem[7] = -nuaChieuRongNamCham*cosGoc + nuaChieuDaiNamCham*sinGoc + diemTrungTamNamCham_y;

      // ---- vẽ nam châm
      daGiac( tepSVG, mangDiem, 4, kDUNG, kNAM_CHAM__MAU_TO, kNAM_CHAM__DO_DUC_TO, kDUNG,
             kNAM_CHAM__CHIEU_RONG_NET, kNAM_CHAM__MAU_NET, kNAM_CHAM__DO_DUC_NET );

      chiSoNamCham++;
   }
}


#pragma mark ==== Vẽ Những Dòng Điện
void veDongDienPhanHinhTron( FILE *tepSVG, DongDienPhanHinhTron *mangDongDien, unsigned char soDongDien, float trungTam_x, float trungTam_y, float phongTo ) {

   float gocDongDien = 0;
   float gocGiuaDongDien = k2_PI/soDongDien;

   float banKinhHinhCungNgoai = mangDongDien[0].banKinhNgoai*phongTo;
   float banKinhHinhCungNoi = mangDongDien[0].banKinhNoi*phongTo;
   float chieuRongGoc = mangDongDien[0].chieuRongGoc;

   unsigned char chiSoDongDien = 0;
   while( chiSoDongDien < soDongDien ) {
      float mangDiem[8];
      mangDiem[0] = trungTam_x + banKinhHinhCungNgoai*cosf( gocDongDien );
      mangDiem[1] = trungTam_y - banKinhHinhCungNgoai*sinf( gocDongDien );
      mangDiem[2] = trungTam_x + banKinhHinhCungNgoai*cosf( gocDongDien + chieuRongGoc );
      mangDiem[3] = trungTam_y - banKinhHinhCungNgoai*sinf( gocDongDien + chieuRongGoc );
      mangDiem[4] = trungTam_x + banKinhHinhCungNoi*cosf( gocDongDien + chieuRongGoc );
      mangDiem[5] = trungTam_y - banKinhHinhCungNoi*sinf( gocDongDien + chieuRongGoc );
      mangDiem[6] = trungTam_x + banKinhHinhCungNoi*cosf( gocDongDien );
      mangDiem[7] = trungTam_y - banKinhHinhCungNoi*sinf( gocDongDien );
      
      // ----
      hinhPhanTron( tepSVG, mangDiem, banKinhHinhCungNgoai, banKinhHinhCungNoi,
                   0.0f, kSAI, kSAI,   kSAI, 0x00000, 0.0f,
                   kDUNG, kDONG_DIEN__CHIEU_RONG_NET, kDONG_DIEN__MAU_NET, kDONG_DIEN__DO_DUC_NET );
      
      gocDongDien += gocGiuaDongDien;
      chiSoDongDien++;
   }
}

void veDongDienHinhTron( FILE *tepSVG, DongDienHinhTron *mangDongDien, unsigned char soDongDien, float trungTam_x, float trungTam_y, float phongTo, float pha ) {

   float gocDongDien = pha;
   float gocGiuaDongDien = k2_PI/soDongDien;

   float banKinhDongDien = mangDongDien[0].banKinh*phongTo;
   float cachTuTrungTamXoay = mangDongDien[0].cachTuTrungTam;

   unsigned char chiSoDongDien = 0;
   while( chiSoDongDien < soDongDien ) {
      float cachTrungTamX = cachTuTrungTamXoay*cosf( gocDongDien )*phongTo;
      float cachTrungTamY = cachTuTrungTamXoay*sinf( gocDongDien )*phongTo;
      
      float diem0_x = trungTam_x + cachTrungTamX;
      float diem0_y = trungTam_y + cachTrungTamY;
      
      // ---- vẽ hình tròn
      hinhTron( tepSVG, diem0_x, diem0_y, banKinhDongDien, kSAI, 0x00000, 0.0f,
               kDUNG, kDONG_DIEN__CHIEU_RONG_NET, kDONG_DIEN__MAU_NET, kDONG_DIEN__DO_DUC_NET );
      
      gocDongDien += gocGiuaDongDien;
      chiSoDongDien++;
   }
}


#pragma mark ==== Vẽ Nền Sơ Đồ Dòng Điện
void veNenSoDoDongDien( FILE *tepSVG, SoDoDongDien *soDo ) {
   
   // ----
   float viTriX = soDo->viTriX;
   float viTriY = soDo->viTriY;
   
   float chieuRong = soDo->chieuRong;
   float banKinhSoDo = soDo->banKinhSoDo;
   
   unsigned short soNetBanKinh = soDo->soNetBanKinh;
   
   // ---- nền
   chuNhat( tepSVG, viTriX, viTriY, chieuRong, chieuRong, kDUNG, kSO_DO_NEN__MAU, 1.0f,
           kSAI, 0.0f, 0x000000, 0.0f );
   
   float nuaChieuRong = chieuRong*0.5f;
   // ---- tính phóng to
   float phongTo = nuaChieuRong/banKinhSoDo;
   
   // ==== vẽ các vòng tròn
   unsigned char chiSoNet = 0;
   float banKinhHinhTron = nuaChieuRong;
   float buocNet = banKinhHinhTron/soNetBanKinh;
   float soDo_tamX = banKinhHinhTron + viTriX;
   float soDo_tamY = banKinhHinhTron + viTriY;
   
   while( chiSoNet < soNetBanKinh ) {
      // ---- vẽ hình tròn
      hinhTron( tepSVG, soDo_tamX, soDo_tamY, banKinhHinhTron, kSAI, 0x000000, 0.0f,
               kDUNG, kSO_DO_NEN__CHIEU_RONG_NET, kSO_DO_NEN__MAU_NET, kSO_DO_NEN__DO_DUC_NET );
      
      banKinhHinhTron -= buocNet;
      chiSoNet++;
   }
   
   // ==== HAI TRỤC
   // ---- trục x = 0 (ngang)
   float diem0_x = viTriX - 10.0f;
   float diem0_y = viTriY + nuaChieuRong;
   float diem1_x = viTriX + chieuRong + 10.0f;
   float diem1_y = diem0_y;
   duong( tepSVG, diem0_x, diem0_y, diem1_x, diem1_y, kSO_DO_TRUC__CHIEU_RONG_NET, kSO_DO_TRUC__MAU, kSO_DO_TRUC__DO_DUC );
   
   // ---- trục y = 0 (dộc)
   diem0_x = viTriX + nuaChieuRong;
   diem0_y = viTriY - 10.0f;
   diem1_x = diem0_x;
   diem1_y = viTriY + chieuRong + 10.0f;
   duong( tepSVG, diem0_x, diem0_y, diem1_x, diem1_y, kSO_DO_TRUC__CHIEU_RONG_NET, kSO_DO_TRUC__MAU, kSO_DO_TRUC__DO_DUC );
   
   // ==== SỐ TRỤC
   diem0_x = viTriX + nuaChieuRong - 4.0f;
   diem0_y = viTriY + chieuRong - 4.0f;
   
   chiSoNet = 0;
   unsigned char chiSoCuoi = soNetBanKinh; // nửa
   float buocSo = banKinhSoDo/soNetBanKinh;
   buocNet = nuaChieuRong/soNetBanKinh;

   float giaTriSo = banKinhSoDo;
   
   while( chiSoNet <= chiSoCuoi ) {
      char xauSo[32];
      sprintf( xauSo, "%3.1f", giaTriSo );
      vanBan_ngang( tepSVG, xauSo, diem0_x, diem0_y, "Sans", 8.0f, "Normal",
                   kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "end" );
      diem0_y -= buocNet;
      giaTriSo -= buocSo;
      chiSoNet++;
   }
}
