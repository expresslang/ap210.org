# Microsoft Developer Studio Project File - Name="AP210Arm" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=AP210Arm - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "AP210Arm.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "AP210Arm.mak" CFG="AP210Arm - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "AP210Arm - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "AP210Arm - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "AP210Arm - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I "c:\steptools_7.0\include" /I "d:\ap210viewer\ap210viewer\ap210arm" /I "d:\ap210viewer\ap210viewer\ap210arm\include" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /D "AP210ARM_EXPORTS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 /nologo /subsystem:windows /dll /machine:I386

!ELSEIF  "$(CFG)" == "AP210Arm - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /I "c:\steptools_7.0\include" /I "d:\ap210viewer\ap210viewer\ap210arm" /I "d:\ap210viewer\ap210viewer\ap210arm\include" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /D "AP210ARM_EXPORTS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "AP210Arm - Win32 Release"
# Name "AP210Arm - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AP210Arm.cpp
# End Source File
# Begin Source File

SOURCE=.\AP210Arm.def
# End Source File
# Begin Source File

SOURCE=.\AP210Arm.odl
# End Source File
# Begin Source File

SOURCE=.\AP210Arm.rc
# End Source File
# Begin Source File

SOURCE=.\ARMObject.cpp
# End Source File
# Begin Source File

SOURCE=.\ARMObjectList.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ARMObject.h
# End Source File
# Begin Source File

SOURCE=.\ARMObjectList.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\AP210Arm.rc2
# End Source File
# End Group
# Begin Group "ARM Source Files"

# PROP Default_Filter "*.cpp"
# Begin Source File

SOURCE=.\Src\add_design_object_management_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\adjacent_stratum_surface_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\advanced_b_rep.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\aggregate_connectivity_requirement.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\altered_package.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\altered_package_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\altered_packaged_part.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\alternate_product.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\alternate_select_product.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\analytical_model.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\analytical_model_port.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\analytical_model_port_assignment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\analytical_model_scalar_port.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\analytical_model_vector_port.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\analytical_model_vector_port_assignment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\analytical_representation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\angle_data_element.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\angular_dimension_with_direction_vector.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\angular_size_dimension.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\angularity_tolerance.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\apex.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\array_placement_group.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\assembled_with_bonding.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\assembled_with_fasteners.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\assembly_alternate_product.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\assembly_bond_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\assembly_component.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\assembly_component_2d_shape.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\assembly_component_3d_shape.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\assembly_composition_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\assembly_group_component.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\assembly_joint.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\assembly_material_composition_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\assembly_module.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\assembly_module_component.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\assembly_module_component_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\assembly_module_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\assembly_module_usage_view.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\assembly_module_usage_view_connector_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\assembly_requirement_allocation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\assembly_separation_requirement_allocation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\assembly_technology_specification.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\axis_placement.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\axis_placement_2d.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\axis_placement_3d.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\b_rep_2d.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\bare_die.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\bare_die_component.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\bare_die_component_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\bare_die_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\bevel_edge_feature_shape.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\blind_passage_template.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\blind_via.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\block.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\bond_assembly_position.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\bonded_conductive_base_blind_via.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\boolean_csg_result.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\bound_volume_shape.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\boundary_based_position_tolerance.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\boundary_size_characteristic.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\boundary_zone_definition_with_specified_size.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\bounding_curve.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\buried_via.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\bus_element_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\bus_structural_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\cartesian_coordinate_system.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\cartesian_point.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\cartesian_transformation_operator_2d.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\centre_axis.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\centre_of_symmetry.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\centre_plane.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\centre_point.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\certification.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\change_design_object_management_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\change_order.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\change_request.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\characteristic.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\circular_runout_tolerance.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\circularity_tolerance.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\closed_curve.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\common_datum.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_2d_edge_location.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_2d_location.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_3d_location.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_assembly_2d_position.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_assembly_3d_position.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_based_annotation_symbol_placement_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_based_annotation_text_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_external_reference.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_feature.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_feature_external_reference.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_feature_make_from_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_feature_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_feature_to_layout_feature_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_feature_to_physical_usage_view_assignment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_group_assignment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_interface_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_make_from_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_mounting_clearance_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_overlap_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_part_2d_geometric_representation_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_part_3d_geometric_representation_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_placement_restriction_assignment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_swap_specification.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_terminal_to_assembly_module_terminal_assignment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_terminal_to_interconnect_module_terminal_assignment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_terminal_to_pca_terminal_assignment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_termination_passage.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_termination_passage_and_contact_size_dependent_land.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_termination_passage_and_contact_size_dependent_non_functional_land.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_termination_passage_dependent_land.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_termination_passage_dependent_non_functional_land.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_termination_passage_interface_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_termination_passage_join_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_termination_passage_template.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_termination_passage_template_interface_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_termination_passage_template_join_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\component_termination_passage_template_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\composite_curve.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\composite_curve_segment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\composite_feature_locating_position_tolerance.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\composite_feature_relating_position_tolerance.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\composite_group_shape_element.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\composite_linear_profile_locating_tolerance.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\composite_linear_profile_refinement_tolerance.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\composite_shape_element.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\composite_signal_property.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\composite_signal_property_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\composite_surface_profile_locating_tolerance.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\composite_surface_profile_refinement_tolerance.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\composite_unit_shape_element.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\concentricity_and_coaxiality_tolerance.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\conductive_filled_area.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\conductive_interconnect_element.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\conductive_interconnect_element_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\conductive_interconnect_element_with_pre_defined_transitions.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\conductive_interconnect_element_with_user_defined_single_transition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\conductor.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\configuration_controlled_message.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\conical_tolerance_zone_boundary.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\conical_tolerance_zone_boundary_and_surface_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\conical_tolerance_zone_boundary_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\conical_tolerance_zone_boundary_diametrical_size_characteristic.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\conical_tolerance_zone_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\connected_filled_area.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\connection_zone.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\connection_zone_based_assembly_joint.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\connection_zone_interface_plane_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\connection_zone_model_port_assignment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\connectivity_allocation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\connectivity_sub_structure.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\consistent_part_template_shape_projection.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\consistent_physical_unit_shape_projection.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\consistent_stratum_shape_projection.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\constraint_occurrence.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\contact_size_dependent_land.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\contact_size_dependent_non_functional_land.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\contract.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\coordinated_characteristic.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\counterbore_passage_template.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\countersunk_passage_template.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\csg_primitive.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\csg_solid.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\curve.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\curve_dimension.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\curve_style.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\curve_style_font.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\curve_style_font_and_scaling.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\cutout.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\cutout_edge_segment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\cylindricity_tolerance.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\data_element.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\date.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\date_and_time.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\datum.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\datum_axis.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\datum_axis_and_tolerance_zone_orienting_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\datum_axis_related_orientation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\datum_based_direction_vector.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\datum_based_length_measure.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\datum_based_vector_orientation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\datum_difference.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\datum_difference_analytical_model_port_assignment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\datum_difference_based_characteristic.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\datum_difference_based_model_parameter.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\datum_difference_functional_unit_usage_view_terminal_assignment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\datum_feature.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\datum_feature_material_condition_property.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\datum_feature_usage_in_common_datum_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\datum_feature_usage_in_datum_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\datum_feature_usage_in_datum_system_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\datum_feature_usage_in_single_datum_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\datum_plane.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\datum_point.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\datum_precedence_assignment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\datum_reference_frame.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\datum_system.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\datum_system_defining_conditions.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\datum_system_defining_conditions_with_material_conditions.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\datum_system_defining_conditions_without_material_conditions.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\datum_target.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\datum_target_set.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\datum_target_usage_in_datum_target_set_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\datum_usage_in_datum_system_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\default_assembly_bond_shape.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\default_attachment_size_and_component_termination_passage_based_land_physical_template.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\default_attachment_size_and_via_based_land_physical_template.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\default_attachment_size_based_land_physical_template.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\default_component_termination_passage_based_land_physical_template.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\default_component_termination_passage_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\default_land_physical_template.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\default_passage_based_land_physical_template.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\default_trace_template.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\default_unsupported_passage_based_land_physical_template.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\default_unsupported_passage_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\default_via_based_land_physical_template.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\default_via_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\delete_design_object_management_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\dependently_located_layer_connection_point.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\derived_shape_element.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\design_characteristic_occurrence.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\design_composition_path.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\design_functional_unit_allocation_to_assembly_component.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\design_functional_unit_allocation_to_assembly_joint.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\design_functional_unit_allocation_to_fabrication_joint.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\design_functional_unit_allocation_to_reference_functional_unit.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\design_intent_modification.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\design_intent_modification_3d_shape.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\design_intent_modification_in_stratum_3d_position.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\design_intent_modification_in_stratum_planar_position.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\design_intent_modification_non_planar_2d_shape.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\design_intent_modification_planar_shape.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\design_intent_modification_sequence.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\design_intent_modification_styled_area_representation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\design_layer_stratum.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\design_layer_technology.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\design_object_management_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\design_requirement_occurrence.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\design_specification.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\device_2d_position.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\device_3d_position.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\device_terminal_map.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\device_terminal_map_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\diametrical_boundary_size_characteristic.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\dielectric_crossover_area.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\dielectric_material_passage.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\digital_analytical_model_port.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\dimension_along_curve.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\dimension_location_with_direction_vector.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\dimension_location_with_specified_datum_system.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\dimension_qualifier.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\dimension_related_positional_boundary.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\dimension_related_positional_boundary_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\dimension_set.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\dimensional_characteristic.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\dimensional_characteristic_representation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\dimensional_location.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\dimensional_size.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\dimensional_size_based_on_opposing_boundaries.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\directed_axis.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\direction_element.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\documentation_layer_stratum.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\documentation_layer_technology.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\edge_based_2d_wireframe.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\edge_based_wireframe.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\edge_segment_vertex.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\edge_shape.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\ee_approval.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\ee_colour.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\ee_document.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\ee_document_identifier.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\ee_material.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\ee_product.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\ee_product_category.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\ee_product_category_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\ee_product_configuration.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\ee_product_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\ee_product_model.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\ee_product_related_product_category.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\ee_product_specific_parameter_value_assignment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\ee_product_version.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\ee_requirement_occurrence.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\ee_rule.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\ee_rule_complex_clause.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\ee_rule_conclusion_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\ee_rule_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\ee_rule_function.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\ee_rule_premise_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\ee_rule_simple_clause.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\ee_rule_version.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\ee_specification.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\ee_text.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\electrical_isolation_removal_structure.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\electrical_network_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\electrical_requirement_occurrence.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\electromagnetic_compatibility_requirement_allocation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\electromagnetic_requirement_occurrence.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\engineering_make_from.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\equivalent_functional_terminals_assignment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\equivalent_functional_unit_definition_assignment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\evaluated_characteristic.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\explicitly_located_layer_connection_point.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\external_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\externally_defined_curve_font.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\externally_defined_dimension_representation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\externally_defined_ee_product_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\externally_defined_hatch_style.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\externally_defined_tile.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\externally_defined_tile_style.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\fabrication_joint.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\fabrication_technology_specification.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\feature_group_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\feature_shape_composition_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\feature_shape_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\feature_shape_occurrence.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\fiducial.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\fiducial_part_feature.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\fiducial_stratum_feature.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\fill_area.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\fill_area_occurrence.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\fill_area_style.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\fill_area_style_hatching.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\fill_area_style_tile.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\fill_area_style_tile_curve_with_style.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\fill_area_style_tile_solid_region.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\fill_area_style_tile_symbol_with_style.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\filled_area_material_removal_structure.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\flatness_tolerance.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\font_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\frozen_assignment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\frozen_design_object.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\functional_specification.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\functional_specification_to_requirement_occurrence_assignment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\functional_terminal_group.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\functional_terminal_group_assignment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\functional_unit.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\functional_unit_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\functional_unit_network_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\functional_unit_network_node_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\functional_unit_network_terminal_definition_bus_assignment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\functional_unit_network_terminal_definition_node_assignment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\functional_unit_requirement_allocation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\functional_unit_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\functional_unit_terminal_bus_assignment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\functional_unit_terminal_node_assignment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\functional_unit_usage_view.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\functional_unit_usage_view_terminal_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\functional_usage_view_to_part_terminal_assignment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\functional_usage_view_to_printed_part_template_terminal_assignment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\gate_path_swap_specification.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\geometric_alignment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\geometric_intersection.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\geometric_tolerance.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\geometric_tolerance_qualifier.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\geometric_tolerance_with_applied_material_condition_property.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\geometric_tolerance_with_referenced_datum_system.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\geometric_tolerance_without_referenced_datum_system.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\geometrically_bounded_2d_wireframe.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\geometrically_bounded_surface.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\guided_wave_bare_die_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\guided_wave_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\inter_stratum_extent.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\inter_stratum_feature.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\inter_stratum_feature_edge_segment_template.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\inter_stratum_feature_edge_template.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\inter_stratum_feature_template.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\inter_stratum_join_implementation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\inter_stratum_join_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\interconnect_component_interface_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\interconnect_component_join_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\interconnect_module.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\interconnect_module_component.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\interconnect_module_component_stratum_based_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\interconnect_module_component_surface_feature.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\interconnect_module_component_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\interconnect_module_constraint_region.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\interconnect_module_edge.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\interconnect_module_edge_segment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\interconnect_module_edge_segment_surface.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\interconnect_module_edge_surface.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\interconnect_module_primary_surface.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\interconnect_module_product_assembly_view_fabrication_joint.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\interconnect_module_secondary_surface.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\interconnect_module_stratum_assembly_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\interconnect_module_stratum_based_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\interconnect_module_surface_feature.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\interconnect_module_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\interconnect_module_usage_view.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\interface_component.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\interface_component_allocation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\interface_mounted_join.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\interface_requirement_occurrence.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\interface_specification.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\interfaced_group_component.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\interfacial_connection.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\internal_probe_access_area.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\internal_stratum_access.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\intra_stratum_join_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\item_restricted_requirement_occurrence.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\join_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\join_two_physical_connectivity_definition_supporting_printed_component.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\junction_vertex_allocation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\laminate_component.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\laminate_text_component.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\laminate_text_string_component.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\land.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\land_interface_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\land_join_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\land_physical_template.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\land_template_interface_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\land_template_join_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\land_template_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\language_reference_manual.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\layer.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\layer_connection_point.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\layer_connection_point_link.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\layer_qualified_layout_spacing_requirement_occurrence.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\layout_spacing_requirement_non_conforming_design_object.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\layout_spacing_requirement_occurrence.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\lead_form_specification.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\length_data_element.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\length_trimmed_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\library_ee_product_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\library_item.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\library_model.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\limit_dimension_representation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\line_width_class.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\linear_extension.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\ListOfanalytical_model_scalar_port.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\ListOfbus_structural_definition_or_node.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\ListOfcomposite_curve_segment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\ListOfdate_and_time.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\ListOfphysical_connectivity_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\ListOfplain_or_structured_text.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\ListOfprinted_part_template_material.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\ListOfscalar_terminal_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\located_interconnect_module_thickness_requirement.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\managed_design_object.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\marking.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\material_addition_feature.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\material_addition_feature_template.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\material_assembly_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\material_composition_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\material_electrical_conductivity_requirement_occurrence.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\material_removal_feature.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\material_removal_feature_template.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\material_shape_modification.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\material_specification.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\mating_connector_component.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\mating_connector_placement_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\mating_connector_termination.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\maximum_dimension_representation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\maximum_tolerance_characteristic.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\minimally_defined_bare_die_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\minimally_defined_component_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\minimum_dimension_representation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\minimum_tolerance_characteristic.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\model_parameter.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\mounting_restriction_area.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\next_higher_assembly_interface_requirement.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\next_higher_assembly_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\non_conductive_base_blind_via.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\non_feature_shape_element.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\non_functional_land.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\non_functional_land_interface_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\non_functional_land_join_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\numeric_parameter.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\open_shell_based_surface.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\operational_requirement_occurrence_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\opposing_boundary_set_size_characteristic.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\organization.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\orientation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\package.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\package_body.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\package_body_bottom_surface.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\package_body_surface.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\package_body_top_surface.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\package_external_reference.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\package_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\package_terminal_external_reference.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\package_terminal_occurrence.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\packaged_component.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\packaged_component_join_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\packaged_connector.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\packaged_connector_component.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\packaged_connector_component_interface_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\packaged_connector_terminal_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\packaged_part.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\packaged_part_interface_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\packaged_part_join_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\packaged_part_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\parallel_shape_element_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\parallelism_tolerance.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\parameter_assignment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\part_array_feature.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\part_based_constraint_occurrence.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\part_connected_terminals_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\part_device.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\part_device_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\part_device_terminal_model_port_assignment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\part_feature.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\part_feature_model_port_assignment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\part_group_feature.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\part_mounting_feature.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\part_template.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\part_template_3d_shape.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\part_template_non_planar_2d_shape.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\part_template_planar_shape.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\part_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\part_terminal_external_reference.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\part_text_template.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\part_tooling_feature.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\partially_plated_cutout.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\partially_plated_interconnect_module_edge.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\participant_date_and_time_assignment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\passage_technology.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\pca.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\pca_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\pca_usage_view.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\pcb.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\pcb_usage_view.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\perpendicular_shape_element_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\perpendicularity_tolerance.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\person.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\person_and_organization.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\physical_component_feature.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\physical_connectivity_abstraction_map.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\physical_connectivity_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\physical_connectivity_definition_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\physical_connectivity_element.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\physical_connectivity_interrupting_cutout.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\physical_connectivity_make_from_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\physical_connectivity_structure_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\physical_feature_or_part_template.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\physical_laminate_component.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\physical_network.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\physical_network_supporting_inter_stratum_feature.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\physical_network_supporting_stratum_feature_conductive_join.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\physical_node_requirement_to_implementing_component_allocation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\physical_unit.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\physical_unit_3d_shape.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\physical_unit_design_view.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\physical_unit_planar_shape.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\physical_unit_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\physical_unit_usage_view.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\placement_group.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\placement_group_area_assignment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\planar_projected_shape.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\planar_shape.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\planned_characteristic.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\planned_date_effectivity.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\planned_effectivity.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\planned_lot_effectivity.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\planned_serial_number_effectivity.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\plated_conductive_base_blind_via.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\plated_cutout.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\plated_cutout_edge_segment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\plated_inter_stratum_feature.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\plated_interconnect_module_edge.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\plated_interconnect_module_edge_segment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\plated_passage.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\plus_minus_tolerance_characteristic.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\plus_minus_tolerance_range_representation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\polarity_indication_feature.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\position_tolerance.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\position_tolerance_with_referenced_datum_system.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\position_tolerance_without_referenced_datum_system.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\positional_boundary.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\positional_boundary_and_profile_boundary_member_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\positional_boundary_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\positional_boundary_member.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\positional_boundary_member_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\positional_boundary_offset.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\positive_ratio_measure.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\pre_defined_dimension_qualifier.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\pre_defined_geometric_tolerance_qualifier.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\primary_orientation_feature.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\primary_reference_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\primary_stratum_indicator_symbol.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\printed_component.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\printed_component_join_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\printed_connector_component.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\printed_connector_component_interface_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\printed_connector_template.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\printed_connector_template_terminal_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\printed_part_cross_section_template.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\printed_part_cross_section_template_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\printed_part_template.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\printed_part_template_connected_terminals_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\printed_part_template_interface_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\printed_part_template_join_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\printed_part_template_material.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\printed_part_template_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\printed_part_template_terminal_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\probe_access_area.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\process_specification.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\product_association.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\profile_boundary_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\profile_boundary_definition_with_offsets.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\profile_of_any_line_tolerance.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\profile_of_any_line_tolerance_with_referenced_datum_system.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\profile_of_any_line_tolerance_without_referenced_datum_system.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\profile_of_any_surface_tolerance.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\profile_of_any_surface_tolerance_with_referenced_datum_system.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\profile_of_any_surface_tolerance_without_referenced_datum_system.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\profile_related_positional_boundary.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\profile_related_positional_boundary_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\projected_tolerance_zone_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\projected_zone_and_base_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\projected_zone_height_characteristic.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\promissory_usage_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\purpose_occurrence.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\qualified_data_element.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\radius_edge_feature_shape.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\reference_composition_path.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\reference_functional_unit_assignment_to_part.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\registered_font.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\registered_style.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\representation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\requirement_allocation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\requirement_composition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\requirement_group_occurrence.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\restraint_condition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\right_angular_wedge.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\right_circular_cylinder.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\routed_interconnect_component.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\routed_packaged_component.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\routed_printed_component.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\rule_action.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\rule_adoption.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\rule_change_request.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\rule_creation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\rule_expiration.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\rule_justification.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\rule_modification.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\rule_priority.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\rule_rejection.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\rule_request.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\rule_set.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\rule_set_group.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\rule_submission.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\rule_supersedence.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\runout_tolerance_zone_definition_with_specified_angle.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\runout_tolerance_zone_orienting_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\runout_zone_orientation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\scalar_terminal_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\seating_plane.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\secondary_orientation_feature.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\security_classification.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\separate_geometric_tolerance_requirement.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfanalytical_representation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfassembled_feature_select.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfassembly_component.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfassembly_joint.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfassembly_module.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfassembly_or_interconnect_design_object_select.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfcharacteristic.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfcomponent_or_feature.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfcomponent_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfconductive_interconnect_element.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfconical_tolerance_zone_boundary_diametrical_size_characteristic.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfconnection_zone.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfcoordinated_characteristic.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfcorrelated_or_independent.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfcurve.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfcurve_style.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfdatum_axis.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfdatum_feature_material_condition_property.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfdatum_plane.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfdatum_precedence_assignment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfdesign_intent_modification_planar_shape.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfdesign_object_management_relationship_or_description.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfdimensional_characteristic.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfdirection_element.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfee_document.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfee_material.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfee_product.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfee_product_version.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfee_requirement_occurrence.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfee_rule_complex_clause.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfee_rule_simple_clause.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfee_specification.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfee_text.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfexternal_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOffabricated_feature_select.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOffeature_shape_occurrence.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOffill_area_style.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOffrozen_design_object.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOffunctional_unit.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOffunctional_unit_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOffunctional_unit_usage_view_terminal_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfgeometric_or_dimension_select.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfgeometric_tolerance.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfgeometric_tolerance_with_referenced_datum_system.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfinter_stratum_extent.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfinterconnect_module.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfinterconnect_module_component_stratum_based_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfinterconnect_module_design_object_select.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfinterface_component.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfinterface_mounted_join.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfjoin_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOflayer_connection_point.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOflayer_connection_point_link.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOflength_data_element.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfmating_connector_termination.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfmodel_parameter.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfpackage_body_surface.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfparameter_assignment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfpart_feature.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfpart_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfperson.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfperson_organization.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfpositional_boundary_member.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfpositional_boundary_member_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfprinted_part_template_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfproduct_object_select.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfregistered_style.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfrule_priority.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfrule_set.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfshieldable_item.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfstratum_feature.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfstratum_feature_planar_shape.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfstructured_text.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOftermination_or_junction.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOftolerance_zone_boundary_member.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOftolerance_zone_boundary_member_offset.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfvector.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\SetOfwork_request.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\shape_dimension_representation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\shape_element.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\shape_element_boundary_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\shape_element_composing_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\shape_element_constituent_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\shape_element_deriving_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\shape_element_locating_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\shape_element_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\shape_formed_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\shell_based_2d_wireframe.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\shell_based_wireframe.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\shield.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\shield_allocation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\signal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\signal_property.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\signal_specification.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\simultaneous_geometric_tolerance_requirement.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\single_boundary_dimension.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\single_datum.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\singular_dimension_representation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\solid_curve.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\solid_fill_style.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\solid_of_linear_extrusion.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\special_symbol_laminate_component.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\special_symbol_part_template.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\specification_allocation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\start_order.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\start_request.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\statistical_dimensional_tolerance.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\statistical_geometric_tolerance.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\statistical_tolerance_characteristic.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\step_edge_feature_shape.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\straightness_tolerance.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\stratum.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\stratum_3d_shape.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\stratum_average_surface.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\stratum_average_surface_shape.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\stratum_concept_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\stratum_concept_to_physical_usage_view_assignment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\stratum_feature.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\stratum_feature_3d_shape.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\stratum_feature_conductive_join.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\stratum_feature_in_stratum_3d_position.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\stratum_feature_in_stratum_planar_position.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\stratum_feature_non_planar_2d_shape.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\stratum_feature_planar_shape.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\stratum_feature_shape_stratum_average_surface_shape_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\stratum_feature_shape_stratum_surface_shape_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\stratum_feature_styled_area_representation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\stratum_feature_template.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\stratum_feature_template_component.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\stratum_interconnect_module_3d_position.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\stratum_interconnect_module_planar_position.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\stratum_make_from_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\stratum_planar_shape.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\stratum_surface.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\stratum_surface_in_stratum_3d_position.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\stratum_surface_shape.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\stratum_technology.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\stratum_technology_line_width_tolerance_assignment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\structured_text.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\styled_curve_occurrence.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\styled_text.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\sub_assembly_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\substitute_product.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\supplied_product_version.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\surface_finish_specification.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\surface_prepped_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\symmetrical_tolerance_characteristic.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\symmetry_tolerance.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\tangent_plane.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\tangent_shape_element.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\technology.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\terminal_pair_port_equivalence_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\terminal_swap_specification.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\termination_constraint.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\test_select_product.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\test_specification.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\theoretically_exact_dimension_representation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\thermal_component.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\thermal_feature.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\thermal_isolation_removal_structure.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\thermal_isolation_requirement_assignment.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\thermal_network_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\thermal_requirement_allocation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\thermal_requirement_occurrence.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\tolerance_characteristic.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\tolerance_specific_restraint_condition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\tolerance_zone.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\tolerance_zone_and_viewing_plane_orienting_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\tolerance_zone_boundary.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\tolerance_zone_boundary_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\tolerance_zone_boundary_member.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\tolerance_zone_boundary_member_offset.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\tolerance_zone_circular_or_cylindrical_or_spherical_boundary.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\tolerance_zone_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\tolerance_zone_definition_with_per_unit_size_specification.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\tolerance_zone_definition_with_specified_orientation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\tolerance_zone_explicit_opposing_boundary_set.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\tolerance_zone_form.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\tolerance_zone_implicit_opposing_boundary_set.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\tolerance_zone_opposing_boundary_set.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\tolerance_zone_per_unit_size_specification.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\topological_junction.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\total_runout_tolerance.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\trace_template.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\transmission_line_functional_unit_terminal_allocation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\transmission_line_functional_unit_to_routed_printed_component_allocation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\trimmed_line.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\true_profile.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\unsupported_passage.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\unsupported_passage_dependent_non_functional_land.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\unsupported_passage_template.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\usage_concept_usage_relationship.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\user_defined_dimension_qualifier.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\user_defined_geometric_tolerance_qualifier.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\vector.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\via.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\via_and_contact_size_dependent_land.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\via_and_contact_size_dependent_non_functional_land.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\via_dependent_land.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\via_dependent_non_functional_land.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\via_template.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\via_template_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\via_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\viewing_plane.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\viewing_plane_based_orientation.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\viewing_plane_definition.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\volume_shape_projection.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\wire_terminal.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\work_order.cpp
# End Source File
# Begin Source File

SOURCE=.\Src\work_request.cpp
# End Source File
# End Group
# Begin Group "ARM Include Files"

# PROP Default_Filter "*.h"
# Begin Source File

SOURCE=.\Include\add_design_object_management_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\adjacent_stratum_surface_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\advanced_b_rep.h
# End Source File
# Begin Source File

SOURCE=.\Include\aggregate_connectivity_requirement.h
# End Source File
# Begin Source File

SOURCE=.\Include\altered_package.h
# End Source File
# Begin Source File

SOURCE=.\Include\altered_package_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\altered_packaged_part.h
# End Source File
# Begin Source File

SOURCE=.\Include\alternate_product.h
# End Source File
# Begin Source File

SOURCE=.\Include\alternate_select_product.h
# End Source File
# Begin Source File

SOURCE=.\Include\analytical_model.h
# End Source File
# Begin Source File

SOURCE=.\Include\analytical_model_port.h
# End Source File
# Begin Source File

SOURCE=.\Include\analytical_model_port_assignment.h
# End Source File
# Begin Source File

SOURCE=.\Include\analytical_model_port_assignment_select.h
# End Source File
# Begin Source File

SOURCE=.\Include\analytical_model_scalar_port.h
# End Source File
# Begin Source File

SOURCE=.\Include\analytical_model_vector_port.h
# End Source File
# Begin Source File

SOURCE=.\Include\analytical_model_vector_port_assignment.h
# End Source File
# Begin Source File

SOURCE=.\Include\analytical_representation.h
# End Source File
# Begin Source File

SOURCE=.\Include\angle_data_element.h
# End Source File
# Begin Source File

SOURCE=.\Include\angular_dimension_with_direction_vector.h
# End Source File
# Begin Source File

SOURCE=.\Include\angular_size_dimension.h
# End Source File
# Begin Source File

SOURCE=.\Include\angularity_tolerance.h
# End Source File
# Begin Source File

SOURCE=.\Include\ap210is.h
# End Source File
# Begin Source File

SOURCE=.\Include\apex.h
# End Source File
# Begin Source File

SOURCE=.\Include\array_placement_group.h
# End Source File
# Begin Source File

SOURCE=.\Include\assembled_feature_select.h
# End Source File
# Begin Source File

SOURCE=.\Include\assembled_with_bonding.h
# End Source File
# Begin Source File

SOURCE=.\Include\assembled_with_fasteners.h
# End Source File
# Begin Source File

SOURCE=.\Include\assembly_alternate_product.h
# End Source File
# Begin Source File

SOURCE=.\Include\assembly_bond_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\assembly_component.h
# End Source File
# Begin Source File

SOURCE=.\Include\assembly_component_2d_shape.h
# End Source File
# Begin Source File

SOURCE=.\Include\assembly_component_3d_shape.h
# End Source File
# Begin Source File

SOURCE=.\Include\assembly_composition_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\assembly_group_component.h
# End Source File
# Begin Source File

SOURCE=.\Include\assembly_joint.h
# End Source File
# Begin Source File

SOURCE=.\Include\assembly_material_composition_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\assembly_module.h
# End Source File
# Begin Source File

SOURCE=.\Include\assembly_module_component.h
# End Source File
# Begin Source File

SOURCE=.\Include\assembly_module_component_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\assembly_module_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\assembly_module_usage_view.h
# End Source File
# Begin Source File

SOURCE=.\Include\assembly_module_usage_view_connector_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\assembly_or_interconnect_design_object_select.h
# End Source File
# Begin Source File

SOURCE=.\Include\assembly_requirement_allocation.h
# End Source File
# Begin Source File

SOURCE=.\Include\assembly_separation_requirement_allocation.h
# End Source File
# Begin Source File

SOURCE=.\Include\assembly_technology_specification.h
# End Source File
# Begin Source File

SOURCE=.\Include\axis_placement.h
# End Source File
# Begin Source File

SOURCE=.\Include\axis_placement_2d.h
# End Source File
# Begin Source File

SOURCE=.\Include\axis_placement_3d.h
# End Source File
# Begin Source File

SOURCE=.\Include\axis_placement_or_datum_based_vector_orientation_select.h
# End Source File
# Begin Source File

SOURCE=.\Include\b_rep_2d.h
# End Source File
# Begin Source File

SOURCE=.\Include\bare_die.h
# End Source File
# Begin Source File

SOURCE=.\Include\bare_die_component.h
# End Source File
# Begin Source File

SOURCE=.\Include\bare_die_component_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\bare_die_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\bevel_edge_feature_shape.h
# End Source File
# Begin Source File

SOURCE=.\Include\blind_passage_template.h
# End Source File
# Begin Source File

SOURCE=.\Include\blind_via.h
# End Source File
# Begin Source File

SOURCE=.\Include\block.h
# End Source File
# Begin Source File

SOURCE=.\Include\bond_assembly_position.h
# End Source File
# Begin Source File

SOURCE=.\Include\bonded_conductive_base_blind_via.h
# End Source File
# Begin Source File

SOURCE=.\Include\boolean_csg_operand.h
# End Source File
# Begin Source File

SOURCE=.\Include\boolean_csg_result.h
# End Source File
# Begin Source File

SOURCE=.\Include\boolean_operator.h
# End Source File
# Begin Source File

SOURCE=.\Include\bound_volume_shape.h
# End Source File
# Begin Source File

SOURCE=.\Include\boundary_based_position_tolerance.h
# End Source File
# Begin Source File

SOURCE=.\Include\boundary_size_characteristic.h
# End Source File
# Begin Source File

SOURCE=.\Include\boundary_zone_definition_with_specified_size.h
# End Source File
# Begin Source File

SOURCE=.\Include\bounding_curve.h
# End Source File
# Begin Source File

SOURCE=.\Include\buried_via.h
# End Source File
# Begin Source File

SOURCE=.\Include\bus_element_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\bus_structural_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\bus_structural_definition_or_node.h
# End Source File
# Begin Source File

SOURCE=.\Include\cartesian_coordinate_system.h
# End Source File
# Begin Source File

SOURCE=.\Include\cartesian_point.h
# End Source File
# Begin Source File

SOURCE=.\Include\cartesian_transformation_operator_2d.h
# End Source File
# Begin Source File

SOURCE=.\Include\centre_axis.h
# End Source File
# Begin Source File

SOURCE=.\Include\centre_of_symmetry.h
# End Source File
# Begin Source File

SOURCE=.\Include\centre_plane.h
# End Source File
# Begin Source File

SOURCE=.\Include\centre_point.h
# End Source File
# Begin Source File

SOURCE=.\Include\centre_type.h
# End Source File
# Begin Source File

SOURCE=.\Include\certification.h
# End Source File
# Begin Source File

SOURCE=.\Include\change_design_object_management_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\change_order.h
# End Source File
# Begin Source File

SOURCE=.\Include\change_request.h
# End Source File
# Begin Source File

SOURCE=.\Include\characteristic.h
# End Source File
# Begin Source File

SOURCE=.\Include\circular_runout_tolerance.h
# End Source File
# Begin Source File

SOURCE=.\Include\circularity_tolerance.h
# End Source File
# Begin Source File

SOURCE=.\Include\closed_curve.h
# End Source File
# Begin Source File

SOURCE=.\Include\common_datum.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_2d_edge_location.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_2d_location.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_3d_location.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_assembly_2d_position.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_assembly_3d_position.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_based_annotation_symbol_placement_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_based_annotation_text_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_based_message_type.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_external_reference.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_feature.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_feature_external_reference.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_feature_make_from_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_feature_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_feature_to_layout_feature_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_feature_to_physical_usage_view_assignment.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_group_assignment.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_interface_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_make_from_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_mounting_clearance_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_or_component_feature.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_or_feature.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_overlap_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_part_2d_geometric_representation_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_part_3d_geometric_representation_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_placement_restriction_assignment.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_swap_specification.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_terminal_to_assembly_module_terminal_assignment.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_terminal_to_interconnect_module_terminal_assignment.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_terminal_to_pca_terminal_assignment.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_termination_passage.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_termination_passage_and_contact_size_dependent_land.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_termination_passage_and_contact_size_dependent_non_functional_land.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_termination_passage_dependent_land.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_termination_passage_dependent_non_functional_land.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_termination_passage_interface_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_termination_passage_join_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_termination_passage_template.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_termination_passage_template_interface_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_termination_passage_template_join_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\component_termination_passage_template_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\composite_curve.h
# End Source File
# Begin Source File

SOURCE=.\Include\composite_curve_segment.h
# End Source File
# Begin Source File

SOURCE=.\Include\composite_feature_locating_position_tolerance.h
# End Source File
# Begin Source File

SOURCE=.\Include\composite_feature_relating_position_tolerance.h
# End Source File
# Begin Source File

SOURCE=.\Include\composite_group_shape_element.h
# End Source File
# Begin Source File

SOURCE=.\Include\composite_linear_profile_locating_tolerance.h
# End Source File
# Begin Source File

SOURCE=.\Include\composite_linear_profile_refinement_tolerance.h
# End Source File
# Begin Source File

SOURCE=.\Include\composite_shape_element.h
# End Source File
# Begin Source File

SOURCE=.\Include\composite_signal_property.h
# End Source File
# Begin Source File

SOURCE=.\Include\composite_signal_property_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\composite_surface_profile_locating_tolerance.h
# End Source File
# Begin Source File

SOURCE=.\Include\composite_surface_profile_refinement_tolerance.h
# End Source File
# Begin Source File

SOURCE=.\Include\composite_unit_shape_element.h
# End Source File
# Begin Source File

SOURCE=.\Include\concentricity_and_coaxiality_tolerance.h
# End Source File
# Begin Source File

SOURCE=.\Include\conductive_filled_area.h
# End Source File
# Begin Source File

SOURCE=.\Include\conductive_interconnect_element.h
# End Source File
# Begin Source File

SOURCE=.\Include\conductive_interconnect_element_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\conductive_interconnect_element_with_pre_defined_transitions.h
# End Source File
# Begin Source File

SOURCE=.\Include\conductive_interconnect_element_with_user_defined_single_transition.h
# End Source File
# Begin Source File

SOURCE=.\Include\conductor.h
# End Source File
# Begin Source File

SOURCE=.\Include\configuration_controlled_message.h
# End Source File
# Begin Source File

SOURCE=.\Include\conical_tolerance_zone_boundary.h
# End Source File
# Begin Source File

SOURCE=.\Include\conical_tolerance_zone_boundary_and_surface_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\conical_tolerance_zone_boundary_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\conical_tolerance_zone_boundary_diametrical_size_characteristic.h
# End Source File
# Begin Source File

SOURCE=.\Include\conical_tolerance_zone_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\connected_filled_area.h
# End Source File
# Begin Source File

SOURCE=.\Include\connection_zone.h
# End Source File
# Begin Source File

SOURCE=.\Include\connection_zone_based_assembly_joint.h
# End Source File
# Begin Source File

SOURCE=.\Include\connection_zone_interface_plane_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\connection_zone_model_port_assignment.h
# End Source File
# Begin Source File

SOURCE=.\Include\connectivity_allocation.h
# End Source File
# Begin Source File

SOURCE=.\Include\connectivity_component.h
# End Source File
# Begin Source File

SOURCE=.\Include\connectivity_sub_structure.h
# End Source File
# Begin Source File

SOURCE=.\Include\consistent_part_template_shape_projection.h
# End Source File
# Begin Source File

SOURCE=.\Include\consistent_physical_unit_shape_projection.h
# End Source File
# Begin Source File

SOURCE=.\Include\consistent_stratum_shape_projection.h
# End Source File
# Begin Source File

SOURCE=.\Include\constraining_element_definitions.h
# End Source File
# Begin Source File

SOURCE=.\Include\constraint_occurrence.h
# End Source File
# Begin Source File

SOURCE=.\Include\contact_size_dependent_land.h
# End Source File
# Begin Source File

SOURCE=.\Include\contact_size_dependent_non_functional_land.h
# End Source File
# Begin Source File

SOURCE=.\Include\contract.h
# End Source File
# Begin Source File

SOURCE=.\Include\coordinated_characteristic.h
# End Source File
# Begin Source File

SOURCE=.\Include\correlated_or_independent.h
# End Source File
# Begin Source File

SOURCE=.\Include\counterbore_passage_template.h
# End Source File
# Begin Source File

SOURCE=.\Include\countersunk_passage_template.h
# End Source File
# Begin Source File

SOURCE=.\Include\csg_primitive.h
# End Source File
# Begin Source File

SOURCE=.\Include\csg_solid.h
# End Source File
# Begin Source File

SOURCE=.\Include\curve.h
# End Source File
# Begin Source File

SOURCE=.\Include\curve_dimension.h
# End Source File
# Begin Source File

SOURCE=.\Include\curve_font_or_scaled_curve_font_select.h
# End Source File
# Begin Source File

SOURCE=.\Include\curve_style.h
# End Source File
# Begin Source File

SOURCE=.\Include\curve_style_font.h
# End Source File
# Begin Source File

SOURCE=.\Include\curve_style_font_and_scaling.h
# End Source File
# Begin Source File

SOURCE=.\Include\curve_style_font_select.h
# End Source File
# Begin Source File

SOURCE=.\Include\cutout.h
# End Source File
# Begin Source File

SOURCE=.\Include\cutout_edge_segment.h
# End Source File
# Begin Source File

SOURCE=.\Include\cylindricity_tolerance.h
# End Source File
# Begin Source File

SOURCE=.\Include\data_element.h
# End Source File
# Begin Source File

SOURCE=.\Include\date.h
# End Source File
# Begin Source File

SOURCE=.\Include\date_and_time.h
# End Source File
# Begin Source File

SOURCE=.\Include\date_or_date_and_time.h
# End Source File
# Begin Source File

SOURCE=.\Include\datum.h
# End Source File
# Begin Source File

SOURCE=.\Include\datum_axis.h
# End Source File
# Begin Source File

SOURCE=.\Include\datum_axis_and_tolerance_zone_orienting_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\datum_axis_related_orientation.h
# End Source File
# Begin Source File

SOURCE=.\Include\datum_based_direction_vector.h
# End Source File
# Begin Source File

SOURCE=.\Include\datum_based_length_measure.h
# End Source File
# Begin Source File

SOURCE=.\Include\datum_based_vector_orientation.h
# End Source File
# Begin Source File

SOURCE=.\Include\datum_difference.h
# End Source File
# Begin Source File

SOURCE=.\Include\datum_difference_analytical_model_port_assignment.h
# End Source File
# Begin Source File

SOURCE=.\Include\datum_difference_based_characteristic.h
# End Source File
# Begin Source File

SOURCE=.\Include\datum_difference_based_model_parameter.h
# End Source File
# Begin Source File

SOURCE=.\Include\datum_difference_functional_unit_usage_view_terminal_assignment.h
# End Source File
# Begin Source File

SOURCE=.\Include\datum_feature.h
# End Source File
# Begin Source File

SOURCE=.\Include\datum_feature_material_condition_property.h
# End Source File
# Begin Source File

SOURCE=.\Include\datum_feature_usage_in_common_datum_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\datum_feature_usage_in_datum_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\datum_feature_usage_in_datum_system_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\datum_feature_usage_in_single_datum_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\datum_plane.h
# End Source File
# Begin Source File

SOURCE=.\Include\datum_point.h
# End Source File
# Begin Source File

SOURCE=.\Include\datum_precedence_assignment.h
# End Source File
# Begin Source File

SOURCE=.\Include\datum_reference_frame.h
# End Source File
# Begin Source File

SOURCE=.\Include\datum_system.h
# End Source File
# Begin Source File

SOURCE=.\Include\datum_system_defining_conditions.h
# End Source File
# Begin Source File

SOURCE=.\Include\datum_system_defining_conditions_with_material_conditions.h
# End Source File
# Begin Source File

SOURCE=.\Include\datum_system_defining_conditions_without_material_conditions.h
# End Source File
# Begin Source File

SOURCE=.\Include\datum_target.h
# End Source File
# Begin Source File

SOURCE=.\Include\datum_target_set.h
# End Source File
# Begin Source File

SOURCE=.\Include\datum_target_usage_in_datum_target_set_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\datum_usage_in_datum_system_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\default_assembly_bond_shape.h
# End Source File
# Begin Source File

SOURCE=.\Include\default_attachment_size_and_component_termination_passage_based_land_physical_template.h
# End Source File
# Begin Source File

SOURCE=.\Include\default_attachment_size_and_via_based_land_physical_template.h
# End Source File
# Begin Source File

SOURCE=.\Include\default_attachment_size_based_land_physical_template.h
# End Source File
# Begin Source File

SOURCE=.\Include\default_component_termination_passage_based_land_physical_template.h
# End Source File
# Begin Source File

SOURCE=.\Include\default_component_termination_passage_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\default_land_physical_template.h
# End Source File
# Begin Source File

SOURCE=.\Include\default_passage_based_land_physical_template.h
# End Source File
# Begin Source File

SOURCE=.\Include\default_trace_template.h
# End Source File
# Begin Source File

SOURCE=.\Include\default_unsupported_passage_based_land_physical_template.h
# End Source File
# Begin Source File

SOURCE=.\Include\default_unsupported_passage_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\default_via_based_land_physical_template.h
# End Source File
# Begin Source File

SOURCE=.\Include\default_via_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\degree_or_radian.h
# End Source File
# Begin Source File

SOURCE=.\Include\delete_design_object_management_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\dependently_located_layer_connection_point.h
# End Source File
# Begin Source File

SOURCE=.\Include\derived_shape_element.h
# End Source File
# Begin Source File

SOURCE=.\Include\descriptive_or_geometric_orientation.h
# End Source File
# Begin Source File

SOURCE=.\Include\design_characteristic_occurrence.h
# End Source File
# Begin Source File

SOURCE=.\Include\design_composition_path.h
# End Source File
# Begin Source File

SOURCE=.\Include\design_functional_unit_allocation_to_assembly_component.h
# End Source File
# Begin Source File

SOURCE=.\Include\design_functional_unit_allocation_to_assembly_joint.h
# End Source File
# Begin Source File

SOURCE=.\Include\design_functional_unit_allocation_to_fabrication_joint.h
# End Source File
# Begin Source File

SOURCE=.\Include\design_functional_unit_allocation_to_reference_functional_unit.h
# End Source File
# Begin Source File

SOURCE=.\Include\design_intent_modification.h
# End Source File
# Begin Source File

SOURCE=.\Include\design_intent_modification_3d_shape.h
# End Source File
# Begin Source File

SOURCE=.\Include\design_intent_modification_3d_shape_select.h
# End Source File
# Begin Source File

SOURCE=.\Include\design_intent_modification_in_stratum_3d_position.h
# End Source File
# Begin Source File

SOURCE=.\Include\design_intent_modification_in_stratum_planar_position.h
# End Source File
# Begin Source File

SOURCE=.\Include\design_intent_modification_non_planar_2d_shape.h
# End Source File
# Begin Source File

SOURCE=.\Include\design_intent_modification_planar_shape.h
# End Source File
# Begin Source File

SOURCE=.\Include\design_intent_modification_planar_shape_select.h
# End Source File
# Begin Source File

SOURCE=.\Include\design_intent_modification_sequence.h
# End Source File
# Begin Source File

SOURCE=.\Include\design_intent_modification_styled_area_representation.h
# End Source File
# Begin Source File

SOURCE=.\Include\design_layer_stratum.h
# End Source File
# Begin Source File

SOURCE=.\Include\design_layer_technology.h
# End Source File
# Begin Source File

SOURCE=.\Include\design_object_management_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\design_object_management_relationship_or_description.h
# End Source File
# Begin Source File

SOURCE=.\Include\design_requirement_occurrence.h
# End Source File
# Begin Source File

SOURCE=.\Include\design_specification.h
# End Source File
# Begin Source File

SOURCE=.\Include\device_2d_position.h
# End Source File
# Begin Source File

SOURCE=.\Include\device_3d_position.h
# End Source File
# Begin Source File

SOURCE=.\Include\device_terminal_map.h
# End Source File
# Begin Source File

SOURCE=.\Include\device_terminal_map_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\diametrical_boundary_size_characteristic.h
# End Source File
# Begin Source File

SOURCE=.\Include\dielectric_crossover_area.h
# End Source File
# Begin Source File

SOURCE=.\Include\dielectric_material_passage.h
# End Source File
# Begin Source File

SOURCE=.\Include\digital_analytical_model_port.h
# End Source File
# Begin Source File

SOURCE=.\Include\digital_signal_flow_direction.h
# End Source File
# Begin Source File

SOURCE=.\Include\dimension_along_curve.h
# End Source File
# Begin Source File

SOURCE=.\Include\dimension_location_with_direction_vector.h
# End Source File
# Begin Source File

SOURCE=.\Include\dimension_location_with_specified_datum_system.h
# End Source File
# Begin Source File

SOURCE=.\Include\dimension_qualifier.h
# End Source File
# Begin Source File

SOURCE=.\Include\dimension_qualifiers.h
# End Source File
# Begin Source File

SOURCE=.\Include\dimension_related_positional_boundary.h
# End Source File
# Begin Source File

SOURCE=.\Include\dimension_related_positional_boundary_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\dimension_set.h
# End Source File
# Begin Source File

SOURCE=.\Include\dimensional_characteristic.h
# End Source File
# Begin Source File

SOURCE=.\Include\dimensional_characteristic_representation.h
# End Source File
# Begin Source File

SOURCE=.\Include\dimensional_location.h
# End Source File
# Begin Source File

SOURCE=.\Include\dimensional_location_or_dimensional_size.h
# End Source File
# Begin Source File

SOURCE=.\Include\dimensional_size.h
# End Source File
# Begin Source File

SOURCE=.\Include\dimensional_size_based_on_opposing_boundaries.h
# End Source File
# Begin Source File

SOURCE=.\Include\dimensional_types.h
# End Source File
# Begin Source File

SOURCE=.\Include\directed_axis.h
# End Source File
# Begin Source File

SOURCE=.\Include\direction_element.h
# End Source File
# Begin Source File

SOURCE=.\Include\document_or_organization.h
# End Source File
# Begin Source File

SOURCE=.\Include\documentation_layer_stratum.h
# End Source File
# Begin Source File

SOURCE=.\Include\documentation_layer_technology.h
# End Source File
# Begin Source File

SOURCE=.\Include\edge_based_2d_wireframe.h
# End Source File
# Begin Source File

SOURCE=.\Include\edge_based_wireframe.h
# End Source File
# Begin Source File

SOURCE=.\Include\edge_segment_vertex.h
# End Source File
# Begin Source File

SOURCE=.\Include\edge_shape.h
# End Source File
# Begin Source File

SOURCE=.\Include\ee_approval.h
# End Source File
# Begin Source File

SOURCE=.\Include\ee_colour.h
# End Source File
# Begin Source File

SOURCE=.\Include\ee_document.h
# End Source File
# Begin Source File

SOURCE=.\Include\ee_document_identifier.h
# End Source File
# Begin Source File

SOURCE=.\Include\ee_material.h
# End Source File
# Begin Source File

SOURCE=.\Include\ee_product.h
# End Source File
# Begin Source File

SOURCE=.\Include\ee_product_category.h
# End Source File
# Begin Source File

SOURCE=.\Include\ee_product_category_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\ee_product_configuration.h
# End Source File
# Begin Source File

SOURCE=.\Include\ee_product_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\ee_product_model.h
# End Source File
# Begin Source File

SOURCE=.\Include\ee_product_related_product_category.h
# End Source File
# Begin Source File

SOURCE=.\Include\ee_product_specific_parameter_value_assignment.h
# End Source File
# Begin Source File

SOURCE=.\Include\ee_product_version.h
# End Source File
# Begin Source File

SOURCE=.\Include\ee_requirement_occurrence.h
# End Source File
# Begin Source File

SOURCE=.\Include\ee_rule.h
# End Source File
# Begin Source File

SOURCE=.\Include\ee_rule_complex_clause.h
# End Source File
# Begin Source File

SOURCE=.\Include\ee_rule_conclusion_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\ee_rule_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\ee_rule_function.h
# End Source File
# Begin Source File

SOURCE=.\Include\ee_rule_premise_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\ee_rule_simple_clause.h
# End Source File
# Begin Source File

SOURCE=.\Include\ee_rule_version.h
# End Source File
# Begin Source File

SOURCE=.\Include\ee_specification.h
# End Source File
# Begin Source File

SOURCE=.\Include\ee_text.h
# End Source File
# Begin Source File

SOURCE=.\Include\electrical_isolation_removal_structure.h
# End Source File
# Begin Source File

SOURCE=.\Include\electrical_network_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\electrical_requirement_occurrence.h
# End Source File
# Begin Source File

SOURCE=.\Include\electromagnetic_compatibility_requirement_allocation.h
# End Source File
# Begin Source File

SOURCE=.\Include\electromagnetic_requirement_occurrence.h
# End Source File
# Begin Source File

SOURCE=.\Include\engineering_make_from.h
# End Source File
# Begin Source File

SOURCE=.\Include\environment.h
# End Source File
# Begin Source File

SOURCE=.\Include\equivalent_functional_terminals_assignment.h
# End Source File
# Begin Source File

SOURCE=.\Include\equivalent_functional_unit_definition_assignment.h
# End Source File
# Begin Source File

SOURCE=.\Include\evaluated_characteristic.h
# End Source File
# Begin Source File

SOURCE=.\Include\evaluated_characteristic_or_description.h
# End Source File
# Begin Source File

SOURCE=.\Include\evaluation_type.h
# End Source File
# Begin Source File

SOURCE=.\Include\explicitly_located_layer_connection_point.h
# End Source File
# Begin Source File

SOURCE=.\Include\extend_or_chord_2_extend_or_truncate_or_round.h
# End Source File
# Begin Source File

SOURCE=.\Include\extend_or_truncate.h
# End Source File
# Begin Source File

SOURCE=.\Include\external_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\externally_defined_curve_font.h
# End Source File
# Begin Source File

SOURCE=.\Include\externally_defined_dimension_representation.h
# End Source File
# Begin Source File

SOURCE=.\Include\externally_defined_ee_product_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\externally_defined_hatch_style.h
# End Source File
# Begin Source File

SOURCE=.\Include\externally_defined_tile.h
# End Source File
# Begin Source File

SOURCE=.\Include\externally_defined_tile_style.h
# End Source File
# Begin Source File

SOURCE=.\Include\fabricated_feature_select.h
# End Source File
# Begin Source File

SOURCE=.\Include\fabrication_joint.h
# End Source File
# Begin Source File

SOURCE=.\Include\fabrication_technology_specification.h
# End Source File
# Begin Source File

SOURCE=.\Include\feature_group_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\feature_shape_composition_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\feature_shape_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\feature_shape_occurrence.h
# End Source File
# Begin Source File

SOURCE=.\Include\fiducial.h
# End Source File
# Begin Source File

SOURCE=.\Include\fiducial_part_feature.h
# End Source File
# Begin Source File

SOURCE=.\Include\fiducial_stratum_feature.h
# End Source File
# Begin Source File

SOURCE=.\Include\fill_area.h
# End Source File
# Begin Source File

SOURCE=.\Include\fill_area_occurrence.h
# End Source File
# Begin Source File

SOURCE=.\Include\fill_area_style.h
# End Source File
# Begin Source File

SOURCE=.\Include\fill_area_style_hatching.h
# End Source File
# Begin Source File

SOURCE=.\Include\fill_area_style_tile.h
# End Source File
# Begin Source File

SOURCE=.\Include\fill_area_style_tile_curve_with_style.h
# End Source File
# Begin Source File

SOURCE=.\Include\fill_area_style_tile_shape_select.h
# End Source File
# Begin Source File

SOURCE=.\Include\fill_area_style_tile_solid_region.h
# End Source File
# Begin Source File

SOURCE=.\Include\fill_area_style_tile_symbol_with_style.h
# End Source File
# Begin Source File

SOURCE=.\Include\fill_style_select.h
# End Source File
# Begin Source File

SOURCE=.\Include\filled_area_material_removal_structure.h
# End Source File
# Begin Source File

SOURCE=.\Include\flatness_tolerance.h
# End Source File
# Begin Source File

SOURCE=.\Include\font_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\font_select.h
# End Source File
# Begin Source File

SOURCE=.\Include\frozen_assignment.h
# End Source File
# Begin Source File

SOURCE=.\Include\frozen_design_object.h
# End Source File
# Begin Source File

SOURCE=.\Include\functional_specification.h
# End Source File
# Begin Source File

SOURCE=.\Include\functional_specification_to_requirement_occurrence_assignment.h
# End Source File
# Begin Source File

SOURCE=.\Include\functional_terminal_group.h
# End Source File
# Begin Source File

SOURCE=.\Include\functional_terminal_group_assignment.h
# End Source File
# Begin Source File

SOURCE=.\Include\functional_unit.h
# End Source File
# Begin Source File

SOURCE=.\Include\functional_unit_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\functional_unit_network_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\functional_unit_network_node_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\functional_unit_network_terminal_definition_bus_assignment.h
# End Source File
# Begin Source File

SOURCE=.\Include\functional_unit_network_terminal_definition_node_assignment.h
# End Source File
# Begin Source File

SOURCE=.\Include\functional_unit_requirement_allocation.h
# End Source File
# Begin Source File

SOURCE=.\Include\functional_unit_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\functional_unit_terminal_bus_assignment.h
# End Source File
# Begin Source File

SOURCE=.\Include\functional_unit_terminal_node_assignment.h
# End Source File
# Begin Source File

SOURCE=.\Include\functional_unit_usage_view.h
# End Source File
# Begin Source File

SOURCE=.\Include\functional_unit_usage_view_terminal_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\functional_usage_view_to_part_terminal_assignment.h
# End Source File
# Begin Source File

SOURCE=.\Include\functional_usage_view_to_printed_part_template_terminal_assignment.h
# End Source File
# Begin Source File

SOURCE=.\Include\gate_path_swap_specification.h
# End Source File
# Begin Source File

SOURCE=.\Include\geometric_alignment.h
# End Source File
# Begin Source File

SOURCE=.\Include\geometric_intersection.h
# End Source File
# Begin Source File

SOURCE=.\Include\geometric_or_dimension_select.h
# End Source File
# Begin Source File

SOURCE=.\Include\geometric_tolerance.h
# End Source File
# Begin Source File

SOURCE=.\Include\geometric_tolerance_qualifier.h
# End Source File
# Begin Source File

SOURCE=.\Include\geometric_tolerance_qualifiers.h
# End Source File
# Begin Source File

SOURCE=.\Include\geometric_tolerance_with_applied_material_condition_property.h
# End Source File
# Begin Source File

SOURCE=.\Include\geometric_tolerance_with_referenced_datum_system.h
# End Source File
# Begin Source File

SOURCE=.\Include\geometric_tolerance_without_referenced_datum_system.h
# End Source File
# Begin Source File

SOURCE=.\Include\geometrically_bounded_2d_wireframe.h
# End Source File
# Begin Source File

SOURCE=.\Include\geometrically_bounded_surface.h
# End Source File
# Begin Source File

SOURCE=.\Include\guided_wave_bare_die_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\guided_wave_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\horizontal_justification.h
# End Source File
# Begin Source File

SOURCE=.\Include\inter_stratum_extent.h
# End Source File
# Begin Source File

SOURCE=.\Include\inter_stratum_feature.h
# End Source File
# Begin Source File

SOURCE=.\Include\inter_stratum_feature_edge_segment_template.h
# End Source File
# Begin Source File

SOURCE=.\Include\inter_stratum_feature_edge_template.h
# End Source File
# Begin Source File

SOURCE=.\Include\inter_stratum_feature_template.h
# End Source File
# Begin Source File

SOURCE=.\Include\inter_stratum_join_implementation.h
# End Source File
# Begin Source File

SOURCE=.\Include\inter_stratum_join_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\interconnect_component_interface_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\interconnect_component_join_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\interconnect_module.h
# End Source File
# Begin Source File

SOURCE=.\Include\interconnect_module_component.h
# End Source File
# Begin Source File

SOURCE=.\Include\interconnect_module_component_stratum_based_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\interconnect_module_component_surface_feature.h
# End Source File
# Begin Source File

SOURCE=.\Include\interconnect_module_component_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\interconnect_module_constraint_region.h
# End Source File
# Begin Source File

SOURCE=.\Include\interconnect_module_design_object_category.h
# End Source File
# Begin Source File

SOURCE=.\Include\interconnect_module_design_object_select.h
# End Source File
# Begin Source File

SOURCE=.\Include\interconnect_module_edge.h
# End Source File
# Begin Source File

SOURCE=.\Include\interconnect_module_edge_segment.h
# End Source File
# Begin Source File

SOURCE=.\Include\interconnect_module_edge_segment_surface.h
# End Source File
# Begin Source File

SOURCE=.\Include\interconnect_module_edge_surface.h
# End Source File
# Begin Source File

SOURCE=.\Include\interconnect_module_primary_surface.h
# End Source File
# Begin Source File

SOURCE=.\Include\interconnect_module_product_assembly_view_fabrication_joint.h
# End Source File
# Begin Source File

SOURCE=.\Include\interconnect_module_secondary_surface.h
# End Source File
# Begin Source File

SOURCE=.\Include\interconnect_module_stratum_assembly_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\interconnect_module_stratum_based_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\interconnect_module_surface_feature.h
# End Source File
# Begin Source File

SOURCE=.\Include\interconnect_module_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\interconnect_module_terminal_or_inter_stratum_feature.h
# End Source File
# Begin Source File

SOURCE=.\Include\interconnect_module_usage_view.h
# End Source File
# Begin Source File

SOURCE=.\Include\interconnect_or_assembly_module_select.h
# End Source File
# Begin Source File

SOURCE=.\Include\interface_component.h
# End Source File
# Begin Source File

SOURCE=.\Include\interface_component_allocation.h
# End Source File
# Begin Source File

SOURCE=.\Include\interface_mounted_join.h
# End Source File
# Begin Source File

SOURCE=.\Include\interface_requirement_occurrence.h
# End Source File
# Begin Source File

SOURCE=.\Include\interface_specification.h
# End Source File
# Begin Source File

SOURCE=.\Include\interfaced_group_component.h
# End Source File
# Begin Source File

SOURCE=.\Include\interfacial_connection.h
# End Source File
# Begin Source File

SOURCE=.\Include\internal_probe_access_area.h
# End Source File
# Begin Source File

SOURCE=.\Include\internal_stratum_access.h
# End Source File
# Begin Source File

SOURCE=.\Include\intra_stratum_join_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\item_restricted_requirement_occurrence.h
# End Source File
# Begin Source File

SOURCE=.\Include\join_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\join_two_physical_connectivity_definition_supporting_printed_component.h
# End Source File
# Begin Source File

SOURCE=.\Include\junction_vertex_allocation.h
# End Source File
# Begin Source File

SOURCE=.\Include\laminate_component.h
# End Source File
# Begin Source File

SOURCE=.\Include\laminate_text_component.h
# End Source File
# Begin Source File

SOURCE=.\Include\laminate_text_string_component.h
# End Source File
# Begin Source File

SOURCE=.\Include\land.h
# End Source File
# Begin Source File

SOURCE=.\Include\land_interface_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\land_join_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\land_physical_template.h
# End Source File
# Begin Source File

SOURCE=.\Include\land_template_interface_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\land_template_join_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\land_template_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\land_template_terminal_class.h
# End Source File
# Begin Source File

SOURCE=.\Include\language_reference_manual.h
# End Source File
# Begin Source File

SOURCE=.\Include\layer.h
# End Source File
# Begin Source File

SOURCE=.\Include\layer_connection_point.h
# End Source File
# Begin Source File

SOURCE=.\Include\layer_connection_point_link.h
# End Source File
# Begin Source File

SOURCE=.\Include\layer_position.h
# End Source File
# Begin Source File

SOURCE=.\Include\layer_purpose.h
# End Source File
# Begin Source File

SOURCE=.\Include\layer_qualified_layout_spacing_requirement_occurrence.h
# End Source File
# Begin Source File

SOURCE=.\Include\layout_spacing_requirement_non_conforming_design_object.h
# End Source File
# Begin Source File

SOURCE=.\Include\layout_spacing_requirement_occurrence.h
# End Source File
# Begin Source File

SOURCE=.\Include\lead_form_specification.h
# End Source File
# Begin Source File

SOURCE=.\Include\length_data_element.h
# End Source File
# Begin Source File

SOURCE=.\Include\length_trimmed_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\library_ee_product_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\library_item.h
# End Source File
# Begin Source File

SOURCE=.\Include\library_model.h
# End Source File
# Begin Source File

SOURCE=.\Include\life_cycle_stage.h
# End Source File
# Begin Source File

SOURCE=.\Include\limit_dimension_representation.h
# End Source File
# Begin Source File

SOURCE=.\Include\line_width_class.h
# End Source File
# Begin Source File

SOURCE=.\Include\linear_extension.h
# End Source File
# Begin Source File

SOURCE=.\Include\ListOfanalytical_model_scalar_port.h
# End Source File
# Begin Source File

SOURCE=.\Include\ListOfbus_structural_definition_or_node.h
# End Source File
# Begin Source File

SOURCE=.\Include\ListOfcomposite_curve_segment.h
# End Source File
# Begin Source File

SOURCE=.\Include\ListOfdate_and_time.h
# End Source File
# Begin Source File

SOURCE=.\Include\ListOfphysical_connectivity_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\ListOfplain_or_structured_text.h
# End Source File
# Begin Source File

SOURCE=.\Include\ListOfprinted_part_template_material.h
# End Source File
# Begin Source File

SOURCE=.\Include\ListOfscalar_terminal_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\located_interconnect_module_thickness_requirement.h
# End Source File
# Begin Source File

SOURCE=.\Include\locating_or_refinement_linear_profile_tolerance.h
# End Source File
# Begin Source File

SOURCE=.\Include\locating_or_refinement_surface_profile_tolerance.h
# End Source File
# Begin Source File

SOURCE=.\Include\locating_or_relating_position_tolerance.h
# End Source File
# Begin Source File

SOURCE=.\Include\managed_design_object.h
# End Source File
# Begin Source File

SOURCE=.\Include\markable_item.h
# End Source File
# Begin Source File

SOURCE=.\Include\marked_message_select.h
# End Source File
# Begin Source File

SOURCE=.\Include\marking.h
# End Source File
# Begin Source File

SOURCE=.\Include\material_addition_feature.h
# End Source File
# Begin Source File

SOURCE=.\Include\material_addition_feature_template.h
# End Source File
# Begin Source File

SOURCE=.\Include\material_assembly_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\material_composition_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\material_condition.h
# End Source File
# Begin Source File

SOURCE=.\Include\material_condition_property_names.h
# End Source File
# Begin Source File

SOURCE=.\Include\material_conductivity_classification.h
# End Source File
# Begin Source File

SOURCE=.\Include\material_electrical_conductivity_requirement_occurrence.h
# End Source File
# Begin Source File

SOURCE=.\Include\material_or_specification.h
# End Source File
# Begin Source File

SOURCE=.\Include\material_removal_feature.h
# End Source File
# Begin Source File

SOURCE=.\Include\material_removal_feature_template.h
# End Source File
# Begin Source File

SOURCE=.\Include\material_shape_modification.h
# End Source File
# Begin Source File

SOURCE=.\Include\material_specification.h
# End Source File
# Begin Source File

SOURCE=.\Include\mating_connector_component.h
# End Source File
# Begin Source File

SOURCE=.\Include\mating_connector_part.h
# End Source File
# Begin Source File

SOURCE=.\Include\mating_connector_placement_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\mating_connector_termination.h
# End Source File
# Begin Source File

SOURCE=.\Include\maximum_dimension_representation.h
# End Source File
# Begin Source File

SOURCE=.\Include\maximum_tolerance_characteristic.h
# End Source File
# Begin Source File

SOURCE=.\Include\measure_orientation.h
# End Source File
# Begin Source File

SOURCE=.\Include\message_source_select.h
# End Source File
# Begin Source File

SOURCE=.\Include\message_type.h
# End Source File
# Begin Source File

SOURCE=.\Include\minimally_defined_bare_die_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\minimally_defined_component_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\minimum_dimension_representation.h
# End Source File
# Begin Source File

SOURCE=.\Include\minimum_tolerance_characteristic.h
# End Source File
# Begin Source File

SOURCE=.\Include\model_parameter.h
# End Source File
# Begin Source File

SOURCE=.\Include\model_parameter_type.h
# End Source File
# Begin Source File

SOURCE=.\Include\mounting_restriction_area.h
# End Source File
# Begin Source File

SOURCE=.\Include\next_higher_assembly_interface_requirement.h
# End Source File
# Begin Source File

SOURCE=.\Include\next_higher_assembly_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\non_conductive_base_blind_via.h
# End Source File
# Begin Source File

SOURCE=.\Include\non_feature_shape_element.h
# End Source File
# Begin Source File

SOURCE=.\Include\non_functional_land.h
# End Source File
# Begin Source File

SOURCE=.\Include\non_functional_land_interface_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\non_functional_land_join_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\non_numeric_property_type.h
# End Source File
# Begin Source File

SOURCE=.\Include\numeric_or_non_numeric_select.h
# End Source File
# Begin Source File

SOURCE=.\Include\numeric_parameter.h
# End Source File
# Begin Source File

SOURCE=.\Include\offset_types.h
# End Source File
# Begin Source File

SOURCE=.\Include\open_shell_based_surface.h
# End Source File
# Begin Source File

SOURCE=.\Include\operational_requirement_occurrence_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\opposing_boundary_set_size_characteristic.h
# End Source File
# Begin Source File

SOURCE=.\Include\organization.h
# End Source File
# Begin Source File

SOURCE=.\Include\orientation.h
# End Source File
# Begin Source File

SOURCE=.\Include\orientation_select.h
# End Source File
# Begin Source File

SOURCE=.\Include\package.h
# End Source File
# Begin Source File

SOURCE=.\Include\package_body.h
# End Source File
# Begin Source File

SOURCE=.\Include\package_body_bottom_surface.h
# End Source File
# Begin Source File

SOURCE=.\Include\package_body_surface.h
# End Source File
# Begin Source File

SOURCE=.\Include\package_body_top_surface.h
# End Source File
# Begin Source File

SOURCE=.\Include\package_external_reference.h
# End Source File
# Begin Source File

SOURCE=.\Include\package_or_package_external_reference.h
# End Source File
# Begin Source File

SOURCE=.\Include\package_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\package_terminal_external_reference.h
# End Source File
# Begin Source File

SOURCE=.\Include\package_terminal_occurrence.h
# End Source File
# Begin Source File

SOURCE=.\Include\package_terminal_or_package_terminal_external_reference.h
# End Source File
# Begin Source File

SOURCE=.\Include\packaged_component.h
# End Source File
# Begin Source File

SOURCE=.\Include\packaged_component_join_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\packaged_connector.h
# End Source File
# Begin Source File

SOURCE=.\Include\packaged_connector_component.h
# End Source File
# Begin Source File

SOURCE=.\Include\packaged_connector_component_interface_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\packaged_connector_terminal_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\packaged_or_printed_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\packaged_part.h
# End Source File
# Begin Source File

SOURCE=.\Include\packaged_part_interface_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\packaged_part_join_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\packaged_part_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\parallel_shape_element_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\parallelism_tolerance.h
# End Source File
# Begin Source File

SOURCE=.\Include\parameter_assignment.h
# End Source File
# Begin Source File

SOURCE=.\Include\part_array_feature.h
# End Source File
# Begin Source File

SOURCE=.\Include\part_based_constraint_occurrence.h
# End Source File
# Begin Source File

SOURCE=.\Include\part_connected_terminals_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\part_device.h
# End Source File
# Begin Source File

SOURCE=.\Include\part_device_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\part_device_terminal_model_port_assignment.h
# End Source File
# Begin Source File

SOURCE=.\Include\part_feature.h
# End Source File
# Begin Source File

SOURCE=.\Include\part_feature_model_port_assignment.h
# End Source File
# Begin Source File

SOURCE=.\Include\part_feature_or_template_feature.h
# End Source File
# Begin Source File

SOURCE=.\Include\part_group_feature.h
# End Source File
# Begin Source File

SOURCE=.\Include\part_mounting_feature.h
# End Source File
# Begin Source File

SOURCE=.\Include\part_template.h
# End Source File
# Begin Source File

SOURCE=.\Include\part_template_3d_shape.h
# End Source File
# Begin Source File

SOURCE=.\Include\part_template_non_planar_2d_shape.h
# End Source File
# Begin Source File

SOURCE=.\Include\part_template_or_physical_unit_2d_shape_select.h
# End Source File
# Begin Source File

SOURCE=.\Include\part_template_or_physical_unit_3d_shape_select.h
# End Source File
# Begin Source File

SOURCE=.\Include\part_template_planar_shape.h
# End Source File
# Begin Source File

SOURCE=.\Include\part_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\part_terminal_external_reference.h
# End Source File
# Begin Source File

SOURCE=.\Include\part_text_template.h
# End Source File
# Begin Source File

SOURCE=.\Include\part_tooling_feature.h
# End Source File
# Begin Source File

SOURCE=.\Include\partially_plated_cutout.h
# End Source File
# Begin Source File

SOURCE=.\Include\partially_plated_interconnect_module_edge.h
# End Source File
# Begin Source File

SOURCE=.\Include\participant_date_and_time_assignment.h
# End Source File
# Begin Source File

SOURCE=.\Include\passage_technology.h
# End Source File
# Begin Source File

SOURCE=.\Include\pca.h
# End Source File
# Begin Source File

SOURCE=.\Include\pca_interface_select.h
# End Source File
# Begin Source File

SOURCE=.\Include\pca_product_design_object_category.h
# End Source File
# Begin Source File

SOURCE=.\Include\pca_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\pca_usage_view.h
# End Source File
# Begin Source File

SOURCE=.\Include\pcb.h
# End Source File
# Begin Source File

SOURCE=.\Include\pcb_usage_view.h
# End Source File
# Begin Source File

SOURCE=.\Include\perpendicular_shape_element_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\perpendicularity_tolerance.h
# End Source File
# Begin Source File

SOURCE=.\Include\person.h
# End Source File
# Begin Source File

SOURCE=.\Include\person_and_organization.h
# End Source File
# Begin Source File

SOURCE=.\Include\person_organization.h
# End Source File
# Begin Source File

SOURCE=.\Include\physical_component_feature.h
# End Source File
# Begin Source File

SOURCE=.\Include\physical_connectivity_abstraction_map.h
# End Source File
# Begin Source File

SOURCE=.\Include\physical_connectivity_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\physical_connectivity_definition_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\physical_connectivity_element.h
# End Source File
# Begin Source File

SOURCE=.\Include\physical_connectivity_interrupting_cutout.h
# End Source File
# Begin Source File

SOURCE=.\Include\physical_connectivity_make_from_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\physical_connectivity_structure_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\physical_feature_or_part_template.h
# End Source File
# Begin Source File

SOURCE=.\Include\physical_laminate_component.h
# End Source File
# Begin Source File

SOURCE=.\Include\physical_network.h
# End Source File
# Begin Source File

SOURCE=.\Include\physical_network_supporting_inter_stratum_feature.h
# End Source File
# Begin Source File

SOURCE=.\Include\physical_network_supporting_stratum_feature_conductive_join.h
# End Source File
# Begin Source File

SOURCE=.\Include\physical_node_requirement_to_implementing_component_allocation.h
# End Source File
# Begin Source File

SOURCE=.\Include\physical_unit.h
# End Source File
# Begin Source File

SOURCE=.\Include\physical_unit_3d_shape.h
# End Source File
# Begin Source File

SOURCE=.\Include\physical_unit_design_view.h
# End Source File
# Begin Source File

SOURCE=.\Include\physical_unit_or_part_template.h
# End Source File
# Begin Source File

SOURCE=.\Include\physical_unit_planar_shape.h
# End Source File
# Begin Source File

SOURCE=.\Include\physical_unit_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\physical_unit_usage_view.h
# End Source File
# Begin Source File

SOURCE=.\Include\placement_group.h
# End Source File
# Begin Source File

SOURCE=.\Include\placement_group_area_assignment.h
# End Source File
# Begin Source File

SOURCE=.\Include\plain_or_structured_text.h
# End Source File
# Begin Source File

SOURCE=.\Include\planar_projected_shape.h
# End Source File
# Begin Source File

SOURCE=.\Include\planar_shape.h
# End Source File
# Begin Source File

SOURCE=.\Include\planned_characteristic.h
# End Source File
# Begin Source File

SOURCE=.\Include\planned_date_effectivity.h
# End Source File
# Begin Source File

SOURCE=.\Include\planned_effectivity.h
# End Source File
# Begin Source File

SOURCE=.\Include\planned_lot_effectivity.h
# End Source File
# Begin Source File

SOURCE=.\Include\planned_serial_number_effectivity.h
# End Source File
# Begin Source File

SOURCE=.\Include\plated_conductive_base_blind_via.h
# End Source File
# Begin Source File

SOURCE=.\Include\plated_cutout.h
# End Source File
# Begin Source File

SOURCE=.\Include\plated_cutout_edge_segment.h
# End Source File
# Begin Source File

SOURCE=.\Include\plated_inter_stratum_feature.h
# End Source File
# Begin Source File

SOURCE=.\Include\plated_interconnect_module_edge.h
# End Source File
# Begin Source File

SOURCE=.\Include\plated_interconnect_module_edge_segment.h
# End Source File
# Begin Source File

SOURCE=.\Include\plated_passage.h
# End Source File
# Begin Source File

SOURCE=.\Include\plus_minus_tolerance_characteristic.h
# End Source File
# Begin Source File

SOURCE=.\Include\plus_minus_tolerance_range_representation.h
# End Source File
# Begin Source File

SOURCE=.\Include\polarity_indication_feature.h
# End Source File
# Begin Source File

SOURCE=.\Include\position_tolerance.h
# End Source File
# Begin Source File

SOURCE=.\Include\position_tolerance_with_referenced_datum_system.h
# End Source File
# Begin Source File

SOURCE=.\Include\position_tolerance_without_referenced_datum_system.h
# End Source File
# Begin Source File

SOURCE=.\Include\positional_boundary.h
# End Source File
# Begin Source File

SOURCE=.\Include\positional_boundary_and_profile_boundary_member_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\positional_boundary_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\positional_boundary_member.h
# End Source File
# Begin Source File

SOURCE=.\Include\positional_boundary_member_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\positional_boundary_offset.h
# End Source File
# Begin Source File

SOURCE=.\Include\positive_ratio_measure.h
# End Source File
# Begin Source File

SOURCE=.\Include\pre_defined_dimension_qualifier.h
# End Source File
# Begin Source File

SOURCE=.\Include\pre_defined_geometric_tolerance_qualifier.h
# End Source File
# Begin Source File

SOURCE=.\Include\precedence_type.h
# End Source File
# Begin Source File

SOURCE=.\Include\primary_orientation_feature.h
# End Source File
# Begin Source File

SOURCE=.\Include\primary_reference_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\primary_stratum_indicator_symbol.h
# End Source File
# Begin Source File

SOURCE=.\Include\printed_component.h
# End Source File
# Begin Source File

SOURCE=.\Include\printed_component_join_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\printed_connector_component.h
# End Source File
# Begin Source File

SOURCE=.\Include\printed_connector_component_interface_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\printed_connector_template.h
# End Source File
# Begin Source File

SOURCE=.\Include\printed_connector_template_terminal_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\printed_part_cross_section_template.h
# End Source File
# Begin Source File

SOURCE=.\Include\printed_part_cross_section_template_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\printed_part_template.h
# End Source File
# Begin Source File

SOURCE=.\Include\printed_part_template_connected_terminals_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\printed_part_template_interface_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\printed_part_template_join_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\printed_part_template_material.h
# End Source File
# Begin Source File

SOURCE=.\Include\printed_part_template_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\printed_part_template_terminal_class.h
# End Source File
# Begin Source File

SOURCE=.\Include\printed_part_template_terminal_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\probe_access_area.h
# End Source File
# Begin Source File

SOURCE=.\Include\process_specification.h
# End Source File
# Begin Source File

SOURCE=.\Include\product_association.h
# End Source File
# Begin Source File

SOURCE=.\Include\product_object_select.h
# End Source File
# Begin Source File

SOURCE=.\Include\profile_boundary_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\profile_boundary_definition_with_offsets.h
# End Source File
# Begin Source File

SOURCE=.\Include\profile_of_any_line_tolerance.h
# End Source File
# Begin Source File

SOURCE=.\Include\profile_of_any_line_tolerance_with_referenced_datum_system.h
# End Source File
# Begin Source File

SOURCE=.\Include\profile_of_any_line_tolerance_without_referenced_datum_system.h
# End Source File
# Begin Source File

SOURCE=.\Include\profile_of_any_surface_tolerance.h
# End Source File
# Begin Source File

SOURCE=.\Include\profile_of_any_surface_tolerance_with_referenced_datum_system.h
# End Source File
# Begin Source File

SOURCE=.\Include\profile_of_any_surface_tolerance_without_referenced_datum_system.h
# End Source File
# Begin Source File

SOURCE=.\Include\profile_related_positional_boundary.h
# End Source File
# Begin Source File

SOURCE=.\Include\profile_related_positional_boundary_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\projected_tolerance_zone_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\projected_zone_and_base_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\projected_zone_height_characteristic.h
# End Source File
# Begin Source File

SOURCE=.\Include\promissory_usage_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\purpose.h
# End Source File
# Begin Source File

SOURCE=.\Include\purpose_occurrence.h
# End Source File
# Begin Source File

SOURCE=.\Include\qualified_data_element.h
# End Source File
# Begin Source File

SOURCE=.\Include\radius_edge_feature_shape.h
# End Source File
# Begin Source File

SOURCE=.\Include\reference_composition_path.h
# End Source File
# Begin Source File

SOURCE=.\Include\reference_functional_unit_assignment_to_part.h
# End Source File
# Begin Source File

SOURCE=.\Include\registered_font.h
# End Source File
# Begin Source File

SOURCE=.\Include\registered_style.h
# End Source File
# Begin Source File

SOURCE=.\Include\relationship_operation.h
# End Source File
# Begin Source File

SOURCE=.\Include\representation.h
# End Source File
# Begin Source File

SOURCE=.\Include\requirement_allocation.h
# End Source File
# Begin Source File

SOURCE=.\Include\requirement_allocation_select.h
# End Source File
# Begin Source File

SOURCE=.\Include\requirement_composition.h
# End Source File
# Begin Source File

SOURCE=.\Include\requirement_group_occurrence.h
# End Source File
# Begin Source File

SOURCE=.\Include\restrained_item_select.h
# End Source File
# Begin Source File

SOURCE=.\Include\restraint_condition.h
# End Source File
# Begin Source File

SOURCE=.\Include\restriction_basis_item.h
# End Source File
# Begin Source File

SOURCE=.\Include\right_angular_wedge.h
# End Source File
# Begin Source File

SOURCE=.\Include\right_circular_cylinder.h
# End Source File
# Begin Source File

SOURCE=.\Include\routed_interconnect_component.h
# End Source File
# Begin Source File

SOURCE=.\Include\routed_packaged_component.h
# End Source File
# Begin Source File

SOURCE=.\Include\routed_printed_component.h
# End Source File
# Begin Source File

SOURCE=.\Include\rule_action.h
# End Source File
# Begin Source File

SOURCE=.\Include\rule_adoption.h
# End Source File
# Begin Source File

SOURCE=.\Include\rule_change_request.h
# End Source File
# Begin Source File

SOURCE=.\Include\rule_creation.h
# End Source File
# Begin Source File

SOURCE=.\Include\rule_expiration.h
# End Source File
# Begin Source File

SOURCE=.\Include\rule_justification.h
# End Source File
# Begin Source File

SOURCE=.\Include\rule_modification.h
# End Source File
# Begin Source File

SOURCE=.\Include\rule_priority.h
# End Source File
# Begin Source File

SOURCE=.\Include\rule_rejection.h
# End Source File
# Begin Source File

SOURCE=.\Include\rule_request.h
# End Source File
# Begin Source File

SOURCE=.\Include\rule_set.h
# End Source File
# Begin Source File

SOURCE=.\Include\rule_set_group.h
# End Source File
# Begin Source File

SOURCE=.\Include\rule_submission.h
# End Source File
# Begin Source File

SOURCE=.\Include\rule_supersedence.h
# End Source File
# Begin Source File

SOURCE=.\Include\runout_tolerance_zone_definition_with_specified_angle.h
# End Source File
# Begin Source File

SOURCE=.\Include\runout_tolerance_zone_orienting_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\runout_zone_orientation.h
# End Source File
# Begin Source File

SOURCE=.\Include\scalar_or_coordinated_characteristics.h
# End Source File
# Begin Source File

SOURCE=.\Include\scalar_terminal_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\seating_plane.h
# End Source File
# Begin Source File

SOURCE=.\Include\secondary_orientation_feature.h
# End Source File
# Begin Source File

SOURCE=.\Include\security_classification.h
# End Source File
# Begin Source File

SOURCE=.\Include\separate_geometric_tolerance_requirement.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfanalytical_representation.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfassembled_feature_select.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfassembly_component.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfassembly_joint.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfassembly_module.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfassembly_or_interconnect_design_object_select.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfcharacteristic.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfcomponent_or_feature.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfcomponent_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfconductive_interconnect_element.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfconical_tolerance_zone_boundary_diametrical_size_characteristic.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfconnection_zone.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfcoordinated_characteristic.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfcorrelated_or_independent.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfcurve.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfcurve_style.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfdatum_axis.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfdatum_feature_material_condition_property.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfdatum_plane.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfdatum_precedence_assignment.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfdesign_intent_modification_planar_shape.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfdesign_object_management_relationship_or_description.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfdimensional_characteristic.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfdirection_element.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfee_document.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfee_material.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfee_product.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfee_product_version.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfee_requirement_occurrence.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfee_rule_complex_clause.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfee_rule_simple_clause.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfee_specification.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfee_text.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfexternal_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOffabricated_feature_select.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOffeature_shape_occurrence.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOffill_area_style.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOffrozen_design_object.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOffunctional_unit.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOffunctional_unit_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOffunctional_unit_usage_view_terminal_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfgeometric_or_dimension_select.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfgeometric_tolerance.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfgeometric_tolerance_with_referenced_datum_system.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfinter_stratum_extent.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfinterconnect_module.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfinterconnect_module_component_stratum_based_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfinterconnect_module_design_object_select.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfinterface_component.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfinterface_mounted_join.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfjoin_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOflayer_connection_point.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOflayer_connection_point_link.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOflength_data_element.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfmating_connector_termination.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfmodel_parameter.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfpackage_body_surface.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfparameter_assignment.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfpart_feature.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfpart_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfperson.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfperson_organization.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfpositional_boundary_member.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfpositional_boundary_member_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfprinted_part_template_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfproduct_object_select.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfregistered_style.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfrule_priority.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfrule_set.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfshieldable_item.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfstratum_feature.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfstratum_feature_planar_shape.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfstructured_text.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOftermination_or_junction.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOftolerance_zone_boundary_member.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOftolerance_zone_boundary_member_offset.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfvector.h
# End Source File
# Begin Source File

SOURCE=.\Include\SetOfwork_request.h
# End Source File
# Begin Source File

SOURCE=.\Include\shape_dimension_representation.h
# End Source File
# Begin Source File

SOURCE=.\Include\shape_element.h
# End Source File
# Begin Source File

SOURCE=.\Include\shape_element_boundary_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\shape_element_composing_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\shape_element_constituent_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\shape_element_deriving_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\shape_element_locating_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\shape_element_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\shape_formed_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\shell_based_2d_wireframe.h
# End Source File
# Begin Source File

SOURCE=.\Include\shell_based_wireframe.h
# End Source File
# Begin Source File

SOURCE=.\Include\shield.h
# End Source File
# Begin Source File

SOURCE=.\Include\shield_allocation.h
# End Source File
# Begin Source File

SOURCE=.\Include\shieldable_item.h
# End Source File
# Begin Source File

SOURCE=.\Include\signal.h
# End Source File
# Begin Source File

SOURCE=.\Include\signal_flow_direction.h
# End Source File
# Begin Source File

SOURCE=.\Include\signal_property.h
# End Source File
# Begin Source File

SOURCE=.\Include\signal_specification.h
# End Source File
# Begin Source File

SOURCE=.\Include\simultaneous_geometric_tolerance_requirement.h
# End Source File
# Begin Source File

SOURCE=.\Include\single_boundary_dimension.h
# End Source File
# Begin Source File

SOURCE=.\Include\single_datum.h
# End Source File
# Begin Source File

SOURCE=.\Include\singular_dimension_representation.h
# End Source File
# Begin Source File

SOURCE=.\Include\solid_curve.h
# End Source File
# Begin Source File

SOURCE=.\Include\solid_fill_style.h
# End Source File
# Begin Source File

SOURCE=.\Include\solid_of_linear_extrusion.h
# End Source File
# Begin Source File

SOURCE=.\Include\special_symbol_laminate_component.h
# End Source File
# Begin Source File

SOURCE=.\Include\special_symbol_part_template.h
# End Source File
# Begin Source File

SOURCE=.\Include\specification_allocation.h
# End Source File
# Begin Source File

SOURCE=.\Include\square_or_round.h
# End Source File
# Begin Source File

SOURCE=.\Include\standard_or_reference_document.h
# End Source File
# Begin Source File

SOURCE=.\Include\start_order.h
# End Source File
# Begin Source File

SOURCE=.\Include\start_request.h
# End Source File
# Begin Source File

SOURCE=.\Include\statistical_dimensional_tolerance.h
# End Source File
# Begin Source File

SOURCE=.\Include\statistical_geometric_tolerance.h
# End Source File
# Begin Source File

SOURCE=.\Include\statistical_tolerance_characteristic.h
# End Source File
# Begin Source File

SOURCE=.\Include\status.h
# End Source File
# Begin Source File

SOURCE=.\Include\step_edge_feature_shape.h
# End Source File
# Begin Source File

SOURCE=.\Include\stiffness_class.h
# End Source File
# Begin Source File

SOURCE=.\Include\straightness_tolerance.h
# End Source File
# Begin Source File

SOURCE=.\Include\stratum.h
# End Source File
# Begin Source File

SOURCE=.\Include\stratum_3d_shape.h
# End Source File
# Begin Source File

SOURCE=.\Include\stratum_average_surface.h
# End Source File
# Begin Source File

SOURCE=.\Include\stratum_average_surface_shape.h
# End Source File
# Begin Source File

SOURCE=.\Include\stratum_concept.h
# End Source File
# Begin Source File

SOURCE=.\Include\stratum_concept_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\stratum_concept_to_physical_usage_view_assignment.h
# End Source File
# Begin Source File

SOURCE=.\Include\stratum_feature.h
# End Source File
# Begin Source File

SOURCE=.\Include\stratum_feature_3d_shape.h
# End Source File
# Begin Source File

SOURCE=.\Include\stratum_feature_3d_shape_select.h
# End Source File
# Begin Source File

SOURCE=.\Include\stratum_feature_conductive_join.h
# End Source File
# Begin Source File

SOURCE=.\Include\stratum_feature_in_stratum_3d_position.h
# End Source File
# Begin Source File

SOURCE=.\Include\stratum_feature_in_stratum_planar_position.h
# End Source File
# Begin Source File

SOURCE=.\Include\stratum_feature_non_planar_2d_shape.h
# End Source File
# Begin Source File

SOURCE=.\Include\stratum_feature_planar_representation_select.h
# End Source File
# Begin Source File

SOURCE=.\Include\stratum_feature_planar_shape.h
# End Source File
# Begin Source File

SOURCE=.\Include\stratum_feature_shape_stratum_average_surface_shape_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\stratum_feature_shape_stratum_surface_shape_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\stratum_feature_styled_area_representation.h
# End Source File
# Begin Source File

SOURCE=.\Include\stratum_feature_template.h
# End Source File
# Begin Source File

SOURCE=.\Include\stratum_feature_template_component.h
# End Source File
# Begin Source File

SOURCE=.\Include\stratum_interconnect_module_3d_position.h
# End Source File
# Begin Source File

SOURCE=.\Include\stratum_interconnect_module_planar_position.h
# End Source File
# Begin Source File

SOURCE=.\Include\stratum_make_from_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\stratum_planar_shape.h
# End Source File
# Begin Source File

SOURCE=.\Include\stratum_surface.h
# End Source File
# Begin Source File

SOURCE=.\Include\stratum_surface_designation.h
# End Source File
# Begin Source File

SOURCE=.\Include\stratum_surface_in_stratum_3d_position.h
# End Source File
# Begin Source File

SOURCE=.\Include\stratum_surface_shape.h
# End Source File
# Begin Source File

SOURCE=.\Include\stratum_surface_shape_select.h
# End Source File
# Begin Source File

SOURCE=.\Include\stratum_technology.h
# End Source File
# Begin Source File

SOURCE=.\Include\stratum_technology_line_width_tolerance_assignment.h
# End Source File
# Begin Source File

SOURCE=.\Include\structured_text.h
# End Source File
# Begin Source File

SOURCE=.\Include\styled_area_representation.h
# End Source File
# Begin Source File

SOURCE=.\Include\styled_curve_occurrence.h
# End Source File
# Begin Source File

SOURCE=.\Include\styled_text.h
# End Source File
# Begin Source File

SOURCE=.\Include\sub_assembly_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\substitute_product.h
# End Source File
# Begin Source File

SOURCE=.\Include\supplied_product_version.h
# End Source File
# Begin Source File

SOURCE=.\Include\surface_finish_specification.h
# End Source File
# Begin Source File

SOURCE=.\Include\surface_prepped_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\symmetrical_tolerance_characteristic.h
# End Source File
# Begin Source File

SOURCE=.\Include\symmetry_tolerance.h
# End Source File
# Begin Source File

SOURCE=.\Include\tangent_plane.h
# End Source File
# Begin Source File

SOURCE=.\Include\tangent_shape_element.h
# End Source File
# Begin Source File

SOURCE=.\Include\technology.h
# End Source File
# Begin Source File

SOURCE=.\Include\terminal_pair_port_equivalence_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\terminal_swap_specification.h
# End Source File
# Begin Source File

SOURCE=.\Include\termination_constraint.h
# End Source File
# Begin Source File

SOURCE=.\Include\termination_or_junction.h
# End Source File
# Begin Source File

SOURCE=.\Include\test_select_product.h
# End Source File
# Begin Source File

SOURCE=.\Include\test_specification.h
# End Source File
# Begin Source File

SOURCE=.\Include\theoretically_exact_dimension_representation.h
# End Source File
# Begin Source File

SOURCE=.\Include\thermal_component.h
# End Source File
# Begin Source File

SOURCE=.\Include\thermal_feature.h
# End Source File
# Begin Source File

SOURCE=.\Include\thermal_isolation_removal_structure.h
# End Source File
# Begin Source File

SOURCE=.\Include\thermal_isolation_requirement_assignment.h
# End Source File
# Begin Source File

SOURCE=.\Include\thermal_network_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\thermal_requirement_allocation.h
# End Source File
# Begin Source File

SOURCE=.\Include\thermal_requirement_occurrence.h
# End Source File
# Begin Source File

SOURCE=.\Include\tolerance_characteristic.h
# End Source File
# Begin Source File

SOURCE=.\Include\tolerance_specific_restraint_condition.h
# End Source File
# Begin Source File

SOURCE=.\Include\tolerance_zone.h
# End Source File
# Begin Source File

SOURCE=.\Include\tolerance_zone_and_viewing_plane_orienting_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\tolerance_zone_boundary.h
# End Source File
# Begin Source File

SOURCE=.\Include\tolerance_zone_boundary_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\tolerance_zone_boundary_member.h
# End Source File
# Begin Source File

SOURCE=.\Include\tolerance_zone_boundary_member_offset.h
# End Source File
# Begin Source File

SOURCE=.\Include\tolerance_zone_circular_or_cylindrical_or_spherical_boundary.h
# End Source File
# Begin Source File

SOURCE=.\Include\tolerance_zone_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\tolerance_zone_definition_with_per_unit_size_specification.h
# End Source File
# Begin Source File

SOURCE=.\Include\tolerance_zone_definition_with_specified_orientation.h
# End Source File
# Begin Source File

SOURCE=.\Include\tolerance_zone_explicit_opposing_boundary_set.h
# End Source File
# Begin Source File

SOURCE=.\Include\tolerance_zone_form.h
# End Source File
# Begin Source File

SOURCE=.\Include\tolerance_zone_implicit_opposing_boundary_set.h
# End Source File
# Begin Source File

SOURCE=.\Include\tolerance_zone_opposing_boundary_set.h
# End Source File
# Begin Source File

SOURCE=.\Include\tolerance_zone_per_unit_size_specification.h
# End Source File
# Begin Source File

SOURCE=.\Include\toleranceable_shape_element.h
# End Source File
# Begin Source File

SOURCE=.\Include\topological_junction.h
# End Source File
# Begin Source File

SOURCE=.\Include\total_runout_tolerance.h
# End Source File
# Begin Source File

SOURCE=.\Include\trace_junction_or_via.h
# End Source File
# Begin Source File

SOURCE=.\Include\trace_template.h
# End Source File
# Begin Source File

SOURCE=.\Include\transmission_line_functional_unit_terminal_allocation.h
# End Source File
# Begin Source File

SOURCE=.\Include\transmission_line_functional_unit_to_routed_printed_component_allocation.h
# End Source File
# Begin Source File

SOURCE=.\Include\trimmed_line.h
# End Source File
# Begin Source File

SOURCE=.\Include\trimmed_or_bounding_curve.h
# End Source File
# Begin Source File

SOURCE=.\Include\true_profile.h
# End Source File
# Begin Source File

SOURCE=.\Include\true_profile_representations.h
# End Source File
# Begin Source File

SOURCE=.\Include\two_or_three_dimensional.h
# End Source File
# Begin Source File

SOURCE=.\Include\unsupported_passage.h
# End Source File
# Begin Source File

SOURCE=.\Include\unsupported_passage_dependent_non_functional_land.h
# End Source File
# Begin Source File

SOURCE=.\Include\unsupported_passage_template.h
# End Source File
# Begin Source File

SOURCE=.\Include\usage_concept.h
# End Source File
# Begin Source File

SOURCE=.\Include\usage_concept_usage_relationship.h
# End Source File
# Begin Source File

SOURCE=.\Include\user_defined_dimension_qualifier.h
# End Source File
# Begin Source File

SOURCE=.\Include\user_defined_geometric_tolerance_qualifier.h
# End Source File
# Begin Source File

SOURCE=.\Include\vector.h
# End Source File
# Begin Source File

SOURCE=.\Include\vertical_justification.h
# End Source File
# Begin Source File

SOURCE=.\Include\via.h
# End Source File
# Begin Source File

SOURCE=.\Include\via_and_contact_size_dependent_land.h
# End Source File
# Begin Source File

SOURCE=.\Include\via_and_contact_size_dependent_non_functional_land.h
# End Source File
# Begin Source File

SOURCE=.\Include\via_dependent_land.h
# End Source File
# Begin Source File

SOURCE=.\Include\via_dependent_non_functional_land.h
# End Source File
# Begin Source File

SOURCE=.\Include\via_template.h
# End Source File
# Begin Source File

SOURCE=.\Include\via_template_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\via_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\viewing_plane.h
# End Source File
# Begin Source File

SOURCE=.\Include\viewing_plane_based_orientation.h
# End Source File
# Begin Source File

SOURCE=.\Include\viewing_plane_definition.h
# End Source File
# Begin Source File

SOURCE=.\Include\volume_shape_projection.h
# End Source File
# Begin Source File

SOURCE=.\Include\wire_terminal.h
# End Source File
# Begin Source File

SOURCE=.\Include\work_order.h
# End Source File
# Begin Source File

SOURCE=.\Include\work_request.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
