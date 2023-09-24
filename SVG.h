// SVG.h
// 2009.06.03

#pragma once

#define kSAI  0
#define kDUNG 1

// khổ giấy A4 cho SVG
#define kCHIEU_CAO__A4    1123 // điểm ảnh
#define kCHIEU_RONG__A4    794 // điểm ảnh

#define kCHIEU_CAO__A3    1587 // điểm ảnh
#define kCHIEU_RONG__A3   1123 // điểm ảnh

#define kCHIEU_CAO__A2    2245 // điểm ảnh
#define kCHIEU_RONG__A2   1587 // điểm ảnh

#include <stdio.h>

// ---- lưu đầu tập tin SVG
void luuDauSVG( FILE *tep, unsigned int beRong, unsigned int beCao );      // ---- đầu tập tin SVG

void ketThucSVG( FILE *tep );


// ---- hình chủ nhật, tròn, elip
void chuNhat( FILE *tep, float gocX, float gocY, float beRong, float beCao, unsigned char toDay, unsigned int mauToDay, float doDucToDay,
          unsigned char net, float beRongNet, unsigned int mauNet, float doDucNet );
 
void hinhTron( FILE *tep, float tamX, float tamY, float banKinh, unsigned char toDay, unsigned int mauToDay, float doDucToDay,
            unsigned char net, float beRongNet, unsigned int mauNet, float doDucNet );

void hinhCungTron( FILE *tep, float batDauX, float batDauY, float banKinh, float gocXoayX,
                  unsigned char xaNhat, unsigned char quetAm,
                  float ketThucX, float ketThucY,
                  unsigned char toDay, unsigned int mauToDay, float doDucToDay,
                  unsigned char net, float beRongNet, unsigned int mauNet, float doDucNet );

void elip( FILE *tep, float tamX, float tamY, float banKinhX, float banKinhY, unsigned char toDay, unsigned int mauToDay, float doDucToDay,
             unsigned char net, float beRongNet, unsigned int mauNet, float doDucNet );

// ---- phần hình tròn
void hinhPhanTron( FILE *tep, float *mangDiem, float banKinhNgoai, float banKinhNoi,
                  float gocXoayX, unsigned char xaNhat, unsigned char quetAm,
                  unsigned char toDay, unsigned int mauToDay, float doDucToDay,
                  unsigned char net, float beRongNet, unsigned int mauNet, float doDucNet );

// ---- đường
void duong( FILE *tep, float diemX0, float diemY0, float diemX1, float diemY1, float beRongNet, unsigned int mauNet, float doDucNet );
 
void duongDaDiem( FILE *tep, float *mangDiem, unsigned int soLuongDiem, unsigned char toDay, unsigned int mauToDay, float doDucToDay,
                    unsigned char net, float beRongNet, unsigned int mauNet, float doDucNet );
 
void daGiac( FILE *tep, float *mangDiem, unsigned int soLuongDiem, unsigned char toDay, unsigned int mauToDay, float doDucToDay,
unsigned char net, float beRongNet, unsigned int mauNet, float doDucNet );

void daGiacChuyenSac( FILE *tep, float *mangDiem, unsigned int soLuongDiem, unsigned int maSoChuyenSac );
 
void duongCong( FILE *tep, float diemBatDauX, float diemBatDauY, float *mangDiem, unsigned int soLuongKhuc,
                unsigned char toDay, unsigned int mauToDay, float doDucToDay, unsigned char net, float beRongNet, unsigned int mauNet, float doDucNet );

// ---- văn bản
void vanBan_ngang( FILE *tep, char *xau, float viTriX, float viTriY, char *giaDinhPhong, float coKichPhong, char *beDayPhong,
unsigned char toDay, unsigned int mauToDay, float doDucToDay, unsigned char net, float beRongNet, unsigned int mauNet, float doDucNet,
                   char *canhHang );

void vanBan_ngangXoay( FILE *tep, char *xau, float viTriX, float viTriY, char *giaDinhPhong, float coKichPhong, char *beDayPhong,
                      unsigned char toDay, unsigned int mauToDay, float doDucToDay, unsigned char net, float beRongNet, unsigned int mauNet, float doDucNet, char *canhHang, float gocXoay );

void vanBan_doc( FILE *tep, char *xau, float viTriX, float viTriY, char *giaDinhPhong, float coKichPhong, char *beDayPhong,
                 unsigned char toDay, unsigned int mauToDay, float doDucToDay, unsigned char net, float beRongNet, unsigned int mauNet, float doDucNet );
 
// ---- Đặt chuyển sắc
void datChuyeSacTuyenTinh( FILE *tep, unsigned int *mangMau, float *mangViTriBuoc,
                          unsigned short soLuongBuoc, unsigned int maSoChuyenSac, float viTriDauX, float viTriDauY, float viTriCuoiX, float viTriCuoiY );
 
