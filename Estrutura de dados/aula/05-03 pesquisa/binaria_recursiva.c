int 
buscaBinaria2 (int x, int n, int v[]) {
   return bb (x, -1, n, v);
}
static int 
bb (int x, int e, int d, int v[]) {
   if (e == d-1) return d;  
   else {
      int m = (e + d)/2;
      if (v[m] < x)  
         return bb (x, m, d, v);
      else  
         return bb (x, e, m, v); 
   } 
}