// SơồHìnhVuông.h
// 2023.09.19

// Cho vẽ vị trí nam châm và dòng điện 

#pragma once

#include "../NamCham/NamChamHinhTru.h"
#include "../NamCham/NamChamHinhHop.h"
#include "../DongDien/DongDienPhanHinhTron.h"
#include "../DongDien/DongDienHinhTron.h"


void veNhungNamChamHinhTru( FILE *tepSVG, NamChamHinhTru *mangNamCham, unsigned char soNamCham, float trungTam_x, float trungTam_y, float phongTo );
void veNhungNamChamHinhHop( FILE *tepSVG, NamChamHinhHop *mangNamCham, unsigned char soNamCham, float trungTam_x, float trungTam_y, float phongTo );

void veDongDienPhanHinhTron( FILE *tepSVG, DongDienPhanHinhTron *mangDongDien, unsigned char soDongDien, float trungTam_x, float trungTam_y, float phongTo );
void veDongDienHinhTron( FILE *tepSVG, DongDienHinhTron *mangDongDien, unsigned char soDongDien, float trungTam_x, float trungTam_y, float phongTo, float pha );

void veNenSoDoDongDien( FILE *tepSVG, SoDoDongDien *soDo );
