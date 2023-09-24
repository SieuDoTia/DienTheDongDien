/* Khởi động 2005.11.24  */
#define kPHIEN_BAN "2023.09.22"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Vecto.h"
#include "NamCham/NamCham.h"
#include "DongDien/DongDien.h"
#include "SoDo/SoDo.h"
#include "NhapThongTin.h"
#include "MoPhong.h"
#include "HangSo.h"


// ----- quét qua từ z = –1 đến z = 1
void hamKiemTraNamChamHinhTru() {
   
   Vecto viTriDongDien;
   viTriDongDien.x = 0.0;
   viTriDongDien.y = 0.0;
   viTriDongDien.z = -1.0;
   
   // ---- nam châm
   NamChamHinhTru namCham;
   namCham.banKinh = 1.0;
   namCham.chieuCao = 1.0;
   namCham.cuongDo = 1.0;

   unsigned short soDoanChuVi = 4;
   
   Vecto tuTruong;
   double buocZ = 0.2f;
   
   printf( "\nKiểm Tra Hình Trụ\n" );
   
   unsigned char chiSo = 0;
   while( chiSo <= 10 ) {
      // ---- tính xấp xỉ
      tuTruong = tinhTuTruongNamTramHinhTruMoi( &viTriDongDien, &namCham, soDoanChuVi );
      printf( "viTri z: %5.3f |  B: %5.3e; %5.3e; %5.3e\n",
             viTriDongDien.z, tuTruong.x, tuTruong.y, tuTruong.z );

      // ---- áp dụng công thức cho điểm trên trục z
      double tuTruongZ = tinhTuTruongTrenTrucHinhTru( viTriDongDien.z, namCham.banKinh, namCham.chieuCao, namCham.cuongDo );
      
      // ---- phát kết qủa
      printf( "  so sánh viTri Z: (%5.3f;)  B_z: %5.3e   tỉ số %5.3f\n", viTriDongDien.z, tuTruongZ, tuTruong.z/tuTruongZ );

      viTriDongDien.z += buocZ;
      chiSo++;
   }
}

void hamKiemTraNamChamHinhHop() {
   
   Vecto viTriDongDien;
   viTriDongDien.x = 0.0;
   viTriDongDien.y = 0.0;
   viTriDongDien.z = -1.0;
   
   // ---- nam châm
   NamChamHinhHop namCham;
   namCham.chieuDai = 1.0;
   namCham.chieuRong = 1.0;
   namCham.chieuCao = 1.0;
   namCham.cuongDo = 1.0;
   
   unsigned short soDoanX = 2;
   unsigned short soDoanY = 2;
   
   Vecto tuTruong;
   Vecto tuTruong2;
   double buocZ = 0.2f;
   
   printf( "\nKiểm Tra Hình Hợp\n" );

   unsigned char chiSo = 0;
   while( chiSo <= 10 ) {
      // ---- tính  xấp xỉ
      tuTruong = tinhTuTruongNamTramHinhHopMoi( &viTriDongDien, &namCham,
                                 soDoanX, soDoanY );
      
      tuTruong2 = tinhTuTruongNamTramHinhHopMoi2( &viTriDongDien, &namCham );
      
      
      // ---- áp dụng công thức cho điểm trên trục z
      double tuTruongZ = tinhTuTruongTrenTrucHinhHop( viTriDongDien.z, namCham.chieuDai, namCham.chieuRong, namCham.chieuCao, namCham.cuongDo );
      printf( "----- viTri z: %5.3f |  B: %5.3e; %5.3e; %5.3e\n",
              viTriDongDien.z, tuTruong.x, tuTruong.y, tuTruong.z );

      // ---- phát kết qủa
      printf( "  so sánh viTri Z: (%5.3f;)  B_z: %5.3e   tỉ số %5.3f\n", viTriDongDien.z, tuTruongZ, tuTruong.z/tuTruongZ );
      
      printf( "         2-->  B: %5.3e; %5.3e; %5.3e  tỉ số %5.3f\n\n", tuTruong2.x, tuTruong2.y, tuTruong2.z, tuTruong2.z/tuTruongZ );
      
      viTriDongDien.z += buocZ;
      
      chiSo++;
   }
}

void hamKiemTraNamChamHinhHop2() {

   
   // ---- nam châm
   NamChamHinhHop namCham;
   namCham.chieuDai = 1.0;
   namCham.chieuRong = 1.0;
   namCham.chieuCao = 1.0;
   namCham.cuongDo = 1.0;
   
   unsigned short soDoanX = 1;
   unsigned short soDoanY = 1;

   
   Vecto tuTruong1;
   Vecto tuTruong2;
   Vecto viTri;
   
   // ====
   viTri.x = 0.0;
   viTri.y = 0.0;
   viTri.z = 0.0;
   printf( "-----> %5.3f; %5.3f; %5.3f <------\n", viTri.x, viTri.y, viTri.z );
   // ---- tính  xấp xỉ
   tuTruong1 = tinhTuTruongNamTramHinhHopMoi( &viTri, &namCham,
                                            soDoanX, soDoanY );
   // ---- tíng công thức
   tuTruong2 = tinhTuTruongNamTramHinhHopMoi2( &viTri, &namCham );

   printf( "   1--> : %5.3e; %5.3e; %5.3e\n", tuTruong1.x, tuTruong1.y, tuTruong1.z );
   printf( "   2--> : %5.3e; %5.3e; %5.3e\n\n", tuTruong2.x, tuTruong2.y, tuTruong2.z );
   
   // ====
   viTri.x = 1.0;
   viTri.y = 0.0;
   viTri.z = 0.0;
   printf( "-----> %5.3f; %5.3f; %5.3f <------\n", viTri.x, viTri.y, viTri.z );
   // ---- tính  xấp xỉ
   tuTruong1 = tinhTuTruongNamTramHinhHopMoi( &viTri, &namCham,
                                             soDoanX, soDoanY );
   // ---- tíng công thức
   tuTruong2 = tinhTuTruongNamTramHinhHopMoi2( &viTri, &namCham );

   printf( "   1--> : %5.3e; %5.3e; %5.3e\n", tuTruong1.x, tuTruong1.y, tuTruong1.z );
   printf( "   2--> : %5.3e; %5.3e; %5.3e\n\n", tuTruong2.x, tuTruong2.y, tuTruong2.z );

   // ====
   viTri.x = 0.0;
   viTri.y = 1.0;
   viTri.z = 0.0;
   printf( "-----> %5.3f; %5.3f; %5.3f <------\n", viTri.x, viTri.y, viTri.z );
   // ---- tính  xấp xỉ
   tuTruong1 = tinhTuTruongNamTramHinhHopMoi( &viTri, &namCham,
                                             soDoanX, soDoanY );
   // ---- tíng công thức
   tuTruong2 = tinhTuTruongNamTramHinhHopMoi2( &viTri, &namCham );

   printf( "   1--> : %5.3e; %5.3e; %5.3e\n", tuTruong1.x, tuTruong1.y, tuTruong1.z );
   printf( "   2--> : %5.3e; %5.3e; %5.3e\n\n", tuTruong2.x, tuTruong2.y, tuTruong2.z );
   
   // ====
   viTri.x = -1.0;
   viTri.y = .0;
   viTri.z = 0.0;
   printf( "-----> %5.3f; %5.3f; %5.3f <------\n", viTri.x, viTri.y, viTri.z );
   // ---- tính  xấp xỉ
   tuTruong1 = tinhTuTruongNamTramHinhHopMoi( &viTri, &namCham,
                                             soDoanX, soDoanY );
   // ---- tíng công thức
   tuTruong2 = tinhTuTruongNamTramHinhHopMoi2( &viTri, &namCham );
   
   printf( "   1--> : %5.3e; %5.3e; %5.3e\n", tuTruong1.x, tuTruong1.y, tuTruong1.z );
   printf( "   2--> : %5.3e; %5.3e; %5.3e\n\n", tuTruong2.x, tuTruong2.y, tuTruong2.z );
   
   // ====
   viTri.x = 0.0;
   viTri.y = -1.0;
   viTri.z = 0.0;
   printf( "-----> %5.3f; %5.3f; %5.3f <------\n", viTri.x, viTri.y, viTri.z );
   // ---- tính  xấp xỉ
   tuTruong1 = tinhTuTruongNamTramHinhHopMoi( &viTri, &namCham,
                                             soDoanX, soDoanY );
   // ---- tíng công thức
   tuTruong2 = tinhTuTruongNamTramHinhHopMoi2( &viTri, &namCham );
   
   printf( "   1--> : %5.3e; %5.3e; %5.3e\n", tuTruong1.x, tuTruong1.y, tuTruong1.z );
   printf( "   2--> : %5.3e; %5.3e; %5.3e\n\n", tuTruong2.x, tuTruong2.y, tuTruong2.z );
   
   // ====
   viTri.x = 1.0;
   viTri.y = 1.0;
   viTri.z = 1.0;
   printf( "======> %5.3f; %5.3f; %5.3f <======\n", viTri.x, viTri.y, viTri.z );
   // ---- tính  xấp xỉ
   tuTruong1 = tinhTuTruongNamTramHinhHopMoi( &viTri, &namCham,
                                             soDoanX, soDoanY );
   // ---- tíng công thức
   tuTruong2 = tinhTuTruongNamTramHinhHopMoi2( &viTri, &namCham );
   
   printf( "   1--> : %5.3e; %5.3e; %5.3e\n", tuTruong1.x, tuTruong1.y, tuTruong1.z );
   printf( "   2--> : %5.3e; %5.3e; %5.3e\n\n", tuTruong2.x, tuTruong2.y, tuTruong2.z );

   // ====
   viTri.x = -1.0;
   viTri.y = -1.0;
   viTri.z = -1.0;
   printf( "=====> %5.3f; %5.3f; %5.3f <=====\n", viTri.x, viTri.y, viTri.z );
   // ---- tính  xấp xỉ
   tuTruong1 = tinhTuTruongNamTramHinhHopMoi( &viTri, &namCham,
                                             soDoanX, soDoanY );
   // ---- tíng công thức
   tuTruong2 = tinhTuTruongNamTramHinhHopMoi2( &viTri, &namCham );
   
   printf( "   1--> : %5.3e; %5.3e; %5.3e\n", tuTruong1.x, tuTruong1.y, tuTruong1.z );
   printf( "   2--> : %5.3e; %5.3e; %5.3e\n\n", tuTruong2.x, tuTruong2.y, tuTruong2.z );
}

// ====================================================
/*
 Điệm thế
∫E•dl = ∂/∂t ∫B • dS
∫E•dl = ∫(B • n) v • dl

Nhớ v = ω x r
 
 */

/* Bezier */
/* CHƯA DÙNG
typedef struct {
   Vecto diemQuanTri[4];  // danh sách điểm quản trị
   //   unsigned short soLuongDiem;  // số lượng điểm
} Bezier;
*/

#pragma mark ==== Vị Dụ Và Kiểm Tra
// ---- cho rôto có nam châm hình trụ
void viDuNamChamHinhTru() {
   
   // ==== Nam Châm Hình Trụ
   double cuongDoNamCham = 978.0;   // A/mm
   double banKinhNamCham = 2.0;  // mm
   double chieuCaoNamCham = 1.6;  // mm
   double chieuCao = 2.0;  // mm  trên
   
   double cachTuTrungTam = 7.0;  // mm
   double doCao = 2.0;       // mm
   NamChamHinhTru *mangNamCham = malloc( 5*sizeof(NamChamHinhTru) );
   
   unsigned char chiSoNamCham = 0;
   unsigned char soNamCham = 3;
   double goc = 0.0;                  // radian
   double gocBuoc = k2_PI/soNamCham;  // radian
   
   while( chiSoNamCham < soNamCham ) {
      // ---- rút nam châm từ mảng
      NamChamHinhTru *namCham = &(mangNamCham[chiSoNamCham]);

      namCham->banKinh = banKinhNamCham;
      namCham->chieuCao = chieuCaoNamCham;
      namCham->cuongDo = cuongDoNamCham;
      
      namCham->viTri.x = cachTuTrungTam*cos( goc );
      namCham->viTri.y = cachTuTrungTam*sin( goc );
      namCham->viTri.z = doCao;

      goc += gocBuoc;
      chiSoNamCham++;
   }
   
   // ==== Dòng Điện Phần Hình Tròn
   double banKinhNoi = 5.0;   // mm
   double banKinhNgoai = 9.0; // mm
   double chieuRongGoc = kPI*0.333;
   unsigned char soDongDien = 3;
   DongDienPhanHinhTron dongDienPhanHinhTron = datDongDienPhanHinhTron( banKinhNoi, banKinhNgoai, chieuRongGoc, soDongDien );
   
   double tocDoXoay = 1.0;    // radian/giây
   unsigned char soDoanTinh = 2;
   
   
   // ==== Mảng Mẫu
   unsigned short soLuongGoc = 128;  // ôộ phân giải quét vòng
   double *mangDienThe = malloc( 1 + (soLuongGoc * sizeof( double ) << 1) );  // điểm x và y
   if( mangDienThe == NULL ) {
      printf( "ĐiệnThế - LỖI LẦM: giàng bộ nhớ cho mảng\n" );
      exit(2);
   }
   
   // ---- quét góc và tính
   double gocXoay = 0.0;      // radian
   double buocGoc = k2_PI/soLuongGoc;
   unsigned short chiSoGoc = 0;
   unsigned short chiSoMang = 0;
   while( chiSoGoc <= soLuongGoc ) {
      
      // ---- tính điện thế
      double dienThe = 0.0f;
      unsigned char chiSoNamCham = 0;
      
      while( chiSoNamCham < soNamCham ) {
         dienThe += tinhDienTheChoDongPhanHinhTron_namChamHinhTru( &dongDienPhanHinhTron, soDoanTinh, gocXoay,
                                                 &(mangNamCham[chiSoNamCham]) );
         chiSoNamCham++;
      }

      // ----
      mangDienThe[chiSoMang] = gocXoay/kPI;  //
      chiSoMang++;
      mangDienThe[chiSoMang] = dienThe;
      chiSoMang++;
      
      // ---- kết qủa
      //     printf( "%d  %5.3f DienThe %5.3e\n", chiSoGoc, gocXoay, dienThe );
      
      gocXoay += buocGoc;
      chiSoGoc++;
   }

   // ---- vẽ sơ đồ
   char *tenTapTinViDu0 = "VíDụNamChâmTròn_DòngĐiệnPhânHìnhTròn.svg";
   veSoDo_dongDienPhanHinhTron_namChamHinhTru( tenTapTinViDu0, mangDienThe, soLuongGoc+1, mangNamCham, soNamCham, &dongDienPhanHinhTron, soDongDien );
   
   
   // ==== Dòng Điện Hình Tròn
   // ==== Dòng Điện Phần Hình Tròn
   double banKinh = 2.0;   // mm
   cachTuTrungTam = 7.0;  // mm
   soDongDien = 3;
   DongDienHinhTron dongDienHinhTron = datDongDienHinhTron( banKinh, cachTuTrungTam, soDongDien );
   
   tocDoXoay = 1.0;    // radian/giây
   soDoanTinh = 2;

   // ---- quét góc và tính
   gocXoay = 0.0;      // radian
   chiSoGoc = 0;
   chiSoMang = 0;
   while( chiSoGoc <= soLuongGoc ) {
      
      // ---- tính điện thế
      double dienThe = 0.0f;
      unsigned char chiSoNamCham = 0;
      
      while( chiSoNamCham < soNamCham ) {
         dienThe += tinhDienTheChoDongHinhTron_namChamHinhTru( &dongDienHinhTron, soDoanTinh, gocXoay,
                                                 &(mangNamCham[chiSoNamCham]) );

         chiSoNamCham++;
      }

      // ----
      mangDienThe[chiSoMang] = gocXoay/kPI;  //
      chiSoMang++;
      mangDienThe[chiSoMang] = dienThe;
      chiSoMang++;
      
      // ---- kết qủa
      //     printf( "%d  %5.3f DienThe %5.3e\n", chiSoGoc, gocXoay, dienThe );
      
      gocXoay += buocGoc;
      chiSoGoc++;
   }
   
   // ---- vẽ sơ đồ
   char *tenTapTinViDu1 = "VíDụNamChâmTròn_DòngĐiệnHìnhTròn.svg";
   veSoDo_dongDienHinhTron_namChamHinhTru( tenTapTinViDu1, mangDienThe, soLuongGoc+1, mangNamCham, soNamCham, &dongDienHinhTron, soDongDien );
   
   
   // ---- thả bộ nhớ
   free( mangDienThe );
}


// ---- cho rôto có nam châm hình hộp
void viDuNamChamHinhHop() {
   
   // ==== Nam Châm Hình Trụ
   double cuongDoNamCham = 978.0; // A/mm
   double chieuDaiNamCham = 3.0;  // mm
   double chieuRongNamCham = 3.0; // mm
   double chieuCaoNamCham = 1.6;  // mm
   double chieuCao = 2.0;  // mm  trên
   
   double cachTuTrungTam = 7.0;  // mm
   double doCao = 2.0;       // mm
   NamChamHinhHop *mangNamCham = malloc( 5*sizeof(NamChamHinhHop) );
   
   unsigned char chiSoNamCham = 0;
   unsigned char soNamCham = 5;
   double goc = 0.0;                  // radian
   double gocBuoc = k2_PI/soNamCham;  // radian
   
   while( chiSoNamCham < soNamCham ) {
      // ---- rút nam châm từ mảng
      NamChamHinhHop *namCham = &(mangNamCham[chiSoNamCham]);
      
      // ---- đặt tham số cho nam châm
      namCham->chieuDai = chieuDaiNamCham;
      namCham->chieuRong = chieuRongNamCham;
      namCham->chieuCao = chieuCaoNamCham;
      namCham->cuongDo = cuongDoNamCham;
      namCham->gocXoay = goc;
      
      namCham->viTri.x = cachTuTrungTam*cos( goc );
      namCham->viTri.y = cachTuTrungTam*sin( goc );
      namCham->viTri.z = doCao;
      
      goc += gocBuoc;
      chiSoNamCham++;
   }

   // ==== Dòng Điện Phần Hình Tròn
   double banKinhNoi = 5.0;   // mm
   double banKinhNgoai = 9.0; // mm
   double chieuRongGoc = kPI*0.333;
   unsigned char soDongDien = 3;
   DongDienPhanHinhTron dongDienPhanHinhTron = datDongDienPhanHinhTron( banKinhNoi, banKinhNgoai, chieuRongGoc, soDongDien );
   
   double tocDoXoay = 1.0;    // radian/giây
   unsigned char soDoanTinh = 2;
   
   
   // ==== Mảng Mẫu
   unsigned short soLuongGoc = 128;  // ôộ phân giải quét vòng
   double *mangDienThe = malloc( 1 + (soLuongGoc * sizeof( double ) << 1) );  // điểm x và y
   if( mangDienThe == NULL ) {
      printf( "ĐiệnThế - LỖI LẦM: giàng bộ nhớ cho mảng\n" );
      exit(9);
   }
   
   // ---- quét góc và tính
   double gocXoay = 0.0;      // radian
   double buocGoc = k2_PI/soLuongGoc;
   unsigned short chiSoGoc = 0;
   unsigned short chiSoMang = 0;
   while( chiSoGoc <= soLuongGoc ) {
      
      // ---- tính điện thế
      double dienThe = 0.0f;
      unsigned char chiSoNamCham = 0;
      
      while( chiSoNamCham < soNamCham ) {
         dienThe += tinhDienTheChoDongPhanHinhTron_namChamHinhHop( &dongDienPhanHinhTron, soDoanTinh, gocXoay,
                                                              &(mangNamCham[chiSoNamCham]) );
         chiSoNamCham++;
      }
      
      // ----
      mangDienThe[chiSoMang] = gocXoay/kPI;  //
      chiSoMang++;
      mangDienThe[chiSoMang] = dienThe;
      chiSoMang++;
      
      // ---- kết qủa
      //     printf( "%d  %5.3f DienThe %5.3e\n", chiSoGoc, gocXoay, dienThe );
      
      gocXoay += buocGoc;
      chiSoGoc++;
   }
   
   // ---- vẽ sơ đồ
   char *tenTapTinViDu0 = "VíDụNamChâmHộp_DòngĐiệnPhânHìnhTròn.svg";
   veSoDo_dongDienPhanHinhTron_namChamHinhHop( tenTapTinViDu0, mangDienThe, soLuongGoc+1, mangNamCham, soNamCham, &dongDienPhanHinhTron, soDongDien );
   
   
   // ==== Dòng Điện Hình Tròn
   // ==== Dòng Điện Phần Hình Tròn
   double banKinh = 3.0;   // mm
   cachTuTrungTam = 7.0;  // mm
   soDongDien = 3;
   DongDienHinhTron dongDienHinhTron = datDongDienHinhTron( banKinh, cachTuTrungTam, soDongDien );
   
   tocDoXoay = 1.0;    // radian/giây
   soDoanTinh = 2;
   
   // ---- quét góc và tính
   gocXoay = 0.0;      // radian
   chiSoGoc = 0;
   chiSoMang = 0;
   while( chiSoGoc <= soLuongGoc ) {
      
      // ---- tính điện thế
      double dienThe = 0.0f;
      unsigned char chiSoNamCham = 0;
      
      while( chiSoNamCham < soNamCham ) {
         dienThe += tinhDienTheChoDongHinhTron_namChamHinhHop( &dongDienHinhTron, soDoanTinh, gocXoay,
                                                              &(mangNamCham[chiSoNamCham]) );
         
         chiSoNamCham++;
      }
      
      // ----
      mangDienThe[chiSoMang] = gocXoay/kPI;  //
      chiSoMang++;
      mangDienThe[chiSoMang] = dienThe;
      chiSoMang++;
      
      // ---- kết qủa
      //     printf( "%d  %5.3f DienThe %5.3e\n", chiSoGoc, gocXoay, dienThe );
      
      gocXoay += buocGoc;
      chiSoGoc++;
   }
   
   // ---- vẽ sơ đồ
   char *tenTapTinViDu1 = "VíDụNamChâmHộp_DòngĐiệnHìnhTròn.svg";
   veSoDo_dongDienHinhTron_namChamHinhHop( tenTapTinViDu1, mangDienThe, soLuongGoc+1, mangNamCham, soNamCham, &dongDienHinhTron, soDongDien );
   
   // ---- thả bộ nhớ
   free( mangDienThe );
}


#pragma mark ==== main

int main( int argc, char **argv ) {

   // --- phiên bản
   printf( "\nPhiên Bản: %s\n\n", kPHIEN_BAN );

   if( argc >= 2 ) {
      char tenTapTinNhap[128];   // <<<----- KHÔNG AN TOÀN
      unsigned char chieuDaiTen = 0;
      
      char *kyTu = argv[1];

      while( *kyTu != 0x00 ) {
         tenTapTinNhap[chieuDaiTen] = *kyTu++;
         chieuDaiTen++;
      }
      tenTapTinNhap[chieuDaiTen] = 0x00;

      // ---- nhập dữ liệu tập tin
      ThongTinNamCham thongTinNamCham;
      ThongTinDongDien thongTinDongDien;
      unsigned char xuatTapTin;  // cho biết xuất dữ liệu SVG hay bảng số hay cả hai
      nhapDuLieuTuTapTin( tenTapTinNhap, &thongTinNamCham, &thongTinDongDien, &xuatTapTin );
      
      // ---- xem có đủ thông tin không
      kiemTraThongTin( &thongTinNamCham, &thongTinDongDien, &xuatTapTin );
      
      // ---- Thực Hành Mô Phổng
      unsigned short soMau = 128; // 
      thucHanhMoPhong( &thongTinNamCham, &thongTinDongDien, tenTapTinNhap, soMau, xuatTapTin );
   }
   else { // phát ví dụ
      printf( "Ví dụ dùng gõ:\n ./dienTheDongDien <tên tập tin>\n\n" );
      printf( "Những ký hiệu cho tập tin:\n" );
      printf( "  P - Phiêu bản:\n" );
      printf( "\n" );
      printf( "  X - XUẤT TẬP TIN:\n" );
      printf( "    t - tộp tin xuất, có hai loại: tập tin bảng số 'b' và tập tin SVG 's'\n" );
      printf( "\n" );
      printf( "  N - NAM CHÂM:\n" );
      printf( "    l - loại nam châm, có hai loại: hình trụ 't' và hình hộp 'h'\n" );
      printf( "  Tham số cho nam châm HÌNH TRỤ\n" );
      printf( "    bk - bán kính ban châm (mm)\n" );
      printf( "    cc - chiều cao nam châm (mm)\n" );
      printf( "    dc - độ cao đo từ mặt phảng dòng điện (mm)\n" );
      printf( "    kc - khoảng cách từ trung tam xoay (mm)\n" );
      printf( "    sl - số lượng nam châm trên rôtor\n" );
      printf( "\n" );
      printf( "  Tham số cho nam châm HÌNH HỘP\n" );
      printf( "    cc - chiều cao nam châm (mm)\n" );
      printf( "    cd - chiều dài nam châm (mm)\n" );
      printf( "    cr - chiều rộng nam châm (mm)\n" );
      printf( "    dc - độ cao đo từ mặt phảng dòng điện (mm)\n" );
      printf( "    kc - khoảng cách từ trung tam xoay (mm)\n" );
      printf( "    sl - số lượng nam châm trên rôtor\n" );
      printf( "\n" );
      printf( "\n  D - dòng điện:\n" );
      printf( "    l - loại dòng điện, có hai loại: phần hình tròn 'p' và hình tròn 't'\n" );
      printf( "  Tham số cho dòng điện PHẦN HÌNH TRÒN\n" );
      printf( "    b1 - bán nội (mm)\n" );
      printf( "    b2 - bán kính ngoại (mm)\n" );
      printf( "    cr - chiều rộng góc (radian)\n" );
      printf( "    sl - số lượng dòng điện\n" );
      printf( "\n" );
      printf( "  Tham số cho dòng điện HÌNH TRÒN\n" );
      printf( "    bk - bán kính (mm)\n" );
      printf( "    kc - khoảng cách từ trung tam xoay (mm)\n" );
      printf( "    sl - số lượng dòng điện\n" );
      printf( "\n" );
      printf( "Tập tin ví dụ:\n" );
      printf( " # ---- Phiên bản tập tin\n" );
      printf( " P=1.00\n" );
      printf( " #\n" );
      printf( " # ---- Xuất loại tập tin bảng số và tập tin SVG\n" );
      printf( " X t=b t=s\n" );
      printf( " #\n" );
      printf( " # ---- Nam châm hình trụ, bán kính=3.0; chiều cao=1.5;\n" );
      printf( " #         khoảng cách=8.0; độ cao=4.0  số lượng=5  cường độ=978.0\n" );
      printf( " N l=t bk=3.0 cc=1.5 kc=8.0 dc=4.0 sl=5 am=978.0\n" );
      printf( " #\n" );
      printf( " # ---- Dòng điện phần hình tròn, bán kính nội=4.0; bán kính ngoại=9.0;\n" );
      printf( " #         chiều rộng=0.5; số lượng=3\n" );
      printf( " D l=p sl=3 b1=3.0 b2=5.0  cr=0.5\n" );
      printf( "\n" );
   
      // ---- chỉ dùng cho kiểm tra phần mềm
      //  hamKiemTraNamChamHinhHop2();
      //  hamKiemTraNamChamHinhHop();
      //  viDuNamChamHinhTru();
      
      // ---- ví dụ phần mềm
      viDuNamChamHinhHop();
   }

   return 0;
}
