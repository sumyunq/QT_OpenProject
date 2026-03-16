include("D:/QT6WorkSpace/Servers/build/Desktop_Qt_6_8_3_MinGW_64_bit-Release-with-Debug-Information/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/Servers-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase;qtmultimedia;qtmultimedia")

qt6_deploy_runtime_dependencies(
    EXECUTABLE D:/QT6WorkSpace/Servers/build/Desktop_Qt_6_8_3_MinGW_64_bit-Release-with-Debug-Information/Servers.exe
    GENERATE_QT_CONF
)
