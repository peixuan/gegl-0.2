/* This file is an image processing operation for GEGL
 *
 * GEGL is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * GEGL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with GEGL; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 * Copyright 2006 Øyvind Kolås <pippin@gimp.org>
 */
#if GEGL_CHANT_PROPERTIES
gegl_chant_double (value, -10.0, 10.0, 0.5, "global opacity value, used if no aux input is provided")
#else

#define GEGL_CHANT_POINT_COMPOSER
#define GEGL_CHANT_NAME            opacity
#define GEGL_CHANT_DESCRIPTION     "weights the opacity of the input with either the value of the aux input or the global value property"
#define GEGL_CHANT_SELF            "opacity.c"
#define GEGL_CHANT_CATEGORIES      "transparency"
#define GEGL_CHANT_INIT
#include "gegl-chant.h"

static void init (GeglChantOperation *self)
{
  GEGL_OPERATION_POINT_COMPOSER (self)->format = babl_format ("RaGaBaA float");
  GEGL_OPERATION_POINT_COMPOSER (self)->aux_format = babl_format ("Y float");
}

static gboolean
process (GeglOperation *op,
          void          *in_buf,
          void          *aux_buf,
          void          *out_buf,
          glong          n_pixels)
{

  gfloat *in = in_buf;
  gfloat *out = out_buf;
  gfloat *aux = aux_buf;

  if (aux == NULL)
    {
      gint i;
      gfloat value = GEGL_CHANT_OPERATION (op)->value;
      for (i=0; i<n_pixels; i++)
        {
          gint j;
          for (j=0; j<4; j++)
            out[j] = in[j] * value;
          in  += 4;
          out += 4;
        }
    }
  else
    {
      gint i;
      for (i=0; i<n_pixels; i++)
        {
          gint j;
          for (j=0; j<4; j++)
            out[j] = in[j] * (*aux);
          in  += 4;
          out += 4;
          aux += 1;
        }
    }
  return TRUE;
}
#endif
