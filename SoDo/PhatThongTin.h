// PhatThongTin.h
// 2023.09.19

#pragma once

#include "../NamCham/NamChamHinhTru.h"
#include "../NamCham/NamChamHinhHop.h"
#include "../DongDien/DongDienPhanHinhTron.h"
#include "../DongDien/DongDienHinhTron.h"


void phatThongTinNamChamHinhTru( FILE *tepSVG, float viTriX, float viTriY, NamChamHinhTru *mangNamCham, unsigned char soNamCham );

void phatThongTinNamChamHinhHop( FILE *tepSVG, float viTriX, float viTriY, NamChamHinhHop *mangNamCham, unsigned char soNamCham );

void phatThongTinDongDienPhanHinhTron(  FILE *tepSVG, float viTriX, float viTriY, DongDienPhanHinhTron *dongDien, unsigned char soDongDien );

void phatThongTinDongDienHinhTron(  FILE *tepSVG, float viTriX, float viTriY, DongDienHinhTron *dongDien, unsigned char soDongDien );
