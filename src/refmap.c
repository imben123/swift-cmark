#include "refmap.h"
#include "map.h"         /* internal: defines struct cmark_map, cmark_map_entry */
#include "references.h"  /* internal: defines struct cmark_reference */

cmark_map_entry *
cmark_map_first_entry(cmark_map *map) {
    return map ? map->refs : NULL;
}

cmark_map_entry *
cmark_map_entry_next(cmark_map_entry *entry) {
    return entry ? entry->next : NULL;
}

const cmark_reference_definition *
cmark_map_entry_get_definition(cmark_map_entry *entry) {
  if (!entry) return NULL;

  /* The internal struct cmark_reference lays out its first fields as:
     map_entry entry;
     bool is_attributes_reference;
   so offset of url/title is stable.
   We pretend the first three fields of that struct match our public view. */

  struct cmark_reference *internal = (struct cmark_reference *)entry;
  static cmark_reference_definition def;

  def.label = (const char *)internal->entry.label;
  def.url   = (const char *)internal->url.data;
  def.title = (const char *)internal->title.data;
  def.start_line = internal->start_line;
  def.start_column = internal->start_column;
  def.end_line = internal->end_line;
  def.end_column = internal->end_column;
  return &def;
}
