/* gegl-chant contains incantations to that produce the boilerplate
 * needed to write GEGL operation plug-ins. It abstracts away inheritance
 * by giving a limited amount of base classes, and reduced creation of
 * a properties struct and registration of properties for that structure to
 * a minimum amount of code through use of the C preprocessor. You should
 * look at the operations implemented using chanting (they #include this file)
 * to see how it is used in practice.
 *
 * GEGL is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * GEGL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with GEGL; if not, see <http://www.gnu.org/licenses/>.
 *
 * 2006-2008 © Øyvind Kolås.
 */

#ifndef GEGL_CHANT_SELF
#error "GEGL_CHANT_SELF not defined"
#endif

#define GEGL_CHANT_PROPERTIES 1

/****************************************************************************/

#include <gegl-plugin.h>


#ifdef GEGL_CHANT_SOURCE
  #include <operation/gegl-operation-source.h>
  #include <operation/gegl-extension-handler.h>
  #define GEGL_CHANT_PARENT_TypeName      GeglOperationSource
  #define GEGL_CHANT_PARENT_TypeNameClass GeglOperationSourceClass
  #define GEGL_CHANT_PARENT_TYPE          GEGL_TYPE_OPERATION_SOURCE
  #define GEGL_CHANT_PARENT_CLASS         GEGL_OPERATION_SOURCE_CLASS
#endif
#ifdef GEGL_CHANT_SINK
  #include <operation/gegl-operation-sink.h>
  #define GEGL_CHANT_PARENT_TypeName      GeglOperationSink
  #define GEGL_CHANT_PARENT_TypeNameClass GeglOperationSinkClass
  #define GEGL_CHANT_PARENT_TYPE          GEGL_TYPE_OPERATION_SINK
  #define GEGL_CHANT_PARENT_CLASS         GEGL_OPERATION_SINK_CLASS
#endif
#ifdef GEGL_CHANT_FILTER
  #include <operation/gegl-operation-filter.h>
  #define GEGL_CHANT_PARENT_TypeName      GeglOperationFilter
  #define GEGL_CHANT_PARENT_TypeNameClass GeglOperationFilterClass
  #define GEGL_CHANT_PARENT_TYPE          GEGL_TYPE_OPERATION_FILTER
  #define GEGL_CHANT_PARENT_CLASS         GEGL_OPERATION_FILTER_CLASS
#endif
#ifdef GEGL_CHANT_POINT_FILTER
  #include <operation/gegl-operation-point-filter.h>
  #define GEGL_CHANT_PARENT_TypeName      GeglOperationPointFilter
  #define GEGL_CHANT_PARENT_TypeNameClass GeglOperationPointFilterClass
  #define GEGL_CHANT_PARENT_TYPE          GEGL_TYPE_OPERATION_POINT_FILTER
  #define GEGL_CHANT_PARENT_CLASS         GEGL_OPERATION_POINT_FILTER_CLASS
#endif
#ifdef GEGL_CHANT_AREA_FILTER
  #include <operation/gegl-operation-area-filter.h>
  #define GEGL_CHANT_PARENT_TypeName      GeglOperationAreaFilter
  #define GEGL_CHANT_PARENT_TypeNameClass GeglOperationAreaFilterClass
  #define GEGL_CHANT_PARENT_TYPE          GEGL_TYPE_OPERATION_AREA_FILTER
  #define GEGL_CHANT_PARENT_CLASS         GEGL_OPERATION_AREA_FILTER_CLASS
#endif
#ifdef GEGL_CHANT_COMPOSER
  #include <operation/gegl-operation-composer.h>
  #define GEGL_CHANT_PARENT_TypeName      GeglOperationComposer
  #define GEGL_CHANT_PARENT_TypeNameClass GeglOperationComposerClass
  #define GEGL_CHANT_PARENT_TYPE          GEGL_TYPE_OPERATION_COMPOSER
  #define GEGL_CHANT_PARENT_CLASS         GEGL_OPERATION_COMPOSER_CLASS
#endif
#ifdef GEGL_CHANT_POINT_COMPOSER
  #include <operation/gegl-operation-point-composer.h>
  #define GEGL_CHANT_PARENT_TypeName      GeglOperationPointComposer
  #define GEGL_CHANT_PARENT_TypeNameClass GeglOperationPointComposerClass
  #define GEGL_CHANT_PARENT_TYPE          GEGL_TYPE_OPERATION_POINT_COMPOSER
  #define GEGL_CHANT_PARENT_CLASS         GEGL_OPERATION_POINT_COMPOSER_CLASS
#endif
#ifdef GEGL_CHANT_META
  #include <operation/gegl-operation-meta.h>
  #define GEGL_CHANT_PARENT_TypeName      GeglOperationMeta
  #define GEGL_CHANT_PARENT_TypeNameClass GeglOperationMetaClass
  #define GEGL_CHANT_PARENT_TYPE          GEGL_TYPE_OPERATION_META
  #define GEGL_CHANT_PARENT_CLASS         GEGL_OPERATION_META_CLASS
#endif

typedef struct Generated        GeglChantOperation;
typedef struct GeneratedClass   ChantClass;

struct Generated
{
  GEGL_CHANT_PARENT_TypeName  parent_instance;
#define gegl_chant_int(name, min, max, def, blurb)     gint       name;
#define gegl_chant_double(name, min, max, def, blurb)  gdouble    name;
#define gegl_chant_boolean(name, def, blurb)           gboolean   name;
#define gegl_chant_string(name, def, blurb)            gchar     *name;
#define gegl_chant_path(name, def, blurb)              gchar     *name;
#define gegl_chant_multiline(name, def, blurb)              gchar     *name;
#define gegl_chant_multiline(name, def, blurb)         gchar     *name;
#define gegl_chant_object(name, blurb)                 GObject   *name;
#define gegl_chant_pointer(name, blurb)                gpointer   name;
#define gegl_chant_color(name, def, blurb)             GeglColor *name;
#define gegl_chant_curve(name, blurb)                  GeglCurve *name;
#define gegl_chant_vector(name, blurb)                 GeglVector *name;

#include GEGL_CHANT_SELF

/****************************************************************************/

/* undefining the chant macros before all subsequent inclusions */
#undef gegl_chant_int
#undef gegl_chant_double
#undef gegl_chant_boolean
#undef gegl_chant_string
#undef gegl_chant_path
#undef gegl_chant_multiline
#undef gegl_chant_multiline
#undef gegl_chant_object
#undef gegl_chant_pointer
#undef gegl_chant_color
#undef gegl_chant_curve
#undef gegl_chant_vector

/****************************************************************************/

  gpointer *priv;  /* free to use be implementer of operation */
};

struct GeneratedClass
{
  GEGL_CHANT_PARENT_TypeNameClass parent_class;
};

#define GEGL_CHANT_OPERATION(obj) ((GeglChantOperation*)(obj))

#ifndef GEGL_CHANT_STATIC
#  define M_DEFINE_TYPE_EXTENDED(type_name, TYPE_PARENT, flags, CODE) \
  \
static void     gegl_chant_init              (GeglChantOperation *self); \
static void     gegl_chant_class_init        (ChantClass    *klass); \
static GType    type_name##_get_type         (GTypeModule *module); \
G_MODULE_EXPORT const GeglModuleInfo * gegl_module_query     (GTypeModule *module);\
G_MODULE_EXPORT gboolean        gegl_module_register         (GTypeModule *module);\
static gpointer gegl_chant_parent_class = NULL; \
\
static void \
gegl_chant_class_intern_init (gpointer klass) \
{ \
  gegl_chant_parent_class = g_type_class_peek_parent (klass); \
  gegl_chant_class_init ((ChantClass*) klass); \
} \
\
static GType \
type_name##_get_type (GTypeModule *module) \
{ \
  static GType g_define_type_id = 0; \
  if (G_UNLIKELY (g_define_type_id == 0)) \
    { \
      static const GTypeInfo g_define_type_info = \
        { \
          sizeof (ChantClass), \
          (GBaseInitFunc) NULL, \
          (GBaseFinalizeFunc) NULL, \
          (GClassInitFunc) gegl_chant_class_intern_init, \
          (GClassFinalizeFunc) NULL, \
          NULL,   /* class_data */ \
          sizeof (GeglChantOperation), \
          0,      /* n_preallocs */ \
          (GInstanceInitFunc) gegl_chant_init, \
          NULL    /* value_table */ \
        }; \
      g_define_type_id = gegl_module_register_type (module, TYPE_PARENT,\
                                                    "GeglOpPlugIn-" #type_name,\
                                                    &g_define_type_info, \
                                                    (GTypeFlags) 0);\
    } \
  return g_define_type_id; \
}\
\
static const GeglModuleInfo modinfo =\
{\
 GEGL_MODULE_ABI_VERSION,\
 #type_name,\
 "v0.0",\
 "(c) 2006, released under the LGPL",\
 "June 2006"\
};\
\
G_MODULE_EXPORT const GeglModuleInfo *\
gegl_module_query (GTypeModule *module)\
{\
  return &modinfo;\
}\
\
G_MODULE_EXPORT gboolean \
gegl_module_register (GTypeModule *module)\
{\
  type_name##_get_type (module);\
  return TRUE;\
}

#else
#  define M_DEFINE_TYPE_EXTENDED(type_name, TYPE_PARENT, flags, CODE) \
  \
static void     gegl_chant_init              (GeglChantOperation   *self); \
static void     gegl_chant_class_init        (ChantClass *klass); \
static gpointer gegl_chant_parent_class = NULL; \
static void     gegl_chant_class_intern_init (gpointer klass) \
  { \
    gegl_chant_parent_class = g_type_class_peek_parent (klass); \
    gegl_chant_class_init ((ChantClass*) klass); \
  } \
\
static GType \
type_name##_get_type (GTypeModule *module) \
{ \
  static GType g_define_type_id = 0; \
  if (G_UNLIKELY (g_define_type_id == 0)) \
    { \
      static const GTypeInfo g_define_type_info = \
        { \
          sizeof (ChantClass), \
          (GBaseInitFunc) NULL, \
          (GBaseFinalizeFunc) NULL, \
          (GClassInitFunc) gegl_chant_class_intern_init, \
          (GClassFinalizeFunc) NULL, \
          NULL,   /* class_data */ \
          sizeof (GeglChantOperation), \
          0,      /* n_preallocs */ \
          (GInstanceInitFunc) gegl_chant_init, \
          NULL    /* value_table */ \
        }; \
      g_define_type_id = \
        g_type_register_static (TYPE_PARENT, "GeglOpPlugIn-" #type_name,\
                                &g_define_type_info, (GTypeFlags) flags); \
      { CODE ; } \
    } \
  return g_define_type_id; \
}
#endif

#define M_DEFINE_TYPE(t_n, T_P)   M_DEFINE_TYPE_EXTENDED (t_n, T_P, 0, )

M_DEFINE_TYPE (GEGL_CHANT_NAME, GEGL_CHANT_PARENT_TYPE)

enum
{
  PROP_0,
#define gegl_chant_int(name, min, max, def, blurb)     PROP_##name,
#define gegl_chant_double(name, min, max, def, blurb)  PROP_##name,
#define gegl_chant_boolean(name, def, blurb)           PROP_##name,
#define gegl_chant_string(name, def, blurb)            PROP_##name,
#define gegl_chant_path(name, def, blurb)              PROP_##name,
#define gegl_chant_multiline(name, def, blurb)         PROP_##name,
#define gegl_chant_object(name, blurb)                 PROP_##name,
#define gegl_chant_pointer(name, blurb)                PROP_##name,
#define gegl_chant_color(name, def, blurb)             PROP_##name,
#define gegl_chant_curve(name, blurb)                  PROP_##name,
#define gegl_chant_vector(name, blurb)                 PROP_##name,

#include GEGL_CHANT_SELF

#undef gegl_chant_int
#undef gegl_chant_double
#undef gegl_chant_boolean
#undef gegl_chant_string
#undef gegl_chant_path
#undef gegl_chant_multiline
#undef gegl_chant_object
#undef gegl_chant_pointer
#undef gegl_chant_color
#undef gegl_chant_curve
#undef gegl_chant_vector
  PROP_LAST
};

static void
get_property (GObject      *gobject,
              guint         property_id,
              GValue       *value,
              GParamSpec   *pspec)
{
  GeglChantOperation *self = GEGL_CHANT_OPERATION (gobject);

  switch (property_id)
  {
#define gegl_chant_int(name, min, max, def, blurb)\
    case PROP_##name: g_value_set_int (value, self->name);break;
#define gegl_chant_double(name, min, max, def, blurb)\
    case PROP_##name: g_value_set_double (value, self->name);break;
#define gegl_chant_boolean(name, def, blurb)\
    case PROP_##name: g_value_set_boolean (value, self->name);break;
#define gegl_chant_string(name, def, blurb)\
    case PROP_##name: g_value_set_string (value, self->name);break;
#define gegl_chant_path(name, def, blurb)\
    case PROP_##name: g_value_set_string (value, self->name);break;
#define gegl_chant_multiline(name, def, blurb)\
    case PROP_##name: g_value_set_string (value, self->name);break;
#define gegl_chant_object(name, blurb)\
    case PROP_##name: g_value_set_object (value, self->name);break;
#define gegl_chant_pointer(name, blurb)\
    case PROP_##name: g_value_set_pointer (value, self->name);break;
#define gegl_chant_color(name, def, blurb)\
    case PROP_##name: g_value_set_object (value, self->name);break;
#define gegl_chant_curve(name, blurb)\
    case PROP_##name: g_value_set_object (value, self->name);break;
#define gegl_chant_vector(name, blurb)\
    case PROP_##name: g_value_set_object (value, self->name);break;/*XXX*/

#include GEGL_CHANT_SELF

#undef gegl_chant_int
#undef gegl_chant_double
#undef gegl_chant_boolean
#undef gegl_chant_string
#undef gegl_chant_path
#undef gegl_chant_multiline
#undef gegl_chant_object
#undef gegl_chant_pointer
#undef gegl_chant_color
#undef gegl_chant_curve
#undef gegl_chant_vector
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (gobject, property_id, pspec);
      break;
  }
  self = NULL; /* silence GCC if no properties were defined */
}

static void
set_property (GObject      *gobject,
              guint         property_id,
              const GValue *value,
              GParamSpec   *pspec)
{
  GeglChantOperation *self = GEGL_CHANT_OPERATION (gobject);

  switch (property_id)
  {
#define gegl_chant_int(name, min, max, def, blurb)\
    case PROP_##name:\
      self->name = g_value_get_int (value);\
      break;
#define gegl_chant_double(name, min, max, def, blurb)\
    case PROP_##name:\
      self->name = g_value_get_double (value);\
      break;
#define gegl_chant_boolean(name, def, blurb)\
    case PROP_##name:\
      self->name = g_value_get_boolean (value);\
      break;
#define gegl_chant_string(name, def, blurb)\
    case PROP_##name:\
      if (self->name)\
        g_free (self->name);\
      self->name = g_strdup (g_value_get_string (value));\
      break;
#define gegl_chant_path(name, def, blurb)\
    case PROP_##name:\
      if (self->name)\
        g_free (self->name);\
      self->name = g_strdup (g_value_get_string (value));\
      break;
#define gegl_chant_multiline(name, def, blurb)\
    case PROP_##name:\
      if (self->name)\
        g_free (self->name);\
      self->name = g_strdup (g_value_get_string (value));\
      break;
#define gegl_chant_object(name, blurb)\
    case PROP_##name:\
      if (self->name != NULL) \
         g_object_unref (self->name);\
      self->name = g_value_dup_object (value);\
      break;
#define gegl_chant_pointer(name, blurb)\
    case PROP_##name:\
      self->name = g_value_get_pointer (value);\
      break;
#define gegl_chant_color(name, def, blurb)\
    case PROP_##name:\
      if (self->name != NULL && G_IS_OBJECT (self->name))\
         g_object_unref (self->name);\
      self->name = g_value_dup_object (value);\
      break;
#define gegl_chant_curve(name, blurb)\
    case PROP_##name:\
      if (self->name != NULL && G_IS_OBJECT (self->name))\
         g_object_unref (self->name);\
      self->name = g_value_dup_object (value);\
      break;
#define gegl_chant_vector(name, blurb)\
    case PROP_##name:\
      if (self->name != NULL && G_IS_OBJECT (self->name))\
        {/*XXX: remove old signal */\
         g_object_unref (self->name);\
        }\
      self->name = g_value_dup_object (value);\
      g_signal_connect (G_OBJECT (self->name), "changed", G_CALLBACK(gegl_operation_vector_prop_changed), self);\
      break; /*XXX*/

#include GEGL_CHANT_SELF

#undef gegl_chant_int
#undef gegl_chant_double
#undef gegl_chant_boolean
#undef gegl_chant_string
#undef gegl_chant_path
#undef gegl_chant_multiline
#undef gegl_chant_object
#undef gegl_chant_pointer
#undef gegl_chant_color
#undef gegl_chant_curve
#undef gegl_chant_vector

    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (gobject, property_id, pspec);
      break;
  }
  self = NULL; /* silence GCC if no properties were defined */
}

#ifdef GEGL_CHANT_POINT_FILTER
static gboolean process (GeglOperation *operation,
                         void          *in_buf,
                         void          *out_buf,
                         glong          samples);
#else
#ifdef GEGL_CHANT_COMPOSER
static gboolean process (GeglOperation       *operation,
                         GeglBuffer          *in_buf,
                         GeglBuffer          *aux_buf,
                         GeglBuffer          *out_buf,
                         const GeglRectangle *result);
#else
#ifdef GEGL_CHANT_POINT_COMPOSER
static gboolean process (GeglOperation *operation,
                         void          *in_buf,
                         void          *aux_buf,
                         void          *out_buf,
                         glong          samples);
#else
#ifdef GEGL_CHANT_SINK
static gboolean process (GeglOperation       *operation,
                         GeglBuffer          *input,
                         const GeglRectangle *result);
#else
#ifdef GEGL_CHANT_SOURCE
static gboolean process (GeglOperation       *operation,
                         GeglNodeContext     *context,
                         GeglBuffer          *output,
                         const GeglRectangle *result);
#else
#ifdef GEGL_CHANT_FILTER
static gboolean process (GeglOperation       *operation,
                         GeglBuffer          *input,
                         GeglBuffer          *output,
                         const GeglRectangle *result);
#else
#ifdef GEGL_CHANT_AREA_FILTER
static gboolean process (GeglOperation       *operation,
                         GeglBuffer          *input,
                         GeglBuffer          *output,
                         const GeglRectangle *result);
#else
#ifndef GEGL_CHANT_META
static gboolean process (GeglOperation       *operation,
                         GeglNodeContext     *context,
                         const GeglRectangle *result);
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif

static void
gegl_chant_init (GeglChantOperation *self)
{
  self->priv = NULL;
}

#ifdef GEGL_CHANT_INIT
static void init (GeglChantOperation *self);
#endif

#ifdef GEGL_CHANT_PREPARE
static void prepare (GeglOperation *self);
#endif

#ifdef GEGL_CHANT_AREA_FILTER
static void tickle (GeglOperation *self);
#endif

static void gegl_chant_destroy_notify (gpointer data)
{
  GeglChantOperation *self = GEGL_CHANT_OPERATION (data);

#define gegl_chant_int(name, min, max, def, blurb)
#define gegl_chant_double(name, min, max, def, blurb)
#define gegl_chant_boolean(name, def, blurb)
#define gegl_chant_string(name, def, blurb)\
  if (self->name)\
    {\
      g_free (self->name);\
      self->name = NULL;\
    }
#define gegl_chant_path(name, def, blurb)\
  if (self->name)\
    {\
      g_free (self->name);\
      self->name = NULL;\
    }
#define gegl_chant_multiline(name, def, blurb)\
  if (self->name)\
    {\
      g_free (self->name);\
      self->name = NULL;\
    }
#define gegl_chant_object(name, blurb)\
  if (self->name)\
    {\
      g_object_unref (self->name);\
      self->name = NULL;\
    }
#define gegl_chant_pointer(name, blurb)
#define gegl_chant_color(name, def, blurb)\
  if (self->name)\
    {\
      g_object_unref (self->name);\
      self->name = NULL;\
    }
#define gegl_chant_curve(name, blurb)\
  if (self->name)\
    {\
      g_object_unref (self->name);\
      self->name = NULL;\
    }
#define gegl_chant_vector(name, blurb)\
  if (self->name)\
    {\
      g_object_unref (self->name);\
      self->name = NULL;\
    } /*XXX*/

#include GEGL_CHANT_SELF

#undef gegl_chant_int
#undef gegl_chant_double
#undef gegl_chant_boolean
#undef gegl_chant_string
#undef gegl_chant_path
#undef gegl_chant_multiline
#undef gegl_chant_object
#undef gegl_chant_pointer
#undef gegl_chant_color
#undef gegl_chant_curve
#undef gegl_chant_vector
  self = NULL; /* shut up gcc warnings if there were no properties to clean up*/
}

static GObject *
gegl_chant_constructor (GType                  type,
                        guint                  n_construct_properties,
                        GObjectConstructParam *construct_properties)
{
  GObject *obj;

  obj = G_OBJECT_CLASS (gegl_chant_parent_class)->constructor (
            type, n_construct_properties, construct_properties);

#ifdef GEGL_CHANT_INIT
  init (GEGL_CHANT_OPERATION (obj));
#endif

  g_object_set_data_full (obj, "chant-data", obj, gegl_chant_destroy_notify);

  return obj;
}

#ifdef GEGL_CHANT_CLASS_INIT
static void class_init (GeglOperationClass *operation_class);
#endif

#ifdef GEGL_CHANT_SOURCE
static GeglRectangle get_defined_region (GeglOperation *self);
#endif

static void
gegl_chant_class_init (ChantClass * klass)
{
  GObjectClass               *object_class = G_OBJECT_CLASS (klass);
  GeglOperationClass         *operation_class;

#ifndef GEGL_CHANT_META
#ifndef GEGL_CHANT_AREA_FILTER
  GEGL_CHANT_PARENT_TypeNameClass *parent_class = GEGL_CHANT_PARENT_CLASS (klass);
#endif
#ifdef GEGL_CHANT_AREA_FILTER
  /* not really the parent class, but what we're after */
  GeglOperationFilterClass *parent_class = GEGL_OPERATION_FILTER_CLASS (klass);
#endif
  parent_class->process = process;
#endif
  operation_class = GEGL_OPERATION_CLASS (klass);

#ifdef GEGL_CHANT_PREPARE
  operation_class->prepare = prepare;
#endif

#ifdef GEGL_CHANT_AREA_FILTER
  operation_class->tickle = tickle;
#endif

  object_class->set_property = set_property;
  object_class->get_property = get_property;

  object_class->constructor  = gegl_chant_constructor;

#ifdef GEGL_CHANT_CLASS_INIT
  class_init (operation_class);
#endif

#ifdef GEGL_CHANT_SOURCE
  operation_class->get_defined_region = get_defined_region;
#endif

#define M_GEGL_CHANT_SET_NAME_EXTENDED(name) \
  gegl_operation_class_set_name (operation_class, #name);
#define M_GEGL_CHANT_SET_NAME(name)   M_GEGL_CHANT_SET_NAME_EXTENDED(name)
  M_GEGL_CHANT_SET_NAME (GEGL_CHANT_NAME);

#ifdef GEGL_CHANT_DESCRIPTION
  operation_class->description = GEGL_CHANT_DESCRIPTION;
#endif
#ifdef GEGL_CHANT_CATEGORIES
  operation_class->categories = GEGL_CHANT_CATEGORIES;
#else
  operation_class->categories = "misc";
#endif

#define gegl_chant_int(name, min, max, def, blurb)  \
  g_object_class_install_property (object_class, PROP_##name,\
                                   g_param_spec_int (#name, #name, blurb,\
                                                     min, max, def,\
                                                     (GParamFlags) (\
                                                     G_PARAM_READWRITE |\
                                                     G_PARAM_CONSTRUCT |\
                                                     GEGL_PARAM_PAD_INPUT)));
#define gegl_chant_double(name, min, max, def, blurb)  \
  g_object_class_install_property (object_class, PROP_##name,\
                                   g_param_spec_double (#name, #name, blurb,\
                                                        min, max, def,\
                                                        (GParamFlags) (\
                                                        G_PARAM_READWRITE |\
                                                        G_PARAM_CONSTRUCT |\
                                                        GEGL_PARAM_PAD_INPUT)));
#define gegl_chant_boolean(name, def, blurb)  \
  g_object_class_install_property (object_class, PROP_##name,\
                                   g_param_spec_boolean (#name, #name, blurb,\
                                                         def,\
                                                         (GParamFlags) (\
                                                         G_PARAM_READWRITE |\
                                                         G_PARAM_CONSTRUCT |\
                                                         GEGL_PARAM_PAD_INPUT)));
#define gegl_chant_string(name, def, blurb)  \
  g_object_class_install_property (object_class, PROP_##name,\
                                   g_param_spec_string (#name, #name, blurb,\
                                                        def,\
                                                        (GParamFlags) ( \
                                                        G_PARAM_READWRITE |\
                                                        G_PARAM_CONSTRUCT |\
                                                        GEGL_PARAM_PAD_INPUT)));
#define gegl_chant_path(name, def, blurb)  \
  g_object_class_install_property (object_class, PROP_##name,\
                                   gegl_param_spec_path (#name, #name, blurb,\
                                                         FALSE, FALSE,\
                                                         def,\
                                                         (GParamFlags) ( \
                                                         G_PARAM_READWRITE |\
                                                         G_PARAM_CONSTRUCT |\
                                                         GEGL_PARAM_PAD_INPUT)));
#define gegl_chant_multiline(name, def, blurb)  \
  g_object_class_install_property (object_class, PROP_##name,\
                                   gegl_param_spec_multiline (#name, #name, blurb,\
                                                         def,\
                                                         (GParamFlags) ( \
                                                         G_PARAM_READWRITE |\
                                                         G_PARAM_CONSTRUCT |\
                                                         GEGL_PARAM_PAD_INPUT)));
#define gegl_chant_object(name, blurb)  \
  g_object_class_install_property (object_class, PROP_##name,\
                                   g_param_spec_object (#name, #name, blurb,\
                                                        G_TYPE_OBJECT,\
                                                        (GParamFlags) (\
                                                        G_PARAM_READWRITE |\
                                                        G_PARAM_CONSTRUCT |\
                                                        GEGL_PARAM_PAD_INPUT)));
#define gegl_chant_pointer(name, blurb)  \
  g_object_class_install_property (object_class, PROP_##name,\
                                   g_param_spec_pointer (#name, #name, blurb,\
                                                        (GParamFlags) (\
                                                        G_PARAM_READWRITE |\
                                                        G_PARAM_CONSTRUCT |\
                                                        GEGL_PARAM_PAD_INPUT)));
#define gegl_chant_color(name, def, blurb)  \
  g_object_class_install_property (object_class, PROP_##name,\
                                   gegl_param_spec_color_from_string (#name, #name, blurb,\
                                                          def,\
                                                          (GParamFlags) (\
                                                          G_PARAM_READWRITE |\
                                                          G_PARAM_CONSTRUCT |\
                                                          GEGL_PARAM_PAD_INPUT)));
#define gegl_chant_curve(name, blurb)  \
  g_object_class_install_property (object_class, PROP_##name,\
                                   gegl_param_spec_curve (#name, #name, blurb,\
                                                          gegl_curve_default_curve(),\
                                                          (GParamFlags) (\
                                                          G_PARAM_READWRITE |\
                                                          G_PARAM_CONSTRUCT |\
                                                          GEGL_PARAM_PAD_INPUT)));
#define gegl_chant_vector(name, blurb)  \
  g_object_class_install_property (object_class, PROP_##name,\
                                   gegl_param_spec_vector (#name, #name, blurb,\
                                                           NULL, \
                                                          (GParamFlags) (\
                                                          G_PARAM_READWRITE |\
                                                          G_PARAM_CONSTRUCT |\
                                                          GEGL_PARAM_PAD_INPUT)));
#include GEGL_CHANT_SELF

#undef gegl_chant_int
#undef gegl_chant_double
#undef gegl_chant_boolean
#undef gegl_chant_string
#undef gegl_chant_path
#undef gegl_chant_multiline
#undef gegl_chant_object
#undef gegl_chant_pointer
#undef gegl_chant_color
#undef gegl_chant_curve
#undef gegl_chant_vector
}

/****************************************************************************/