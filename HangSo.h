// HằngSố.h
// 2023.08.28

#pragma once


/*
 Đoàn chuẩn rộng hai đơn vị
 v        v           v        v
 +-----+--------+-----+-----+--------+-----+
 -1.0  -0.86    -0.34   0.0  0.34    0.86    1.0
 
 */
/* Những hằng số cầu phương Gauss  */
#define kGAUSS_DIEM_0 -0.861136115940526
#define kGAUSS_DIEM_1 -0.3399810435848563
#define kGAUSS_DIEM_2  0.3399810435848563
#define kGAUSS_DIEM_3  0.861136115940526

#define kGAUSS_QUYEN_LUONG_0 0.3478548451374538
#define kGAUSS_QUYEN_LUONG_1 0.6521451548625461
#define kGAUSS_QUYEN_LUONG_2 0.6521451548625461
#define kGAUSS_QUYEN_LUONG_3 0.3478548451374538

// ---- hằnng số toán
#define kPI      3.141592654
#define k2_PI    6.283185307

// ---- xuất loại tập tin
#define kXUAT_TAP_TIN__SVG     0x01
#define kXUAT_TAP_TIN__BANG_SO 0x02


// 1.0 e-7 = µ_0/4π H/m --> hằng số từ trường
#define kHANG_SO_TU_TRUONG 1.0e-4  //1.0e-7 * 1000 mm //

/* Đơn vị
   B = µ_0/4π ∫∫(M x r)/r^3 dS
 => T = H/m • ((A/m) • m) • m^–3 • m^2
 = H/m^2 • (A)
 
 Nếu dùng mm thay m
=> H/m • (A/mm •mm) • mm^2 / mm^3
= H/m (A)/mm

= H/m (A)/mm • (1000 mm /m)

=1000 H/m^2 (A)
= 1.0e3 • 1.0e-7 = 1.0e-4 H/mm
*/
