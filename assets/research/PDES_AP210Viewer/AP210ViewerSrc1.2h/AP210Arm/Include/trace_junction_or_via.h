#ifndef TRACE_JUNCTION_OR_VIA_H
#define TRACE_JUNCTION_OR_VIA_H

// Enumerations
union trace_junction_or_via {
   class inter_stratum_join_relationship *ST_inter_stratum_join_relationship;
   class explicitly_located_layer_connection_point *ST_explicitly_located_layer_connection_point;
   };

#endif
