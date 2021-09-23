
add_library(Qt5::WinRtSensorPlugin MODULE IMPORTED)


_populate_Sensors_plugin_properties(WinRtSensorPlugin RELEASE "sensors/qtsensors_winrt.dll" TRUE)
_populate_Sensors_plugin_properties(WinRtSensorPlugin DEBUG "sensors/qtsensors_winrtd.dll" TRUE)

list(APPEND Qt5Sensors_PLUGINS Qt5::WinRtSensorPlugin)
set_property(TARGET Qt5::Sensors APPEND PROPERTY QT_ALL_PLUGINS_sensors Qt5::WinRtSensorPlugin)
set_property(TARGET Qt5::WinRtSensorPlugin PROPERTY QT_PLUGIN_TYPE "sensors")
set_property(TARGET Qt5::WinRtSensorPlugin PROPERTY QT_PLUGIN_EXTENDS "")
