
add_library(Qt5::QWinrtWebViewPlugin MODULE IMPORTED)


_populate_WebView_plugin_properties(QWinrtWebViewPlugin RELEASE "webview/qtwebview_winrt.dll" TRUE)
_populate_WebView_plugin_properties(QWinrtWebViewPlugin DEBUG "webview/qtwebview_winrtd.dll" TRUE)

list(APPEND Qt5WebView_PLUGINS Qt5::QWinrtWebViewPlugin)
set_property(TARGET Qt5::WebView APPEND PROPERTY QT_ALL_PLUGINS_webview Qt5::QWinrtWebViewPlugin)
set_property(TARGET Qt5::QWinrtWebViewPlugin PROPERTY QT_PLUGIN_TYPE "webview")
set_property(TARGET Qt5::QWinrtWebViewPlugin PROPERTY QT_PLUGIN_EXTENDS "")
