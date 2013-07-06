# SCRIPT_TESTS =
#   sh_Comp_t
#   sh_8211_t
#   sh_ReadWrite_t
#   sh_Writer_t
#   sh_Accessor_t
#   sh_Cell_t
#   sh_Line_t
#   sh_Directory_t

#add_test(sh_Comp_t sh_Comp_t sh_Comp_t)

add_executable(container_t container_t.cpp)
target_link_libraries(container_t boost_system sdts++ fl sysutils)

add_executable(sc_Field_t sc_Field_t.cpp)
target_link_libraries(sc_Field_t boost_system sdts++ fl sysutils)

add_executable(sc_MultiTypeValue_t sc_MultiTypeValue_t.cpp)
target_link_libraries(sc_MultiTypeValue_t boost_system sdts++ fl sysutils)

add_executable(sc_Subfield_t sc_Subfield_t.cpp)
target_link_libraries(sc_Subfield_t boost_system sdts++ fl sysutils)

add_executable(sio_8211Converter_t sio_8211Converter_t.cpp)
target_link_libraries(sio_8211Converter_t boost_system sdts++ fl sysutils)

add_executable(sio_ConverterFactory_t sio_ConverterFactory_t.cpp)
target_link_libraries(sio_ConverterFactory_t boost_system sdts++ fl sysutils)

add_executable(sio_8211DDRField_t sio_8211DDRField_t.cpp)
target_link_libraries(sio_8211DDRField_t boost_system sdts++ fl sysutils)

add_executable(sio_8211DDRLeader_t sio_8211DDRLeader_t.cpp)
target_link_libraries(sio_8211DDRLeader_t boost_system sdts++ fl sysutils)

add_executable(sio_8211DDR_t sio_8211DDR_t.cpp)
target_link_libraries(sio_8211DDR_t boost_system sdts++ fl sysutils)

add_executable(sio_8211DRLeader_t sio_8211DRLeader_t.cpp)
target_link_libraries(sio_8211DRLeader_t boost_system sdts++ fl sysutils)

add_executable(sio_8211DR_t sio_8211DR_t.cpp)
target_link_libraries(sio_8211DR_t boost_system sdts++ fl sysutils)

add_executable(sio_8211DirEntry_t sio_8211DirEntry_t.cpp)
target_link_libraries(sio_8211DirEntry_t boost_system sdts++ fl sysutils)

add_executable(sio_8211FieldFormat_t sio_8211FieldFormat_t.cpp)
target_link_libraries(sio_8211FieldFormat_t boost_system sdts++ fl sysutils)

add_executable(sio_8211Field_t sio_8211Field_t.cpp)
target_link_libraries(sio_8211Field_t boost_system sdts++ fl sysutils)

add_executable(sio_8211SubfieldFormat_t sio_8211SubfieldFormat_t.cpp)
target_link_libraries(sio_8211SubfieldFormat_t boost_system sdts++ fl sysutils)

add_executable(sio_Buffer_t sio_Buffer_t.cpp)
target_link_libraries(sio_Buffer_t boost_system sdts++ fl sysutils)

add_executable(sio_Error_t sio_Error_t.cpp)
target_link_libraries(sio_Error_t boost_system sdts++ fl sysutils)

add_executable(sb_catd_t sb_catd_t.cpp)
target_link_libraries(sb_catd_t boost_system sdts++ fl sysutils)

add_executable(sb_cats_t sb_cats_t.cpp)
target_link_libraries(sb_cats_t boost_system sdts++ fl sysutils)

add_executable(sb_ForeignID_t sb_ForeignID_t.cpp)
target_link_libraries(sb_ForeignID_t boost_system sdts++ fl sysutils)

add_executable(sb_Spatial_t sb_Spatial_t.cpp)
target_link_libraries(sb_Spatial_t boost_system sdts++ fl sysutils)

add_executable(sb_utils_t sb_utils_t.cpp)
target_link_libraries(sb_utils_t boost_system sdts++ fl sysutils)

add_executable(sl_Point_t sl_Point_t.cpp)
target_link_libraries(sl_Point_t boost_system sdts++ fl sysutils)

add_executable(sl_String_t sl_String_t.cpp)
target_link_libraries(sl_String_t boost_system sdts++ fl sysutils)

add_executable(sl_Chain_t sl_Chain_t.cpp)
target_link_libraries(sl_Chain_t boost_system sdts++ fl sysutils)

add_executable(sl_Ring_t sl_Ring_t.cpp)
target_link_libraries(sl_Ring_t boost_system sdts++ fl sysutils)

add_executable(sl_Polygon_t sl_Polygon_t.cpp)
target_link_libraries(sl_Polygon_t boost_system sdts++ fl sysutils)

add_executable(sl_Node_t sl_Node_t.cpp)
target_link_libraries(sl_Node_t boost_system sdts++ fl sysutils)
