#ifndef CMARK_GFM_UNDERLINE_H
#define CMARK_GFM_UNDERLINE_H

#include "cmark-gfm-core-extensions.h"

extern cmark_node_type CMARK_NODE_UNDERLINE;
cmark_syntax_extension *create_underline_extension(void);

#endif
