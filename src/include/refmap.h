#ifndef CMARK_REFMAP_H
#define CMARK_REFMAP_H

#include "map.h"

#ifdef __cplusplus
extern "C" {
#endif

/** Opaque handle to the map of reference definitions. */
typedef struct cmark_map cmark_map;

/** Opaque handle to one entry in that map. */
typedef struct cmark_map_entry cmark_map_entry;

/** The user‐visible view of a reference definition. */
typedef struct {
  const char *label;   /* the normalized label, e.g. "foo" */
  const char *url;     /* the URL string */
  const char *title;   /* the optional title (may be "") */
  int start_line;
  int start_column;
  int end_line;
  int end_column;
} cmark_reference_definition;

/** Walk the map’s linked list: */
CMARK_GFM_EXPORT
cmark_map_entry *cmark_map_first_entry(cmark_map *map);

CMARK_GFM_EXPORT
cmark_map_entry *cmark_map_entry_next(cmark_map_entry *entry);

/** Cast the entry to a cmark_reference: */
CMARK_GFM_EXPORT
const cmark_reference_definition *cmark_map_entry_get_definition(cmark_map_entry *entry);

#ifdef __cplusplus
}
#endif

#endif
