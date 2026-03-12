include("D:/a_app/QT/workspace/Servers/build/Desktop_Qt_6_8_3_MinGW_64_bit-RelWithDebInfo/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/Servers-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE D:/a_app/QT/workspace/Servers/build/Desktop_Qt_6_8_3_MinGW_64_bit-RelWithDebInfo/Servers.exe
    GENERATE_QT_CONF
)
