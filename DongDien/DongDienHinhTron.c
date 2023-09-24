// 2023.09.07

#include <math.h>
#include "DongDienHinhTron.h"
#include "../HangSo.h"


DongDienHinhTron datDongDienHinhTron( double banKinh, double cachTuTrungTam, unsigned char soDongDien ) {
   
   DongDienHinhTron dongDien;

   dongDien.banKinh = banKinh;
   dongDien.cachTuTrungTam = cachTuTrungTam;
   dongDien.soDongDien = soDongDien;

   return dongDien;
}


/*
 • trung tâm xoay tại (0; 0; 0)
 • xoay quanh trục z
 */

//  ∂/∂t ∫∫ B•dS = ∫B•v•∆l = ∫B • (ω × r) • n • dl

// • gócXoay là góchiện tại
// • mặt phẳng của vòng điện z = 0
// • trung tâm cấu trúc vòng điện tạo 0; 0; 0
// • đơn vị góc là radian


double tinhDienTheChoDongHinhTron_namChamHinhTru( DongDienHinhTron *dongDien, unsigned char soDoanCong, double gocXoay, NamChamHinhTru *namCham ) {
   
   double banKinh = dongDien->banKinh;
   double cachTuTrungTam = dongDien->cachTuTrungTam;  // cách từ trung tâm xoay
//   unsigned soDongDien = dongDien->soDongDien;

   // ---- vị trí trên vòng điện đang tính
   Vecto viTri;
   viTri.z = 0.0;
   
   double viTriNamChamX = namCham->viTri.x;
   double viTriNamChamY = namCham->viTri.y;
   
   // ---- vị trí dòng diện hình tròn
   double cachTuTrungTamX = cachTuTrungTam*cos(gocXoay);
   double cachTuTrungTamY = cachTuTrungTam*sin(gocXoay);
   
   // ---- cho đoạn vòng điện hướng chu vi hình tròn
   double chieuDaiDoanChuVi = k2_PI/soDoanCong;
   double phongToDoanChuVi = chieuDaiDoanChuVi*0.5;
   
   //      vị trí mặt phẳng dây điện - vị trí nam châm
   Vecto viTriTuongDoiNamCham;
   viTriTuongDoiNamCham.z = 0.0 - namCham->viTri.z;   // mặt phẳng vòng điện tại z = 0
   
   // ==== bắt đầu tính
   // ---- số đoạn nam châm
   unsigned char soDoanChuViNamCham = 4;
   double dienThe = 0.0;
   
   // ==============================
   // ---- quét vòng
   double gocDau = 0.0;   // radian
   double trungTamDoanChuViDau = chieuDaiDoanChuVi*0.5;  // radian
   
   unsigned char chiSoDoanCong = 0;
   while( chiSoDoanCong < soDoanCong ) {
      // ==== 0
      double gocChuViNamCham = phongToDoanChuVi*kGAUSS_DIEM_0 + trungTamDoanChuViDau;
      double cosGoc = cos( gocChuViNamCham );
      double sinGoc = sin( gocChuViNamCham );
      viTri.x = banKinh*cosGoc + cachTuTrungTamX;
      viTri.y = banKinh*sinGoc + cachTuTrungTamY;

      // ---- tính vị trí tương đối nam châm
      viTriTuongDoiNamCham.x = viTri.x - viTriNamChamX;
      viTriTuongDoiNamCham.y = viTri.y - viTriNamChamY;
      
      // ---- tính từ trường tại vị trí này
      Vecto tuTruong = tinhTuTruongNamTramHinhTruMoi( &viTriTuongDoiNamCham, namCham, soDoanChuViNamCham );
      double tuTruongZ = tuTruong.z;
      
      // ---- tính cách trong mặt phẳng
      double cach = sqrt( viTri.x*viTri.x + viTri.y*viTri.y );
      double gocDenDiem = atan( viTri.y/viTri.x );
      if( viTri.x < 0.0 )
         gocDenDiem = kPI + gocDenDiem;

      // ---- tính hương xoay
      double huongXoayX = -sin( gocDenDiem );
      double huongXoayY = cos( gocDenDiem );

      // ---- góp phần điện thế
      dienThe += tuTruongZ*kGAUSS_QUYEN_LUONG_0*cach*(cosGoc*huongXoayX + sinGoc*huongXoayY );
      
      // ==== 1
      gocChuViNamCham = phongToDoanChuVi*kGAUSS_DIEM_1 + trungTamDoanChuViDau;
      cosGoc = cos( gocChuViNamCham );
      sinGoc = sin( gocChuViNamCham );
      viTri.x = banKinh*cosGoc + cachTuTrungTamX;
      viTri.y = banKinh*sinGoc + cachTuTrungTamY;

      // ---- tính vị trí tương đối nam châm
      viTriTuongDoiNamCham.x = viTri.x - viTriNamChamX;
      viTriTuongDoiNamCham.y = viTri.y - viTriNamChamY;
      
      // ---- tính từ trường tại vị trí này
      tuTruong = tinhTuTruongNamTramHinhTruMoi( &viTriTuongDoiNamCham, namCham, soDoanChuViNamCham );
      tuTruongZ = tuTruong.z;
      
      // ---- tính cách trong mặt phẳng
      cach = sqrt( viTri.x*viTri.x + viTri.y*viTri.y );
      gocDenDiem = atan( viTri.y/viTri.x );
      if( viTri.x < 0.0 )
         gocDenDiem = kPI + gocDenDiem;
      
      // ---- tính hương xoay
      huongXoayX = -sin( gocDenDiem );
      huongXoayY = cos( gocDenDiem );

      // ---- góp phần điện thế
      dienThe += tuTruongZ*kGAUSS_QUYEN_LUONG_1*cach*(cosGoc*huongXoayX + sinGoc*huongXoayY );
      
      // ==== 2
      gocChuViNamCham = phongToDoanChuVi*kGAUSS_DIEM_2 + trungTamDoanChuViDau;
      cosGoc = cos( gocChuViNamCham );
      sinGoc = sin( gocChuViNamCham );
      viTri.x = banKinh*cosGoc + cachTuTrungTamX;
      viTri.y = banKinh*sinGoc + cachTuTrungTamY;

      // ---- tính vị trí tương đối nam châm
      viTriTuongDoiNamCham.x = viTri.x - viTriNamChamX;
      viTriTuongDoiNamCham.y = viTri.y - viTriNamChamY;
      
      // ---- tính từ trường tại vị trí này
      tuTruong = tinhTuTruongNamTramHinhTruMoi( &viTriTuongDoiNamCham, namCham, soDoanChuViNamCham );
      tuTruongZ = tuTruong.z;
      
      // ---- tính cách trong mặt phẳng
      cach = sqrt( viTri.x*viTri.x + viTri.y*viTri.y );
      gocDenDiem = atan( viTri.y/viTri.x );
      if( viTri.x < 0.0 )
         gocDenDiem = kPI + gocDenDiem;
      
      // ---- tính hương xoay
      huongXoayX = -sin( gocDenDiem );
      huongXoayY = cos( gocDenDiem );

      // ---- góp phần điện thế
      dienThe += tuTruongZ*kGAUSS_QUYEN_LUONG_2*cach*(cosGoc*huongXoayX + sinGoc*huongXoayY );
      
      // ==== 3
      gocChuViNamCham = phongToDoanChuVi*kGAUSS_DIEM_3 + trungTamDoanChuViDau;
      cosGoc = cos( gocChuViNamCham );
      sinGoc = sin( gocChuViNamCham );
      viTri.x = banKinh*cosGoc + cachTuTrungTamX;
      viTri.y = banKinh*sinGoc + cachTuTrungTamY;

      // ---- tính vị trí tương đối nam châm
      viTriTuongDoiNamCham.x = viTri.x - viTriNamChamX;
      viTriTuongDoiNamCham.y = viTri.y - viTriNamChamY;
      
      // ---- tính từ trường tại vị trí này
      tuTruong = tinhTuTruongNamTramHinhTruMoi( &viTriTuongDoiNamCham, namCham, soDoanChuViNamCham );
      tuTruongZ = tuTruong.z;
      
      // ---- tính cách trong mặt phẳng
      cach = sqrt( viTri.x*viTri.x + viTri.y*viTri.y );
      gocDenDiem = atan( viTri.y/viTri.x );
      if( viTri.x < 0.0 )
         gocDenDiem = kPI + gocDenDiem;
      
      // ---- tính hương xoay
      huongXoayX = -sin( gocDenDiem );
      huongXoayY = cos( gocDenDiem );

      // ---- góp phần điện thế
      dienThe += tuTruongZ*kGAUSS_QUYEN_LUONG_3*cach*(cosGoc*huongXoayX + sinGoc*huongXoayY );
      
      // ---- đoạn tiếp
      trungTamDoanChuViDau += chieuDaiDoanChuVi;
      chiSoDoanCong++;
   }

   // ---- cuối cùnh nhân hphóng to đoạn
   dienThe *= -phongToDoanChuVi;
   
   return dienThe;
}


double tinhDienTheChoDongHinhTron_namChamHinhHop( DongDienHinhTron *dongDien, unsigned char soDoanCong, double gocXoay, NamChamHinhHop *namCham ) {
   
   double banKinh = dongDien->banKinh;
   double cachTuTrungTam = dongDien->cachTuTrungTam;  // cách từ trung tâm xoay
   //   unsigned soDongDien = dongDien->soDongDien;
   
   // ---- vị trí trên vòng điện đang tính
   Vecto viTri;
   viTri.z = 0.0;
   
   double viTriNamChamX = namCham->viTri.x;
   double viTriNamChamY = namCham->viTri.y;
   
   // ---- vị trí dòng diện hình tròn
   double cachTuTrungTamX = cachTuTrungTam*cos(gocXoay);
   double cachTuTrungTamY = cachTuTrungTam*sin(gocXoay);
   
   // ---- cho đoạn vòng điện hướng chu vi hình tròn
   double chieuDaiDoanChuVi = k2_PI/soDoanCong;
   double phongToDoanChuVi = chieuDaiDoanChuVi*0.5;
   
   //      vị trí mặt phẳng dây điện - vị trí nam châm
   Vecto viTriTuongDoiNamCham;
   viTriTuongDoiNamCham.z = 0.0 - namCham->viTri.z;   // mặt phẳng vòng điện tại z = 0
   
   // ==== bắt đầu tính
   double dienThe = 0.0;
   
   // ==============================
   // ---- quét vòng
   double gocDau = 0.0;   // radian
   double trungTamDoanChuViDau = chieuDaiDoanChuVi*0.5;  // radian
   
   unsigned char chiSoDoanCong = 0;
   while( chiSoDoanCong < soDoanCong ) {
      // ==== 0
      double gocChuViNamCham = phongToDoanChuVi*kGAUSS_DIEM_0 + trungTamDoanChuViDau;
      double cosGoc = cos( gocChuViNamCham );
      double sinGoc = sin( gocChuViNamCham );
      viTri.x = banKinh*cosGoc + cachTuTrungTamX;
      viTri.y = banKinh*sinGoc + cachTuTrungTamY;
      
      // ---- tính vị trí tương đối nam châm
      viTriTuongDoiNamCham.x = viTri.x - viTriNamChamX;
      viTriTuongDoiNamCham.y = viTri.y - viTriNamChamY;
      
      // ---- tính từ trường tại vị trí này
      Vecto tuTruong = tinhTuTruongNamTramHinhHopMoi2( &viTriTuongDoiNamCham, namCham );
      double tuTruongZ = tuTruong.z;
      
      // ---- tính cách trong mặt phẳng
      double cach = sqrt( viTri.x*viTri.x + viTri.y*viTri.y );
      double gocDenDiem = atan( viTri.y/viTri.x );
      if( viTri.x < 0.0 )
         gocDenDiem = kPI + gocDenDiem;
      
      // ---- tính hương xoay
      double huongXoayX = -sin( gocDenDiem );
      double huongXoayY = cos( gocDenDiem );
      
      // ---- góp phần điện thế
      dienThe += tuTruongZ*kGAUSS_QUYEN_LUONG_0*cach*(cosGoc*huongXoayX + sinGoc*huongXoayY );
      
      // ==== 1
      gocChuViNamCham = phongToDoanChuVi*kGAUSS_DIEM_1 + trungTamDoanChuViDau;
      cosGoc = cos( gocChuViNamCham );
      sinGoc = sin( gocChuViNamCham );
      viTri.x = banKinh*cosGoc + cachTuTrungTamX;
      viTri.y = banKinh*sinGoc + cachTuTrungTamY;
      
      // ---- tính vị trí tương đối nam châm
      viTriTuongDoiNamCham.x = viTri.x - viTriNamChamX;
      viTriTuongDoiNamCham.y = viTri.y - viTriNamChamY;
      
      // ---- tính từ trường tại vị trí này
      tuTruong = tinhTuTruongNamTramHinhHopMoi2( &viTriTuongDoiNamCham, namCham );
      tuTruongZ = tuTruong.z;
      
      // ---- tính cách trong mặt phẳng
      cach = sqrt( viTri.x*viTri.x + viTri.y*viTri.y );
      gocDenDiem = atan( viTri.y/viTri.x );
      if( viTri.x < 0.0 )
         gocDenDiem = kPI + gocDenDiem;
      
      // ---- tính hương xoay
      huongXoayX = -sin( gocDenDiem );
      huongXoayY = cos( gocDenDiem );
      
      // ---- góp phần điện thế
      dienThe += tuTruongZ*kGAUSS_QUYEN_LUONG_1*cach*(cosGoc*huongXoayX + sinGoc*huongXoayY );
      
      // ==== 2
      gocChuViNamCham = phongToDoanChuVi*kGAUSS_DIEM_2 + trungTamDoanChuViDau;
      cosGoc = cos( gocChuViNamCham );
      sinGoc = sin( gocChuViNamCham );
      viTri.x = banKinh*cosGoc + cachTuTrungTamX;
      viTri.y = banKinh*sinGoc + cachTuTrungTamY;
      
      // ---- tính vị trí tương đối nam châm
      viTriTuongDoiNamCham.x = viTri.x - viTriNamChamX;
      viTriTuongDoiNamCham.y = viTri.y - viTriNamChamY;
      
      // ---- tính từ trường tại vị trí này
      tuTruong = tinhTuTruongNamTramHinhHopMoi2( &viTriTuongDoiNamCham, namCham );
      tuTruongZ = tuTruong.z;
      
      // ---- tính cách trong mặt phẳng
      cach = sqrt( viTri.x*viTri.x + viTri.y*viTri.y );
      gocDenDiem = atan( viTri.y/viTri.x );
      if( viTri.x < 0.0 )
         gocDenDiem = kPI + gocDenDiem;
      
      // ---- tính hương xoay
      huongXoayX = -sin( gocDenDiem );
      huongXoayY = cos( gocDenDiem );
      
      // ---- góp phần điện thế
      dienThe += tuTruongZ*kGAUSS_QUYEN_LUONG_2*cach*(cosGoc*huongXoayX + sinGoc*huongXoayY );
      
      // ==== 3
      gocChuViNamCham = phongToDoanChuVi*kGAUSS_DIEM_3 + trungTamDoanChuViDau;
      cosGoc = cos( gocChuViNamCham );
      sinGoc = sin( gocChuViNamCham );
      viTri.x = banKinh*cosGoc + cachTuTrungTamX;
      viTri.y = banKinh*sinGoc + cachTuTrungTamY;
      
      // ---- tính vị trí tương đối nam châm
      viTriTuongDoiNamCham.x = viTri.x - viTriNamChamX;
      viTriTuongDoiNamCham.y = viTri.y - viTriNamChamY;
      
      // ---- tính từ trường tại vị trí này
      tuTruong = tinhTuTruongNamTramHinhHopMoi2( &viTriTuongDoiNamCham, namCham );
      tuTruongZ = tuTruong.z;
      
      // ---- tính cách trong mặt phẳng
      cach = sqrt( viTri.x*viTri.x + viTri.y*viTri.y );
      gocDenDiem = atan( viTri.y/viTri.x );
      if( viTri.x < 0.0 )
         gocDenDiem = kPI + gocDenDiem;
      
      // ---- tính hương xoay
      huongXoayX = -sin( gocDenDiem );
      huongXoayY = cos( gocDenDiem );
      
      // ---- góp phần điện thế
      dienThe += tuTruongZ*kGAUSS_QUYEN_LUONG_3*cach*(cosGoc*huongXoayX + sinGoc*huongXoayY );
      
      // ---- đoạn tiếp
      trungTamDoanChuViDau += chieuDaiDoanChuVi;
      chiSoDoanCong++;
   }
   
   // ---- cuối cùnh nhân hphóng to đoạn
   dienThe *= -phongToDoanChuVi;
   
   return dienThe;
}
