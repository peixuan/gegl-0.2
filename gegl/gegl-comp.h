#ifndef __GEGL_COMP_H__
#define __GEGL_COMP_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "gegl-point-op.h"

#define GEGL_TYPE_COMP               (gegl_comp_get_type ())
#define GEGL_COMP(obj)               (G_TYPE_CHECK_INSTANCE_CAST ((obj), GEGL_TYPE_COMP, GeglComp))
#define GEGL_COMP_CLASS(klass)       (G_TYPE_CHECK_CLASS_CAST ((klass),  GEGL_TYPE_COMP, GeglCompClass))
#define GEGL_IS_COMP(obj)            (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GEGL_TYPE_COMP))
#define GEGL_IS_COMP_CLASS(klass)    (G_TYPE_CHECK_CLASS_TYPE ((klass),  GEGL_TYPE_COMP))
#define GEGL_COMP_GET_CLASS(obj)     (G_TYPE_INSTANCE_GET_CLASS ((obj),  GEGL_TYPE_COMP, GeglCompClass))

#ifndef __TYPEDEF_GEGL_COMP__
#define __TYPEDEF_GEGL_COMP__
typedef struct _GeglComp GeglComp;
#endif
struct _GeglComp 
{
   GeglPointOp point_op;

   /*< private >*/
   GeglCompositeMode comp_mode; 
};

typedef struct _GeglCompClass GeglCompClass;
struct _GeglCompClass 
{
   GeglPointOpClass point_op_class;
};

GType            gegl_comp_get_type         (void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
