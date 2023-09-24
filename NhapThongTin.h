/* NhậpThôngTin.h */
// 2023.09.22


#pragma once

#include "NamCham/NamCham.h"
#include "DongDien/DongDien.h"


void nhapDuLieuTuTapTin( char *tenTapTinDuLieu, ThongTinNamCham *thongTinNamCham,
                        ThongTinDongDien *thongTinDongDien, unsigned char *xuatTapTin );

void kiemTraThongTin( ThongTinNamCham *thongTinNamCham, ThongTinDongDien *thongTinDongDien,
                     unsigned char *xuatTapTin );
