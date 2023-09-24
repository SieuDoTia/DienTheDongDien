// 2023.09.07

#include <math.h>
#include "DongDienPhanHinhTron.h"
#include "../HangSo.h"
#include <stdio.h> // <--- bỏ sau

DongDienPhanHinhTron datDongDienPhanHinhTron( double banKinhNoi, double banKinhNgoai, double chieuRongGoc, unsigned char soDongDien ) {
   
   DongDienPhanHinhTron dongDien;
   
   dongDien.banKinhNoi = banKinhNoi;
   dongDien.banKinhNgoai = banKinhNgoai;
   dongDien.chieuRongGoc = chieuRongGoc;
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
double tinhDienTheChoDongPhanHinhTron_namChamHinhTru( DongDienPhanHinhTron *dongDien, unsigned char soDoanCong, double gocXoay, NamChamHinhTru *namCham ) {
   
   double chieuRongGoc = dongDien->chieuRongGoc;
   double banKinhNoi = dongDien->banKinhNoi;
   double banKinhNgoai = dongDien->banKinhNgoai;
//   unsigned soDongDien = dongDien->soDongDien;

   // ---- vị trí trên vòng điện đang tính
   Vecto viTri;
   viTri.z = 0.0;
   
   double viTriNamChamX = namCham->viTri.x;
   double viTriNamChamY = namCham->viTri.y;
   
   // ---- cho đoạn vòng điện hướng bán kính
   double chieuDaiDoan = (banKinhNgoai - banKinhNoi)/soDoanCong;
   double phongToDoan = chieuDaiDoan*0.5;

   //      vị trí mặt phẳng dây điện - vị trí nam châm
   Vecto viTriTuongDoiNamCham;
   viTriTuongDoiNamCham.z = 0.0 - namCham->viTri.z;   // mặt phẳng vòng điện tại z = 0

   // ==== bắt đầu tính
   // ---- số đoạn
   unsigned char soDoanChuVi = 4;
   double dienThe = 0.0;

   // ==============================
   // +    |------->|
   double gocDau = gocXoay;
   double cosGoc = cos( gocDau );
   double sinGoc = sin( gocDau );
   double trungTamDoan = banKinhNoi + chieuDaiDoan*0.5;
   
   unsigned char chiSoDoanCong = 0;
   while( chiSoDoanCong < soDoanCong ) {
      // ==== 0
      // ----- tính điểm trên đường cong
      double cach = phongToDoan*kGAUSS_DIEM_0 + trungTamDoan;
      viTri.x = cach*cosGoc;
      viTri.y = cach*sinGoc;

      // ---- tính vị trí tương đối nam châm
      viTriTuongDoiNamCham.x = viTri.x - viTriNamChamX;
      viTriTuongDoiNamCham.y = viTri.y - viTriNamChamY;

      // ---- tính từ trường tại vị trí này
      Vecto tuTruong = tinhTuTruongNamTramHinhTruMoi( &viTriTuongDoiNamCham, namCham, soDoanChuVi );
      double tuTruongZ = tuTruong.z;

      // ---- góp phần điện thế
      dienThe += tuTruongZ*kGAUSS_QUYEN_LUONG_0*cach;
   
      // ==== 1
      cach = phongToDoan*kGAUSS_DIEM_1 + trungTamDoan;
      viTri.x = cach*cosGoc;
      viTri.y = cach*sinGoc;

      // ---- tính vị trí tương đối nam châm
      viTriTuongDoiNamCham.x = viTri.x - viTriNamChamX;
      viTriTuongDoiNamCham.y = viTri.y - viTriNamChamY;

      // ---- tính từ trường tại vị trí này
      tuTruong = tinhTuTruongNamTramHinhTruMoi( &viTriTuongDoiNamCham, namCham, soDoanChuVi );
      tuTruongZ = tuTruong.z;
      
      // ---- góp phần điện thế
      dienThe += tuTruongZ*kGAUSS_QUYEN_LUONG_1*cach;

      // ==== 2
      cach = phongToDoan*kGAUSS_DIEM_2 + trungTamDoan;
      viTri.x = cach*cosGoc;
      viTri.y = cach*sinGoc;

      // ---- tính vị trí tương đối nam châm
      viTriTuongDoiNamCham.x = viTri.x - viTriNamChamX;
      viTriTuongDoiNamCham.y = viTri.y - viTriNamChamY;

      // ---- tính từ trường tại vị trí này
      tuTruong = tinhTuTruongNamTramHinhTruMoi( &viTriTuongDoiNamCham, namCham, soDoanChuVi );
      tuTruongZ = tuTruong.z;
      
      // ---- góp phần điện thế
      dienThe += tuTruongZ*kGAUSS_QUYEN_LUONG_2*cach;

      // ==== 3
      cach = phongToDoan*kGAUSS_DIEM_3 + trungTamDoan;
      viTri.x = cach*cosGoc;
      viTri.y = cach*sinGoc;

      // ---- tính vị trí tương đối nam châm
      viTriTuongDoiNamCham.x = viTri.x - viTriNamChamX;
      viTriTuongDoiNamCham.y = viTri.y - viTriNamChamY;

      // ---- tính từ trường tại vị trí này
      tuTruong = tinhTuTruongNamTramHinhTruMoi( &viTriTuongDoiNamCham, namCham, soDoanChuVi );
      tuTruongZ = tuTruong.z;
      
      // ---- góp phần điện thế
      dienThe += tuTruongZ*kGAUSS_QUYEN_LUONG_3*cach;

      // ---- đoạn tiếp
      trungTamDoan += chieuDaiDoan;
      chiSoDoanCong++;
   }
   
   // ==============================
   // +    |<-------|
   double gocCuoi = gocXoay + chieuRongGoc;
   cosGoc = cos( gocCuoi );
   sinGoc = sin( gocCuoi );
   trungTamDoan = banKinhNoi + chieuDaiDoan*0.5;
   
   chiSoDoanCong = 0;
   while( chiSoDoanCong < soDoanCong ) {
      // ==== 0
      // ----- tính điểm trên đường cong
      double cach = phongToDoan*kGAUSS_DIEM_0 + trungTamDoan;
      viTri.x = cach*cosGoc;
      viTri.y = cach*sinGoc;

      // ---- tính vị trí tương đối nam châm
      viTriTuongDoiNamCham.x = viTri.x - viTriNamChamX;
      viTriTuongDoiNamCham.y = viTri.y - viTriNamChamY;
      
      // ---- tính từ trường tại vị trí này
      Vecto tuTruong = tinhTuTruongNamTramHinhTruMoi( &viTriTuongDoiNamCham, namCham, soDoanChuVi );
      double tuTruongZ = tuTruong.z;
      
      // ---- góp phần điện thế
      dienThe -= tuTruongZ*kGAUSS_QUYEN_LUONG_0*cach;

      // ==== 1
      cach = phongToDoan*kGAUSS_DIEM_1 + trungTamDoan;
      viTri.x = cach*cosGoc;
      viTri.y = cach*sinGoc;

      // ---- tính vị trí tương đối nam châm
      viTriTuongDoiNamCham.x = viTri.x - viTriNamChamX;
      viTriTuongDoiNamCham.y = viTri.y - viTriNamChamY;

      // ---- tính từ trường tại vị trí này
      tuTruong = tinhTuTruongNamTramHinhTruMoi( &viTriTuongDoiNamCham, namCham, soDoanChuVi );
      tuTruongZ = tuTruong.z;
      
      // ---- góp phần điện thế
      dienThe -= tuTruongZ*kGAUSS_QUYEN_LUONG_1*cach;

      // ==== 2
      cach = phongToDoan*kGAUSS_DIEM_2 + trungTamDoan;
      viTri.x = cach*cosGoc;
      viTri.y = cach*sinGoc;

      // ---- tính vị trí tương đối nam châm
      viTriTuongDoiNamCham.x = viTri.x - viTriNamChamX;
      viTriTuongDoiNamCham.y = viTri.y - viTriNamChamY;

      // ---- tính từ trường tại vị trí này
      tuTruong = tinhTuTruongNamTramHinhTruMoi( &viTriTuongDoiNamCham, namCham, soDoanChuVi );
      tuTruongZ = tuTruong.z;
      
      // ---- góp phần điện thế
      dienThe -= tuTruongZ*kGAUSS_QUYEN_LUONG_2*cach;

      // ==== 3
      cach = phongToDoan*kGAUSS_DIEM_3 + trungTamDoan;
      viTri.x = cach*cosGoc;
      viTri.y = cach*sinGoc;

      // ---- tính vị trí tương đối nam châm
      viTriTuongDoiNamCham.x = viTri.x - viTriNamChamX;
      viTriTuongDoiNamCham.y = viTri.y - viTriNamChamY;

      // ---- tính từ trường tại vị trí này
      tuTruong = tinhTuTruongNamTramHinhTruMoi( &viTriTuongDoiNamCham, namCham, soDoanChuVi );
      tuTruongZ = tuTruong.z;
      
      // ---- góp phần điện thế
      dienThe -= tuTruongZ*kGAUSS_QUYEN_LUONG_3*cach;

      // ---- đoạn tiếp
      trungTamDoan += chieuDaiDoan;
      chiSoDoanCong++;
   }
   
   // ---- cuối cùnh nhân hphóng to đoạn
   dienThe *= phongToDoan;
   
   return dienThe;
}


double tinhDienTheChoDongPhanHinhTron_namChamHinhHop( DongDienPhanHinhTron *dongDien, unsigned char soDoanCong, double gocXoay, NamChamHinhHop *namCham ) {
   
   double chieuRongGoc = dongDien->chieuRongGoc;
   double banKinhNoi = dongDien->banKinhNoi;
   double banKinhNgoai = dongDien->banKinhNgoai;
   //   unsigned soDongDien = dongDien->soDongDien;
   
   // ---- vị trí trên vòng điện đang tính
   Vecto viTri;
   viTri.z = 0.0;
   
   double viTriNamChamX = namCham->viTri.x;
   double viTriNamChamY = namCham->viTri.y;
   
   // ---- cho đoạn vòng điện hướng bán kính
   double chieuDaiDoan = (banKinhNgoai - banKinhNoi)/soDoanCong;
   double phongToDoan = chieuDaiDoan*0.5;
   
   //      vị trí mặt phẳng dây điện - vị trí nam châm
   Vecto viTriTuongDoiNamCham;
   viTriTuongDoiNamCham.z = 0.0 - namCham->viTri.z;   // mặt phẳng vòng điện tại z = 0
   
   // ==== bắt đầu tính
   // ---- số đoạn
   double dienThe = 0.0;
   
   // ==============================
   // +    |------->|
   double gocDau = gocXoay;
   double cosGoc = cos( gocDau );
   double sinGoc = sin( gocDau );
   double trungTamDoan = banKinhNoi + chieuDaiDoan*0.5;
   
   unsigned char chiSoDoanCong = 0;
   while( chiSoDoanCong < soDoanCong ) {
      // ==== 0
      // ----- tính điểm trên đường cong
      double cach = phongToDoan*kGAUSS_DIEM_0 + trungTamDoan;
      viTri.x = cach*cosGoc;
      viTri.y = cach*sinGoc;
      
      // ---- tính vị trí tương đối nam châm
      viTriTuongDoiNamCham.x = viTri.x - viTriNamChamX;
      viTriTuongDoiNamCham.y = viTri.y - viTriNamChamY;
      
      // ---- tính từ trường tại vị trí này
      Vecto tuTruong = tinhTuTruongNamTramHinhHopMoi2( &viTriTuongDoiNamCham, namCham );
      double tuTruongZ = tuTruong.z;
      
      // ---- góp phần điện thế
      dienThe += tuTruongZ*kGAUSS_QUYEN_LUONG_0*cach;
      
      // ==== 1
      cach = phongToDoan*kGAUSS_DIEM_1 + trungTamDoan;
      viTri.x = cach*cosGoc;
      viTri.y = cach*sinGoc;
      
      // ---- tính vị trí tương đối nam châm
      viTriTuongDoiNamCham.x = viTri.x - viTriNamChamX;
      viTriTuongDoiNamCham.y = viTri.y - viTriNamChamY;
      
      // ---- tính từ trường tại vị trí này
      tuTruong = tinhTuTruongNamTramHinhHopMoi2( &viTriTuongDoiNamCham, namCham );
      tuTruongZ = tuTruong.z;
      
      // ---- góp phần điện thế
      dienThe += tuTruongZ*kGAUSS_QUYEN_LUONG_1*cach;
      
      // ==== 2
      cach = phongToDoan*kGAUSS_DIEM_2 + trungTamDoan;
      viTri.x = cach*cosGoc;
      viTri.y = cach*sinGoc;
      
      // ---- tính vị trí tương đối nam châm
      viTriTuongDoiNamCham.x = viTri.x - viTriNamChamX;
      viTriTuongDoiNamCham.y = viTri.y - viTriNamChamY;
      
      // ---- tính từ trường tại vị trí này
      tuTruong = tinhTuTruongNamTramHinhHopMoi2( &viTriTuongDoiNamCham, namCham );
      tuTruongZ = tuTruong.z;
      
      // ---- góp phần điện thế
      dienThe += tuTruongZ*kGAUSS_QUYEN_LUONG_2*cach;
      
      // ==== 3
      cach = phongToDoan*kGAUSS_DIEM_3 + trungTamDoan;
      viTri.x = cach*cosGoc;
      viTri.y = cach*sinGoc;
      
      // ---- tính vị trí tương đối nam châm
      viTriTuongDoiNamCham.x = viTri.x - viTriNamChamX;
      viTriTuongDoiNamCham.y = viTri.y - viTriNamChamY;
      
      // ---- tính từ trường tại vị trí này
      tuTruong = tinhTuTruongNamTramHinhHopMoi2( &viTriTuongDoiNamCham, namCham );
      tuTruongZ = tuTruong.z;
      
      // ---- góp phần điện thế
      dienThe += tuTruongZ*kGAUSS_QUYEN_LUONG_3*cach;
      
      // ---- đoạn tiếp
      trungTamDoan += chieuDaiDoan;
      chiSoDoanCong++;
   }
   
   // ==============================
   // +    |<-------|
   double gocCuoi = gocXoay + chieuRongGoc;
   cosGoc = cos( gocCuoi );
   sinGoc = sin( gocCuoi );
   trungTamDoan = banKinhNoi + chieuDaiDoan*0.5;
   
   chiSoDoanCong = 0;
   while( chiSoDoanCong < soDoanCong ) {
      // ==== 0
      // ----- tính điểm trên đường cong
      double cach = phongToDoan*kGAUSS_DIEM_0 + trungTamDoan;
      viTri.x = cach*cosGoc;
      viTri.y = cach*sinGoc;
      
      // ---- tính vị trí tương đối nam châm
      viTriTuongDoiNamCham.x = viTri.x - viTriNamChamX;
      viTriTuongDoiNamCham.y = viTri.y - viTriNamChamY;
      
      // ---- tính từ trường tại vị trí này
      Vecto tuTruong = tinhTuTruongNamTramHinhHopMoi2( &viTriTuongDoiNamCham, namCham );
      double tuTruongZ = tuTruong.z;
      
      // ---- góp phần điện thế
      dienThe -= tuTruongZ*kGAUSS_QUYEN_LUONG_0*cach;
      
      // ==== 1
      cach = phongToDoan*kGAUSS_DIEM_1 + trungTamDoan;
      viTri.x = cach*cosGoc;
      viTri.y = cach*sinGoc;
      
      // ---- tính vị trí tương đối nam châm
      viTriTuongDoiNamCham.x = viTri.x - viTriNamChamX;
      viTriTuongDoiNamCham.y = viTri.y - viTriNamChamY;
      
      // ---- tính từ trường tại vị trí này
      tuTruong = tinhTuTruongNamTramHinhHopMoi2( &viTriTuongDoiNamCham, namCham );
      tuTruongZ = tuTruong.z;
      
      // ---- góp phần điện thế
      dienThe -= tuTruongZ*kGAUSS_QUYEN_LUONG_1*cach;
      
      // ==== 2
      cach = phongToDoan*kGAUSS_DIEM_2 + trungTamDoan;
      viTri.x = cach*cosGoc;
      viTri.y = cach*sinGoc;
      
      // ---- tính vị trí tương đối nam châm
      viTriTuongDoiNamCham.x = viTri.x - viTriNamChamX;
      viTriTuongDoiNamCham.y = viTri.y - viTriNamChamY;
      
      // ---- tính từ trường tại vị trí này
      tuTruong = tinhTuTruongNamTramHinhHopMoi2( &viTriTuongDoiNamCham, namCham );
      tuTruongZ = tuTruong.z;
      
      // ---- góp phần điện thế
      dienThe -= tuTruongZ*kGAUSS_QUYEN_LUONG_2*cach;
      
      // ==== 3
      cach = phongToDoan*kGAUSS_DIEM_3 + trungTamDoan;
      viTri.x = cach*cosGoc;
      viTri.y = cach*sinGoc;
      
      // ---- tính vị trí tương đối nam châm
      viTriTuongDoiNamCham.x = viTri.x - viTriNamChamX;
      viTriTuongDoiNamCham.y = viTri.y - viTriNamChamY;
      
      // ---- tính từ trường tại vị trí này
      tuTruong = tinhTuTruongNamTramHinhHopMoi2( &viTriTuongDoiNamCham, namCham );
      tuTruongZ = tuTruong.z;
      
      // ---- góp phần điện thế
      dienThe -= tuTruongZ*kGAUSS_QUYEN_LUONG_3*cach;
      
      // ---- đoạn tiếp
      trungTamDoan += chieuDaiDoan;
      chiSoDoanCong++;
   }
   
   // ---- cuối cùnh nhân hphóng to đoạn
   dienThe *= phongToDoan;
   
   return dienThe;
   
}
