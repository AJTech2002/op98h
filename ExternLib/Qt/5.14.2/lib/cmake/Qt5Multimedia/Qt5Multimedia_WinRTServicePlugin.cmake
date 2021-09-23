
add_library(Qt5::WinRTServicePlugin MODULE IMPORTED)


_populate_Multimedia_plugin_properties(WinRTServicePlugin RELEASE "mediaservice/winrtengine.dll" TRUE)
_populate_Multimedia_plugin_properties(WinRTServicePlugin DEBUG "mediaservice/winrtengined.dll" TRUE)

list(APPEND Qt5Multimedia_PLUGINS Qt5::WinRTServicePlugin)
set_property(TARGET Qt5::Multimedia APPEND PROPERTY QT_ALL_PLUGINS_mediaservice Qt5::WinRTServicePlugin)
set_property(TARGET Qt5::WinRTServicePlugin PROPERTY QT_PLUGIN_TYPE "mediaservice")
set_property(TARGET Qt5::WinRTServicePlugin PROPERTY QT_PLUGIN_EXTENDS "")
