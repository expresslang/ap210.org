#ifndef PRODUCT_OBJECT_SELECT_H
#define PRODUCT_OBJECT_SELECT_H

// Enumerations
union product_object_select {
   class ee_product_configuration *ST_ee_product_configuration;
   class ee_product_definition *ST_ee_product_definition;
   class ee_product_version *ST_ee_product_version;
   class ee_product *ST_ee_product;
   class part_feature *ST_part_feature;
   class physical_connectivity_element *ST_physical_connectivity_element;
   class physical_connectivity_definition *ST_physical_connectivity_definition;
   union restriction_basis_item *ST_restriction_basis_item;
   };

#endif
