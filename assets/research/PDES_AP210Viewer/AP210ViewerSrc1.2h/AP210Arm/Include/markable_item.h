#ifndef MARKABLE_ITEM_H
#define MARKABLE_ITEM_H

// Enumerations
union markable_item {
   class assembly_module *ST_assembly_module;
   class bare_die *ST_bare_die;
   class interconnect_module *ST_interconnect_module;
   class package *ST_package;
   class pca *ST_pca;
   class pcb *ST_pcb;
   class packaged_part *ST_packaged_part;
   };

#endif
