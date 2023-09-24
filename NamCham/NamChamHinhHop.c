// Nam Châm Hình Hợp.c
// 2023.09.04

#include <math.h>
#include "NamChamHinhHop.h"
#include "../HangSo.h"
#include <stdio.h>  // bỏ sau

#pragma mark ==== Đặt Vị Trí Mảng Nam Châm
void datViTriMangNamChamHinhHopDeu( NamChamHinhHop *mangNamCham, unsigned char soNamCham, double cuongDo,
                            double chieuDai, double chieuRong, double chieuCao, double cachTuTrungTam, double doCao ) {
   
   unsigned char chiSoNamCham = 0;
   double goc = 0.0;                  // radian
   double gocBuoc = k2_PI/soNamCham;  // radian
   
   while( chiSoNamCham < soNamCham ) {
      
      NamChamHinhHop *namCham = &(mangNamCham[chiSoNamCham]);
      namCham->chieuDai = chieuDai;
      namCham->chieuRong = chieuRong;
      namCham->chieuCao = chieuCao;
      namCham->cuongDo = cuongDo;
      
      namCham->viTri.x = cachTuTrungTam*cos( goc );
      namCham->viTri.y = cachTuTrungTam*sin( goc );
      namCham->viTri.z = doCao;
      
      namCham->gocXoay = goc;

      goc += gocBuoc;
      chiSoNamCham++;
   }
   
}

/*
 • Tính từ trường của năm châm hình hộp chữ nhật hay hình trụ
 • Tính tích phân của định luật Biot-Savart bằng CẦU PHƯƠNG GAUS (4 điểm từng khúc)
 • Nó tính tương đối trung tâm nam châm
 • Có thể chỉnh số lượng khúc ngang và độc đọc lập nhau
 • Trục của năm châm theo hướng Z
 */

/*
 B = (µ_0/4π) • ∫∫ (M x r) / r^3  dS
 
 M - vectơ cường độ nam châm, từng chiều dài (A/m)
 r - vectơ vị trí - x; y; z  ( m)
 r = √(x^2+ y^2 + z^2)  m
 
 -------------
 Cho nam châm hình trụ có bán kính R
 Điểm tính từ trường trên trục z:
 r = X; y; z
 r = x; Y; z
 r = X; y; z
 r = x; Y; z
 
 M = 0; M; 0
 M = -M; đ; 0
 M = 0; -M; 0
 M = M; 0; 0
 
 B = (µ_0/4π) M •
     ∫∫[z; 0; –X]/(X^2 + y^2 + z^2)^(3/2) dy dz
     ∫∫[0; z; –Y]/(x^2 + Y^2 + z^2)^(3/2) dx dz
     ∫∫[-z; 0; X]/(X^2 + y^2 + z^2)^(3/2) dy dz
     ∫∫[0; -z; Y]/(x^2 + Y^2 + z^2)^(3/2) dx dz
 
 B = 2(µ_0/4π) M •
     ∫∫[z; 0; –X]/(X^2 + y^2 + z^2)^(3/2) dy dz
     ∫∫[0; z; –Y]/(x^2 + Y^2 + z^2)^(3/2) dx dz

 
  B = 2•(µ_0/4π) M •
 ∫[1/(X^2 + y^2 + z_1^2)^(1/2) - 1/(X^2 + y^2 + z_2^2)^(1/2)] dy ; 0;
       –X•∫[z_2/[(X^2 + y^2)(X^2 + y^2 + z_2^2)^(1/2)] - z_1/[(X^2 + y^2)(X^2 + y^2 + z_1^2)^(1/2)]] dy
 
       + 0; ∫[1/(x^2 + Y^2 + z_1^2)^(1/2) - 1/(x^2 + Y^2 + z_2^2)^(1/2)] dy ;
       –Y•∫[z_2/[(x^2 + Y^2)(x^2 + Y^2 + z_2^2)^(1/2)] - z_1/[(x^2 + Y^2)(x^2 + Y^2 + z_1^2)^(1/2)]] dx
 
 B = 2•(µ_0/4π) M •
 [y_2/(X^2 + z_2^2)(X^2 + y_2^2 + z_2^2)^(1/2) - y_1/(X^2 + z_2^2)(X^2 + y_1^2 + z_2^2)^(1/2)]
 – [y_2/(X^2 + z_1^2)(X^2 + y_2^2 + z_1^2)^(1/2) + y_1/(X^2 + z_1^2)(X^2 + y_1^2 + z_1^2)^(1/2)]; 0;
 
 atan[z_2•y_2 /(X•√(X^2 + y_2^2 + z_2^2)^(1/2))] - atan[z_1•y_2 /(X•√(X^2 + y_2^2 + z_1^2)^(1/2))]
 – atan[z_2•y_1 /(X•√(X^2 + y_1^2 + z_2^2)^(1/2))] + atan[z_1•y_1 /(X•√(X^2 + y_1^2 + z_1^2)^(1/2))]
 
 
 [x_2/(Y^2 + z_2^2)(x_2^2 + y_2^2 + z_2^2)^(1/2) - x_1/(Y^2 + z_2^2)(x_1^2 + Y^2 + z_2^2)^(1/2)]
 – [x_2/(Y^2 + z_1^2)(x_2^2 + y_2^2 + z_1^2)^(1/2) + x_1/(X^2 + z_1^2)(x_1^2 + Y^2 + z_1^2)^(1/2)]; 0;
 
 atan[z_2•x_2 /(Y•√(x_2^2 + Y^2 + z_2^2)^(1/2))] - atan[z_1•x_2 /(Y•√(x_2^2 + Y^2 + z_1^2)^(1/2))]
 – atan[z_2•x_1 /(X•√(x_1^2 + Y^2 + z_2^2)^(1/2))] + atan[z_1•y_1 /(Y•√(x_1^2 + Y^2 + z_1^2)^(1/2))]
 
 
 
 
 -----------
 lim z_2 -> ∞ và  lim z_1 -> –∞
 B_z = (µ_0/4π) • 2π • M • R^2 [1 + 1]
 B_z = (µ_0/4π) • 4π • M • R^2
 µ_0/4π = 10^–7 H/m
 */

/*
 B = A/(e_o • c^2)
 
 4π • e_o • c^2 = 10–7 ---> e_o • c^2 = 10–7 / 4π
 
 */

#pragma mark ---- Kiểm Tra Kết Quả Trên Trục Z
// ----- từ trường trên trục z chỉ có thành phần z
//       công thức cho tính từ trường của nam châm hình trụ
float tinhTuTruongTrenTrucHinhHop( float viTriZ, double chieuDai, double chieuRong, double chieuCao, double cuongDo ) {
   
   double nuaChieuDai = chieuDai*0.5;
   double nuaChieuRong = chieuRong*0.5;
   double nuaChieuCao = chieuCao*0.5;

   double xPhai = nuaChieuDai;
   double xTrai = -nuaChieuDai;
   
   double yTruoc = nuaChieuRong;
   double ySau = -nuaChieuRong;
   
   double zTren = nuaChieuCao - viTriZ;
   double zDuoi = -nuaChieuCao - viTriZ;

   // B_z = –(µ_0/4π) • 2 •
   /*    atan[z_2•y_2 /(X•√(X^2 + y_2^2 + z_2^2)^(1/2))] - atan[z_1•y_2 /(X•√(X^2 + y_2^2 + z_1^2)^(1/2))]
    – atan[z_2•y_1 /(X•√(X^2 + y_1^2 + z_2^2)^(1/2))] + atan[z_1•y_1 /(X•√(X^2 + y_1^2 + z_1^2)^(1/2))]
   
      atan[z_2•x_2 /(Y•√(x_2^2 + Y^2 + z_2^2)^(1/2))] - atan[z_1•x_2 /(Y•√(x_2^2 + Y^2 + z_1^2)^(1/2))]
    – atan[z_2•x_1 /(X•√(x_1^2 + Y^2 + z_2^2)^(1/2))] + atan[z_1•y_1 /(Y•√(x_1^2 + Y^2 + z_1^2)^(1/2))]
 */
   // ---- hướng y
   float cach = sqrtf( nuaChieuDai*nuaChieuDai + yTruoc*yTruoc + zTren*zTren );
   float ketQua0_y = zTren*yTruoc/(nuaChieuDai*cach);
   
   cach = sqrtf( nuaChieuDai*nuaChieuDai + yTruoc*yTruoc + zDuoi*zDuoi );
   float ketQua1_y = zDuoi*yTruoc/(nuaChieuDai*cach);
   
   cach = sqrtf( nuaChieuDai*nuaChieuDai + ySau*ySau + zTren*zTren );
   float ketQua2_y = zTren*ySau/(nuaChieuDai*cach);
   
   cach = sqrtf( nuaChieuDai*nuaChieuDai + ySau*ySau + zDuoi*zDuoi );
   float ketQua3_y = zDuoi*ySau/(nuaChieuDai*cach);
   
   // ---- hướng x
   cach = sqrtf( xPhai*xPhai + nuaChieuRong*nuaChieuRong + zTren*zTren );
   float ketQua0_x = zTren*xPhai/(nuaChieuDai*cach);
   
   cach = sqrtf( xPhai*xPhai + nuaChieuRong*nuaChieuRong + zDuoi*zDuoi );
   float ketQua1_x = zDuoi*xPhai/(nuaChieuDai*cach);
   
   cach = sqrtf( xTrai*xTrai + nuaChieuRong*nuaChieuRong + zTren*zTren );
   float ketQua2_x = zTren*xTrai/(nuaChieuDai*cach);
   
   cach = sqrtf( xTrai*xTrai + nuaChieuRong*nuaChieuRong + zDuoi*zDuoi );
   float ketQua3_x = zDuoi*xTrai/(nuaChieuDai*cach);

   
   float tuTruongZ = atanf( ketQua0_y ) - atanf( ketQua1_y ) - atanf( ketQua2_y ) + atanf( ketQua3_y );
   tuTruongZ += atanf( ketQua0_x ) - atanf( ketQua1_x ) - atanf( ketQua2_x ) + atanf( ketQua3_x );
   tuTruongZ *= kHANG_SO_TU_TRUONG*cuongDo*2.0f;
   
   return tuTruongZ;
}


// Tín từ trường B (đơn vị Telsa)
// tính tương đối với trung tâm nam châm
// cường độ - A/mm
Vecto tinhTuTruongNamTramHinhHopMoi( Vecto *viTri, NamChamHinhHop *namCham,
                                 unsigned short soDoanX, unsigned short soDoanY ) {
   
   // ==== chuẩn bị
   // ---- cỡ thước
   double chieuDai = namCham->chieuDai;
   double chieuRong = namCham->chieuRong;
   double chieuCao = namCham->chieuCao;
   
   double nuaChieuDai = chieuDai*0.5;
   double nuaChieuRong = chieuRong*0.5;
   
   // ---- cho đoạn chu vi
   double phongToX = nuaChieuDai/soDoanX;  // tỉ số cho đoạn cầu phương Gauss
   double chieuRongDoanX = chieuDai/soDoanX;
   
   double phongToY = nuaChieuRong/soDoanY;  // tỉ số cho đoạn cầu phương Gauss
   double chieuRongDoanY = chieuRong/soDoanY;
   
   double zTren = viTri->z - 0.5*chieuCao;
   double zDuoi = viTri->z + 0.5*chieuCao;
   
   // ---- xóa từ trường
   Vecto tuTruong;
   tuTruong.x = 0.0;
   tuTruong.y = 0.0;
   tuTruong.z = 0.0;
   
   // ==== bắt đầu tính
   double trungTamDoanXDau = chieuRongDoanX*0.5 - nuaChieuDai;
   double trungTamDoanYDau = chieuRongDoanY*0.5 - nuaChieuRong;

   double xTrenNamCham = nuaChieuDai;

   // ---- vị trí tương đối nam châm
   Vecto viTriTuongDoi;

   // ==== hướng +x
   viTriTuongDoi.x = viTri->x - xTrenNamCham;
   double trungTamDoanY = trungTamDoanYDau;
   unsigned short chiSoDoanY = 0;
   while( chiSoDoanY < soDoanY ) {
      // ==== 0
      double yTrenNamCham = phongToY*kGAUSS_DIEM_0 + trungTamDoanY;
      viTriTuongDoi.y = viTri->y - yTrenNamCham;

      // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
      double cachXYBinh = viTriTuongDoi.x*viTriTuongDoi.x + viTriTuongDoi.y*viTriTuongDoi.y;
      double cachTren = sqrt( cachXYBinh + zTren*zTren );
      double cachDuoi = sqrt( cachXYBinh + zDuoi*zDuoi );
      
      double daoNghichTren = 1.0/cachTren;
      double daoNghichDuoi = 1.0/cachDuoi;
      
      // ---- góp phần vào từ trường
      tuTruong.x += kGAUSS_QUYEN_LUONG_0*phongToY*(daoNghichDuoi - daoNghichTren);
      tuTruong.z -= kGAUSS_QUYEN_LUONG_0*phongToY*viTriTuongDoi.x/cachXYBinh*(zTren*daoNghichTren - zDuoi*daoNghichDuoi);
      
      // ==== 1
      yTrenNamCham = phongToY*kGAUSS_DIEM_1 + trungTamDoanY;
      viTriTuongDoi.y = viTri->y - yTrenNamCham;

      // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
      cachXYBinh = viTriTuongDoi.x*viTriTuongDoi.x + viTriTuongDoi.y*viTriTuongDoi.y;
      cachTren = sqrt( cachXYBinh + zTren*zTren );
      cachDuoi = sqrt( cachXYBinh + zDuoi*zDuoi );
      
      daoNghichTren = 1.0/cachTren;
      daoNghichDuoi = 1.0/cachDuoi;
      
      // ---- góp phần vào từ trường
      tuTruong.x += kGAUSS_QUYEN_LUONG_1*phongToY*(daoNghichDuoi - daoNghichTren);
      tuTruong.z -= kGAUSS_QUYEN_LUONG_1*phongToY*viTriTuongDoi.x/cachXYBinh*(zTren*daoNghichTren - zDuoi*daoNghichDuoi);
      
      // ==== 2
      yTrenNamCham = phongToY*kGAUSS_DIEM_2 + trungTamDoanY;
      viTriTuongDoi.y = viTri->y - yTrenNamCham;

      // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
      cachXYBinh = viTriTuongDoi.x*viTriTuongDoi.x + viTriTuongDoi.y*viTriTuongDoi.y;
      cachTren = sqrt( cachXYBinh + zTren*zTren );
      cachDuoi = sqrt( cachXYBinh + zDuoi*zDuoi );
      
      daoNghichTren = 1.0/cachTren;
      daoNghichDuoi = 1.0/cachDuoi;
      
      // ---- góp phần vào từ trường
      tuTruong.x += kGAUSS_QUYEN_LUONG_2*phongToY*(daoNghichDuoi - daoNghichTren);
      tuTruong.z -= kGAUSS_QUYEN_LUONG_2*phongToY*viTriTuongDoi.x/cachXYBinh*(zTren*daoNghichTren - zDuoi*daoNghichDuoi);
      
      // ==== 3
      yTrenNamCham = phongToY*kGAUSS_DIEM_3 + trungTamDoanY;
      viTriTuongDoi.y = viTri->y - yTrenNamCham;

      // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
      cachXYBinh = viTriTuongDoi.x*viTriTuongDoi.x + viTriTuongDoi.y*viTriTuongDoi.y;
      cachTren = sqrt( cachXYBinh + zTren*zTren );
      cachDuoi = sqrt( cachXYBinh + zDuoi*zDuoi );
      
      daoNghichTren = 1.0/cachTren;
      daoNghichDuoi = 1.0/cachDuoi;
      
      // ---- góp phần vào từ trường
      tuTruong.x += kGAUSS_QUYEN_LUONG_3*phongToY*(daoNghichDuoi - daoNghichTren);
      tuTruong.z -= kGAUSS_QUYEN_LUONG_3*phongToY*viTriTuongDoi.x/cachXYBinh*(zTren*daoNghichTren - zDuoi*daoNghichDuoi);

      trungTamDoanY += chieuRongDoanY;
      chiSoDoanY++;
   }
   
   // ==== hướng +y
   double yTrenNamCham = nuaChieuRong;
   viTriTuongDoi.y = viTri->y - yTrenNamCham;
   double trungTamDoanX = trungTamDoanXDau;
   unsigned char chiSoDoanX = 0;
   while( chiSoDoanX < soDoanX ) {
      // ==== 0
      double xTrenNamCham = phongToX*kGAUSS_DIEM_0 + trungTamDoanX;
      viTriTuongDoi.x = viTri->x - xTrenNamCham;

      // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
      double cachXYBinh = viTriTuongDoi.x*viTriTuongDoi.x + viTriTuongDoi.y*viTriTuongDoi.y;
      double cachTren = sqrt( cachXYBinh + zTren*zTren );
      double cachDuoi = sqrt( cachXYBinh + zDuoi*zDuoi );
      
      double daoNghichTren = 1.0/cachTren;
      double daoNghichDuoi = 1.0/cachDuoi;
      
      // ---- góp phần vào từ trường
      tuTruong.y += kGAUSS_QUYEN_LUONG_0*phongToX*(daoNghichDuoi - daoNghichTren);
      tuTruong.z -= kGAUSS_QUYEN_LUONG_0*phongToX*viTriTuongDoi.y/cachXYBinh*(zTren*daoNghichTren - zDuoi*daoNghichDuoi);
      
      // ==== 1
      xTrenNamCham = phongToX*kGAUSS_DIEM_1 + trungTamDoanX;
      viTriTuongDoi.x = viTri->x - xTrenNamCham;

      // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
      cachXYBinh = viTriTuongDoi.x*viTriTuongDoi.x + viTriTuongDoi.y*viTriTuongDoi.y;
      cachTren = sqrt( cachXYBinh + zTren*zTren );
      cachDuoi = sqrt( cachXYBinh + zDuoi*zDuoi );
      
      daoNghichTren = 1.0/cachTren;
      daoNghichDuoi = 1.0/cachDuoi;
      
      // ---- góp phần vào từ trường
      tuTruong.y += kGAUSS_QUYEN_LUONG_1*phongToY*(daoNghichDuoi - daoNghichTren);
      tuTruong.z -= kGAUSS_QUYEN_LUONG_1*phongToY*viTriTuongDoi.y/cachXYBinh*(zTren*daoNghichTren - zDuoi*daoNghichDuoi);
      
      // ==== 2
      xTrenNamCham = phongToX*kGAUSS_DIEM_2 + trungTamDoanX;
      viTriTuongDoi.x = viTri->x - xTrenNamCham;

      // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
      cachXYBinh = viTriTuongDoi.x*viTriTuongDoi.x + viTriTuongDoi.y*viTriTuongDoi.y;
      cachTren = sqrt( cachXYBinh + zTren*zTren );
      cachDuoi = sqrt( cachXYBinh + zDuoi*zDuoi );
      
      daoNghichTren = 1.0/cachTren;
      daoNghichDuoi = 1.0/cachDuoi;
      
      // ---- góp phần vào từ trường
      tuTruong.y += kGAUSS_QUYEN_LUONG_2*phongToY*(daoNghichDuoi - daoNghichTren);
      tuTruong.z -= kGAUSS_QUYEN_LUONG_2*phongToY*viTriTuongDoi.y/cachXYBinh*(zTren*daoNghichTren - zDuoi*daoNghichDuoi);
      
      // ==== 3
      xTrenNamCham = phongToX*kGAUSS_DIEM_3 + trungTamDoanX;
      viTriTuongDoi.x = viTri->x - xTrenNamCham;

      // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
      cachXYBinh = viTriTuongDoi.x*viTriTuongDoi.x + viTriTuongDoi.y*viTriTuongDoi.y;
      cachTren = sqrt( cachXYBinh + zTren*zTren );
      cachDuoi = sqrt( cachXYBinh + zDuoi*zDuoi );
      
      daoNghichTren = 1.0/cachTren;
      daoNghichDuoi = 1.0/cachDuoi;
      
      // ---- góp phần vào từ trường
      tuTruong.y += kGAUSS_QUYEN_LUONG_3*phongToX*(daoNghichDuoi - daoNghichTren);
      tuTruong.z -= kGAUSS_QUYEN_LUONG_3*phongToX*viTriTuongDoi.y/cachXYBinh*(zTren*daoNghichTren - zDuoi*daoNghichDuoi);

      trungTamDoanX += chieuRongDoanX;
      chiSoDoanX++;
   }

   // ==== hướng -x
   viTriTuongDoi.x = viTri->x + xTrenNamCham;
   trungTamDoanY = trungTamDoanYDau;
   chiSoDoanY = 0;
   while( chiSoDoanY < soDoanY ) {
      // ==== 0
      double yTrenNamCham = phongToY*kGAUSS_DIEM_0 + trungTamDoanY;
      viTriTuongDoi.y = viTri->y - yTrenNamCham;

      // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
      double cachXYBinh = viTriTuongDoi.x*viTriTuongDoi.x + viTriTuongDoi.y*viTriTuongDoi.y;
      double cachTren = sqrt( cachXYBinh + zTren*zTren );
      double cachDuoi = sqrt( cachXYBinh + zDuoi*zDuoi );
      
      double daoNghichTren = 1.0/cachTren;
      double daoNghichDuoi = 1.0/cachDuoi;
      
      // ---- góp phần vào từ trường
      tuTruong.x -= kGAUSS_QUYEN_LUONG_0*phongToY*(daoNghichDuoi - daoNghichTren);
      tuTruong.z += kGAUSS_QUYEN_LUONG_0*phongToY*viTriTuongDoi.x/cachXYBinh*(zTren*daoNghichTren - zDuoi*daoNghichDuoi);
      
      // ==== 1
      yTrenNamCham = phongToY*kGAUSS_DIEM_1 + trungTamDoanY;
      viTriTuongDoi.y = viTri->y - yTrenNamCham;

      // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
      cachXYBinh = viTriTuongDoi.x*viTriTuongDoi.x + viTriTuongDoi.y*viTriTuongDoi.y;
      cachTren = sqrt( cachXYBinh + zTren*zTren );
      cachDuoi = sqrt( cachXYBinh + zDuoi*zDuoi );
      
      daoNghichTren = 1.0/cachTren;
      daoNghichDuoi = 1.0/cachDuoi;
      
      // ---- góp phần vào từ trường
      tuTruong.x -= kGAUSS_QUYEN_LUONG_1*phongToY*(daoNghichDuoi - daoNghichTren);
      tuTruong.z += kGAUSS_QUYEN_LUONG_1*phongToY*viTriTuongDoi.x/cachXYBinh*(zTren*daoNghichTren - zDuoi*daoNghichDuoi);
      
      // ==== 2
      yTrenNamCham = phongToY*kGAUSS_DIEM_2 + trungTamDoanY;
      viTriTuongDoi.y = viTri->y - yTrenNamCham;

      // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
      cachXYBinh = viTriTuongDoi.x*viTriTuongDoi.x + viTriTuongDoi.y*viTriTuongDoi.y;
      cachTren = sqrt( cachXYBinh + zTren*zTren );
      cachDuoi = sqrt( cachXYBinh + zDuoi*zDuoi );
      
      daoNghichTren = 1.0/cachTren;
      daoNghichDuoi = 1.0/cachDuoi;
      
      // ---- góp phần vào từ trường
      tuTruong.x -= kGAUSS_QUYEN_LUONG_2*phongToY*(daoNghichDuoi - daoNghichTren);
      tuTruong.z += kGAUSS_QUYEN_LUONG_2*phongToY*viTriTuongDoi.x/cachXYBinh*(zTren*daoNghichTren - zDuoi*daoNghichDuoi);
      
      // ==== 3
      yTrenNamCham = phongToY*kGAUSS_DIEM_3 + trungTamDoanY;
      viTriTuongDoi.y = viTri->y - yTrenNamCham;

      // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
      cachXYBinh = viTriTuongDoi.x*viTriTuongDoi.x + viTriTuongDoi.y*viTriTuongDoi.y;
      cachTren = sqrt( cachXYBinh + zTren*zTren );
      cachDuoi = sqrt( cachXYBinh + zDuoi*zDuoi );
      
      daoNghichTren = 1.0/cachTren;
      daoNghichDuoi = 1.0/cachDuoi;
      
      // ---- góp phần vào từ trường
      tuTruong.x -= kGAUSS_QUYEN_LUONG_3*phongToY*(daoNghichDuoi - daoNghichTren);
      tuTruong.z += kGAUSS_QUYEN_LUONG_3*phongToY*viTriTuongDoi.x/cachXYBinh*(zTren*daoNghichTren - zDuoi*daoNghichDuoi);

      trungTamDoanY += chieuRongDoanY;
      chiSoDoanY++;
   }
   
   // ==== hướng -y
   yTrenNamCham = nuaChieuRong;
   viTriTuongDoi.y = viTri->y + yTrenNamCham;
   trungTamDoanX = trungTamDoanXDau;
   chiSoDoanX = 0;
   while( chiSoDoanX < soDoanX ) {
      // ==== 0
      double xTrenNamCham = phongToX*kGAUSS_DIEM_0 + trungTamDoanX;
      viTriTuongDoi.x = viTri->x - xTrenNamCham;

      // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
      double cachXYBinh = viTriTuongDoi.x*viTriTuongDoi.x + viTriTuongDoi.y*viTriTuongDoi.y;
      double cachTren = sqrt( cachXYBinh + zTren*zTren );
      double cachDuoi = sqrt( cachXYBinh + zDuoi*zDuoi );
      
      double daoNghichTren = 1.0/cachTren;
      double daoNghichDuoi = 1.0/cachDuoi;
      
      // ---- góp phần vào từ trường
      tuTruong.y -= kGAUSS_QUYEN_LUONG_0*phongToX*(daoNghichDuoi - daoNghichTren);
      tuTruong.z += kGAUSS_QUYEN_LUONG_0*phongToX*viTriTuongDoi.y/cachXYBinh*(zTren*daoNghichTren - zDuoi*daoNghichDuoi);
      
      // ==== 1
      xTrenNamCham = phongToX*kGAUSS_DIEM_1 + trungTamDoanX;
      viTriTuongDoi.x = viTri->x - xTrenNamCham;

      // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
      cachXYBinh = viTriTuongDoi.x*viTriTuongDoi.x + viTriTuongDoi.y*viTriTuongDoi.y;
      cachTren = sqrt( cachXYBinh + zTren*zTren );
      cachDuoi = sqrt( cachXYBinh + zDuoi*zDuoi );
      
      daoNghichTren = 1.0/cachTren;
      daoNghichDuoi = 1.0/cachDuoi;
      
      // ---- góp phần vào từ trường
      tuTruong.y -= kGAUSS_QUYEN_LUONG_1*phongToY*(daoNghichDuoi - daoNghichTren);
      tuTruong.z += kGAUSS_QUYEN_LUONG_1*phongToY*viTriTuongDoi.y/cachXYBinh*(zTren*daoNghichTren - zDuoi*daoNghichDuoi);
      
      // ==== 2
      xTrenNamCham = phongToX*kGAUSS_DIEM_2 + trungTamDoanX;
      viTriTuongDoi.x = viTri->x - xTrenNamCham;

      // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
      cachXYBinh = viTriTuongDoi.x*viTriTuongDoi.x + viTriTuongDoi.y*viTriTuongDoi.y;
      cachTren = sqrt( cachXYBinh + zTren*zTren );
      cachDuoi = sqrt( cachXYBinh + zDuoi*zDuoi );
      
      daoNghichTren = 1.0/cachTren;
      daoNghichDuoi = 1.0/cachDuoi;
      
      // ---- góp phần vào từ trường
      tuTruong.y -= kGAUSS_QUYEN_LUONG_2*phongToY*(daoNghichDuoi - daoNghichTren);
      tuTruong.z += kGAUSS_QUYEN_LUONG_2*phongToY*viTriTuongDoi.y/cachXYBinh*(zTren*daoNghichTren - zDuoi*daoNghichDuoi);
      
      // ==== 3
      xTrenNamCham = phongToX*kGAUSS_DIEM_3 + trungTamDoanX;
      viTriTuongDoi.x = viTri->x - xTrenNamCham;

      // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
      cachXYBinh = viTriTuongDoi.x*viTriTuongDoi.x + viTriTuongDoi.y*viTriTuongDoi.y;
      cachTren = sqrt( cachXYBinh + zTren*zTren );
      cachDuoi = sqrt( cachXYBinh + zDuoi*zDuoi );
      
      daoNghichTren = 1.0/cachTren;
      daoNghichDuoi = 1.0/cachDuoi;
      
      // ---- góp phần vào từ trường
      tuTruong.y -= kGAUSS_QUYEN_LUONG_3*phongToX*(daoNghichDuoi - daoNghichTren);
      tuTruong.z += kGAUSS_QUYEN_LUONG_3*phongToX*viTriTuongDoi.y/cachXYBinh*(zTren*daoNghichTren - zDuoi*daoNghichDuoi);

      trungTamDoanX += chieuRongDoanX;
      chiSoDoanX++;
   }

   // ---- cuối cùng nhân hằng số từ trường và tỉ sô phóng to, và bbán kính nam châm
   double cuongDo = namCham->cuongDo;
   tuTruong.x *= -kHANG_SO_TU_TRUONG*cuongDo;
   tuTruong.y *= -kHANG_SO_TU_TRUONG*cuongDo;
   tuTruong.z *= -kHANG_SO_TU_TRUONG*cuongDo;

   return tuTruong;
}


/*
 B = -(µ_o/4π) ∫∫ (M x r) dS/ r^3
 
 Cho trường hợp này M = (Mx; M_y; 0)
 M_x  M_y  0
 r_x  r_y  z
 
 = (M_y•z; –M_x•z; M_x•r_y – M_y•r_x)
 
 +x:  (r_x = x_2)
 M = (0; M; 0)
 r = (x_2; y; z)
 M x r = (M•z; 0; –M•x_2)
 
 R = (x_2^2 + y^2 + z^2))
 B = –∫∫(M•z; 0; –M•x_2)/R^(3/2) dydz
 B = M∫∫(–z; 0; +x_2)/R^(3/2) dydz
 
 B_x = M∫∫–z//R^(3/2) dydz
 B_x = M ∫[1/√(x_2^2 + y^2 + z_2^2)
 - 1/√(x_2^2 + y^2 + z_1^2)] dy
 
 = M {asinh[y_2/√[x_2^2 + z_2^2]
 - asinh[y_1/√[x_2^2 + z_2^2]]
 - asinh[y_2/√[x_2^2 + z_1^2]]
 + asinh[y_1/√[x_2^2 + z_1^2]]}
 
 
 B_y = 0
 
 B_z = M•x_2•∫[z_2/{(x_2^2 + y^2)√(x_2^2 + y^2 + z_2^2)}
 – z_1/{(x_2^2 + y^2)√(x_2^2 + y^2 + z_1^2)] dy
 
 B_z = M [atan(y_2•z_2)/{x_2•√(x_2^2 + y_2^2 + z_2^2)
 - atan(y_1•z_2)/{x_2•√(x_2^2 + y_1^2 + z_2^2)
 - atan(y_2•z_1)/{x_2•√(x_2^2 + y_2^2 + z_1^2)
 + atan(y_1•z_1)/{x_2•√(x_2^2 + y_1^2 + z_1^2)]
 
 ----------------------------
 +y:  (r_y = y_2)
 M = (–M; 0; 0)
 r = (x; y_2; z)
 M x r = (0; +M•z; –M•y_2)
 
 R = (x^2 + y_2^2 + z^2))
 B = –∫∫(0; +M•z; –M•y_2)/R^(3/2) dxdz
 B = M∫∫(0; –z; +y_2)/R^(3/2) dxdz
 
 B_y = –M∫∫z//R^(3/2) dxdz
 
 B_y = M ∫[1/√(x^2 + y_2^2 + z_2^2) - 1/√(x^2 + y_2^2 + z_1^2)] dx
 = M {asinh[x_2/√[y_2^2 + z_2^2]]
 - asinh[x_1/√[y_2^2 + z_2^2]]
 - asinh[x_2/√[y_2^2 + z_1^2]]
 + asinh[x_1/√[y_2^2 + z_1^2]]}
 
 B_z = –M [atan(x_2•z_2)/{y_1•√(x_2^2 + y_2^2 + z_2^2)
 - atan(x_1•z_2)/{y_1•√(x_1^2 + y_2^2 + z_2^2)
 - atan(x_2•z_1)/{y_1•√(x_2^2 + y_2^2 + z_1^2)
 + atan(x_1•z_1)/{y_1•√(x_1^2 + y_2^2 + z_1^2)]
 
 ----------------------------
 –x:  (r_x = x_1)
 M = (0; –M; 0)
 r = (x_1; y; z)
 M x r = (–M•z; 0; +M•x_2)
 
 R = (x_1^2 + y^2 + z^2))
 B = –∫∫(–M•z; 0; +M•x_2)/R^(3/2) dydz
 B = M∫∫(z; 0; –x_2)/R^(3/2) dydz
 
 B_x = M∫∫z//R^(3/2) dydz
 B_x = –M ∫[1/√(x_2^2 + y^2 + z_2^2) - 1/√(x_2^2 + y^2 + z_1^2)] dy
 
 B_x = M ∫[1/√(x_2^2 + y^2 + z_2^2) - 1/√(x_2^2 + y^2 + z_1^2)] dy
 = –M {asinh[y_2/√[x_1^2 + z_2^2]]
 - asinh[y_1/√[x_1^2 + z_2^2]]
 - asinh[y_2/√[x_1^2 + z_1^2]]
 + asinh[y_1/√[x_1^2 + z_1^2]]}
 
 B_z = –M [atan(y_2•z_2)/{x_1•√(x_1^2 + y_2^2 + z_2^2)
 - atan(y_1•z_2)/{x_1•√(x_1^2 + y_1^2 + z_2^2)
 - atan(y_2•z_1)/{x_1•√(x_1^2 + y_2^2 + z_1^2)
 + atan(y_1•z_1)/{x_1•√(x_1^2 + y_1^2 + z_1^2)]
 
 ----------------------------
 -y:  (r_y = y_1)
 M = (M; 0; 0)
 r = (x; y_1; z)
 M x r = (0; –M•z; M•y_1)
 
 R = (x^2 + y_1^2 + z^2))
 B = –∫∫(0; –M•z; M•y_1)/R^(3/2) dxdz
 B = M∫∫(0; z; –y_1)/R^(3/2) dxdz
 
 
 B_x = 0
 B_y = M∫∫z//R^(3/2) dxdz
 
 B_y = –M ∫[1/√(x^2 + y_2^2 + z_2^2) - 1/√(x^2 + y_2^2 + z_1^2)] dx
 = –M {asinh[x_2/√[y_1^2 + z_2^2]]
 - asinh[x_1/√[y_1^2 + z_2^2]]
 - asinh[x_2/√[y_1^2 + z_1^2]]
 + asinh[x_1/√[y_1^2 + z_1^2]]}
 
 
 B_z = –M [atan(x_2•z_2)/{y_1•√(x_2^2 + y_1^2 + z_2^2)
 - atan(x_1•z_2)/{y_1•√(x_1^2 + y_1^2 + z_2^2)
 - atan(x_2•z_1)/{y_1•√(x_2^2 + y_1^2 + z_1^2)
 + atan(x_1•z_1)/{y_1•√(x_1^2 + y_1^2 + z_1^2)]
 */



Vecto tinhTuTruongNamTramHinhHopMoi2( Vecto *viTri, NamChamHinhHop *namCham ) {
   
   // ==== chuẩn bị
   // ---- cỡ thước
   double chieuDai = namCham->chieuDai;    // |<--2X-->|
   double chieuRong = namCham->chieuRong;  // |<--2Y-->|
   double chieuCao = namCham->chieuCao;    // |<--2Z-->|
   
   double nuaChieuDai = chieuDai*0.5;      // X
   double nuaChieuRong = chieuRong*0.5;    // Y
   double nuaChieuDaiBinh = nuaChieuDai*nuaChieuDai;
   double nuaChieuRongBinh = nuaChieuRong*nuaChieuRong;

   
   double xPhai = viTri->x - 0.5*chieuDai;   // x_2
   double xTrai = viTri->x + 0.5*chieuDai;   // x_1
   double xPhaiBinh = xPhai*xPhai;
   double xTraiBinh = xTrai*xTrai;

   double yTruoc = viTri->y - 0.5*chieuRong;  // y_2
   double ySau = viTri->y + 0.5*chieuRong;    // y_1
   double yTruocBinh = yTruoc*yTruoc;
   double ySauBinh = ySau*ySau;

   double zTren = viTri->z - 0.5*chieuCao;   // z_2
   double zDuoi = viTri->z + 0.5*chieuCao;   // z_1
   double zTrenBinh = zTren*zTren;
   double zDuoiBinh = zDuoi*zDuoi;
   
   // ---- xóa từ trường
   Vecto tuTruong;
   tuTruong.x = 0.0;
   tuTruong.y = 0.0;
   tuTruong.z = 0.0;
   
   // ==== bắt đầu tính
   // ---- hướng +x
   double cachDuoi = sqrt(xPhaiBinh + zDuoi*zDuoi);
   double cachTren = sqrt(xPhaiBinh + zTren*zTren);

   tuTruong.x = asinh( yTruoc/cachDuoi ) - asinh( ySau/cachDuoi ) - asinh( yTruoc/cachTren ) + asinh( ySau/cachTren );
   
   double giaTri_0 = yTruoc*zTren;
   double giaTri_1 = ySau*zTren;
   double giaTri_2 = yTruoc*zDuoi;
   double giaTri_3 = ySau*zDuoi;

   tuTruong.z = atan( giaTri_0/(xPhai*sqrt( xPhaiBinh + yTruocBinh + zTrenBinh )) )
              - atan( giaTri_1/(xPhai*sqrt( xPhaiBinh + ySauBinh + zTrenBinh )) )
              - atan( giaTri_2/(xPhai*sqrt( xPhaiBinh + yTruocBinh + zDuoiBinh )) )
              + atan( giaTri_3/(xPhai*sqrt( xPhaiBinh + ySauBinh + zDuoiBinh )) );


   // --- huong +y
   cachDuoi = sqrt(yTruocBinh + zDuoi*zDuoi);
   cachTren = sqrt(yTruocBinh + zTren*zTren);
   
   tuTruong.y = asinh( xPhai/cachDuoi ) - asinh( xTrai/cachDuoi ) - asinh( xPhai/cachTren ) + asinh( xTrai/cachTren );
   
   giaTri_0 = xPhai*zTren;
   giaTri_1 = xTrai*zTren;
   giaTri_2 = xPhai*zDuoi;
   giaTri_3 = xTrai*zDuoi;
   
   tuTruong.z += atan( giaTri_0/(yTruoc*sqrt( xPhaiBinh + yTruocBinh + zTrenBinh  )) )
   - atan( giaTri_1/(yTruoc*sqrt( xTraiBinh + yTruocBinh + zTrenBinh )) )
   - atan( giaTri_2/(yTruoc*sqrt( xPhaiBinh + yTruocBinh + zDuoiBinh )) )
   + atan( giaTri_3/(yTruoc*sqrt( xTraiBinh + yTruocBinh + zDuoiBinh )) );
   

   // ---- hướng -x
   cachDuoi = sqrt(xTraiBinh + zDuoi*zDuoi);
   cachTren = sqrt(xTraiBinh + zTren*zTren);
   
   tuTruong.x -= asinh( yTruoc/cachDuoi ) - asinh( ySau/cachDuoi ) - asinh( yTruoc/cachTren ) + asinh( ySau/cachTren );
   
   giaTri_0 = yTruoc*zTren;
   giaTri_1 = ySau*zTren;
   giaTri_2 = yTruoc*zDuoi;
   giaTri_3 = ySau*zDuoi;
   
   tuTruong.z -= atan( giaTri_0/(xTrai*sqrt( xTraiBinh + yTruocBinh + zTrenBinh )) )
   - atan( giaTri_1/(xTrai*sqrt( xTraiBinh + ySauBinh + zTrenBinh )) )
   - atan( giaTri_2/(xTrai*sqrt( xTraiBinh + yTruocBinh + zDuoiBinh )) )
   + atan( giaTri_3/(xTrai*sqrt( xTraiBinh + ySauBinh + zDuoiBinh )) );

   
   // --- huong -y
   cachDuoi = sqrt(ySauBinh + zDuoi*zDuoi);
   cachTren = sqrt(ySauBinh + zTren*zTren);
   
   tuTruong.y -= asinh( xPhai/cachDuoi ) - asinh( xTrai/cachDuoi ) - asinh( xPhai/cachTren ) + asinh( xTrai/cachTren );
   
   giaTri_0 = xPhai*zTren;
   giaTri_1 = xTrai*zTren;
   giaTri_2 = xPhai*zDuoi;
   giaTri_3 = xTrai*zDuoi;
   
   tuTruong.z -= atan( giaTri_0/(ySau*sqrt( xPhaiBinh + ySauBinh + zTrenBinh )) )
   - atan( giaTri_1/(ySau*sqrt( xTraiBinh + ySauBinh + zTrenBinh )) )
   - atan( giaTri_2/(ySau*sqrt( xPhaiBinh + ySauBinh + zDuoiBinh )) )
   + atan( giaTri_3/(ySau*sqrt( xTraiBinh + ySauBinh + zDuoiBinh )) );

   // ---- cuối cùng nhân hằng số từ trường và tỉ sô phóng to, và bbán kính nam châm
   double cuongDo = namCham->cuongDo;
   tuTruong.x *= kHANG_SO_TU_TRUONG*cuongDo;
   tuTruong.y *= kHANG_SO_TU_TRUONG*cuongDo;
   tuTruong.z *= -kHANG_SO_TU_TRUONG*cuongDo;
   
   return tuTruong;
}
