// Vecto.h
// 2558.12.16
// đổi từ float sang double

#pragma once

typedef struct {
   double x;   // tọa đồ x; y; z
   double y;
   double z;
} Vecto;

// ---- dịch vụ vectơ
void donViHoa( Vecto *vecto );   // đơn vị hóa
Vecto tichCoHuong( Vecto *vecto0, Vecto *vecto1 );   // tích có hướng
