
add_library(Qt5::QWinRTIntegrationPlugin MODULE IMPORTED)


_populate_Gui_plugin_properties(QWinRTIntegrationPlugin RELEASE "platforms/qwinrt.dll" TRUE)
_populate_Gui_plugin_properties(QWinRTIntegrationPlugin DEBUG "platforms/qwinrtd.dll" TRUE)

list(APPEND Qt5Gui_PLUGINS Qt5::QWinRTIntegrationPlugin)
set_property(TARGET Qt5::Gui APPEND PROPERTY QT_ALL_PLUGINS_platforms Qt5::QWinRTIntegrationPlugin)
set_property(TARGET Qt5::QWinRTIntegrationPlugin PROPERTY QT_PLUGIN_TYPE "platforms")
set_property(TARGET Qt5::QWinRTIntegrationPlugin PROPERTY QT_PLUGIN_EXTENDS "-")
