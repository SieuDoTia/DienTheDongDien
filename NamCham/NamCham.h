// NamChâm.h
// 2023.09.21


#pragma once

#include "NamChamHinhTru.h"
#include "NamChamHinhHop.h"


// ---- loại nam châm
#define kNAM_CHAM__HINH_TRU 't'
#define kNAM_CHAM__HINH_HOP 'h'

/* Thông Tin Nam Châm */
typedef struct {
   unsigned char soLuong;   // số lượng
   unsigned char loai;      // loại
   double doCao;            // độ cao đo từ mặt phẳng dòng điện (mm)
   double cachTuTrungTam;   // cách từ trung tâm
   double cuongDo;          // cường độ
   union {
      NamChamHinhTru hinhTru;
      NamChamHinhHop hinhHop;
   } thongTin;    // thông tin
} ThongTinNamCham;
