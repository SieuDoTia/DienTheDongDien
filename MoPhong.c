/* NhậpThôngTin.c */
// 2023.09.22


#include "MoPhong.h"
#include "SoDo/SoDo.h"
#include "HangSo.h"
#include <stdio.h>
#include <stdlib.h>



double *moPhongNamChamHinhTru_dongDienPhanHinhTron( NamChamHinhTru *mangNamCham, unsigned char soNamCham,
                           DongDienPhanHinhTron *dongDienPhanHinhTron, unsigned short soMau ) {

   double *mangDienThe = malloc( ((1 + soMau) * sizeof( double )) << 1 );  // điểm x và y
   if( mangDienThe == NULL ) {
      printf( "LỖI LẦM: Vấn đề giàng bộ nhớ cho mảng\n" );
      exit(2);
   }
   
   // ---- quét góc và tính
   double gocXoay = 0.0;      // radian
   double buocGoc = k2_PI/soMau;
   
   unsigned char soDoanTinh = 4;
   unsigned short chiSoMau = 0;
   unsigned short chiSoMang = 0;
   while( chiSoMau <= soMau ) {
      
      // ---- tính điện thế
      double dienThe = 0.0f;
      unsigned char chiSoNamCham = 0;

      while( chiSoNamCham < soNamCham ) {
         dienThe += tinhDienTheChoDongPhanHinhTron_namChamHinhTru( dongDienPhanHinhTron, soDoanTinh, gocXoay,
                                                              &(mangNamCham[chiSoNamCham]) );
         chiSoNamCham++;
      }

      // ----
      mangDienThe[chiSoMang] = gocXoay/kPI;  //
      chiSoMang++;
      mangDienThe[chiSoMang] = dienThe;
      chiSoMang++;
      
      gocXoay += buocGoc;
      chiSoMau++;
   }

   return mangDienThe;
}

double *moPhongNamChamHinhHop_dongDienPhanHinhTron( NamChamHinhHop *mangNamCham, unsigned char soNamCham,
                           DongDienPhanHinhTron *dongDienPhanHinhTron, unsigned short soMau ) {

   double *mangDienThe = malloc( 1 + (soMau * sizeof( double ) << 1) );  // điểm x và y
   if( mangDienThe == NULL ) {
      printf( "LỖI LẦM: Vấn đề giàng bộ nhớ cho mảng\n" );
      exit(2);
   }
   
   // ---- quét góc và tính
   double gocXoay = 0.0;      // radian
   double buocGoc = k2_PI/soMau;
   
   unsigned char soDoanTinh = 4;
   unsigned short chiSoMau = 0;
   unsigned short chiSoMang = 0;
   while( chiSoMau <= soMau ) {
      
      // ---- tính điện thế
      double dienThe = 0.0f;
      unsigned char chiSoNamCham = 0;
      
      while( chiSoNamCham < soNamCham ) {
         dienThe += tinhDienTheChoDongPhanHinhTron_namChamHinhHop( dongDienPhanHinhTron, soDoanTinh, gocXoay,
                                                              &(mangNamCham[chiSoNamCham]) );
         chiSoNamCham++;
      }
      
      // ----
      mangDienThe[chiSoMang] = gocXoay/kPI;  //
      chiSoMang++;
      mangDienThe[chiSoMang] = dienThe;
      chiSoMang++;
      
      gocXoay += buocGoc;
      chiSoMau++;
   }
   
   return mangDienThe;
}

double *moPhongNamChamHinhTru_dongDienHinhTron( NamChamHinhTru *mangNamCham, unsigned char soNamCham,
                              DongDienHinhTron *dongDienHinhTron, unsigned short soMau ) {

   double *mangDienThe = malloc( 1 + (soMau * sizeof( double ) << 1) );  // điểm x và y
   if( mangDienThe == NULL ) {
      printf( "LỖI LẦM: Vấn đề giàng bộ nhớ cho mảng\n" );
      exit(2);
   }
   
   // ---- quét góc và tính
   double gocXoay = 0.0;      // radian
   double buocGoc = k2_PI/soMau;
   
   unsigned char soDoanTinh = 4;
   unsigned short chiSoMau = 0;
   unsigned short chiSoMang = 0;
   while( chiSoMau <= soMau ) {
      
      // ---- tính điện thế
      double dienThe = 0.0f;
      unsigned char chiSoNamCham = 0;
      
      while( chiSoNamCham < soNamCham ) {
         dienThe += tinhDienTheChoDongHinhTron_namChamHinhTru( dongDienHinhTron, soDoanTinh, gocXoay,
                                                              &(mangNamCham[chiSoNamCham]) );
         chiSoNamCham++;
      }
      
      // ----
      mangDienThe[chiSoMang] = gocXoay/kPI;  //
      chiSoMang++;
      mangDienThe[chiSoMang] = dienThe;
      chiSoMang++;

      gocXoay += buocGoc;
      chiSoMau++;
   }
   
   return mangDienThe;
}

double *moPhongNamChamHinhHop_dongDienHinhTron( NamChamHinhHop *mangNamCham, unsigned char soNamCham,
                              DongDienHinhTron *dongDienHinhTron, unsigned short soMau ) {
   
   double *mangDienThe = malloc( 1 + (soMau * sizeof( double ) << 1) );  // điểm x và y
   if( mangDienThe == NULL ) {
      printf( "LỖI LẦM: Vấn đề giàng bộ nhớ cho mảng\n" );
      exit(2);
   }
   
   // ---- quét góc và tính
   double gocXoay = 0.0;      // radian
   double buocGoc = k2_PI/soMau;
   
   unsigned char soDoanTinh = 4;
   unsigned short chiSoMau = 0;
   unsigned short chiSoMang = 0;
   while( chiSoMau <= soMau ) {
      
      // ---- tính điện thế
      double dienThe = 0.0f;
      unsigned char chiSoNamCham = 0;
      
      while( chiSoNamCham < soNamCham ) {
         dienThe += tinhDienTheChoDongHinhTron_namChamHinhHop( dongDienHinhTron, soDoanTinh, gocXoay,
                                                              &(mangNamCham[chiSoNamCham]) );
         chiSoNamCham++;
      }
      
      // ----
      mangDienThe[chiSoMang] = gocXoay/kPI;  //
      chiSoMang++;
      mangDienThe[chiSoMang] = dienThe;
      chiSoMang++;
      
      gocXoay += buocGoc;
      chiSoMau++;
   }
   
   return mangDienThe;
}

#pragma mark ==== Tên Tập Tin Xuất
void soanTenTapTinSVG( char *tenTapTinNhap, char *tenTapTinSVG ) {
   
   char *xauKetQuaSVG = "_KếtQủa.svg";
   unsigned char chiSoKyTu = 0;
   while( tenTapTinNhap[chiSoKyTu] ) {
      tenTapTinSVG[chiSoKyTu] = tenTapTinNhap[chiSoKyTu];
      chiSoKyTu++;
   }
   
   // ---- bỏ ".txt"
   chiSoKyTu -= 4;
   
   // ---- kèm duôi mới cho tập tin SVG
   unsigned char chiSoPhu = 0;
   while( xauKetQuaSVG[chiSoPhu] ) {
      tenTapTinSVG[chiSoKyTu] = xauKetQuaSVG[chiSoPhu];
      chiSoKyTu++;
      chiSoPhu++;
   }
   // ---- kết thúc xâu
   tenTapTinSVG[chiSoKyTu] = 0x00;
}

void soanTenTapTinBangSo( char *tenTapTinNhap, char *tenTapTinBangSo ) {
   
   char *xauKetQuaSVG = "_BảngSố.txt";
   unsigned char chiSoKyTu = 0;
   while( tenTapTinNhap[chiSoKyTu] ) {
      tenTapTinBangSo[chiSoKyTu] = tenTapTinNhap[chiSoKyTu];
      chiSoKyTu++;
   }
   
   // ---- bỏ ".txt"
   chiSoKyTu -= 4;
   
   // ---- kèm duôi mới cho tập tin SVG
   unsigned char chiSoPhu = 0;
   while( xauKetQuaSVG[chiSoPhu] ) {
      tenTapTinBangSo[chiSoKyTu] = xauKetQuaSVG[chiSoPhu];
      chiSoKyTu++;
      chiSoPhu++;
   }
   // ---- kết thúc xâu
   tenTapTinBangSo[chiSoKyTu] = 0x00;
}

#pragma mark ====
void xuatBangSo( char *tenTapTinBangSo, double *mangDienThe, unsigned short soMau ) {
   
   FILE *tapTinBangSo = fopen( tenTapTinBangSo, "w" );
   
   if( tapTinBangSo == NULL ) {
      printf( "LỖI LẦM: Vấn đề mở tệp tin '%s'.\n", tenTapTinBangSo );
      exit(3);
   }
   // ---- hàng đầu
   fprintf( tapTinBangSo, "radian/π; µV / (rad/s)\n" );
   
   unsigned short chiSoMau = 0;
   unsigned int chiSoCuoi = soMau << 1;

   while( chiSoMau < chiSoCuoi ) {
      fprintf( tapTinBangSo, "%5.3f; %5.3e\n", mangDienThe[chiSoMau], mangDienThe[chiSoMau+1] );
      chiSoMau += 2;
   }
}


#pragma mark ==== Thực Hành Mô Phỏng
void thucHanhMoPhong( ThongTinNamCham *thongTinNamCham, ThongTinDongDien *thongTinDongDien, char *tenTapTinNhap,
                     unsigned short soMau, unsigned char xuatTapTin ) {
   
   // ==== TẠO MẢNG NAM CHÂM
   NamChamHinhTru *mangNamChamHinhTru = NULL;
   NamChamHinhHop *mangNamChamHinhHop = NULL;
   unsigned char soLuongNamCham = thongTinNamCham->soLuong;
   unsigned char loaiNamCham = thongTinNamCham->loai;
   
   if( loaiNamCham == kNAM_CHAM__HINH_TRU ) {
      mangNamChamHinhTru = malloc( soLuongNamCham*sizeof( NamChamHinhTru ) );
      if( mangNamChamHinhTru == NULL ) {
         printf( "LỖI LẦM: Vấn đề giành bộ nhớ\n" );;
         exit(2);
      }
      datViTriMangNamChamHinhTruDeu( mangNamChamHinhTru, soLuongNamCham, thongTinNamCham->cuongDo,
                                    thongTinNamCham->thongTin.hinhTru.banKinh, thongTinNamCham->thongTin.hinhTru.chieuCao,
                                    thongTinNamCham->cachTuTrungTam, thongTinNamCham->doCao );
   }
   else if( thongTinNamCham->loai == kNAM_CHAM__HINH_HOP ) {
      mangNamChamHinhHop = malloc( soLuongNamCham*sizeof( NamChamHinhHop ) );
      if( mangNamChamHinhHop == NULL ) {
         printf( "LỖI LẦM: Vấn đề giành bộ nhớ\n" );;
         exit(2);
      }
      datViTriMangNamChamHinhHopDeu( mangNamChamHinhHop, soLuongNamCham, thongTinNamCham->cuongDo,
                                    thongTinNamCham->thongTin.hinhHop.chieuDai, thongTinNamCham->thongTin.hinhHop.chieuRong,
                                    thongTinNamCham->thongTin.hinhHop.chieuCao, thongTinNamCham->cachTuTrungTam,
                                    thongTinNamCham->doCao );
   }
   
   // ==== TẠO MẢNG DÒNG ĐIẾN
   DongDienPhanHinhTron dongDienPhanHinhTron;
   DongDienHinhTron dongDienHinhTron;
   unsigned char soLuongDongDien = thongTinDongDien->soLuong;
   unsigned char loaiDongDien = thongTinDongDien->loai;
   
   if( thongTinDongDien->loai == kDONG_DIEN__PHAN_HINH_TRON ) {
      dongDienPhanHinhTron = datDongDienPhanHinhTron( thongTinDongDien->thongTin.phanHinhTron.banKinhNoi,
                                                     thongTinDongDien->thongTin.phanHinhTron.banKinhNgoai,
                                                     thongTinDongDien->thongTin.phanHinhTron.chieuRongGoc, soLuongDongDien );
   }
   else if( thongTinDongDien->loai == kDONG_DIEN__HINH_TRON ) {
      dongDienHinhTron = datDongDienHinhTron( thongTinDongDien->thongTin.hinhTron.banKinh,
                                             thongTinDongDien->cachTuTrungTam, thongTinDongDien->soLuong );
   }
   
   // ==== Tên tập tin SVG
   char tenTapTinSVG[256];
   char tenTapTinBangSo[256];


   
   if( xuatTapTin & kXUAT_TAP_TIN__BANG_SO ) {
      soanTenTapTinSVG( tenTapTinNhap, tenTapTinSVG );
      printf( "\n Tên tập tin SVG: %s\n", tenTapTinSVG );
   }
   if( xuatTapTin & kXUAT_TAP_TIN__BANG_SO )
      soanTenTapTinBangSo( tenTapTinNhap, tenTapTinBangSo );
      printf( "\n Tên tập tin Bảng Số: %s\n\n", tenTapTinBangSo );

   // ==== MÔ PHỎNG
   double *mangDienThe = NULL;
   if( (loaiNamCham == kNAM_CHAM__HINH_TRU) && (loaiDongDien == kDONG_DIEN__PHAN_HINH_TRON) ) {
      mangDienThe = moPhongNamChamHinhTru_dongDienPhanHinhTron( mangNamChamHinhTru, soLuongNamCham,
                                                               &dongDienPhanHinhTron, soMau );
      if( xuatTapTin & kXUAT_TAP_TIN__BANG_SO ) {
         // ---- vẽ sơ đồ
         veSoDo_dongDienPhanHinhTron_namChamHinhTru( tenTapTinSVG, mangDienThe, soMau+1, mangNamChamHinhTru, soLuongNamCham, &dongDienPhanHinhTron, soLuongDongDien );
      }
      
      if( xuatTapTin & kXUAT_TAP_TIN__BANG_SO ) {
         xuatBangSo( tenTapTinBangSo, mangDienThe, soMau + 1 );
      }
   }
   else if( (loaiNamCham == kNAM_CHAM__HINH_HOP) && (loaiDongDien == kDONG_DIEN__PHAN_HINH_TRON) ) {
      mangDienThe = moPhongNamChamHinhHop_dongDienPhanHinhTron( mangNamChamHinhHop, soLuongNamCham,
                                                               &dongDienPhanHinhTron, soMau );
      if( xuatTapTin & kXUAT_TAP_TIN__BANG_SO ) {
      // ---- vẽ sơ đồ
         veSoDo_dongDienPhanHinhTron_namChamHinhHop( tenTapTinSVG, mangDienThe, soMau+1, mangNamChamHinhHop, soLuongNamCham, &dongDienPhanHinhTron, soLuongDongDien );
      }
      
      if( xuatTapTin & kXUAT_TAP_TIN__BANG_SO ) {
         xuatBangSo( tenTapTinBangSo, mangDienThe, soMau + 1 );
      }
   }
   else if( (loaiNamCham == kNAM_CHAM__HINH_TRU) && (loaiDongDien == kDONG_DIEN__HINH_TRON) ) {
      mangDienThe = moPhongNamChamHinhTru_dongDienHinhTron( mangNamChamHinhTru, soLuongNamCham,
                                                           &dongDienHinhTron, soMau );
      // ---- vẽ sơ đồ
      if( xuatTapTin & kXUAT_TAP_TIN__BANG_SO ) {
      veSoDo_dongDienHinhTron_namChamHinhTru( tenTapTinSVG, mangDienThe, soMau+1, mangNamChamHinhTru, soLuongNamCham, &dongDienHinhTron, soLuongDongDien );
   }

      if( xuatTapTin & kXUAT_TAP_TIN__BANG_SO ) {
         xuatBangSo( tenTapTinBangSo, mangDienThe, soMau + 1 );
      }
   }
   else if( (loaiNamCham == kNAM_CHAM__HINH_HOP) && (loaiDongDien == kDONG_DIEN__HINH_TRON) ) {
      mangDienThe = moPhongNamChamHinhHop_dongDienHinhTron( mangNamChamHinhHop, soLuongNamCham,
                                                           &dongDienHinhTron, soMau );
      // ---- vẽ sơ đồ
      if( xuatTapTin & kXUAT_TAP_TIN__BANG_SO ) {
      veSoDo_dongDienHinhTron_namChamHinhHop( tenTapTinSVG, mangDienThe, soMau+1, mangNamChamHinhHop, soLuongNamCham, &dongDienHinhTron, soLuongDongDien );
      }
      
      if( xuatTapTin & kXUAT_TAP_TIN__BANG_SO ) {
         xuatBangSo( tenTapTinBangSo, mangDienThe, soMau + 1 );
      }
   }

   // ---- thả bộ nhớ
   if( mangNamChamHinhTru )
      free( mangNamChamHinhTru );
   if( mangNamChamHinhHop )
      free( mangNamChamHinhHop );
   free( mangDienThe );
}
