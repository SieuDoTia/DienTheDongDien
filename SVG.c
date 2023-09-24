// SVG.c
// 2009.06.03


#include <stdio.h>
#include <math.h>
#include "SVG.h"

// M - di chuyên ̉ đến  ̣iểm (x; y) nhưng không vẽ gì
// L - vẽ đường thẳng đến điểm (x; y)
// C - vẽ đường cong (x; y) (x; y) (x; y)
// A - vẽ hình cung bắt đầu từ điểm (x; y) bánKínhX bbánKínhY

// z - kết thúc nét và nối với đầu nét

#pragma mark ==== Lưu đầu tệp SVG
void luuDauSVG( FILE *tep, unsigned int beRong, unsigned int beCao ) {    // ---- đầu tập tin SVG

   fprintf( tep, "<svg version=\"1.1\" width=\"%d\" height=\"%d\" xmlns=\"http://www.w3.org/2000/svg\">\n\n", beRong, beCao );
}

void ketThucSVG( FILE *tep ) {
   
   // ---- kết thúc tệp SVG
   fprintf( tep, "</svg>\n" );
}


#pragma mark ==== Hình Chủ Nhật, Tròn, Elip
// Vẽ hình chữ nhật tại góc trái dưới tại (gocX; gocY)
void chuNhat( FILE *tep, float gocX, float gocY, float beRong, float beCao, unsigned char toDay, unsigned int mauToDay, float doDucToDay,
         unsigned char net, float beRongNet, unsigned int mauNet, float doDucNet ) {
   
	fprintf( tep, "<rect x=\"%5.1f\" y=\"%5.1f\" width=\"%5.1f\" height=\"%5.1f\" ", gocX, gocY, beRong, beCao );
	if( toDay )
	   fprintf( tep, "fill=\"#%06X\" fill-opacity=\"%4.2f\" ", mauToDay, doDucToDay );
	else
	   fprintf( tep, "fill=\"none\" " );
	if( net ) {
	   fprintf( tep, "stroke=\"#%06X\" stroke-opacity=\"%4.2f\" ", mauNet, doDucNet );
	   fprintf( tep, "stroke-width=\"%5.1f\" ", beRongNet );
	}
	else {
	   fprintf( tep, "stroke=\"none\" " );
	}

   fprintf( tep, "/>\n\n" );
}


// Vẽ hình tròn tại điểm (tamX; tamY)
void hinhTron( FILE *tep, float tamX, float tamY, float banKinh, unsigned char toDay, unsigned int mauToDay, float doDucToDay,
         unsigned char net, float beRongNet, unsigned int mauNet, float doDucNet ) {
   
	fprintf( tep, "<circle cx=\"%5.1f\" cy=\"%5.1f\" r=\"%5.1f\" ", tamX, tamY, banKinh );
	if( toDay )
	   fprintf( tep, "fill=\"#%06X\" fill-opacity=\"%4.2f\" ", mauToDay, doDucToDay );
	else
	   fprintf( tep, "fill=\"none\" " );
	if( net ) {
	   fprintf( tep, "stroke=\"#%06X\" stroke-opacity=\"%4.2f\" ", mauNet, doDucNet );
	   fprintf( tep, "stroke-width=\"%5.1f\" ", beRongNet );
	}
	else {
	   fprintf( tep, "stroke=\"none\" " );
	}

   fprintf( tep, "/>\n\n" );
}

void hinhCungTron( FILE *tep, float batDauX, float batDauY, float banKinh, float gocXoayX, unsigned char xaNhat, unsigned char quetAm,
                  float ketThucX, float ketThucY,
                  unsigned char toDay, unsigned int mauToDay, float doDucToDay,
              unsigned char net, float beRongNet, unsigned int mauNet, float doDucNet ) {
   
   fprintf( tep, "<path d =\"M %5.1f %5.1f  A %5.1f %5.1f  %5.1f  %d %d  %5.1f %5.1f\" ",
           batDauX, batDauY, banKinh, banKinh, gocXoayX, xaNhat, quetAm, ketThucX, ketThucY );
   if( toDay )
      fprintf( tep, "fill=\"#%06X\" fill-opacity=\"%4.2f\" ", mauToDay, doDucToDay );
   else
      fprintf( tep, "fill=\"none\" " );
   if( net ) {
      fprintf( tep, "stroke=\"#%06X\" stroke-opacity=\"%4.2f\" ", mauNet, doDucNet );
      fprintf( tep, "stroke-width=\"%5.1f\" ", beRongNet );
   }
   else {
      fprintf( tep, "stroke=\"none\" " );
   }
   
   fprintf( tep, "/>\n\n" );
}


// Vẽ hình elips
void elip( FILE *tep, float tamX, float tamY, float banKinhX, float banKinhY, unsigned char toDay, unsigned int mauToDay, float doDucToDay,
         unsigned char net, float beRongNet, unsigned int mauNet, float doDucNet ) {

	fprintf( tep, "<ellipse cx=\"%5.1f\" cy=\"%5.1f\" rx=\"%5.1f\" ry=\"%5.1f\" ", tamX, tamY, banKinhX, banKinhY );
	if( toDay )
	   fprintf( tep, "fill=\"#%06X\" fill-opacity=\"%4.2f\" ", mauToDay, doDucToDay );
	else
	   fprintf( tep, "fill=\"none\" " );
	if( net ) {
	   fprintf( tep, "stroke=\"#%06X\" stroke-opacity=\"%4.2f\" ", mauNet, doDucNet );
	   fprintf( tep, "stroke-width=\"%5.1f\" ", beRongNet );
	}
	else {
	   fprintf( tep, "stroke=\"none\" " );
	}

   fprintf( tep, "/>\n\n" );
}


#pragma mark ==== Phần Hình Tròn
void hinhPhanTron( FILE *tep, float *mangDiem, float banKinhNgoai, float banKinhNoi,
                  float gocXoayX, unsigned char xaNhat, unsigned char quetAm,
                  unsigned char toDay, unsigned int mauToDay, float doDucToDay,
                  unsigned char net, float beRongNet, unsigned int mauNet, float doDucNet ) {
   
   fprintf( tep, "<path d =\"M %5.1f %5.1f  A %5.1f %5.1f  %5.1f  %d %d  %5.1f %5.1f ",
           mangDiem[0], mangDiem[1], banKinhNgoai, banKinhNgoai, gocXoayX, xaNhat, quetAm, mangDiem[2], mangDiem[3] );
   fprintf( tep, "  L %5.1f %5.1f ",
           mangDiem[4], mangDiem[5] );
   fprintf( tep, "  A %5.1f %5.1f  %5.1f  %d %d  %5.1f %5.1f z\" ",
           banKinhNoi, banKinhNoi, gocXoayX, xaNhat, !quetAm, mangDiem[6], mangDiem[7] );
   
   if( toDay )
      fprintf( tep, "fill=\"#%06X\" fill-opacity=\"%4.2f\" ", mauToDay, doDucToDay );
   else
      fprintf( tep, "fill=\"none\" " );
   if( net ) {
      fprintf( tep, "stroke=\"#%06X\" stroke-opacity=\"%4.2f\" ", mauNet, doDucNet );
      fprintf( tep, "stroke-width=\"%5.1f\" ", beRongNet );
   }
   else {
      fprintf( tep, "stroke=\"none\" " );
   }
   
   fprintf( tep, "/>\n\n" );
}


#pragma mark ==== Đường
// Vẽ một nét giữa hai điểm
void duong( FILE *tep, float diemX0, float diemY0, float diemX1, float diemY1, float beRongNet, unsigned int mauNet, float doDucNet ) {
   
   fprintf( tep, "<line x1=\"%5.1f\" y1=\"%5.1f\" x2=\"%5.1f\" y2=\"%5.1f\" stroke=\"#%06X\" stroke-opacity=\"%4.2f\" stroke-width=\"%5.1f\" />\n",
	               diemX0, diemY0, diemX1, diemY1, mauNet, doDucNet, beRongNet );
}


// Để vẽ một dãy nét
// mảng phải có điểm sắp xếp với nhau: x0; y0; x1; y1; ...
void duongDaDiem( FILE *tep, float *mangDiem, unsigned int soLuongDiem, unsigned char toDay, unsigned int mauToDay, float doDucToDay,
                    unsigned char net, float beRongNet, unsigned int mauNet, float doDucNet ) {
   int chiSo = 0; // points are interlaced

   fprintf( tep, "<polyline points=\"" );
   while( chiSo < soLuongDiem ) {
	   fprintf( tep, "%5.1f,%5.1f  ", mangDiem[chiSo << 1], mangDiem[(chiSo << 1) + 1] );
      if( chiSo % 10 == 0 )
		   fprintf( tep, "\n" );
      chiSo++;
	}

	fprintf( tep, "\"\n" );
	if( toDay )
	   fprintf( tep, "fill=\"#%06X\" fill-opacity=\"%4.2f\" ", mauToDay, doDucToDay );
	else
	   fprintf( tep, "fill=\"none\" " );
	if( net ) {
	   fprintf( tep, "stroke=\"#%06X\" stroke-opacity=\"%4.2f\" ", mauNet, doDucNet );
	   fprintf( tep, "stroke-width=\"%5.1f\" ", beRongNet );
	}
	else {
	   fprintf( tep, "stroke=\"none\" " );
	}

   fprintf( tep, "/>\n\n" );
}


// Để vẽ hình đa giác
// mảng phải có điểm sắp xếp với nhau: x0; y0; x1; y1; ...
void daGiac( FILE *tep, float *mangDiem, unsigned int soLuongDiem, unsigned char toDay, unsigned int mauToDay, float doDucToDay,
                    unsigned char net, float beRongNet, unsigned int mauNet, float doDucNet ) {
   int chiSoDiem = 0;

   fprintf( tep, "<polygon points=\"" );
   while( chiSoDiem < soLuongDiem ) {
	   fprintf( tep, "%5.1f,%5.1f  ", mangDiem[chiSoDiem << 1], mangDiem[(chiSoDiem << 1) + 1] );
      
      // ---- cho dễ nhìn trong tệp SVG
      if( chiSoDiem % 10 == 0 )
		   fprintf( tep, "\n" );
      
      chiSoDiem++;
	}

	fprintf( tep, "\"\n" );
	if( toDay )
	   fprintf( tep, "fill=\"#%06X\" fill-opacity=\"%4.2f\" ", mauToDay, doDucToDay );
	else
	   fprintf( tep, "fill=\"none\" " );
	if( net ) {
	   fprintf( tep, "stroke=\"#%06X\" stroke-opacity=\"%4.2f\" ", mauNet, doDucNet );
	   fprintf( tep, "stroke-width=\"%5.1f\" ", beRongNet );
	}
	else {
	   fprintf( tep, "stroke=\"none\" " );
	}

   fprintf( tep, "/>\n\n" );
}

void daGiacChuyenSac( FILE *tep, float *mangDiem, unsigned int soLuongDiem, unsigned int maSoChuyenSac ) {
   int chiSoDiem = 0;
   
   fprintf( tep, "<polygon points=\"" );
   while( chiSoDiem < soLuongDiem ) {
      fprintf( tep, "%5.1f,%5.1f  ", mangDiem[chiSoDiem << 1], mangDiem[(chiSoDiem << 1) + 1] );
      
      // ---- cho dễ nhìn trong tệp SVG
      if( chiSoDiem % 10 == 0 )
         fprintf( tep, "\n" );
      
      chiSoDiem++;
   }
   
   fprintf( tep, "\"\n" );

   fprintf( tep, "fill=\"url(#lg%d)\" ", maSoChuyenSac );
   fprintf( tep, "stroke=\"none\" " );

   fprintf( tep, "/>\n\n" );
}

// mảng có dữ liệu dạng: điểmĐiềuKhiển_X1, điểmĐiềuKhiển_Y1, điểmĐiềuKhiển_X2, điểmĐiềuKhiển_Y2, ... điểmKếtThúc_X, điểmKếtThúc_Y
void duongCong( FILE *tep, float diemBatDauX, float diemBatDauY, float *mangDiem, unsigned int soLuongKhuc,
                    unsigned char toDay, unsigned int mauToDay, float doDucToDay, unsigned char net, float beRongNet, unsigned int mauNet, float doDucNet ) {
   int chiSoKhuc = 0;

   fprintf( tep, "<path d=\" M%5.1f,%5.1f", diemBatDauX, diemBatDauY );
   while( chiSoKhuc < soLuongKhuc ) {
	   fprintf( tep, "\nC %5.1f,%5.1f %5.1f,%5.1f %5.1f,%5.1f",
		   mangDiem[chiSoKhuc*6], mangDiem[chiSoKhuc*6 + 1],
		   mangDiem[chiSoKhuc*6 + 2], mangDiem[chiSoKhuc*6 + 3],
		   mangDiem[chiSoKhuc*6 + 4], mangDiem[chiSoKhuc*6 + 5] );
      chiSoKhuc++;
   }
	fprintf( tep, "\"\n" );
	if( toDay )
	   fprintf( tep, "fill=\"#%06X\" fill-opacity=\"%4.2f\" ", mauToDay, doDucToDay );
	else
	   fprintf( tep, "fill=\"none\" " );
	if( net ) {
	   fprintf( tep, "stroke=\"#%06X\" stroke-opacity=\"%4.2f\" ", mauNet, doDucNet );
	   fprintf( tep, "stroke-width=\"%5.1f\" ", beRongNet );
	}
	else {
	   fprintf( tep, "stroke=\"none\" " );
	}

   fprintf( tep, "/>\n\n" );
}


void vanBan_ngang( FILE *tep, char *xau, float viTriX, float viTriY, char *giaDinhPhong, float coKichPhong, char *beDayPhong,
                       unsigned char toDay, unsigned int mauToDay, float doDucToDay, unsigned char net, float beRongNet, unsigned int mauNet, float doDucNet, char *canhHang ) {

   fprintf( tep, "<text x=\"%5.1f\" y=\"%5.1f\" font-family=\"%s\" font-size=\"%5.1f\" font-weight=\"%s\" writing-mode=\"lr\" ", viTriX, viTriY, giaDinhPhong, coKichPhong, beDayPhong );
   
   fprintf( tep, "text-anchor=\"%s\" ", canhHang );   // start middle  end
   
	if( toDay )
	   fprintf( tep, "fill=\"#%06X\" fill-opacity=\"%4.2f\" ", mauToDay, doDucToDay );
	else
	   fprintf( tep, "fill=\"none\" " );
	if( net ) {
	   fprintf( tep, "stroke=\"#%06X\" stroke-opacity=\"%4.2f\" ", mauNet, doDucNet );
	   fprintf( tep, "stroke-width=\"%5.1f\" ", beRongNet );
	}
	else {
	   fprintf( tep, "stroke=\"none\" " );
	}
   fprintf( tep, ">\n" );
	fprintf( tep, " %s </text>\n\n", xau );
}


void vanBan_ngangXoay( FILE *tep, char *xau, float viTriX, float viTriY, char *giaDinhPhong, float coKichPhong, char *beDayPhong,
                  unsigned char toDay, unsigned int mauToDay, float doDucToDay, unsigned char net, float beRongNet, unsigned int mauNet, float doDucNet, char *canhHang, float gocXoay ) {
   
   fprintf( tep, "<text x=\"%5.1f\" y=\"%5.1f\" font-family=\"%s\" font-size=\"%5.1f\" font-weight=\"%s\" writing-mode=\"lr\" ", viTriX, viTriY, giaDinhPhong, coKichPhong, beDayPhong );
   
   fprintf( tep, "text-anchor=\"%s\" dominant-baseline=\"central\" ", canhHang );   // start middle  end
   fprintf( tep, "transform=\"rotate(%5.1f, %5.1f, %5.1f)\" ", gocXoay, viTriX, viTriY );   // start middle  end
   
   if( toDay )
      fprintf( tep, "fill=\"#%06X\" fill-opacity=\"%4.2f\" ", mauToDay, doDucToDay );
   else
      fprintf( tep, "fill=\"none\" " );
   if( net ) {
      fprintf( tep, "stroke=\"#%06X\" stroke-opacity=\"%4.2f\" ", mauNet, doDucNet );
      fprintf( tep, "stroke-width=\"%5.1f\" ", beRongNet );
   }
   else {
      fprintf( tep, "stroke=\"none\" " );
   }
   fprintf( tep, ">\n" );
   fprintf( tep, " %s </text>\n\n", xau );
}


void vanBan_doc( FILE *tep, char *xau, float viTriX, float viTriY, char *giaDinhPhong, float coKichPhong, char *beDayPhong,
				         unsigned char toDay, unsigned int mauToDay, float doDucToDay, unsigned char net, float beRongNet, unsigned int mauNet, float doDucNet ) {

   fprintf( tep, "<text x=\"%5.1f\" y=\"%5.1f\" font-family=\"%s\" font-size=\"%5.1f\" font-weight=\"%s\" writing-mode=\"tb\" ", viTriX, viTriY, giaDinhPhong, coKichPhong, beDayPhong );
	if( toDay )
	   fprintf( tep, "fill=\"#%06X\" fill-opacity=\"%4.2f\" ", mauToDay, doDucToDay );
	else
	   fprintf( tep, "fill=\"none\" " );
	if( net ) {
	   fprintf( tep, "stroke=\"#%06X\" stroke-opacity=\"%4.2f\" ", mauNet, doDucNet );
	   fprintf( tep, "stroke-width=\"%5.1f\" ", beRongNet );
	}
	else {
	   fprintf( tep, "stroke=\"none\" " );
	}
   fprintf( tep, ">\n" );
	fprintf( tep, " %s </text>\n\n", xau );
}



#pragma mark ==== Chuyển Sắc
void datChuyeSacTuyenTinh( FILE *tep, unsigned int *mangMau, float *mangViTriBuoc,
                        unsigned short soLuongBuoc, unsigned int maSoChuyenSac, float viTriDauX, float viTriDauY, float viTriCuoiX, float viTriCuoiY ) {

   fprintf( tep, " <linearGradient id=\"lg%d\" gradientUnits=\"userSpaceOnUse\" x1=\"%5.1f\" y1=\"%5.1f\" x2=\"%5.1f\" y2=\"%5.1f\">\n", maSoChuyenSac, viTriDauX,viTriDauY, viTriCuoiX, viTriCuoiY );

   // các bước cho chuyển sắc
   unsigned short chiSoBuoc = 0;
   while( chiSoBuoc < soLuongBuoc ) {
      fprintf( tep, "  <stop offset=\"%5.2f\" stop-color=\"#%06X\" stop-opacity=\"1.0\"/>\n", mangViTriBuoc[chiSoBuoc], mangMau[chiSoBuoc] );
      chiSoBuoc++;
   }

   fprintf( tep, " </linearGradient>\n" );
}


