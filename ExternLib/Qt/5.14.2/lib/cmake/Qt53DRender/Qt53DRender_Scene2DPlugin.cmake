
add_library(Qt5::Scene2DPlugin MODULE IMPORTED)


_populate_3DRender_plugin_properties(Scene2DPlugin RELEASE "renderplugins/scene2d.dll" TRUE)
_populate_3DRender_plugin_properties(Scene2DPlugin DEBUG "renderplugins/scene2dd.dll" TRUE)

list(APPEND Qt53DRender_PLUGINS Qt5::Scene2DPlugin)
set_property(TARGET Qt5::3DRender APPEND PROPERTY QT_ALL_PLUGINS_renderplugins Qt5::Scene2DPlugin)
set_property(TARGET Qt5::Scene2DPlugin PROPERTY QT_PLUGIN_TYPE "renderplugins")
set_property(TARGET Qt5::Scene2DPlugin PROPERTY QT_PLUGIN_EXTENDS "")