#!/usr/bin/env ruby

copyright = '
/* !!!! AUTOGENERATED FILE generated by porter-duff.rb !!!!! 
 *
 *  Copyright 2006 Øyvind Kolås <pippin@gimp.org>
 *
 * !!!! AUTOGENERATED FILE !!!!!
 *
 */'

a = [
      ['atop',         'cA * aB  + cB * (1.0 - aA)'],
      ['atop_reverse', 'cA * (1.0- aB) + cB * aA'],
      ['clear',        '0.0'],
      ['dst',          'cB  * 1.0'],
      ['in',           'cA * aB'],
      ['in_reverse',   'cB * aA'],
      ['out',          'cA * (1.0 - aB)'],
      ['out_reverse',  'cB * (1.0 - aA)'],
      ['over',         'cA + cB * (1.0 - aA)'],
      ['src',          'cA'],
      ['under',        'cA * (1.0 - aB) + cB'],
      ['xor',          'cA * (1.0 - aB) + cB * (1.0 - aA)'],
    ]

a.each do
    |item|

    name     = item[0] + ''
    filename = name + '.c'

    puts "generating #{filename}"
    file = File.open(filename, 'w')

    name        = item[0]
    capitalized = name.capitalize
    swapcased   = name.swapcase
    formula     = item[1]

    file.write copyright
    file.write "
#if GEGL_CHANT_PROPERTIES
/* no properties */
#else

#define GEGL_CHANT_POINT_COMPOSER
#define GEGL_CHANT_NAME          #{name}
#define GEGL_CHANT_DESCRIPTION   \"Porter Duff operation #{name} (c = #{formula})\"
#define GEGL_CHANT_CATEGORIES    \"compositors:porter duff\"
#define GEGL_CHANT_SELF          \"#{filename}\"
#define GEGL_CHANT_INIT
#include \"gegl-chant.h\"

static void init (GeglChantOperation *self)
{
  GEGL_OPERATION_POINT_COMPOSER (self)->format = babl_format (\"RaGaBaA float\");
  GEGL_OPERATION_POINT_COMPOSER (self)->aux_format = babl_format (\"RaGaBaA float\");

}

static gboolean
process (GeglOperation *op,
          void          *in_buf,
          void          *aux_buf,
          void          *out_buf,
          glong          n_pixels)
{
  gint i;
  gfloat *in = in_buf;
  gfloat *aux = aux_buf;
  gfloat *out = out_buf;

  if (aux==NULL)
    return TRUE;

  for (i=0; i<n_pixels; i++)
    {
      int  j;
      gfloat aA, aB;

      aB=in[3];
      aA=aux[3];
      for (j=0; j<4; j++)
          {
              gfloat cA, cB;

              cB=in[j];
              cA=aux[j];
              out[j] = #{formula};
          }
      in  += 4;
      aux += 4;
      out += 4;
    }
  return TRUE;
}

#endif
"

  file.close
end
