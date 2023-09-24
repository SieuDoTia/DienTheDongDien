/* NhậpThôngTin.c */
// 2023.09.22

#include "NhapThongTin.h"
#include "HangSo.h"
#include <stdio.h>
#include <stdlib.h>


#pragma mark ==== Phân Tích Nam Châm
void docThongTinNamCham( char *xauThongTinNamCham, unsigned char soKyTu, ThongTinNamCham *namCham ) {
   //printf( "  %s\n", xauThongTinNamCham );
   
   // ---- thông tin cho nam châm
   char loaiNamCham = 0;
   double banKinh = 0.0;
   double chieuCao = 0.0;
   double cuongDo = 0.0;
   
   double chieuDai = 0.0;
   double chieuRong = 0.0;

   double cachTuTrungTam = 0.0;
   double doCao = 0.0;

   unsigned char soLuongNamCham = 0;
   
   // ---- tìm loại
   unsigned char chiSoKyTu = 0;
   while( chiSoKyTu < soKyTu ) {
      char kyTu = xauThongTinNamCham[chiSoKyTu];

      // ---- cường độ
      if( kyTu == 'a' ) { // kiếm "am"
         chiSoKyTu++;
         kyTu = xauThongTinNamCham[chiSoKyTu];
         if( kyTu == 'm' ) {
            chiSoKyTu += 2;   // bỏ qua dấu '='
            sscanf( &(xauThongTinNamCham[chiSoKyTu]), "%lf", &cuongDo );
         }
      }
      // ---- bán kính
      else if( kyTu == 'b' ) {   // kiếm "bk"
         chiSoKyTu++;
         kyTu = xauThongTinNamCham[chiSoKyTu];
         if( kyTu == 'k' ) {
            chiSoKyTu += 2;   // bỏ qua dấu '='
            sscanf( &(xauThongTinNamCham[chiSoKyTu]), "%lf", &banKinh );
         }
      }
      // ---- chiều dài, rộng, hay cao
      else if( kyTu == 'c' ) {  // kiếm "cc" "cr" "cc"
         chiSoKyTu++;
         kyTu = xauThongTinNamCham[chiSoKyTu];
         // ---- chiều cao
         if( kyTu == 'c' ) {
            chiSoKyTu += 2;   // bỏ qua dấu '='
            sscanf( &(xauThongTinNamCham[chiSoKyTu]), "%lf", &chieuCao );
         }
         else if( kyTu == 'd' ) {
            chiSoKyTu += 2;   // bỏ qua dấu '='
            sscanf( &(xauThongTinNamCham[chiSoKyTu]), "%lf", &chieuDai );
         }
         else if( kyTu == 'r' ) {
            chiSoKyTu += 2;   // bỏ qua dấu '='
            sscanf( &(xauThongTinNamCham[chiSoKyTu]), "%lf", &chieuRong );
         }
      }
      // ---- độ cao
      else if( kyTu == 'd' ) {   // kiếm "dc"
         chiSoKyTu++;
         kyTu = xauThongTinNamCham[chiSoKyTu];
         if( kyTu == 'c' ) {
            chiSoKyTu += 2;   // bỏ qua dấu '='
            sscanf( &(xauThongTinNamCham[chiSoKyTu]), "%lf", &doCao );
         }
      }
      // ---- khoảng các từ trung tâm
      else if( kyTu == 'k' ) {   // kiếm "kc"
         chiSoKyTu++;
         kyTu = xauThongTinNamCham[chiSoKyTu];
         if( kyTu == 'c' ) {
            chiSoKyTu += 2;   // bỏ qua dấu '='
            sscanf( &(xauThongTinNamCham[chiSoKyTu]), "%lf", &cachTuTrungTam );
         }
      }
      // ---- loại nam châm
      else if( kyTu == 'l' ) {
         chiSoKyTu += 2;
         loaiNamCham = xauThongTinNamCham[chiSoKyTu];
      }
      // ---- số lượng nam châm
      else if( kyTu == 's' ) {   // kiếm "sl"
         chiSoKyTu++;
         kyTu = xauThongTinNamCham[chiSoKyTu];
         if( kyTu == 'l' ) {
            chiSoKyTu += 2;   // bỏ qua dấu '='
            sscanf( &(xauThongTinNamCham[chiSoKyTu]), "%hhu", &soLuongNamCham);
         }
      }
      
      chiSoKyTu++;
   }

   // ---- đặt thông tin nam châm

   namCham->soLuong = soLuongNamCham;
   namCham->cuongDo = cuongDo;
   namCham->cachTuTrungTam = cachTuTrungTam;
   namCham->doCao = doCao;

   if( loaiNamCham == kNAM_CHAM__HINH_HOP ) {
      namCham->loai = kNAM_CHAM__HINH_HOP;
      
      namCham->thongTin.hinhHop.chieuDai = chieuDai;
      namCham->thongTin.hinhHop.chieuDai = chieuRong;
      namCham->thongTin.hinhTru.chieuCao = chieuCao;
   }
   else if( loaiNamCham == kNAM_CHAM__HINH_TRU ) {
      namCham->loai = kNAM_CHAM__HINH_TRU;

      namCham->thongTin.hinhTru.banKinh = banKinh;
      namCham->thongTin.hinhTru.chieuCao = chieuCao;
   }
}

#pragma mark ==== Phân Tích Dòng Điện
void docThongTinDongDien( char *xauThongTinDongDien, unsigned char soKyTu, ThongTinDongDien *dongDien ) {
   //printf( "  %s\n", xauThongTinDongDien );

   // ---- thông tin cho dòng điện
   unsigned char loaiDongDien = 0;
   unsigned char soLuongDongDien = 0;
   double banKinh = 0.0;
   double banKinhNoi = 0.0;
   double banKinhNgoai = 0.0;
   double chieuRongGoc = 0.0;
   double cachTuTrungTam = 0.0;
   
   // ---- tìm loại
   unsigned char chiSoKyTu = 0;
   while( chiSoKyTu < soKyTu ) {
      char kyTu = xauThongTinDongDien[chiSoKyTu];
      
      // ---- bán kính
      if( kyTu == 'b' ) {   // kiếm "bk" "b1" "b2"
         chiSoKyTu++;
         kyTu = xauThongTinDongDien[chiSoKyTu];
         if( kyTu == 'k' ) {
            chiSoKyTu += 2;   // bỏ qua dấu '='
            sscanf( &(xauThongTinDongDien[chiSoKyTu]), "%lf", &banKinh );
         }
         else if( kyTu == '1' ) {
            chiSoKyTu += 2;   // bỏ qua dấu '='
            sscanf( &(xauThongTinDongDien[chiSoKyTu]), "%lf", &banKinhNoi );
         }
         else if( kyTu == '2' ) {
            chiSoKyTu += 2;   // bỏ qua dấu '='
            sscanf( &(xauThongTinDongDien[chiSoKyTu]), "%lf", &banKinhNgoai );
         }
      }
      // ---- chiều rộng góc
      else if( kyTu == 'c' ) {   // kiếm "cr"
         chiSoKyTu++;
         kyTu = xauThongTinDongDien[chiSoKyTu];
         if( kyTu == 'r' ) {
            chiSoKyTu += 2;   // bỏ qua dấu '='
            sscanf( &(xauThongTinDongDien[chiSoKyTu]), "%lf", &chieuRongGoc );
         }
      }
      // ---- khoảng các từ trung tâm
      else if( kyTu == 'k' ) {   // kiếm "kc"
         chiSoKyTu++;
         kyTu = xauThongTinDongDien[chiSoKyTu];
         if( kyTu == 'c' ) {
            chiSoKyTu += 2;   // bỏ qua dấu '='
            sscanf( &(xauThongTinDongDien[chiSoKyTu]), "%lf", &cachTuTrungTam );
         }
      }
      // ---- loại dòng điện
      else if( kyTu == 'l' ) {
         chiSoKyTu += 2;
         loaiDongDien = xauThongTinDongDien[chiSoKyTu];
      }
      // ---- số lượng nam châm
      else if( kyTu == 's' ) {   // kiếm "sl"
         chiSoKyTu++;
         kyTu = xauThongTinDongDien[chiSoKyTu];
         if( kyTu == 'l' ) {
            chiSoKyTu += 2;   // bỏ qua dấu '='
            sscanf( &(xauThongTinDongDien[chiSoKyTu]), "%hhu", &soLuongDongDien);
         }
      }
   
      chiSoKyTu++;
   }

   // ---- đặt thông tin dòng điện
   if( loaiDongDien == kDONG_DIEN__PHAN_HINH_TRON ) {
      dongDien->loai = kDONG_DIEN__PHAN_HINH_TRON;
      dongDien->soLuong = soLuongDongDien;
      dongDien->thongTin.phanHinhTron.banKinhNoi = banKinhNoi;
      dongDien->thongTin.phanHinhTron.banKinhNgoai = banKinhNgoai;
      dongDien->thongTin.phanHinhTron.chieuRongGoc = chieuRongGoc;
      dongDien->cachTuTrungTam = cachTuTrungTam;
   }
   else if( loaiDongDien == kDONG_DIEN__HINH_TRON ) {
      dongDien->loai = kDONG_DIEN__HINH_TRON;
      dongDien->soLuong = soLuongDongDien;
      dongDien->thongTin.hinhTron.banKinh = banKinh;
      dongDien->cachTuTrungTam = cachTuTrungTam;
   }
   
}

void docThongTinXuatTapTin( char *xauThongXuatTapTin, unsigned char soKyTu, unsigned char *xuatTapTin ) {
   
   // thông tin
   *xuatTapTin = 0;
   
   // ---- tìm loại
   unsigned char chiSoKyTu = 0;
   while( chiSoKyTu < soKyTu ) {
      char kyTu = xauThongXuatTapTin[chiSoKyTu];
      
      // ---- tập tin
      if( kyTu == 't' ) {   // kiếm "bk" "b1" "b2"
         chiSoKyTu += 2;   // bỏ qua dấu '='
         kyTu = xauThongXuatTapTin[chiSoKyTu];
         if( kyTu == 's' ) {
            *xuatTapTin |= kXUAT_TAP_TIN__SVG;
         }
         else if( kyTu == 'b' ) {
            *xuatTapTin |= kXUAT_TAP_TIN__BANG_SO;
         }
      }
      
      chiSoKyTu++;
   }
}

#pragma mark ==== Nhập Dữ Liệi Từ Tập Tin
void nhapDuLieuTuTapTin( char *tenTapTinDuLieu, ThongTinNamCham *thongTinNamCham,
                        ThongTinDongDien *thongTinDongDien, unsigned char *xuatTapTin ) {
   
   FILE *tapTinDuLieu = fopen( tenTapTinDuLieu, "r" );
   *xuatTapTin = 0;
   
   if( tapTinDuLieu == NULL ) {
      printf( "LỖI LẦM: Vấn đề mở tập tin '%s'. Kiểm tra đã gõ tên tập tin đúng nhe.\n\n", tenTapTinDuLieu );
      exit(2);
   }
   
   printf( "Đã nhập tập tin: '%s'\n", tenTapTinDuLieu );
   
   // ---- xem chiều dài tập tin
   unsigned short chiSoKyTu = 0;
   
   while( fgetc( tapTinDuLieu ) != EOF ) {
      chiSoKyTu++;
   }
   if( chiSoKyTu == 0 ) {
      printf( "LỖI LẦM: Tập tin rỗng!" );
      exit(0);
   }
   else {
      rewind( tapTinDuLieu );
      
      while( !feof( tapTinDuLieu ) ) {
         char kyTu = fgetc( tapTinDuLieu );
         if( kyTu == 'N' || kyTu == 'n' ) {
            // ---- chép vào xâu
            char xauThongTinNamCham[128];
            char kyTu = 1;
            unsigned char chiSoKyTu = 0;
            while( ((kyTu = fgetc( tapTinDuLieu )) != '\n') && !feof( tapTinDuLieu ) ) {
               
               xauThongTinNamCham[chiSoKyTu] = kyTu;
               chiSoKyTu++;
            }
            xauThongTinNamCham[chiSoKyTu] = 0x00;
            
            // ---- phân tích thông tin nam châm
            docThongTinNamCham( xauThongTinNamCham, chiSoKyTu, thongTinNamCham );
         }
         else if( kyTu == 'D' || kyTu == 'd' ) {
            // ---- chép vào xâu
            char xauThongTinDongDien[128];
            char kyTu = 1;   // đặc = 1 cho vào được lặp vòng while
            unsigned char chiSoKyTu = 0;
            while( ((kyTu = fgetc( tapTinDuLieu )) != '\n') && !feof( tapTinDuLieu ) ) {
               
               xauThongTinDongDien[chiSoKyTu] = kyTu;
               chiSoKyTu++;
            }
            xauThongTinDongDien[chiSoKyTu] = 0x00;
            
            // ---- phân tích thông tin nam châm
            docThongTinDongDien( xauThongTinDongDien, chiSoKyTu, thongTinDongDien );
         }
         // ---- dữ liệu vị trí tâm
         else if( (kyTu == 'X') || (kyTu == 'x') ) {
            // ---- chép vào xâu
            char xauThongTinNamCham[128];
            char kyTu = 1;
            unsigned char chiSoKyTu = 0;
            while( ((kyTu = fgetc( tapTinDuLieu )) != '\n') && !feof( tapTinDuLieu ) ) {
               
               xauThongTinNamCham[chiSoKyTu] = kyTu;
               chiSoKyTu++;
            }
            xauThongTinNamCham[chiSoKyTu] = 0x00;
            
            // ---- phân tích thông tin nam châm
            docThongTinXuatTapTin( xauThongTinNamCham, chiSoKyTu, xuatTapTin );
         }
/*         else if( kyTu == 'V' ) {
            // ---- bỏ chú tích
            while( (fgetc( tapTinDuLieu ) != '\n') && !feof( tapTinDuLieu ) )
               ;
         }
         // ---- Mô phỏng - số mẫu, xuất tấp tin dữ liệu nào hay tập tin SVG
         else if( kyTu == 'M' ) {
          // ---- bỏ chú tích
          while( (fgetc( tapTinDuLieu ) != '\n') && !feof( tapTinDuLieu ) )
          ;
          } */
         else if( kyTu == '#' ) {
            // ---- bỏ chú tích
            while( (fgetc( tapTinDuLieu ) != '\n') && !feof( tapTinDuLieu ) )
               ;
         }
         else {
            // ---- bỏ ký tự nào thi không biết
            while( (fgetc( tapTinDuLieu ) != '\n') && !feof( tapTinDuLieu ) )
               ;
         }
      }
   }
   
}


void kiemTraThongTin( ThongTinNamCham *namCham, ThongTinDongDien *dongDien, unsigned char *xuatTapTin ) {
   
   unsigned char loaiNamCham = namCham->loai;
   unsigned char loaiDongDien = dongDien->loai;

   // ==== PHÁT THÔNG TIN NAM CHÂM
   printf( "\n ==== Thông Tin Nam Châm ====\n" );
   if( loaiNamCham == kNAM_CHAM__HINH_TRU ) {
      printf( "  Loại: Hình trụ\n" );
      printf( "  Số lượng: %d\n", namCham->soLuong );
      printf( "  Bán kính: %5.1f mm\n", namCham->thongTin.hinhTru.banKinh );
      printf( "  Chiều cao: %5.1f mm\n", namCham->thongTin.hinhTru.chieuCao );
      printf( "  Cường độ: %5.1f A/mm\n", namCham->cuongDo );
      printf( "  Độ cao trên dòng điện: %5.1f  mm\n", namCham->doCao );
      printf( "  Cách từ trung tâm xoay: %5.1f mm\n", namCham->cachTuTrungTam );
   }
   else if( loaiNamCham == kNAM_CHAM__HINH_HOP ) {
      printf( "  Loại: Hình Hộp\n" );
      printf( "  Số lượng: %d\n", namCham->soLuong );
      printf( "  Chiều dài: %5.1f mm\n", namCham->thongTin.hinhHop.chieuDai );
      printf( "  Chiều rộng: %5.1f mm\n", namCham->thongTin.hinhHop.chieuRong );
      printf( "  Chiều cao: %5.1f mm\n", namCham->thongTin.hinhHop.chieuCao );
      printf( "  Cường độ: %5.1f A/mm\n", namCham->cuongDo );
      printf( "  Độ cao trên dòng điện: %5.1f mm\n", namCham->doCao );
      printf( "  Cách từ trung tâm xoay: %5.1f mm\n", namCham->cachTuTrungTam );
   }
   else {
      printf( "VẤN ĐỀ: Loại nam châm: Không biết\n" );
      exit(3);
   }
   
   // ---- kiểm tra thông tin nam châm
   if( namCham->soLuong == 0 ) {
      printf( "VẤN ĐỀ: Nam châm: số lượng %d\n", namCham->soLuong );
      exit(3);
   }
   if( namCham->cachTuTrungTam == 0.0 ) {
      printf( "VẤN ĐỀ: Nam châm: khoảng cách từ trung tâm xoay: %5.1f mm\n", namCham->cachTuTrungTam );
      exit(3);
   }
   if( namCham->cuongDo == 0.0 ) {
      printf( "VẤN ĐỀ: Nam châm: cường độ: %5.1f mm\n", namCham->cuongDo );
      exit(3);
   }
   
   // ==== PHÁT THÔNG TIN DÒNG ĐIỆN
   printf( "\n ==== Thông Tin Dòng Điện ====\n" );
   if( loaiDongDien == kDONG_DIEN__PHAN_HINH_TRON ) {
      printf( "  Loại: Hình phần tròn\n" );
      printf( "  Số lượng: %d\n", dongDien->soLuong );
      printf( "  Bán kính nội: %5.1f mm\n", dongDien->thongTin.phanHinhTron.banKinhNoi );
      printf( "  Bán kính ngoại: %5.1f mm\n", dongDien->thongTin.phanHinhTron.banKinhNgoai );
      printf( "  Chiều rộng: %5.1f rad\n", dongDien->thongTin.phanHinhTron.chieuRongGoc );
      printf( "  Cách từ trung tâm xoay: %5.1f mm\n", dongDien->cachTuTrungTam );
      
      if( dongDien->thongTin.phanHinhTron.banKinhNoi == dongDien->thongTin.phanHinhTron.banKinhNgoai ) {
         printf( "\nVẤN ĐỀ: Dòng điện phần hình tròn: bán kính nội = bán kính ngoại\n" );
         exit(3);
      }
      if( dongDien->thongTin.phanHinhTron.chieuRongGoc == 0.0 ) {
         printf( "\nVẤN ĐỀ: Dòng điện phần hình tròn: cách từ trung tâm = 0.0 rad\n" );
         exit(3);
      }
   }
   else if( loaiDongDien == kDONG_DIEN__HINH_TRON ) {
      printf( "  Loại: Hình tròn\n" );
      printf( "  Số lượng: %d\n", dongDien->soLuong );
      printf( "  Bán kính: %5.1f mm\n", dongDien->thongTin.hinhTron.banKinh );
      printf( "  Cách từ trung tâm xoay: %5.1f mm\n", dongDien->cachTuTrungTam );
      
      if( dongDien->thongTin.hinhTron.banKinh == 0.0 ) {
         printf( "\nVẤN ĐỀ: Dòng điện hình tròn: bán kính = 0.0 mm\n" );
         exit(3);
      }
   }
   else {
      printf( "\nVẤN ĐỀ: Loại dòng điện: Không biết\n" );
      exit(3);
   }
   
   // ---- kiểm tra thông tin dòng điện
   if( dongDien->soLuong == 0 ) {
      printf( "\nVẤN ĐỀ: Dòng điện: số lượng %d\n", dongDien->soLuong );
      exit(3);
   }
   if( dongDien->cachTuTrungTam == 0.0 ) {
      printf( "\nVẤN ĐỀ: Dòng điện: khoảng cách từ trung tâm xoay: %5.1f mm\n", dongDien->cachTuTrungTam );
      exit(3);
   }
   
}
