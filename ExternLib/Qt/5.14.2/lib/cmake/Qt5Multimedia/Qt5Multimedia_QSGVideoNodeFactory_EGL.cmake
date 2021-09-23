
add_library(Qt5::QSGVideoNodeFactory_EGL MODULE IMPORTED)


_populate_Multimedia_plugin_properties(QSGVideoNodeFactory_EGL RELEASE "video/videonode/eglvideonode.dll" TRUE)
_populate_Multimedia_plugin_properties(QSGVideoNodeFactory_EGL DEBUG "video/videonode/eglvideonoded.dll" TRUE)

list(APPEND Qt5Multimedia_PLUGINS Qt5::QSGVideoNodeFactory_EGL)
set_property(TARGET Qt5::Multimedia APPEND PROPERTY QT_ALL_PLUGINS_video_videonode Qt5::QSGVideoNodeFactory_EGL)
set_property(TARGET Qt5::QSGVideoNodeFactory_EGL PROPERTY QT_PLUGIN_TYPE "video/videonode")
set_property(TARGET Qt5::QSGVideoNodeFactory_EGL PROPERTY QT_PLUGIN_EXTENDS "Qt5::Quick")
