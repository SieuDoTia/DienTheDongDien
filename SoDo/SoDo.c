// 2023.08.28
// VeSoDo.c

#include <stdlib.h>
#include <math.h>
#include "../HangSo.h"
#include "../SVG.h"
#include "SoDo.h"
#include "SoDoHinhChuNhat.h"
#include "SoDoHinhVuong.h"
#include "PhatThongTin.h"

#define kSO_DO_DONG_DIEN__BAN_KINH 14.0f  // mm
#define kSO_DO_DONG_DIEN__SO_NET_BAN_KINH 7

#pragma mark ==== Phân Tích Dữ Liệu
void timGiaTriDuLieuNhoVaLonNhat( double *mangDuLieu, unsigned short soDiem, double *nhoNhat, double *lonNhat ) {
   
   // ---- dùng giá trị đầu cho khởi động
   double beNhat = mangDuLieu[0];
   double toNhat = mangDuLieu[0];
   
   // ---- quét và kiếm
   unsigned short chiSoDiem = 1;
   while( chiSoDiem < soDiem ) {
      double giaTriDuLieu = mangDuLieu[chiSoDiem];
      
      // ---- so sanh
      if( giaTriDuLieu < beNhat )
         beNhat = giaTriDuLieu;
      if( giaTriDuLieu > toNhat )
         toNhat = giaTriDuLieu;
      
      chiSoDiem++;
   }
   
   // ---- giữ kết qủa
   *nhoNhat = beNhat;
   *lonNhat = toNhat;
}

#pragma mark ==== Vẽ Dòng Điện Có Nam Châm
void veSoDoDongDienPhanHinhTronDeu_namChamHinhTru( FILE *tepSVG, SoDoDongDien *soDoDongDien, DongDienPhanHinhTron *mangDongDien, NamChamHinhTru *mangNamCham, unsigned char soNamCham ) {
   
   // ==== CHUẨN BỊ VẼ SƠ ĐỒ DÒNG ĐIỆN
   float viTriX = soDoDongDien->viTriX;
   float viTriY = soDoDongDien->viTriY;
   float chieuRongSoDo = soDoDongDien->chieuRong;
   
   float banKinhSoDo = soDoDongDien->banKinhSoDo;
   float nuaChieuRongSoDo = chieuRongSoDo*0.5f;
   // ---- tính phóng to
   float phongTo = nuaChieuRongSoDo/banKinhSoDo;
   
   // ==== VẼ NỀN
   veNenSoDoDongDien( tepSVG, soDoDongDien );
   
   // ==== DÒNG ĐIỆN HÌNH PHẦN TRÒN
   unsigned char soDongDien = mangDongDien->soDongDien;
   float trungTamSoDo_x = viTriX + nuaChieuRongSoDo;
   float trungTamSoDo_y = viTriY + nuaChieuRongSoDo;
   veDongDienPhanHinhTron( tepSVG, mangDongDien, soDongDien, trungTamSoDo_x, trungTamSoDo_y, phongTo );
   
   // ==== VẼ CÁC NAM CHÂM
   veNhungNamChamHinhTru( tepSVG, mangNamCham, soNamCham, trungTamSoDo_x, trungTamSoDo_y, phongTo );

   // ==== TIÊU ĐỀ
   float diem0_x = viTriX + nuaChieuRongSoDo;
   float diem0_y = viTriY - 20.0f;
   vanBan_ngang( tepSVG, "DÒNG ĐIỆN", diem0_x, diem0_y, "Sans", 20.0f, "Bold",
                kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "middle" );
}


void veSoDoDongDienHinhTronDeu_namChamHinhTru( FILE *tepSVG, SoDoDongDien *soDoDongDien, DongDienHinhTron *mangDongDien, NamChamHinhTru *mangNamCham, unsigned char soNamCham ) {
   
   // ==== CHUẨN BỊ VẼ SƠ ĐỒ DÒNG ĐIỆN
   float viTriX = soDoDongDien->viTriX;
   float viTriY = soDoDongDien->viTriY;
   float chieuRongSoDo = soDoDongDien->chieuRong;
   
   float banKinhSoDo = soDoDongDien->banKinhSoDo;
   float nuaChieuRongSoDo = chieuRongSoDo*0.5f;
   // ---- tính phóng to
   float phongTo = nuaChieuRongSoDo/banKinhSoDo;

   // ==== VẼ NỀN
   veNenSoDoDongDien( tepSVG, soDoDongDien );
   
   // ==== DÒNG ĐIỆN HÌNH TRÒN
   // ---- tính trung tâm sơ đồ
   float soDongDien = mangDongDien->soDongDien;
   float trungTamSoDo_x = viTriX + nuaChieuRongSoDo;
   float trungTamSoDo_y = viTriY + nuaChieuRongSoDo;
   float pha = kPI/6.0f;  // cho nam và dòng điện không nằm trên nhau
   veDongDienHinhTron( tepSVG, mangDongDien, soDongDien, trungTamSoDo_x, trungTamSoDo_y, phongTo, pha );
   
   // ==== VẼ CÁC NAM CHÂM HÌNH TRỤ
   veNhungNamChamHinhTru( tepSVG, mangNamCham, soNamCham, trungTamSoDo_x, trungTamSoDo_y, phongTo );
   
   // ==== TIÊU ĐỀ
   float diem0_x = viTriX + nuaChieuRongSoDo;
   float diem0_y = viTriY - 20.0f;
   vanBan_ngang( tepSVG, "DÒNG ĐIỆN", diem0_x, diem0_y, "Sans", 20.0f, "Bold",
                kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "middle" );
}

void veSoDoDongDienPhanHinhTronDeu_namChamHinhHop( FILE *tepSVG, SoDoDongDien *soDoDongDien, DongDienPhanHinhTron *mangDongDien, NamChamHinhHop *mangNamCham, unsigned char soNamCham ) {
   
   // ==== CHUẨN BỊ VẼ SƠ ĐỒ DÒNG ĐIỆN
   float viTriX = soDoDongDien->viTriX;
   float viTriY = soDoDongDien->viTriY;
   float chieuRongSoDo = soDoDongDien->chieuRong;
   
   float banKinhSoDo = soDoDongDien->banKinhSoDo;
   float nuaChieuRongSoDo = chieuRongSoDo*0.5f;
   // ---- tính phóng to
   float phongTo = nuaChieuRongSoDo/banKinhSoDo;
   
   // ==== VẼ NỀN
   veNenSoDoDongDien( tepSVG, soDoDongDien );
   
   // ==== DÒNG ĐIỆN HÌNH PHẦN TRÒN
   unsigned char soDongDien = mangDongDien->soDongDien;
   float trungTamSoDo_x = viTriX + nuaChieuRongSoDo;
   float trungTamSoDo_y = viTriY + nuaChieuRongSoDo;
   veDongDienPhanHinhTron( tepSVG, mangDongDien, soDongDien, trungTamSoDo_x, trungTamSoDo_y, phongTo );
   
   // ==== VẼ CÁC NAM CHÂM
   veNhungNamChamHinhHop( tepSVG, mangNamCham, soNamCham, trungTamSoDo_x, trungTamSoDo_y, phongTo );
   
   // ==== TIÊU ĐỀ
   float diem0_x = viTriX + nuaChieuRongSoDo;
   float diem0_y = viTriY - 20.0f;
   vanBan_ngang( tepSVG, "DÒNG ĐIỆN", diem0_x, diem0_y, "Sans", 20.0f, "Bold",
                kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "middle" );
}

void veSoDoDongDienHinhTronDeu_namChamHinhHop( FILE *tepSVG, SoDoDongDien *soDoDongDien, DongDienHinhTron *mangDongDien, NamChamHinhHop *mangNamCham, unsigned char soNamCham ) {
   
   // ==== CHUẨN BỊ VẼ SƠ ĐỒ DÒNG ĐIỆN
   float viTriX = soDoDongDien->viTriX;
   float viTriY = soDoDongDien->viTriY;
   float chieuRongSoDo = soDoDongDien->chieuRong;
   
   float banKinhSoDo = soDoDongDien->banKinhSoDo;
   float nuaChieuRongSoDo = chieuRongSoDo*0.5f;
   // ---- tính phóng to
   float phongTo = nuaChieuRongSoDo/banKinhSoDo;
   
   // ==== VẼ NỀN
   veNenSoDoDongDien( tepSVG, soDoDongDien );
   
   // ==== DÒNG ĐIỆN HÌNH PHẦN TRÒN
   unsigned char soDongDien = mangDongDien->soDongDien;
   float trungTamSoDo_x = viTriX + nuaChieuRongSoDo;
   float trungTamSoDo_y = viTriY + nuaChieuRongSoDo;
   float pha = kPI/6.0f;  // cho nam và dòng điện không nằm trên nhau
   veDongDienHinhTron( tepSVG, mangDongDien, soDongDien, trungTamSoDo_x, trungTamSoDo_y, phongTo, pha );
   
   // ==== VẼ CÁC NAM CHÂM
   veNhungNamChamHinhHop( tepSVG, mangNamCham, soNamCham, trungTamSoDo_x, trungTamSoDo_y, phongTo );
   
   // ==== TIÊU ĐỀ
   float diem0_x = viTriX + nuaChieuRongSoDo;
   float diem0_y = viTriY - 20.0f;
   vanBan_ngang( tepSVG, "DÒNG ĐIỆN", diem0_x, diem0_y, "Sans", 20.0f, "Bold",
                kDUNG, 0x000000, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "middle" );
}


#pragma mark ==== Vẽ Sơ Đồ
void veSoDo_dongDienPhanHinhTron_namChamHinhTru( char *tenTep, double *mangDuLieu, unsigned short soDiem, NamChamHinhTru *mangNamCham, unsigned char soNamCham, DongDienPhanHinhTron *dongDien, unsigned char soDongDien ) {
   
   FILE *tepSVG = fopen( tenTep, "w" );
   if(  tepSVG == NULL ) {
      printf( "SVG - LỖI LẦM: Vấn đề mở tập tin\n" );
      exit(1);
   }
   
   // ---- phân tích dữ liệu
   double nhoNhat;
   double lonNhat;
   timGiaTriDuLieuNhoVaLonNhat( mangDuLieu, soDiem, &nhoNhat, &lonNhat );
   
   double chenhLechDuLieu = lonNhat - nhoNhat;
   
   // ==== SƠ ĐỒ DẠNG SỐNG
   SoDoChuNhat soDo_dangSong;
   soDo_dangSong.viTriX = kLE_TRAI;
   soDo_dangSong.viTriY = kLE_TREN;
   
   soDo_dangSong.cucTieuX = 0.0f;  // radian/ π
   soDo_dangSong.cucTieuY = -10.0f;  // µV / (rad/s)
   
   soDo_dangSong.cucDaiX = 2.0f; // radian /π
   soDo_dangSong.cucDaiY = 10.f;  // µV / (rad/s)

   soDo_dangSong.chieuRong = kCHIEU_RONG__A4 - kLE_TRAI - kLE_PHAI;
   soDo_dangSong.chieuCao = 300.0f;
   
   soDo_dangSong.soNetX = 20;   // không biết
   soDo_dangSong.soNetY = 20;  // phạm vi 0 đến 2π radian, nét từng 0,1/π radiaa
   
   // ==== SƠ ĐỒ DÒNG ĐIỆN
   SoDoDongDien soDoDongDien;
   soDoDongDien.viTriX = kLE_TRAI - 20.0f;
   soDoDongDien.viTriY = 500.0f;

   soDoDongDien.chieuRong = (kCHIEU_RONG__A4*0.5f) - kLE_TRAI - kLE_PHAI;
   soDoDongDien.banKinhSoDo = kSO_DO_DONG_DIEN__BAN_KINH;
   
   soDoDongDien.soNetBanKinh = kSO_DO_DONG_DIEN__SO_NET_BAN_KINH;

   // ==== SƠ ĐỒ ĐỘ CAO
   SoDoDoCaoNamCham soDo_doCaoNamCham;
   soDo_doCaoNamCham.viTriX = kLE_TRAI - 20.0f + soDoDongDien.chieuRong*0.5f;
   soDo_doCaoNamCham.viTriY = 820.0f;
   
   soDo_doCaoNamCham.chieuRong = soDoDongDien.chieuRong*0.5f;
   soDo_doCaoNamCham.chieuCao = soDoDongDien.chieuRong*0.25f;
   
   soDo_doCaoNamCham.cucTieuX = 0.0f; // mm
   soDo_doCaoNamCham.cucTieuY = 0.0;  // mm
   
   soDo_doCaoNamCham.cucDaiX = kSO_DO_DONG_DIEN__BAN_KINH; // mm
   soDo_doCaoNamCham.cucDaiY = 5.0f;  // mm
   
   soDo_doCaoNamCham.soNetX = 14;
   soDo_doCaoNamCham.soNetY = 5;
   
   soDo_doCaoNamCham.namChamChieuRong = mangNamCham[0].banKinh*2.0;
   soDo_doCaoNamCham.namChamChieuCao = mangNamCham[0].chieuCao;
   soDo_doCaoNamCham.namChamViTriX = mangNamCham[0].viTri.x;
   soDo_doCaoNamCham.namChamViTriY = mangNamCham[0].viTri.z;

   float banKinhNgoai = dongDien[0].banKinhNgoai;
   float banKinhNoi = dongDien[0].banKinhNoi;
   soDo_doCaoNamCham.dongDienViTriX = banKinhNgoai - banKinhNoi;
   soDo_doCaoNamCham.dongDienChieuRong = (banKinhNgoai - banKinhNoi)*0.5f;


   // ==== SVG
   // ---- ĐẦU TẬP TIN
   luuDauSVG( tepSVG, kCHIEU_RONG__A4, kCHIEU_CAO__A4 );
   // ---- vẽ sơ đồ dạng sống
   veSoDo_dangSong( tepSVG, mangDuLieu, soDiem, &soDo_dangSong );

   // ----- vẽ sơ đồ dòng điện
   veSoDoDongDienPhanHinhTronDeu_namChamHinhTru( tepSVG, &soDoDongDien, dongDien, mangNamCham, soNamCham );
   
   // ---- vẽ sơ đồ độ co nam châm
   veSoDo_doCaoNamChamHinhTron( tepSVG, &soDo_doCaoNamCham );
   
   // ---- phát thông tin về hệ thống
   phatThongTinNamChamHinhTru( tepSVG, kLE_TRAI + 300.0, 500.0f, mangNamCham, soNamCham );
   phatThongTinDongDienPhanHinhTron( tepSVG, kLE_TRAI + 300.0, 680.0f, dongDien, soDongDien );
   // ----
   ketThucSVG( tepSVG );
}


void veSoDo_dongDienHinhTron_namChamHinhTru( char *tenTep, double *mangDuLieu, unsigned short soDiem, NamChamHinhTru *mangNamCham, unsigned char soNamCham, DongDienHinhTron *dongDien, unsigned char soDongDien ) {

   FILE *tepSVG = fopen( tenTep, "w" );
   if(  tepSVG == NULL ) {
      printf( "SVG - LỖI LẦM: Vấn đề mở tập tin\n" );
      exit(1);
   }
   
   // ---- phân tích dữ liệu
   double nhoNhat;
   double lonNhat;
   timGiaTriDuLieuNhoVaLonNhat( mangDuLieu, soDiem, &nhoNhat, &lonNhat );
   
   double chenhLechDuLieu = lonNhat - nhoNhat;
   
   // ==== SƠ ĐỒ DẠNG SỐNG
   SoDoChuNhat soDoChuNhat;
   soDoChuNhat.viTriX = kLE_TRAI;
   soDoChuNhat.viTriY = kLE_TREN;
   
   soDoChuNhat.cucTieuX = 0.0f;  // radian/ π
   soDoChuNhat.cucTieuY = -10.0f;  // không biết đơn vị
   
   soDoChuNhat.cucDaiX = 2.0f; // radian /π
   soDoChuNhat.cucDaiY = 10.f;  // không biết đơn vị
   
   soDoChuNhat.chieuRong = kCHIEU_RONG__A4 - kLE_TRAI - kLE_PHAI;
   soDoChuNhat.chieuCao = 300.0f;
   
   soDoChuNhat.soNetX = 20;   // kh4ng biết
   soDoChuNhat.soNetY = 20;  // phạm vi 0 đến 2π radian, nét từng 0,1/π radiaa
   
   // ==== SƠ ĐỒ DÒNG ĐIỆN
   SoDoDongDien soDoDongDien;
   soDoDongDien.viTriX = kLE_TRAI - 20.0f;
   soDoDongDien.viTriY = 500.0f;
   
   soDoDongDien.chieuRong = (kCHIEU_RONG__A4*.5f) - kLE_TRAI - kLE_PHAI;
   soDoDongDien.banKinhSoDo = kSO_DO_DONG_DIEN__BAN_KINH;
   
   soDoDongDien.soNetBanKinh = kSO_DO_DONG_DIEN__SO_NET_BAN_KINH;

   // ==== SƠ ĐỒ ĐỘ CAO
   SoDoDoCaoNamCham soDo_doCaoNamCham;
   soDo_doCaoNamCham.viTriX = kLE_TRAI - 20.0f + soDoDongDien.chieuRong*0.5f;
   soDo_doCaoNamCham.viTriY = 820.0f;
   
   soDo_doCaoNamCham.chieuRong = soDoDongDien.chieuRong*0.5f;
   soDo_doCaoNamCham.chieuCao = soDoDongDien.chieuRong*0.25f;
   
   soDo_doCaoNamCham.cucTieuX = 0.0f; // mm
   soDo_doCaoNamCham.cucTieuY = 0.0;  // mm
   
   soDo_doCaoNamCham.cucDaiX = kSO_DO_DONG_DIEN__BAN_KINH; // mm
   soDo_doCaoNamCham.cucDaiY = 5.0f;  // mm
   
   soDo_doCaoNamCham.soNetX = 14;
   soDo_doCaoNamCham.soNetY = 5;
   
   soDo_doCaoNamCham.namChamChieuRong = mangNamCham[0].banKinh*2.0;
   soDo_doCaoNamCham.namChamChieuCao = mangNamCham[0].chieuCao;
   soDo_doCaoNamCham.namChamViTriX = mangNamCham[0].viTri.x;
   soDo_doCaoNamCham.namChamViTriY = mangNamCham[0].viTri.z;
   
   soDo_doCaoNamCham.dongDienViTriX = dongDien[0].cachTuTrungTam;
   soDo_doCaoNamCham.dongDienChieuRong = dongDien[0].banKinh*2.0f;
   
   // ==== SVG
   // ---- ĐẦU TẬP TIN
   luuDauSVG( tepSVG, kCHIEU_RONG__A4, kCHIEU_CAO__A4 );

   // ---- vẽ sơ đồ dạng sống
   veSoDo_dangSong( tepSVG, mangDuLieu, soDiem, &soDoChuNhat );
   
   // ----- vẽ sơ đồ dòng điện
   veSoDoDongDienHinhTronDeu_namChamHinhTru( tepSVG, &soDoDongDien, dongDien, mangNamCham, soNamCham );

   // ---- vẽ sơ đồ độ co nam châm
   veSoDo_doCaoNamChamHinhTron( tepSVG, &soDo_doCaoNamCham );

   // ---- phát thông tin về hệ thống
   phatThongTinNamChamHinhTru( tepSVG, kLE_TRAI + 300.0, 500.0f, mangNamCham, soNamCham );
   phatThongTinDongDienHinhTron( tepSVG, kLE_TRAI + 300.0, 680.0f, dongDien, soDongDien );

   // ----
   ketThucSVG( tepSVG );
}


void veSoDo_dongDienPhanHinhTron_namChamHinhHop( char *tenTep, double *mangDuLieu, unsigned short soDiem, NamChamHinhHop *mangNamCham, unsigned char soNamCham, DongDienPhanHinhTron *dongDien, unsigned char soDongDien ) {
   
   FILE *tepSVG = fopen( tenTep, "w" );
   if(  tepSVG == NULL ) {
      printf( "SVG - LỖI LẦM: Vấn đề mở tập tin\n" );
      exit(1);
   }
   
   // ---- phân tích dữ liệu
   double nhoNhat;
   double lonNhat;
   timGiaTriDuLieuNhoVaLonNhat( mangDuLieu, soDiem, &nhoNhat, &lonNhat );

   double chenhLechDuLieu = lonNhat - nhoNhat;
   
   // ==== SƠ ĐỒ DẠNG SỐNG
   SoDoChuNhat soDo_dangSong;
   soDo_dangSong.viTriX = kLE_TRAI;
   soDo_dangSong.viTriY = kLE_TREN;
   
   soDo_dangSong.cucTieuX = 0.0f;  // radian/ π
   soDo_dangSong.cucTieuY = -10.0f;  // không biết đơn vị
   
   soDo_dangSong.cucDaiX = 2.0f; // radian /π
   soDo_dangSong.cucDaiY = 10.f;  // không biết đơn vị
   
   soDo_dangSong.chieuRong = kCHIEU_RONG__A4 - kLE_TRAI - kLE_PHAI;
   soDo_dangSong.chieuCao = 300.0f;
   
   soDo_dangSong.soNetX = 20;   // không biết
   soDo_dangSong.soNetY = 20;  // phạm vi 0 đến 2π radian, nét từng 0,1/π radiaa
   
   // ==== SƠ ĐỒ DÒNG ĐIỆN
   SoDoDongDien soDoDongDien;
   soDoDongDien.viTriX = kLE_TRAI - 20.0f;
   soDoDongDien.viTriY = 500.0f;
   
   soDoDongDien.chieuRong = (kCHIEU_RONG__A4*.5f) - kLE_TRAI - kLE_PHAI;
   soDoDongDien.banKinhSoDo = kSO_DO_DONG_DIEN__BAN_KINH;
   
   soDoDongDien.soNetBanKinh = kSO_DO_DONG_DIEN__SO_NET_BAN_KINH;

   // ==== SƠ ĐỒ ĐỘ CAO
   SoDoDoCaoNamCham soDo_doCaoNamCham;
   soDo_doCaoNamCham.viTriX = kLE_TRAI - 20.0f + soDoDongDien.chieuRong*0.5f;
   soDo_doCaoNamCham.viTriY = 820.0f;
   
   soDo_doCaoNamCham.chieuRong = soDoDongDien.chieuRong*0.5f;
   soDo_doCaoNamCham.chieuCao = soDoDongDien.chieuRong*0.25f;
   
   soDo_doCaoNamCham.cucTieuX = 0.0f; // mm
   soDo_doCaoNamCham.cucTieuY = 0.0;  // mm
   
   soDo_doCaoNamCham.cucDaiX = kSO_DO_DONG_DIEN__BAN_KINH; // mm
   soDo_doCaoNamCham.cucDaiY = 5.0f;  // mm
   
   soDo_doCaoNamCham.soNetX = 14;
   soDo_doCaoNamCham.soNetY = 4;

   soDo_doCaoNamCham.namChamChieuRong = mangNamCham[0].chieuDai;
   soDo_doCaoNamCham.namChamChieuCao = mangNamCham[0].chieuCao;
   soDo_doCaoNamCham.namChamViTriX = mangNamCham[0].viTri.x;
   soDo_doCaoNamCham.namChamViTriY = mangNamCham[0].viTri.z;
   
   float banKinhNgoai = dongDien[0].banKinhNgoai;
   float banKinhNoi = dongDien[0].banKinhNoi;
   soDo_doCaoNamCham.dongDienViTriX = banKinhNgoai - banKinhNoi;
   soDo_doCaoNamCham.dongDienChieuRong = (banKinhNgoai - banKinhNoi)*0.5f;

   
   // ==== SVG
   // ---- ĐẦU TẬP TIN
   luuDauSVG( tepSVG, kCHIEU_RONG__A4, kCHIEU_CAO__A4 );
   // ---- vẽ sơ đồ dạng sống
   veSoDo_dangSong( tepSVG, mangDuLieu, soDiem, &soDo_dangSong );
   
   // ----- vẽ sơ đồ dòng điện
   veSoDoDongDienPhanHinhTronDeu_namChamHinhHop( tepSVG, &soDoDongDien, dongDien, mangNamCham, soNamCham );

   // ---- vẽ sơ đồ độ co nam châm
   veSoDo_doCaoNamChamHinhTron( tepSVG, &soDo_doCaoNamCham );
   
   // ---- phát thông tin về hệ thống
   phatThongTinNamChamHinhHop( tepSVG, kLE_TRAI + 300.0, 500.0f, mangNamCham, soNamCham );
   phatThongTinDongDienPhanHinhTron( tepSVG, kLE_TRAI + 300.0, 680.0f, dongDien, soDongDien );
   // ----
   ketThucSVG( tepSVG );
}

void veSoDo_dongDienHinhTron_namChamHinhHop( char *tenTepSVG, double *mangDuLieu, unsigned short soDiem, NamChamHinhHop *mangNamCham, unsigned char soNamCham, DongDienHinhTron *dongDien, unsigned char soDongDien ) {
   
   FILE *tepSVG = fopen( tenTepSVG, "w" );
   if(  tepSVG == NULL ) {
      printf( "SVG - LỖI LẦM: Vấn đề mở tập tin\n" );
      exit(1);
   }
   
   // ---- phân tích dữ liệu
   double nhoNhat;
   double lonNhat;
   timGiaTriDuLieuNhoVaLonNhat( mangDuLieu, soDiem, &nhoNhat, &lonNhat );
   
   double chenhLechDuLieu = lonNhat - nhoNhat;
   
   // ==== SƠ ĐỒ DẠNG SỐNG
   SoDoChuNhat soDo_dangSong;
   soDo_dangSong.viTriX = kLE_TRAI;
   soDo_dangSong.viTriY = kLE_TREN;
   
   soDo_dangSong.cucTieuX = 0.0f;  // radian/ π
   soDo_dangSong.cucTieuY = -10.0f;  // µV / (rad/s)
   
   soDo_dangSong.cucDaiX = 2.0f; // radian /π
   soDo_dangSong.cucDaiY = 10.f;  // µV / (rad/s)
   
   soDo_dangSong.chieuRong = kCHIEU_RONG__A4 - kLE_TRAI - kLE_PHAI;
   soDo_dangSong.chieuCao = 300.0f;
   
   soDo_dangSong.soNetX = 20;
   soDo_dangSong.soNetY = 20;
   
   // ==== SƠ ĐỒ DÒNG ĐIỆN
   SoDoDongDien soDoDongDien;
   soDoDongDien.viTriX = kLE_TRAI - 20.0f;
   soDoDongDien.viTriY = 500.0f;
   
   soDoDongDien.chieuRong = (kCHIEU_RONG__A4*0.5f) - kLE_TRAI - kLE_PHAI;
   soDoDongDien.banKinhSoDo = kSO_DO_DONG_DIEN__BAN_KINH;
   
   soDoDongDien.soNetBanKinh = kSO_DO_DONG_DIEN__SO_NET_BAN_KINH;

   // ==== SƠ ĐỒ ĐỘ CAO
   SoDoDoCaoNamCham soDo_doCaoNamCham;
   soDo_doCaoNamCham.viTriX = kLE_TRAI - 20.0f + soDoDongDien.chieuRong*0.5f;
   soDo_doCaoNamCham.viTriY = 820.0f;
   
   soDo_doCaoNamCham.chieuRong = soDoDongDien.chieuRong*0.5f;
   soDo_doCaoNamCham.chieuCao = soDoDongDien.chieuRong*0.25f;

   soDo_doCaoNamCham.cucTieuX = 0.0f; // mm
   soDo_doCaoNamCham.cucTieuY = 0.0;  // mm
   
   soDo_doCaoNamCham.cucDaiX = kSO_DO_DONG_DIEN__BAN_KINH; // mm
   soDo_doCaoNamCham.cucDaiY = 4.0f;  // mm

   soDo_doCaoNamCham.soNetX = 14;
   soDo_doCaoNamCham.soNetY = 4;
   
   soDo_doCaoNamCham.namChamChieuRong = mangNamCham[0].chieuDai;
   soDo_doCaoNamCham.namChamChieuCao = mangNamCham[0].chieuCao;
   soDo_doCaoNamCham.namChamViTriX = mangNamCham[0].viTri.x;
   soDo_doCaoNamCham.namChamViTriY = mangNamCham[0].viTri.z;
   
   soDo_doCaoNamCham.dongDienViTriX = dongDien[0].cachTuTrungTam;
   soDo_doCaoNamCham.dongDienChieuRong = dongDien[0].banKinh*2.0f;


   // ==== SVG
   // ---- ĐẦU TẬP TIN
   luuDauSVG( tepSVG, kCHIEU_RONG__A4, kCHIEU_CAO__A4 );
   // ---- vẽ sơ đồ dạng sống
   veSoDo_dangSong( tepSVG, mangDuLieu, soDiem, &soDo_dangSong );
   
   // ----- vẽ sơ đồ dòng điện
   veSoDoDongDienHinhTronDeu_namChamHinhHop( tepSVG, &soDoDongDien, dongDien, mangNamCham, soNamCham );
   
   // ---- vẽ sơ đồ độ co nam châm
   veSoDo_doCaoNamChamHinhTron( tepSVG, &soDo_doCaoNamCham );

   // ---- phát thông tin về hệ thống
   phatThongTinNamChamHinhHop( tepSVG, kLE_TRAI + 340.0, 500.0f, mangNamCham, soNamCham );
   phatThongTinDongDienHinhTron( tepSVG, kLE_TRAI + 340.0, 680.0f, dongDien, soDongDien );
   
   // ----
   phatThongTinTapTapTinNhapVaNgayThang( tepSVG, kLE_TRAI, 750.0f, tenTepSVG );
   
   // ----
   ketThucSVG( tepSVG );
}
