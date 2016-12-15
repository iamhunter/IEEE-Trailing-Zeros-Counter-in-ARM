/* display the frequency of trailing zeros in floating-point
      numbers
   */

   #include <stdio.h>
   #include <math.h>
   #include <float.h>

   int trailing_zeros( int word );

   /* array of numbers to inspect - end with 0.0 */
   float a[] = { 1.0, 0.5, 0.375, 0.1, 1.0/3.0, 255.0,
                 M_E, M_PI, M_SQRT2, FLT_MAX,
                 0.0 };

   /* frequency count table */
   int count[24] = { 0 };

   int main()
   {
      /* union used to avoid conversion */
      union float_or_int
      {
         float f;
         int i;
      } number;

      int j;

      /* echo and inspect array entries */
      printf( "floating point numbers to inspect and count\n" );
      for( j = 0; a[j] != 0.0; j++ )
      {
         number.f = a[j];
         printf( "  %11g (hex representation = 0x%08x)\n",
                    number.f, number.i );
         count[ trailing_zeros( number.i ) ]++;
      }

      /* print frequency results */
      printf( "\nnumber of trailing zeros in float fractions\n" );
      printf( "  #0 - count\n" );
      for( j = 23; j >= 0; j-- )
      {
         printf( "  %2d - %2d\n", j, count[j] );
      }

      return 0;
   }
