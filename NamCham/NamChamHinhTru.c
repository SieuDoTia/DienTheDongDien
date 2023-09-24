// Nam Châm Hình Trụ.c
// 2023.08.28

#include <math.h>
#include "NamChamHinhTru.h"
#include "../HangSo.h"


#pragma mark ==== Đặt Vị Trí Mảng Nam Châm
void datViTriMangNamChamHinhTruDeu( NamChamHinhTru *mangNamCham, unsigned char soNamCham, double cuongDo,
                        double banKinhNamCham, double chieuCaoNamCham, double cachTuTrungTam, double doCao ) {
   
   unsigned char chiSoNamCham = 0;
   double goc = 0.0;                  // radian
   double gocBuoc = k2_PI/soNamCham;  // radian
   
   while( chiSoNamCham < soNamCham ) {
      
      NamChamHinhTru *namCham = &(mangNamCham[chiSoNamCham]);
      namCham->banKinh = banKinhNamCham;
      namCham->chieuCao = chieuCaoNamCham;
      namCham->cuongDo = cuongDo;
      
      namCham->viTri.x = cachTuTrungTam*cos( goc );
      namCham->viTri.y = cachTuTrungTam*sin( goc );
      namCham->viTri.z = doCao;
      
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
 
 Cho nam châm hình trụ vị trí tổng quát

 r = x - R•cos น; y - R•sin น; z
 M = -M•sin น; M•cos น; 0
 B = (µ_0/4π) M∫∫ (cos น • z; sin น • z; -(sin น • rx + cos น • ry)) • dz dน / (r_x^2 + r_y^2 + z^2)^(3/2)
 
  B = (µ_0/4π) M ∫
 
 cos น • {1/√(z1 + r_y^2 + r_x^2) – 1/√(z2^2 + r_y^2 + r_x^2)};
 
 sin น • {1/√(z1 + r_y^2 + r_x^2) – 1/√(z2^2 + r_y^2 + r_x^2)};
 
 -(sin น • ry + cos น • rx)) •
 {z_2/[(r_x^2 + r_y^2) • √(r_x^2 + r_y^2 + z_2^2)] - z_1/[(r_x^2 + r_y^2) • √(r_x^2 + r_y^2 + z_1^2)]};
 
 -------------
 Cho nam châm hình trụ có bán kính R
 Điểm tính từ trường trên trục z:
 r = R•cos น; R•sin น; z
 M = -M•sin น; M•cos น; 0
 
 B = (µ_0/4π) M • R ∫∫ [cos น • z; sin น • z; – R] / (R^2 + z^2)^(3/2) • dz dน
    = (µ_0/4π) M • R ∫ [cos น • z; sin น • z; – R] / (R^2 + z^2)^(3/2) • dน
 
 B_z = (µ_0/4π) M • R^2 ∫∫ dz dน / (R^2 + z^2)^(3/2)
 B_z = (µ_0/4π) • 2π • M • R^2 ∫ dz / (R^2 + z^2)^(3/2)
 B_z = (µ_0/4π) • 2π • M • R^2 [z/(R^3 •(z^2/R^2 + 1))]| (z_1 -> z_2)
 B_z = (µ_0/4π) • 2π • M • R^2 [z/(R^2 •(z^2 + R^2))]| (z_1 -> z_2)
 
 B_z = (µ_0/4π) • 2π • M • R^2 [z_2/(R^2 •(z_2^2 + R^2)) - z_1/(R^2 •(z_1^2 + R^2)]
 
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
float tinhTuTruongTrenTrucHinhTru( float viTriZ, double banKinh, double chieuCao, double cuongDo ) {
   
   double nuaChieuCao = chieuCao*0.5;
   
   double zTren = nuaChieuCao - viTriZ;
   double zDuoi = -nuaChieuCao - viTriZ;
   
   // B_z = –(µ_0/4π) • 2π • M • R^2 [z_2/(R^2 •(z_2^2 + R^2)) - z_1/(R^2 •(z_1^2 + R^2)]
   float duoi = zDuoi/sqrt( zDuoi*zDuoi + banKinh*banKinh );
   float tren = zTren/sqrt( zTren*zTren + banKinh*banKinh );
   
   float tuTruongZ = tren - duoi;
   tuTruongZ *= kHANG_SO_TU_TRUONG*cuongDo*banKinh*banKinh*k2_PI;
   
   return tuTruongZ;
}


// Tín từ trường B (đơn vị Telsa)
// tính tương đối với trung tâm nam châm
// cường độ - A/m
/*
Vecto tinhTuTruongNamTramHinhTru( Vecto *viTri, NamChamHinhTru *namCham, unsigned short soDoanChuVi, unsigned short soDoanZ, double *maTranQuyenLuong ) {
   
   // ==== chuẩn bị
   // ---- cỡ thước
   double chieuCao = namCham->chieuCao;
   double banKinh = namCham->banKinh;
   
   double phongToZ = chieuCao*0.5/soDoanZ;  // tỉ số cho đoạn cầu phương Gauss
   double chieuCaoDoanZ = chieuCao/soDoanZ;
   
   // ---- cho đoạn chu vi
   double phongToChuVi = kPI/soDoanChuVi;
   double chieuRongDoanChuVi = k2_PI/soDoanChuVi;
   
   // ---- xóa từ trường
   Vecto tuTruong;
   tuTruong.x = 0.0;
   tuTruong.y = 0.0;
   tuTruong.z = 0.0;
   
   // ==== bắt đầu tính
   double trungTamDoanZ = chieuCaoDoanZ*0.5 - chieuCao*0.5;
   double trungTamDoanChuViDau = chieuRongDoanChuVi*0.5;
   
   unsigned short chiSoDoanZ = 0;
   while( chiSoDoanZ < soDoanZ ) {

      // ---- hướng Z - điểm Gauss 0
      double zTrenNamCham = phongToZ*kGAUSS_DIEM_0 + trungTamDoanZ;
      // ---- vị trí tương đối nam châm
      Vecto viTriTuongDoi;
      viTriTuongDoi.z = viTri->z - zTrenNamCham;
      
      // ---- tính quanh chu vi
      double trungTamDoanChuVi = trungTamDoanChuViDau;
      unsigned short chiSoDoanChuVi = 0;
      while( chiSoDoanChuVi < soDoanChuVi ) {
         // ==== 0
         double gocChuViNamCham = phongToChuVi*kGAUSS_DIEM_0 + trungTamDoanChuVi;
         double cosGoc = cos( gocChuViNamCham );
         double sinGoc = sin( gocChuViNamCham );
         double xTrenNamCham = banKinh*cosGoc;
         double yTrenNamCham = banKinh*sinGoc;
         viTriTuongDoi.x = viTri->x - xTrenNamCham;
         viTriTuongDoi.y = viTri->y - yTrenNamCham;
         
         // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
         double cachTuNamCham = sqrt( viTriTuongDoi.x*viTriTuongDoi.x +
                                     viTriTuongDoi.y*viTriTuongDoi.y +
                                     viTriTuongDoi.z*viTriTuongDoi.z );
         double cachMu3 = cachTuNamCham*cachTuNamCham*cachTuNamCham;
         // ---- góp phần vào từ trường
         tuTruong.x += maTranQuyenLuong[0]*viTriTuongDoi.z*cosGoc/cachMu3;
         tuTruong.y += maTranQuyenLuong[0]*viTriTuongDoi.z*sinGoc/cachMu3;
         tuTruong.z -= maTranQuyenLuong[0]*(viTriTuongDoi.y*sinGoc + viTriTuongDoi.x*cosGoc)/cachMu3;
         
         // ==== 1
         gocChuViNamCham = phongToChuVi*kGAUSS_DIEM_1 + trungTamDoanChuVi;
         cosGoc = cos( gocChuViNamCham );
         sinGoc = sin( gocChuViNamCham );
         xTrenNamCham = banKinh*cosGoc;
         yTrenNamCham = banKinh*sinGoc;
         viTriTuongDoi.x = viTri->x - xTrenNamCham;
         viTriTuongDoi.y = viTri->y - yTrenNamCham;
         
         // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
         cachTuNamCham = sqrt( viTriTuongDoi.x*viTriTuongDoi.x +
                              viTriTuongDoi.y*viTriTuongDoi.y +
                              viTriTuongDoi.z*viTriTuongDoi.z );
         cachMu3 = cachTuNamCham*cachTuNamCham*cachTuNamCham;
         // ---- góp phần vào từ trường
         tuTruong.x += maTranQuyenLuong[1]*viTriTuongDoi.z*cosGoc/cachMu3;
         tuTruong.y += maTranQuyenLuong[1]*viTriTuongDoi.z*sinGoc/cachMu3;
         tuTruong.z -= maTranQuyenLuong[1]*(viTriTuongDoi.y*sinGoc + viTriTuongDoi.x*cosGoc)/cachMu3;
         
         // ==== 2
         gocChuViNamCham = phongToChuVi*kGAUSS_DIEM_2 + trungTamDoanChuVi;
         cosGoc = cos( gocChuViNamCham );
         sinGoc = sin( gocChuViNamCham );
         xTrenNamCham = banKinh*cosGoc;
         yTrenNamCham = banKinh*sinGoc;
         viTriTuongDoi.x = viTri->x - xTrenNamCham;
         viTriTuongDoi.y = viTri->y - yTrenNamCham;
         
         // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
         cachTuNamCham = sqrt( viTriTuongDoi.x*viTriTuongDoi.x +
                              viTriTuongDoi.y*viTriTuongDoi.y +
                              viTriTuongDoi.z*viTriTuongDoi.z );
         cachMu3 = cachTuNamCham*cachTuNamCham*cachTuNamCham;
         // ---- góp phần vào từ trường
         tuTruong.x += maTranQuyenLuong[2]*viTriTuongDoi.z*cosGoc/cachMu3;
         tuTruong.y += maTranQuyenLuong[2]*viTriTuongDoi.z*sinGoc/cachMu3;
         tuTruong.z -= maTranQuyenLuong[2]*(viTriTuongDoi.y*sinGoc + viTriTuongDoi.x*cosGoc)/cachMu3;
         
         // ==== 3
         gocChuViNamCham = phongToChuVi*kGAUSS_DIEM_3 + trungTamDoanChuVi;
         cosGoc = cos( gocChuViNamCham );
         sinGoc = sin( gocChuViNamCham );
         xTrenNamCham = banKinh*cosGoc;
         yTrenNamCham = banKinh*sinGoc;
         viTriTuongDoi.x = viTri->x - xTrenNamCham;
         viTriTuongDoi.y = viTri->y - yTrenNamCham;
         
         // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
         cachTuNamCham = sqrt( viTriTuongDoi.x*viTriTuongDoi.x +
                              viTriTuongDoi.y*viTriTuongDoi.y +
                              viTriTuongDoi.z*viTriTuongDoi.z );
         cachMu3 = cachTuNamCham*cachTuNamCham*cachTuNamCham;
         // ---- góp phần vào từ trường
         tuTruong.x += maTranQuyenLuong[3]*viTriTuongDoi.z*cosGoc/cachMu3;
         tuTruong.y += maTranQuyenLuong[3]*viTriTuongDoi.z*sinGoc/cachMu3;
         tuTruong.z -= maTranQuyenLuong[3]*(viTriTuongDoi.y*sinGoc + viTriTuongDoi.x*cosGoc)/cachMu3;
         
         trungTamDoanChuVi += chieuRongDoanChuVi;
         chiSoDoanChuVi++;
      }
      
      // ---- hướng Z - điểm Gauss 1
      zTrenNamCham = phongToZ*kGAUSS_DIEM_1 + trungTamDoanZ;
      viTriTuongDoi.z = viTri->z - zTrenNamCham;
      // ---- tính quanh chu vi
      trungTamDoanChuVi = trungTamDoanChuViDau;
      chiSoDoanChuVi = 0;
      while( chiSoDoanChuVi < soDoanChuVi ) {
         // ==== 0
         double gocChuViNamCham = phongToChuVi*kGAUSS_DIEM_0 + trungTamDoanChuVi;
         double cosGoc = cos( gocChuViNamCham );
         double sinGoc = sin( gocChuViNamCham );
         double xTrenNamCham = banKinh*cosGoc;
         double yTrenNamCham = banKinh*sinGoc;
         viTriTuongDoi.x = viTri->x - xTrenNamCham;
         viTriTuongDoi.y = viTri->y - yTrenNamCham;
         
         // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
         double cachTuNamCham = sqrt( viTriTuongDoi.x*viTriTuongDoi.x +
                                     viTriTuongDoi.y*viTriTuongDoi.y +
                                     viTriTuongDoi.z*viTriTuongDoi.z );
         double cachMu3 = cachTuNamCham*cachTuNamCham*cachTuNamCham;
         // ---- góp phần vào từ trường
         tuTruong.x += maTranQuyenLuong[4]*viTriTuongDoi.z*cosGoc/cachMu3;
         tuTruong.y += maTranQuyenLuong[4]*viTriTuongDoi.z*sinGoc/cachMu3;
         tuTruong.z -= maTranQuyenLuong[4]*(viTriTuongDoi.y*sinGoc + viTriTuongDoi.x*cosGoc)/cachMu3;
         
         // ==== 1
         gocChuViNamCham = phongToChuVi*kGAUSS_DIEM_1 + trungTamDoanChuVi;
         cosGoc = cos( gocChuViNamCham );
         sinGoc = sin( gocChuViNamCham );
         xTrenNamCham = banKinh*cosGoc;
         yTrenNamCham = banKinh*sinGoc;
         viTriTuongDoi.x = viTri->x - xTrenNamCham;
         viTriTuongDoi.y = viTri->y - yTrenNamCham;
         
         // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
         cachTuNamCham = sqrt( viTriTuongDoi.x*viTriTuongDoi.x +
                              viTriTuongDoi.y*viTriTuongDoi.y +
                              viTriTuongDoi.z*viTriTuongDoi.z );
         cachMu3 = cachTuNamCham*cachTuNamCham*cachTuNamCham;
         // ---- góp phần vào từ trường
         tuTruong.x += maTranQuyenLuong[5]*viTriTuongDoi.z*cosGoc/cachMu3;
         tuTruong.y += maTranQuyenLuong[5]*viTriTuongDoi.z*sinGoc/cachMu3;
         tuTruong.z -= maTranQuyenLuong[5]*(viTriTuongDoi.y*sinGoc + viTriTuongDoi.x*cosGoc)/cachMu3;
         
         // ==== 2
         gocChuViNamCham = phongToChuVi*kGAUSS_DIEM_2 + trungTamDoanChuVi;
         cosGoc = cos( gocChuViNamCham );
         sinGoc = sin( gocChuViNamCham );
         xTrenNamCham = banKinh*cosGoc;
         yTrenNamCham = banKinh*sinGoc;
         viTriTuongDoi.x = viTri->x - xTrenNamCham;
         viTriTuongDoi.y = viTri->y - yTrenNamCham;
         
         // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
         cachTuNamCham = sqrt( viTriTuongDoi.x*viTriTuongDoi.x +
                              viTriTuongDoi.y*viTriTuongDoi.y +
                              viTriTuongDoi.z*viTriTuongDoi.z );
         cachMu3 = cachTuNamCham*cachTuNamCham*cachTuNamCham;
         // ---- góp phần vào từ trường
         tuTruong.x += maTranQuyenLuong[6]*viTriTuongDoi.z*cosGoc/cachMu3;
         tuTruong.y += maTranQuyenLuong[6]*viTriTuongDoi.z*sinGoc/cachMu3;
         tuTruong.z -= maTranQuyenLuong[6]*(viTriTuongDoi.y*sinGoc + viTriTuongDoi.x*cosGoc)/cachMu3;
         
         // ==== 3
         gocChuViNamCham = phongToChuVi*kGAUSS_DIEM_3 + trungTamDoanChuVi;
         cosGoc = cos( gocChuViNamCham );
         sinGoc = sin( gocChuViNamCham );
         xTrenNamCham = banKinh*cosGoc;
         yTrenNamCham = banKinh*sinGoc;
         viTriTuongDoi.x = viTri->x - xTrenNamCham;
         viTriTuongDoi.y = viTri->y - yTrenNamCham;
         
         // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
         cachTuNamCham = sqrt( viTriTuongDoi.x*viTriTuongDoi.x +
                              viTriTuongDoi.y*viTriTuongDoi.y +
                              viTriTuongDoi.z*viTriTuongDoi.z );
         cachMu3 = cachTuNamCham*cachTuNamCham*cachTuNamCham;
         // ---- góp phần vào từ trường
         tuTruong.x += maTranQuyenLuong[7]*viTriTuongDoi.z*cosGoc/cachMu3;
         tuTruong.y += maTranQuyenLuong[7]*viTriTuongDoi.z*sinGoc/cachMu3;
         tuTruong.z -= maTranQuyenLuong[7]*(viTriTuongDoi.y*sinGoc + viTriTuongDoi.x*cosGoc)/cachMu3;
         
         trungTamDoanChuVi += chieuRongDoanChuVi;
         chiSoDoanChuVi++;
      }
      
      // ---- phóng to cho điểm Gauss 2
      zTrenNamCham = phongToZ*kGAUSS_DIEM_2 + trungTamDoanZ;
      viTriTuongDoi.z = viTri->z - zTrenNamCham;
      // ---- tính quanh chu vi
      trungTamDoanChuVi = trungTamDoanChuViDau;
      chiSoDoanChuVi = 0;
      while( chiSoDoanChuVi < soDoanChuVi ) {
         // ==== 0
         double gocChuViNamCham = phongToChuVi*kGAUSS_DIEM_0 + trungTamDoanChuVi;
         double cosGoc = cos( gocChuViNamCham );
         double sinGoc = sin( gocChuViNamCham );
         double xTrenNamCham = banKinh*cosGoc;
         double yTrenNamCham = banKinh*sinGoc;
         viTriTuongDoi.x = viTri->x - xTrenNamCham;
         viTriTuongDoi.y = viTri->y - yTrenNamCham;
         
         // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
         double cachTuNamCham = sqrt( viTriTuongDoi.x*viTriTuongDoi.x +
                                     viTriTuongDoi.y*viTriTuongDoi.y +
                                     viTriTuongDoi.z*viTriTuongDoi.z );
         double cachMu3 = cachTuNamCham*cachTuNamCham*cachTuNamCham;
         // ---- góp phần vào từ trường
         tuTruong.x += maTranQuyenLuong[8]*viTriTuongDoi.z*cosGoc/cachMu3;
         tuTruong.y += maTranQuyenLuong[8]*viTriTuongDoi.z*sinGoc/cachMu3;
         tuTruong.z -= maTranQuyenLuong[8]*(viTriTuongDoi.y*sinGoc + viTriTuongDoi.x*cosGoc)/cachMu3;
         
         // ==== 1
         gocChuViNamCham = phongToChuVi*kGAUSS_DIEM_1 + trungTamDoanChuVi;
         cosGoc = cos( gocChuViNamCham );
         sinGoc = sin( gocChuViNamCham );
         xTrenNamCham = banKinh*cosGoc;
         yTrenNamCham = banKinh*sinGoc;
         viTriTuongDoi.x = viTri->x - xTrenNamCham;
         viTriTuongDoi.y = viTri->y - yTrenNamCham;
         
         // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
         cachTuNamCham = sqrt( viTriTuongDoi.x*viTriTuongDoi.x +
                              viTriTuongDoi.y*viTriTuongDoi.y +
                              viTriTuongDoi.z*viTriTuongDoi.z );
         cachMu3 = cachTuNamCham*cachTuNamCham*cachTuNamCham;
         // ---- góp phần vào từ trường
         tuTruong.x += maTranQuyenLuong[9]*viTriTuongDoi.z*cosGoc/cachMu3;
         tuTruong.y += maTranQuyenLuong[9]*viTriTuongDoi.z*sinGoc/cachMu3;
         tuTruong.z -= maTranQuyenLuong[9]*(viTriTuongDoi.y*sinGoc + viTriTuongDoi.x*cosGoc)/cachMu3;
         
         // ==== 2
         gocChuViNamCham = phongToChuVi*kGAUSS_DIEM_2 + trungTamDoanChuVi;
         cosGoc = cos( gocChuViNamCham );
         sinGoc = sin( gocChuViNamCham );
         xTrenNamCham = banKinh*cosGoc;
         yTrenNamCham = banKinh*sinGoc;
         viTriTuongDoi.x = viTri->x - xTrenNamCham;
         viTriTuongDoi.y = viTri->y - yTrenNamCham;
         
         // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
         cachTuNamCham = sqrt( viTriTuongDoi.x*viTriTuongDoi.x +
                              viTriTuongDoi.y*viTriTuongDoi.y +
                              viTriTuongDoi.z*viTriTuongDoi.z );
         cachMu3 = cachTuNamCham*cachTuNamCham*cachTuNamCham;
         // ---- góp phần vào từ trường
         tuTruong.x += maTranQuyenLuong[10]*viTriTuongDoi.z*cosGoc/cachMu3;
         tuTruong.y += maTranQuyenLuong[10]*viTriTuongDoi.z*sinGoc/cachMu3;
         tuTruong.z -= maTranQuyenLuong[10]*(viTriTuongDoi.y*sinGoc + viTriTuongDoi.x*cosGoc)/cachMu3;
         
         // ==== 3
         gocChuViNamCham = phongToChuVi*kGAUSS_DIEM_3 + trungTamDoanChuVi;
         cosGoc = cos( gocChuViNamCham );
         sinGoc = sin( gocChuViNamCham );
         xTrenNamCham = banKinh*cosGoc;
         yTrenNamCham = banKinh*sinGoc;
         viTriTuongDoi.x = viTri->x - xTrenNamCham;
         viTriTuongDoi.y = viTri->y - yTrenNamCham;
         
         // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
         cachTuNamCham = sqrt( viTriTuongDoi.x*viTriTuongDoi.x +
                              viTriTuongDoi.y*viTriTuongDoi.y +
                              viTriTuongDoi.z*viTriTuongDoi.z );
         cachMu3 = cachTuNamCham*cachTuNamCham*cachTuNamCham;
         // ---- góp phần vào từ trường
         tuTruong.x += maTranQuyenLuong[11]*viTriTuongDoi.z*cosGoc/cachMu3;
         tuTruong.y += maTranQuyenLuong[11]*viTriTuongDoi.z*sinGoc/cachMu3;
         tuTruong.z -= maTranQuyenLuong[11]*(viTriTuongDoi.y*sinGoc + viTriTuongDoi.x*cosGoc)/cachMu3;
         
         trungTamDoanChuVi += chieuRongDoanChuVi;
         chiSoDoanChuVi++;
      }
      
      // ---- phóng to cho điểm Gauss 3
      zTrenNamCham = phongToZ*kGAUSS_DIEM_3 + trungTamDoanZ;
      viTriTuongDoi.z = viTri->z - zTrenNamCham;
      // ---- tính quanh chu vi
      trungTamDoanChuVi = trungTamDoanChuViDau;
      chiSoDoanChuVi = 0;
      while( chiSoDoanChuVi < soDoanChuVi ) {
         // ==== 0
         double gocChuViNamCham = phongToChuVi*kGAUSS_DIEM_0 + trungTamDoanChuVi;
         double cosGoc = cos( gocChuViNamCham );
         double sinGoc = sin( gocChuViNamCham );
         double xTrenNamCham = banKinh*cosGoc;
         double yTrenNamCham = banKinh*sinGoc;
         viTriTuongDoi.x = viTri->x - xTrenNamCham;
         viTriTuongDoi.y = viTri->y - yTrenNamCham;
         
         // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
         double cachTuNamCham = sqrt( viTriTuongDoi.x*viTriTuongDoi.x +
                                     viTriTuongDoi.y*viTriTuongDoi.y +
                                     viTriTuongDoi.z*viTriTuongDoi.z );
         double cachMu3 = cachTuNamCham*cachTuNamCham*cachTuNamCham;
         // ---- góp phần vào từ trường
         tuTruong.x += maTranQuyenLuong[12]*viTriTuongDoi.z*cosGoc/cachMu3;
         tuTruong.y += maTranQuyenLuong[12]*viTriTuongDoi.z*sinGoc/cachMu3;
         tuTruong.z -= maTranQuyenLuong[12]*(viTriTuongDoi.y*sinGoc + viTriTuongDoi.x*cosGoc)/cachMu3;
         
         // ==== 1
         gocChuViNamCham = phongToChuVi*kGAUSS_DIEM_1 + trungTamDoanChuVi;
         cosGoc = cos( gocChuViNamCham );
         sinGoc = sin( gocChuViNamCham );
         xTrenNamCham = banKinh*cosGoc;
         yTrenNamCham = banKinh*sinGoc;
         viTriTuongDoi.x = viTri->x - xTrenNamCham;
         viTriTuongDoi.y = viTri->y - yTrenNamCham;
         
         // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
         cachTuNamCham = sqrt( viTriTuongDoi.x*viTriTuongDoi.x +
                              viTriTuongDoi.y*viTriTuongDoi.y +
                              viTriTuongDoi.z*viTriTuongDoi.z );
         cachMu3 = cachTuNamCham*cachTuNamCham*cachTuNamCham;
         // ---- góp phần vào từ trường
         tuTruong.x += maTranQuyenLuong[13]*viTriTuongDoi.z*cosGoc/cachMu3;
         tuTruong.y += maTranQuyenLuong[13]*viTriTuongDoi.z*sinGoc/cachMu3;
         tuTruong.z -= maTranQuyenLuong[13]*(viTriTuongDoi.y*sinGoc + viTriTuongDoi.x*cosGoc)/cachMu3;
         
         // ==== 2
         gocChuViNamCham = phongToChuVi*kGAUSS_DIEM_2 + trungTamDoanChuVi;
         cosGoc = cos( gocChuViNamCham );
         sinGoc = sin( gocChuViNamCham );
         xTrenNamCham = banKinh*cosGoc;
         yTrenNamCham = banKinh*sinGoc;
         viTriTuongDoi.x = viTri->x - xTrenNamCham;
         viTriTuongDoi.y = viTri->y - yTrenNamCham;
         
         // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
         cachTuNamCham = sqrt( viTriTuongDoi.x*viTriTuongDoi.x +
                              viTriTuongDoi.y*viTriTuongDoi.y +
                              viTriTuongDoi.z*viTriTuongDoi.z );
         cachMu3 = cachTuNamCham*cachTuNamCham*cachTuNamCham;
         // ---- góp phần vào từ trường
         tuTruong.x += maTranQuyenLuong[14]*viTriTuongDoi.z*cosGoc/cachMu3;
         tuTruong.y += maTranQuyenLuong[14]*viTriTuongDoi.z*sinGoc/cachMu3;
         tuTruong.z -= maTranQuyenLuong[14]*(viTriTuongDoi.y*sinGoc + viTriTuongDoi.x*cosGoc)/cachMu3;
         
         // ==== 3
         gocChuViNamCham = phongToChuVi*kGAUSS_DIEM_3 + trungTamDoanChuVi;
         cosGoc = cos( gocChuViNamCham );
         sinGoc = sin( gocChuViNamCham );
         xTrenNamCham = banKinh*cosGoc;
         yTrenNamCham = banKinh*sinGoc;
         viTriTuongDoi.x = viTri->x - xTrenNamCham;
         viTriTuongDoi.y = viTri->y - yTrenNamCham;
         
         // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
         cachTuNamCham = sqrt( viTriTuongDoi.x*viTriTuongDoi.x +
                              viTriTuongDoi.y*viTriTuongDoi.y +
                              viTriTuongDoi.z*viTriTuongDoi.z );
         cachMu3 = cachTuNamCham*cachTuNamCham*cachTuNamCham;
         // ---- góp phần vào từ trường
         tuTruong.x += maTranQuyenLuong[15]*viTriTuongDoi.z*cosGoc/cachMu3;
         tuTruong.y += maTranQuyenLuong[15]*viTriTuongDoi.z*sinGoc/cachMu3;
         tuTruong.z -= maTranQuyenLuong[15]*(viTriTuongDoi.y*sinGoc + viTriTuongDoi.x*cosGoc)/cachMu3;
         
         trungTamDoanChuVi += chieuRongDoanChuVi;
         chiSoDoanChuVi++;
      }
      
      // ---- tính cho đạn tiễp
      trungTamDoanZ += chieuCaoDoanZ;
      chiSoDoanZ++;
   }
   
   // ---- cuối cùnh nhân hằng số từ trường và tỉ sô phóng to, và bbán kính nam châm
   double cuongDo = namCham->cuongDo;
   tuTruong.x *= kHANG_SO_TU_TRUONG*cuongDo*phongToZ*phongToChuVi*banKinh;
   tuTruong.y *= kHANG_SO_TU_TRUONG*cuongDo*phongToZ*phongToChuVi*banKinh;
   tuTruong.z *= kHANG_SO_TU_TRUONG*cuongDo*phongToZ*phongToChuVi*banKinh;
   
   return tuTruong;
}
*/

Vecto tinhTuTruongNamTramHinhTruMoi( Vecto *viTri, NamChamHinhTru *namCham, unsigned short soDoanChuVi ) {
   
   // ==== chuẩn bị
   // ---- cỡ thước
   double chieuCao = namCham->chieuCao;
   double banKinh = namCham->banKinh;
   
   // ---- cho đoạn chu vi
   double phongToChuVi = kPI/soDoanChuVi;
   double chieuRongDoanChuVi = k2_PI/soDoanChuVi;
   
   double zTren = viTri->z - 0.5*chieuCao;
   double zDuoi = viTri->z + 0.5*chieuCao;
   
   // ---- xóa từ trường
   Vecto tuTruong;
   tuTruong.x = 0.0;
   tuTruong.y = 0.0;
   tuTruong.z = 0.0;
   
   // ==== bắt đầu tính
   double trungTamDoanChuViDau = chieuRongDoanChuVi*0.5;
   
   // ---- vị trí tương đối nam châm
   Vecto viTriTuongDoi;
   
   // ---- tính quanh chu vi
   double trungTamDoanChuVi = trungTamDoanChuViDau;
   unsigned short chiSoDoanChuVi = 0;
   while( chiSoDoanChuVi < soDoanChuVi ) {
      // ==== 0
      double gocChuViNamCham = phongToChuVi*kGAUSS_DIEM_0 + trungTamDoanChuVi;
      double cosGoc = cos( gocChuViNamCham );
      double sinGoc = sin( gocChuViNamCham );
      double xTrenNamCham = banKinh*cosGoc;
      double yTrenNamCham = banKinh*sinGoc;
      viTriTuongDoi.x = viTri->x - xTrenNamCham;
      viTriTuongDoi.y = viTri->y - yTrenNamCham;
      
      // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
      double cachXYBinh = viTriTuongDoi.x*viTriTuongDoi.x + viTriTuongDoi.y*viTriTuongDoi.y;
      double cachTren = sqrt( cachXYBinh + zTren*zTren );
      double cachDuoi = sqrt( cachXYBinh + zDuoi*zDuoi );
      
      double daoNghichTren = 1.0/cachTren;
      double daoNghichDuoi = 1.0/cachDuoi;

      // ---- góp phần vào từ trường
      tuTruong.x += kGAUSS_QUYEN_LUONG_0*cosGoc*(daoNghichDuoi - daoNghichTren);
      tuTruong.y += kGAUSS_QUYEN_LUONG_0*sinGoc*(daoNghichDuoi - daoNghichTren);
      tuTruong.z -= kGAUSS_QUYEN_LUONG_0*(viTriTuongDoi.y*sinGoc + viTriTuongDoi.x*cosGoc)/cachXYBinh
                      *(zTren*daoNghichTren - zDuoi*daoNghichDuoi);
      
      // ==== 1
      gocChuViNamCham = phongToChuVi*kGAUSS_DIEM_1 + trungTamDoanChuVi;
      cosGoc = cos( gocChuViNamCham );
      sinGoc = sin( gocChuViNamCham );
      xTrenNamCham = banKinh*cosGoc;
      yTrenNamCham = banKinh*sinGoc;
      viTriTuongDoi.x = viTri->x - xTrenNamCham;
      viTriTuongDoi.y = viTri->y - yTrenNamCham;
      
      // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
      cachXYBinh = viTriTuongDoi.x*viTriTuongDoi.x + viTriTuongDoi.y*viTriTuongDoi.y;
      cachTren = sqrt( cachXYBinh + zTren*zTren );
      cachDuoi = sqrt( cachXYBinh + zDuoi*zDuoi );
      
      daoNghichTren = 1.0/cachTren;
      daoNghichDuoi = 1.0/cachDuoi;
      
      // ---- góp phần vào từ trường
      tuTruong.x += kGAUSS_QUYEN_LUONG_1*cosGoc*(daoNghichDuoi - daoNghichTren);
      tuTruong.y += kGAUSS_QUYEN_LUONG_1*sinGoc*(daoNghichDuoi - daoNghichTren);
      tuTruong.z -= kGAUSS_QUYEN_LUONG_1*(viTriTuongDoi.y*sinGoc + viTriTuongDoi.x*cosGoc)/cachXYBinh
      *(zTren*daoNghichTren - zDuoi*daoNghichDuoi);
      
      // ==== 2
      gocChuViNamCham = phongToChuVi*kGAUSS_DIEM_2 + trungTamDoanChuVi;
      cosGoc = cos( gocChuViNamCham );
      sinGoc = sin( gocChuViNamCham );
      xTrenNamCham = banKinh*cosGoc;
      yTrenNamCham = banKinh*sinGoc;
      viTriTuongDoi.x = viTri->x - xTrenNamCham;
      viTriTuongDoi.y = viTri->y - yTrenNamCham;
      
      // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
      cachXYBinh = viTriTuongDoi.x*viTriTuongDoi.x + viTriTuongDoi.y*viTriTuongDoi.y;
      cachTren = sqrt( cachXYBinh + zTren*zTren );
      cachDuoi = sqrt( cachXYBinh + zDuoi*zDuoi );
      
      daoNghichTren = 1.0/cachTren;
      daoNghichDuoi = 1.0/cachDuoi;
      
      // ---- góp phần vào từ trường
      tuTruong.x += kGAUSS_QUYEN_LUONG_2*cosGoc*(daoNghichDuoi - daoNghichTren);
      tuTruong.y += kGAUSS_QUYEN_LUONG_2*sinGoc*(daoNghichDuoi - daoNghichTren);
      tuTruong.z -= kGAUSS_QUYEN_LUONG_2*(viTriTuongDoi.y*sinGoc + viTriTuongDoi.x*cosGoc)/cachXYBinh
      *(zTren*daoNghichTren - zDuoi*daoNghichDuoi);
      
      // ==== 3
      gocChuViNamCham = phongToChuVi*kGAUSS_DIEM_3 + trungTamDoanChuVi;
      cosGoc = cos( gocChuViNamCham );
      sinGoc = sin( gocChuViNamCham );
      xTrenNamCham = banKinh*cosGoc;
      yTrenNamCham = banKinh*sinGoc;
      viTriTuongDoi.x = viTri->x - xTrenNamCham;
      viTriTuongDoi.y = viTri->y - yTrenNamCham;
      
      // ---- tính cách từ điểm trên nam châm đến điểm trong không gian
      cachXYBinh = viTriTuongDoi.x*viTriTuongDoi.x + viTriTuongDoi.y*viTriTuongDoi.y;
      cachTren = sqrt( cachXYBinh + zTren*zTren );
      cachDuoi = sqrt( cachXYBinh + zDuoi*zDuoi );
      
      daoNghichTren = 1.0/cachTren;
      daoNghichDuoi = 1.0/cachDuoi;
      
      // ---- góp phần vào từ trường
      tuTruong.x += kGAUSS_QUYEN_LUONG_3*cosGoc*(daoNghichDuoi - daoNghichTren);
      tuTruong.y += kGAUSS_QUYEN_LUONG_3*sinGoc*(daoNghichDuoi - daoNghichTren);
      tuTruong.z -= kGAUSS_QUYEN_LUONG_3*(viTriTuongDoi.y*sinGoc + viTriTuongDoi.x*cosGoc)/cachXYBinh
      *(zTren*daoNghichTren - zDuoi*daoNghichDuoi);
      
      trungTamDoanChuVi += chieuRongDoanChuVi;
      chiSoDoanChuVi++;
   }
   
   // ---- cuối cùnh nhân hằng số từ trường và tỉ sô phóng to, và bbán kính nam châm
   double cuongDo = namCham->cuongDo;
   tuTruong.x *= -kHANG_SO_TU_TRUONG*cuongDo*phongToChuVi*banKinh;
   tuTruong.y *= -kHANG_SO_TU_TRUONG*cuongDo*phongToChuVi*banKinh;
   tuTruong.z *= -kHANG_SO_TU_TRUONG*cuongDo*phongToChuVi*banKinh;
   
   return tuTruong;
}

