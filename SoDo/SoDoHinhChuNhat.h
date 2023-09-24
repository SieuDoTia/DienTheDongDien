// SơồHìnhChữNhật.h
// 2023.09.19

#pragma once

#include "../NamCham/NamChamHinhTru.h"
#include "../NamCham/NamChamHinhHop.h"
#include "../DongDien/DongDienPhanHinhTron.h"
#include "../DongDien/DongDienHinhTron.h"

void veSoDo_dangSong( FILE *tepSVG, double *mangDuLieu, unsigned short soDiem, SoDoChuNhat *soDo );
void veSoDo_doCaoNamChamHinhTron( FILE *tepSVG, SoDoDoCaoNamCham *soDo );
